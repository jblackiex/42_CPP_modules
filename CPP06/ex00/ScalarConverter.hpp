#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cerrno>
#include <sstream>
#include <limits>
#include <iomanip>

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &obj);
	~ScalarConverter();
	ScalarConverter &operator=(const ScalarConverter &obj);

	static char _char;
	static int _int;
	static float _float;
	static double _double;
	static bool _flag_error;
	static bool _flag_inf;
public:
	static void convertInt(const std::string& str);
	static void check_type(const std::string& str);
	static void convertFloat(const std::string& str);
	static void convertDouble(const std::string& str);
	static void print_str(const std::string& str);
	static void convert(const std::string& str);

};

#endif