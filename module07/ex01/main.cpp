/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tissad <tissad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 22:24:21 by tissad            #+#    #+#             */
/*   Updated: 2025/01/03 18:22:29 by tissad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

// A function to be applied to each element of the array
void printInt(int x){
    std::cout << x << " ";
}
// A function squaring an integer
void sqrInt(int& x) {
    x *= x;
}

int main() {
    // Test with an array of integers
    int intArray[] = {1, 2, 3, 4, 5};
    std::size_t intArrayLength = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Original intArray: ";
    iter(intArray, intArrayLength, printInt);  // Applies printInt
    std::cout << "\n";

    std::cout << "Square intArray: ";
    iter(intArray, intArrayLength, sqrInt);  // Applies doubleInt
    iter(intArray, intArrayLength, print<int>);
    std::cout << "\n";

    // Test with an array of strings
    std::string strArray[] = {"hello", "world", "iter", "template"};
    std::size_t strArrayLength = sizeof(strArray) / sizeof(strArray[0]);

    std::cout << "String array: ";
    iter(strArray, strArrayLength, print<std::string>);
    std::cout << "\n";

    return 0;
}