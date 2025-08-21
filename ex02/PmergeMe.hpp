/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaporte <mlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 18:58:36 by mlaporte          #+#    #+#             */
/*   Updated: 2025/05/04 18:58:36 by mlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <vector>
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <algorithm>
#include <ctime>

typedef std::pair<int, int> int_pair;

class PmergeMe
{

	private:
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		std::deque<int> _deque;
		std::vector<int> _vector;
		std::vector<int> _inputVector;
	public:
		PmergeMe();
		~PmergeMe();
		class InvalidInputException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Error";
				}
		};

		void checkInputVector(int argc, char **argv, std::vector<int> &v);
		void checkInputDeque(int argc, char **argv);
		void sort(int argc, char **argv);
		void sort(std::vector<int> &v);
		void print(const std::deque<int> &d) const;
		void print(const std::vector<int> &v) const;
		void printResultDeque(int argc, char **argv);
		void printResultVector(int argc, char **argv);
		std::vector<int> sortAlgorithm(std::vector<int> &v);
		std::deque<int> sortAlgorithm(std::deque<int> &d);
		void mergeVector(std::vector<int> &sorted, std::vector<int> &pendings);
		void mergeDeque(std::deque<int> &sorted, std::deque<int> &pendings);
		void insertionSortDeque(std::deque<int_pair> &pairs, int size);
		void insertionSortVector(std::vector<int_pair> &pairs, int size);
		int jacobsthalNumber(int n);
		int binarySearchVector(const std::vector<int> &v, int value, int start, int end);
		int binarySearchDeque(const std::deque<int> &d, int value, int start, int end);
};	


#endif