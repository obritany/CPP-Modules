#include "span.hpp"

int main()
{
	Span sp = Span(20000);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << std::endl;

	sp.print();
	std::cout << std::endl;

	std::vector<int> test1(3, 7); // n = 3, val = 7
	sp.addNumbers(test1.begin(), test1.end());
	std::vector<int> test2(4, 8);
	sp.addNumbers(test2.begin(), test2.end());
	sp.print();
	std::cout << std::endl;

	std::vector<int> test3(18000, 1000);
	try
	{
		sp.addNumbers(test3.begin(), test3.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

		sp.addNumbers(test3.begin(), test3.end());
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}