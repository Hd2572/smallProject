#ifndef REGISTERDIALOG_H
#define REGISTERDIALOG_H

#include <QDialog>

#include "manage.h"

/*
    注册界面类
*/

namespace Ui
{
    class registerDialog;
}

class registerDialog : public QDialog
{
    Q_OBJECT

  public:
    Manage* mage;  //用户管理对象
    explicit registerDialog(Manage& mage, QWidget* parent = nullptr);
    ~registerDialog();

  private slots:
    void on_pushButton_2_clicked();  //注册按钮

    void on_pushButton_clicked();  //返回登录按钮

  private:
    Ui::registerDialog* ui;
};

#endif  // REGISTERDIALOG_H
