#ifndef ITER_HPP
#define ITER_HPP

template <typename T>
void print(T& val)
{
	std::cout << val << " ";
}

template <typename T>
void doubling(T& val)
{
	val += val;
}

template <typename T>
void iter(T *arr, int len, void f(T &))
{
	for (int i = 0; i < len; i++)
		f(arr[i]);
}

#endif