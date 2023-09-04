/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 06:15:38 by rbroque           #+#    #+#             */
/*   Updated: 2023/09/04 08:17:39 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

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

template <typename T>
static void insertionSort(T &sequence, const size_t beginIndex, const size_t endIndex) {

	for (size_t i = beginIndex; i < endIndex; ++i) {
		const int tmpValue = sequence[i + 1];
		size_t j = i + 1;
		while (j > beginIndex && sequence[j - 1] > tmpValue) {
			sequence[j] = sequence[j - 1];
			--j;
		}
		sequence[j] = tmpValue;
	}
}

template <typename T>
static void merge(T &sequence, const size_t beginIndex, const size_t subSize, const size_t endIndex) {

	const size_t index1 = subSize - beginIndex + 1;
	const size_t index2 = endIndex - subSize;
	size_t leftIndex = 0;
	size_t rightIndex = 0;
	std::vector<typename T::value_type> left(sequence.begin() + beginIndex, sequence.begin() + subSize + 1);
	std::vector<typename T::value_type> right(sequence.begin() + subSize + 1, sequence.begin() + endIndex + 1);

	for (size_t i = beginIndex; i <= endIndex; ++i) {
		if (rightIndex == index2 || (leftIndex != index1 && left[leftIndex] <= right[rightIndex])) {
			sequence[i] = left[leftIndex];
			++leftIndex;
		} else {
			sequence[i] = right[rightIndex];
			++rightIndex;
		}
	}
}

template <typename T>
static void sortNumbers(T &sequence, const size_t beginIndex, const size_t endIndex) {
	if (endIndex > beginIndex) {
		if (endIndex - beginIndex <= 2) {
			insertionSort(sequence, beginIndex, endIndex);
		} else {
			const size_t subSize = (beginIndex + endIndex) / 2;
			sortNumbers(sequence, beginIndex, subSize);
			sortNumbers(sequence, subSize + 1, endIndex);
			merge(sequence, beginIndex, subSize, endIndex);
		}
	}
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
		_dequeSeq.push_back(nb);
		++sequence;
	}
	_vectSortTime = 0;
	_dequeSortTime = 0;
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
	_dequeSeq = other._dequeSeq;
	return *this;
}

/////////////
// Member //
///////////

void PmergeMe::sort() {

	displayContainers("Before");
	sortVectorSeq();
	sortDequeSeq();
	displayContainers("After ");
	displayTime(_vectorSeq);
	displayTime(_dequeSeq);
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
	sortNumbers(_vectorSeq, 0, _vectorSeq.size() - 1);
	clock_t	end = clock();
	double elapsed_secs = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	_vectSortTime = elapsed_secs;
}

void PmergeMe::sortDequeSeq() {

	clock_t	start = clock();
	sortNumbers(_dequeSeq, 0, _dequeSeq.size() - 1);
	clock_t	end = clock();
	double elapsed_secs = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	_dequeSortTime = elapsed_secs;
}

void PmergeMe::displayContainers(const std::string &prefix) {
	std::cout << prefix << VECTOR_DISPLAY;
	displaySequence(_vectorSeq);
	std::cout << prefix << LIST_DISPLAY;
	displaySequence(_dequeSeq);
}

template <typename T>
void PmergeMe::displayTime(const T &container) {

	double time;
	std::cout << "Time to process a range of " << container.size() << " elements with ";
	if (typeid(container) == typeid(std::vector<int>))
	{
		std::cout << "std::vector : ";
		time = _vectSortTime;
	}
	else if (typeid(container) == typeid(std::deque<int>))
	{
		std::cout << "std::deque : ";
		time = _dequeSortTime;
	}
	std::cout << std::fixed << DOUBLE_PRECISION << time << std::endl;
}
