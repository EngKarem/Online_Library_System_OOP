#include <string>
#include <utility>
#include "User.h"
using namespace std;
//consider moving it to avoid unnecessary copies
User::User():age(0),name(" "),password(" "),email(" "),id(0) {}
User::User(string name, int age, string email, string password):age(age),name(std::move(name)),password(std::move(password)),email(std::move(email)){}
User::User(const User & user):User(user.name,user.age,user.email,user.password){}
void User::setId(int i) { id= i;}
void User::setName(string n) { name = std::move(n);}
void User::setAge(int a) { age = a;}
void User::setEmail(string e) { email = std::move(e);}
void User::setPassword(string pass) { password = std::move(pass);}
bool User::operator==(const User& user){
    return name == user.name && email == user.email && age == user.age && password == user.password;
}
ostream &operator<<(ostream &out, const User &user ){
    out<<"=========USER "<<user.id<<" INFO========="
    <<"\nName: "<<user.name
    <<"\nAge: "<<user.age
    <<"\nEmail: "<<user.email<<endl;
    return out;
}
istream &operator>>( istream &in, User &user ){
    in>>user.name>>user.age>>user.email>>user.password;
    return in;
}
