#pragma once
// #include <deque>
#include <stack>

template<typename T>
class MutantStack : public std::stack<T> {

public:
	using iterator = typename std::deque<T>::iterator;
	iterator begin() {
		return this->c.begin();
	}
	iterator end() {
		return this->c.end();
	}
};
