/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moreTest.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tissad <tissad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 22:38:54 by tissad            #+#    #+#             */
/*   Updated: 2025/01/03 18:37:19 by tissad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"


int main()
{
	Array<int> *intArray = NULL;
	try {
		// Test default constructor
		Array<int> emptyArray;
		std::cout	<< "Empty array size: "
					<< emptyArray.size()
					<< std::endl;

		// Test constructor with size
		intArray = new Array<int>(5);
		std::cout	<< "Integer array size: "
					<< intArray->size() 
					<< std::endl;

		// Test default initialization
		std::cout	<< "Initial values in intArray: "
					<< *intArray
					<< std::endl;

		// Modify elements using subscript operator
		for (std::size_t i = 0; i < intArray->size(); ++i) {
			(*intArray)[i] = static_cast<int>(i * 10);
		}

		std::cout << "Modified values in intArray using subscript operator: "
				  << *intArray
				  << std::endl;

		// Test copy constructor
		Array<int> copyArray = *intArray;
		std::cout << "Copied array values: "
				  << copyArray
				  << std::endl;
		
		// Modify original array and ensure copy is unaffected
		intArray->iter(sqrInt);
		std::cout	<< "Modified original array: "
					<< *intArray
					<< std::endl;
					
		std::cout	<< "Copy array after original modification: "
					<< copyArray
					<< std::endl;



		// Test string array
		Array<std::string> stringArray(3);
		stringArray[0] = "Hello";
		stringArray[1] = "World";
		stringArray[2] = "!";
		std::cout	<< "String array: "
					<< stringArray 
					<< std::endl;
		stringArray.iter(toUpper);
		std::cout	<< "String array after toUpper: "
					<< stringArray
					<< std::endl;

		// Test Complex array
		Array<Complex> complexArray(4);
		complexArray[0] = Complex(1.0, 2.0);
		complexArray[1] = Complex(3.0, 4.0);
		complexArray[2] = Complex(5.0, 6.0);
		complexArray[3] = Complex(7.0, 8.0);
		
		Array<Complex> sqrComplexArray = complexArray;
		std::cout	<< "Copied complex array: "
					<< sqrComplexArray
					<< std::endl;

		// Test Complex array modification
		sqrComplexArray.iter(sqrComplex);
		std::cout	<< "Complex array after squaring: "
					<< sqrComplexArray
					<< std::endl;
		
		// Test Complex array modification
		complexArray.iter(conjugate);
		std::cout	<< "Complex array after conjugate: "
					<< complexArray
					<< std::endl;
				
		std::cout	<< "Complex array after squaring: "
					<< sqrComplexArray
					<< std::endl;

		// test operator + overloading with complex Array
		Complex c1 = Complex(0.0, 0.0);
		for (std::size_t i = 0; i < complexArray.size(); ++i)
		{
			c1 = c1 + complexArray[i];
		}	
		std::cout	<< "Sum of complex array: "
					<< c1
					<< std::endl;
		
		// Test out-of-bounds access
		std::cout	<< "Accessing out-of-bounds index...\n"
					<< (*intArray)[10]
					<< std::endl; // This should throw an exception
		if (intArray) 
		{
			delete intArray;
			intArray = NULL;
		}
					
	}
	catch (const std::exception& e)
	{
		if (intArray) 
		{
			delete intArray;
			intArray = NULL;
		}
		std::cerr << "Exception: " << e.what() << "\n";
	}
	return 0;
}
/*
#include <iostream>
#include <Array.hpp>

#define MAX_VAL 750
int main(int, char**)
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;//
	return 0;
}
*/