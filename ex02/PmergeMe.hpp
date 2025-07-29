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

class PmergeMe
{

	private:
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		std::deque<int> _deque;
		std::vector<int> _vector;
	public:
		PmergeMe();
		~PmergeMe();
		class DuplicateValueException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Invalid input: duplicate values are not allowed.";
				}
		};

		void checkInput(int argc, char **argv);
		void sort(std::deque<int> &d);
		void sort(std::vector<int> &v);
		void printResult(const std::deque<int> &) const;
		void printResult(const std::vector<int> &) const;
};


#endif