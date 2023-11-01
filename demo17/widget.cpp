#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QMouseEvent>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 利用事件过滤器拦截鼠标按下事件
    // 1给控件安装过滤器
    ui->label->installEventFilter(this);

}



// 2重写过滤器事件
// 过滤器事件
// 参数一：判断控件
// 参数二：判断事件
bool Widget::eventFiltter(QObject* obj, QEvent* ev) {
    // 是label标签 并且 鼠标按下
    if (obj == ui->label) {
        if (ev->type() == QEvent::MouseButtonPress) {
            // 转换一下
            QMouseEvent* e = static_cast<QMouseEvent*>(ev);
            QString str = QString("在事件过滤器中鼠标按下, x = %1, y = %2").arg(e->x()).arg(e->y());
            qDebug() << str;
            // 拦截
            return true;
        }
    }
    return QWidget::eventFilter(obj, ev);
}

Widget::~Widget()
{
    delete ui;
}

