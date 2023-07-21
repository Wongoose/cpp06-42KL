// Regular cast bs static_cast
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