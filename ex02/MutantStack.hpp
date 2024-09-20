#pragma once
// #include <deque>
#include <stack>
#include <iostream>

template<typename T>
class MutantStack : public std::stack<T> {

public:

	MutantStack() : std::stack<T>() {
		std::cout << "Default constructor called" << std::endl;
	}
	MutantStack(const MutantStack& other) : std::stack<T>(other) {
		std::cout << "Copy constructor called"<< std::endl;
	}
	MutantStack& operator=(const MutantStack& other) {
		if (this != & other) {
			std::stack<T>::operator=(other);
		}
		return *this;
	}
	~MutantStack() {
		std::cout << "Destructor called" << std::endl;
	}

	using iterator = typename std::deque<T>::iterator;
	iterator begin() {
		return this->c.begin();
	}
	iterator end() {
		return this->c.end();
	}
};
