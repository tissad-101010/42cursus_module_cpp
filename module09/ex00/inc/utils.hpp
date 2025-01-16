/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tissad <tissad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:37:54 by tissad            #+#    #+#             */
/*   Updated: 2025/01/16 14:43:28 by tissad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __UTILS_HPP__
# define __UTILS_HPP__

#include <iostream>


enum validDouble
{
	VALID,
	NEGATIVE,
    LARGE,
	OTHER
};

//function to check if a string is a valid format date (YYYY-MM-DD)
bool isValidDate(const std::string& date);
//function to check if a string is a valid double
int isValidDouble(const std::string& str);

#endif