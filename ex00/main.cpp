#include "easyfind.hpp"
#include <exception>
#include <iostream>
#include <vector>

int main() {
	std::vector<int> int_vec = {6, 1, 7, 1345, 6, 0, -9, 2};
	int_vec.push_back(-99);
	int_vec.push_back(-4);
	std::vector<char> char_vec = {'c', 'a', 'l'};
	std::vector<float> float_vec = {2.1f, 6.1f, 5.9f, 2.0f};

	try {
		easyfind(int_vec, 2);
		easyfind(float_vec, 2);
		easyfind(char_vec, 2);
	} catch (std::exception) {
		std::cout << "No matching number" << std::endl;
	}
	return 0;
}
