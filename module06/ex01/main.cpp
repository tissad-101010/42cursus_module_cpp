/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tissad <tissad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:50:43 by tissad            #+#    #+#             */
/*   Updated: 2025/01/09 16:43:55 by tissad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Serializer.hpp>
#include <iostream>

// Test the Serializer class
int main() {
    // Create a Data object
    Data originalData(1, "Test Data");
	Data originalData2(2, "Test Data2");

    // Serialize the Data object
    void* serializedData = Serializer::serialize(&originalData);
	void* serializedData2 = Serializer::serialize(&originalData2);

    // Deserialize back to a Data pointer
    Data* deserializedData = Serializer::deserialize(serializedData);
	Data* deserializedData2 = Serializer::deserialize(serializedData2);

    // Check if deserialization gives the same pointer
    if (deserializedData == &originalData)
    {
    	std::cout	<< "Deserialization successful!"
                	<< std::endl;
        std::cout	<< "Original Data: id = "
					<< originalData._id 
					<< ", name = "
					<< originalData._name
					<< std::endl;
        std::cout	<< "Deserialized Data: id = "
					<< deserializedData->_id 
					<< ", name = " 
					<< deserializedData->_name
					<< std::endl;
    }
    else
    {
        std::cout << "Deserialization failed!" << std::endl;
	}
	if (deserializedData2 == &originalData2)
	{
		std::cout	<< "Deserialization successful!"
					<< std::endl;
		std::cout	<< "Original Data: id = "
					<< originalData2._id 
					<< ", name = "
					<< originalData2._name
					<< std::endl;
		std::cout	<< "Deserialized Data: id = "
					<< deserializedData2->_id 
					<< ", name = " 
					<< deserializedData2->_name
					<< std::endl;
	}
	else
	{
		std::cout << "Deserialization failed!" << std::endl;
	}
    return 0;
}