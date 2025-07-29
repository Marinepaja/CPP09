/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaporte <mlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 12:18:43 by mlaporte          #+#    #+#             */
/*   Updated: 2025/05/02 12:18:43 by mlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main (int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: './RPN <polish notation string>' " << std::endl;
		return (1);
	}
	RPN rpn;
	try
	{
		rpn.checkInput(argv[1]);
		// rpn._printResult();
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	


}