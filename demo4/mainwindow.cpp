#include "mainwindow.h"
#include <QMenuBar>
#include <QToolBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // 重置窗口
    resize(600, 400);

    // 1菜单栏，只有一个
    QMenuBar* bar = menuBar();
    // 将菜单栏设置到窗口中
    this->setMenuBar(bar);

    // 添加菜单
    QMenu* fileMenu =  bar->addMenu("文件");
    QMenu* editMenu =  bar->addMenu("编辑");
    // 添加菜单项
    QAction* newAction = fileMenu->addAction("新建");
    // 添加分割线
    fileMenu->addSeparator();
    QAction* openAction = fileMenu->addAction("打开");
    // 菜单项中有子菜单
    QMenu* subMenu = new QMenu;
    subMenu->addAction("子菜单1");
    subMenu->addAction("子菜单2");
    newAction->setMenu(subMenu);



    // 2 工具栏，可以有多个
    QToolBar* toolBar = new QToolBar(this);
    // 将工具栏放到窗口中
//    addToolBar(toolBar);
    addToolBar(Qt::LeftToolBarArea, toolBar);     // 设置停靠位置
    // 只允许在左右停靠
    toolBar->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);
    // 设置浮动，关掉浮动
    toolBar->setFloatable(false);
    // 设置移动，不能移动
    toolBar->setMovable(false);
    // 工具栏可以添加菜单项。和文件里面的功能一样
    toolBar->addAction(newAction);
    // 添加分割线
    toolBar->addSeparator();
    toolBar->addAction(openAction);
}

MainWindow::~MainWindow()
{
}

