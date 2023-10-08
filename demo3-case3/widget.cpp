#include "widget.h"

// 需求，按下按钮，请老师吃饭

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    // 生成按钮
    QPushButton* btn = new QPushButton;
    btn->resize(50, 50);
    btn->setParent(this);
    btn->setText("下课");

    void (Teacher::* teacherSignal)() = &Teacher::hungry;
    void (Student::* studentSignal)() = &Student::treat;

    // 信号连接信号，顺序无所谓
    connect(btn, &QPushButton::clicked, this->teacher, teacherSignal);

    // 连接槽函数
    connect(this->teacher, teacherSignal, this->student, studentSignal);

//    // 信号连接信号
//    connect(btn, &QPushButton::clicked, this->teacher, teacherSignal);

    // 1 信号连接信号
    // 2 一个信号可以连接多个槽函数
    // 3 多个信号可以连接一个槽函数
    // 4 信号和槽的参数类型必须一一对应；
    // 5 信号的参数个数可以多于槽函数的个数，反之不可以；相同参数的参数类型要一一对应；
    // 6 可以利用disconnect断开信号和槽。
}

Widget::~Widget()
{
}

