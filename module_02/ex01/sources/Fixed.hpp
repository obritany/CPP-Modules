#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int _value;
	static const int _fractional_bits = 8;

public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed &fixed);
	~Fixed();

	Fixed &operator=(const Fixed &fixed);

	int getRawBits() const;
	void setRawBits(const int raw);
	int toInt() const;
	float toFloat() const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif