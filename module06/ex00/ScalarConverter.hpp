/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tissad <tissad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:03:22 by tissad            #+#    #+#             */
/*   Updated: 2025/01/07 12:28:27 by tissad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCALARCONVERTER_HPP__
#define __SCALARCONVERTER_HPP__


#include <iostream>
#include <string>

enum e_type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	SPECIAL,
	INVALID
};

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &other);
		ScalarConverter &operator=(ScalarConverter const &other);
		~ScalarConverter();
		
		static e_type getType(const std::string &literal);
		
		static bool isSpecial(const std::string &literal);
		static bool isChar(const std::string &literal);
		static bool isInt(const std::string &literal);
		static bool isFloat(const std::string &literal);
		static bool isDouble(const std::string &literal);
		
		static void printChar(long c);
		static void printInt(long i);
		static void printFloat(double f);
		static void printDouble(double d);

		static void convertChar(const std::string &literal);
		static void convertInt(const std::string &literal);
		static void convertFloat(const std::string &literal);
		
        static void convertSpecial(const std::string &literal);

		static int getPrecision(const std::string &literal);

    public:
	
		static void convert(const std::string &literal);
		
};
#endif