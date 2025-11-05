template <scalar T> 
Figure<T>::operator double() const {
    return area();
}

template <scalar T>
bool Figure<T>:: operator!=(const Figure& other) const
{
    return !(*this == other);
}