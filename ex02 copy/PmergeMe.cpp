/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 07:22:50 by mechard           #+#    #+#             */
/*   Updated: 2025/03/29 07:22:50 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	(void)other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	(void)other;
	return *this;
}

bool PmergeMe::addNumber(const std::string &numStr)
{
	for (size_t i = 0; i < numStr.size(); ++i)
		if (!std::isdigit(numStr[i]))
			return false;
	int num = std::atoi(numStr.c_str());
	if (num <= 0)
		return false;
	_vector.push_back(num);
	_deque.push_back(num);
	return true;
}

void PmergeMe::printBefore() const
{
	std::cout << "Before: ";
	for (size_t i = 0; i < _vector.size(); ++i)
		std::cout << _vector[i] << " ";
	std::cout << std::endl;
}

void PmergeMe::printAfterVector() const
{
	std::cout << "After: ";
	for (size_t i = 0; i < _vector.size(); ++i)
		std::cout << _vector[i] << " ";
	std::cout << std::endl;
}

void PmergeMe::printAfterDeque() const
{
	std::cout << "After (deque): ";
	for (size_t i = 0; i < _deque.size(); ++i)
		std::cout << _deque[i] << " ";
	std::cout << std::endl;
}

// -------------------- TRI SUR VECTOR --------------------
void PmergeMe::insertionSortVector(int left, int right)
{
	for (int i = left + 1; i <= right; ++i)
	{
		int key = _vector[i];
		int j = i - 1;
		while (j >= left && _vector[j] > key)
		{
			_vector[j + 1] = _vector[j];
			j--;
		}
		_vector[j + 1] = key;
	}
}

void PmergeMe::mergeVector(int left, int mid, int right)
{
	std::vector<int> leftVec(_vector.begin() + left, _vector.begin() + mid + 1);
	std::vector<int> rightVec(_vector.begin() + mid + 1, _vector.begin() + right + 1);
	int i = 0, j = 0, k = left;
	while (i < (int)leftVec.size() && j < (int)rightVec.size())
	{
		if (leftVec[i] <= rightVec[j])
			_vector[k++] = leftVec[i++];
		else
			_vector[k++] = rightVec[j++];
	}
	while (i < (int)leftVec.size())
		_vector[k++] = leftVec[i++];
	while (j < (int)rightVec.size())
		_vector[k++] = rightVec[j++];
}

void PmergeMe::mergeSortVector(int left, int right)
{
	if (left >= right)
		return;
	if (right - left + 1 <= INSERTION_SORT_THRESHOLD)
	{
		insertionSortVector(left, right);
		return;
	}
	int mid = left + (right - left) / 2;
	mergeSortVector(left, mid);
	mergeSortVector(mid + 1, right);
	mergeVector(left, mid, right);
}

double PmergeMe::sortVector()
{
    std::clock_t start = std::clock();
    mergeSortVector(0, _vector.size() - 1);
    std::clock_t end = std::clock();

    double elapsed = static_cast<double>(end - start) * 1000000.0 / CLOCKS_PER_SEC;
    return elapsed; // en millisecondes avec décimales
}

// -------------------- TRI SUR DEQUE --------------------
void PmergeMe::insertionSortDeque(int left, int right)
{
	for (int i = left + 1; i <= right; ++i)
	{
		int key = _deque[i];
		int j = i - 1;
		while (j >= left && _deque[j] > key)
		{
			_deque[j + 1] = _deque[j];
			j--;
		}
		_deque[j + 1] = key;
	}
}

void PmergeMe::mergeDeque(int left, int mid, int right)
{
	std::deque<int> leftDeque(_deque.begin() + left, _deque.begin() + mid + 1);
	std::deque<int> rightDeque(_deque.begin() + mid + 1, _deque.begin() + right + 1);
	int i = 0, j = 0, k = left;
	while (i < (int)leftDeque.size() && j < (int)rightDeque.size())
	{
		if (leftDeque[i] <= rightDeque[j])
			_deque[k++] = leftDeque[i++];
		else
			_deque[k++] = rightDeque[j++];
	}
	while (i < (int)leftDeque.size())
		_deque[k++] = leftDeque[i++];
	while (j < (int)rightDeque.size())
		_deque[k++] = rightDeque[j++];
}

void PmergeMe::mergeSortDeque(int left, int right)
{
	if (left >= right)
		return;
	if (right - left + 1 <= INSERTION_SORT_THRESHOLD)
	{
		insertionSortDeque(left, right);
		return;
	}
	int mid = left + (right - left) / 2;
	mergeSortDeque(left, mid);
	mergeSortDeque(mid + 1, right);
	mergeDeque(left, mid, right);
}

double PmergeMe::sortDeque()
{
    std::clock_t start = std::clock();
    mergeSortDeque(0, _deque.size() - 1);
    std::clock_t end = std::clock();

    double elapsed = static_cast<double>(end - start) * 1000000.0 / CLOCKS_PER_SEC;
    return elapsed; // en millisecondes avec décimales
}
