#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = nullptr);

    // 学生进行响应，即实槽函数，void，可重载
    void treat();
    void treat(QString foodName);           // 重载

signals:

};

#endif // STUDENT_H
