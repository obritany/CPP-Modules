#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Default constructor\n";
}

Brain::Brain(const Brain &brain)
{
	*this = brain;
	std::cout << "Brain Copy constructor\n";
}

Brain::~Brain()
{
	std::cout << "Brain destructor\n";
}

Brain &Brain::operator=(const Brain &brain)
{
	for (int i = 0; i < 100; i++)
		_ideas[i] = brain._ideas[i];
	return (*this);
}

void Brain::fill_ideas()
{
	for (int i = 0; i < 100; i++)
		_ideas[i] = "Idea #" + std::to_string(i);
}

void Brain::show_ideas()
{
	for (int i = 0; i < 100; i++)
		std::cout << _ideas[i] << std::endl;
}

std::string Brain::get_idea(int index)
{
	return (_ideas[index]);
}

void Brain::set_idea(int index, std::string idea)
{
	_ideas[index] = idea;
}