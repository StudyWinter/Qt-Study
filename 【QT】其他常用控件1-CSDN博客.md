 

新建项目

![](https://img-blog.csdnimg.cn/00321dd933654860bccc1997b217d087.png)

**scrollArea**

**滚动**

![](https://img-blog.csdnimg.cn/cdc85ec061fb4d19a8b80e8e49f49666.png)

**toolBox**

![](https://img-blog.csdnimg.cn/a2b694e31cab4927af23de97618c80e7.png)

插入

![](https://img-blog.csdnimg.cn/dc1ccf2241a749f19e2645e52e5a52e7.png)

**tabWidget**

![](https://img-blog.csdnimg.cn/5c678686f4e5445191b50b0b3979f02e.png)

**stackedWidget**

![](https://img-blog.csdnimg.cn/9ea6c9e161444f39aff4e1b22a46336b.png)

切换

![](https://img-blog.csdnimg.cn/6aa43797cd0f47d6b8fcc6d619effa12.png)

索引是0

![](https://img-blog.csdnimg.cn/9eb71da186ac4fa486eda40c2563c97a.png)

运行后，没有切换按钮，结合pushbutton，加两个Button

![](https://img-blog.csdnimg.cn/f7f292438c2248b7bda0bd8035cfb723.png)

代码

```cpp
#include "widget.h"
#include "ui_widget.h"
 
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
 
    // 设置默认选择第一个
    ui->stackedWidget->setCurrentIndex(0);
    connect(ui->Button1, &QPushButton::clicked, this, [=]() {
        // 设置当前索引
        ui->stackedWidget->setCurrentIndex(0);
    });
 
    connect(ui->Button2, &QPushButton::clicked, this, [=]() {
        // 设置当前索引
        ui->stackedWidget->setCurrentIndex(1);
    });
}
 
Widget::~Widget()
{
    delete ui;
}
 
```

结果

![](https://img-blog.csdnimg.cn/e2ffa1965f7244a2b8ba75d5f09f58b4.png)

**frame**

基本同Widget

**comboBox**

![](https://img-blog.csdnimg.cn/15bc1963441245a187f910fc9e636974.png)

代码

```cpp
    ui->comboBox->addItem("奔驰");
    ui->comboBox->addItem("宝马");
    ui->comboBox->addItem("保时捷");
```

结果

![](https://img-blog.csdnimg.cn/6f8dfa640e95484984adae2546335440.png)

案例，点击按钮，定位到保时捷

代码

```cpp
    ui->comboBox->addItem("奔驰");
    ui->comboBox->addItem("宝马");
    ui->comboBox->addItem("保时捷");
 
    connect(ui->Button3, &QPushButton::clicked, this, [=]() {
//        ui->comboBox->setCurrentIndex(2);
        ui->comboBox->setCurrentText("保时捷");
    });
```

结果

![](https://img-blog.csdnimg.cn/031d9daeabe441c49da57fa0cde29551.png)

本文转自 <https://blog.csdn.net/Zhouzi_heng/article/details/134020488?csdn_share_tail=%7B%22type%22%3A%22blog%22%2C%22rType%22%3A%22article%22%2C%22rId%22%3A%22134020488%22%2C%22source%22%3A%22Zhouzi_heng%22%7D>，如有侵权，请联系删除。