/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tissad <tissad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:20:49 by tissad            #+#    #+#             */
/*   Updated: 2025/01/16 18:26:06 by tissad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"


RPN::RPN()
{
}

RPN::RPN(const RPN &rhs)
{
	(void)rhs;
}

RPN &RPN::operator=(const RPN &rhs)
{
	(void)rhs;
	return (*this);
}


RPN::~RPN()
{
}


void RPN::rpn(const std::string &str)
{
	std::stack<int> stack;
	std::string ops = "+-/*";
	for(size_t i = 0; i < str.size(); i++)
	{
		if (str[i] != ' ' && !isdigit(str[i]) && ops.find(str[i]) == std::string::npos)
		{	
			std::cout << "yyyyyError" << std::endl;
			return;	
		}
		while (str[i] && str[i] == ' ')
			i++;
		if (isdigit(str[i]))
			stack.push((str[i] - '0'));
		while (str[i] && str[i] == ' ')
			i++;
		if (ops.find(str[i]) != std::string::npos && stack.size() == 2)
		{
			int a = stack.top();
			stack.pop();
			int b = stack.top();
			stack.pop();
			if (str[i] == '+')
				stack.push(b + a);
			else if (str[i] == '-')
				stack.push(b - a);
			else if (str[i] == '/')
				stack.push(b / a);
			else if (str[i] == '*')
				stack.push(b * a);
		}
	}
	if (stack.size() == 1)
		std::cout << stack.top() << std::endl;
	else
		std::cout << "Error" << std::endl;
}
