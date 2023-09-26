/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 18:35:20 by zwong             #+#    #+#             */
/*   Updated: 2023/09/26 15:28:06 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

// What does it mean to serialize something?
// -    Data serialization is the process of converting an object into a stream of bytes to more easily save or transmit it.
// -    Serialization is the process of converting a data structure to a format that
//      can be stored in a storage place or sent over a computer network and then reconfigured
//      in another computer environment.
// Serialization saves an item as a byte string in storage.
// Learning about reinterpret_cast (more than static_cast, converts pointer to different types)
// It works in it's own magical ways
int main() {
    std::cout << MAGENTA << "----- Creating Data struct -----" << std::endl << RESET;
    Data data = Data();

    data.content = (char *)"helloworld";
    data.num = 42;
	std::cout << YELLOW << "Address of original data: " << &data << std::endl << RESET;
	std::cout << GREY << "var content of data: " << (char *)data.content << std::endl << RESET;
	std::cout << GREY << "var num of data: " << data.num << std::endl << RESET;


    std::cout << MAGENTA << "----- Serialize then deserialize data -----" << std::endl << RESET;
    Serializer serializer = Serializer();
	
	uintptr_t ptr = serializer.serialize(&data);
	std::cout << GREEN << "serialized data..." << std::endl << RESET;
	
    Data *result = serializer.deserialize(ptr);
	std::cout << YELLOW << "Address after deserialize: " << result << std::endl << RESET;
	std::cout << GREY << "var content of data: " << (char *)result->content << std::endl << RESET;
	std::cout << GREY << "var num of data: " << result->num << std::endl << RESET;
    return (0);
}
