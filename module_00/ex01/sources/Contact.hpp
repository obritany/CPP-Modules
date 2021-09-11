#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>

class Contact
{
private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;
	void print_width(std::string &str);

public:
	void set_first_name();
	void set_last_name();
	void set_nickname();
	void set_phone_number();
	void set_darkest_secret();
	void print_list();
	void print_line(int index);
	bool is_empty();
};

#endif