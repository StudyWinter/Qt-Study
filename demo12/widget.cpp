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


    ui->comboBox->addItem("奔驰");
    ui->comboBox->addItem("宝马");
    ui->comboBox->addItem("保时捷");

    connect(ui->Button3, &QPushButton::clicked, this, [=]() {
//        ui->comboBox->setCurrentIndex(2);
        ui->comboBox->setCurrentText("保时捷");
    });


}

Widget::~Widget()
{
    delete ui;
}

