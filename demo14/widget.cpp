#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 设置一半
    connect(ui->pushButton, &QPushButton::clicked, this, [=]() {
        ui->widget->setVal(50);
    });

    // 获取当前的值
    connect(ui->pushButton_2, &QPushButton::clicked, this, [=]() {
       qDebug() << "当前的值是:" << ui->widget->getVal();
    });


}

Widget::~Widget()
{
    delete ui;
}

