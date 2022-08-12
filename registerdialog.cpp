#include "registerdialog.h"

#include <QMessageBox>

#include "logindialog.h"
#include "ui_registerdialog.h"
registerDialog::registerDialog(Manage& m, QWidget* parent) : QDialog(parent), ui(new Ui::registerDialog)
{
    mage = &m;  //用户管理
    ui->setupUi(this);
    ui->lineEdit_2->setMaxLength(20);  //设置输入长度上限
    ui->lineEdit_3->setMaxLength(20);
    ui->lineEdit_4->setMaxLength(20);
}

registerDialog::~registerDialog() { delete ui; }

//注册按钮
void registerDialog::on_pushButton_2_clicked()
{
    QString unam = ui->lineEdit_4->text();  //接收输入框内数据
    QString pwrd = ui->lineEdit_2->text();
    QString pwrd2 = ui->lineEdit_3->text();

    if (pwrd == "" || unam == "")  //检测输入合法性
    {
        QMessageBox::warning(this, "Error", "用户名密码不能为空");
        return;
    }
    if (pwrd != pwrd2)
    {
        QMessageBox::warning(this, "Error", "前后密码不一致");  //密码不一致时清空密码栏
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
        return;
    }

    User tmp(unam, pwrd);         //临时对象
    int f = mage->addUser(&tmp);  //存入新用户

    if (!f)
    {
        QMessageBox::warning(this, "重复注册",
                             "此账户已存在，您可直接登录");  //账户已有时跳转登录界面，并将此账户设为默认
        mage->defunam = ui->lineEdit_4->text();
        mage->defpwrd = ui->lineEdit_2->text();
    }
    else if (f == 1)
    {
        QMessageBox::about(this, "注册成功",
                           "注册成功，即将跳转到登录界面");  //注册成功时跳转登录界面，并将此账户设为默认
        mage->defunam = ui->lineEdit_4->text();
        mage->defpwrd = ui->lineEdit_2->text();
    }
    else if (f == 2)
    {
        QMessageBox::about(this, "用户名冲突", "此用户名已存在，用户名不可相同");  //用户名冲突时报错，清除用户名栏
        ui->lineEdit_4->clear();
        return;
    }

    LoginDialog* l = new LoginDialog(*mage);  //关闭当前窗口转到登录界面
    l->show();
    this->close();
}
//返回登录按钮
void registerDialog::on_pushButton_clicked()  //关闭当前窗口转到登录界面
{
    LoginDialog* l = new LoginDialog(*mage);
    l->show();
    this->close();
}
