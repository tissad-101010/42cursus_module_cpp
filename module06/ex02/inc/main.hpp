/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tissad <tissad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:58:09 by tissad            #+#    #+#             */
/*   Updated: 2025/01/09 19:00:16 by tissad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MAIN_HPP__
#define __MAIN_HPP__

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <exception>

#define MAX_INSTANCE 10

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif