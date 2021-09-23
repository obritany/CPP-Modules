#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
private:
	std::string _ideas[100];

public:
	Brain();
	Brain(const Brain &brain);
	~Brain();

	Brain &operator=(const Brain &cat);

	void fill_ideas();
	void show_ideas();

	std::string get_idea(int index);
	void set_idea(int index, std::string idea);
};

#endif