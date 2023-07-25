/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 10:04:26 by zwong             #+#    #+#             */
/*   Updated: 2023/07/25 10:04:31 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>
#include <iostream>
#include <iomanip>

#define RESET "\033[39m"
#define BLACK "\033[30m"
#define GREY "\033[90m"
#define RED "\033[31m"
#define CYAN "\033[36m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[94m"
#define MAGENTA "\033[35m"

typedef struct Data_s {
    void *content;
    int num;
} Data;

class Serializer {
    public:
        // Constructors
        Serializer();
        Serializer(std::string str);
        Serializer(const Serializer &copy);

        // Destructor
        ~Serializer();

        // Operators
        Serializer &operator=(const Serializer &other);

        // Getters

        // Setters

        // Functions
        uintptr_t serialize(Data *ptr);
        Data *deserialize(uintptr_t raw);

    private:
};
#endif