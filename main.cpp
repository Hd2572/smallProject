#include <QApplication>

#include "logindialog.h"
#include "manage.h"
#include "widget.h"

/*
    实现简单登录注册功能
    2022/8/12
*/

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    Manage* mage = new Manage;  //创建一个用户管理对象
    LoginDialog l(*mage);       //创建一个登录界面
    l.show();
    return a.exec();
}
