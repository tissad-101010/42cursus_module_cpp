/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tissad <tissad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 21:10:30 by tissad            #+#    #+#             */
/*   Updated: 2025/01/16 21:16:54 by tissad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PMERGEME_HPP__
#define __PMERGEME_HPP__

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>

class PmergeMe
{
    private:
        
        PmergeMe();
        PmergeMe(const PmergeMe &rhs);
        PmergeMe &operator=(const PmergeMe &rhs);
        ~PmergeMe();

        static void _pmergeMeList();
        static void _pmergeMeVector();
        
    public:
        static void pmergeMe();
};

#endif