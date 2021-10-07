#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array
{
private:
	// T *_arr;
	// unsigned int _len;

public:
	T *_arr;
	unsigned int _len;
	Array();
	Array(unsigned int n);
	Array(const Array &src);
	~Array();

	Array &operator=(const Array &src);
};

template <typename T>
Array<T>::Array() : _arr(NULL), _len(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : _len(n)
{
	_arr = new T[_len];
	for (unsigned int i = 0; i < _len; i++)
		new (_arr + i) T();
}

template <typename T>
Array<T>::Array(const Array &src) : _len(src._len)
{
	_arr = new T[_len];
	for (unsigned int i = 0; i < _len; i++)
		_arr[i] = src._arr[i];
}

template <typename T>
Array<T>::~Array()
{
	delete[] _arr;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &src)
{
	if (this == &src)
		return (*this);

	delete[] _arr;
	new (this) Array(src);
	return (*this);
}

#endif