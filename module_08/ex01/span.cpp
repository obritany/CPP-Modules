#include "span.hpp"

Span::Span() : _N(0), _count(0)
{
}

Span::Span(unsigned int N) : _N(N), _count(0)
{
}

Span::Span(const Span &src) : _vec(src._vec), _N(src._N), _count(src._count)
{
}

Span::~Span()
{
}

Span &Span::operator=(const Span &src)
{
	if (this == &src)
		return (*this);

	new (this) Span(src);
	return (*this);
}

void Span::addNumber(int val)
{
	if (_count >= _N)
		throw std::exception();

	_vec.push_back(val);
	_count++;
}

int Span::shortestSpan()
{
	if (_count < 2)
		throw std::exception();

	std::vector<int> temp(_vec);
	std::sort(temp.begin(), temp.end());
	std::adjacent_difference(temp.begin(), temp.end(), temp.begin());
	int min = *std::min_element(temp.begin(), temp.end());
	return (std::fabs(min));
}

int Span::longestSpan()
{
	if (_count < 2)
		throw std::exception();

	std::vector<int> temp(_vec);
	int max = *std::max_element(temp.begin(), temp.end()) - *std::min_element(temp.begin(), temp.end());
	return (std::fabs(max));
}

void Span::addNumbers(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
	int size = std::distance(start, end);
	if (_vec.size() + size > _N)
		throw std::exception();

	_count += size;
	_vec.insert(_vec.begin() + _vec.size(), start, end); // dest start it, src start it, src end it
}

void Span::printNum(int val)
{
	std::cout << val << std::endl;
}

void Span::print()
{
	std::for_each(_vec.begin(), _vec.end(), printNum);
}