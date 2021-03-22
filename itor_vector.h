#ifndef ITOR_VECTOR_H
#define ITOR_VECTOR_H

#include "Itor.h"

template <typename T> class vector;

template <typename T>
class Itor_vector : public Itor<T> {
public:

    vector<T>& v;

    size_t index;

    Itor_vector<T>(vector<T>& vec) : v{vec} {
        index = 0;
    }

    Itor_vector(vector<T>& vec, size_t size) : v{vec}{

        index = size;
    }

    T* first() {
        return &v[0];
    }
// Указатель на следующий элемент

    virtual T* next() {
        return &v[index+1];
    }

    bool operator!=(const Itor_vector<T>& other) const{
        return index != other.index;
    }

    bool operator==(const Itor<T>& other) const{
        return index == other.index;
    }

    Itor_vector<T>& operator++(){
        ++index;
        return *this;
    }

    T& operator*() const{
        return v[index];
    }


};

#endif // ITOR_VECTOR_H
