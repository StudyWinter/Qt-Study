#ifndef QMYPUSHBUTTON_H
#define QMYPUSHBUTTON_H

#include <QPushButton>

class QMyPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit QMyPushButton(QWidget *parent = nullptr);
    // 添加析构函数
    ~QMyPushButton();

signals:

};

#endif // QMYPUSHBUTTON_H
