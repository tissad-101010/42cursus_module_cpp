/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tissad <tissad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 21:23:21 by tissad            #+#    #+#             */
/*   Updated: 2025/01/07 23:07:04 by tissad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef __DATA_HPP__
#define __DATA_HPP__

#include <string>

//create a non-empty (it means it has data members) Data structure.
struct Data
{
	int 		_id;
	std::string	_name;
	
	Data(int id, std::string name);
	~Data();
};

#endif