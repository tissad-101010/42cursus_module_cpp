/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tissad <tissad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:03:22 by tissad            #+#    #+#             */
/*   Updated: 2024/12/19 20:36:11 by tissad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCALARCONVERTER_HPP__
#define __SCALARCONVERTER_HPP__


#include <iostream>
#include <string>

#define CHAR 1
#define INT 2
#define FLOAT 3
#define DOUBLE 4

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &other);
		ScalarConverter &operator=(ScalarConverter const &other);
		~ScalarConverter();
		
		static void convertChar(const std::string &literal);
		static void convertInt(const std::string &literal);
		static void convertFloat(const std::string &literal);
		static void convertDouble(const std::string &literal);
		static void printChar(char c);
		
	public:
	
		static void convert(const std::string &literal);
		
};
#endif