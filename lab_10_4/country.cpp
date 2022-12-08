#include "country.hpp"


namespace mo {
    country::country(std::string name) : m_name(name) {
        std::cout << "Вызван конструктор страны " << m_name << std::endl;
    }

    country::~country() {
        std::cout << "Вызван деструктор страны " << m_name << std::endl;
    }

    void country::add(city* city) {
        for (size_t i = 0; i < m_cities.size(); i++) {
            if (m_cities[i]->getId() == city->getId()) {
                return;
            }
        }

        m_cities.push_back(city);
    }

    void country::remove(city* city) {
        int index = -1;

        for (size_t i = 0; i < m_cities.size(); i++) {
            if (m_cities[i]->getId() == city->getId()) {
                index = i;
                break;
            }
        }

        if (index >= 0) {
            m_cities.erase(m_cities.begin() + index);
        }
    }

    void country::print() {
        std::cout << "*** Вывод информации о стране ***" << std::endl;
        std::cout << "Страна: " << m_name << std::endl;
        if (m_cities.size() > 0) {
            std::cout << "Города: " << std::endl;
            for (size_t i = 0; i < m_cities.size(); i++) {
                m_cities[i]->print();

                for (size_t i = 0; i < 30; i++) {
                    std::cout << '_';
                }
                std::cout << std::endl;
            }
        }
        std::cout << "***" << std::endl;
    }
}