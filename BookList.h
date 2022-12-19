#ifndef ONLINE_LIBARRY_SYSTEM_BOOKLIST_H
#define ONLINE_LIBARRY_SYSTEM_BOOKLIST_H
#include "Book.h"
using namespace std;

class BookList {
    Book* books;
    int capacity;
public:
    int booksCount;
    explicit BookList(int capacity);
    BookList(const BookList& anotherList);
    Book searchBook(const string& name);
    Book searchBook(int id);
    void deleteBook(int id);
    Book getTheHighestRatedBook();
    void getBooksForUser(const User&) const;
    Book & operator [ ] (int position);
    friend ostream &operator<<( ostream &output, BookList &booklist );
    ~BookList();
};

#endif //ONLINE_LIBARRY_SYSTEM_BOOKLIST_H
