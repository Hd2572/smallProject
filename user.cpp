#include "user.h"

#include <iostream>
User::User(QString name, QString number)
{
    this->userName = name;  //初始化
    this->passWord = number;
}
User::User() {}
bool User::operator==(User& u) const { return userName == u.userName && passWord == u.passWord; }  //==
User& User::operator=(User& u)                                                                     //=
{
    userName = u.userName;
    passWord = u.passWord;
    return *this;
}
