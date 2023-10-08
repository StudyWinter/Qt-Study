#include "widget.h"
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton* btn = new QPushButton("按钮", this);    // 定义按钮
    btn->move(0, 200);                                  // 移动按钮
    this->setFixedSize(800, 600);                       // 设置窗口大小
    this->setWindowTitle("信号和槽学习");                 // 设置窗口标题
    // 点击按钮，关闭窗口
    // 参数：1信号发送者（指针）， 2发送的信号地址， 3信号的接收者, 4槽函数
    connect(btn, &QPushButton::clicked, this, &Widget::close);
}

Widget::~Widget()
{
}

