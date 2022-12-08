#pragma once

#include <iostream>
#include <vector>
#include "city.hpp"

namespace mo {
	// класс, описывающий страну
	class country {
	private:
		std::string m_name; // название страны
		std::vector<city*> m_cities; // города в стране
	public:
		// конструктор, принимающий название
		country(std::string name);

		// деструктор
		~country();

		// метод, который добавляет город в страну
		void add(city* city);

		// метод, который убирает город из страны
		void remove(city* city);

		// метод, который выводит в консоль информацию
		void print();
	};
}