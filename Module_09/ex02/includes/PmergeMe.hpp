/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 06:07:25 by rbroque           #+#    #+#             */
/*   Updated: 2023/09/30 07:14:35 by rbroque          ###   ########.fr       */
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
		T*	a() const {return _a;};
		T*	b() const {return _b;};
	// Setters
		void seta(T& a) {_a = &a;};
		void setb(T& b) {_b = &b;};
	// Overload operator
		Pair<T>& operator=(const Pair<T>& rhs)
		{
			_a = rhs.a(); _b = rhs.b(); return (*this);
		};
		bool	operator>(const Pair<T>& rhs) const {return (*_a > *rhs.a());};
		bool	operator<(const Pair<T>& rhs) const {return (*_a < *rhs.a());};
		bool	operator>=(const Pair<T>& rhs) const {return (*_a >= *rhs.a());};
		bool	operator<=(const Pair<T>& rhs) const {return (*_a <= *rhs.a());};
		bool	operator==(const Pair<T>& rhs) const {return (*_a == *rhs.a());};
		bool	operator!=(const Pair<T>& rhs) const {return (*_a != *rhs.a());};
		
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

	public:
	template <typename T>
	static void fordJohnsonSort(std::vector<T> &sequence) {

		const size_t size = sequence.size();
		T	*stray = NULL;

		if (size < 2)
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
		template <typename T>
	static std::vector<T> insertPairs(std::vector<Pair<T> > &u, T *stray)
	{
		int J_upper = 1;
		int J_lower = 1;
		int tmp = J_lower;
		typename std::vector<T>::iterator pos;
		typename std::vector<T>::iterator last;
		std::vector<T> mainChain;
	
	
		mainChain.push_back(*(u[0].b()));
		mainChain.push_back(*(u[0].a()));
		if (J_upper == static_cast<int>(u.size()) && stray)
		{
			pos = binary_search(mainChain.begin(), mainChain.end(), *stray);
			mainChain.insert(pos, *stray);
		}
		while (J_upper < static_cast<int>(u.size()))
		{
			// set Jacobsthal values
			tmp = J_lower;
			J_lower = J_upper;
			J_upper = std::min(Jacobsthal_n(J_lower, tmp), static_cast<int>(u.size()));

			// First add all As to mainChain
			for (int i = J_lower; i < J_upper; i++)
				mainChain.push_back(*(u[i].a()));

			// Than insert Bs
				// first insert stray if it exists
			if (J_upper == static_cast<int>(u.size()) && stray)
			{
				pos = binary_search(mainChain.begin(), mainChain.end(), *stray);
				mainChain.insert(pos, *stray);
			}
				// than add Bs
			for (int i = J_upper - 1; i >= J_lower; i--)
			{
				if (J_upper == static_cast<int>(u.size()))
					last = mainChain.end();
				else
					last = mainChain.begin() + J_upper + J_lower - 1;
				// binary search in a list of size (2^n)-1 = t_n + t_n-1 - 1 where t_n = Jacobstahl_n
				pos = binary_search(mainChain.begin(), last, *(u[i].b()));
				mainChain.insert(pos, *(u[i].b()));
			}
		}
		return (mainChain);
	}

	template <typename T>
	static typename std::vector<T>::iterator binary_search(typename std::vector<T>::iterator first, typename std::vector<T>::iterator last, T &val)
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

	static int Jacobsthal_n(int Jacobsthal_n_1, int Jacobsthal_n_2)
	{
		// Jacobsthal suite : t_n = t_n-1 + 2*t_n-2
		return (Jacobsthal_n_1 + 2 * Jacobsthal_n_2);
	}

};
template <>
class Sort<1> {

	public:

	template <typename T>
	static void fordJohnsonSort(std::vector<T> &sequence) {(void)sequence;};
};
