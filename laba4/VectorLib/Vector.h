#pragma once

#include <iostream>
#include <algorithm>

template<typename T>
class OwnIterator;
template<typename T>
class OwnReverseIterator;

template <typename T>
class Vector
{
    typedef OwnIterator<T> iterator;
    typedef OwnIterator<const T> const_iterator;

    typedef OwnReverseIterator<T> reverse_iterator;
    typedef OwnReverseIterator<const T> const_reverse_iterator;

public:

    Vector();
    Vector(size_t size);
    Vector(const Vector<T>& other);
    ~Vector();

    T* data() const;
    T& front() const;
    T& back() const;
    T& at(size_t index);
    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    size_t size() const;
    size_t max_size() const;
    size_t capacity() const;
    bool empty() const;

    void push_back(const T& value);
    void pop_back();
    void emplace(size_t index, T&& value);
    void emplace_back(T&& value);
    void insert(size_t index, const T& value);
    void erase(size_t index);
    void assign(size_t count, const T& value);
    Vector<T>& operator=(const Vector<T>& other);

    void reserve(size_t newCapacity);
    void clear();
    void resize(size_t newSize);

    void sort();
    void reverse();
    void swap(int a, int b);

    iterator begin();
    iterator end();
    const_iterator cbegin() const;
    const_iterator cend() const;

    reverse_iterator rbegin();
    reverse_iterator rend();
    const_reverse_iterator crbegin() const;
    const_reverse_iterator crend() const;

private:

    T* data_m;
    size_t size_m;
    size_t capacity_m;
};

template<typename T>
class OwnIterator : public std::iterator<std::input_iterator_tag, T>
{
    template<typename U>
    friend class Vector;
private:
    OwnIterator(T* p);
public:
    OwnIterator(const OwnIterator& it);

    bool operator!=(OwnIterator const& other) const;
    bool operator==(OwnIterator const& other) const;

    T& operator*() const;
    OwnIterator& operator++();
    OwnIterator& operator--();
    friend OwnIterator operator - (OwnIterator& i1, OwnIterator& i2);

private:
    T* p;
};

template<typename T>
class OwnReverseIterator
{
    template<typename U>
    friend class Vector;
private:
    OwnReverseIterator(T* p);
public:
    OwnReverseIterator(const OwnReverseIterator& it);

    bool operator!=(OwnReverseIterator const& other) const;
    bool operator==(OwnReverseIterator const& other) const;

    T& operator*() const;
    OwnReverseIterator& operator++();
private:
    T* p;
};

template <typename T>
Vector<T>::Vector()
{
    size_m = 0;
    capacity_m = 0;
    data_m = nullptr;
}

template <typename T>
Vector<T>::Vector(size_t size)
{
    size_m = size;
    capacity_m = size;
    data_m = new T[size];
}

template <typename T>
Vector<T>::Vector(const Vector<T>& other)
{
    size_m = other.size_m;
    capacity_m = other.capacity_m;
    data_m = new T[other.capacity_m];
    for (size_t i = 0; i < other.size_m; i++)
    {
        data_m[i] = other.data_m[i];
    }
}

template <typename T>
Vector<T>::~Vector()
{
    this->clear();
}

template <typename T>
T* Vector<T>::data() const
{
    return data_m;
}

template <typename T>
T& Vector<T>::front() const
{
    return data_m[0];
}

template <typename T>
T& Vector<T>::back() const
{
    return data_m[size_m - 1];
}

template <typename T>
T& Vector<T>::at(size_t index)
{
    if (index >= size_m)
        throw std::out_of_range("Out of vector");
    return data_m[index];
}

template <typename T>
T& Vector<T>::operator[](size_t index)
{
    return data_m[index];
}

template <typename T>
const T& Vector<T>::operator[](size_t index) const
{
    return data_m[index];
}

template <typename T>
size_t Vector<T>::size() const
{
    return size_m;
}

template <typename T>
size_t Vector<T>::max_size() const
{
    return 4294967295 / sizeof(Vector<T>);
}

template <typename T>
size_t Vector<T>::capacity() const
{
    return capacity_m;
}

template <typename T>
bool Vector<T>::empty() const
{
    return !size();
}

template <typename T>
void Vector<T>::push_back(const T& value)
{
    if (size_m == 0)
    {
        reserve(1);
    }
    else if (size_m == capacity_m)
    {
        reserve(capacity_m * 2);
    }
    data_m[size_m] = value;
    ++size_m;
}

template <typename T>
void Vector<T>::pop_back()
{
    --size_m;
}

template <typename T>
void Vector<T>::emplace(size_t index, T&& value)
{
    if (index > size_m)
    {
        throw std::out_of_range("Index out of range");
    }
    if (size_m == capacity_m)
    {
        this->reserve(capacity_m * 2);
    }
    for (int i = size_m; i > index; i--)
    {
        data_m[i] = data_m[i - 1];
    }
    data_m[index] = std::move(value);
    size_m++;
}

template <typename T>
void Vector<T>::emplace_back(T&& value)
{
    if (size_m == 0)
    {
        reserve(1);
    }
    else if (size_m == capacity_m)
    {
        reserve(capacity_m * 2);
    }
    data_m[size_m] = std::move(value);
    ++size_m;
}

