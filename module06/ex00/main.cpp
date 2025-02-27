/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tissad <tissad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:50:43 by tissad            #+#    #+#             */
/*   Updated: 2025/01/09 22:56:10 by tissad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <limits>
#include <float.h>
#include <math.h>
#include <stdio.h>


int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Usage: ./convert literal" << std::endl;
        return (1);
    }
    
    ScalarConverter::convert(av[1]);

    // std::cout << std::endl << std::numeric_limits<int>::max() << std::endl;
    // std::cout << std::endl << static_cast<float>(std::numeric_limits<int>::max()) << std::endl;
    // std::cout << std::endl << static_cast<double>(std::numeric_limits<int>::max()) << std::endl;
    
    return (0);
}