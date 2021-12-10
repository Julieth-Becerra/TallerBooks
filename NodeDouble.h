//
// Created by Julieth Viviana on 4/12/2021.
//

#ifndef BOOKS_NODEDOUBLE_H
#define BOOKS_NODEDOUBLE_H
#include <cstdlib>

template <class T> class LinkedList;

template <class T>
class NodeDouble {

    friend class LinkedList<T>;
public:
    NodeDouble(T info) : info(info) {
        next = previous = NULL;
    }

private:
    T info;
    NodeDouble<T>* next;
    NodeDouble<T>* previous;
};

#endif //BOOKS_NODEDOUBLE_H
