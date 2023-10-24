#include "widget.h"
#include "ui_widget.h"
#include <QMovie>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 利用Qlable显示image
    QPixmap pix;
    pix.load(":/Image/Sunny.jpg");
    ui->lableImage->setPixmap(pix);
    // 设置大小
    ui->lableImage->setFixedSize(pix.width(), pix.height());


    // 显示GIF动图
    QMovie* gif = new QMovie(":/Image/mario.gif");
    ui->labelGif->setMovie(gif);
    gif->start();
    gif->setSpeed(300);         // 设置速度，300%

    connect(gif, &QMovie::frameChanged, this, [=](int frameId) {
        if (frameId == gif->frameCount() - 1) {
            gif->stop();                // 播放完停止
        }
    });


}

Widget::~Widget()
{
    delete ui;
}

