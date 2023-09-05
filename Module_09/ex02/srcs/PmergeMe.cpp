/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 06:15:38 by rbroque           #+#    #+#             */
/*   Updated: 2023/09/05 06:43:44 by rbroque          ###   ########.fr       */
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

static void swap(int &nb1, int &nb2) {
	int tmp = nb1;

	nb1 = nb2;
	nb2 = tmp;
}

// Vector version

static void insertionSort(std::vector<int> &sequence, const size_t beginIndex, const size_t endIndex) {

	std::vector<int>::iterator it1 = sequence.begin();
	std::advance(it1, beginIndex);
	std::vector<int>::iterator it2 = sequence.begin();
	std::advance(it2, endIndex);

	if (*it1 > *it2) {
		swap(*it1, *it2);
	}
}

static void merge(std::vector<int> &sequence, const size_t beginIndex, const size_t subSize, const size_t endIndex) {

	const size_t index1 = subSize - beginIndex + 1;
	const size_t index2 = endIndex - subSize;
	size_t leftIndex = 0;
	size_t rightIndex = 0;
	std::vector<int> left(sequence.begin() + beginIndex, sequence.begin() + subSize + 1);
	std::vector<int> right(sequence.begin() + subSize + 1, sequence.begin() + endIndex + 1);

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

// List version

static std::list<int> extractList(std::list<int> &list, const size_t beginIndex, const size_t endIndex) {

	size_t			i;
	std::list<int>	newList;

	i = 0;
	for (std::list<int>::iterator it = list.begin(); it != list.end(); ++it) {
		if (i >= beginIndex && i <= endIndex) {
			newList.push_back(*it);
		}
		++i;
	}
	return newList;
}

static void insertionSort(std::list<int> &sequence, const size_t beginIndex, const size_t endIndex) { // need to be modified!
	
	std::list<int>::iterator it1 = sequence.begin();
	std::list<int>::iterator it2 = sequence.begin();

	std::advance(it1, beginIndex);
	std::advance(it2, endIndex);
	if (*it1 > *it2) {
		swap(*it1, *it2);
	}
}

static void merge(std::list<int> &sequence, const size_t beginIndex, const size_t subSize, const size_t endIndex) {
	std::list<int> left = extractList(sequence, beginIndex, subSize);
	std::list<int> right = extractList(sequence, subSize + 1, endIndex);
	std::list<int>::iterator leftIter = left.begin();
	std::list<int>::iterator rightIter = right.begin();
	std::list<int>::iterator sequenceIter = sequence.begin();

	std::advance(sequenceIter, beginIndex);
	for (size_t i = beginIndex; i <= endIndex; ++i) {
		if (rightIter == right.end() || (leftIter != left.end() && *leftIter <= *rightIter)) {
			*sequenceIter = *leftIter;
			++leftIter;
		} else {
			*sequenceIter = *rightIter;
			++rightIter;
		}
		++sequenceIter;
	}
}


template <typename T>
static void sortNumbers(T &sequence, const size_t beginIndex, const size_t endIndex) {
	if (endIndex > beginIndex) {
		if (endIndex - beginIndex < 2) {
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
	sortNumbers(_vectorSeq, 0, _vectorSeq.size() - 1);
	clock_t	end = clock();
	double elapsed_secs = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	_vectSortTime = elapsed_secs;
}

void PmergeMe::sortListSeq() {

	clock_t	start = clock();
	sortNumbers(_listSeq, 0, _listSeq.size() - 1);
	clock_t	end = clock();
	double elapsed_secs = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	_listSortTime = elapsed_secs;
}

void PmergeMe::displayContainers(const std::string &prefix) {
	std::cout << prefix;
	displaySequence(_vectorSeq);
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
	else if (typeid(container) == typeid(std::list<int>))
	{
		std::cout << "std::list   : ";
		time = _listSortTime;
	}
	std::cout << std::fixed << DOUBLE_PRECISION << time << " us" << std::endl;
}
