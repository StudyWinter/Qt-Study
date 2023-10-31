 

新建项目

![](https://img-blog.csdnimg.cn/c221ae2c597b472fa3019a25dfedd899.png)

加标签控件

![](https://img-blog.csdnimg.cn/1155b276e7f14447ad713ea9355cd4af.png)

当鼠标进去，显示【鼠标进入】，离开时显示【鼠标离开】

将QLable提升成自己的控件，然后再去捕获

添加文件

![](https://img-blog.csdnimg.cn/9e042496fac8430a89f54b3af614246c.png)

改继承的类名

![](https://img-blog.csdnimg.cn/3448fbe9dec145d0aac244773bce8ffa.png)

![](https://img-blog.csdnimg.cn/097bb7dda0cd4425a37b81fa3a997a1c.png)

提升类

![](https://img-blog.csdnimg.cn/ec1be986bb424d0087b784a99d562a6e.png)

同一个父类，可以提升

![](https://img-blog.csdnimg.cn/88685ece9bce4267a695c522a73f7b11.png)

效果

![](https://img-blog.csdnimg.cn/3e6ef426836d46cc8d19352a017ba927.png)

现在代码就和Qlabel对应起来了。

在.h中声明，.cpp中实现

![](https://img-blog.csdnimg.cn/59f5267fa00d439a94a97f8757135006.png)

![](https://img-blog.csdnimg.cn/271fc5284bdd4ed991c38cce57d7cf3b.png)

```cpp
#include "mylabel.h"
#include <QDebug>
 
MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{
 
}
 
 
// 鼠标进入
void MyLabel::enterEvent(QEvent* ) {
    qDebug() << "鼠标进入";
}
 
 
// 鼠标离开
void MyLabel::leaveEvent(QEvent* ) {
    qDebug() << "鼠标离开";
}
```

测试

![](https://img-blog.csdnimg.cn/712de79a0b414aa4ac8b356f4fa81c45.png)

**鼠标的移动、按下、松开事件**

![](https://img-blog.csdnimg.cn/2207bd376d144ee4bf1105346942ba38.png)

![](https://img-blog.csdnimg.cn/fe56cb9fb8c54d03abb33112eeda3eb3.png)

```cpp
    // 鼠标移动事件
    virtual void mouseMoveEvent(QMouseEvent *ev) override;
    // 鼠标按下事件
    virtual void mousePressEvent(QMouseEvent *ev) override;
    // 鼠标松开事件
    virtual void mouseReleaseEvent(QMouseEvent *ev) override;
```

实现

![](https://img-blog.csdnimg.cn/f50f986be218419cba93bb72e9693303.png)

```cpp
#include "mylabel.h"
#include <QDebug>
 
MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{
 
}
 
 
// 鼠标进入
void MyLabel::enterEvent(QEvent* ) {
    qDebug() << "鼠标进入";
}
 
 
// 鼠标离开
void MyLabel::leaveEvent(QEvent* ) {
    qDebug() << "鼠标离开";
}
 
 
// 鼠标移动事件
void MyLabel::mouseMoveEvent(QMouseEvent *ev) {
    qDebug() << "鼠标移动";
}
// 鼠标按下事件
void MyLabel::mousePressEvent(QMouseEvent *ev) {
    qDebug() << "鼠标按下";
}
// 鼠标松开事件
void MyLabel::mouseReleaseEvent(QMouseEvent *ev) {
    qDebug() << "鼠标松开";
}
```

测试

![](https://img-blog.csdnimg.cn/00643c4f99484233911298d4ee288732.png)

坐标信息（**基于控件的坐标系**）

![](https://img-blog.csdnimg.cn/47021982fa034e77964d3fbc0de816a0.png)

```cpp
#include "mylabel.h"
#include <QDebug>
#include <QMouseEvent>
 
MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{
 
}
 
 
// 鼠标进入
void MyLabel::enterEvent(QEvent* ) {
    qDebug() << "鼠标进入";
}
 
 
// 鼠标离开
void MyLabel::leaveEvent(QEvent* ) {
    qDebug() << "鼠标离开";
}
 
 
// 鼠标移动事件
void MyLabel::mouseMoveEvent(QMouseEvent *ev) {
    qDebug() << "鼠标移动" ;
}
// 鼠标按下事件
void MyLabel::mousePressEvent(QMouseEvent *ev) {
    // 格式化字符串方式
    QString str = QString("鼠标按下, x = %1, y = %2").arg(ev->x()).arg(ev->y());
    qDebug() << str;
}
// 鼠标松开事件
void MyLabel::mouseReleaseEvent(QMouseEvent *ev) {
    qDebug() << "鼠标松开";
}
```

效果

![](https://img-blog.csdnimg.cn/c0fe27e330e94fa9bbe7f46ef68a6dbf.png)

其他的类似

![](https://img-blog.csdnimg.cn/3f697181029a4d3c8a05e4cfc0e3c1e7.png)

判断鼠标左右键

![](https://img-blog.csdnimg.cn/a833250c9f764b9f82403bd40c03dc6f.png)

```cpp
// 鼠标按下事件
void MyLabel::mousePressEvent(QMouseEvent *ev) {
    // 格式化字符串方式
    // 左键才打印下面的信息
    if (ev->button() == Qt::LeftButton) {
        QString str = QString("鼠标按下, x = %1, y = %2").arg(ev->x()).arg(ev->y());
        qDebug() << str;
    } else {
        qDebug() << "右键按下";
    }
 
}
```

效果

![](https://img-blog.csdnimg.cn/b1c196fa74304bb4950e05b92d346188.png)

全部改成按左键有输出

```cpp
// 鼠标移动事件
void MyLabel::mouseMoveEvent(QMouseEvent *ev) {
    // 格式化字符串方式
    if (ev->button() == Qt::LeftButton) {
        QString str = QString("鼠标移动, x = %1, y = %2").arg(ev->x()).arg(ev->y());
        qDebug() << str;
    }
}
// 鼠标按下事件
void MyLabel::mousePressEvent(QMouseEvent *ev) {
    // 格式化字符串方式
    // 左键才打印下面的信息
    if (ev->button() == Qt::LeftButton) {
        QString str = QString("鼠标按下, x = %1, y = %2").arg(ev->x()).arg(ev->y());
        qDebug() << str;
    }
 
}
// 鼠标松开事件
void MyLabel::mouseReleaseEvent(QMouseEvent *ev) {
    // 格式化字符串方式
    if (ev->button() == Qt::LeftButton) {
        QString str = QString("鼠标松开, x = %1, y = %2").arg(ev->x()).arg(ev->y());
        qDebug() << str;
    }
}
```

效果

![](https://img-blog.csdnimg.cn/09c8b0fe4c184c1ba78a3348579195ac.png)

移动是没有输出的。按下和松开是一瞬间的，而移动不是一瞬间的，是联合的。使用buttons和&

```cpp
// 鼠标移动事件
void MyLabel::mouseMoveEvent(QMouseEvent *ev) {
    // 格式化字符串方式
    if (ev->buttons() & Qt::LeftButton) {
        QString str = QString("鼠标移动, x = %1, y = %2").arg(ev->x()).arg(ev->y());
        qDebug() << str;
    }
}
```

效果

![](https://img-blog.csdnimg.cn/7d9f673a1175491fbb0012db60ca5fcf.png)

鼠标不点下去，移动。设置鼠标追踪的状态，默认为false，在构造函数中设置

```cpp
#include "mylabel.h"
#include <QDebug>
#include <QMouseEvent>
 
MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{
    // 设置鼠标追踪状态，默认是false
    this->setMouseTracking(true);
}
 
 
// 鼠标进入
void MyLabel::enterEvent(QEvent* ) {
    qDebug() << "鼠标进入";
}
 
 
// 鼠标离开
void MyLabel::leaveEvent(QEvent* ) {
    qDebug() << "鼠标离开";
}
 
 
// 鼠标移动事件
void MyLabel::mouseMoveEvent(QMouseEvent *ev) {
    // 格式化字符串方式
//    if (ev->buttons() & Qt::LeftButton) {
//        QString str = QString("鼠标移动, x = %1, y = %2").arg(ev->x()).arg(ev->y());
//        qDebug() << str;
//    }
 
 
        QString str = QString("鼠标移动, x = %1, y = %2").arg(ev->x()).arg(ev->y());
        qDebug() << str;
 
}
// 鼠标按下事件
void MyLabel::mousePressEvent(QMouseEvent *ev) {
    // 格式化字符串方式
    // 左键才打印下面的信息
    if (ev->button() == Qt::LeftButton) {
        QString str = QString("鼠标按下, x = %1, y = %2").arg(ev->x()).arg(ev->y());
        qDebug() << str;
    }
 
}
// 鼠标松开事件
void MyLabel::mouseReleaseEvent(QMouseEvent *ev) {
    // 格式化字符串方式
    if (ev->button() == Qt::LeftButton) {
        QString str = QString("鼠标松开, x = %1, y = %2").arg(ev->x()).arg(ev->y());
        qDebug() << str;
    }
}
```

效果

![](https://img-blog.csdnimg.cn/47f8690ee546418d9702976e87fcae8b.png)

本文转自 <https://blog.csdn.net/Zhouzi_heng/article/details/134128618?csdn_share_tail=%7B%22type%22%3A%22blog%22%2C%22rType%22%3A%22article%22%2C%22rId%22%3A%22134128618%22%2C%22source%22%3A%22Zhouzi_heng%22%7D>，如有侵权，请联系删除。