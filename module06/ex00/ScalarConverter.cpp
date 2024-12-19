/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tissad <tissad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:30:46 by tissad            #+#    #+#             */
/*   Updated: 2024/12/19 15:38:17 by tissad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstdlib>
#include <limits>

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

const char * ScalarConverter::ImpossibleConversionException::what() const throw()
{
	return ("impossible");
};

const char * ScalarConverter::NonDisplayableException::what() const throw()
{
	return ("Non displayable");
};

void ScalarConverter::convert(const std::string &literal)
{
	std::cout << literal << std::endl;
}