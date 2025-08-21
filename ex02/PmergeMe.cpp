/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaporte <mlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:28:08 by mlaporte          #+#    #+#             */
/*   Updated: 2025/05/02 15:28:08 by mlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

void PmergeMe::checkInputVector(int argc, char **argv, std::vector<int> &v)
{

	for (int i = 0; i < argc; i++)
	{
		try
		{
			int num;
			int value;
			char remaining;
			std::istringstream iss(argv[i]);
			if (iss >> num && !(iss >> remaining))
			{
				value = num;
				if (value < 0)
					throw InvalidInputException();
			}
			else
			{
				throw InvalidInputException();
			}
			if (std::find(v.begin(), v.end(), value) != v.end())
				throw InvalidInputException();
			v.push_back(value);
		
		}
		catch (const std::exception &e)
		{
			throw InvalidInputException();
		}
	}

}


void PmergeMe::checkInputDeque(int argc, char **argv)
{
	for (int i = 0; i < argc; i++)
	{
		try
		{
			int num;
			int value;
			char remaining;
			std::istringstream iss(argv[i]);
			if (iss >> num && !(iss >> remaining))
			{
				value = num;
				if (value < 0)
					throw InvalidInputException();
			}
			if (std::find(this->_deque.begin(), this->_deque.end(), value) != this->_deque.end())
				throw InvalidInputException();
			_deque.push_back(value);
		}
		catch (const std::exception &e)
		{
			throw InvalidInputException();
		}
	}
}

void PmergeMe::sort(int argc, char **argv)
{
	checkInputVector(argc, argv, _inputVector);
	std::cout << "Before: ";
	print(_inputVector);
	printResultVector(argc, argv);
	printResultDeque(argc, argv);
}

void PmergeMe::print(const std::deque<int> &d) const
{
	if (d.empty())
		throw InvalidInputException();
	for (unsigned int i = 0; i < d.size(); i++)
		std::cout << d[i] << " ";
	std::cout << std::endl;
}

void PmergeMe::print(const std::vector<int> &v) const
{
	if (v.empty())
		throw InvalidInputException();
	for (unsigned int i = 0; i < v.size(); i++)
		std::cout << v[i] << " ";
	std::cout << std::endl;
}

void PmergeMe::printResultVector(int argc, char **argv)
{
	clock_t startTime = clock();
	checkInputVector(argc, argv, this->_vector);
	std::vector<int> sortedVector = sortAlgorithm(this->_vector);
	std::cout << "After: ";
	print(sortedVector);
	clock_t endTime = clock();
	std::cout << "Time to process a range of " << this->_vector.size()
              << " elements with std::vector : "
              << static_cast<double>(endTime - startTime) /
                     CLOCKS_PER_SEC * 1000000
              << " us" << std::endl;
}

void PmergeMe::printResultDeque(int argc, char **argv)
{
	clock_t startTime = clock();
	checkInputDeque(argc, argv);
	std::deque<int> sortedDeque = sortAlgorithm(this->_deque);
	// std::cout << "After: ";
	// print(_deque);
	clock_t endTime = clock();
	std::cout << "Time to process a range of " << this->_deque.size()
			  << " elements with std::deque : "
			  << static_cast<double>(endTime - startTime) /
					 CLOCKS_PER_SEC * 1000000
			  << " us" << std::endl;
}

void PmergeMe::insertionSortVector(std::vector<int_pair> &pairs, int size)
{
	// Compares the second element of each pair, starts from the last pair
	for (int curr = 2; curr <= size; curr++)
	{
		int_pair last = pairs[curr - 1];
		int i = curr - 2;
		while (i >= 0 && pairs[i].second > last.second)
		{
			pairs[i + 1] = pairs[i];
			i--;
		}
		pairs[i + 1] = last;
	}
}

std::vector<int> PmergeMe::sortAlgorithm(std::vector<int> &v)
{
	
	if (v.size() <= 1)
		return v;
	// Checks if there is an odd number of elements
	int odd;
	bool uneven = v.size() % 2 == 1;
	if (uneven)
	{
		odd = v.back();
		v.pop_back();
	}

	// Creates pairs of elements
	std::vector<int_pair> pairs;
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it += 2)
	{
		int_pair pair;
		int one = *it;
		int two = *(it + 1);
		pair.first = std::min(one, two);
		pair.second = std::max(one, two);
		pairs.push_back(pair);
	}

	insertionSortVector(pairs, pairs.size());
	
	// Sorts the pairs
	std::vector<int> sorted;
	std::vector<int> pendings;
	for (std::vector<int_pair>::iterator it = pairs.begin(); it != pairs.end(); it++)
	{
		sorted.push_back(it->second);
		pendings.push_back(it->first);
	}
	// std::cout << "Sorted size: " << sorted.size() << std::endl;
	// std::cout << "Pendings size: " << pendings.size() << std::endl;
	if (uneven)
	{
		pendings.push_back(odd);
	}
	// std::cout << "Sorted pairs: ";
	// print(sorted);
	// std::cout << "Pending elements: ";
	// print(pendings);
	mergeVector(sorted, pendings);
	return sorted;
}



void PmergeMe::mergeVector(std::vector<int> &sorted, std::vector<int> &pendings)
{
	// std::cout << "Sorted size: " << sorted.size() << std::endl;
	sorted.insert(sorted.begin(), pendings.front());
	int jn_max;
	int jn_min;
	
	for (int i = 3; ; i++)
    {
        jn_max = jacobsthalNumber(i) - 1;
        jn_min = jacobsthalNumber(i - 1) - 1;
		// std::cout << "JN max: " << jn_max << std::endl;
		// std::cout << "JN min: " << jn_min << std::endl;
        if ((unsigned long)jn_max > pendings.size())
            break ;
        for (int j = jn_max; j > jn_min; j--)
        {
            if (pendings.size() > (unsigned long)j)
            {
                int loc = binarySearchVector(sorted,  pendings.at(j), 0, sorted.size());
                
                    // std::cout << std::endl;
				// 	std::cout << "Before insertion:" << std::endl;
                //     print(pendings);
				// 	std::cout << "Sorted: ";
                //     print(sorted);
                //     std::cout << j << "To insert : " << pendings.at(j) << std::endl;
                //     std::cout << "Insertion pos : " << loc << std::endl;
				// 	std::cout << "Sorted size: " << sorted.size() << std::endl;
				// std::cout << "Pendings size: " << pendings.size() << std::endl;
                if (loc == -1)
                    sorted.push_back(pendings.at(j));
                else
                    sorted.insert(sorted.begin() + loc, pendings.at(j));
				// pendings.erase(pendings.begin() + j);
            }

		}
	}
		for (unsigned long j = jn_min + 1; j < pendings.size(); j++)
		{
			int loc = binarySearchVector(sorted, pendings.at(j), 0, sorted.size());
			if (loc == -1)
                    sorted.push_back(pendings.at(j));
                else
                    sorted.insert(sorted.begin() + loc, pendings.at(j));
		}
		// mergeVector(sorted, pendings);
        // std::cout << "AFTER insertion:" << std::endl;
		// print(pendings);
		// std::cout << "Sorted: after second merge " << sorted.size() << std::endl;
		// print(sorted);
    
}

int PmergeMe::binarySearchVector(const std::vector<int> &v, int value, int start, int end)
{
	while (start <= end)
	{
		int mid = start + (end - start) / 2;
		 if ((unsigned long)mid >= v.size())
            return (-1);
		if (value == v[mid])
            return mid + 1;
		else if (value > v[mid])
			start = mid + 1;
		else
			end = mid - 1;
	}
	if ((unsigned long)start >= v.size())
        return (-1);
	return start;

}

std::deque<int> PmergeMe::sortAlgorithm(std::deque<int> &d)
{
	if (d.size() <= 1)
		return d;
	// Checks if there is an odd number of elements
	int odd;
	bool uneven = d.size() % 2 == 1;
	if (uneven)
	{
		odd = d.back();
		d.pop_back();
	}

	// Creates pairs of elements
	std::deque<int_pair> pairs;
	for (std::deque<int>::iterator it = d.begin(); it != d.end(); it += 2)
	{
		int_pair pair;
		int one = *it;
		int two = *(it + 1);
		pair.first = std::min(one, two);
		pair.second = std::max(one, two);
		pairs.push_back(pair);
	}
	insertionSortDeque(pairs, pairs.size());

	// Sorts the pairs
	std::deque<int> sorted;
	std::deque<int> pendings;
	for (std::deque<int_pair>::iterator it = pairs.begin(); it != pairs.end(); it++)
	{
		sorted.push_back(it->second);
		pendings.push_back(it->first);
	}
	if (uneven)
	{
		pendings.push_back(odd);
	}
	// std::cout << "Sorted pairs: ";
	// print(sorted);
	// std::cout << "Pending elements: ";
	// print(pendings);
	// std::cout << "Sorted size: " << sorted.size() << std::endl;
	// std::cout << "Pendings size: " << pendings.size() << std::endl;
	mergeDeque(sorted, pendings);
	// std::cout << sorted.size() << std::endl;
	return sorted;
}

void PmergeMe::mergeDeque(std::deque<int> &sorted, std::deque<int> &pendings)
{
	sorted.insert(sorted.begin(), pendings.front());
	int jn_max;
	int jn_min;
	for (int i = 3; ; i++)
    {
        jn_max = jacobsthalNumber(i) - 1;
        jn_min = jacobsthalNumber(i - 1) - 1;
        if ((unsigned long)jn_max > pendings.size())
            break ;
        for (int j = jn_max; j > jn_min; j--)
        {
            if (pendings.size() > (unsigned long)j)
            {
                int loc = binarySearchDeque(sorted,  pendings.at(j), 0, sorted.size());
                
                    // std::cout << std::endl;
					// std::cout << "Before insertion:" << std::endl;
                    // print(pendings);
					// std::cout << "Sorted: ";
                    // print(sorted);
                    // std::cout << "To insert : " << pendings.at(j) << std::endl;
                    // std::cout << "Insertion pos : " << loc << std::endl;
               
                if (loc == -1)
                    sorted.push_back(pendings.at(j));
                else
                    sorted.insert(sorted.begin() + loc, pendings.at(j));
				
				// std::cout << "Sorted size: " << sorted.size() << std::endl;
				// std::cout << "Pendings size: " << pe!ndings.size() << std::endl;
				}
        }
	}
		for (unsigned long j = jn_min + 1; j < pendings.size(); j++)
		{
			int loc = binarySearchDeque(sorted, pendings.at(j), 0, sorted.size());
			if (loc == -1)
				sorted.push_back(pendings.at(j));
			else
				sorted.insert(sorted.begin() + loc, pendings.at(j));
		}
		// std::cout << "AFTER insertion:" << std::endl;
		// print(pendings);
		// std::cout << "Sorted with Deque: ";
		// print(sorted);
    
}


void PmergeMe::insertionSortDeque(std::deque<int_pair> &pairs, int size)
{
	// Compares the second element of each pair, starts from the last pair
	for (int curr = 2; curr <= size; curr++)
	{
		int_pair last = pairs[curr - 1];
		int i = curr - 2;
		while (i >= 0 && pairs[i].second > last.second)
		{
			pairs[i + 1] = pairs[i];
			i--;
		}
		pairs[i + 1] = last;
	}
}



int PmergeMe::binarySearchDeque(const std::deque<int> &d, int value, int start, int end)
{
	while (start <= end)
	{
		int mid = start + (end - start) / 2;
		 if ((unsigned long)mid >= d.size())
            return (-1);
		if (value == d[mid])
            return mid + 1;
		else if (value > d[mid])
			start = mid + 1;
		else
			end = mid - 1;
	}
	if ((unsigned long)start >= d.size())
        return (-1);
	return start;

}



int PmergeMe::jacobsthalNumber(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return jacobsthalNumber(n - 1) + 2 * jacobsthalNumber(n - 2);
}

// std::deque<int>::const_iterator std::find(const std::deque<int> &d, int value)
// {
// 	std::deque<int>::const_iterator it = d.begin();
// 	while (it != d.end())
// 	{
// 		if (*it == value)
// 			return it;
// 		++it;
// 	}
// 	return d.end();
// }
// {
// 	if (d.empty())
// 		return;

// 	std::cout << "Deque: ";
// 	for (const auto &value : d)
// 		std::cout << value << " ";
// 	std::cout << std::endl;
// }