#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPicture>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // QPixmap做绘图设备     对不同的平台做了显示的优化
//    QPixmap pix(300, 300);                                  // 一张300*300的纸
//    pix.fill(Qt::white);                                    // 填充
//    QPainter painter(&pix);                                 // 向上面纸中画画
//    painter.setPen(QPen(Qt::green));                        // 绿色的笔
//    painter.drawEllipse(QPoint(150, 150), 100, 100);        // 画圆
//    pix.save("D:\\code\\QT\\demo20\\pix.jpg");              // 存储



    // QImage做绘图设备   专门为像素的访问做优化
//    QImage img(300, 300, QImage::Format_RGB32);               // 一张300*300的纸
//    img.fill(Qt::white);                                      // 填充
//    QPainter painter(&img);
//    painter.setPen(QPen(Qt::red));
//    painter.drawEllipse(QPoint(150, 150), 100, 100);
//    img.save("D:\\code\\QT\\demo20\\img.jpg");


    // QPicture做绘图设备  记录和重现画家的绘图指令
    QPicture pic;
    QPainter painter;
    painter.begin(&pic);            // 开始记录

    painter.setPen(QPen(Qt::blue));
    painter.drawEllipse(QPoint(150, 150), 100, 100);

    painter.end();
    pic.save("D:\\code\\QT\\demo20\\pic.zt");           // 自定义格式，打不开

}



// 利用image访问像素点，重写绘图事件
void Widget::paintEvent(QPaintEvent*)
{
//    // 画出来
//    QPainter painter(this);                 // 当前窗口
//    QImage img;
//    img.load(":/Image/Luffy.png");          // 加载

//    for (int i = 0; i < 100; i++) {
//        for (int j = 0; j < 100; j++) {
//            // 设置像素点
////            QRgb val = qRgb(255, 0, 0);
//            QRgb val = img.pixel(j, i);             // 读像素点
//            img.setPixel(i, j, val);
//        }
//    }

//    painter.drawImage(0, 0, img);           // 画路飞


    // 重现绘图指令
    QPicture pic;
    QPainter painter(this);
    pic.load("D:\\code\\QT\\demo20\\pic.zt");       // 加载
    painter.drawPicture(0, 0, pic);                 // 画出来
}

Widget::~Widget()
{
    delete ui;
}

