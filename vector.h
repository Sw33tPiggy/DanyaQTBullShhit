#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>
#include <algorithm>

template <typename T> class Itor_vector;



template <class T> class vector {
public:
    explicit vector(size_t n); // Доступ по индексу
    T& operator[](size_t index); // Размер
    size_t size();
    void push_back(const T& value);

    Itor_vector<T> begin()
    {
        return Itor_vector<T>(*this);
    }

    Itor_vector<T> end()
    {
        return Itor_vector<T>(*this, size());
    }

private:
    T* array;
    size_t capasity;
    size_t _size;
};

template <class T>
vector<T>::vector(size_t n)
{
    array = new T[n];
    capasity = n;
    _size = 0;
}

template <class T>
void vector<T>::push_back(const T& value){
    if(_size == capasity){

        capasity = capasity * 2;
        if(capasity == 0){
            capasity = 1;
        }
        auto oldArr = array;
        array = new T[capasity];
        std::copy(oldArr, oldArr+_size, array);
    }
    array[_size] = value;
    _size++;
}

template <class T>
size_t vector<T>::size(){
    return _size;
}

template <class T>
T& vector<T>::operator[](size_t index){
    return array[index];
}
#endif // VECTOR_H
