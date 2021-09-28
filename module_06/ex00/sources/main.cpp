#include "Converter.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error: Wrong argument number\n";
		return (1);
	}

	Converter converter(argv[1]);
	converter.printChar();
	converter.printInt();
	converter.printFloat();
	converter.printDouble();
	
	return (0);
}