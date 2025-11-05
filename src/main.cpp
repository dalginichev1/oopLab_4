#include <iostream>

#include "Array.hpp"
#include "Figure.hpp"
#include "Point.hpp"
#include "Rectangle.hpp"
#include "ResultFunctions.hpp"
#include "Rombus.hpp"
#include "Trapez.hpp"

int main() 
{
    Array<std::unique_ptr<Figure<double>>> figures;

    char choice;
 
    do
    {
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
                figures.push_back(std::move(figure));
                break;
            }
            case '2': {
                auto figure = input_trapez<double>();
                figures.push_back(std::move(figure));
                break;
            }
            case '3': {
                auto figure = input_rombus<double>();
                figures.push_back(std::move(figure));
                break;
            }
            case '4': {
                printFigureInfo(figures);
                break;
            }
            case '5': {
                totalArea(figures);
                break;
            }
            case '6': {
                int index = 0;
                std::cout << "Введите индекс фигуры" << std::endl;
                std::cin >> index;
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
