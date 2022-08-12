#ifndef MANAGE_H
#define MANAGE_H

#include <QObject>

#include "user.h"

/*
    用户管理类
*/

class Manage : public QObject
{
    Q_OBJECT
  public:
    explicit Manage(QObject* parent = nullptr);
    ~Manage();
    int addUser(User*);          //添加用户
    bool mateUser(User*) const;  //匹配用户
    QString defunam = "";        //默认用户名
    QString defpwrd = "";        //默认密码

  private:
    User* usr = nullptr;  //现有用户
    int num = 0;          //用户人数
    int size = 0;         //数组容量大小
  signals:

  public slots:
};

#endif  // MANAGE_H
