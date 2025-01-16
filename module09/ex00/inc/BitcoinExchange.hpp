/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tissad <tissad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:23:00 by tissad            #+#    #+#             */
/*   Updated: 2025/01/16 16:52:09 by tissad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BITCOINEXCHANGE_HPP__
# define __BITCOINEXCHANGE_HPP__

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <exception>
//library for strtod
#include <cstdlib>

#define PATHDATA "data/data.csv"
#define PATHERROR "data/invalidData.csv"

class BitcoinExchange
{
	private:
		static std::map<std::string, double> _exchangeRate;

		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);
		BitcoinExchange &operator=(const BitcoinExchange &rhs); 
		~BitcoinExchange();
		
		static void _initExchangeRate(const std::string& filename);
		static void _parseLine(std::string line);
		static void _exchangeRateLine(std::string line);
		static void _printExchangeRateLine(const std::string& currency, double rate);
		static void _exchangeRateFile(const std::string& filename);
		
		//Exception class for invalid line
		class InvalidLine : public std::exception
		{
			private:
				std::string * _error;
			public:
				InvalidLine(const std::string& line);
				~InvalidLine() throw();
				const char *what() const throw();
		};
		
	public:
		static void exchange(const std::string& filename);
		//Exception class for invalid file
		class InvalidFile : public std::exception
		{
			private:
				const std::string * _error;
			public:
				InvalidFile(const std::string& filename);
				~InvalidFile() throw();
				const char *what() const throw();
		};
};
#endif