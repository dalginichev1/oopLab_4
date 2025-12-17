#pragma once

#include "Figure.hpp"

template <scalar T>
class Rombus : public Figure<T> {
  private:
    std::unique_ptr<Point<T>> p1, p2, p3, p4;

  public:
    Rombus(Point<T> p1, Point<T> p2, Point<T> p3, Point<T> p4);
    double area() const override;
    std::string type() const override;
    void printVershins() const override;
    Point<T> center() const override;
    bool operator==(const Figure<T>& other) const override;
};

#include "Rombus.ipp"