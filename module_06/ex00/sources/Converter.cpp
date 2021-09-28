#include "Converter.hpp"

Converter::Converter() : _input(""), _value(0)
{
}

Converter::Converter(const std::string input) : _input(input)
{
	if (_input.length() == 1 && !(isdigit(*(_input.c_str()))))
		_value = static_cast<double>(*(_input.c_str()));
	else
		_value = atof(_input.c_str());
}

Converter::Converter(const Converter &src) : _input(src._input), _value(src._value)
{
}

Converter::~Converter()
{
}

Converter &Converter::operator=(const Converter &src)
{
	if (this == &src)
		return (*this);

	new (this) Converter(src);
	return (*this);
}

void Converter::printChar()
{
	if (_input == "+inf" || _input == "-inf" || _input == "nan" ||
		_input == "+inff" || _input == "-inff" || _input == "nanf")
		std::cout << "char: impossible\n";
	else
	{
		char c = static_cast<char>(_value);
		if (c < 32 || c > 126)
			std::cout << "char: Non displayable\n";
		else
			std::cout << "char: " << c << std::endl;
	}
}

void Converter::printInt()
{
	if (_input == "+inf" || _input == "-inf" || _input == "nan" ||
		_input == "+inff" || _input == "-inff" || _input == "nanf")
		std::cout << "int: impossible\n";
	else
	{
		int i = static_cast<int>(_value);
		std::cout << "int: " << i << std::endl;
	}
}

void Converter::printFloat()
{
	if (_input == "+inf" || _input == "-inf" || _input == "nan")
		std::cout << "float: " << _input << "f" << std::endl;
	else if (_input == "+inff" || _input == "-inff" || _input == "nanf")
		std::cout << "float: " << _input << std::endl;
	else
	{
		float f = static_cast<float>(_value);
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	}
}

void Converter::printDouble()
{
	if (_input == "+inf" || _input == "-inf" || _input == "nan")
		std::cout << "double: " << _input << std::endl;
	else if (_input == "+inff" || _input == "-inff" || _input == "nanf")
		std::cout << "double: " << _input.substr(0, _input.size() - 1) << std::endl;
	else
	{
		double d = static_cast<double>(_value);
		std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
	}
}