/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 10:04:28 by zwong             #+#    #+#             */
/*   Updated: 2023/07/25 10:04:31 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {
    std::cout << "Serializer: Default constructor called" << std::endl;
}

Serializer::Serializer(std::string str) {
    (void)str;
    std::cout << "Serializer: Str constructor called" << std::endl;
}

Serializer::Serializer(const Serializer &copy) {
    (void)copy;
    std::cout << "Serializer: Copy constructor called" << std::endl;
}

Serializer::~Serializer() { std::cout << "Serializer: Default destructor called" << std::endl; }

Serializer &Serializer::operator=(const Serializer &other) {
    (void)other;
    std::cout << "Serializer: copy assignment operator called" << std::endl;
    return (*this);
}

uintptr_t Serializer::serialize(Data *ptr) {
    uintptr_t res = (uintptr_t)(Data *)ptr;
    return (res);
}

Data *Serializer::deserialize(uintptr_t raw) {
    Data *res;
    res = (Data *)(uintptr_t)raw;
    return (res);
}
