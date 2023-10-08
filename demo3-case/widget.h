#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "teacher.h"
#include "student.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    // 老师和学生指针
    Teacher* teacher;
    Student* student;

    // 下课通知函数
    void classIsOver();
};
#endif // WIDGET_H
