 

新建项目

![](https://img-blog.csdnimg.cn/e4ba89dc4e55412dbdfa5705090782b6.png)

![](https://img-blog.csdnimg.cn/4d8673673a304b35a415dde2a78f6968.png)

第一步：设置头标签

![](https://img-blog.csdnimg.cn/d62adfcb67b7470eaa75fc6deeab626b.png)

第二步：设置item

![](https://img-blog.csdnimg.cn/81d7e62d1a3f47fdaad55a10bb26a8c5.png)

![](https://img-blog.csdnimg.cn/8b0a426df2d5412e9a75bd5f69fc1c20.png)

第三步：创建子item，挂载在顶层item下

![](https://img-blog.csdnimg.cn/1ef5e7096f224c9c991ceb58f7e8cae4.png)

完整代码

    #include "widget.h"#include "ui_widget.h" Widget::Widget(QWidget *parent)    : QWidget(parent)    , ui(new Ui::Widget){    ui->setupUi(this);     // 第一步：设置头标签，匿名对象    ui->treeWidget->setHeaderLabels(QStringList() << "英雄" << "英雄介绍");     // 第二步：设置item    QTreeWidgetItem* power = new QTreeWidgetItem(QStringList() << "力量");    // 添加顶层级别的item    ui->treeWidget->addTopLevelItem(power);     QTreeWidgetItem* agile = new QTreeWidgetItem(QStringList() << "敏捷");    // 添加顶层级别的item    ui->treeWidget->addTopLevelItem(agile);     QTreeWidgetItem* intelligence = new QTreeWidgetItem(QStringList() << "智力");    // 添加顶层级别的item    ui->treeWidget->addTopLevelItem(intelligence);      // 第三步：创建子item，挂载在顶层item    QStringList hero1;    hero1 << "吕布" << "吕布挥斩方天画戟的技能命中敌方英雄后会给武器附魔，持续8秒。";    QTreeWidgetItem* l1 = new QTreeWidgetItem(hero1);    power->addChild(l1);      QStringList hero2;    hero2 << "上官婉儿" << "每第三次普攻获得强化，对一条路径上的敌人额外造成300(+40%法术攻击)法术伤害。";    QTreeWidgetItem* l2 = new QTreeWidgetItem(hero2);    agile->addChild(l2);     QStringList hero3;    hero3 << "诸葛亮" << "技能命中敌方目标会叠加印记，达到5层会召唤5颗法球，自动攻击周围目标造成135（+25%法术攻击）法术伤害。";    QTreeWidgetItem* l3 = new QTreeWidgetItem(hero3);    intelligence->addChild(l3); } Widget::~Widget(){    delete ui;} 

效果

![](https://img-blog.csdnimg.cn/fb6522bf4cf74c079edbfd554b631e6d.png)

本文转自 <https://blog.csdn.net/Zhouzi_heng/article/details/133934943?csdn_share_tail=%7B%22type%22%3A%22blog%22%2C%22rType%22%3A%22article%22%2C%22rId%22%3A%22133934943%22%2C%22source%22%3A%22Zhouzi_heng%22%7D>，如有侵权，请联系删除。