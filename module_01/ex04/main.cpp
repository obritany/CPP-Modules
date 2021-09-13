#include <iostream>
#include <fstream>

std::string replace_line(std::string src_line, std::string s1, std::string s2)
{
	size_t pos = 0;
	size_t s1_len = s1.length();

	while (true)
	{
		pos = src_line.find(s1, pos);
		if (pos == std::string::npos)
			break;
		src_line.erase(pos, s1_len);
		src_line.insert(pos, s2);
	}
	return (src_line);
}

void replace_file(std::ifstream &ifstream, std::ofstream &ofstream,
				  std::string s1, std::string s2)
{
	std::string src_line;
	std::string new_line;

	while (ifstream.good())
	{
		std::getline(ifstream, src_line);
		new_line = replace_line(src_line, s1, s2);
		ofstream << new_line;
		if (ifstream.good())
			ofstream << std::endl;
	}
}

int main(int argc, char *argv[])
{
	std::ifstream ifstream;
	std::ofstream ofstream;
	std::string out_file;

	if (argc != 4)
	{
		std::cout << "Error: Wrong arguments\n";
		return (1);
	}

	ifstream.open(argv[1], std::ifstream::in);
	if (!ifstream.is_open())
	{
		std::cout << "Error: Wrong input file\n";
		return (2);
	}

	out_file = std::string(argv[1]).append(".replace");
	ofstream.open(out_file.c_str(), std::ofstream::out | std::ofstream::trunc);
	if (!ofstream.is_open())
	{
		std::cout << "Error: Wrong output file\n";
		return (3);
	}

	replace_file(ifstream, ofstream, argv[2], argv[3]);
	ifstream.close();
	ofstream.close();
	return (0);
}