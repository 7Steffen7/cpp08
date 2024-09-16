#pragma once

#include <exception>
#include <algorithm>
#include <iostream>

template<typename T>
void easyfind(const T vec, const int ref) {
	// auto it = std::find(vec.begin(), vec.end(), ref);
	typename T::const_iterator it = std::find(vec.begin(), vec.end(), ref);
	if (it == vec.end())
		throw std::exception();
	std::cout << "matching number found at index: " << it - vec.begin() << std::endl;
}
