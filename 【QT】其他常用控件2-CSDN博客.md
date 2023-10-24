 

新建项目

![](https://img-blog.csdnimg.cn/5041b895c25544cf8f363321162d9bc8.png)

**lineEdit**

![](https://img-blog.csdnimg.cn/beb3f50245e9448e879c81fc0de89853.png)

什么都不显示（linux password）

![](https://img-blog.csdnimg.cn/b07bf32952274a0bb2d42bb732fdd303.png)

password

![](https://img-blog.csdnimg.cn/8ad197d3c9ac423f9dcf35db0ffc751c.png)

**textEdit和plainTextEdit**

![](https://img-blog.csdnimg.cn/4abf0c463c3e42f1bc0d3e2943a52813.png)

spinBox和doubleSpinBox

![](https://img-blog.csdnimg.cn/c7a61f332f64421fa43c9d2400b0ff84.png)

timeEdit、dateEdit、dateTimeEdit

![](https://img-blog.csdnimg.cn/a0cc74a54d27435d85f2399d89b6cf10.png)

**label**

![](https://img-blog.csdnimg.cn/ce4dba32bd444826a51fdbc01ef4cc4e.png)

显示图案，导入资源：[【QT】资源文件导入\_复制其他项目中的文件到qt项目中\_StudyWinter的博客-CSDN博客](https://blog.csdn.net/Zhouzi_heng/article/details/125434467 "【QT】资源文件导入_复制其他项目中的文件到qt项目中_StudyWinter的博客-CSDN博客")

设置图片，代码

```cpp
#include "widget.h"
#include "ui_widget.h"
 
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
 
    // 利用Qlable显示image
 
    ui->lableImage->setPixmap(QPixmap(":/Image/Sunny.jpg"));
}
 
Widget::~Widget()
{
    delete ui;
}
 
```

结果

![](https://img-blog.csdnimg.cn/edadbae4169440ae9687d3a9eb63ac16.png)

设置固定尺寸，图片和label一样大

```cpp
#include "widget.h"
#include "ui_widget.h"
 
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
 
}
 
Widget::~Widget()
{
    delete ui;
}
 
```

结果

![](https://img-blog.csdnimg.cn/79daeeaca72d4d2bb5a26de7eb1bb70f.png)

label显示动图

![](https://img-blog.csdnimg.cn/8878ae855a114775b5f8d8b8765b1fc1.png)

代码

```cpp
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
 
```

结果

![](https://img-blog.csdnimg.cn/46d2a76bcb4a48c1b119fed415ba0e2c.png)

本文转自 <https://blog.csdn.net/Zhouzi_heng/article/details/134021537?csdn_share_tail=%7B%22type%22%3A%22blog%22%2C%22rType%22%3A%22article%22%2C%22rId%22%3A%22134021537%22%2C%22source%22%3A%22Zhouzi_heng%22%7D>，如有侵权，请联系删除。