#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 点击新建菜单，弹出对话框，使用信号和槽
//    connect(ui->actionnew, &QAction::triggered, this, [=](){
//        // 错误提示
//        QMessageBox::critical(this, "fail", "错误");
//        qDebug() << "弹出对话框";
//    });


    // 点击新建菜单，弹出对话框，使用信号和槽
//    connect(ui->actionnew, &QAction::triggered, this, [=](){
//        // 普通信息
//        QMessageBox::information(this, "information", "普通信息显示");
//        qDebug() << "弹出对话框";
//    });




    // 点击新建菜单，弹出对话框，使用信号和槽
//    connect(ui->actionnew, &QAction::triggered, this, [=](){
//        // 询问对话框
//        // 参数1：父窗口；参数2：标题；参数3：中间显示文本；参数4：按键类型；参数5：关联回车的按键
////        QMessageBox::question(this, "question", "询问！");         // 缺省
////        QMessageBox::question(this, "question", "询问！", QMessageBox::Save|QMessageBox::Cancel);
////        QMessageBox::question(this, "question", "询问！", QMessageBox::Save|QMessageBox::Cancel, QMessageBox::Cancel);

//        // 捕获
//        if (QMessageBox::Save == QMessageBox::question(this,
//                                                       "question", "询问！",
//                                                       QMessageBox::Save|QMessageBox::Cancel,
//                                                       QMessageBox::Cancel)) {
//            qDebug() << "保存";
//        } else {
//            qDebug() << "取消";
//        }

//    });



    // 点击新建菜单，弹出对话框，使用信号和槽
    connect(ui->actionnew, &QAction::triggered, this, [=](){
        // 警告提示
        QMessageBox::warning(this, "warning", "警告");
    });


}

MainWindow::~MainWindow()
{
    delete ui;
}

