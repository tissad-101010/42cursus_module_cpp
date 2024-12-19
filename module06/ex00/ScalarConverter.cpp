/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tissad <tissad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:30:46 by tissad            #+#    #+#             */
/*   Updated: 2024/12/19 21:11:10 by tissad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <limits>
#include <iomanip>

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(ScalarConverter const &other)
{
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter const &other)
{
	(void)other;
	return (*this);
}
ScalarConverter::~ScalarConverter(){};

void ScalarConverter::printChar(char c)
{
	std::cout << "char: ";
	if (isprint(c))
		std::cout << "\'" << c << "\'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
}

void ScalarConverter::convertChar(const std::string &literal)
{
	if (literal.length() == 1)
	{
		printChar(literal[0]);
		std::cout << "int: " << static_cast<int>(literal[0]) << std::endl;
		std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(literal[0]) << "f" << std::endl;
		std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(literal[0]) << std::endl;
		exit(0);
	}
	else if (literal == "0")
	{
		printChar('\0');
		std::cout << "int: 0" << std::endl;
		std::cout << std::fixed << std::setprecision(1) << "float: 0.0f" << std::endl;
		std::cout << std::fixed << std::setprecision(1) << "double: 0.0" << std::endl;
		exit(0);
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
		exit(0);
	}

}

void ScalarConverter::convertInt(const std::string &literal)
{
	char *end;
	
	int i = std::strtol(literal.c_str(), &end, 10);

	if (*end != '\0' || i > std::numeric_limits<int>::max() || i < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
	{
		printChar(static_cast<char>(i));
		std::cout << "int: " << i << std::endl;
		std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(i) << "f" << std::endl;
		std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(i) << std::endl;
		exit(0);
	}
}

void ScalarConverter::convertFloat(const std::string &literal)
{
	char *end;
	
	float f = std::strtof(literal.c_str(), &end);

	if (*end != '\0' || f > std::numeric_limits<float>::max() || f < std::numeric_limits<float>::min())
		std::cout << "float: impossible" << std::endl;
	else
	{
		printChar(static_cast<char>(f));	
		std::cout << "int: " << static_cast<int>(f) << std::endl;
		std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(f) << "f" << std::endl;
		std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(f) << std::endl;
		exit(0);
	}
}	

void ScalarConverter::convert(const std::string &literal)
{
	ScalarConverter::convertChar(literal);
	ScalarConverter::convertInt(literal);
	ScalarConverter::convertFloat(literal);
	//ScalarConverter::convertDouble(literal);
}