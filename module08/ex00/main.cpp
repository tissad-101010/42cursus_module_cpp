/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tissad <tissad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:43:24 by tissad            #+#    #+#             */
/*   Updated: 2025/01/03 22:08:21 by tissad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <deque> // Inclure std::deque
#include "easyfind.hpp"


int main() {
    try {
        // Containers initialisation
        // array of integers
        const int array[] = {1, 2, 3, 4, 5};
        const int arraySize = sizeof(array) / sizeof(array[0]);
    
        // tests with std::vector
        std::vector<int> vec(array, array + arraySize);
        std::cout << "Testing with std::vector..." << std::endl;
        std::vector<int>::const_iterator it = easyfind(vec, 3);
        std::cout << "Found: " << *it << std::endl;

        // tests with std::list
        std::list<int> lst(array, array + arraySize);
        std::cout << "Testing with std::list..." << std::endl;
        std::list<int>::const_iterator lit = easyfind(lst, 2);
        std::cout << "Found: " << *lit << std::endl;

        // tests whith std::deque
        std::deque<int> deq(array, array + arraySize);
        std::cout << "Testing with std::deque..." << std::endl;
        std::deque<int>::const_iterator dit = easyfind(deq, 5);
        std::cout << "Found: " << *dit << std::endl;

        // Cas d'échec
        std::cout << "Testing with value not found..." << std::endl;
        easyfind(vec, 42); // Should throw an exception
    } catch (const NotFoundException& e) {
        std::cerr << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
    }

    return 0;
}
