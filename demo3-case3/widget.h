#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <teacher.h>
#include <student.h>
#include <QPushButton>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    Teacher* teacher = new Teacher;
    Student* student = new Student;
};
#endif // WIDGET_H
