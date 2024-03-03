#include "../include/ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
    std::cout << "Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const &other) 
{
    (void)other;
    std::cout << "Copy constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter(void)
{
    std::cout << "Destructor called" << std::endl;
}

void performConversions(std::string src, char& c, int& i, float& f, double& d)
{
    c = src.front();
    i = static_cast<int>(c);
    f = static_cast<float>(i);
    d = static_cast<double>(i);
}

void ScalarConverter:: convert2Char(std::string src) {
    char c;
    int i;
    float f;
    double d;
    performConversions(src, c, i, f, d);
    std::cout << "Conversion from Char" << std::endl;

    if (src == "nan" || src == "-inf" || src == "+inf") {
        std::cout << "char: Impossible" << std::endl;
    } else if (c < 32 || c > 126) {
        std::cout << "char: Non displayable" << std::endl;
    } else {
        std::cout << "char: " << c << std::endl;
    }

    if (src == "nan" || src == "-inf" || src == "+inf") {
        std::cout << "int: Impossible" << std::endl;
    } else {
        std::cout << "int: " << i << std::endl;
    }

    if (std::floor(f) == f && src != "nan" && src != "-inf" && src != "+inf") {
        std::cout << "float: " << f << ".0f" << std::endl;
    } else if (src == "-inf" || src == "+inf") {
        std::cout << "float: " << f << std::endl;
    } else {
        std::cout << "float: " << f << "f" << std::endl;
    }

    if (std::floor(d) == f && src != "nan" && src != "-inf" && src != "+inf") {
        std::cout << "double: " << f << ".0" << std::endl;
    } else {
        std::cout << "double: " << f << std::endl;
    }
}

void ScalarConverter::convert2Int(std::string src)
{
    long long ll = std::strtol(src.c_str(), nullptr, 10);
    int i = static_cast<int>(ll);
    char c = static_cast<char>(i);
    float f = static_cast<float>(i);
    double d = static_cast<double>(i);

    std::cout << "Conversion from Int" << std::endl;

    if (src == "nan" || src == "-inf" || src == "+inf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
    }
    else 
    {
    if (i < std::numeric_limits<char>::min() || i > std::numeric_limits<char>::max())
        std::cout << "char: impossible" << std::endl;
    else if (c < 32 || c > 126)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: " << c << std::endl;

    if (ll < std::numeric_limits<int>::min() || ll > std::numeric_limits<int>::max())
        std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << i << std::endl;
    }

    if (f == std::floor(f) && !std::isnan(f) && !std::isinf(f))
        std::cout << "float: " << f << ".0f" << std::endl;
    else
        std::cout << "float: " << f << "f" << std::endl;
    if (d == std::floor(d) && !std::isnan(d) && !std::isinf(d))
        std::cout << "double: " << d << ".0" << std::endl;
    else
        std::cout << "double: " << d << std::endl;
}

static bool isSpecialFloat(float value) 
{
    return !(value <= std::numeric_limits<float>::max() && value >= -std::numeric_limits<float>::max());
}

static bool isinfcustom(float value) {
    return std::isinf(value);
}

static bool isnancustom(float value) {
    return std::isnan(value);
}

void ScalarConverter::convert2Float(std::string src)
{
    std::cout << "Conversion from Float" << std::endl;
    if (!src.empty() && (src.back() == 'f' || src.back() == 'F')) 
        src.erase(src.size() - 1);

    std::istringstream iss(src);
    float f;

    if (!(iss >> f)) 
    {
        std::cout << "Conversion to float failed." << std::endl;
        return;
    }

    double d = static_cast<double>(f);
    int i = static_cast<int>(f);
    char c = static_cast<char>(f);
  
    if (src == "nan" || src == "-inf" || src == "+inf")
        std::cout << "char: impossible" << std::endl;   
    else {
        if (c < 32 || c > 126)
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: " << c << std::endl;
    }

    if (f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max() || isnancustom(f) || isinfcustom(f))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << i << std::endl;

    if (f == static_cast<float>(static_cast<int>(f)) && !isSpecialFloat(f))
        std::cout << "float: " << f << ".0f" << std::endl;
    else
        std::cout << "float: " << f << "f" << std::endl;

    if (d == static_cast<double>(static_cast<int>(d)) && !isSpecialFloat(d))
        std::cout << "double: " << d << ".0" << std::endl;
    else
        std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convert2Double(std::string src)
{
    std::cout << "Conversion from Double" << std::endl;
    std::istringstream iss(src);
    
    double d;

    if (!(iss >> d)) 
    {
        std::cout << "Conversion to double failed." << std::endl;
        return;
    }

    int i = static_cast<int>(d);
    char c = static_cast<char>(d);
    float f = static_cast<float>(d);
    
    if (std::isnan(d) || std::isinf(d))
        std::cout << "char: impossible" << std::endl; 
    else if (std::isprint(c))
        std::cout << "char: " << c << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    
    if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max() || std::isnan(d) || std::isinf(d))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << i << std::endl;

    if (f == static_cast<float>(static_cast<int>(f)) && !std::isnan(f) && !std::isinf(f))
        std::cout << "float: " << f << ".0f" << std::endl;
    else
        std::cout << "float: " << f << "f" << std::endl;

    if (d == static_cast<double>(static_cast<int>(d)) && !std::isnan(d) && !std::isinf(d))
        std::cout << "double: " << d << ".0" << std::endl;
    else
        std::cout << "double: " << d << std::endl;
}


void ScalarConverter::convert2Special(std::string src)
{
    (void)src;
    std::cout << "Conversion from Special"  << std::endl;
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: nanf" << std::endl;
    std::cout << "double: nan" << std::endl;
}

void ScalarConverter::convert(std::string const &src)
{

    if(src.back() == 'f')
    	convert2Float(src);
    else if (src.find('.') != std::string::npos)
        convert2Double(src);
    else if (src.length() > 0)
    {
        if(isdigit(src.c_str()[0]) || ((src.c_str()[0] == '-' || src.c_str()[0] == '+') && isdigit(src.c_str()[1])))
        {
               convert2Int(src);
        }
        else if (src.length() > 1)
        {
    	    convert2Special(src);
        }
        else
        {
            convert2Char(src);
        }

    }
    else
        std::cout << "Error: Invalid type" << std::endl;
}
