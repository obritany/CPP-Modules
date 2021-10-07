#include <iostream>

struct Data
{
};

uintptr_t serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*	deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}

int main()
{
	Data		data;
	Data		*data_ptr;
	uintptr_t	uiptr;

	std::cout << "Data address:\t\t\t\t" << &data << std::endl;
	uiptr = serialize(&data);
	std::cout << "Data address\t-> uintptr_t:\t\t" << uiptr << std::endl;
	data_ptr = deserialize(uiptr);
	std::cout << "uintptr_t\t-> Data address:\t" << data_ptr << std::endl;
	return (0);
}