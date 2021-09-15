#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called\n";
	_value = value << Fixed::_fractional_bits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called\n";
	_value = (int)roundf(value * (1 << Fixed::_fractional_bits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called\n";
	*this = fixed;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Assignation operator called\n";

	if (this == &fixed)
		return (*this);

	_value = fixed.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function is called\n";
	return (_value);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function is called\n";
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

Fixed Fixed::operator*(const Fixed &fixed)///////////////////////////////
{
	Fixed rslt;

	rslt.setRawBits(_value * (fixed.getRawBits() >> Fixed::_fractional_bits));
	return (rslt);
}

Fixed Fixed::operator/(const Fixed &fixed)///////////////////////////////
{
	Fixed res;

	res.setRawBits((_value << Fixed::_fractional_bits) / fixed.getRawBits());
	return (res);
}

Fixed &Fixed::operator++()
{
	setRawBits(++_value);
	return (*this);
}

Fixed &Fixed::operator--()
{
	setRawBits(--_value);
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed src(*this);
	setRawBits(++_value);
	return (src);
}

Fixed Fixed::operator--(int)
{
	Fixed src(*this);
	setRawBits(--_value);
	return (src);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return a;
	return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return a;
	return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return a;
	return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return a;
	return b;
}