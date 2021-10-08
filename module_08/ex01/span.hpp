#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <numeric>
#include <cmath>

class Span
{
private:
	std::vector<int> _vec;
	unsigned int _N;
	unsigned int _count;

public:
	Span();
	Span(unsigned int N);
	Span(const Span &src);
	~Span();

	Span &operator=(const Span &src);

	void addNumber(int val);
	int shortestSpan();
	int longestSpan();
	// void addNumbers(std::vector<int>::iterator start, std::vector<int>::iterator end);
};

#endif