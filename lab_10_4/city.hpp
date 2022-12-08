#pragma once

#include <iostream>

namespace mo {
	// класс, описывающий город
	class city {
	private:
		static size_t amount; // количество созданных городов

		std::string m_name; // название города
		size_t m_population; // население города
		size_t m_id; // уникальный идентификатор города
	public:
		// конструктор, принимающий название и население
		city(std::string name, size_t population);

		// деструктор
		~city();

		// метод, который выводит в консоль информацию
		void print();

		// метод, возвращающий уникальный идентификатор
		size_t getId();
	};
}