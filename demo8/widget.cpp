#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QCheckBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 单选按钮，默认选中男
    ui->rBtn_man->setChecked(true);
    this->gender = true;
    // 监听用户选择女

    connect(ui->rBtn_woman, &QRadioButton::clicked, this, [=]() {
        this->gender = false;
    });

    connect(ui->rBtn_man, &QRadioButton::clicked, this, [=]() {
        this->gender = true;
    });

    connect(ui->commit, &QRadioButton::clicked, this, [=]() {
        if (gender == true) {
            qDebug() << "选择的是男性";
        } else {
            qDebug() << "选择的是女性";
        }
    });



//    ui->checkBox_2->setTristate(true);        // 第三种状态，半选中
    connect(ui->checkBox_2, &QCheckBox::stateChanged, this, [=](int state) {
//        str = "价格实惠";
        qDebug() << state;
    });

//    connect(ui->commit, &QRadioButton::clicked, this, [=]() {
//        if (str == "价格实惠") {
//            qDebug() << "选择的是价格实惠";
//        }
//    });





}

Widget::~Widget()
{
    delete ui;
}

