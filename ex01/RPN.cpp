/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaporte <mlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 12:43:12 by mlaporte          #+#    #+#             */
/*   Updated: 2025/05/02 12:43:12 by mlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
	// oper[4] = {'+', '-', '*', '/'}
	_tab[0] = &RPN::_add;
	_tab[1] = &RPN::_sub;
	_tab[2] = &RPN::_mult;
	_tab[3] = &RPN::_div;
	// this->_tab[1] = &_sub;
	// this->_tab[2] = &_mult;
	// this->_tab[3] = &_div;

}

RPN::RPN(const RPN &src)
{
	*this = src;
}

RPN::~RPN()
{
}

RPN &RPN::operator=(const RPN &cpy)
{
	if (this != &cpy)
	{
		this->_stack = cpy._stack;
	}
	return (*this);
}


void	RPN::checkInput(std::string input)
{
	std::istringstream iss(input);
	std::string token;
	int a, b;

	while (iss >> token)
	{
		if (_isnbr(token))
		{
			_stack.push(std::atoi(token.c_str()));
		}
		else if (token == "+" || token == "-" || token == "*" ||token == "/")
		{
			if (_stack.size() < 2)
			{
				throw InvalidInputException();
			}
			b = _stack.top();
			_stack.pop();
			a = _stack.top();
			_stack.pop();
			int result = _calculate(a, b, token[0]);
			_stack.push(result);
		}
		else
		{
			throw InvalidInputException();
		}
		// std::cout << "derniere valeur " << _stack.top() << std::endl;
		
	}
	std::cout << _stack.top() << std::endl;
}

int RPN::_calculate(int a, int b, char op)
{
	// int i;
	std::string oper = "+-*/" ;
	int i = oper.find(op);
	// int result = 
	return ((this->*_tab[i])(a, b));
}

int RPN::_add(int a, int b)
{
	return (a + b);
}

int RPN::_sub(int a, int b)
{
	return (a - b);
}

int RPN::_mult(int a, int b)
{
	return (a * b);
}

int RPN::_div(int a, int b)
{
	if (b == 0)
		throw DivisionByZeroException();
	return (a / b);
}

bool RPN::_isnbr(std::string nbr)
{
	for (size_t i = 0 ;i < nbr.length(); i++)
	{
		if (nbr[i] < '0' || nbr[i] > '9')
			return false;
	}
	return true;
}

const char *RPN::InvalidInputException::what() const throw()
{
	return ("Error");
}

const char *RPN::DivisionByZeroException::what() const throw()
{
	return ("Error : Division by zero !");
}