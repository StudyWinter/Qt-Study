#include "mylabel.h"
#include <QDebug>
#include <QMouseEvent>

MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{
    // 设置鼠标追踪状态，默认是false
//    this->setMouseTracking(true);
}


// 鼠标进入
void MyLabel::enterEvent(QEvent* ) {
    qDebug() << "鼠标进入";
}


// 鼠标离开
void MyLabel::leaveEvent(QEvent* ) {
    qDebug() << "鼠标离开";
}


// 鼠标移动事件
void MyLabel::mouseMoveEvent(QMouseEvent *ev) {
    // 格式化字符串方式
//    if (ev->buttons() & Qt::LeftButton) {
//        QString str = QString("鼠标移动, x = %1, y = %2").arg(ev->x()).arg(ev->y());
//        qDebug() << str;
//    }


        QString str = QString("鼠标移动, x = %1, y = %2").arg(ev->x()).arg(ev->y());
        qDebug() << str;

}
// 鼠标按下事件
void MyLabel::mousePressEvent(QMouseEvent *ev) {
    // 格式化字符串方式
    // 左键才打印下面的信息
    if (ev->button() == Qt::LeftButton) {
        QString str = QString("鼠标按下, x = %1, y = %2").arg(ev->x()).arg(ev->y());
        qDebug() << str;
    }

}
// 鼠标松开事件
void MyLabel::mouseReleaseEvent(QMouseEvent *ev) {
    // 格式化字符串方式
    if (ev->button() == Qt::LeftButton) {
        QString str = QString("鼠标松开, x = %1, y = %2").arg(ev->x()).arg(ev->y());
        qDebug() << str;
    }
}


// 事件分发器
// 拦截鼠标按下
// QEvent是所有事件的父类
bool MyLabel::event(QEvent* e) {
    if (e->type() == QEvent::MouseButtonPress) {
        // 转换一下
        QMouseEvent* ev = static_cast<QMouseEvent*>(e);
        QString str = QString("在event中鼠标按下, x = %1, y = %2").arg(ev->x()).arg(ev->y());
        qDebug() << str;
        // 拦截
        return true;
    }
    // 其他事件交给父类
    return QLabel::event(e);
}
