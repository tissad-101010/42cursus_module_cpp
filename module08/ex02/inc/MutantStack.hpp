/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tissad <tissad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:25:23 by tissad            #+#    #+#             */
/*   Updated: 2025/01/13 16:13:43 by tissad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MUTANTSTACK_HPP__
#define __MUTANTSTACK_HPP__

#include <stack>
#include <deque>
#include <iterator>
#include <iostream>

// mutanstack class that inherits from std::stack
template <typename T>
class MutantStack : public std::stack<T> {
	public:
		// Typedefs for iterators and const iterators
		typedef typename std::deque<T>::iterator iterator;
		typedef typename std::deque<T>::const_iterator const_iterator;
		typedef typename std::deque<T>::reverse_iterator reverse_iterator;
		typedef typename std::deque<T>::const_reverse_iterator const_reverse_iterator;

		MutantStack();
		
		MutantStack(const MutantStack& other);
		
		MutantStack& operator=(const MutantStack& other);
		
		~MutantStack();

		iterator begin();

		iterator end();

		const_iterator begin() const;

		const_iterator end() const;

		reverse_iterator rbegin();

		reverse_iterator rend();

		const_reverse_iterator rbegin() const;

		const_reverse_iterator rend() const;
};

// operator << overloading
template <typename T>
std::ostream& operator<<(std::ostream& os, const MutantStack<T>& mutantStack);

#include "../srcs/MutantStack.tpp"

#endif // __MUTANTSTACK_HPP__