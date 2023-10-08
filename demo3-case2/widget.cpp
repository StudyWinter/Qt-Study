#include "widget.h"

// 需求是：下课后老师发出饿了的信号，学生请老师吃饭

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

    // 连接信号和槽
//    connect(this->teacher, &Teacher::hungry, this->student, &Student::treat);

    // 连接槽函数
    // 连接有参数的信号和槽
    // 使用函数指针
    void (Teacher::*teacherSignal)(QString) = &Teacher::hungey;
    void (Student::*studentSignal)(QString) = &Student::treat;
    connect(this->teacher, teacherSignal, this->student, studentSignal);

    // 调用下课函数
    this->afterClass();

}

Widget::~Widget()
{
}


// 实现触发函数
void Widget::afterClass()
{
    // 触发自定义信号，使用emit
//    emit this->teacher->hungry();
    emit this->teacher->hungey("宫保鸡丁");
}
