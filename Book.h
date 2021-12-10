//
// Created by Julieth Viviana on 4/12/2021.
//

#ifndef BOOKS_BOOK_H
#define BOOKS_BOOK_H
#include <string>
#include <ostream>

class Book {

public:
    Book();

    Book(const std::string &id, const std::string &title, const std::string &author, short pages);

    const std::string &getId() const;

    void setId(const std::string &id);

    const std::string &getTitle() const;

    void setTitle(const std::string &title);

    const std::string &getAuthor() const;

    void setAuthor(const std::string &author);

    short getPages() const;

    void setPages(short pages);

    friend std::ostream &operator<<(std::ostream &os, const Book &book);

    virtual ~Book();

private:
    std::string id;
    std::string title;
    std::string author;
    short pages;

};

#endif //BOOKS_BOOK_H
