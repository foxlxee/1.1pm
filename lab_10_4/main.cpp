/*
Лабораторная работа 10. Вариант 4.
Вам даны два объекта, которые связаны между собой. Необходимо создать 2 класса, описывающие эти объекты и принадлежность 2го объекта 1ому.
Экземпляры классом храните в хипе.
*/

#include "country.hpp"
#include "city.hpp"

int main() {
	setlocale(LC_ALL, "Russian");

	mo::country* country = new mo::country("Российская Федерация");
	mo::city* city1 = new mo::city("Москва", 11920000);
	mo::city* city2 = new mo::city("Санкт-Петербург", 4991000);
	mo::city* city3 = new mo::city("Калининград", 498000);
	mo::city* city4 = new mo::city("Владивосток", 598000);

	country->add(city1);
	country->add(city1);
	country->add(city1);

	country->add(city2);

	country->add(city3);
	country->add(city3);

	country->add(city4);

	country->print();

	delete country;
}