#ifndef ITOR_H
#define ITOR_H
#include <cstddef>

template <typename T> class Itor {
public:
// Указатель на первый элемент

    virtual T* first() = 0;
// Указатель на следующий элемент

    virtual T* next() = 0;

    bool operator!=(const Itor<T>& other) const;

    bool operator==(const Itor<T>& other) const;

    Itor& operator++();

    T& operator*() const;
};





#endif // ITOR_H
