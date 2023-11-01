 

新建项目

![](https://img-blog.csdnimg.cn/1f8327b287094d709170240849cefa38.png)

![](https://img-blog.csdnimg.cn/90067c2b50c2477db5e1371f216834fe.png)

添加文件

![](https://img-blog.csdnimg.cn/8d2455f9c99947598c5e75ecce7e3512.png)

改头文件

![](https://img-blog.csdnimg.cn/2b57611aa6e24f358f2664da3b3cac39.png)

![](https://img-blog.csdnimg.cn/b0c5a33451674d4dbc32c57b210a4e1f.png)

提升

![](https://img-blog.csdnimg.cn/bb9488b692aa42c083bae0c140b1761d.png)

![](https://img-blog.csdnimg.cn/16183173eaf34b3fba06c37abb5b7dd7.png)

### 1 第一种方式

（1）利用事件 void timerEvent ( QTimerEvent \* ev)  
（2）启动定时器 startTimer( 1000) 毫秒单位  
（3）timerEvent 的返回值是定时器的唯一标示 可以和ev->timerid 做比较

需求：设置两个定时器，时间不一样。

（1）首先是重写timerEvent函数

![](https://img-blog.csdnimg.cn/1d4d97e02ffd45f3a335e1227d6937e4.png)

这里加上UI的label控件

![](https://img-blog.csdnimg.cn/8f2f6580b67d4a5eab3b984d49526121.png)

 重写

```cpp
// 定时器事件
void Widget::timerEvent(QTimerEvent *event) {
    if (event->timerId() == this->m_Id1) {
        static int num = 1;
        ui->label->setText(QString::number(num++));
    } else if (event->timerId() == this->m_Id2){
        static int num2 = 1;
        ui->label_2->setText(QString::number(num2++));
    }
 
}
```

（2）因为是两个定时器，在类中加入成员属性，各表示两个定时器的返回值

![](https://img-blog.csdnimg.cn/633f17eefa06431f8166225eadc5cb46.png)

（3）启动两个定时器

```cpp
// 启动定时器
this->m_Id1 = startTimer(1000);     // 毫秒级
 
this->m_Id2 = startTimer(2000);
```

（4）效果

![](https://img-blog.csdnimg.cn/7a46d18d778941f9882b64fecda879e9.png)

代码

![](https://img-blog.csdnimg.cn/8991b7780078406e99c6e37817aba7be.png)

```cpp
#ifndef WIDGET_H
#define WIDGET_H
 
#include <QWidget>
#include <QTimer>
 
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE
 
class Widget : public QWidget
{
    Q_OBJECT
 
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
 
    // 定时器事件
    void timerEvent(QTimerEvent *event);
 
    int m_Id1;
    int m_Id2;
 
private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
```

![](https://img-blog.csdnimg.cn/262133aab9a24fda8530a1be4e355bbd.png)

```cpp
#include "widget.h"
#include "ui_widget.h"
 
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
 
    //  启动定时器
//    startTimer(1000);           //  单位是ms
    this->m_Id1 = startTimer(1000);
 
    this->m_Id2 = startTimer(2000);
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
```

### **2 第二种方式**

**添加一个label**

![](https://img-blog.csdnimg.cn/0c23136e7be643f5be08c8df6c2447b8.png)

定时器类

```cpp
// 定时器类
QTimer* timer = new QTimer(this);
timer->start(500);       // 单位是毫秒
// 监听定时器对象的信号
connect(timer, &QTimer::timeout, this, [=](){
    static int num3 = 1;
    ui->label_3->setText(QString::number(num3++));
});
```

效果

![](https://img-blog.csdnimg.cn/2c87b7e57e2e4bb1a9205c84c37a62b2.png)

扩充，点击暂停按钮，定时器暂停

添加[QPushbutton](https://so.csdn.net/so/search?q=QPushbutton&spm=1001.2101.3001.7020)按钮，使用connect做连接

```cpp
    // 监听暂停
    connect(ui->pushButton, &QPushButton::clicked, this, [=]() {
        timer->stop();
    });
 
    // 监听开始
    connect(ui->push, &QPushButton::clicked, this, [=]() {
        timer->start();
    });
```

效果

![](https://img-blog.csdnimg.cn/96ccef67d36a4e0b9f7c9f144bea6bb3.png)

本文转自 <https://blog.csdn.net/Zhouzi_heng/article/details/125585136?csdn_share_tail=%7B%22type%22%3A%22blog%22%2C%22rType%22%3A%22article%22%2C%22rId%22%3A%22125585136%22%2C%22source%22%3A%22Zhouzi_heng%22%7D>，如有侵权，请联系删除。