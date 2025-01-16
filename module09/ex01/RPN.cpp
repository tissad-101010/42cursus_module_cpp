/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tissad <tissad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:20:49 by tissad            #+#    #+#             */
/*   Updated: 2025/01/16 21:07:01 by tissad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

std::stack<int> RPN::_stack;

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

bool RPN::_isOperator(const char &c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
		return (true);
	return (false);
}

void RPN::_doOperation(const char &c)
{
	int a;
	int b;
	
	if (_stack.size() < 2)
	{
		std::cout << "Error" << std::endl;
		exit(1); ;
	}
	b = _stack.top();
	_stack.pop();
	a = _stack.top();
	_stack.pop();
	if (c == '+')
		_stack.push(a + b);
	else if (c == '-')
		_stack.push(a - b);
	else if (c == '*')
		_stack.push(a * b);
	else if (c == '/')
		_stack.push(a / b);
	else if (c == '%')
		_stack.push(a % b);
}


void RPN::rpn(const std::string &str)
{
	int i = 0;
	
	while (str[i])
	{
		if (str[i] == ' ')
		{
			i++;
			continue;
		}
		else if (isdigit(str[i]))
		{
			_stack.push(str[i] - '0');
			i++;
		}
		else if (_isOperator(str[i]))
		{
			_doOperation(str[i]);
			i++;
		}
		else
		{
			std::cout << "Error" << std::endl;
			return ;
		}
	}
	if (_stack.size() != 1)
	{
		std::cout << "Error" << std::endl;
		return ;
	}
	std::cout << _stack.top() << std::endl;
}
