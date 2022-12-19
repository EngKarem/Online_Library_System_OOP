#include "UserList.h"
UserList::UserList(int capacity) {
    usersCount = 0;
    this->capacity = capacity;
    users = new User[capacity];
}
void UserList::addUser(const User& user){
    users[usersCount] = user;
    usersCount++;
}

User UserList::searchUser(const string& name){
    User user;
    for(int i = 0; i < usersCount; i++)
        if(users[i].getName()== name){
            user = users[i];
            break;
        }
    return user;
}

User UserList::searchUser(int id){
    User user;
    for(int i = 0; i < usersCount; i++)
        if(users[i].getId()== id){
            user = users[i];
            break;
        }
    return user;
}
void UserList::deleteUser(int id){
    bool found = false;
    for(int i = 0; i < usersCount; i++){
        if(users[i].getId()== id)
        {
            found = true;
            for(int j = i+1; j < usersCount; j++)
                users[j-1] = users[j];
            usersCount--;
            break;
        }
    }
    if (!found)
        cout<<"Not Found \n";
}
ostream &operator<<( ostream &out, UserList &userList ){
    if(userList.usersCount == 0)
        cout<<"========================\nNo Users to Display\n";
    else
        for(int i = 0; i < userList.usersCount; i++)
            out<<userList.users[i];
    return out;
}

UserList::~UserList() {
    if(capacity>0)
        delete [] users;
}


