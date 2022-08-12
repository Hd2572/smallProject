#include "manage.h"

Manage::Manage(QObject* parent) : QObject(parent)
{
    usr = new User[5];  //初始指针分配5个空间
    size += 5;
}

//添加用户
int Manage::addUser(User* u)
{
    if (mateUser(u))  //已有账户，返回0
        return 0;

    for (int i = 0; i < num; i++)  //用户名冲突，返回2
    {
        if (usr[i].userName == (*u).userName)
        {
            return 2;
        }
    }

    if (num + 1 >= size)  //检查容量大小，不足则重新分配
    {
        User* t = new User[size + 5];
        for (int i = 0; i < num; i++) { t[i] = usr[i]; }
        delete[] usr;
        usr = new User[size + 5];
        for (int i = 0; i < num; i++) { usr[i] = t[i]; }
        delete[] t;
        size += 5;
    }

    User* tmp = new User(*u);  //存入新用户，堆中创建防止丢失
    usr[num++] = *tmp;
    return 1;
}

bool Manage::mateUser(User* u) const  //匹配已有用户信息
{
    for (int i = 0; i < num; i++)
    {
        if (usr[i] == *u)
        {
            return 1;
        }
    }
    return 0;
}

Manage::~Manage()  //析构释放数组
{
    if (usr != nullptr)
    {
        delete[] usr;
    }
    num = 0;
    usr = nullptr;
}
