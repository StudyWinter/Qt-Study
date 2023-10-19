 

新建项目

![](https://img-blog.csdnimg.cn/b9088f74b55d4ad2a74438f465f9142a.png)

list widget，做了布局

![](https://img-blog.csdnimg.cn/7dba6b3f505543da8fb8a839ca82a4af.png)

![](https://img-blog.csdnimg.cn/07852361ceae4ee0b92364087e5dfbbd.png)

```cpp
#include "widget.h"
#include "ui_widget.h"
 
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // listWidget的使用，基于item
    QListWidgetItem* item = new QListWidgetItem("气吞万里如虎");
    ui->listWidget->addItem(item);
 
}
 
Widget::~Widget()
{
    delete ui;
}
 
```

设置对齐方式，查帮助

![](https://img-blog.csdnimg.cn/74b39f8261b84bfaac4adbf874a41690.png)

![](https://img-blog.csdnimg.cn/18c10f11ac284a42be47f212f6a9496b.png)

```cpp
// 默认在左侧，设置文本对齐方式
item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
```

默认（不居中，不对齐）

```cpp
#include "widget.h"
#include "ui_widget.h"
 
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
 
 
    // listWidget的使用，基于item
 
    // 默认
    // QStringList -> QList<QString> -> list<string>
    QStringList list;
    list.push_back("123456");
    list << "qazwsx" << "plmij";
    ui->listWidget->addItems(list);
}
 
Widget::~Widget()
{
    delete ui;
}
 
```

效果

![](https://img-blog.csdnimg.cn/30a79ac92b264bdbab820fecf2d96e6f.png)

用途：和列表相关的（歌单）

本文转自 <https://blog.csdn.net/Zhouzi_heng/article/details/133934397?csdn_share_tail=%7B%22type%22%3A%22blog%22%2C%22rType%22%3A%22article%22%2C%22rId%22%3A%22133934397%22%2C%22source%22%3A%22Zhouzi_heng%22%7D>，如有侵权，请联系删除。