 

![](https://img-blog.csdnimg.cn/6d84adad014b4471997eb51baa8b908f.png)

事件过滤器  
**1、给控件安装过滤器**

**2、重写过滤器事件bool eventFilter(两个参数);**

基于上一个项目：[【QT】事件分发器-CSDN博客](https://blog.csdn.net/Zhouzi_heng/article/details/134149585?spm=1001.2014.3001.5501 "【QT】事件分发器-CSDN博客")

![](https://img-blog.csdnimg.cn/4ded80654bd74a81a875057ee633faf3.png)

我的代码有问题，不能实现事件过滤器的功能，先记录下来

![](https://img-blog.csdnimg.cn/7c6c94106e4f4149afb4aeba8ea3c30a.png)

在头文件中要声明该函数。

```cpp
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
 
```

本文转自 <https://blog.csdn.net/Zhouzi_heng/article/details/134170194?csdn_share_tail=%7B%22type%22%3A%22blog%22%2C%22rType%22%3A%22article%22%2C%22rId%22%3A%22134170194%22%2C%22source%22%3A%22Zhouzi_heng%22%7D>，如有侵权，请联系删除。