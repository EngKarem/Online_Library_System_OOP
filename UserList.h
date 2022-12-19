#ifndef ONLINE_LIBARRY_SYSTEM_USERLIST_H
#define ONLINE_LIBARRY_SYSTEM_USERLIST_H
#include <bits/stdc++.h>
#include "User.h"
using namespace std;

class UserList {
    User* users;
    int capacity;
    int usersCount;
public:
    explicit UserList(int capacity);
    void addUser(const User& user);
    User searchUser(const string& name);
    User searchUser(int id);
    void deleteUser(int id);
    friend ostream &operator<<( ostream &output, UserList &userList );
    ~UserList();
};

#endif //ONLINE_LIBARRY_SYSTEM_USERLIST_H
