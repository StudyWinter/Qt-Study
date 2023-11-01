#include "widget.h"
#include "ui_widget.h"
#include <QTimer>
#include <QTimerEvent>
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //  启动定时器
//    startTimer(1000);           //  单位是ms
    this->m_Id1 = startTimer(1000);

    this->m_Id2 = startTimer(2000);


    // 定时器类
    QTimer* timer = new QTimer(this);
    timer->start(500);          // 单位是ms
    // 监听定时器对象的信号
    connect(timer, &QTimer::timeout, this, [=]() {
        static int num3 = 1;
        ui->label_3->setText(QString::number(num3++));
    });

    // 监听暂停
    connect(ui->pushButton, &QPushButton::clicked, this, [=]() {
        timer->stop();
    });

    // 监听开始
    connect(ui->push, &QPushButton::clicked, this, [=]() {
        timer->start();
    });


}

Widget::~Widget()
{
    delete ui;
}


// 定时器事件
void Widget::timerEvent(QTimerEvent *event) {
    //  判断定时器
    if (event->timerId() == this->m_Id1) {
        static int num = 1;
        ui->label->setText(QString::number(num++));
    } else if (event->timerId() == this->m_Id2){
        static int num2 = 1;
        ui->label_2->setText(QString::number(num2++));
    }

}
