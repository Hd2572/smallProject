#include "logindialog.h"

#include <QDebug>

#include "QMessageBox"
#include "registerdialog.h"
#include "ui_logindialog.h"
#include "widget.h"
LoginDialog::LoginDialog(Manage& m, QWidget* parent) : QDialog(parent), ui(new Ui::LoginDialog)
{
    mage = &m;  //传入用户管理对象
    ui->setupUi(this);

    ui->lineEdit->setMaxLength(20);  //设置最长输入20个字符
    ui->lineEdit_2->setMaxLength(20);

    ui->lineEdit->setText(mage->defunam);  //输入框中写入默认数据
    ui->lineEdit_2->setText(mage->defpwrd);
}

LoginDialog::~LoginDialog() { delete ui; }

//登录按钮
void LoginDialog::on_pushButton_clicked()
{
    QString unam = ui->lineEdit->text();  //获取输入栏中输入的用户名和密码
    QString pwrd = ui->lineEdit_2->text();

    if (unam == "" || pwrd == "")  //检测输入合法性
    {
        QMessageBox::warning(this, "Error", "用户名密码不能为空");
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        return;
    }
    else  //比对账户信息
    {
        User tmp(unam, pwrd);
        if (!mage->mateUser(&tmp))
        {
            QMessageBox::warning(this, "Error", "用户名或密码错误");  //信息有误则清除输入框
            ui->lineEdit->clear();
            ui->lineEdit_2->clear();
            return;
        }
    }
    LoginDialog::on_checkBox_stateChanged(0);  //发送一次信号，激活槽函数
    Widget* w = new Widget(*mage);             //账户信息正确则跳转到主窗口
    w->show();
    this->close();
}

//注册按钮
void LoginDialog::on_pushButton_2_clicked()  //跳转输入界面
{
    LoginDialog::on_checkBox_stateChanged(0);  //发送一次信号，激活槽函数
    registerDialog* r = new registerDialog(*mage);
    r->show();
    this->close();
}

//记住用户名密码选项
void LoginDialog::on_checkBox_stateChanged(int arg1)
{
    if (ui->checkBox->isChecked())  //如选中则将此时输入框内数据设为默认数据
    {
        mage->defunam = ui->lineEdit->text();
        mage->defpwrd = ui->lineEdit_2->text();
    }
    else  //否则设为空
    {
        mage->defunam = "";
        mage->defpwrd = "";
    }
}
