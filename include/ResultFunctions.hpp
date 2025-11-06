#pragma once

#include <iostream>
#include <memory>

#include "Rectangle.hpp"
#include "Rombus.hpp"
#include "Trapez.hpp"

template <scalar T>
void printFigureInfo(const Array<Figure<T>>& figures);

template <scalar T>
double totalArea(const Array<Figure<T>>& figures);

template <scalar T>
std::unique_ptr<Figure<T>> input_rectangle();

template <scalar T>
std::unique_ptr<Figure<T>> input_trapez();

template <scalar T>
std::unique_ptr<Figure<T>> input_rombus();

template <scalar T>
bool isRect(const Array<std::unique_ptr<Point<T>>>& points);

template <scalar T>
bool isTrapez(const Array<std::unique_ptr<Point<T>>>& points);

template <scalar T>
bool isRombus(const Array<std::unique_ptr<Point<T>>>& points);

#include "ResultFunctions.ipp"