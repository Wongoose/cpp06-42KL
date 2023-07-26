/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 18:35:20 by zwong             #+#    #+#             */
/*   Updated: 2023/07/26 18:41:28 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

// Learning about dynamic_cast<T>, where it will return 0 if the type is not the same
int main() {
    std::cout << MAGENTA << "----- Testing array of Base class -----" << std::endl << RESET;
    Base *base_array[10];
	for (int i = 0; i < 10; i++) {
		base_array[i] = generate();
		std::cout << "[" << i << "] class is (pointer): ";
		identify(base_array[i]);
		std::cout << "[" << i << "] class is (reference): ";
		identify(*base_array[i]);
		std::cout << std::endl;
        delete base_array[i];
	}
    return (0);
}
