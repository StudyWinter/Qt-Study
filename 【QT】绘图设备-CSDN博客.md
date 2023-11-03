 

**绘图设备是指继承QPainterDevice的子类。**Qt提供了很多这样的类，例如QPixmap、QBitmap、QImage和 QPicture。其中，

1.  QPixmap专门为图像在屏幕上的显示做了优化
2.  QBitmap是QPixmap的一个子类，它的色深限定为1，可以使用 QPixmap的isQBitmap()函数来确定这个QPixmap是不是一个QBitmap。（**只有黑色和白色**）
3.  QImage专门为图像的像素级访问做了优化。
4.  QPicture则可以记录和重现QPainter的各条命令。

新建项目

![](https://img-blog.csdnimg.cn/5fd6cd16fc90454ebe7261f456f39e88.png)

QWidget类继承了QPaintDevice类，所有画家可以画画

![](https://img-blog.csdnimg.cn/42285d561cb14d5b83ada134f466daea.png)**QPixmap做绘图设备**

```cpp
#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
 
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
 
    // QPixmap做绘图设备
    QPixmap pix(300, 300);                                  // 一张300*300的纸
    pix.fill(Qt::white);                                    // 填充
    QPainter painter(&pix);                                 // 向上面纸中画画
    painter.setPen(QPen(Qt::green));                        // 绿色的笔
    painter.drawEllipse(QPoint(150, 150), 100, 100);        // 画圆
    pix.save("D:\\code\\QT\\demo20\\pix.jpg");              // 存储
 
}
 
Widget::~Widget()
{
    delete ui;
}
 
```

效果

![](https://img-blog.csdnimg.cn/722a5b16cb774ba0b920a999597a8c8d.png)

特点：对不同的平台做了显示的优化

**QImage做绘图设备**

![](https://img-blog.csdnimg.cn/291925133b9a489c85e4a2e4de3a9528.png)

```cpp
    // QImage做绘图设备
    QImage img(300, 300, QImage::Format_RGB32);               // 一张300*300的纸
    img.fill(Qt::white);                                      // 填充
    QPainter painter(&img);
    painter.setPen(QPen(Qt::red));
    painter.drawEllipse(QPoint(150, 150), 100, 100);
    img.save("D:\\code\\QT\\demo20\\img.jpg");
```

效果

![](https://img-blog.csdnimg.cn/9352ab6770854b97b24481f51939a101.png)

特点：专门为像素的访问做优化

利用image访问像素点，重写绘图事件

导入资源：[【QT】资源文件导入\_复制其他项目中的文件到qt项目中\_StudyWinter的博客-CSDN博客](https://blog.csdn.net/Zhouzi_heng/article/details/125434467 "【QT】资源文件导入_复制其他项目中的文件到qt项目中_StudyWinter的博客-CSDN博客")

![](https://img-blog.csdnimg.cn/abcbb25729874e069ff30e3ecc785057.png)

头文件中有声明

```cpp
// 利用image访问像素点，重写绘图事件
void Widget::paintEvent(QPaintEvent*)
{
    // 画出来
    QPainter painter(this);                 // 当前窗口
    QImage img;
    img.load(":/Image/Luffy.png");          // 加载
 
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            // 设置像素点
            QRgb val = qRgb(255, 0, 0);
            img.setPixel(i, j, val);
        }
    }
 
    painter.drawImage(0, 0, img);           // 画路飞
}
```

效果

![](https://img-blog.csdnimg.cn/d2ccbfe36e374ea8a3ebfa38a127a44b.png)

也可以读取像素点

```cpp
// 利用image访问像素点，重写绘图事件
void Widget::paintEvent(QPaintEvent*)
{
    // 画出来
    QPainter painter(this);                 // 当前窗口
    QImage img;
    img.load(":/Image/Luffy.png");          // 加载
 
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            // 设置像素点
//            QRgb val = qRgb(255, 0, 0);
            QRgb val = img.pixel(j, i);             // 读像素点
            img.setPixel(i, j, val);
        }
    }
 
    painter.drawImage(0, 0, img);           // 画路飞
}
```

效果

![](https://img-blog.csdnimg.cn/d473a53974e440508ba4dc427de51da0.png)

最后一个需要说明的是QPicture。**这是一个可以记录和重现QPainter命令的绘图设备。** **QPicture将QPainter的命令序列化到一个IO设备，保存为一个平台独立的文件格式。**这种格式有时候会是“元文件(meta- files)”。Qt的这种格式是二进制的，不同于某些本地的元文件，Qt的pictures文件没有内容上的限制，只要是能够被QPainter绘制的元素，不论是字体还是pixmap，或者是变换，都可以保存进一个picture中。

**QPicture****是平台无关的**，因此它可以使用在多种设备之上，比如svg、pdf、ps、打印机或者屏幕。回忆下我们这里所说的QPaintDevice，实际上是说可以有QPainter绘制的对象。QPicture使用系统的分辨率，并且可以调整 QPainter来消除不同设备之间的显示差异。

**如果我们要记录下QPainter的命令，首先要使用QPainter::begin()函数，将QPicture实例作为参数传递进去，以便告诉系统开始记录，记录完毕后使用QPainter::end()命令终止。**

```cpp
#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPicture>
 
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
 
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
 
```

效果

![](https://img-blog.csdnimg.cn/e188922249b34547ac21b118ff8cefda.png)

完整代码

```cpp
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
            QRgb val = qRgb(255, 0, 0);
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
 
```

本文转自 <https://blog.csdn.net/Zhouzi_heng/article/details/134209881?csdn_share_tail=%7B%22type%22%3A%22blog%22%2C%22rType%22%3A%22article%22%2C%22rId%22%3A%22134209881%22%2C%22source%22%3A%22Zhouzi_heng%22%7D>，如有侵权，请联系删除。