/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tissad <tissad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:30:46 by tissad            #+#    #+#             */
/*   Updated: 2025/01/07 15:02:12 by tissad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstdlib>
#include <limits>
#include <iomanip>
#include <cmath>
#include <cfloat>


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

bool ScalarConverter::isChar(const std::string &literal)
{
	if ((literal.length() == 1 && !isdigit(literal[0])))
		return (true);
	else if ((literal.length() == 3 
			&& literal[0] == '\'' 
			&& literal[2] == '\''))
		return (true);
	return (false);
}

bool ScalarConverter::isInt(const std::string &literal)
{
	char	*end;
	
	std::strtol(literal.c_str(), &end, 10);
	if (*end == '\0')
		return (true);
	return (false);
}

bool ScalarConverter::isFloat(const std::string &literal)
{
	char	*end;
	
	std::strtof(literal.c_str(), &end);
	if (*end == 'f' && *(end + 1) == '\0')
		return (true);
	return (false);
}

bool ScalarConverter::isDouble(const std::string &literal)
{
	char	*end;
	
	std::strtod(literal.c_str(), &end);
	if (*end == '\0')
		return (true);
	return (false);
}

bool ScalarConverter::isSpecial(const std::string &literal)
{
	if (literal == "nan"
		|| literal == "-inf"
		|| literal == "+inf"
		|| literal == "inf")
		return (true);
	return (false);
}

e_type ScalarConverter::getType(const std::string &literal)
{
	
	if (isSpecial(literal))
		return (SPECIAL);
	else if (isChar(literal))
		return (CHAR);
	else if (isInt(literal))
		return (INT);
	else if (isFloat(literal))
		return (FLOAT);
	else if (isDouble(literal))
		return (DOUBLE);
	return (INVALID);
}

void ScalarConverter::printChar(long c)
{
	std::cout << "char: ";
	if (c > std::numeric_limits<char>::max() || c < 0)
		std::cout << "impossible" << std::endl;
	else if (!isprint(static_cast<char> (c)))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "\'" <<static_cast<char>(c) << "\'" << std::endl;
}

void ScalarConverter::printInt(long i)
{
	std::cout << "int: ";
	if (i > std::numeric_limits<int>::max() || i < std::numeric_limits<int>::min())
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int> (i) << std::endl;
}

void ScalarConverter::printFloat(float f)
{
	std::cout << "float: ";
	try
	{
		if (std::isnan(f) || std::isinf(f))
		 	throw std::overflow_error("impossible");
		else
			std::cout << f << "f" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void ScalarConverter::printDouble(double d)
{
	std::cout << "double: ";
	try
	{
		if (std::isnan(d) || std::isinf(d))
			throw std::overflow_error("impossible");
		std::cout << d << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void ScalarConverter::convertChar(const std::string &literal)
{
	long	c;
	
	c = static_cast<long>(literal[0]);
	if (literal.length() == 3)
		c = static_cast<long>(literal[1]);
	printChar(c);
	printInt(c);
	printFloat(static_cast<float>(c));
	printDouble(static_cast<double>(c));
}

void ScalarConverter::convertInt(const std::string &literal)
{
	char	*end;
	long	i;

	i = std::strtol(literal.c_str(), &end, 10);
	printChar(i);
	printInt(i);
	printFloat(static_cast<float>(i));
	printDouble(static_cast<double>(i));
}

void ScalarConverter::convertFloat(const std::string &literal)
{
	char	*end;
	double	f;

	f = std::strtof(literal.c_str(), &end);
	printChar(static_cast<long>(f));
	printInt(static_cast<long>(f));
	printFloat(f);
	printDouble(f);
}	

void ScalarConverter::convertSpecial(const std::string &literal)
{
	
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (literal == "nan")
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;	
	}
	else if (literal == "-inf")
	{
		printFloat(-INFINITY);
		printDouble(-INFINITY);
	}
	else if (literal == "+inf" || literal == "inf")
	{
		printFloat(INFINITY);
		printDouble(INFINITY);
	}
}

int ScalarConverter::getPrecision(const std::string &literal)
{
	int count = 0;
	
	for (size_t i = 0; i < literal.length(); i++)
	{
		if (literal[i] == '.')
		{
			count = literal.length() - i - 1;
			break;	
		}
	}
	count = (count == 0) ? 1 : count;
	return (count);
}

void ScalarConverter::convert(const std::string &literal)
{
	// use swtich case to call the right function
	// based on the type of the literal
	
	std::cout << std::fixed << std::setprecision(getPrecision(literal));
	e_type type = getType(literal);
	
	switch (type)	// switch case
	{
		case CHAR:
			convertChar(literal);
			break;
		case INT:
			convertInt(literal);
			break;
		case FLOAT:
			convertFloat(literal);
			break;
		case DOUBLE:
			convertFloat(literal);
			break;
		case SPECIAL:
			convertSpecial(literal);
			break;
		case INVALID:
			std::cout << "Invalid input" << std::endl;
			break;
	}
}