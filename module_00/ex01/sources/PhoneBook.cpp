#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	index = 0;
}

void PhoneBook::add_contact()
{
	contacts[index].set_first_name();
	contacts[index].set_last_name();
	contacts[index].set_nickname();
	contacts[index].set_phone_number();
	contacts[index].set_darkest_secret();
	if (++index == 8)
		index = 0;
}

void PhoneBook::search_contact()
{
	int trg_index;
	std::string str;

	std::cout << std::setw(11) << "index|"
			  << std::setw(11) << "first name|"
			  << std::setw(11) << "last name|"
			  << std::setw(11) << "nickname|"
			  << std::endl;

	for (int i = 0; i < 8; i++)
	{
		if (!contacts[i].is_empty())
			contacts[i].print_line(i + 1);
	}

	std::cout << "Enter index: ";
	std::getline(std::cin, str);

	trg_index = str[0] - '0';
	if (trg_index < 1 || trg_index > 8 || contacts[trg_index - 1].is_empty())
		std::cout << "Wrong index\n";
	else
		contacts[trg_index - 1].print_list();
}