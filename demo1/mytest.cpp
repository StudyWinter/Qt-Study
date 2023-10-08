#include "mytest.h"
#include <QPushButton>

MyTest::MyTest(QWidget *parent)
    : QWidget(parent)
{
    // 创建一个按钮
    QPushButton* btn = new QPushButton;
//    btn->show();                // 顶层显示方式，和目前的窗口是分开的，不建议使用

    // 让btn依赖在MyTest中，设置父窗口，把它放进去
    btn->setParent(this);

    // 显示文本
    btn->setText("第一个按钮");

    // 创建第二个按钮
    QPushButton* btn2 = new QPushButton("第二个窗口", this);

    // 后面出现的会覆盖前面的
    // 移动第二个按钮
    btn2->move(100, 100);
    // 按钮也可以指定大小
    btn2->resize(150, 50);

    // 重置窗口大小 可移动
    resize(600,400);

    // 设置固定的大小，即不能移动
    setFixedSize(600,400);

    // 设置窗口标题
    setWindowTitle("第一个窗口");


}

MyTest::~MyTest()
{
}

