# ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <limits>

class ScalarConverter
{
    public:
        ScalarConverter();
        ~ScalarConverter();
        static void convert(const std::string& input);

};

# endif
