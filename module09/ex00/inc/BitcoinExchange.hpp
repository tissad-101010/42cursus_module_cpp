/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tissad <tissad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:23:00 by tissad            #+#    #+#             */
/*   Updated: 2025/01/14 17:45:49 by tissad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BITCOINEXCHANGE_HPP__
# define __BITCOINEXCHANGE_HPP__

#include <iostream>
#include <fstream>
#include <string>
#include <map>

class BitcoinExchange
{
    private:
        static std::map<std::string, double> _exchangeRate;

        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &src);
        BitcoinExchange &operator=(const BitcoinExchange &rhs); 
        ~BitcoinExchange();
        
        static void _initExchangeRate();
        static void _parseLine(std::string line);
        static void _printExchangeRate();
    
    public:
        static void exchange(std::string filename);
};

#endif