//
// Created by Julieth Viviana on 4/12/2021.
//
#include "LinkedList.h"

template<class T>
LinkedList<T>::LinkedList() {
    head =last = NULL;
}

template<class T>
bool LinkedList<T>::isEmpty() {
    return head == NULL && last == NULL;
}

template<class T>
void LinkedList<T>::addNodeFirst(T info) {
    NodeDouble<T> *newNode = new NodeDouble<T>(info);
    if (isEmpty()) {
        head = newNode;
        last = newNode;
    } else {
        head->previous = newNode;
        newNode->next = head;
        head = newNode;
    }
}

template<class T>
void LinkedList<T>::addNodeLast(T info) {
    NodeDouble<T> *newNode = new NodeDouble<T>(info);
    if (isEmpty()) {
        head = newNode;
        last = newNode;
    } else {
        last->next = newNode;
        newNode->previous = last;
        last = newNode;
    }
}

template<class T>
void LinkedList<T>::addNodeSorted(T info) {
    NodeDouble<T> *nodeNew = new NodeDouble<T>(info);

    if (isEmpty()) {
        head = last = nodeNew;
    } else if (info.getId().compare(head->info.getId()) < 0) {
        addNodeFirst(info);
    } else if (info.getId().compare(last->info.getId()) > 0) {
        addNodeLast(info);
    } else {
        NodeDouble<T> *act = head;
        NodeDouble<T> *ant = NULL;
        while (info.getId().compare(act->info.getId()) > 0) {
            ant = act;
            act = act->next;
        }
        nodeNew->next = act;
        nodeNew->previous = ant;
        ant->next = nodeNew;
        act->previous = nodeNew;
    }
}

template<class T>
void LinkedList<T>::addNodeAfterTo(NodeDouble<T> *after, T info) {
    NodeDouble<T> *nodeNew = new NodeDouble<T>(info);
    if( after == last ){
        addNodeLast( info );
    }else{
        nodeNew->next = after->next;
        nodeNew->previous = after;
        after->next = nodeNew;
        after->next->previous = nodeNew;
    }
}

template<class T>
void LinkedList<T>::addNodeBeforeTo(NodeDouble<T>  *before, T info) {
    NodeDouble<T> *nodeNew = new NodeDouble<T>(info);
    if( before == head ){
        addNodeFirst( info );
    }else{
        nodeNew->next = before;
        nodeNew->previous = before->previous;
        before->previous->next = nodeNew;
        before->previous = nodeNew;
    }

}


template<class T>
std::vector<T> LinkedList<T>::getList(bool sw) {
    std::vector<T> out;

    NodeDouble<T> *aux = sw ? head : last;

    while (aux != NULL) {
        out.push_back(aux->info);
        aux = sw ? aux->next : aux->previous;
    }

    return out;

}

template<class T>
int LinkedList<T>::getSize() {
    int cont = 0;
    NodeDouble<T> *aux = head;
    while (aux != NULL) {
        cont++;
        aux = aux->next;
    }

    return cont;
}

template<class T>
T *LinkedList<T>::getObject(int index) {
    NodeDouble<T> *aux = head;
    int cont = 0;
    while (cont < index) {
        aux = aux->next;
        cont++;
    }

    return &aux->info;
}

template<class T>
NodeDouble<T> *LinkedList<T>::findNode(std::string id) {
    NodeDouble<T>* aux = head;
    while( aux != NULL && aux->info.getId().compare( id ) != 0 ){
        aux = aux->next;
    }

    return aux;
}

template <class T>
T* LinkedList<T>::findInfo(std::string id){
    return &findNode(id)->info;
}
template<class T>
T LinkedList<T>::deleteNode(NodeDouble<T> *node) {
    NodeDouble<T> *aux = head;
    T ret;
    if (node == head) {
        ret = head->info;
        head = head->next;
    } else if (node == last) {
        ret = last->info;
        last = last->previous;
        last->next = NULL;
    } else {
        while (aux != NULL) {
            if (aux == node) {
                ret = aux->info;
                aux->next->previous = aux->previous;
                aux->previous->next = aux->next;
                break;
            }
            aux = aux->next;
        }
    }
    return ret;
}
template<class T>
T LinkedList<T>::getFirst() {
    return head->info;
}

template<class T>
T LinkedList<T>::getLast() {
    return last->info;
}
template<class T>
bool LinkedList<T>::nodeExist(std::string id) {
    return findNode(id) != NULL;
}
template<class T>
LinkedList<T>::~LinkedList() {
    NodeDouble<T> *aux;
    while (head != NULL) {
        aux = head;
        head = head->next;
        delete (aux);
    }
}
