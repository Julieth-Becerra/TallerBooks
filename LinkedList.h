//
// Created by Julieth Viviana on 4/12/2021.
//

#ifndef BOOKS_LINKEDLIST_H
#define BOOKS_LINKEDLIST_H
#include <vector>
#include "NodeDouble.h"
#include <string>

template <class T>
class LinkedList {
public:
    LinkedList();

    bool isEmpty();

    void addNodeFirst(T);

    void addNodeLast(T);

    void addNodeSorted(T info);

    NodeDouble<T>* findNode( std::string );

    T* findInfo( std::string );

    void addNodeAfterTo(NodeDouble<T>*, T);

    void addNodeBeforeTo(NodeDouble<T>*, T);

    std::vector<T> getList(bool);

    int getSize();

    T* getObject(int);

    T deleteNode (NodeDouble<T> *);

    T getFirst ();

    T getLast ();

    bool nodeExist(std::string);

    virtual ~LinkedList();

private:
    NodeDouble<T>* head;
    NodeDouble<T>* last;

};
#endif //BOOKS_LINKEDLIST_H
