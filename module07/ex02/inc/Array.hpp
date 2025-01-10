/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tissad <tissad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 22:42:46 by tissad            #+#    #+#             */
/*   Updated: 2025/01/10 14:52:01 by tissad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ARRAY_HPP__
#define __ARRAY_HPP__

#include <stdexcept> // For std::exception

template <typename T>
class Array {
	private:
		T* _data;				// Pointer to the dynamically allocated array
		std::size_t _size;		// Size of the array

	public:
		// Default constructor: Creates an empty array
		Array();

		// Constructor with size parameter
		Array(unsigned int n);

		// Copy constructor
		Array(const Array& other);

		// Destructor
		~Array();

		// Assignment operator
		Array& operator=(const Array& other);

		// Subscript operator for accessing elements (read and write)
		T& operator[](std::size_t index);

		// Subscript operator for accessing elements (read-only)
		const T& operator[](std::size_t index) const;

		// Member function to get the size of the array
		std::size_t size() const;
		
		// iter function template
		template <typename F>
		void iter(F function);
};

// overloading operator << to print Array elements
template <typename U>
std::ostream& operator<<(std::ostream& os, const Array<U>& array);

#include "../src/Array.tpp" // Include template implementation file

#endif // __ARRAY_HPP__
