 

继承Widget

#### **PushButton**

![](https://img-blog.csdnimg.cn/76612893ab4446c391b84df60f99bd30.png)

设置图片，先导入图片资源，见：[【QT】资源文件导入\_复制其他项目中的文件到qt项目中\_StudyWinter的博客-CSDN博客](https://blog.csdn.net/Zhouzi_heng/article/details/125434467 "【QT】资源文件导入_复制其他项目中的文件到qt项目中_StudyWinter的博客-CSDN博客")

在布局中添加图片

![](https://img-blog.csdnimg.cn/491bf2989c6344238942c7597bdfdfdd.png)

![](https://img-blog.csdnimg.cn/86630ae34156431f93841934c21ba691.png)

调整尺寸

![](https://img-blog.csdnimg.cn/2f1c1af26eb04e7b9a92d7a9c78a6fba.png)

#### **toolButton**

显示图片、文本

![](https://img-blog.csdnimg.cn/25375a22b67349fd842b92ec8033e0f6.png)

显示图片（图片和文字都有时，显示图片）

![](https://img-blog.csdnimg.cn/d6a7c7b9b28e474c868a8adb24c556c4.png)

显示文字

![](https://img-blog.csdnimg.cn/577c447535c84dd4a6f3f7c7d8a9a0cb.png)

透明

![](https://img-blog.csdnimg.cn/376b20627e464ad7ad9b6cdfeaf9bd32.png)

#### **RadioButton** 

**单选按钮**

![](https://img-blog.csdnimg.cn/e0f90768b80e4c439d737b1407644922.png)

![](https://img-blog.csdnimg.cn/a8a708b9048849d48b97c0e682f67025.png)

四个中只能选一个，布局

![](https://img-blog.csdnimg.cn/4b0f3c40b5604c23944701dfa6efc19d.png)

默认选择一个，先改名

![](https://img-blog.csdnimg.cn/7d13c3ae396f4aeeae37d43a020c8eaf.png)

执行

![](https://img-blog.csdnimg.cn/cb2777df31054469ba6cd13edb0c70c9.png)

捕获用户的选择

![](https://img-blog.csdnimg.cn/b7d73e8b263d4df883bd07b4fffc7bcf.png)

代码

    #include "widget.h"#include "ui_widget.h"#include <QDebug> Widget::Widget(QWidget *parent)    : QWidget(parent)    , ui(new Ui::Widget){    ui->setupUi(this);     // 单选按钮，默认选中男    ui->rBtn_man->setChecked(true);    // 监听用户选择女    connect(ui->rBtn_woman, &QRadioButton::clicked, this, [=]() {        qDebug() << "选择女";    });} Widget::~Widget(){    delete ui;}

用户最终的选择

![](https://img-blog.csdnimg.cn/7b9b1fb3e13f41ed8f1bf911fed8ae40.png)

加一个性别参数

![](https://img-blog.csdnimg.cn/a9e7417a36c44161b62afbcf71733fa5.png)

代码

    #include "widget.h"#include "ui_widget.h"#include <QDebug> Widget::Widget(QWidget *parent)    : QWidget(parent)    , ui(new Ui::Widget){    ui->setupUi(this);     // 单选按钮，默认选中男    ui->rBtn_man->setChecked(true);    this->gender = true;    // 监听用户选择女     connect(ui->rBtn_woman, &QRadioButton::clicked, this, [=]() {        this->gender = false;    });     connect(ui->rBtn_man, &QRadioButton::clicked, this, [=]() {        this->gender = true;    });     connect(ui->commit, &QRadioButton::clicked, this, [=]() {        if (gender == true) {            qDebug() << "选择的是男性";        } else {            qDebug() << "选择的是女性";        }    });  } Widget::~Widget(){    delete ui;} 

结果

![](https://img-blog.csdnimg.cn/96ca2230bcac41cba5349afd306c90d6.png)

#### **CheckBox** 

**复选按钮**

![](https://img-blog.csdnimg.cn/07de159ab51240419ddfa7732d759bb6.png)

![](https://img-blog.csdnimg.cn/804d50259ea44565b2ecdc9b86ca9320.png)

监听价格实惠是否被选中，

法一：同样加属性

![](https://img-blog.csdnimg.cn/b0a60f0affe24e6ea8b887e7c056d5c2.png)

代码

    #include "widget.h"#include "ui_widget.h"#include <QDebug> Widget::Widget(QWidget *parent)    : QWidget(parent)    , ui(new Ui::Widget){    ui->setupUi(this);     // 单选按钮，默认选中男    ui->rBtn_man->setChecked(true);    this->gender = true;    // 监听用户选择女     connect(ui->rBtn_woman, &QRadioButton::clicked, this, [=]() {        this->gender = false;    });     connect(ui->rBtn_man, &QRadioButton::clicked, this, [=]() {        this->gender = true;    });     connect(ui->commit, &QRadioButton::clicked, this, [=]() {        if (gender == true) {            qDebug() << "选择的是男性";        } else {            qDebug() << "选择的是女性";        }    });        connect(ui->checkBox_2, &QRadioButton::clicked, this, [=]() {        str = "价格实惠";    });     connect(ui->commit, &QRadioButton::clicked, this, [=]() {        if (str == "价格实惠") {            qDebug() << "选择的是价格实惠";        }    });     } Widget::~Widget(){    delete ui;} 

结果

![](https://img-blog.csdnimg.cn/08ece9ea75124fec8f736d2eec1d5190.png)

法二：

使用checkbox特有的信号

![](https://img-blog.csdnimg.cn/4a9f2215a9974fa9b69f50387d4cd52a.png)

选中是2，取消是0

![](https://img-blog.csdnimg.cn/e5432d7a417640d1ac2ebfdb3b311ce5.png)

代码

    #include "widget.h"#include "ui_widget.h"#include <QDebug>#include <QCheckBox> Widget::Widget(QWidget *parent)    : QWidget(parent)    , ui(new Ui::Widget){    ui->setupUi(this);     // 单选按钮，默认选中男    ui->rBtn_man->setChecked(true);    this->gender = true;    // 监听用户选择女     connect(ui->rBtn_woman, &QRadioButton::clicked, this, [=]() {        this->gender = false;    });     connect(ui->rBtn_man, &QRadioButton::clicked, this, [=]() {        this->gender = true;    });     connect(ui->commit, &QRadioButton::clicked, this, [=]() {        if (gender == true) {            qDebug() << "选择的是男性";        } else {            qDebug() << "选择的是女性";        }    });        connect(ui->checkBox_2, &QCheckBox::stateChanged, this, [=](int state) {        qDebug() << state;    });    } Widget::~Widget(){    delete ui;} 

法一：代码：怎么没有1呢，半选中状态

    ui->checkBox_2->setTristate(true);        // 第三种状态，半选中

![](https://img-blog.csdnimg.cn/8cf60e6278d04ae7ad270a77e2173669.png)

法二：√

![](https://img-blog.csdnimg.cn/ca4a72430ed149749c5b7c0eeae15507.png)

最好使用一种（代码或者控件），防止凌乱。

本文转自 <https://blog.csdn.net/Zhouzi_heng/article/details/133913648?csdn_share_tail=%7B%22type%22%3A%22blog%22%2C%22rType%22%3A%22article%22%2C%22rId%22%3A%22133913648%22%2C%22source%22%3A%22Zhouzi_heng%22%7D>，如有侵权，请联系删除。