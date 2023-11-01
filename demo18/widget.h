#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    // 定时器事件
    void timerEvent(QTimerEvent *event);

    int m_Id1;
    int m_Id2;

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
