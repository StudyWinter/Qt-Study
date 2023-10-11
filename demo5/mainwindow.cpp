#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 行代码必须在构造函数的最前面

    // 两种路径
//    ui->actionopen->setIcon(QIcon("D:/code/QT/demo5/Image/Luffy.png"));
//    ui->actionnew->setIcon(QIcon("D:\\code\\QT\\demo5\\Image\\LuffyQ.png"));

    // 引入格式：":+前缀名+文件名"
    ui->actionnew->setIcon(QIcon(":/Image/Luffy.png"));
    ui->actionopen->setIcon(QIcon(":/Image/LuffyQ.png"));

}

MainWindow::~MainWindow()
{
    delete ui;
}

