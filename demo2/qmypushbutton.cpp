#include "qmypushbutton.h"
#include <QDebug>

QMyPushButton::QMyPushButton(QWidget *parent) : QPushButton(parent)
{

}

QMyPushButton::~QMyPushButton()
{
    qDebug() << "QMyPushButton的析构函数";
}
