/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 14:37:02 by zwong             #+#    #+#             */
/*   Updated: 2023/09/26 11:30:23 by zwong            ###   ########.fr       */
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

// PUBLIC functions
// Steps
// 1. Get input
// 2. Define what type is the input
// 3. Validate
// 4. Convert to the other 3 types and print
void ScalarConverter::convert(const std::string &input) {
    this->_input = input;
    _main_define_type();
    switch (_type) {
        case INVALID:
            std::cout << RED << "Input is invalid, please try again!" << std::endl << RESET;
            break ;
        case CHAR:
            convert_from_char(this->_input);
            break ;
        case INT:
            convert_from_int(this->_input);
            break ;
        case FLOAT:
            convert_from_float(this->_input);
            break ;
        case DOUBLE:
            convert_from_double(this->_input);
            break ;
        case MY_NAN:
            convert_from_nan(this->_input);
            break ;
        case INF:
            convert_from_inf(this->_input);
            break ;
        default:
            std::cout << RED << "Error 505: Something wrong happened!" << std::endl << RESET;
    }
    return;
}

// PRIVATE functions to set types
void ScalarConverter::_main_define_type() {
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
    int len = _input.length();
    bool hasDecimal = false;

    if (_input[0] == '+' || _input[0] == '-')
        i++;
    while (i < len) {
        if (_input[i] == '.') {
            if (hasDecimal == false)
                hasDecimal = true;
            else
                return ;
        }
        else if (_input[i] == 'f' && (i + 1 == len) && std::isdigit(_input[i - 1])) {
            _type = FLOAT;
            return ;
        }
        else if (!std::isdigit(_input[i]))
            return ;
        i++;
    }
    if (hasDecimal) _type = DOUBLE;
    else _type = INT;
    return ;
}
