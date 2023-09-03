/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 06:15:38 by rbroque           #+#    #+#             */
/*   Updated: 2023/09/03 13:42:24 by rbroque          ###   ########.fr       */
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

	displayContainers("Before");
	sortVectorSeq();
	// sortListSeq(_listSeq);
	displayContainers("After ");
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

void PmergeMe::displayContainers(const std::string &prefix) {
	std::cout << prefix << VECTOR_DISPLAY;
	displaySequence(_vectorSeq);
	std::cout << prefix << LIST_DISPLAY;
	displaySequence(_listSeq);
}

static void insertionSort(std::vector<int> &sequence, const size_t beginIndex, const size_t endIndex) {

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

static void merge(std::vector<int> &sequence, const size_t beginIndex, const size_t subSize, const size_t endIndex) {

	const size_t		index1 = subSize - beginIndex + 1;
	const size_t		index2 = endIndex - subSize;
	size_t				leftIndex = 0;
	size_t				rightIndex = 0;
	std::vector<int>	left(sequence.begin() + beginIndex, sequence.begin() + subSize + 1);
	std::vector<int>	right(sequence.begin() + subSize + 1, sequence.begin() + endIndex + 1);
	std::vector<int>	mergedContainer(left);

	for (size_t i = beginIndex; i < endIndex - beginIndex + 1; ++i) {
		if (rightIndex == index2) {
			sequence[i] = left[leftIndex];
			++leftIndex;
		} else if (leftIndex == index1) {
			sequence[i] = right[rightIndex];
			++rightIndex;
		} else if (right[rightIndex] > left[leftIndex]) {
			sequence[i] = left[leftIndex];
			++leftIndex;
		} else {
			sequence[i] = right[rightIndex];
			++rightIndex;
		}
	}
}

static void sortNumbers(std::vector<int> &sequence, const size_t beginIndex, const size_t endIndex) {
	if (endIndex - beginIndex > 2) {
		const size_t subSize = (beginIndex + endIndex) / 2;
		sortNumbers(sequence, beginIndex, subSize);
		sortNumbers(sequence, subSize + 1, endIndex);
		merge(sequence, beginIndex, subSize, endIndex);
	} else {
		insertionSort(sequence, beginIndex, endIndex);
	}
}

void PmergeMe::sortVectorSeq() {

	sortNumbers(_vectorSeq, 0, _vectorSeq.size() - 1);
}