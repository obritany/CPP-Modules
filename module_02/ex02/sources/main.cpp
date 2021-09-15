#include "Fixed.hpp"

int main()
{
	Fixed a;
	std::cout << "============" << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << "============" << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a << std::endl;
	std::cout << --a << std::endl;
	std::cout << "============" << std::endl;
	std::cout << Fixed(15.5f) + Fixed(10.01f) << std::endl;

	std::cout << "============" << std::endl;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << "b is : " << b << std::endl;

	Fixed for_c(15);
	Fixed for_c2(2);
	Fixed c = for_c / for_c2;
	c = Fixed(35) / Fixed(2);
	std::cout << "c is : " << c << std::endl;
	std::cout << "============" << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << "============" << std::endl;
	std::cout << (Fixed(4.4f) < Fixed(4.5f)) << std::endl;
	std::cout << (Fixed(4.5f) == Fixed(4.5f)) << std::endl;

	return 0;
}