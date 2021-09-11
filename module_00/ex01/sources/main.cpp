#include "PhoneBook.hpp"

int main()
{
	PhoneBook phonebook;
	std::string command;

	while (true)
	{
		if (std::cin.eof())
			return (0);
		std::cout << "Enter command: ";
		std::getline(std::cin, command);

		if (!command.compare("EXIT"))
			return (0);
		else if (!command.compare("ADD"))
			phonebook.add_contact();
		else if (!command.compare("SEARCH"))
			phonebook.search_contact();
		else
			std::cout << "Wrong input!\n";
	}
	return (0);
}