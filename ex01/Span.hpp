#pragma once
#include <cstddef>
#include <iterator>
#include <stdexcept>
#include <vector>

class Span {
	public:
		Span();
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		int operator[](const size_t) const;
		~Span();

		unsigned int getVecSize() const;
		void addNumber(int nbr);
		template<typename T>
		void addManyNumbers(const T& source) {
			if (std::size(source) + _int_vec.size() > _max_nbr_of_elements)
				throw  std::out_of_range("max numbers of elements reached");
			_int_vec.insert(_int_vec.end(), std::begin(source), std::end(source));
		}
		size_t shortestSpan();
		size_t longestSpan();
		static std::vector<int> createRanNbr(int N);

	private:
		unsigned int _max_nbr_of_elements;
		std::vector<int> _int_vec;
};
