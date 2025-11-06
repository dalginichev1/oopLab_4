#include <iostream>

#include "Array.hpp"
#include "Figure.hpp"
#include "Point.hpp"
#include "Rectangle.hpp"
#include "ResultFunctions.hpp"
#include "Rombus.hpp"
#include "Trapez.hpp"

int main() {
    Array<std::unique_ptr<Figure<double>>> figures;

    char choice;

    do {
        std::cout << "Main menu" << std::endl;
        std::cout << "1.Добавить прямоугольник" << std::endl;
        std::cout << "2.Добавить равнобедренную трапецию" << std::endl;
        std::cout << "3.Добавить ромб" << std::endl;
        std::cout << "4.Вывести всю информацию по фигурам" << std::endl;
        std::cout << "5.Вывести общую площадь всех фигур" << std::endl;
        std::cout << "6.Удалить фигуру по индексу" << std::endl;
        std::cout << "0.Выход" << std::endl;

        std::cin >> choice;

        switch (choice) {
        case '1': {
            auto figure = input_rectangle<double>();
            if (figure == nullptr) {
                std::cout << "Это не прямоугольник" << std::endl;
                break;
            } else {
                figures.push_back(std::move(figure));
                break;
            }
        }
        case '2': {
            auto figure = input_trapez<double>();
            if (figure == nullptr) {
                std::cout << "Это не трапеция" << std::endl;
                break;
            } else {
                figures.push_back(std::move(figure));
                break;
            }
        }
        case '3': {
            auto figure = input_rombus<double>();
            if (figure == nullptr) {
                std::cout << "Это не ромб" << std::endl;
                break;
            } else {
                figures.push_back(std::move(figure));
                break;
            }
        }
        case '4': {
            printFigureInfo(figures);
            break;
        }
        case '5': {
            double total_area = totalArea(figures);
            std::cout << "Общая площадь всех фигур: " << total_area << std::endl;
            break;
        }
        case '6': {
            int index = 0;
            std::cout << "Введите индекс фигуры" << std::endl;
            std::cin >> index;
            if (figures.size() == 0) {
                std::cout << "Фигур нет" << std::endl;
                break;
            }
            figures.remove(index);
            break;
        }
        case '0': {
            break;
        }
        }
    } while (choice != 0);

    return 0;
}
