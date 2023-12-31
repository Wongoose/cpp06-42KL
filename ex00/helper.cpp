/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 22:12:20 by zwong             #+#    #+#             */
/*   Updated: 2023/09/26 14:57:23 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// PRIVATE helper functions
// printing char requires extra validation
// 1. 
void _print_char(int c) {
    if (c >= CHAR_MAX || c <= CHAR_MIN)
        std::cout << GREY << "char: impossible" << std::endl << RESET;
    else if (std::isprint(c))
        std::cout << GREEN << "char: '" << static_cast<char>(c) << "'" << std::endl << RESET;
    else
        std::cout << GREY << "char: Non displayable" << std::endl << RESET;
}

// PRIVATE conversion functions
void convert_from_char(const std::string &input) {
    std::cout << MAGENTA << "----- Converting from char -----" << std::endl << RESET;
    // Before convert, use corresponding types first
    char c = input[0];
    _print_char(c);
    std::cout << GREEN << "int: " << static_cast<int>(c) << std::endl << RESET;
    std::cout << GREEN << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl << RESET;
    std::cout << GREEN << "double: " << static_cast<double>(c) << std::endl << RESET;
}

void convert_from_int(const std::string &input) {
    std::cout << MAGENTA << "----- Converting from int -----" << std::endl << RESET;
    long temp = std::strtol(input.c_str(), NULL, 10);
    if (temp > INT_MAX || temp < INT_MIN) {
        std::cout << RED << "Failed with error: integer input is out of bounds!" << std::endl << RESET;
        return ;
    }
    // NOTE: If any bugs occurs, could be due to using "long" instead of "int"
    int num = (int)temp;
    // char
    _print_char(static_cast<int>(num));
    // int
    std::cout << GREEN << "int: " << num << std::endl << RESET;
    // float
    std::cout << GREEN << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(num) << "f" << std::endl << RESET;
    // double
    std::cout << GREEN << "double: " << static_cast<double>(num) << std::endl << RESET;
}

// NEXT: Fix decimal point precision
void convert_from_float(const std::string &input) {
    std::cout << MAGENTA << "----- Converting from float -----" << std::endl << RESET;
    float num = std::strtof(input.c_str(), NULL);
    // char
    _print_char(static_cast<char>(num));
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

void convert_from_double(const std::string &input) {
    std::cout << MAGENTA << "----- Converting from double -----" << std::endl << RESET;
    double num = std::strtod(input.c_str(), NULL);
    // char
    _print_char(static_cast<char>(num));
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

void convert_from_nan(const std::string &input) {
    std::cout << MAGENTA << "----- Converting from nan/nanf -----" << std::endl << RESET;
    // from double nan
    if (input == "nan") {
        double d = std::numeric_limits<double>::quiet_NaN(); // use corressponding type first (required by project)
        std::cout << GREY << "char: impossible" << std::endl << RESET;
        std::cout << GREY << "int: impossible" << std::endl << RESET;
        std::cout << GREY << "float: " << static_cast<float>(d) << "f" << std::endl << RESET;
        std::cout << GREY << "double: " << d << std::endl << RESET;
    }
    // from float nanf
    else if (input == "nanf") {
        float f = std::numeric_limits<float>::quiet_NaN(); // use corressponding type first (required by project)
        std::cout << GREY << "char: impossible" << std::endl << RESET;
        std::cout << GREY << "int: impossible" << std::endl << RESET;
        std::cout << GREY << "float: " << f << "f" << std::endl << RESET;
        std::cout << GREY << "double: " << static_cast<double>(f) << std::endl << RESET;
    }
}

void convert_from_inf(const std::string &input) {
    std::cout << MAGENTA << "----- Converting from inf/inff -----" << std::endl << RESET;
    int sign = input[0] == '-' ? -1 : 1;
    // from double inf
    if (input.compare(1, 4, "inf")) {
        double d = std::numeric_limits<double>::infinity(); // use corressponding type first (required by project)
        std::cout << GREY << "char: impossible" << std::endl << RESET;
        std::cout << GREY << "int: impossible" << std::endl << RESET;
        d *= sign;
        std::cout << GREY << "float: " << static_cast<float>(d) << "f" << std::endl << RESET;
        std::cout << GREY << "double: " << d << std::endl << RESET;
    }
    // from float inf
    else if (input.compare(1, 4, "inff")) {
        float f = std::numeric_limits<float>::infinity(); // use corressponding type first (required by project)
        std::cout << GREY << "char: impossible" << std::endl << RESET;
        std::cout << GREY << "int: impossible" << std::endl << RESET;
        f *= sign;
        std::cout << GREY << "float: " << f << "f" << std::endl << RESET;
        std::cout << GREY << "double: " << static_cast<double>(f) << std::endl << RESET;
    }
}