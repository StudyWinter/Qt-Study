#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColorDialog>     // 颜色对话框头文件
#include <QFontDialog>
#include <QFileDialog>
#include <QDebug>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 点击新建菜单项，弹出对话框，使用信号和槽，lambda表达式
//    connect(ui->actionnew, &QAction::triggered, this, [=]() {
//        // 颜色对话框
////        QColorDialog::getColor();

//        // 设置颜色
////        QColorDialog::getColor(QColor(255, 0, 0));

//        // 捕获
//        QColor color = QColorDialog::getColor(QColor(255, 0, 0));
//        qDebug() << color.red() << color.blue() << color.green();
//    });


    // 字体对话框
    // 点击新建菜单项，弹出对话框，使用信号和槽，lambda表达式
//    connect(ui->actionnew, &QAction::triggered, this, [=](){
//        //  字体对话框
//        bool ok;
//        QFontDialog::getFont(&ok, QFont("华文彩云", 20));
//        //        // 捕获
//        QFont font = QFontDialog::getFont(&ok, QFont("华文彩云", 20));
//        qDebug() << "字体：" << font.family() << "字号：" << font.pointSize()
//                 << "加粗：" << font.bold() << "倾斜：" << font.italic();
//    });


    // 点击新建菜单项，弹出对话框，使用信号和槽，lambda表达式
    connect(ui->actionnew, &QAction::triggered, this, [=](){

        // 文件对话框
        // 默认在项目的同级目录
        //        QFileDialog::getOpenFileName(this, "打开文件");
        // 修改默认路径
        //        QFileDialog::getOpenFileName(this, "打开文件", "C:\\Users\\xxx\\Desktop\\coding");
        // 过滤格式，只看exe文件
        //        QFileDialog::getOpenFileName(this, "打开文件", "C:\\Users\\xxx\\Desktop\\coding", "(*.exe)");

        // 捕获
        QString str = QFileDialog::getOpenFileName(this, "打开文件", "C:\\Users\\xxx\\Desktop\\coding", "(*.exe)");
        qDebug() << str;

    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

