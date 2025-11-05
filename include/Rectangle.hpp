#pragma once

#include "Figure.hpp"

template<scalar T>
class Rectangle: public Figure<T>
{
    private:
        std::unique_ptr<Point<T>> p1, p2, p3, p4;
    public:
        Rectangle(Point<T> _p1, Point<T> _p2, Point<T> _p3, Point<T> _p4);
        double area() const override;
        void printVershins() const override;
        Point<T> center() const override;
        std::string type() const override;
        bool operator==(const Figure<T>& other) const override;
};

#include "Rectangle.ipp"