/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tissad <tissad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:23:19 by tissad            #+#    #+#             */
/*   Updated: 2025/01/14 17:40:27 by tissad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int main(int ac, char **av)
{
	// open the file av[1]
	if (ac != 2)
	{
		std::cerr << "Usage: ./bitcoin [filename]" << std::endl;
		return (1);
	}
	BitcoinExchange::exchange(av[1]);
	return (0);
}