#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {}

Fixed::Fixed(const int value)
{
	_value = value << _fractional_bits;
}

Fixed::Fixed(const float value)
{
	_value = (int)roundf(value * (float)(1 << _fractional_bits));
}

Fixed::Fixed(const Fixed &fixed)
{
	*this = fixed;
}

Fixed::~Fixed() {}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	if (this == &fixed)
		return (*this);

	_value = fixed.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const
{
	return (_value);
}

void Fixed::setRawBits(int const raw)
{
	_value = raw;
}

int Fixed::toInt() const
{
	return (_value >> _fractional_bits);
}

float Fixed::toFloat() const
{
	return ((float)_value / (float)(1 << _fractional_bits));
}

std::ostream &operator<<(std::ostream &cout, const Fixed &fixed)
{
	cout << fixed.toFloat();
	return (cout);
}

bool Fixed::operator>(const Fixed &fixed) const
{
	return (_value > fixed.getRawBits());
}

bool Fixed::operator<(const Fixed &fixed) const
{
	return (_value < fixed.getRawBits());
}

bool Fixed::operator>=(const Fixed &fixed)
{
	return (_value >= fixed.getRawBits());
}

bool Fixed::operator<=(const Fixed &fixed)
{
	return (_value <= fixed.getRawBits());
}

bool Fixed::operator==(const Fixed &fixed)
{
	return (_value == fixed.getRawBits());
}

bool Fixed::operator!=(const Fixed &fixed)
{
	return (_value != fixed.getRawBits());
}

Fixed Fixed::operator+(const Fixed &fixed)
{
	Fixed rslt;

	rslt.setRawBits(_value + fixed.getRawBits());
	return (rslt);
}

Fixed Fixed::operator-(const Fixed &fixed)
{
	Fixed rslt;

	rslt.setRawBits(_value - fixed.getRawBits());
	return (rslt);
}

Fixed Fixed::operator*(const Fixed &fixed)
{
	Fixed rslt;

	rslt.setRawBits((_value * fixed.getRawBits()) >> _fractional_bits);
	return (rslt);
}

Fixed Fixed::operator/(const Fixed &fixed)
{
	Fixed rslt;

	rslt.setRawBits((_value << _fractional_bits) / fixed.getRawBits());
	return (rslt);
}

Fixed &Fixed::operator++()
{
	++_value;
	return (*this);
}

Fixed &Fixed::operator--()
{
	--_value;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed src(*this);

	_value++;
	return (src);
}

Fixed Fixed::operator--(int)
{
	Fixed src(*this);

	_value--;
	return (src);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return a;
	else
		return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return a;
	else
		return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return a;
	else
		return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return a;
	else
		return b;
}