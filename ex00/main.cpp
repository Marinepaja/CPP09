/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaporte <mlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 10:35:18 by mlaporte          #+#    #+#             */
/*   Updated: 2025/04/18 10:35:18 by mlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	BitcoinExchange btc;
	if (argc != 2)
	{
		std::cerr << "Error: wrong number of arguments" << std::endl;
		return 1;
	}
	btc.getData();
	btc.checkInput(argv[1]);
	
	// BitcoinExchange exchange;
	// if (!exchange.loadData("data.csv"))
	// {
	// 	std::cerr << "Error: could not load data" << std::endl;
	// 	return 1;
	// }

	// if (!exchange.processInput(argv[1]))
	// {
	// 	std::cerr << "Error: could not process input" << std::endl;
	// 	return 1;
	// }

	return 0;
}