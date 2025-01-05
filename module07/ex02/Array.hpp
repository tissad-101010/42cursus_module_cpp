/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tissad <tissad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 22:42:46 by tissad            #+#    #+#             */
/*   Updated: 2025/01/03 18:19:11 by tissad           ###   ########.fr       */
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

// A function squaring an integer
void sqrInt(int& x);
// function that transforms an string to uppercase
void toUpper(std::string& str);

// anther class for testing
class Complex
{
	private:
		double _real;
		double _imaginary;
	public:
		Complex();
		Complex(double real, double imaginary);
		Complex(const Complex& other);
		~Complex();
		Complex& operator=(const Complex& other);
		// operator + overloading
		Complex operator+(const Complex& other) const;
		// operator - overloading
		Complex operator-(const Complex& other) const;
		// operator * overloading
		Complex operator*(const Complex& other) const;
		// operator / overloading
		Complex operator/(const Complex& other) const;
		double real() const;
		double imaginary() const;
		void real(double real);
		void imaginary(double imaginary);
};
// operator << overloading
std::ostream& operator<<(std::ostream& os, const Complex& complex);

// function taking a Complex object and squaring its real and imaginary parts
void sqrComplex(Complex& complex);
// function taking a Complex object and computing the conjugate
void conjugate(Complex& complex);

#include "Array.tpp" // Include template implementation file

#endif // __ARRAY_HPP__
