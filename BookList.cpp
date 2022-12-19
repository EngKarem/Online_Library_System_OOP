#include "BookList.h"
BookList::BookList(int capacity) {
    booksCount = 0;
    this-> capacity = capacity;
    books = new Book[capacity];
}
BookList::BookList(const BookList &anotherList) {
    booksCount = anotherList.booksCount;
    capacity = anotherList.capacity;
    books =  new Book [capacity];
    for(int i =0;i<capacity;i++)
        books[i]=anotherList.books[i];
}
Book BookList::searchBook(const string& name) {
    Book book;
    for(int i = 0; i < booksCount; i++)
        if (books[i].getTitle() == name)
            book = books[i];
    return book;
}

Book BookList::searchBook(int id) {
    Book book;
    for(int i = 0; i < booksCount; i++)
        if (books[i].getId() == id)
            book = books[i];

    return book;
}
ostream &operator<<( ostream &out, BookList &booklist ) {
    if(booklist.booksCount == 0)
        cout<<"========================\nNo Books to Display\n";
    else
        for (int i = 0; i < booklist.booksCount; i++)
            out<<booklist.books[i];
    return out;
}

void BookList::deleteBook(int id){
    bool found = false;
    for(int i = 0; i < booksCount; i++)
        if (books[i].getId() == id)
        {
            found = true;
            for(int j = i+1; j < booksCount; j++)
                books[j-1] = books[j];
            booksCount--;
            break;
        }
    if(!found)
        cout<<"Not Found \n";
}
Book BookList::getTheHighestRatedBook(){
    double max = books[0].getRate();
    int id = 0;
    for(int i = 0; i < booksCount; i++)
        if(books[i].getRate() > max)
        {
            max = books[i].getRate();
            id = i;
        }
    return books[id];
}
void BookList::getBooksForUser(const User& user) const{
    for(int i = 0; i < booksCount; i++)
        if(books[i].getAuthor() == user)
            cout<<books[i];
}
Book & BookList::operator[](int pos) {
    if(pos<0 || pos>=booksCount)
        cout<<"Error: out of range";

    return books[pos];
}
BookList::~BookList() {
    if(capacity>0)
        delete [] books;
}