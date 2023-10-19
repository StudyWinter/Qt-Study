#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 第一步：设置头标签，匿名对象
    ui->treeWidget->setHeaderLabels(QStringList() << "英雄" << "英雄介绍");

    // 第二步：设置item
    QTreeWidgetItem* power = new QTreeWidgetItem(QStringList() << "力量");
    // 添加顶层级别的item
    ui->treeWidget->addTopLevelItem(power);

    QTreeWidgetItem* agile = new QTreeWidgetItem(QStringList() << "敏捷");
    // 添加顶层级别的item
    ui->treeWidget->addTopLevelItem(agile);

    QTreeWidgetItem* intelligence = new QTreeWidgetItem(QStringList() << "智力");
    // 添加顶层级别的item
    ui->treeWidget->addTopLevelItem(intelligence);


    // 第三步：创建子item，挂载在顶层item
    QStringList hero1;
    hero1 << "吕布" << "吕布挥斩方天画戟的技能命中敌方英雄后会给武器附魔，持续8秒。";
    QTreeWidgetItem* l1 = new QTreeWidgetItem(hero1);
    power->addChild(l1);


    QStringList hero2;
    hero2 << "上官婉儿" << "每第三次普攻获得强化，对一条路径上的敌人额外造成300(+40%法术攻击)法术伤害。";
    QTreeWidgetItem* l2 = new QTreeWidgetItem(hero2);
    agile->addChild(l2);

    QStringList hero3;
    hero3 << "诸葛亮" << "技能命中敌方目标会叠加印记，达到5层会召唤5颗法球，自动攻击周围目标造成135（+25%法术攻击）法术伤害。";
    QTreeWidgetItem* l3 = new QTreeWidgetItem(hero3);
    intelligence->addChild(l3);

}

Widget::~Widget()
{
    delete ui;
}

