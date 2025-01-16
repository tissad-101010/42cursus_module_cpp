/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tissad <tissad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:20:41 by tissad            #+#    #+#             */
/*   Updated: 2025/01/16 21:02:24 by tissad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RPN_HPP__
#define __RPN_HPP__

#include <iostream>
#include <string>
#include <stack>
#include <cstdlib>

class RPN
{
	private:
		static std::stack<int> _stack;
		RPN();
		RPN(const RPN &rhs);
		RPN &operator=(const RPN &rhs);
		~RPN();
		static bool _isOperator(const char &c);
		static void _doOperation(const char &c);
		
		
	public:
		static void rpn(const std::string &str);
};

#endif