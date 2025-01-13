/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tissad <tissad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 22:23:45 by tissad            #+#    #+#             */
/*   Updated: 2025/01/13 17:48:11 by tissad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <limits>

// Constructor
Span::Span(unsigned int N) : maxSize(N) {}

// Destructor
Span::~Span() {}

// add number to the vector
void Span::addNumber(int number) {
	if (numbers.size() >= maxSize) {
		throw SpanFullException();
	}
	numbers.push_back(number);
}

// shortestSpan
int Span::shortestSpan() const {
	if (numbers.size() < 2) {
		throw NotEnoughNumbersException();
	}

	std::vector<int> sorted = numbers;
	std::sort(sorted.begin(), sorted.end());

	int shortest = std::numeric_limits<int>::max();
	for (size_t i = 1; i < sorted.size(); ++i) {
		int span = sorted[i] - sorted[i - 1];
		if (span < shortest) {
			shortest = span;
		}
	}
	return shortest;
}

// longestSpan
int Span::longestSpan() const {
	if (numbers.size() < 2) {
		throw NotEnoughNumbersException();
	}

	int minElement = *std::min_element(numbers.begin(), numbers.end());
	int maxElement = *std::max_element(numbers.begin(), numbers.end());

	return maxElement - minElement;
}
