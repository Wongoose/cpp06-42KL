/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 14:36:50 by zwong             #+#    #+#             */
/*   Updated: 2023/07/24 22:17:35 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <climits>
#include <limits>
#include <cmath>

#define RESET "\033[39m"
#define BLACK "\033[30m"
#define GREY "\033[90m"
#define RED "\033[31m"
#define CYAN "\033[36m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[94m"
#define MAGENTA "\033[35m"

// char e.g. c, a
// int e.g. 0, -42, 42
// float e.g. 0.0f, -4.2f, 4.2f, -inff, +inff
// double e.g. 0.0, -4.2, 4.2, -inf, +inf, nan

// Learning points
// - difference between float and double
// - what is inff, inf, nan

typedef enum e_type {
    NONE,
    INVALID,
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    MY_NAN,
    INF
}   t_type;

class ScalarConverter {
    public:
        // Constructors
        ScalarConverter();
        ScalarConverter(const std::string str);
        ScalarConverter(const ScalarConverter &copy);

        // Destructor
        ~ScalarConverter(); // not using virtual because no other class is derived from this

        // Operators
        ScalarConverter &operator=(const ScalarConverter &other);

        // Getters
        std::string get_input() const;
        t_type get_type() const;

        // Setters

        // Functions
        void convert(const std::string &input); // should only take in string representation of char, int, float, double
        // Note: If after convert to char, and is non printable then -> print an infor message
        // Take in as string, convert to actual type, then return as explicit datatype

    private:
        std::string _input;
        t_type _type;
        void _main_set_type();
        void _set_type_int_float_double();
};

// From helper file
void convert_from_char(const std::string &input);
void convert_from_int(const std::string &input);
void convert_from_float(const std::string &input);
void convert_from_double(const std::string &input);
void convert_from_nan(const std::string &input);
void convert_from_inf(const std::string &input);

#endif
