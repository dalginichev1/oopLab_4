#pragma once

#include <iostream>
#include <memory>
#include "Rectangle.hpp"
#include "Trapez.hpp"
#include "Rombus.hpp"

template<scalar T>
void printFigureInfo(const Array<Figure<T>>& figures);

template<scalar T>
double totalArea(const Array<Figure<T>>& figures);

template<scalar T>
std::unique_ptr<Figure<T>> input_rectangle();

template<scalar T>
std::unique_ptr<Figure<T>> input_trapez();

template<scalar T>
std::unique_ptr<Figure<T>> input_rombus();

#include "ResultFunctions.ipp"