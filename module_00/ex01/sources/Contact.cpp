#include "Contact.hpp"

void Contact::set_first_name()
{
	std::cout << "Set first name: ";
	std::getline(std::cin, first_name);
}

void Contact::set_last_name()
{
	std::cout << "Set last name: ";
	std::getline(std::cin, last_name);
}

void Contact::set_nickname()
{
	std::cout << "Set nickname: ";
	std::getline(std::cin, nickname);
}

void Contact::set_phone_number()
{
	std::cout << "Set phone number: ";
	std::getline(std::cin, phone_number);
}

void Contact::set_darkest_secret()
{
	std::cout << "Set darkest secret: ";
	std::getline(std::cin, darkest_secret);
}

void Contact::print_list()
{
	std::cout << "First name: " << first_name << std::endl;
	std::cout << "Last name: " << last_name << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone number: " << phone_number << std::endl;
	std::cout << "Darkest secret: " << darkest_secret << std::endl;
}

void Contact::print_width(std::string &str)
{
	if (str.length() > 10)
		std::cout << std::setw(9) << str.substr(0, 9) << '.';
	else
		std::cout << std::setw(10) << str;
}

void Contact::print_line(int index)
{
	std::cout << std::setw(10) << index << '|';
	print_width(first_name);
	std::cout << '|';
	print_width(last_name);
	std::cout << '|';
	print_width(nickname);
	std::cout << '|';
	std::cout << std::endl;
}

bool Contact::is_empty()
{
	return (first_name.empty());
}