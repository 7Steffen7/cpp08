#include "Span.hpp"
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <limits>
#include <numeric>
#include <random>
#include <stdexcept>
#include <vector>

Span::Span(unsigned int N) : _max_nbr_of_elements(N) {
	std::cout << "Span uint constructor called" << std::endl;
}

Span::Span() : _max_nbr_of_elements(0) {
	std::cout << "Span default constructor called" << std::endl;
}

Span::Span(const Span& other) : _max_nbr_of_elements(other._max_nbr_of_elements),
								_int_vec(other._int_vec) {
	std::cout << "Span copy constructor called" << std::endl;
}

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		_max_nbr_of_elements = other._max_nbr_of_elements;
		_int_vec = other._int_vec;
	}
	return *this;
}

Span::~Span() {
	std::cout << "Span destructor called" << std::endl;
}

int Span::operator[](const size_t i) const {
	if (i >= _max_nbr_of_elements)
		throw std::out_of_range("index out of range");
	return _int_vec[i];
}

void	Span::addNumber(int nbr) {
	if (_int_vec.size() >= _max_nbr_of_elements)
		throw std::out_of_range("max numbers of elements reached");
	_int_vec.push_back(nbr);
}

unsigned int Span::getVecSize() const {
	return _int_vec.size();
}

size_t Span::shortestSpan() {
	if (_int_vec.size() < 2)
		throw std::invalid_argument("Empty/Invalid Vector");
	std::vector<int> temp_vec = _int_vec;
	std::sort(temp_vec.begin(), temp_vec.end());
	std::vector<int> distances(temp_vec.size());
	std::adjacent_difference(temp_vec.begin(), temp_vec.end(), distances.begin());
	// std::cout << "test: " ;
	// for (size_t i = 0; i < distances.size(); ++i) {
	// 	std::cout << distances[i] << " ";
	// }
	// std::cout << std::endl;
	return *std::min_element(distances.begin() + 1, distances.end());
}

size_t Span::longestSpan() {
	if (_int_vec.size() < 2)
		throw std::invalid_argument("Empty/Invalid Vector");
	auto [min_it, max_it] = std::minmax_element(_int_vec.begin(), _int_vec.end());
	return *max_it - *min_it;
}

std::vector<int> Span::createRanNbr(int N) {
	std::vector<int> nbrs;
	nbrs.reserve(N);
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, std::numeric_limits<int>::max());
	for (int i = 0; i < N; ++i) {
		nbrs.push_back(dis(gen));
	}
	return nbrs;
}
