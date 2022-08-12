#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

#include "manage.h"

/*
    登录界面类
*/

namespace Ui
{
    class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

  public:
    Manage* mage;  //用户管理对象
    explicit LoginDialog(Manage& m, QWidget* parent = nullptr);
    ~LoginDialog();

  private slots:
    void on_pushButton_clicked();  //登录按钮

    void on_pushButton_2_clicked();  //注册按钮

    void on_checkBox_stateChanged(int arg1);  //记住数据选项框

  private:
    Ui::LoginDialog* ui;
};

#endif  // LOGINDIALOG_H
