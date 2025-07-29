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

void PmergeMe::checkInput(int argc, char **argv)
{
	if (argc > 1)
	{
		for (int i = 1; i < argc; i++)
		{
			int value = std::atoi(argv[i]);
			if (std::find(_deque.begin(), _deque.end(), value) != _deque.end())
				throw DuplicateValueException();
			_deque.push_back(value);
			_vector.push_back(value);
		}
	}

}


std::deque<int>::const_iterator std::find(const std::deque<int> &d, int value)
{
	std::deque<int>::const_iterator it = d.begin();
	while (it != d.end())
	{
		if (*it == value)
			return it;
		++it;
	}
	return d.end();
}
// {
// 	if (d.empty())
// 		return;

// 	std::cout << "Deque: ";
// 	for (const auto &value : d)
// 		std::cout << value << " ";
// 	std::cout << std::endl;
// }