#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // tableWidget的使用
    // 第一步，设置列数
    ui->tableWidget->setColumnCount(3);
    // 第二步，设置水平表头的的标签
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "姓名" << "性别" << "年龄");
    // 第三步，设置行数
    ui->tableWidget->setRowCount(5);

    // 第四部，设置正文
//    ui->tableWidget->setItem(0, 0, new QTableWidgetItem("亚瑟"));

    QStringList nameList;
    nameList << "亚瑟" << "妲己" << "韩信" << "孙悟空" << "孙膑";

    QList<QString> genderList;
    genderList << "男" << "女" << "男" << "男" << "男";

    for (int i = 0; i < 5; i++) {
        int col = 0;
        ui->tableWidget->setItem(i, col++, new QTableWidgetItem(nameList[i]));
        ui->tableWidget->setItem(i, col++, new QTableWidgetItem(genderList.at(i)));
        // int转QString,number静态函数
        ui->tableWidget->setItem(i, col++, new QTableWidgetItem(QString::number(18 + i)));
    }


    // 点击添加赵云
    connect(ui->addButton, &QPushButton::clicked, this, [=]() {
        // 如果有赵云，就不添加
        bool flag = ui->tableWidget->findItems("赵云", Qt::MatchExactly).isEmpty();
        // 存在
        if (flag == false) {
            QMessageBox::warning(this, "警告", "已经有赵云，添加失败");
        } else {
            // 添加一行
            ui->tableWidget->insertRow(0);
            ui->tableWidget->setItem(0, 0, new QTableWidgetItem("赵云"));
            ui->tableWidget->setItem(0, 1, new QTableWidgetItem("男"));
            ui->tableWidget->setItem(0, 2, new QTableWidgetItem(QString::number(25)));
        }
    });


    // 点击删除赵云
    connect(ui->delButton, &QPushButton::clicked, this, [=]() {
        // 如果没有赵云，就不删除
        bool flag = ui->tableWidget->findItems("赵云", Qt::MatchExactly).isEmpty();
        // 不存在，无法删除
        if (flag) {
            QMessageBox::warning(this, "警告", "没有有赵云，删除失败");
        } else {
            // 找到位置，删除，找到第一个
            int row = ui->tableWidget->findItems("赵云", Qt::MatchExactly).first()->row();
            ui->tableWidget->removeRow(row);
        }
    });

}

Widget::~Widget()
{
    delete ui;
}

