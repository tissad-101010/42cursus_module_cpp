/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tissad <tissad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:46:29 by tissad            #+#    #+#             */
/*   Updated: 2025/01/03 21:59:46 by tissad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __EASYFIND_TPP__
#define __EASYFIND_TPP__

#include "easyfind.hpp"

// Implémentation de easyfind
template <typename T>
typename T::const_iterator easyfind(const T& container, int value)
{
    typename T::const_iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
    {
        throw NotFoundException();
    }
    return it;
}

#endif // __EASYFIND_TPP__
