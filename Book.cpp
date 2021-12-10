//
// Created by Julieth Viviana on 4/12/2021.
//
#include "Book.h"

Book::Book() {

}

Book::Book(const std::string &id, const std::string &title, const std::string &author, short pages) : id(id),
                                                                                                      title(title),
                                                                                                      author(author),
                                                                                                      pages(pages) {}

const std::string &Book::getId() const {
    return id;
}

void Book::setId(const std::string &id) {
    Book::id = id;
}

const std::string &Book::getTitle() const {
    return title;
}

void Book::setTitle(const std::string &title) {
    Book::title = title;
}

const std::string &Book::getAuthor() const {
    return author;
}

void Book::setAuthor(const std::string &author) {
    Book::author = author;
}

short Book::getPages() const {
    return pages;
}

void Book::setPages(short pages) {
    Book::pages = pages;
}

std::ostream &operator<<(std::ostream &os, const Book &book) {
    os << "id: " << book.id << " title: " << book.title << " author: " << book.author << " pages: " << book.pages;
    return os;
}

Book::~Book() {

}
