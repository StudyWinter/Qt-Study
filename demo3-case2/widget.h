#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <teacher.h>
#include <student.h>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    // 加入对象树
    Teacher* teacher = new Teacher(this);
    Student* student = new Student(this);

    // 下课函数，即触发函数
    void afterClass();

};
#endif // WIDGET_H
