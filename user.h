#ifndef USER_H
#define USER_H

#include <QString>

/*
    用户类
*/
class User
{
  public:
    QString userName;  //用户名
    bool operator==(User&) const;
    User& operator=(User&);  //两种重载
    User(QString, QString);
    User();

  private:
    QString passWord;  //密码
};

#endif  // USER_H
