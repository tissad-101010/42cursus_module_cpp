/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tissad <tissad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:03:22 by tissad            #+#    #+#             */
/*   Updated: 2024/12/19 15:36:14 by tissad           ###   ########.fr       */
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
		class ImpossibleConversionException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class NonDisplayableException : public std::exception
		{
			public:
				const char *what() const throw();
		};
	public:
	
		static void convert(const std::string &literal);
		
};
#endif