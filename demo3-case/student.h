#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = nullptr);

    // 槽函数。写在public slots下或者public下，或者全局函数，或者lambda表达式。
    // 1 返回值void
    // 2 需要声明，需要实现
    // 3 可以有参数，可以重载
    void treat();

signals:

};

#endif // STUDENT_H
