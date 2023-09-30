/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 06:07:25 by rbroque           #+#    #+#             */
/*   Updated: 2023/09/30 08:54:19 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <climits>
#include <string>
#include <cstdlib>
#include <vector>
#include <list>
#include <ctime>
#include <iomanip>
#include <typeinfo>

// Error messages

#define MISSING_ARG_ERROR_M		"missing argument"
#define UNEXPECTED_CHAR_ERROR_M	"unexpected character"
#define OVERFLOW_ERROR_M		"overflow"
#define NEGATIVE_NB_ERROR_M		"negative number"
#define EMPTY_ARG_ERROR_M		"empty argument"

// Display

#define BEFORE_PATTERN			"Before: "
#define AFTER_PATTERN			"After:  "

// Colors

#define NC		"\033[0m"
#define RED		"\033[0;31m"
#define GREEN	"\033[0;32m"

#define ASCII_NB_SHIFT		48
#define DOUBLE_PRECISION	5
#define SPACE				" "

#ifndef PRINT_DEBUG
# define PRINT_DEBUG false
#endif

class PmergeMe {

	private:

		// Attributes
			std::vector<int>	_vectorSeq;
			std::list<int>		_listSeq;
			double				_vectSortTime;
			double				_listSortTime;
		// Methods
			void sortVectorSeq();
			void sortListSeq();
			void displayContainers(const std::string &prefix) const;
			template <typename T>
			void displayTime(const T &container) const;
			PmergeMe(); // Cannot be used

	public:

		// Constructors
			PmergeMe(char **sequence);
			PmergeMe(PmergeMe const &other);
		// Overload assignment operator
			PmergeMe &operator=(PmergeMe const &other);
		// Member
			void sort();
		// Destructor
			~PmergeMe();
		// Exceptions
			class MissingArgError: public std::exception {
				public:
					const char *what() const throw();
			};
			class UnexpectedCharacterError: public std::exception {
				public:
					const char *what() const throw();
			};
			class OverflowError: public std::exception {
				public:
					const char *what() const throw();
			};
			class NegativeNumberError: public std::exception {
				public:
					const char *what() const throw();
			};
			class EmptyArgError: public std::exception {
				public:
					const char *what() const throw();
			};
};

// Pair

template <typename T>
class Pair {

	private:
	T*				_a;
	T*				_b;

	public:

	// Constructors
		Pair<T>() : _a(NULL), _b(NULL){};
		Pair<T>(T& a, T& b) : _a(&a), _b(&b){};
		Pair<T>(const Pair<T>& other) {*this = other;};
	// Destructor
		~Pair<T>(){};
	// Getters
		T*	first() const {return _a;};
		T*	second() const {return _b;};
	// Overload operator
		Pair<T>& operator=(const Pair<T>& other)
		{
			_a = other.first(); _b = other.second(); return (*this);
		};
		bool	operator>(const Pair<T>& other) const {return (*_a > *other.first());};
		bool	operator<(const Pair<T>& other) const {return (*_a < *other.first());};
		bool	operator>=(const Pair<T>& other) const {return (*_a >= *other.first());};
		bool	operator<=(const Pair<T>& other) const {return (*_a <= *other.first());};
		bool	operator==(const Pair<T>& other) const {return (*_a == *other.first());};
		bool	operator!=(const Pair<T>& other) const {return (*_a != *other.first());};
		
	// Methods
		void sort()
		{
			if (*_a < *_b)
				std::swap(_a, _b);
		};
};

// Sort

template <int N>
class Sort {

	private:
	
		template <typename T>
		static std::vector<T> insertPairs(const std::vector<Pair<T> > &u, const T *stray);
		template <typename T>
		static typename std::vector<T>::iterator binary_search(
			const typename std::vector<T>::iterator first,
			const typename std::vector<T>::iterator last,
			const T &val);
		static size_t Jacobsthal_n(const size_t Jacobsthal_n_1, const size_t Jacobsthal_n_2);

	public:
	
		template <typename T>
		static void fordJohnsonSort(std::vector<T> &sequence);
};

template <>
class Sort<1> {

	public:

	template <typename T>
	static void fordJohnsonSort(std::vector<T> &sequence) {(void)sequence;};
};
