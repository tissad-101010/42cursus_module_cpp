/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tissad <tissad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 22:43:13 by tissad            #+#    #+#             */
/*   Updated: 2025/01/03 19:12:12 by tissad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ARRAY_TPP__
#define __ARRAY_TPP__

#include <iostream> // Optional for debugging

// Default constructor
template <typename T>
Array<T>::Array() : _data(NULL), _size(0) {}

// Constructor with size parameter
template <typename T>
Array<T>::Array(unsigned int n) : _data(new T[n]()), _size(n) {}

// Copy constructor
template <typename T>
Array<T>::Array(const Array& other) : _data(NULL), _size(other._size)
{
    if (this->_size > 0)
    {
        this->_data = new T[this->_size];
        for (std::size_t i = 0; i < this->_size; ++i)
        {
            this->_data[i] = other._data[i];
        }
    }
}

// Destructor
template <typename T>
Array<T>::~Array()
{
    delete[] _data;
}

// Assignment operator
template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
    if (this != &other)
    {
        delete[] this->_data;
        this->_size = other._size;
        this->_data = (_size > 0) ? new T[this->_size] : NULL;
        for (std::size_t i = 0; i < this->_size; ++i)
        {
            this->_data[i] = other._data[i];
        }
    }
    return *this;
}

// Subscript operator for accessing elements (read and write)
template <typename T>
T& Array<T>::operator[](std::size_t index)
{
    if (index >= this->_size || this->_size == 0 || this->_data == NULL) {
        throw std::out_of_range("Index out of bounds");
    }
    return (this->_data[index]);
}

// Subscript operator for accessing elements (read-only)
template <typename T>
const T& Array<T>::operator[](std::size_t index) const
{
    if (index >= this->_size || this->_size == 0 || this->_data == NULL) {
        throw std::out_of_range("Index out of bounds");
    }
    return (this->_data[index]);
}

// Member function to get the size of the array
template <typename T>
std::size_t Array<T>::size() const
{
    return (this->_size);
}

// iter function template
template <typename T>
template <typename F>
void Array<T>::iter(F function)
{
    for (std::size_t i = 0; i < this->_size; ++i)
    {
        function(this->_data[i]);
    }
}

// out operator << to print Array elements
template <typename U>
std::ostream& operator<<(std::ostream& os, const Array<U>& array)
{
    os << "[";
    for (std::size_t i = 0; i < array.size(); ++i)
    {
        os << array[i];
        if (i < array.size() - 1)
        {
            os << ", ";
        }
    }
    os << "]";
    return os;
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tissad <tissad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 22:43:00 by tissad            #+#    #+#             */
/*   Updated: 2025/01/03 17:36:53 by tissad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath> // For sqrt, atan2


// A function squaring an integer
void sqrInt(int& x)
{
    x *= x;
}

// function that transforms an string to uppercase
void toUpper(std::string& str)
{
    for (std::size_t i = 0; i < str.length(); ++i)
    {
        str[i] = std::toupper(str[i]);
    }
}

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

#endif // __ARRAY_TPP__