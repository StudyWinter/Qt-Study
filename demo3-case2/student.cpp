#include "student.h"
#include <QDebug>

Student::Student(QObject *parent) : QObject(parent)
{

}

void Student::treat()
{
    qDebug() << "请老师吃饭";
}

void Student::treat(QString foodName)
{
    // QString转成char*
    // 先调用toUtf-8转成QByteArray
    // 再调用data转换成char*
    qDebug() << "请老师吃饭，老师要吃" << foodName;
    qDebug() << "请老师吃饭，老师要吃" << foodName.toUtf8().data();
}
