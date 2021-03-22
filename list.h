#ifndef LIST_H
#define LIST_H

#include <cstddef>

template <typename T> class list {
public:
    struct Link {
        // Предыдущий элемент
        Link* pre = nullptr;
        T content;
        // Следующий
        Link* suc = nullptr;
    };

    list();
    list(int n);
    // Вставить перед текущим элементом
    void put(T&);
    // Получить текущий элемент
    T& get();

    const T& operator[](int index);
private:
    Link * Head;
//    Link * LastAccesed;
//    int lastIndex;
    Link * Tail;
    size_t size;
};

template <typename T>
list<T>::list()
{
    Head = nullptr;
    Tail = nullptr;
    size = 0;
}

template <typename T>
void list<T>::put(T& element){
    if(Head == nullptr){
        Head = new Link;
        Head->pre = nullptr;
        Head->suc = nullptr;
        Head->content = element;
        Tail = Head;
    } else {
        Link* tmp = new Link;
        Tail->suc = tmp;
        tmp->pre = Tail;
        tmp->suc = nullptr;
        Tail = tmp;
    }
    size++;
}

template <typename T>
T& list<T>::get(){
    return Tail->content;
}

template <typename T>
const T& list<T>::operator[](int index){
//    if(abs(lastIndex - index) * 2 < size){

//    }
    if( 2 * index < size){
        Link * p = Head;
        for(int i = 0; i<index; i++){
            p = p->suc;
        }
        return p->content;
    } else {
        Link * p = Tail;
        for(int i = 0; i<size-index-1; i++){
            p = p->pre;
        }
        return p->content;
    }
}

template <typename T>
list<T>::list(int n){
    size = n;
    Head = new Link;
    Tail = Head;
    for(int i = 0; i<n; i++){
        Link * tmp = new Link;
        Tail->suc = tmp;
        tmp->pre = Tail;
        Tail = tmp;
    }
}

#endif // LIST_H
