#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include "manage.h"

/*
    主窗口类
*/

namespace Ui
{
    class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

  public:
    Manage* mage;
    explicit Widget(Manage& m, QWidget* parent = nullptr);
    ~Widget();

  private slots:
    void on_pushButton_10_clicked();  //退出登录按钮

  private:
    Ui::Widget* ui;
};

#endif  // WIDGET_H
