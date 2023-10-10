#include "mainwindow.h"

#include <QStatusBar>
#include <QLabel>
#include <QDockWidget>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(600, 400);

    // 3、状态栏。只能有一个，不用new
//    QStatusBar* sBar = statusBar();
//    // 添加到窗口
//    this->setStatusBar(sBar);
//    // 添加标签。提示的文本和父窗口
//    QLabel* label1 = new QLabel("左侧信息", this);
//    sBar->addWidget(label1);        // 多态接口，法1

//    // 加到右侧信息
//    QLabel* label2 = new QLabel("右侧信息", this);
//    sBar->addPermanentWidget(label2);       // 法2

//    // 中间插入信息
//    QLabel* label3 = new QLabel("中间信息", this);
//    // 按下标0,1插入
//    sBar->insertWidget(1, label3);          // 法3



    // 4 铆接部件/浮动窗口
    QDockWidget* dock = new QDockWidget("浮动窗口", this);
    // 设置到窗口中，添加到下侧，围绕中间， 没有中心部件，就在上侧
    this->addDockWidget(Qt::BottomDockWidgetArea ,dock);

    // 只允许在上侧和下侧
    dock->setAllowedAreas(Qt::BottomDockWidgetArea | Qt::TopDockWidgetArea);


    // 5、中心部件，核心部件，也只能有一个
    QTextEdit* edit = new QTextEdit(this);
    // 添加到窗口
    setCentralWidget(edit);

}

MainWindow::~MainWindow()
{
}

