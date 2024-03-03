#include "../include/ScalarConverter.hpp"

int main(int argc, char* argv[])
{
    try {
        if (argc != 2)
        {
            throw std::invalid_argument("Usage: " + std::string(argv[0]) + " <input>");
        }
        ScalarConverter::convert(argv[1]);
        return 0;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}
