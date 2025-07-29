/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaporte <mlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 12:20:48 by mlaporte          #+#    #+#             */
/*   Updated: 2025/05/02 12:20:48 by mlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <cstdlib>


class RPN
{

	public:
		class InvalidInputException : public std::exception
		{
			public :
				virtual const char *what() const throw();
		};
		class DivisionByZeroException : public std::exception
		{
			public :
				virtual const char *what() const throw();
		};
		RPN();
		RPN(const RPN &src);
		~RPN();
		RPN &operator=(const RPN &cpy);
		void checkInput(std::string input);
		
	private:
		std::stack<int> _stack;
		void _checkOperator(char c);
		bool _isnbr(std::string str);
		int _calculate(int a, int b, char op);

		typedef int (RPN::*func)(int, int);
		func	_tab[4];
		int	_add(int a, int b);
		int	_mult(int a, int b);
		int	_sub(int a, int b);
		int	_div(int a, int b);
};

#endif