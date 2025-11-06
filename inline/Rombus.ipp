template <scalar T>
Rombus<T>::Rombus(Point<T> _p1, Point<T> _p2, Point<T> _p3, Point<T> _p4)
    : p1(std::make_unique<Point<T>>(_p1)), p2(std::make_unique<Point<T>>(_p2)),
      p3(std::make_unique<Point<T>>(_p3)), p4(std::make_unique<Point<T>>(_p4)) {
}

template <scalar T>
std::string Rombus<T>::type() const {
    return "Ромб";
}

template <scalar T>
double Rombus<T>::area() const {
    double d1 = std::sqrt(std::pow(p3->x() - p1->x(), 2) + std::pow(p3->y() - p1->y(), 2));
    double d2 = std::sqrt(std::pow(p4->x() - p2->x(), 2) + std::pow(p4->y() - p2->y(), 2));
    return (d1 * d2) / 2;
}

template <scalar T>
Point<T> Rombus<T>::center() const {
    double xcenter = (p1->x() + p2->x() + p3->x() + p4->x()) / 4;
    double ycenter = (p1->y() + p2->y() + p3->y() + p4->y()) / 4;
    return Point<T>(xcenter, ycenter);
}

template <scalar T>
void Rombus<T>::printVershins() const {
    std::cout << "Вершины ромба: " << *p1 << *p2 << *p3 << *p4 << std::endl;
}

template <scalar T>
bool Rombus<T>::operator==(const Figure<T>& other) const {
    const Rombus<T>* rombus = dynamic_cast<const Rombus<T>*>(&other);

    if (rombus == nullptr)
        return false;

    return std::abs(rombus->area() - area()) < 1e-9;
}