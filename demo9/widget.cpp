#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);


    // listWidget的使用，基于item
//    QListWidgetItem* item = new QListWidgetItem("气吞万里如虎");
//    ui->listWidget->addItem(item);
//    // 默认在左侧，设置文本对齐方式
//    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);


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

