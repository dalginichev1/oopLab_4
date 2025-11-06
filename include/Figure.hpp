#pragma once

#include <cmath>
#include <iostream>
#include <memory>
#include <string>

#include "Point.hpp"

template <scalar T>
class Figure {
  private:
    std::unique_ptr<Point<T>> point;

  public:
    virtual bool operator==(const Figure& other) const = 0;
    bool operator!=(const Figure& other) const;
    virtual void printVershins() const = 0;
    virtual double area() const = 0;
    virtual Point<T> center() const = 0;
    virtual std::string type() const = 0;
    explicit virtual operator double() const;
    virtual ~Figure() = default;
};

#include "Figure.ipp"