/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tissad <tissad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 22:18:14 by tissad            #+#    #+#             */
/*   Updated: 2025/01/13 17:45:03 by tissad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SPAN_HPP__
#define __SPAN_HPP__

#include <vector>
#include <algorithm>
#include <exception>

class Span
{
	private:
		unsigned int maxSize;
		std::vector<int> numbers;
	public:

		Span(unsigned int N);
		~Span();


		void addNumber(int number);
		template <typename Iterator>
		void addNumbers(Iterator begin, Iterator end);
		int shortestSpan() const;
		int longestSpan() const;

		class SpanFullException : public std::exception {
		public:
			const char* what() const throw() {
				return "Span is already full!";
			}
		};

		class NotEnoughNumbersException : public std::exception {
		public:
			const char* what() const throw() {
				return "Not enough numbers in Span to calculate span!";
			}
		};
};


template <typename Iterator>
void Span::addNumbers(Iterator begin, Iterator end) {
    if (std::distance(begin, end) + numbers.size() > maxSize) {
        throw SpanFullException();
    }
    numbers.insert(numbers.end(), begin, end);
}

#endif // __SPAN_HPP__
