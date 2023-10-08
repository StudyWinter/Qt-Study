#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = nullptr);

    // 学生请老师吃饭
    void treat();
signals:

};

#endif // STUDENT_H
