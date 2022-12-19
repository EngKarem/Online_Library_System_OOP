#include"User.cpp"
#include"UserList.cpp"
#include"BookList.cpp"
#include"Book.cpp"
using namespace std;
string separate()
{
    return"========================\n";
}

int main() {
    int user_id = 0,book_id = 0,choice,id,num;
    BookList bookList(10);
    UserList userList(10);
    while(true){
        cout << "Select one of the following choices :\n";
        cout << "1- Book Menu \n" << "2- User Menu \n" << "3- Exit Menu \n";
        cin >> choice;
        if (choice == 1) {
            Book book;
            while (true) {
                cout << "Book Menu\n" << separate();
                cout << "1- Add book\n" << "2- Search for a book\n" << "3- Display books\n"
                     << "4- Get highest rating book\n" << "5- Get all books for a user\n"
                     << "6- Copy book in another list\n" << "7- Exit\n";
                cin >> choice;
                if(choice == 1){
                    cout << separate() << "Enter the number of books you want to add \n" << separate();
                    cin >> num;
                    for(int i = 0;i<num;i++)
                    {
                        cout << separate() << "Enter the book information in this order \n"<<"Title ISBN Category\n"  << separate();
                        cin >> book;
                        cout<<"Enter user id to assign author \n";
                        cin>>id;
                        book.setAuthor(userList.searchUser(id));
                        bookList.booksCount++;
                        book.setId(++book_id);
                        bookList[book_id-1] = book;
                    }
                }
                else if(choice == 2) {
                    while (true) {
                        cout << "1- Search by id\n" << "2- Search by name\n" << "3- Back to books menu\n" << separate();
                        cin >> choice;
                        if(choice == 1){
                            cout << "Enter book id \n" << separate();
                            cin >> id;
                            book = bookList.searchBook(id);
                        }
                        else if(choice == 2)
                        {
                            string name;
                            cout << "Enter book name \n" << separate();
                            cin >> name;
                            book = bookList.searchBook(name);
                        }
                        else if (choice == 3)
                            break;
                        else
                            cout << separate() << "Wrong Input \n" << separate();
                        if(book.getId()!=0) {
                            cout << book;
                            while (true) {
                                cout << "1-Update author\n" << "2-Update title\n" << "3-Update category\n"
                                     << "4-Delete book\n" << "5-Update rate\n" << "6-Return to books menu\n";
                                cin >> choice;
                                if (choice == 1) {
                                    cout << "Enter author id \n";
                                    cin >> id;
                                    for (int i = 0; i < bookList.booksCount; i++)
                                        if (bookList[i].getAuthor() == book.author)
                                            bookList[i].setAuthor(userList.searchUser(id));
                                } else if (choice == 2) {
                                    string title;
                                    cout << "Enter book title \n";
                                    cin >> title;
                                    for (int i = 0; i < bookList.booksCount; i++)
                                        if (bookList[i].getTitle() == book.getTitle())
                                            bookList[i].setTitle(title);
                                } else if (choice == 3) {
                                    string cat;
                                    cout << "Enter book category \n";
                                    cin >> cat;
                                    for (int i = 0; i < bookList.booksCount; i++)
                                        if (bookList[i].getCategory() == book.getCategory())
                                            bookList[i].setCategory(cat);
                                }
                                else if (choice == 4){
                                    bookList.deleteBook(book.getId());
                                }
                                else if (choice == 5)
                                {
                                    cout<<"Enter book rating \n";
                                    int rate;
                                    cin>>rate;
                                    for (int i = 0; i < bookList.booksCount; i++)
                                        if (bookList[i].getId() == book.getId())
                                            bookList[i].rateBook(rate);
                                }
                                else if (choice == 6)
                                    break;
                                else
                                    cout << separate() << "Wrong Input \n" << separate();
                            }
                        }else
                            cout << separate() << "Not Found \n" << separate();
                    }
                }
                else if(choice == 3)
                    cout << bookList;
                else if(choice == 4)
                    cout<<bookList.getTheHighestRatedBook();
                else if(choice == 5)
                {
                    cout<<"Enter user id \n";
                    cin>>id;
                    bookList.getBooksForUser(userList.searchUser(id));
                }
                else if(choice == 6){
                    BookList bookList2(bookList);
                    cout<<"Copied current list("<<bookList.booksCount<<" Books) to new list and switched to it\n";
                }
                else if(choice == 7)
                    break;
                else
                    cout << separate() << "Wrong Input \n" << separate();
            }
        }
        else if (choice == 2) {
            User user;
            while (true) {
                cout << separate() << "User Menu\n";
                cout << separate() << "1- Add user\n" << "2- Search for a user\n" << "3- Display users\n"  << "4- Delete user\n" << "5- Back to main menu\n"  << separate();
                cin >> choice;
                if(choice == 1){
                    cout << separate() << "Enter the number of users you want to add \n" << separate();
                    cin >> num;
                    for(int i = 0;i<num;i++)
                    {
                        cout << separate() << "Enter the user information in this order \n"<<"Name Age Email Password \n"  << separate();
                        cin >> user;
                        user.setId(++user_id);
                        userList.addUser(user);
                    }
                }
                else if(choice == 2) {
                    while (true) {
                        cout << "1- Search by id\n" << "2- Search by name\n" << "3- Back to users menu\n" << separate();
                        cin >> choice;
                        if(choice == 1){
                            cout << "Enter user id \n" << separate();
                            cin >> id;
                            if(userList.searchUser(id).getId() == 0)
                                cout<<"Not Found \n";
                            else
                                cout<<userList.searchUser(id);
                        }
                        else if(choice == 2)
                        {
                            string name;
                            cout << "Enter user name \n" << separate();
                            cin >> name;
                            if(userList.searchUser(name).getId() == 0)
                                cout<<"Not Found \n";
                            else
                                cout<<userList.searchUser(name);
                        }
                        else if (choice == 3)
                            break;
                        else
                            cout << separate() << "Wrong Input \n" << separate();
                    }
                }
                else if(choice == 3)
                    cout << userList;
                else if(choice == 4)
                {
                    cout << "Enter user id \n" << separate();
                    cin >> id;
                    userList.deleteUser(id);
                }
                else if(choice == 5)
                    break;
                else
                    cout << separate() << "Wrong Input \n" << separate();
            }
        }
        else if(choice == 3)
            break;
        else
            cout << separate() << "Wrong Input \n" << separate();
    }
    return 0;
}
