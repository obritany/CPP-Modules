#include "Fixed.hpp"

int main()
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max(a, b) << std::endl;
	std::cout << std::endl;

	std::cout << "a--:\t" << a-- << std::endl;
	std::cout << "a:\t" << a << std::endl;
	std::cout << "--a:\t" << --a << std::endl;
	std::cout << "--a:\t" << --a << std::endl;
	std::cout << std::endl;

	std::cout << "18.3f + 9.5f:\t" << Fixed(18.3f) + Fixed(9.5f) << std::endl;
	std::cout << "15 - 2:\t\t" << Fixed(15) - Fixed(2) << std::endl;
	std::cout << "2.1f * 3.2f:\t" << Fixed(2.1f) * Fixed(3.2f) << std::endl;
	std::cout << "15 / 4:\t\t" << Fixed(15) / Fixed(4) << std::endl;
	std::cout << std::endl;

	std::cout << "3.5f < 3.6f:\t" << (Fixed(3.5f) < Fixed(3.6f)) << std::endl;
	std::cout << "3.5f > 3.6f:\t" << (Fixed(3.5f) > Fixed(3.6f)) << std::endl;
	std::cout << "3.5f == 3.5f:\t" << (Fixed(3.5f) == Fixed(3.5f)) << std::endl;
	std::cout << "3.5f != 3.6f:\t" << (Fixed(3.5f) != Fixed(3.6f)) << std::endl;
	std::cout << std::endl;

	std::cout << "min(3.5f, 3.6f):\t" << Fixed::min(Fixed(3.5f), Fixed(3.6f)) << std::endl;
	std::cout << "max(3.5f, 3.6f):\t" << Fixed::max(Fixed(3.5f), Fixed(3.6f)) << std::endl;

	return 0;
}