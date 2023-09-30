/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 06:15:38 by rbroque           #+#    #+#             */
/*   Updated: 2023/09/30 07:46:05 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

//////////////////////////////////////////////////////////////////
/////////////////////////////// Sort /////////////////////////////
//////////////////////////////////////////////////////////////////

template <int N>
template <typename T>
void Sort<N>::fordJohnsonSort(std::vector<T> &sequence) {

		const size_t size = sequence.size();
		T	*stray = NULL;

		if (size < 2 || N < 2)
			return ;
		// Make pairs (A, B) and identify highest value as A
		std::vector<Pair<T> > u(size/ 2);
		if (sequence.size() % 2) //stores stray value in case of an odd size
			stray = &(*(--sequence.end()));
		for (unsigned long i = 0; i < u.size(); i++)
		{
			u[i] = Pair<T>(sequence[2 * i], sequence[2 * i + 1]); //instantiate pairs
			u[i].sort(); //sort pair (ie: set highest value as A)
		}
		// Sort list of pairs recursively
		Sort<N - 1>::template fordJohnsonSort<Pair<T> >(u);

		// Insert Bs in main chain with binary search
		sequence = insertPairs(u, stray);
}
	
template <int N>
template <typename T>
std::vector<T> Sort<N>::insertPairs(std::vector<Pair<T> > &u, T *stray) {

		size_t J_upper = 1;
		size_t J_lower = 1;
		size_t tmp = J_lower;
		typename std::vector<T>::iterator pos;
		typename std::vector<T>::iterator last;
		std::vector<T> mainChain;
	
		mainChain.push_back(*(u[0].second()));
		mainChain.push_back(*(u[0].first()));
		if (J_upper == u.size() && stray)
		{
			pos = binary_search(mainChain.begin(), mainChain.end(), *stray);
			mainChain.insert(pos, *stray);
		}
		while (J_upper < u.size())
		{
			// set Jacobsthal values
			tmp = J_lower;
			J_lower = J_upper;
			J_upper = std::min(Jacobsthal_n(J_lower, tmp), u.size());

			// First add all As to mainChain
			for (size_t i = J_lower; i < J_upper; i++)
				mainChain.push_back(*(u[i].first()));

			// Than insert Bs
				// first insert stray if it exists
			if (J_upper == u.size() && stray)
			{
				pos = binary_search(mainChain.begin(), mainChain.end(), *stray);
				mainChain.insert(pos, *stray);
			}
				// than add Bs
			for (size_t i = J_upper - 1; i >= J_lower; i--)
			{
				if (J_upper == u.size())
					last = mainChain.end();
				else
					last = mainChain.begin() + J_upper + J_lower - 1;
				// binary search in a list of size (2^n)-1 = t_n + t_n-1 - 1 where t_n = Jacobstahl_n
				pos = binary_search(mainChain.begin(), last, *(u[i].second()));
				mainChain.insert(pos, *(u[i].second()));
			}
		}
		return (mainChain);
}

template <int N>
template <typename T>
typename std::vector<T>::iterator Sort<N>::binary_search(const typename std::vector<T>::iterator first, const typename std::vector<T>::iterator last, const T &val)
{
	typename std::vector<T>::iterator middle;

	// Stop condition
	if (std::distance(first, last) < 2)
	{
		if (val < *first)
			return (first);
		else
			return (last);
	}
	// Else
	middle = first + std::distance(first, last) / 2;
	if (val < *middle) 
		return (binary_search(first, middle, val)); // calls binary_search on left part
	else 
		return (binary_search(middle, last, val)); // calls binary_search on right part
}

template <int N>
size_t Sort<N>::Jacobsthal_n(const size_t Jacobsthal_n_1, const size_t Jacobsthal_n_2)
{
	// Jacobsthal suite : t_n = t_n-1 + 2*t_n-2
	return (Jacobsthal_n_1 + 2 * Jacobsthal_n_2);
}

//////////////////////////////////////////////////////////////////
//////////////////////////// PMergeMe ////////////////////////////
//////////////////////////////////////////////////////////////////

/////////////////////
// Static methods //
///////////////////

static int toInt(const int nb, const int added) {
	if (added > INT_MAX - 10 * nb)
		throw PmergeMe::OverflowError();
	return 10 * nb + added;
}

static int getIntFromStr(const std::string &str) {

	int	nb;
	
	nb = 0;
	for (size_t i = 0; i < str.length(); ++i) {
		if (isdigit(str[i])) {
			nb = toInt(nb, str[i] - ASCII_NB_SHIFT);
		}
		else {
			throw PmergeMe::UnexpectedCharacterError();
		}
	}
	if (nb < 0)
		throw PmergeMe::NegativeNumberError();
	return nb;
}

template <typename T>
static void displaySequence(const T &sequence) {
	const size_t size = sequence.size();
	typename T::const_iterator it = sequence.begin();
	for (size_t i = 0; i < size; ++i) {
		std::cout << *it;
		if (i + 1 < size) {
			std::cout << SPACE;
		}
		++it;
	}
	std::cout << std::endl;
}

///////////////////
// Constructors //
/////////////////

// Cannot be used

PmergeMe::PmergeMe() {
	if (PRINT_DEBUG) {
		std::cout << "PmergeMe has been " <<
		GREEN << "created (empty)" << NC << std::endl;
	}
}

PmergeMe::PmergeMe(PmergeMe const &other) {
	
	*this = other;
	if (PRINT_DEBUG) {
		std::cout << "PmergeMe has been " <<
		GREEN << "created (copy)" << NC << std::endl;
	}
}

PmergeMe::PmergeMe(char **sequence) {
	
	if (*sequence == NULL)
		throw MissingArgError();
	while (*sequence) {
		const std::string nbString = *sequence;
		if (nbString.empty())
			throw EmptyArgError();
		const int nb = getIntFromStr(nbString);
		_vectorSeq.push_back(nb);
		_listSeq.push_back(nb);
		++sequence;
	}
	_vectSortTime = 0;
	_listSortTime = 0;
	if (PRINT_DEBUG) {
		std::cout << "PmergeMe has been " <<
		GREEN << "created (set)" << NC << std::endl;
	}
}

///////////////////////////////////
// Overload assignment operator //
/////////////////////////////////

PmergeMe &PmergeMe::operator=(PmergeMe const &other) {
	_vectorSeq = other._vectorSeq;
	_listSeq = other._listSeq;
	return *this;
}

/////////////
// Member //
///////////

void PmergeMe::sort() {

	displayContainers(BEFORE_PATTERN);
	sortVectorSeq();
	sortListSeq();
	displayContainers(AFTER_PATTERN);
	displayTime(_vectorSeq);
	displayTime(_listSeq);
}

/////////////////
// Destructor //
///////////////

PmergeMe::~PmergeMe() {
	if (PRINT_DEBUG) {
		std::cout << "PmergeMe has been " <<
		RED << "destroyed" << std::endl;
	}
}

/////////////////
// Exceptions //
///////////////

const char *PmergeMe::MissingArgError::what() const throw() {
	return MISSING_ARG_ERROR_M;
}

const char *PmergeMe::UnexpectedCharacterError::what() const throw() {
	return UNEXPECTED_CHAR_ERROR_M;
}

const char *PmergeMe::OverflowError::what() const throw() {
	return OVERFLOW_ERROR_M;
}

const char *PmergeMe::NegativeNumberError::what() const throw() {
	return NEGATIVE_NB_ERROR_M;
}

const char *PmergeMe::EmptyArgError::what() const throw() {
	return EMPTY_ARG_ERROR_M;
}

//////////////
// Private //
////////////

void PmergeMe::sortVectorSeq() {

	clock_t	start = clock();
	Sort<32>::fordJohnsonSort<int>(_vectorSeq);
	clock_t	end = clock();
	double elapsed_secs = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	_vectSortTime = elapsed_secs;
}

void PmergeMe::sortListSeq() {

	clock_t	start = clock();
//	sortNumbers(_listSeq, 0, _listSeq.size() - 1);
	clock_t	end = clock();
	double elapsed_secs = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	_listSortTime = elapsed_secs;
}

void PmergeMe::displayContainers(const std::string &prefix) const {
	std::cout << prefix;
	displaySequence(_vectorSeq);
}

template <typename T>
void PmergeMe::displayTime(const T &container) const {

	double time;
	std::cout << "Time to process a range of " << container.size() << " elements with ";
	if (typeid(container) == typeid(std::vector<int>))
	{
		std::cout << "std::vector : ";
		time = _vectSortTime;
	}
	else if (typeid(container) == typeid(std::list<int>))
	{
		std::cout << "std::list   : ";
		time = _listSortTime;
	}
	std::cout << std::fixed << DOUBLE_PRECISION << time << " us" << std::endl;
}
