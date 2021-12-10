#include <iostream>
#include "ManagementBook.h"


void list(bool);

void selector();

Book createBook();

int main() {
    selector();
    return 0;
}

void selector() {
    int op;
    std::cout << "TIPO DE LISTA A UTILIZAR" << std::endl
              << "1. Normal" << std::endl
              << "2. Ordenada" << std::endl;
    std::cin >> op;
    int isSorted = op == 2;
    list(isSorted);

    std::cout << "¿Desea cambiar de lista?" << std::endl << "1. Si" << std::endl << "2. No (SALIR)" << std::endl;
    std::cin >> op;
    op == 1 ? selector() : exit(0);
}

void list(bool isSorted) {
    LinkedList<Book> *books = new LinkedList<Book>();
    LinkedList<Book> *sorted = new LinkedList<Book>();
    ManagementBook *managementBook = new ManagementBook(isSorted ? sorted : books);
    int op = 0;
    Book book;
    do {
        std::cout << "*****MENU PRINCIPAL*****" << std::endl;
        std::cout
                << "1. Comprobar lista vacia" << std::endl
                << "2. Agregar" << std::endl
                << "3. Buscar" << std::endl
                << "4. Eliminar" << std::endl
                << "5. Obtener datos" << std::endl
                << "6. Salir" << std::endl;
        std::cin >> op;
        switch (op) {
            case 1: {
                std::cout << "La lista esta: " << (managementBook->isEmpty()?"vacia":"con objetos") << std::endl;
                break;
            }
            case 2: {
                if (!isSorted) {
                    int op2 = 0;
                    std::cout << "*****AGREGAR*****" << std::endl
                              << "1. Agregar nodo al inicio" << std::endl
                              << "2. Agregar nodo al final" << std::endl
                              << "3. Agregar nodo despues de" << std::endl
                              << "4. Agregar nodo antes de" << std::endl;
                    std::cin >> op2;
                    book = createBook();
                    switch (op2) {
                        case 1:
                            managementBook->addNodeFirst(book);
                            std::cout << "Libro agregado al inicio" << std::endl;
                            break;
                        case 2:
                            managementBook->addNodeLast(book);
                            std::cout << "Libro agregado al final" << std::endl;
                            break;
                        case 3: {
                            std::string id;
                            std::cout << "Id del nodo: " << std::endl;
                            std::cin >> id;
                            if (managementBook->addNodeAfter(id, book)) {
                                std::cout << "Agregado despues del nodo con id " << id << std::endl;
                            } else {
                                std::cout << "Error al añadir nodo" << std::endl;
                            }
                            break;
                        }
                        case 4: {
                            std::string id;
                            std::cout << "Id del nodo: " << std::endl;
                            std::cin >> id;
                            if (managementBook->addNodeBefore(id, book)) {
                                std::cout << "Agregado antes del nodo con id " << id << std::endl;
                            } else {
                                std::cout << "Error al añadir nodo" << std::endl;
                            }
                            break;
                        }
                        default:
                            std::cout << "Opcion no valida" << std::endl;
                            break;
                    }
                } else {
                    book = createBook();
                    managementBook->addNodeSorted(book);
                    std::cout << "Nodo agregado de forma ordenada" << std::endl;
                }
                break;
            }
            case 3: {
                int op2 = 0;
                std::cout << "*****BUSCAR*****" << std::endl
                          << "1. Buscar nodo" << std::endl
                          << "2. Buscar informacion" << std::endl;
                std::cin >> op2;
                std::string id;
                switch (op2) {
                    case 1: {
                        std::cout << "Id del nodo:" << std::endl;
                        std::cin >> id;
                        std::cout << managementBook->findNode(id) << std::endl;
                    }
                        break;
                    case 2:
                        std::cout << "Id del nodo:" << std::endl;
                        std::cin >> id;
                        std::cout << managementBook->findInfo(id);
                        break;
                    default:
                        std::cout << "Opcion no valida" << std::endl;
                        break;
                }
                break;
            }
            case 4: {
                std::string id;
                std::cout << "Id de nodo a eliminar" << std::endl;
                std::cin >> id;
                std::cout << managementBook->deleteNode(id) << std::endl;

            }
                break;
            case 5: {
                int op2 = 0;
                std::cout << "*****OBTENER DATOS*****" << std::endl
                          << "1. Obtener toda la lista" << std::endl
                          << "2. Obtener el tamaño de la lista" << std::endl
                          << "3. Obtener el objeto por id" << std::endl
                          << "4. Obtener el primer nodo" << std::endl
                          << "4. Obtener el ultimo nodo" << std::endl;
                std::cin >> op2;
                switch (op2) {
                    case 1: {
                        int op3;
                        std::cout << "Selecciona como desea obtener a lista:  " << std::endl
                                  << "1. De arriba hacia abajo" << std::endl
                                  << "2. De abajo hacia arriba" << std::endl;
                        std::cin >> op3;
                        if (op3 != 1 and op3 != 2) {
                            std::cout << "Opcion no valida" << std::endl;
                        }
                        std::cout << managementBook->getList(op3) << std::endl;
                        break;
                    }
                    case 2:
                        std::cout << "El tamaño de la lista es " << managementBook->getSize() << std::endl;
                        break;
                    case 3: {
                        int id;
                        std::cout << "Ingrese el indice del objeto que desea obtener: " << std::endl;
                        std::cin >> id;
                        Book *b = managementBook->getObject(id);
                        if (b != NULL) {
                            std::cout << "El objeto es " << b << std::endl;
                        } else {
                            std::cout << "No se ha encontrado el objeto" << std::endl;
                        }
                        break;
                    }
                    case 4: {
                        std::cout << "El primer elemento es" << managementBook->getFirst() << std::endl;
                        break;
                    }
                    case 5: {
                        std::cout << "El ultimo elemento es" << managementBook->getLast() << std::endl;
                        break;
                    }
                }
                break;
            }
            case 6:
                break;
            default:
                std::cout << "Opcion no valida" << std::endl;
                break;
        }
    } while (op != 6);
}

Book createBook() {
    std::string id;
    std::string title;
    std::string author;
    short pages;
    std::cout << "Ingrese id: " << std::endl;
    std::cin >> id;
    std::cout << "Ingrese titulo " << std::endl;
    std::cin >> title;
    std::cout << "Ingrese autor: " << std::endl;
    std::cin >> author;
    std::cout << "Ingrese paginas: " << std::endl;
    std::cin >> pages;
    return Book(id,title, author, pages);
}
