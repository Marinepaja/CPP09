/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaporte <mlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:28:22 by mlaporte          #+#    #+#             */
/*   Updated: 2025/05/02 15:28:22 by mlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc == 1)
		return (1);

	try 
	{
		PmergeMe pmerge;
		pmerge.checkInput(argc, argv);
	}
	catch (const PmergeMe::DuplicateValueException &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
}