/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 18:35:20 by zwong             #+#    #+#             */
/*   Updated: 2023/09/26 15:42:37 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

// Learning about dynamic_cast<T>, where it will return 0 if the type is not the same
// So in a way it does this:
//  - Tries to cast to a type (trial and error)
//  - Used on a base pointer (*) -> to identify the derived class (got it?)

// Note: Derived class can be represented as a "base pointer (*)"
// However, it is different when dynamic_cast a pointer vs reference (pointer is best practice)
int main() {
    std::cout << MAGENTA << "----- Testing random generator of Base class -----" << std::endl << RESET;
    Base *base_array[10];
	for (int i = 0; i < 10; i++) {
        // Generate is random so I wouldn't know what derived type I got (represented/hidden as Base *)
		base_array[i] = generate();
		std::cout << "[" << i << "] class is (pointer): ";
		identify(base_array[i]);
		std::cout << "[" << i << "] class is (reference): ";
		identify(*base_array[i]);
		std::cout << std::endl;
        delete base_array[i];
	}
    std::cout << MAGENTA << "----- Testing identifying Derived classes -----" << std::endl << RESET;
    Base *a_class = new A();
    Base *b_class = new B();
    Base *c_class = new C();
    std::cout << "Supposed to be 'A', with result: ";
    identify(a_class);
    std::cout << "Supposed to be 'B', with result: ";
    identify(b_class);
    std::cout << "Supposed to be 'C', with result: ";
    identify(c_class);
    return (0);
}
