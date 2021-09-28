#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <iostream>
#include <iomanip>

class Converter
{
private:
	std::string _input;
	double _value;

public:
	Converter();
	Converter(const std::string input);
	Converter(const Converter &src);
	~Converter();

	Converter &operator=(const Converter &src);

	void printChar();
	void printInt();
	void printFloat();
	void printDouble();
};

#endif