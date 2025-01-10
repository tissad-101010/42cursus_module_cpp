/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Comlex.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tissad <tissad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:43:15 by tissad            #+#    #+#             */
/*   Updated: 2025/01/10 14:49:13 by tissad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Complex.hpp"

// Default constructor
Complex::Complex() : _real(0), _imaginary(0) {}
// Constructor with parameters
Complex::Complex(double real, double imaginary) : _real(real), _imaginary(imaginary) {}
// Copy constructor
Complex::Complex(const Complex& other) : _real(other._real), _imaginary(other._imaginary) {}
// Destructor
Complex::~Complex() {}
// Assignment operator
Complex& Complex::operator=(const Complex& other)
{
	if (this != &other)
	{
		this->_real = other._real;
		this->_imaginary = other._imaginary;
	}
	return *this;
}
// Member function to get the real part
double Complex::real() const
{
	return _real;
}
// Member function to get the imaginary part
double Complex::imaginary() const
{
	return _imaginary;
}
// Member function to set the real part
void Complex::real(double real)
{
	_real = real;
}
// Member function to set the imaginary part
void Complex::imaginary(double imaginary)
{
	_imaginary = imaginary;
}
// operator + overloading
Complex Complex::operator+(const Complex& other) const
{
	return Complex(_real + other._real, _imaginary + other._imaginary);
}

// operator - overloading
Complex Complex::operator-(const Complex& other) const
{
	return Complex(_real - other._real, _imaginary - other._imaginary);
}

// operator * overloading
Complex Complex::operator*(const Complex& other) const
{
	return Complex(_real * other._real - _imaginary * other._imaginary,
				_real * other._imaginary + _imaginary * other._real);
}

// operator / overloading
Complex Complex::operator/(const Complex& other) const
{
	double denominator = other._real * other._real + other._imaginary * other._imaginary;
	return Complex((_real * other._real + _imaginary * other._imaginary) / denominator,
				(_imaginary * other._real - _real * other._imaginary) / denominator);
}

// operator << overloading
std::ostream& operator<<(std::ostream& os, const Complex& complex)
{
	os << complex.real() << " + " << complex.imaginary() << "i";
	return os;
}

// function taking a Complex object and squaring its real and imaginary parts
void sqrComplex(Complex& complex)
{
	double real = complex.real();
	double imaginary = complex.imaginary();
	complex.real(real * real - imaginary * imaginary);
	complex.imaginary(2 * real * imaginary);
}
// function taking a Complex object and computing the conjugate
void conjugate(Complex& complex)
{
	complex.imaginary(-complex.imaginary());
}