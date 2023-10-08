#include "widget.h"
#include <QPushButton>
#include <qmypushbutton.h>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    // 测试析构函数
    QMyPushButton* mybtn = new QMyPushButton;
    mybtn->setParent(this);
    mybtn->move(0, 300);
    mybtn->setText("我的按钮");
}

Widget::~Widget()
{
    qDebug() << "Widget的析构函数";
}

