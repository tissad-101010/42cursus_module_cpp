/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Complex.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tissad <tissad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:41:57 by tissad            #+#    #+#             */
/*   Updated: 2025/01/10 14:46:01 by tissad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __COMPLEX_HPP__
#define __COMPLEX_HPP__

#include <iostream>
#include <cmath> 

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

#endif