#pragma once

#include "Figure.hpp"

template <scalar T>
class Trapez : public Figure<T> {
  private:
    std::shared_ptr<Point<T>> p1, p2, p3, p4;

  public:
    Trapez(Point<T> _p1, Point<T> _p2, Point<T> _p3, Point<T> _p4);
    std::string type() const override;
    double area() const override;
    Point<T> center() const override;
    void printVershins() const override;
    bool operator==(const Figure<T>& other) const override;
};

#include "Trapez.ipp"