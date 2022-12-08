#include "city.hpp"

namespace mo {
	size_t city::amount(0);

	city::city(std::string name, size_t population) : m_name(name), m_population(population), m_id(city::amount++) {
		std::cout << "Вызван конструктор города " << m_name << std::endl;
	}

	city::~city() {
		std::cout << "Вызван деструктор города " << m_name << std::endl;
	}

	void city::print() {
		std::cout
			<< "Город "
			<< m_name
			<< std::endl
			<< "Население приблизительно "
			<< m_population << std::endl;
	}

	size_t city::getId() {
		return m_id;
	}
}