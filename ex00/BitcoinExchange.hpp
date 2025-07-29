/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaporte <mlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 10:37:48 by mlaporte          #+#    #+#             */
/*   Updated: 2025/04/18 10:37:48 by mlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

class BitcoinExchange
{
	public:
		class InvalidDateException : public std::exception
		{
			public :
				virtual const char *what() const throw();
		};
		class NegativeNumberException : public std::exception
		{
			public :
				virtual const char *what() const throw();
		};
		class TooLargeNumberException : public std::exception
		{
			public :
				virtual const char *what() const throw();
		};
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);
		~BitcoinExchange();
		BitcoinExchange &operator=(const BitcoinExchange &rhs);
		void checkInput(std::string filename);
		void getData(void);

	private : 
		std::map<std::string, float> _data;
		void _checkDate(std::string date);
		void _checkValue(const float value);
		void _print_btc(std::string date, float value);
		void _firstLine(std::string line, std::ifstream &file);
		
};

#endif