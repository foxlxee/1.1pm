/*
Лабораторная работа 9. Вариант 4.
Воспользуйтесь первым принципом ООП, абстракцией, и сформируйте класс, включив в него только минимальный набор переменных (полей) для заданного вашим вариантом объекта.
Используйте второй принцип ООП, инкапсуляцию, чтобы не допустить некорректного ввода параметров.
Добавьте в класс функции (методы), которые позволят решить задачу. Продемонстрируйте решение.
Разбивать класс на файлы можете по желанию.

Найти периметр прямоугольника.
*/

#include <iostream>

// класс, который содержит информацию о прямоугольнике
class Rectangle {
private:
    unsigned int m_width; // ширина
    unsigned int m_height; // высота
public:
    // конструктор, принимающий ширину и высоту
    Rectangle(unsigned int width, unsigned int height) :
        m_width(width), m_height(height) {}

    // метод, возвращающий ширину
    unsigned int getWidth() {
        return m_width;
    }

    // метод, возвращающий высоту
    unsigned int getHeight() {
        return m_height;
    }

    // метод, возвращающий периметр
    unsigned int getPerimeter() {
        return 2 * (m_width + m_height);
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    Rectangle rectangle(150, 100);

    std::cout << "Ширина: " << rectangle.getWidth() << std::endl
              << "Высота: " << rectangle.getHeight() << std::endl
              << "Периметр: " << rectangle.getPerimeter() << std::endl;
}