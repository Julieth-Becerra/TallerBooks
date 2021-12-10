//
// Created by Julieth Viviana on 8/12/2021.
//

#ifndef BOOKS_MANAGEMENTBOOK_H
#define BOOKS_MANAGEMENTBOOK_H

#include "NodeDouble.h"
#include "LinkedList.cpp"
#include "Book.h"

class ManagementBook{
public:

    ManagementBook(LinkedList<Book>*);

    bool isEmpty();

    void addNodeFirst(Book);

    void addNodeLast(Book);

    bool addNodeSorted(Book);

    bool addNodeAfter(std::string id, Book);

    bool addNodeBefore(std::string id, Book);

    std::string findNode(std::string);

    std::string findInfo(std::string);

    std::string deleteNode(std::string);

    std::string getList(bool);

    int getSize();

    Book* getObject(int);

    std::string getFirst();

    std::string getLast();

    std::string convertToString(Book);

private:
    LinkedList<Book>* list;
};


#endif //BOOKS_MANAGEMENTBOOK_H
