#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array
{
private:
	T *_arr;
	unsigned int _len;

public:
	Array();
	Array(unsigned int n);
	Array(const Array &src);
	~Array();

	Array &operator=(const Array &src);
	T &operator[](unsigned int i);

	unsigned int size() const;

	class IndexOutOfRangeException : public std::exception
	{
	public:
		const char *what() const throw();
	};
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

template <typename T>
T &Array<T>::operator[](unsigned int i)
{
	if (i >= _len)
		throw IndexOutOfRangeException();

	return (_arr[i]);
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (_len);
}

template <typename T>
const char *Array<T>::IndexOutOfRangeException::what() const throw()
{
	return ("Index Out Of Range Exception");
}

#endif