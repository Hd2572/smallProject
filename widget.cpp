#include "widget.h"

#include "logindialog.h"
#include "ui_widget.h"

Widget::Widget(Manage& m, QWidget* parent) : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);  //用户管理对象
    mage = &m;
}

Widget::~Widget() { delete ui; }
//退出登录
void Widget::on_pushButton_10_clicked()  //关闭主窗口，打开登录窗口
{
    LoginDialog* l = new LoginDialog(*mage);
    l->show();
    this->close();
}
