template<scalar T>
Rectangle<T>::Rectangle(Point<T> _p1, Point<T> _p2, Point<T> _p3, Point<T> _p4)
    : p1(std::make_unique<Point<T>>(_p1)),
      p2(std::make_unique<Point<T>>(_p2)),
      p3(std::make_unique<Point<T>>(_p3)),
      p4(std::make_unique<Point<T>>(_p4)) {}

template<scalar T>
double Rectangle<T>::area() const
{
    double weight = std::sqrt(std::pow(p1->x() - p2->x(), 2) + std::pow(p1->y() - p2->y(), 2));
    double height = std::sqrt(std::pow(p2->x() - p3->x(), 2) + std::pow(p2->y() - p3->y(), 2));
    return weight * height;
}

template<scalar T>
std::string Rectangle<T>::type() const
{
    return "прямоугольник";
}

template<scalar T>
void Rectangle<T>::printVershins() const
{
    std::cout << "Вершины прямоугольника: " << *p1 << *p2 << *p3 << *p4 << std::endl;
}

template<scalar T>
Point<T> Rectangle<T>::center() const
{
    double xcenter = (p1->x() + p2->x() + p3->x() + p4->x()) / 4;
    double ycenter = (p1->y() + p2->y() + p3->y() + p4->y()) / 4;
    return Point<T>(xcenter, ycenter);
}

template<scalar T>
bool Rectangle<T>::operator==(const Figure<T>& other) const
{
    const Rectangle<T>* rect = dynamic_cast<const Rectangle<T>*>(&other);
    if (rect != nullptr)
    {
        return (rect->center() == center()) && (rect->area() == area());
    }

    return false;
}