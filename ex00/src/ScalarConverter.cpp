#include "../include/ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    return;
}

ScalarConverter::~ScalarConverter()
{
    return;
}

void ScalarConverter::convert(const std::string& input) {
    // Convert string to int
    int i;
    std::istringstream iss_int(input);
    iss_int >> i;
    if (!iss_int.fail()) {
        std::cout << "char: ";
        if (std::isprint(static_cast<char>(i))) {
            std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
        } else {
            std::cout << "Non displayable" << std::endl;
        }
        std::cout << "int: " << i << std::endl;
    } else {
        std::cerr << "Conversion to int impossible" << std::endl;
    }

    // Convert string to float
    float f;
    std::istringstream iss_float(input);
    iss_float >> std::noskipws >> f;
    if (!iss_float.fail()) {
        std::cout << "float: " << std::setprecision(std::numeric_limits<float>::digits10) << std::fixed << f << "f" << std::endl;
    } else {
        std::cerr << "Conversion to float impossible" << std::endl;
    }

    // Convert string to double
    double d;
    std::istringstream iss_double(input);
    iss_double >> std::noskipws >> d;
    if (!iss_double.fail()) {
        std::cout << "double: " << std::setprecision(std::numeric_limits<double>::digits10) << std::fixed << d << std::endl;
    } else {
        std::cerr << "Conversion to double impossible" << std::endl;
    }
}