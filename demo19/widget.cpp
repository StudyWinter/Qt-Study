#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPushButton>
#include <QTimer>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    posX = 0;

    // 点击移动按钮，图片移动
    connect(ui->pushButton, &QPushButton::clicked, this, [=]() {
        posX += 10;
        // 重新画图，手动调用
        update();       // 自动调用paintEvent

    });


    // 图片自动移动
    QTimer* time = new QTimer(this);
    time->start(10);
    connect(time, &QTimer::timeout, this, [=]() {
        posX++;
        update();
    });
}

Widget::~Widget()
{
    delete ui;
}

// 重写绘图事件
void Widget::paintEvent(QPaintEvent *event)
{
    // 创建画家
    // this表示绘图设备，往当前窗口画画
    QPainter painter(this);

    /***************************************基本绘图**************************************/

//    // 指定画笔
//    QPen pen(QColor(255, 0, 0));
//    // 设置画笔的宽度
//    pen.setWidth(3);        // 默认是1
//    // 设置画笔风格
//    pen.setStyle(Qt::DotLine);
//    // 画家使用画笔
//    painter.setPen(pen);


//    // 画刷，可以填充封闭的图案
//    QBrush brush(Qt::cyan);         // 青色
//    // 设置画刷风格
//    brush.setStyle(Qt::Dense5Pattern);
//    // 画家使用画刷
//    painter.setBrush(brush);

//    painter.drawLine(QPoint(0, 0), QPoint(100, 100));                 // 画线
//    painter.drawEllipse(QPoint(100, 100), 50, 50);                    // 画圆(椭圆)
//    painter.drawRect(QRect(20, 20, 50, 50));                          // 画矩形


//    // 写字
//    painter.setFont(QFont("华文彩云", 20));         // 设置字体字号
//    painter.drawText(QRect(0, 200, 200, 150), "好好学习，天天向上");



    /*****************************************高级绘图****************************************/
//    painter.drawEllipse(QPoint(100, 100), 50, 50);          // 画圆

//    // 设置抗锯齿
//    painter.setRenderHint(QPainter::Antialiasing);
//    painter.drawEllipse(QPoint(250, 100), 50, 50);          // 画圆

//    painter.drawRect(QRect(20, 20, 50, 50));
//    // 移动画家
//    painter.translate(100, 0);
//    painter.save();                 // 保存
//    painter.drawRect(QRect(20, 20, 50, 50));
//    painter.translate(100, 0);
//    painter.restore();              // 恢复到100处
//    painter.drawRect(QRect(20, 20, 50, 50));


    // 画成品的图案
    QPixmap pix;
    pix.load(":/Image/Luffy.png");
    // 窗口的宽度
    if (posX > this->width()) {
        // 重置
        posX = 0 - pix.width();
    }
    painter.drawPixmap(posX, 0, pix);




}
