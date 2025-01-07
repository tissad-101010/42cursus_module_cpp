/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tissad <tissad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:03:26 by tissad            #+#    #+#             */
/*   Updated: 2025/01/07 15:09:16 by tissad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SERIALIZATION_HPP__
#define __SERIALIZATION_HPP__

#include <iostream>
#include <string>

//Implement a class Serializer, who will not be initializable by the user by any way,
//with the following static methods:
class Serializer
{
    private:
        Serializer();
        Serializer(Serializer const &other);
        Serializer &operator=(Serializer const &other);
        ~Serializer();
    
    public:
        //It takes a pointer and converts it to the unsigned integer type uintptr_t.
        uintptr_t serialize(Data* ptr);
        //It takes an unsigned integer parameter and converts it to a pointer to Data.
        Data* deserialize(uintptr_t raw);

}
#endif