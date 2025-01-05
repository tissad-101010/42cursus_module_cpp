/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tissad <tissad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:46:29 by tissad            #+#    #+#             */
/*   Updated: 2025/01/03 22:00:00 by tissad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __EASYFIND_HPP__
#define __EASYFIND_HPP__

#include <algorithm>
#include <exception>

// Classe NotFoundException that inherits from std::exception
class NotFoundException : public std::exception {
public:
    const char* what() const throw()
    {
        return "Element not found in the container";
    }
};

// Fonction easyfind that takes a container and a value as parameters
template <typename T>
typename T::const_iterator easyfind(const T& container, int value);

#include "easyfind.tpp" // Include the implementation file

#endif // __EASYFIND_HPP__
