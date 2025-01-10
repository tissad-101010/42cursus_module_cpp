/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tissad <tissad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 22:43:13 by tissad            #+#    #+#             */
/*   Updated: 2025/01/10 14:48:55 by tissad           ###   ########.fr       */
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
		if (this->_data != NULL)
		{
			delete[] this->_data;
		}
		this->_size = other._size;
		this->_data = (this->_size > 0) ? new T[this->_size] : NULL;
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
#endif // __ARRAY_TPP__