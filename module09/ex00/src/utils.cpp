/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tissad <tissad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:30:01 by tissad            #+#    #+#             */
/*   Updated: 2025/01/16 14:45:30 by tissad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include <cstdlib>
#include <limits>



bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool isValidDate(const std::string& date) {
    if (date.length() != 10) {
        return false;
    }

    // Check format YYYY-MM-DD
    for (int i = 0; i < 10; ++i) {
        if ((i == 4 || i == 7) && date[i] != '-') {
            return false;
        } else if ((i != 4 && i != 7) && !isdigit(date[i])) {
            return false;
        }
    }

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12) {
        return false;
    }

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (isLeapYear(year)) {
        daysInMonth[1] = 29;  // February in a leap year
    }

    if (day < 1 || day > daysInMonth[month - 1]) {
        return false;
    }
    return true;
}


// function to check if a string is a valid double use strtod
int isValidDouble(const std::string& str)
{
	char *endptr;
	if (std::strtod(str.c_str(), &endptr) < 0)
		return (NEGATIVE);
	if (std::strtod(str.c_str(), &endptr) > static_cast<double>(std::numeric_limits<int>::max()))
		return (LARGE);
	if (*endptr != '\0')
		return (OTHER);
	return (VALID);
}