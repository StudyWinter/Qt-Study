#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 点击新建菜单项，弹出对话框，使用信号和槽
    connect(ui->actionnew, &QAction::triggered, this, [=](){
        // 对话框的分类
        // 模态对话框：不可以对其他窗口进行操作，起到阻塞作用
        // 非模态对话框：可以对其他窗口进行操作，不会阻塞

        // 创建模态对话框
//        QDialog dlg(this);
//        dlg.resize(200, 50);
//        dlg.exec();                 // 这里阻塞
//        qDebug() << "弹出对话框";



        // 创建非模态对话框
        // 在堆区创建
        QDialog* dlg = new QDialog(this);
        dlg->resize(200, 50);
        dlg->show();
        // 设置属性，关闭窗口时，释放对象
        dlg->setAttribute(Qt::WA_DeleteOnClose);
        qDebug() <<"弹出对话框";
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

