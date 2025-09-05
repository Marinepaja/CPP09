/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 05:49:07 by mechard           #+#    #+#             */
/*   Updated: 2025/03/29 05:49:07 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cstdlib>

class PmergeMe
{

public:
	PmergeMe();
	~PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	bool addNumber(const std::string &numStr);
	double sortVector();
	double sortDeque();
	void printBefore() const;
	void printAfterVector() const;
	void printAfterDeque() const;

private:
	std::vector<int> _vector;
	std::deque<int> _deque;
	static const int INSERTION_SORT_THRESHOLD = 10;
	void insertionSortVector(int left, int right);
	void mergeVector(int left, int mid, int right);
	void mergeSortVector(int left, int right);
	void insertionSortDeque(int left, int right);
	void mergeDeque(int left, int mid, int right);
	void mergeSortDeque(int left, int right);

};

#endif
