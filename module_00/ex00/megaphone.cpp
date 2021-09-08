#include <iostream>

int main(int argc, char *argv[])
{
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
		while (*(++argv))
			while (**argv)
				std::cout << (char)std::toupper(*(*argv)++);
	std::cout << "\n";
	return (0);
}