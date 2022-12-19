#ifndef ONLINE_LIBARRY_SYSTEM_BOOK_H
#define ONLINE_LIBARRY_SYSTEM_BOOK_H
#include "User.h"
using namespace std;

class Book
{
private:
    string title;
    string isbn;
    string category;
    double averageRating;
public:
    User author;
    static int avgCount;
    int id{};
    Book();
    Book(string title, string isbn, string category, double rate);
    Book(const Book& book);
    void setTitle(string title);
    string getTitle() const {return title;}
    double getRate() const {return averageRating;}
    void setISBN(string isbn);
    string getISBN() const {return isbn;}
    void setId(int id);
    int getId() const {return id;}
    void setCategory(string category);
    string getCategory() {return category;}
    void setAuthor(const User& user);
    User getAuthor() const {return author;}
    void rateBook(double rating);
    bool operator==(const Book& book);
    friend ostream &operator<<(ostream &output, const Book &book );
    friend istream &operator>>( istream &input, Book &book );
};


#endif //ONLINE_LIBARRY_SYSTEM_BOOK_H
