#include "Span.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>

int main() {

Span sp = Span(12);

// should fail because vector is empty - No span possible
try {
	std::cout << sp.shortestSpan() << std::endl;
} catch (const std::invalid_argument& e) {
	std::cout << e.what() <<  std::endl;
} catch (const std::out_of_range& e) {
	std::cout << e.what() << std::endl;
}

// should fail because vector has only 1 number - No span possible
try {
	// add number to vector
	sp.addNumber(6);
	std::cout << sp.shortestSpan() << std::endl;
} catch (const std::invalid_argument& e) {
	std::cout << e.what() <<  std::endl;
} catch (const std::out_of_range& e) {
	std::cout << e.what() << std::endl;
}

try {
	// add 4 numbers 1 by 1 to vector
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	for (size_t i = 0; i < sp.getVecSize(); ++i) {
		std::cout << sp[i] << std::endl;
	}
	std::cout << std::endl;
	std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "longest span: " << sp.longestSpan() << std::endl;

	// create 5 random numbers
	std::vector<int> nbrs = Span::createRanNbr(5);
	// add these random numbers to the vector
	sp.addManyNumbers(nbrs);

	for (size_t i = 0; i < sp.getVecSize(); ++i) {
		std::cout << sp[i] << std::endl;
	}
	std::cout << std::endl;
	std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "longest span: " << sp.longestSpan() << std::endl;

	/*
	try to add 3 more numbers (at once) but would exceed max nbr of elements
	triggers overflow protection
	*/
	nbrs = Span::createRanNbr(3);
	sp.addManyNumbers(nbrs);

} catch (const std::invalid_argument& e) {
	std::cout << e.what() <<  std::endl;
} catch (const std::out_of_range& e) {
	std::cout << e.what() << std::endl;
}
try {
	/*
	try to add 3 more numbers (one by one) but would exceed max nbr of elements
	triggers overflow protection
	*/
	sp.addNumber(-3242);
	sp.addNumber(283492348);
	sp.addNumber(48);
} catch (const std::invalid_argument& e) {
	std::cout << e.what() <<  std::endl;
} catch (const std::out_of_range& e) {
	std::cout << e.what() << std::endl;
}
	return 0;
}
