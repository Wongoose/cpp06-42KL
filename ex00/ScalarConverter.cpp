/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 14:37:02 by zwong             #+#    #+#             */
/*   Updated: 2023/07/21 18:31:55 by zwong            ###   ########.fr       */
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
void ScalarConverter::convert(const std::string &input) {
    this->_input = input;
    _main_set_type();
    switch (_type) {
        case INVALID:
            std::cout << RED << "Input is invalid, please try again!" << std::endl << RESET;
            break ;
        case CHAR:
            _convert_from_char();
            break ;
        case INT:
            _convert_from_int();
            break ;
        case FLOAT:
            _convert_from_float();
            break ;
        case DOUBLE:
            _convert_from_double();
            break ;
        case MY_NAN:
            _convert_from_nan();
            break ;
        case INF:
            _convert_from_inf();
            break ;
        default:
            std::cout << RED << "Error 505: Something wrong happened!" << std::endl << RESET;
    }
    return;
}

// PRIVATE functions to set types
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

// PRIVATE helper functions
void _print_char(int c, int f) {
    if (c - f >= CHAR_MAX || c <= CHAR_MIN)
        std::cout << GREY << "char: impossible" << std::endl << RESET;
    else if (std::isprint(c))
        std::cout << GREEN << "char: '" << static_cast<char>(c) << "'" << std::endl << RESET;
    else
        std::cout << GREY << "char: Non displayable" << std::endl << RESET;
}

// PRIVATE conversion functions
void ScalarConverter::_convert_from_char() {
    std::cout << MAGENTA << "----- Converting from char -----" << std::endl << RESET;
    // Before convert, use corresponding types first
    char c = _input[0];
    _print_char(c, 0);
    std::cout << GREEN << "int: " << static_cast<int>(c) << std::endl << RESET;
    std::cout << GREEN << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl << RESET;
    std::cout << GREEN << "double: " << static_cast<double>(c) << std::endl << RESET;
}

void ScalarConverter::_convert_from_int() {
    std::cout << MAGENTA << "----- Converting from int -----" << std::endl << RESET;
    long temp = std::strtol(_input.c_str(), NULL, 10);
    if (temp > INT_MAX || temp < INT_MIN) {
        std::cout << RED << "Failed with error: integer input is out of bounds!" << std::endl << RESET;
        return ;
    }
    // NOTE: If any bugs occurs, could be due to using "long" instead of "int"
    int num = (int)temp;
    // char
    _print_char(static_cast<int>(num), 0);
    // int
    std::cout << GREEN << "int: " << num << std::endl << RESET;
    // float
    std::cout << GREEN << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(num) << "f" << std::endl << RESET;
    // double
    std::cout << GREEN << "double: " << static_cast<double>(num) << std::endl << RESET;
}

// NEXT: Fix decimal point precision
void ScalarConverter::_convert_from_float() {
    std::cout << MAGENTA << "----- Converting from float -----" << std::endl << RESET;
    float num = std::strtof(_input.c_str(), NULL);
    // char
    _print_char((int)num, 1); // float comparison "float < CHAR_MAX + 1" cuz float decimal will round down
    // int
    if (num < INT_MIN || num > INT_MAX) // cannot overflow int max/min because float conversion caps
        std::cout << GREY << "int: impossible" << std::endl << RESET;
    else
        std::cout << GREEN << "int: " << static_cast<int>(num) << std::endl << RESET;
    // float
    double temp_int;
    std::cout << GREEN << "float: " << num;
    // modf() return fractional signed value, while storing integral portion in "temp_int"
    // 999999.5 is the point where number changes to 1e+06
    if (modf(num, &temp_int) == 0 && num < 999999.5) { 
        std::cout << ".0f" << std::endl;
    } else {
        std::cout << "f" << std::endl;
    }
    // double
    std::cout << "double: " << static_cast<double>(num);
    if (modf(num, &temp_int) == 0 && num < 999999.5) {
        std::cout << ".0";
    }
    std::cout << std::endl << RESET;
}

// NOTE that all 32-bit int values from 2147483584 to 2147483647 will be rounded up
// to a float value of 2147483648. The largest int value that will round down is 2147483583,
// which the same as (INT_MAX - 64) on a 32-bit system.

void ScalarConverter::_convert_from_double() {
    std::cout << MAGENTA << "----- Converting from double -----" << std::endl << RESET;
    double num = std::strtod(_input.c_str(), NULL);
    // char
    _print_char((int)num, 1); // double comparison might need "float < CHAR_MAX + 1"
    // int
    if (num < INT_MIN || num > INT_MAX) // cannot overflow int max/min because double conversion caps
        std::cout << GREY << "int: impossible" << std::endl << RESET;
    else
        std::cout << GREEN << "int: " << static_cast<int>(num) << std::endl << RESET;
    // float
    double temp_int;
    std::cout << GREEN << "float: " << static_cast<float>(num);
    // modf() return fractional signed value, while storing integral portion in "temp_int"
    // 999999.5 is the point where number changes to 1e+06
    if (modf(num, &temp_int) == 0 && num < 999999.5) { 
        std::cout << ".0f" << std::endl;
    } else {
        std::cout << "f" << std::endl;
    }
    // double
    std::cout << "double: " << num;
    if (modf(num, &temp_int) == 0 && num < 999999.5) {
        std::cout << ".0";
    }
    std::cout << std::endl << RESET;
}

void ScalarConverter::_convert_from_nan() {
    std::cout << MAGENTA << "----- Converting from nan/nanf -----" << std::endl << RESET;
    // from double nan
    if (_input == "nan") {
        double d = std::numeric_limits<double>::quiet_NaN(); // use corressponding type first (required by project)
        std::cout << GREY << "char: impossible" << std::endl << RESET;
        std::cout << GREY << "int: impossible" << std::endl << RESET;
        std::cout << GREY << "float: " << static_cast<float>(d) << "f" << std::endl << RESET;
        std::cout << GREY << "double: " << d << std::endl << RESET;
    }
    // from float nanf
    else if (_input == "nanf") {
        float f = std::numeric_limits<float>::quiet_NaN(); // use corressponding type first (required by project)
        std::cout << GREY << "char: impossible" << std::endl << RESET;
        std::cout << GREY << "int: impossible" << std::endl << RESET;
        std::cout << GREY << "float: " << f << "f" << std::endl << RESET;
        std::cout << GREY << "double: " << static_cast<double>(f) << std::endl << RESET;
    }
}

void ScalarConverter::_convert_from_inf() {
    std::cout << MAGENTA << "----- Converting from inf/inff -----" << std::endl << RESET;
    int sign = _input[0] == '-' ? -1 : 1;
    // from double inf
    if (_input.compare(1, 4, "inf")) {
        double d = std::numeric_limits<double>::infinity(); // use corressponding type first (required by project)
        std::cout << GREY << "char: impossible" << std::endl << RESET;
        std::cout << GREY << "int: impossible" << std::endl << RESET;
        d *= sign;
        std::cout << GREY << "float: " << static_cast<float>(d) << "f" << std::endl << RESET;
        std::cout << GREY << "double: " << d << std::endl << RESET;
    }
    // from float inf
    else if (_input.compare(1, 4, "inff")) {
        float f = std::numeric_limits<float>::infinity(); // use corressponding type first (required by project)
        std::cout << GREY << "char: impossible" << std::endl << RESET;
        std::cout << GREY << "int: impossible" << std::endl << RESET;
        f *= sign;
        std::cout << GREY << "float: " << f << "f" << std::endl << RESET;
        std::cout << GREY << "double: " << static_cast<double>(f) << std::endl << RESET;
    }
}
