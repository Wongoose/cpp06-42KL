/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 18:35:20 by zwong             #+#    #+#             */
/*   Updated: 2023/09/26 14:51:11 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Scalar type simply means any basic types that holds a fixed range of value (dynamic list is not)
// Regular cast is static_cast
// - Regular cast has runtime checks from the program
// - static_cast has not runtime check, hence program assumes you know for sure what you are doing

#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
    ScalarConverter converter = ScalarConverter();

    (void)argc;
    converter.convert(argv[1]);

    // System comparison
    // std::cout << std::strtof(argv[1], NULL) << std::endl;
    return (0);
}
