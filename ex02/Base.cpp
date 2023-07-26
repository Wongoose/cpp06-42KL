/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:35:43 by zwong             #+#    #+#             */
/*   Updated: 2023/07/26 18:40:55 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::Base() { std::cout << "Base: Default constructor called" << std::endl; }

Base::~Base() { std::cout << "Base: Default destructor called" << std::endl; }

Base *generate(void) {
    int type = std::rand() % 3;

    switch (type) {
        case 0:
            return (new A);
        case 1:
            return (new B);
        case 2:
            return (new C);
        default:
            return (new A);
    }
}

// Difference between pointer and reference dynamic_cast
// - https://www.cprogramming.com/reference/typecasting/dynamiccast.html#:~:text=Reference%20dynamic%20cast&text=subclass%20%3D%20dynamic_cast%3C,in%20a%20try%2Fcatch%20block.

void identify(Base *p) {
    if (dynamic_cast<A*>(p) != 0)
        std::cout << GREEN << "\"A\"" << std::endl << RESET;
    else if (dynamic_cast<B*>(p) != 0)
        std::cout << GREEN << "\"B\"" << std::endl << RESET;
    else if (dynamic_cast<C*>(p) != 0)
        std::cout << GREEN << "\"C\"" << std::endl << RESET;
    else
        std::cout << RED << "Failed to identify class!" << std::endl << RESET;
}

void identify(Base &p) {
    Base useless;

    try {
        useless = dynamic_cast<A&>(p);
        (void)useless;
        std::cout << GREEN << "\"A\"" << std::endl << RESET;
    } catch (std::exception &err) {
        std::cout << RED << "Failed to identify class!" << std::endl << RESET;
    }
    try {
        useless = dynamic_cast<B&>(p);
        (void)useless;
        std::cout << GREEN << "\"B\"" << std::endl << RESET;
    } catch (std::exception &err) {
        std::cout << RED << "Failed to identify class!" << std::endl << RESET;
    }
    try {
        useless = dynamic_cast<C&>(p);
        (void)useless;
        std::cout << GREEN << "\"C\"" << std::endl << RESET;
    } catch (std::exception &err) {
        std::cout << RED << "Failed to identify class!" << std::endl << RESET;
    }
}
