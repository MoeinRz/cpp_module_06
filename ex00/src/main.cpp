#include "../include/ScalarConverter.hpp"

void leakes(void)
{
    system("leaks converter");
}

int main(int argc, char* argv[])
{
    try {
        if (argc != 2)
        {
            throw std::invalid_argument("Usage: " + std::string(argv[0]) + " <input>");
        }
        // leakes();
        ScalarConverter::convert(argv[1]);
        return 0;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}
