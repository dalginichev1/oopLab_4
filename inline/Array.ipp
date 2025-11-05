template<typename T>
Array<T>::Array(): _size(0), _capacity(1), _data(std::make_unique<T[]>(1)) {}

template<typename T>
void Array<T>::resize(size_t new_capacity)
{
    std::unique_ptr<T[]> new_data = std::make_unique<T[]>(new_capacity);

    size_t i = 0;

    for(i = 0; i < _size; ++i)
    {
        new_data[i] = std::move(_data[i]);
    }

    _data = std::move(new_data);
    _capacity = new_capacity;
}

template<typename T>
Array<T>::Array(Array&& other) noexcept: _size(other._size), _capacity(other._capacity), _data(std::move(other._data))
{
    other._size = 0;
    other._capacity = 0;
}

template<typename T>
Array<T>& Array<T>::operator=(Array&& other) noexcept
{
    if (this != &other)
    {
        _size = other._size;
        _capacity = other._capacity;
        _data = std::move(other._data);
        other._size = 0;
        other._capacity = 0;
    }

    return *this;
}

template<typename T>
void Array<T>::push_back(T&& t)
{
    if (_size >= _capacity)
    {
        resize(_capacity * 2);
    }

    _data[_size++] = std::move(t);
}

template<typename T>
void Array<T>::push_back(const T& t)
{
    if (_size >= _capacity)
    {
        resize(_capacity * 2);
    }

    _data[_size++] = t;
}

template<typename T>
T& Array<T>::operator[](int index)
{
    if (index < 0)
    {
        index += _size;
    }

    if((index >= _size) || (index < 0))
    {
        throw std::out_of_range("Index is out of range");
    }

    return _data[index];
}

template<typename T>
const T& Array<T>::operator[](int index) const
{
    if (index < 0)
    {
        index += _size;
    }

    if((index >= _size) || (index < 0))
    {
        throw std::out_of_range("Index is out of range");
    }

    return _data[index];
}

template<typename T>
void Array<T>::remove(int index)
{
    size_t i = 0;
    if(index < 0)
    {
        index += _size;
    }

    if (index < 0 || index >= _size)
    {
        throw std::out_of_range("Index is out of range");
    }

    for(i = index; i < _size - 1; ++i)
    {
        _data[i] = std::move(_data[i + 1]);
    }

    --_size;
}

template<typename T>
size_t Array<T>::size() const
{
    return _size;
}
