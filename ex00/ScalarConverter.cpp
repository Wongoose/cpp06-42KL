/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 14:37:02 by zwong             #+#    #+#             */
/*   Updated: 2023/07/20 14:47:33 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
    std::cout << "ScalarConverter: Default constructor called" << std::endl;
    _type = NONE;
}

ScalarConverter::ScalarConverter(std::string str) {
    std::cout << "ScalarConverter: Str constructor called" << std::endl;
    (void)str;
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy) {
    std::cout << "ScalarConverter: Copy constructor called" << std::endl;
    _input = copy.get_input();
    _type = copy.get_type();
}

ScalarConverter::~ScalarConverter() { std::cout << "ScalarConverter: Default destructor called" << std::endl; }

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
    std::cout << "ScalarConverter: copy assignment operator called" << std::endl;
    _input = other.get_input();
    _type = other.get_type();
    return (*this);
}

// Getters
std::string ScalarConverter::get_input() const {
    return (_input);
}

t_type ScalarConverter::get_type() const {
    return (_type);
}

// Setter

// Functions NEXT: Do convert functions
void ScalarConverter::convert(const std::string &input) {
    return;
}

// PRIVATE functions
void ScalarConverter::_main_set_type() {
    _type = INVALID;
    // Check for char
    if (_input.length() == 1 && !std::isdigit(_input[0])) {
        _type = CHAR;
        return ;
    }
    // Check first for "nan" or "nanf"
    else if (_input == "nan" || _input == "nanf") {
        _type = MY_NAN;
        return ;
    }
    // Check for all the "inf"
    else if (_input == "+inf" || _input == "-inf" || _input == "+inff" || _input == "-inff") {
        _type = INF;
        return ;
    }
    // Else, just assume it is int, float, or double type
    else
        _set_type_int_float_double();
}

void ScalarConverter::_set_type_int_float_double() {
    int i = 0;
}
