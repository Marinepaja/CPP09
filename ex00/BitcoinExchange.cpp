/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaporte <mlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 11:20:54 by mlaporte          #+#    #+#             */
/*   Updated: 2025/04/18 11:20:54 by mlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	*this = src;
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &cpy)
{
	if (this != &cpy)
	{
		this->_data = cpy._data;
	}
	return (*this);
}

void BitcoinExchange::checkInput(std::string filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file " << filename << std::endl;
		return ;
	}
	std::string line;
	std::string sep;
	std::string date;
	float value;

	try
	{
		_firstLine(line, file);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << " First line must be 'date | value'" << std::endl;
	}
	
	// if (std::getline(file, line) && line.compare ("date | value"))
	// {
	// 	// std::cout << line.compare("date | value") << std::endl;
	// 	std::cerr << line << std::endl << "Error: first line should be 'date | value'" << std::endl;
	// 	return ;
	// }
	while (std::getline(file, line))
	{
		std::istringstream iss(line);
		iss >> date >> sep >> value;
		// if (sep != "|")
		// 	std::cerr << "Error: bad input => " << line << std::endl;
		try
		{

			if (sep != "|")
				throw BitcoinExchange::InvalidDateException();	
			_checkDate(date);
			_checkValue(value);
			_print_btc(date, value);
		}
		catch(const BitcoinExchange::InvalidDateException& e)
		{
			std::cerr << e.what() << " => " << 	line << std::endl;
		}
		catch(const BitcoinExchange::NegativeNumberException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(const BitcoinExchange::TooLargeNumberException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		// std::cout << date << " | " << value << std::endl;
	}
	file.close();
	}

void BitcoinExchange::_firstLine(std::string line, std::ifstream &file)
{
	if (!std::getline(file, line))
		throw BitcoinExchange::InvalidDateException();
	if (line.empty())
		throw BitcoinExchange::InvalidDateException();
	if (line.find("date") != 0 || line.find("|") != 5)
		throw BitcoinExchange::InvalidDateException();
	if (line.find("value") != 7)
		throw BitcoinExchange::InvalidDateException();
}


void BitcoinExchange::getData(void)
{
	std::ifstream file("data.csv");
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file data.csv" << std::endl;
		return;
	}
	std::string line;
	std::string date;
	float value;
	while (std::getline(file, line))
	{
		line.replace(line.find(','), 1, " ");
		std::istringstream iss(line);
		
		iss >> date >> value;
		_data[date] = value;
		// std::cout << date << " | " << value << std::endl;
	}
}

void BitcoinExchange::_checkDate(std::string date)
{
	int year, month, day;
	if (!date.compare("date"))
		return ;
	if ((date.length() != 10) || date[4] != '-' || date[7] != '-')
		throw BitcoinExchange::InvalidDateException();
	std::istringstream iss(date);
	iss >> year;
	if (year < 2009 || year > 2022 )
		throw BitcoinExchange::InvalidDateException();
	iss.ignore(1);
	iss >> month;
	if (month < 1 || month > 12)
		throw BitcoinExchange::InvalidDateException();
	iss.ignore(1);
	iss >> day;
	if (day < 1 || day > 31)
		throw BitcoinExchange::InvalidDateException();
	else if (month == 2 && day > 29)
		throw BitcoinExchange::InvalidDateException();
	else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		throw BitcoinExchange::InvalidDateException();
	else if (year == 2009 && month == 1 && day < 3)
		throw BitcoinExchange::InvalidDateException();
	else
		return ;
	
}

void BitcoinExchange::_checkValue(float value)
{
	if (value < 0)
		throw BitcoinExchange::NegativeNumberException();
	else if (value > 1000)
		throw BitcoinExchange::TooLargeNumberException();
	else
		return ;
}

void BitcoinExchange::_print_btc(std::string date, float value)
{
	std::map<std::string, float>::iterator it = _data.lower_bound(date);
	if (it->first != date && it != _data.begin())
		it--;
	std::cout << date << " => " << value << " = " << value * it->second << std::endl;
}

const char *BitcoinExchange::InvalidDateException::what() const throw()
{
	return ("Error: bad input");
}

const char *BitcoinExchange::NegativeNumberException::what() const throw()
{
	return ("Error: not a positive number.");
}

const char *BitcoinExchange::TooLargeNumberException::what() const throw()
{
	return ("Error: too large a number.");
}