#include "../include/ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    return;
}

ScalarConverter::~ScalarConverter()
{
    return;
}

void ScalarConverter::convert(const std::string& input)
{
    std::istringstream iss(input);
    char charValue;
    int intValue;
    float floatValue;
    double doubleValue;

    if (iss >> charValue && iss.eof()) {
        if (isprint(charValue)) {
            std::cout << "Char: '" << charValue << "'" << std::endl;
        } else {
            std::cerr << "Error: Input character is not displayable." << std::endl;
        }
    }

    iss.clear();
    iss.seekg(0);

    if (iss >> intValue && iss.eof()) {
        std::cout << "Int: " << intValue << std::endl;
    }

    iss.clear();
    iss.seekg(0);

    if (iss >> floatValue && iss.eof()) {
        std::cout << "Float: " << floatValue << std::endl;
    }

    iss.clear();
    iss.seekg(0);

    if (iss >> doubleValue && iss.eof()) {
        std::cout << "Double: " << doubleValue << std::endl;
    }

    if (!iss.eof()) {
        std::cerr << "Error: Invalid input format." << std::endl;
    }
}
