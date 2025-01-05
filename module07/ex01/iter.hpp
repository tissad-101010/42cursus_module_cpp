/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tissad <tissad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 22:24:05 by tissad            #+#    #+#             */
/*   Updated: 2025/01/03 18:39:39 by tissad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ITER_HPP__
#define __ITER_HPP__ 

#include <iostream>
#include <string>

// iter function template
template <typename T, typename F>
void iter(T* array, std::size_t length, F function) {
    for (std::size_t i = 0; i < length; ++i) {
        function(array[i]);
    }
}

// A function template to print elements of any type
template <typename T>
void print(const T& element) {
    std::cout << element << " ";
}

#endif // __ITER_HPP__
