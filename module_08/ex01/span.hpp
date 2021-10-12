#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

class Span
{
private:
	std::vector<int> _vec;
	unsigned int _N;
	unsigned int _count;

	static void printNum(int num); // static for use in print() function

public:
	Span();
	Span(unsigned int N);
	Span(const Span &src);
	~Span();

	Span &operator=(const Span &src);

	void addNumber(int val);
	int shortestSpan();
	int longestSpan();
	void addNumbers(std::vector<int>::iterator start, std::vector<int>::iterator end);
	void print();
};

#endif