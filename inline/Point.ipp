template<scalar T>
Point<T>::Point(T x_0, T y_0): _x(x_0), _y(y_0) {}

template<scalar T>
T Point<T>::x() const
{
    return _x;
}

template<scalar T>
T Point<T>::y() const
{
    return _y;
}

template<scalar T>
bool Point<T>::operator==(const Point& other)
{
    return _x == other._x && _y == other._y;
}

template<scalar T>
bool Point<T>::operator!=(const Point& other)
{
    return _x != other._x || _y != other._y;
}

template<scalar T>
std::ostream& operator<<(std::ostream& os, const Point<T>& point)
{
    os << "(" << point.x() << ", " << point.y() << ")" << std::endl;
    return os;
}