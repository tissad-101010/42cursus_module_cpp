/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tissad <tissad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:43:24 by tissad            #+#    #+#             */
/*   Updated: 2025/01/13 17:18:35 by tissad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include "Complex.hpp"
#include <algorithm>
#include <ctime>

// Main function
#define MAX_VAL 5

// function compares two complex numbers
bool compareComplex(const Complex& a, const Complex& b)
{
	return (a < b);
}

int main()
{
	std::cout << "********tests for MutantStack with integers********" << std::endl;
	MutantStack<int> mstack;
	srand(time(NULL));
	// initialize mstack with random integers from 0 to MAX_VAL
	for (size_t i = 0; i < MAX_VAL; i++)
		mstack.push(rand() % 10);

	std::cout << "Size of mstack: " << mstack.size() << std::endl;
	std::cout << "Top of mstack: " << mstack.top() << std::endl;
	mstack.pop();
	
	std::cout << "Size of mstack after pop: " << mstack.size() << std::endl;
	std::cout << "Top of mstack after pop: " << mstack.top() << std::endl;
	
	std::cout << "Iterating through mstack: ";
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	std::cout << "test for reverse iterator: ";
	for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	std::cout << "test for const iterator: ";
	for (MutantStack<int>::const_iterator it = mstack.begin(); it != mstack.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	std::cout << "test for const reverse iterator: ";
	for (MutantStack<int>::const_reverse_iterator it = mstack.rbegin(); it != mstack.rend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	std::cout << "test with std::sort from algorithm: ";
	std::sort(mstack.begin(), mstack.end());
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	std::cout << "test with std::find from algorithm and reverse iterator: ";
	MutantStack<int>::reverse_iterator toFind = std::find(mstack.rbegin(), mstack.rend(), 2);
	(toFind != mstack.rend()) ? std::cout << "Found : " << *toFind : std::cout << "Not found ";
	std::cout << std::endl;
	std::cout << std::endl;
	
	// tests for MutantStack with strings
	std::cout << "********tests for MutantStack with strings********" << std::endl;
	MutantStack<std::string> mstack_str;
	mstack_str.push("Hello");
	mstack_str.push("World");
	mstack_str.push("!");
	
	std::cout << "Size of mstack_str: " << mstack_str.size() << std::endl;
	std::cout << "Top of mstack_str: " << mstack_str.top() << std::endl;
	mstack_str.pop();
	std::cout << "Size of mstack_str after pop: " << mstack_str.size() << std::endl;
	std::cout << "Top of mstack_str after pop: " << mstack_str.top() << std::endl;
	std::cout << "Iterating through mstack_str: ";
	
	for (MutantStack<std::string>::iterator it = mstack_str.begin(); it != mstack_str.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	std::cout << "test for reverse iterator: ";
	for (MutantStack<std::string>::reverse_iterator it = mstack_str.rbegin(); it != mstack_str.rend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	std::cout << "test for const iterator: ";
	for (MutantStack<std::string>::const_iterator it = mstack_str.begin(); it != mstack_str.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	std::cout << "test for const reverse iterator: ";
	for (MutantStack<std::string>::const_reverse_iterator it = mstack_str.rbegin(); it != mstack_str.rend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << std::endl;
	
	// tests for MutantStack with complex numbers
	std::cout << "********tests for MutantStack with complex numbers********" << std::endl;
	MutantStack<Complex> mstack_complex;
	for (size_t i = 0; i < MAX_VAL; i++)
		mstack_complex.push(Complex(rand() % 10, rand() % 10));
		
	std::cout << "Size of mstack_complex: " << mstack_complex.size() << std::endl;
	std::cout << "Top of mstack_complex: " << mstack_complex.top() << std::endl;
	mstack_complex.pop();
	std::cout << "Size of mstack_complex after pop: " << mstack_complex.size() << std::endl;
	std::cout << "Top of mstack_complex after pop: " << mstack_complex.top() << std::endl;
	std::cout << "Iterating through mstack_complex: ";
	
	for (MutantStack<Complex>::iterator it = mstack_complex.begin(); it != mstack_complex.end(); it++)
		std::cout << *it << ", ";
	std::cout << std::endl;
	
	std::cout << "test for reverse iterator: ";
	for (MutantStack<Complex>::reverse_iterator it = mstack_complex.rbegin(); it != mstack_complex.rend(); it++)
		std::cout << *it << ", ";
	std::cout << std::endl;
	
	std::cout << "test for const iterator: ";
	for (MutantStack<Complex>::const_iterator it = mstack_complex.begin(); it != mstack_complex.end(); it++)
		std::cout << *it << ", ";
	std::cout << std::endl;
	
	std::cout << "test for const reverse iterator: ";
	for (MutantStack<Complex>::const_reverse_iterator it = mstack_complex.rbegin(); it != mstack_complex.rend(); it++)
		std::cout << *it << ", ";
	std::cout << std::endl;
	
	std::cout << "test with std::sort from algorithm: ";
	std::sort(mstack_complex.begin(), mstack_complex.end(), compareComplex);
	for (MutantStack<Complex>::iterator it = mstack_complex.begin(); it != mstack_complex.end(); it++)
		std::cout << *it << ", ";
	std::cout << std::endl;	
	
	return (0);
}