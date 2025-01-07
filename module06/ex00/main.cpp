/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tissad <tissad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:50:43 by tissad            #+#    #+#             */
/*   Updated: 2025/01/07 12:10:50 by tissad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <limits>

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Usage: ./convert literal" << std::endl;
        return (1);
    }
    ScalarConverter::convert(av[1]);
    
    std::cout << std::endl << 214748.9 << std::endl;
    
    // std::cout << std::endl << std::numeric_limits<int>::max() << std::endl;
    // std::cout << std::endl << static_cast<float>(std::numeric_limits<int>::max()) << std::endl;
    // std::cout << std::endl << static_cast<double>(std::numeric_limits<int>::max()) << std::endl;
    return (0);
}