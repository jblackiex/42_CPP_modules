#include "ScalarConverter.hpp"
#include <stdio.h>

/*

Quando dichiari variabili statiche in una classe in C++, 
devi fornire una definizione concreta per quelle variabili in un 
file CPP (ad esempio, ScalarConverter.cpp). 
Questo perché la dichiarazione nella classe (nel file header .h) 
fornisce solo una dichiarazione anticipata delle variabili,
ma non definisce effettivamente la memoria per esse. 
La definizione delle variabili statiche nel file CPP risolve 
questo problema e garantisce che la memoria sia effettivamente 
allocata per le variabili.

*/
char         ScalarConverter::_char;
int          ScalarConverter::_int;
float        ScalarConverter::_float;
double       ScalarConverter::_double;
bool		 ScalarConverter::_flag_char;
bool		 ScalarConverter::_flag_int;
bool		 ScalarConverter::_flag_error;
bool		 ScalarConverter::_flag_inf;

ScalarConverter::ScalarConverter(){
	this->_flag_error = false;
	this->_flag_inf = false;
  std::cout << "Default constructor called, Welcome to converter!" << std::endl;
}

ScalarConverter::~ScalarConverter(){
  std::cout << "Destructor called, Conversion did it!" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& obj){
	*this = obj;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& obj){
	if (this != &obj)
	{
		_char = obj._char;
		_int = obj._int;
		_float = obj._float;
		_double = obj._double;
		_flag_error = obj._flag_error;
		_flag_inf = obj._flag_inf;
		_flag_int = obj._flag_int;
		_flag_char = obj._flag_char;
	}
	return *this;
}

void	ScalarConverter::print_str(const std::string& str)
{
	std::cout << "char: ";
	if (_flag_error || _flag_inf)
		std::cout << "impossible" << std::endl;
	else if ((_char < 32 || _char > 126) || !_flag_char)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << _char << "'" << std::endl;

	std::cout << "int: ";
	if (!_flag_int && _int >= std::numeric_limits<int>::min() && _int <= std::numeric_limits<int>::max() && !_flag_error && !_flag_inf)	
		std::cout << _int << std::endl;
	else
		std::cout << "impossible" << std::endl;

	std::cout << "float: ";
	if (!_float && !_flag_error && !_flag_inf)
	{
		std::cout << "0.0f" << std::endl;
		std::cout << "double: " << "0.0" << std::endl;
		return ;
	}
	if (_float <= std::numeric_limits<float>::max() && !_flag_error && !_flag_inf)
			if (str.find(".") != str.npos)
				std::cout << std::fixed << std::setprecision(str.find("f") != str.npos ? (str.find("f") - str.find(".") - 1) : (str.length() - 1) - str.find(".")) << _float << "f" << std::endl;
			else
				std::cout << std::fixed << std::setprecision(1) << _float << "f" << std::endl;	
	else if (_flag_inf)
		std::cout << (str[0] == '-' ? "-" : "+") << "inff" << std::endl;
	else
		std::cout << "nanf" << std::endl;

	std::cout << "double: ";
	if (_double <= std::numeric_limits<double>::max() && !_flag_error && !_flag_inf)
		if (str.find(".") != str.npos)
			std::cout << std::fixed << std::setprecision(str.find("f") != str.npos ? ((str.length() - 1) - str.find(".") - 1) : (str.length() - 1) - str.find(".")) << _double << std::endl;
		else
			std::cout << std::fixed << std::setprecision(1) << _double << std::endl;	
	else if (_flag_inf)
		std::cout << (str[0] == '-' ? "-" : "+") << "inf" << std::endl;
	else
		std::cout << "nan" << std::endl;
}

void ScalarConverter::convertInt(const std::string& str)
{
	long int inte;
	inte = std::strtol(str.c_str(), 0, 10);
	if ((inte < INT_MIN || inte > INT_MAX))
	{
		_flag_error = true;
		return ;
	}
	_int = (int) inte;
	_char = static_cast<char>(_int);
	_float = static_cast<float>(_int);
	_double = static_cast<double>(_int);
}

void ScalarConverter::convertFloat(const std::string& str)
{
	long double floate;

	floate = std::strtof(str.c_str(), 0);
	if (floate < -FLT_MAX || floate > FLT_MAX)
	{
		_flag_error = true;
		return ;
	}
	_float = std::strtof(str.c_str(), 0);
	_int = static_cast<int>(_float);
	if ((int)_float < INT_MIN || (int)_float > INT_MAX)
		_flag_int = true;
	_char = static_cast<char>(_float);
	_double = static_cast<double>(_float);
}

void ScalarConverter::convertDouble(const std::string& str)
{
	long long doubl;
	doubl = std::strtod(str.c_str(), 0);
	if (doubl < -DBL_MAX || doubl > DBL_MAX)
	{
		_flag_error = true;
		return ;
	}
	_double = std::strtod(str.c_str(), 0);;
	_int = static_cast<int>(_double);
	if (_double < INT_MIN || _double > INT_MAX)
		_flag_int = true;
	_char = static_cast<char>(_double);
	_float = static_cast<float>(_double);
}

bool isInt(const std::string& str) {
    char* endPtr; // Puntatore all'ultimo carattere convertito da strtol
    std::strtol(str.c_str(), &endPtr, 10);
    // Verifica se la conversione ha avuto successo
    return (endPtr == str.c_str() + str.length());
}

bool isFloat(const std::string& str) {
	std::string tmp = str;
	tmp.erase(tmp.length() - 1);
    std::stringstream iss(tmp);
    float f;
    return (!(iss >> f).fail()) && (iss.eof());
}

bool isDouble(const std::string& str) {
	//if (str.find("f") != str.npos)
		//return false;
	std::stringstream iss(str);
    double d;
    return (!(iss >> d).fail()) && (iss.eof());
}

void ScalarConverter::check_type(const std::string& str)
{
	if (str.find("f") == str.npos && str.find(".") == str.npos && isInt(str))
		convertInt(str);
	else if (isFloat(str) && str.find("f") != str.npos)
		convertFloat(str);
	else if (isDouble(str))
		convertDouble(str);
	else
		_flag_error = true;
}

void ScalarConverter::convert(const std::string& str) {

	_flag_error = false;
	_flag_inf = false;
	_flag_char = false;
	int count = 0;
	if (str == "nan" || str == "nanf")
		_flag_error = true;
	else if (str == "-inff" || str == "+inff" || str == "inff" || str == "-inf" || str == "+inf" || str == "inf")
		_flag_inf = true;
	else if (str.length() == 1 && !isdigit(str[0]))
	{
    	_char = str[0];
    	_int = static_cast<int>(str[0]);
    	_float = static_cast<float>(str[0]);
    	_double = static_cast<double>(str[0]);
		_flag_char = true;
	}
	else if (!_flag_error && !_flag_inf)
	{
		if (str[0] == '.')
			_flag_error = true;
		else
		{
			for (std::string::size_type i = 1; i < str.length(); i++)
				if (!std::isdigit(str[i])) {
					_flag_error = ((i == str.length() - 1) && str[i] == 'f') || (str[i] == '.' && ++count) ? false : true;
			}
		}
		if (count > 1 || str[str.length() - 1] == '.')
			_flag_error = true;
		if (!_flag_error)
			check_type(str);
	}
	print_str(str);
}
