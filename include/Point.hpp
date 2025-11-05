#pragma once

#include <concepts>
#include <iostream>

template<typename T>
concept scalar = std::is_arithmetic<T>::value;

template<scalar T>
class Point
{
    private:
        T _x, _y;
    public:
        Point(T x_0 = 0, T y_0 = 0);
        T x() const;
        T y() const;
        bool operator==(const Point<T>& other);
        bool operator!=(const Point<T>& other);
        friend std::ostream& operator<< <>(std::ostream& os, const Point<T>& point);
};

#include "Point.ipp"