#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP


# include <iostream>
# include <string>
# include <fstream>
# include <cstdlib>
# include <ctime>
# include <limits>
# include <sstream>
# include <cmath>

class ScalarConverter
{
    public:
        ScalarConverter(ScalarConverter const &other);
        ~ScalarConverter();
        static void convert(std::string const &src);
    private:
        ScalarConverter(void);
        static void convert2Special(std::string src);
        static void convert2Char(std::string src);
        static void convert2Int(std::string src);
        static void convert2Float(std::string src);
        static void convert2Double(std::string src);
};

#endif
