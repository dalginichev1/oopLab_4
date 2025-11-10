template <scalar T>
Point<T>::Point(T x_0, T y_0) : _x(x_0), _y(y_0) {
}

template <scalar T>
T Point<T>::x() const {
    return _x;
}

template <scalar T>
T Point<T>::y() const {
    return _y;
}

template <scalar T>
bool Point<T>::operator==(const Point& other) const {
    return _x == other._x && _y == other._y;
}

template <scalar T>
bool Point<T>::operator!=(const Point& other) const {
    return _x != other._x || _y != other._y;
}

template <scalar T>
Point<T> Point<T>::operator-(const Point<T>& other) {
    return Point<T>(_x - other._x, _y - other._y);
}

template <scalar T>
T dot_prod(const Point<T>& v1, const Point<T>& v2) {
    return v1.x() * v2.x() + v1.y() * v2.y();
}

template <scalar T>
T cross(const Point<T>& v1, const Point<T>& v2) {
    return v1.x() * v2.y() - v1.y() * v2.x();
}

template <scalar T>
std::ostream& operator<<(std::ostream& os, const Point<T>& point) {
    os << "(" << point.x() << ", " << point.y() << ")" << std::endl;
    return os;
}