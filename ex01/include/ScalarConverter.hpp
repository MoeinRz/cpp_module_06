# ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <sstream>
#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>

class ScalarConverter
{
    public:
        ScalarConverter();
        ~ScalarConverter();
        static void convert(const std::string& input);

};

# endif
