/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:48:27 by vasargsy          #+#    #+#             */
/*   Updated: 2023/07/23 20:42:03 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {
    
    Data data;
    data.value = 60;

    uintptr_t sPtr = Serializer::serialize(&data);

    Data* dPtr = Serializer::deserialize(sPtr);

    if (dPtr == &data)
	{
        std::cout << "Deserialization successful. Pointers match." << std::endl;
        std::cout << "Value: " << dPtr->value << std::endl;
    }
	else
        std::cout << "Deserialization failed. Pointers do not match." << std::endl;

    return 0;
}