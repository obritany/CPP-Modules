#ifndef EASYFIND_HPP
#define EASYFIND_HPP

template <typename T>
typename T::iterator easyfind(T &cont, int val)
{
	typename T::iterator rslt;

	rslt = std::find(cont.begin(), cont.end(), val);

	if (*rslt != val)
		throw std::exception();
	return rslt;
}

#endif