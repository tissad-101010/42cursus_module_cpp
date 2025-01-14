/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tissad <tissad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:43:24 by tissad            #+#    #+#             */
/*   Updated: 2025/01/14 12:16:15 by tissad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits>

#define MAX_INT 10000

int main() {
	try {
		// testing with a small number of elements
		std::cout << "********tests addNumber with a small number of elements********" << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl << std::endl;
	
		// testing with a large number of elements 
		std::cout << "********tests addNumbers with a large number of elements********" << std::endl;
		// generate a vector of random numbers
		std::vector<int> vec;
		
		srand(time(NULL));
		
		for (int i = 0; i < MAX_INT; ++i) {
			vec.push_back(std::rand() % std::numeric_limits<int>::max());
		}
		
		Span largeSpan(MAX_INT);
		
		largeSpan.addNumbers(vec.begin(), vec.end());
		std::cout << "Shortest Span: " << largeSpan.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << largeSpan.longestSpan() << std::endl << std::endl;

		// testing with a small number of elements
		std::cout << "********Throw an exception********" << std::endl;        
		Span smallSpan(2);
		smallSpan.addNumber(1);
		smallSpan.addNumber(2);
		std::cout << smallSpan << std::endl;
		smallSpan.addNumber(3); // should throw an exception
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}