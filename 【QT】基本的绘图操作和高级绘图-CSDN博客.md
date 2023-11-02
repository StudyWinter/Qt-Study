 

#### 基本绘图

新建项目

![](https://img-blog.csdnimg.cn/775033a054804b66b0b7c67c31ad01d8.png)

重新绘图事件

![](https://img-blog.csdnimg.cn/1de22882671e4150a08a0b7145b73b27.png)

**画基本图形**

![](https://img-blog.csdnimg.cn/79ff331a28c24125938188d23dad0ded.png)

```cpp
#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
 
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
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
    painter.drawLine(QPoint(0, 0), QPoint(100, 100));                 // 画线
    painter.drawEllipse(QPoint(100, 100), 50, 50);                    // 画圆(椭圆)
    painter.drawRect(QRect(20, 20, 50, 50));                          // 画矩形
}
```

效果

![](https://img-blog.csdnimg.cn/219b88ff0e674be184f3936a7205832c.png)

**写字**

```cpp
    // 写字
    painter.setFont(QFont("华文彩云", 20));         // 设置字体字号
    painter.drawText(QRect(0, 200, 200, 150), "好好学习，天天向上");
```

效果

![](https://img-blog.csdnimg.cn/64510eba72c447c99e9bcc5ffd61394e.png)

设置画笔颜色、宽度、风格

```cpp
#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
 
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
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
 
    // 指定画笔
    QPen pen(QColor(255, 0, 0));
    // 设置画笔的宽度
    pen.setWidth(3);        // 默认是1
    // 设置画笔风格
    pen.setStyle(Qt::DotLine);
    // 画家使用画笔
    painter.setPen(pen);
 
    painter.drawLine(QPoint(0, 0), QPoint(100, 100));                 // 画线
    painter.drawEllipse(QPoint(100, 100), 50, 50);                    // 画圆(椭圆)
    painter.drawRect(QRect(20, 20, 50, 50));                          // 画矩形
 
 
    // 写字
    painter.setFont(QFont("华文彩云", 20));         // 设置字体字号
    painter.drawText(QRect(0, 200, 200, 150), "好好学习，天天向上");
 
}
```

效果

![](https://img-blog.csdnimg.cn/36266afed8ff453aa38e8a5b8da13008.png)

画刷，可以填充封闭的图案

```cpp
#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
 
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
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
 
    // 指定画笔
    QPen pen(QColor(255, 0, 0));
    // 设置画笔的宽度
    pen.setWidth(3);        // 默认是1
    // 设置画笔风格
    pen.setStyle(Qt::DotLine);
    // 画家使用画笔
    painter.setPen(pen);
 
 
    // 画刷，可以填充封闭的图案
    QBrush brush(Qt::cyan);         // 青色
    // 设置画刷风格
    brush.setStyle(Qt::Dense5Pattern);
    // 画家使用画刷
    painter.setBrush(brush);
 
 
 
    painter.drawLine(QPoint(0, 0), QPoint(100, 100));                 // 画线
    painter.drawEllipse(QPoint(100, 100), 50, 50);                    // 画圆(椭圆)
    painter.drawRect(QRect(20, 20, 50, 50));                          // 画矩形
 
 
    // 写字
    painter.setFont(QFont("华文彩云", 20));         // 设置字体字号
    painter.drawText(QRect(0, 200, 200, 150), "好好学习，天天向上");
 
}
```

效果

![](https://img-blog.csdnimg.cn/9a2b812f4b6c4b1eb42b644d7fb548d7.png)

#### 高级绘图

设置抗锯齿

```cpp
    painter.drawEllipse(QPoint(100, 100), 50, 50);          // 画圆
 
    // 设置抗锯齿
    painter.setRenderHint(QPainter::Antialiasing);
    painter.drawEllipse(QPoint(250, 100), 50, 50);          // 画圆
```

效果

![](https://img-blog.csdnimg.cn/f41633c487774ff99d973b6e47352204.png)

移动画家

```cpp
    painter.drawRect(QRect(20, 20, 50, 50));
    // 移动画家
    painter.translate(100, 0);
    painter.save();                 // 保存
    painter.drawRect(QRect(20, 20, 50, 50));
    painter.translate(100, 0);
    painter.restore();              // 恢复到100处
    painter.drawRect(QRect(20, 20, 50, 50));
```

效果

![](https://img-blog.csdnimg.cn/23581a92a88b4928a432300906782668.png)

画成品图，导入资源：[【QT】资源文件导入\_复制其他项目中的文件到qt项目中\_StudyWinter的博客-CSDN博客](https://blog.csdn.net/Zhouzi_heng/article/details/125434467 "【QT】资源文件导入_复制其他项目中的文件到qt项目中_StudyWinter的博客-CSDN博客")

![](https://img-blog.csdnimg.cn/ab2348745da84dd9b79435b9c06b076a.png)

代码

```cpp
    // 画成品的图案
    QPixmap pix;
    pix.load(":/Image/Luffy.png");
    painter.drawPixmap(0, 0, pix);
```

效果

![](https://img-blog.csdnimg.cn/9ec306f8ddc3485394a8a2550107f0ab.png)

在UI文件中加pushbutton，点击button，图片移动。

加入成员变量记录坐标信息

![](https://img-blog.csdnimg.cn/ed9b838604cf42349ff46d9098af441a.png)

![](https://img-blog.csdnimg.cn/c88931fb4cbb4d73b4b3da3da1cc8442.png)

```cpp
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
}
```

效果

![](https://img-blog.csdnimg.cn/d5242c2b33e841adba5db9052eee8261.png)

图片左边出去，可以从右边回来

![](https://img-blog.csdnimg.cn/aaa226601dee4792ae42fc5f09e7b55e.png)

```cpp
    // 画成品的图案
    QPixmap pix;
    pix.load(":/Image/Luffy.png");
    // 窗口的宽度
    if (posX > this->width()) {
        // 重置
        posX = 0 - pix.width();
    }
    painter.drawPixmap(posX, 0, pix);
```

效果

![](https://img-blog.csdnimg.cn/2e68eaf59c3e497a9cacb10cac555a6f.png)

**图片自动移动，利用定时器**

![](https://img-blog.csdnimg.cn/2c01f98ac40344bb852d6a9415cb0f6d.png)

```cpp
    // 图片自动移动
    QTimer* time = new QTimer(this);
    time->start(10);
    connect(time, &QTimer::timeout, this, [=]() {
        posX++;
        update();
    });
```

所有代码

![](https://img-blog.csdnimg.cn/877c1a7081754d9885fb80bd53274fc5.png)

```cpp
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
 
    // 重写绘图事件
    void paintEvent(QPaintEvent *event);
 
    // 记录坐标
    int posX;
 
private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
```

widget.cpp

```cpp
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
```

本文转自 <https://blog.csdn.net/Zhouzi_heng/article/details/134190574?csdn_share_tail=%7B%22type%22%3A%22blog%22%2C%22rType%22%3A%22article%22%2C%22rId%22%3A%22134190574%22%2C%22source%22%3A%22Zhouzi_heng%22%7D>，如有侵权，请联系删除。