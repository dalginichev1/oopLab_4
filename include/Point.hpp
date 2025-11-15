#pragma once

#include <iostream>
#include <concepts>

template <typename T>
concept scalar = std::is_integral<T>::value || std::is_floating_point<T>::value;

template <scalar T>
class Point {
  private:
    T _x, _y;

  public:
    Point(T x_0 = 0, T y_0 = 0);
    T x() const;
    T y() const;
    bool operator==(const Point<T>& other) const;
    bool operator!=(const Point<T>& other) const;
    Point<T> operator-(const Point<T>& other);
    T dot_prod(const Point<T>& v1, const Point<T>& v2);
    T cross(const Point<T>& v1, const Point<T>& v2);
    template <scalar U>
    friend std::ostream& operator<<(std::ostream& os, const Point<T>& point);
};

template <scalar T>
std::ostream& operator<<(std::ostream& os, const Point<T>& point);

#include "Point.ipp"
