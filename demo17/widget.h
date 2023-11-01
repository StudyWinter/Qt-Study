#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    // 过滤器事件
    bool eventFiltter(QObject*, QEvent*);

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
