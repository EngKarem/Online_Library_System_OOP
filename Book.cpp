#include "Book.h"
#include <utility>
int Book::avgCount = 1;
Book::Book():id(0),title(" "),isbn(" "),category(" "),averageRating(0.0){}
Book::Book(string title, string isbn, string category,double rate):title(std::move(title)),isbn(std::move(isbn)),category(std::move(category)),averageRating(rate){}
Book::Book(const Book &book):Book(book.title,book.isbn,book.category,book.averageRating){}

void Book::setId(int i) { id = i;}
void Book::setISBN(string ibn) {isbn=std::move(ibn);}
void Book::setCategory(string cat) { category=std::move(cat);}
void Book::setTitle(string t) { title=std::move(t);}
void Book::setAuthor(const User& user) {author = user;}
void Book::rateBook(double rating) {
    static double sumAvg= 0;
    if(averageRating>0)
    {
        sumAvg += rating;
        averageRating =(sumAvg)/avgCount;
        avgCount++;
    }
    else
    {
        sumAvg += rating;
        averageRating = rating;
        avgCount++;
    }
}
bool Book::operator==(const Book& book){
    return title == book.title && isbn == book.isbn && category == book.category;
}
ostream & operator<<(ostream& out,const Book &book){
    out<<"=========BOOK "<<book.id<<" INFO========="
    <<"\nTitle: "<<book.title
    <<"\nCategory: "<<book.category
    <<"\nIsbn: "<<book.isbn
    <<"\nRate: "<<book.averageRating
    <<"\n=========="<<"Author Info"<<"==========\n"
    <<"Name: "<<book.author.getName()<<"\n"
    <<"Age: "<<book.author.getAge()<<"\n"
    <<"ID: "<<book.author.getId()<<"\n"
    <<"Email: "<<book.author.getEmail()<<"\n";
    return out;
}
istream &operator>>( istream &in, Book &book ){
    in>>book.title>>book.isbn>>book.category;
    return in;
}
