 

首先，找到帮助文档，其路径如图：

![](https://img-blog.csdnimg.cn/20210525221754341.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L1pob3V6aV9oZW5n,size_16,color_FFFFFF,t_70)

![](https://img-blog.csdnimg.cn/20210525222232152.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L1pob3V6aV9oZW5n,size_16,color_FFFFFF,t_70)

**在mywidget.cpp中**

```cpp
#include "mywidget.h"
#include <QPushButton>
 
MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)          // 初始化列表，调用父类构造函数 初始化父类
{
    // 创建一个按钮
    QPushButton* btn = new QPushButton;
    //btn->show();          // show是用顶层方式显示
    // 让btn依赖在MyWidght中。设置父窗口，把它放进去
    btn->setParent(this);
 
    // 显示文本
    btn->setText("第一个按钮");
 
    //创建第二个按钮  按照控件的大小创建窗口
    QPushButton* btn2 = new QPushButton("第二个按钮",this);
 
    // 后面出现的会覆盖前面的窗口
    // 移动btn2的按钮
    btn2->move(100,100);
 
    // 按钮也可以指定大小
    btn2->resize(50,50);
 
    // 重置窗口大小 可移动
    resize(600,400);
 
    // 设置固定的大小，即不能移动
    setFixedSize(600,400);
 
    // 设置窗口标题
    setWindowTitle("第一个窗口");
}
 
MyWidget::~MyWidget()
{
}

```

运行结果

![](https://img-blog.csdnimg.cn/20210525222455561.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L1pob3V6aV9oZW5n,size_16,color_FFFFFF,t_70)

快捷键

    // 注释 ctrl + /
    // 运行 ctrl + r
    // 编译 ctrl + b 
    // 查找 ctrl + f
    // 正行的移动 ctrl + shift + 上键/下键 
    // 帮助文档 F1
    // 自动对齐 ctrl + i
    // 同名之间的.h和.cpp切换  F4

本文转自 <https://blog.csdn.net/Zhouzi_heng/article/details/117266011>，如有侵权，请联系删除。