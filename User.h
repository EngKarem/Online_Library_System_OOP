#ifndef ONLINE_LIBARRY_SYSTEM_USER_H
#define ONLINE_LIBARRY_SYSTEM_USER_H
#include <string>
#include <iostream>

using namespace std;

class User{
private:
    string name ;
    int age;
    string password;
    string email;
public:
    int id{};
    User();
    User(string name, int age, string email, string password);
    User(const User &user);
    void setName(string name);
    string getName() const {return name;}
    void setPassword(string password);
    string getPassword() const {return password;}
    void setEmail(string email);
    string getEmail() const {return email;}
    void setAge(int age);
    int getAge() const {return age;}
    void setId(int i);
    int getId()const {return id;}
    bool operator==(const User& user);
    friend ostream &operator<<(ostream &output, const User &user );
    friend istream &operator>>( istream &input, User &user );
};

#endif //ONLINE_LIBARRY_SYSTEM_USER_H
