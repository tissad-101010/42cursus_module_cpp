/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tissad <tissad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:03:31 by tissad            #+#    #+#             */
/*   Updated: 2025/01/10 12:48:37 by tissad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::Serializer(Serializer const &other)
{
	(void)other;
}

Serializer &Serializer::operator=(Serializer const &other)
{
	(void)other;
	return (*this);
}

Serializer::~Serializer()
{
}



uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<void *>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
