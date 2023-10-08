#include "widget.h"


// 需求：需求：下课后，老师会发出饿了的信号，学生进行响应，请老师吃饭。
// 重点是：发送者不需要实现，而接受者需要实现

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    // 挂对象树上，不用写delete
    this->teacher = new Teacher(this);
    this->student = new Student(this);

    // 连接信号和槽
    connect(this->teacher, &Teacher::hungry, this->student, &Student::treat);
    // 调用下课函数
    classIsOver();
}

Widget::~Widget()
{
}

// 下课函数
void Widget::classIsOver() {
    // 触发自定义信号，使用emit关键字
    emit this->teacher->hungry();
}
