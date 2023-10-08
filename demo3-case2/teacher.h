#ifndef TEACHER_H
#define TEACHER_H

#include <QObject>

class Teacher : public QObject
{
    Q_OBJECT
public:
    explicit Teacher(QObject *parent = nullptr);

signals:
    // 老师发出信号，不实现，可重载，void，位置在signals下
    void hungry();
    void hungey(QString foodName);          // 重载

};

#endif // TEACHER_H
