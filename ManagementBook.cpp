//
// Created by Julieth Viviana on 8/12/2021.
//
#include <sstream>
#include "ManagementBook.h"

ManagementBook::ManagementBook(LinkedList<Book> *list) {
    ManagementBook::list = list;
}

bool ManagementBook::isEmpty() {
    return ManagementBook::list->isEmpty();
}

void ManagementBook::addNodeFirst(Book book) {
    list->addNodeFirst(book);
}
void ManagementBook::addNodeLast(Book book) {
    list->addNodeFirst(book);
}

bool ManagementBook::addNodeSorted(Book mon) {
    if (list->nodeExist(mon.getId())) {
        return false;
    }
    list->addNodeSorted(mon);
    return true;
}

bool ManagementBook::addNodeAfter(std::string after, Book info) {
    if (list->nodeExist(after)) {
        list->addNodeAfterTo(list->findNode(after), info);
        return true;
    }
    return false;
}

bool ManagementBook::addNodeBefore(std::string before, Book info) {
    if (list->nodeExist(before)) {
        list->addNodeBeforeTo(list->findNode(before), info);
        return true;
    }
    return false;
}

std::string ManagementBook::findNode(std::string id) {
    if (list->nodeExist(id)) {
        return "Se ha encontrado el nodo: " + findInfo(id);
    }
    return "Nodo no encontrado";
}

std::string ManagementBook::findInfo(std::string id) {
    return (list->findInfo(id)->getId().compare("")) == 0 ? "Informacion no encontrada" : convertToString(
            *list->findInfo(id));
}

std::string ManagementBook::deleteNode(std::string id) {
    std::string retu = "Nodo no encontrado";
    Book ret;
    if (list->nodeExist(id)) {
        ret = list->deleteNode(list->findNode(id));
        retu = "Se ha eliminado: " + convertToString(ret);
    }
    return retu;
}

std::string ManagementBook::getList(bool dir) {
    std::string ret;
    if (list->isEmpty()) {
        return "La lista esta vacia";
    } else {
        for (const auto &item : list->getList(dir)) {
            ret += convertToString(item) + "\n";
        }
    }
    return ret;
}

int ManagementBook::getSize() {
    return list->getSize();
}

Book *ManagementBook::getObject(int index) {
    return list->getObject(index);
}

std::string ManagementBook::getFirst() {
    return convertToString(list->getFirst());
}

std::string ManagementBook::getLast() {
    return convertToString(list->getLast());
}

std::string ManagementBook::convertToString(Book book) {
    std::ostringstream ret;
    ret << book;
    return ret.str();
}

