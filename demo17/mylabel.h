#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = nullptr);

    // 鼠标进入
    void enterEvent(QEvent* );
    // 鼠标离开
    void leaveEvent(QEvent* );



    // 鼠标移动事件
    void mouseMoveEvent(QMouseEvent *ev);
    // 鼠标按下事件
    void mousePressEvent(QMouseEvent *ev);
    // 鼠标松开事件
    void mouseReleaseEvent(QMouseEvent *ev);

    // 事件分发器
    bool event(QEvent* ev);




signals:

};

#endif // MYLABEL_H