template <typename T>
void Vector<T>::insert(size_t index, const T& value)
{
    if (index > size_m)
    {
        throw std::out_of_range("Index out of range");
    }
    if (size_m == capacity_m)
    {
        this->reserve(capacity_m * 2);
    }
    for (int i = size_m; i > index; i--)
    {
        data_m[i] = data_m[i - 1];
    }
    data_m[index] = value;
    size_m++;
}

template <typename T>
void Vector<T>::erase(size_t index)
{
    if (index >= size_m)
    {
        throw std::out_of_range("Index out of range");
    }
    for (int i = index; i < size_m - 1; i++)
    {
        data_m[i] = data_m[i + 1];
    }
    size_m--;
}

template <typename T>
void Vector<T>::assign(size_t count, const T& value)
{
    this->clear();
    reserve(count);
    for (size_t i = 0; i < count; ++i)
    {
        data_m[i] = value;
    }
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
    if (this != &other)
    {
        this->clear();
        size_m = other.size_m;
        capacity_m = other.capacity_m;
        data_m = new T[other.capacity_m];
        for (size_t i = 0; i < other.size_m; i++)
        {
            data_m[i] = other.data_m[i];
        }
    }
    return *this;
}

template <typename T>
void Vector<T>::reserve(size_t newCapacity)
{
    if (newCapacity > capacity_m)
    {
        T* newData = new T[newCapacity];
        for (size_t i = 0; i < size_m; i++)
        {
            newData[i] = data_m[i];
        }
        delete[] data_m;
        data_m = newData;
        capacity_m = newCapacity;
    }
}

template <typename T>
void Vector<T>::clear()
{
    if (!data_m)
        return;
    delete[] data_m;
    data_m = nullptr;
    size_m = 0;
    capacity_m = 0;
}

template <typename T>
void Vector<T>::resize(size_t newSize)
{
    if (newSize > capacity_m)
    {
        this->reserve(newSize);
    }
    size_m = newSize;
}

template <typename T>
void Vector<T>::sort()
{
    std::sort(data_m, data_m + size_m);
}

template <typename T>
void Vector<T>::reverse()
{
    for (int i = 0; i < size_m / 2; i++)
    {
        T temp = data_m[i];
        data_m[i] = data_m[size_m - i - 1];
        data_m[size_m - i - 1] = temp;
    }
}

template <typename T>
void Vector<T>::swap(int a, int b)
{
    std::swap(data_m[a], data_m[b]);
}

template<typename T>
OwnIterator<T>::OwnIterator(T* p) : p(p)
{

}
template<typename T>
OwnIterator<T>::OwnIterator(const OwnIterator& it) : p(it.p)
{

}
template<typename T>
bool OwnIterator<T>::operator!=(OwnIterator const& other) const
{
    return p != other.p;
}
template<typename T>
bool OwnIterator<T>::operator==(OwnIterator const& other) const
{
    return p == other.p;
}
template<typename T>
T& OwnIterator<T>::operator*() const
{
    return *p;
}
template<typename T>
OwnIterator<T>& OwnIterator<T>::operator++()
{
    ++p;
    return *this;
}
template<typename T>
OwnIterator<T>& OwnIterator<T>::operator--()
{
    --p;
    return *this;
}
template<typename T>
OwnIterator<T> operator - (OwnIterator<T>& i1, OwnIterator<T>& i2)
{
    return OwnIterator<T>(i1.p - i2.p);
}

template<typename T>
OwnReverseIterator<T>::OwnReverseIterator(T* p) : p(p)
{

}
template<typename T>
OwnReverseIterator<T>::OwnReverseIterator(const OwnReverseIterator& it) : p(it.p)
{

}
template<typename T>
bool OwnReverseIterator<T>::operator!=(OwnReverseIterator const& other) const
{
    return p != other.p;
}
template<typename T>
bool OwnReverseIterator<T>::operator==(OwnReverseIterator const& other) const
{
    return p == other.p;
}
template<typename T>
T& OwnReverseIterator<T>::operator*() const
{
    return *p;
}
template<typename T>
OwnReverseIterator<T>& OwnReverseIterator<T>::operator++()
{
    --p;
    return *this;
}

template <typename T>
typename Vector<T>::iterator Vector<T>::begin()
{
    return iterator(data_m);
}
template <typename T>
typename Vector<T>::iterator Vector<T>::end()
{
    return iterator(data_m + size_m);
}
template <typename T>
typename Vector<T>::const_iterator Vector<T>::cbegin() const
{
    return const_iterator(data_m);
}
template <typename T>
typename Vector<T>::const_iterator Vector<T>::cend() const
{
    return const_iterator(data_m + size_m);
}

template <typename T>
typename Vector<T>::reverse_iterator Vector<T>::rbegin()
{
    return reverse_iterator(data_m + size_m - 1);
}
template <typename T>
typename Vector<T>::reverse_iterator Vector<T>::rend()
{
    return reverse_iterator(data_m - 1);
}
template <typename T>
typename Vector<T>::const_reverse_iterator Vector<T>::crbegin() const
{
    return const_reverse_iterator(data_m + size_m - 1);
}
template <typename T>
typename Vector<T>::const_reverse_iterator Vector<T>::crend() const
{
    return const_reverse_iterator(data_m - 1);
}
