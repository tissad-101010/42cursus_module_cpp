/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tissad <tissad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:23:03 by tissad            #+#    #+#             */
/*   Updated: 2025/01/16 17:09:44 by tissad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "utils.hpp"

std::map<std::string, double> BitcoinExchange::_exchangeRate;

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	*this = src;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
	if (this != &rhs)
	{
		this->_exchangeRate = rhs._exchangeRate;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::InvalidFile::InvalidFile(const std::string& filename)
: exception(), _error(new std::string("Error: could not open file: " + filename))
{
}

BitcoinExchange::InvalidLine::InvalidLine(const std::string& line)
: exception(), _error(new std::string("Error: Invalid line : " + line))
{
}

BitcoinExchange::InvalidFile::~InvalidFile() throw()
{
	delete this->_error;
}

BitcoinExchange::InvalidLine::~InvalidLine() throw()
{
	delete this->_error;
}

//Exception class for invalid file
const char *BitcoinExchange::InvalidFile::what() const throw()
{	
	return (this->_error->c_str());
}

//Exception class for invalid line
const char *BitcoinExchange::InvalidLine::what() const throw()
{
	return (this->_error->c_str());
}



//parse the line and add it to the exchangeRate map
void BitcoinExchange::_parseLine(std::string line)
{
	std::string currency;
	double rate;
	size_t pos;
	
	pos = line.find(",");
	if (pos == std::string::npos 
		|| isValidDouble(line.substr(pos + 1)) != VALID
		|| !isValidDate(line.substr(0, pos)))
	{
		//throw an exception if the line is invalid
		throw InvalidLine(line);
	}
	currency = line.substr(0, pos);
	rate = std::strtod(line.substr(pos + 1).c_str(), NULL);
	_exchangeRate[currency] = rate;
}

void BitcoinExchange::_initExchangeRate(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	std::string line;
	
	if(filename.find(".csv") == std::string::npos)
	{
		throw InvalidFile(filename);
	}
	if (!file.is_open())
	{
		throw InvalidFile(filename);
	}
	std::getline(file, line);
	if ((line != "date,exchange_rate"))
	{
		throw InvalidFile(filename);
	}
	while (std::getline(file, line))
	{
		_parseLine(line);
	}
	file.close();
}

void BitcoinExchange::_printExchangeRateLine(const std::string& currency, double rate)
{
		std::string key = currency;
		
		if (_exchangeRate.find(currency) == _exchangeRate.end())
		{
			std::map<std::string, double>::const_iterator it = _exchangeRate.lower_bound(currency);
			if (it != _exchangeRate.begin())
				--it;
			else
			{
				std::cerr << "Error: no previous value." << std::endl;
				return;
			}
			key = it->first;
		}
		//std::cout << key << std::endl;
		std::cout	<< currency << " => " << rate
					<<  " = " << static_cast<double>(rate)  * static_cast<double>(_exchangeRate[key])
					<< std::endl;
}

void BitcoinExchange::_exchangeRateLine(std::string line)
{

	size_t pos;
	
	pos = line.find("|");
	if (pos == std::string::npos)
		std::cerr << "Error: bad input => " << line  << std::endl;
	else if (isValidDouble(line.substr(pos + 2)) == NEGATIVE)
		std::cerr << "Error: not a positive number." << std::endl;
	else if (isValidDouble(line.substr(pos + 2)) == LARGE)
		std::cerr << "Error: too large a number." << std::endl;
	else if (isValidDouble(line.substr(pos + 2)) == OTHER)
		std::cerr << "Error: bad value => " << line  << std::endl;
	else if (!isValidDate(line.substr(0, pos - 1)))
		std::cerr << "Error: bad input => " << line << std::endl;
	else
	{
		_printExchangeRateLine(line.substr(0, pos - 1), std::strtod(line.substr(pos + 2).c_str(), NULL));
	}
}




void BitcoinExchange::_exchangeRateFile(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	std::string line;
	if (!file.is_open())
	{
		throw InvalidFile(filename);
	}
	std::getline(file, line);
	if (! (line == "date | value"))
		_exchangeRateLine(line);
	while (std::getline(file, line))
	{
		_exchangeRateLine(line);
	}
	file.close();
}

void BitcoinExchange::exchange(const std::string& filename)
{
	(void)filename;
	try
	{
		_initExchangeRate(PATHDATA);
	}
	catch (std::exception &e)
	{
		// delete the exchangeRate map
		_exchangeRate.clear();
		std::cerr << e.what() << std::endl;
		return;
	}
	_exchangeRateFile(filename);
	
}

// $> ./btc input.txt
// 2011-01-03 => 3 = 0.9
// 2011-01-03 => 2 = 0.6
// 2011-01-03 => 1 = 0.3
// 2011-01-03 => 1.2 = 0.36
// 2011-01-09 => 1 = 0.32
// Error: not a positive number.
// Error: bad input => 2001-42-42
// 2012-01-11 => 1 = 7.1
// Error: too large a number