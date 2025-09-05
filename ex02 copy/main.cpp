/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 07:23:02 by mechard           #+#    #+#             */
/*   Updated: 2025/03/29 07:23:02 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool isPositiveNumber(const std::string &s)
{
	for (size_t i = 0; i < s.size(); ++i)
	{
		if (!std::isdigit(s[i]))
			return false;
	}
	return true;
}

int main(int argc, char **argv)
{
	if (argc < 2) {
		std::cerr << "Error" << std::endl;
		return 1;
	}
	PmergeMe pm;
	for (int i = 1; i < argc; ++i)
	{
		std::string token = argv[i];
		if (!isPositiveNumber(token))
			return std::cerr << "Error" << std::endl, 1;
		if (!pm.addNumber(token))
			return std::cerr << "Error" << std::endl, 1;
	}
	pm.printBefore();
	double timeVector = pm.sortVector();
	double timeDeque = pm.sortDeque();
	pm.printAfterVector();
	std::cout << std::fixed << std::setprecision(5) << "Time to process a range of " << argc - 1 << " elements with std::vector : " << timeVector << " us" << std::endl;
	std::cout << std::fixed << std::setprecision(5) << "Time to process a range of " << argc - 1 << " elements with std::deque : " << timeDeque << " us" << std::endl;

	return 0;
}
