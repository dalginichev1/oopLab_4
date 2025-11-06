template <scalar T>
Trapez<T>::Trapez(Point<T> _p1, Point<T> _p2, Point<T> _p3, Point<T> _p4)
    : p1(std::make_unique<Point<T>>(_p1)), p2(std::make_unique<Point<T>>(_p2)),
      p3(std::make_unique<Point<T>>(_p3)), p4(std::make_unique<Point<T>>(_p4)) {
}

template <scalar T>
std::string Trapez<T>::type() const {
    return "Трапеция";
}

template <scalar T>
double Trapez<T>::area() const {
    return 0.5 * (p1->x() * (p2->y() - p4->y()) + p2->x() * (p3->y() - p1->y()) +
                  p3->x() * (p4->y() - p2->y()) + p4->x() * (p1->y() - p3->y()));
}

template <scalar T>
Point<T> Trapez<T>::center() const {
    double xcenter = (p1->x() + p2->x() + p3->x() + p4->x()) / 4;
    double ycenter = (p1->y() + p2->y() + p3->y() + p4->y()) / 4;

    return Point<T>(xcenter, ycenter);
}

template <scalar T>
void Trapez<T>::printVershins() const {
    std::cout << "Вершины трапеции: " << *p1 << *p2 << *p3 << *p4 << std::endl;
}

template <scalar T>
bool Trapez<T>::operator==(const Figure<T>(&other)) const {
    const Trapez<T>* trapez = dynamic_cast<const Trapez<T>*>(&other);
    if (trapez == nullptr)
        return false;

    return std::abs(trapez->area() - area()) < 1e-9;
}