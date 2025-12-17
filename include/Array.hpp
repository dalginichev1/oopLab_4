#pragma once

#include <memory>

template <typename T>
class Array {
  private:
    size_t _size = 0;
    size_t _capacity = 1;
    std::shared_ptr<T[]> _data{new T[_capacity], std::default_delete<T[]>()};
    void resize(size_t new_capacity);

    public : Array();
    ~Array() noexcept = default;
    void push_back(T&& t);
    void push_back(const T& t);
    void remove(int index);
    Array(const Array& other);
    Array(Array&& other) noexcept;
    Array& operator=(const Array& other);
    Array& operator=(Array&& other) noexcept;
    T& operator[](int index);
    const T& operator[](int index) const;
    size_t size() const;
};

#include "Array.ipp"