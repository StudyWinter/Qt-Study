 

[QMainWindow](https://so.csdn.net/so/search?q=QMainWindow&spm=1001.2101.3001.7020)是一个为用户提供主窗口程序的类，**包含一个菜单栏（menu bar）、多个工具栏(tool bars)、多个锚接部件(dock widgets)、一个状态栏(status bar)及一个中心部件(central widget)，**是许多应用程序的基础，如文本编辑器，图片编辑器等。

![](https://img-blog.csdnimg.cn/62274ba22baf4cad8382b8d6cf2360a3.png)

### 1 菜单栏

一个主窗口最多只有一个菜单栏。位于主窗口顶部、主窗口标题栏下面。

**（1）创建菜单栏**

通过QMainWindow类的menubar（）函数获取主窗口菜单栏指针

函数原型

```cpp
QMenuBar* menuBar() const；
```

创建

```cpp
 // 菜单栏，最多只能有一个
 QMenuBar* bar = menuBar();
```

（2）将菜单项设置到窗口中

```cpp
// 将菜单栏设置到窗口中
this->setMenuBar(bar);
```

这是运行还是没有显示，因为菜单栏没有内容。

（3）添加菜单

```cpp
QAction* addMenu(QMenu * menu);
QMenu* addMenu(const QString & title);
QMenu* addMenu(const QIcon & icon, const QString & title);
```

目前只有第二个熟悉

```cpp
QMenu* fileMenu = bar->addMenu("文件");
QMenu* editMenu = bar->addMenu("编辑");
```

查看效果

![](https://img-blog.csdnimg.cn/fadf883fdbbf45478bdd42b2dd288834.png)

（4）创建菜单项

函数原型

```cpp
QAction* activeAction() const;
 
QAction* addAction(const QString & text);
 
QAction* addAction(const QIcon & icon, const QString & text);
 
QAction* addAction(const QString & text, const QObject * receiver,
                   const char * member, const QKeySequence & shortcut = 0);
 
QAction* addAction(const QIcon & icon, const QString & text, 
                   const QObject * receiver, const char * member, 
                   const QKeySequence & shortcut = 0);
```

 Qt 并没有专门的菜单项类，只是使用一个[QAction](https://so.csdn.net/so/search?q=QAction&spm=1001.2101.3001.7020)类，抽象出公共的动作。当我们把QAction对象添加到菜单，就显示成一个菜单项，添加到工具栏，就显示成一个工具按钮。用户可以通过点击菜单项、点击工具栏按钮、点击快捷键来激活这个动作。

```cpp
// 菜单项
QAction* newAction = fileMenu->addAction("新建");
// 添加分割线
fileMenu->addSeparator();
QAction* openAction = fileMenu->addAction("打开");
```

![](https://img-blog.csdnimg.cn/ff918ff269a44c4d8a18fac0fc7f9129.png)

 还可以添加子菜单

```cpp
// 菜单项中有子菜单
QMenu* subMenu = new QMenu;
subMenu->addAction("子菜单1");
subMenu->addAction("子菜单2");
newAction->setMenu(subMenu);
```

完整代码

```cpp
#include "mainwindow.h"
#include <QMenuBar>
 
 
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // 重置窗口尺寸
    resize(600, 400);
 
    // 1 菜单栏，最多只能有一个
    QMenuBar* bar = menuBar();
    // 将菜单栏设置到窗口中
    this->setMenuBar(bar);
    // 添加菜单
    QMenu* fileMenu = bar->addMenu("文件");
    QMenu* editMenu = bar->addMenu("编辑");
 
    // 菜单项
    QAction* newAction = fileMenu->addAction("新建");
    // 添加分割线
    fileMenu->addSeparator();
    QAction* openAction = fileMenu->addAction("打开");
 
    // 菜单项中有子菜单
    QMenu* subMenu = new QMenu;
    subMenu->addAction("子菜单1");
    subMenu->addAction("子菜单2");
    newAction->setMenu(subMenu);
}
```

效果

![](https://img-blog.csdnimg.cn/daa92221fa27455a93ceb8f1674a165f.png)

步骤：

（1）新建菜单栏，只能有一个；

（2）将菜单栏设置到窗口中；

（3）添加菜单；

（4）添加菜单项（添加分割线）；

（5）菜单中有子菜单，添加子菜单。

### 2 工具栏

主窗口的工具栏上可以有多个工具条，通常采用一个菜单对应一个工具条的的方式，也可根据需要进行工具条的划分。

（1）创建工具栏

```cpp
// 工具栏，可以有多个
QToolBar* toolBar = new QToolBar(this);
```

（2）将工具栏放到窗口中

```cpp
// 将工具栏放到窗口中
//    addToolBar(toolBar);                   // 默认停靠在上侧
addToolBar(Qt::LeftToolBarArea, toolBar);     // 设置停靠位置
// 只允许在左右停靠
toolBar->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);
// 设置浮动，关掉浮动
toolBar->setFloatable(false);
// 设置移动，不能移动
toolBar->setMovable(false);
```

停靠位置查看

![](https://img-blog.csdnimg.cn/350f7a82b7e84a85bf157204ce381542.png)

```cpp
Qt::LeftToolBarArea		// 停靠在左侧
Qt::RightToolBarArea	// 停靠在右侧
Qt::TopToolBarArea		// 停靠在顶部
Qt::BottomToolBarArea   // 停靠在底部
Qt::AllToolBarAreas		// 以上四个位置都可停靠
```

效果，工具栏在左侧

![](https://img-blog.csdnimg.cn/bed130dce49c45cfbecebc8ce294a26c.png)

 （3）工具栏可以添加菜单项。和文件里面的功能一样

```cpp
toolBar->addAction(newAction);
// 添加分割线
toolBar->addSeparator();
toolBar->addAction(openAction);
```

完整代码

```cpp
#include "mainwindow.h"
#include <QMenuBar>
#include <QToolBar>
 
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // 重置窗口尺寸
    resize(600, 400);
 
    // 1 菜单栏，最多只能有一个
    QMenuBar* bar = menuBar();
    // 将菜单栏设置到窗口中
    this->setMenuBar(bar);
    // 添加菜单
    QMenu* fileMenu = bar->addMenu("文件");
    QMenu* editMenu = bar->addMenu("编辑");
 
    // 菜单项
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
```

效果

![](https://img-blog.csdnimg.cn/534195af8a8447a4877ff76df647a079.png)

步骤：

（1）新建工具栏，可以有多个；

（2）将工具栏放到窗口中；

（3）工具栏可以添加菜单项。和文件里面的功能一样。

### 3 状态栏

派生自QWidget类，使用方法与QWidget类似，QStatusBar类常用成员函数：

状态栏也只能最多有一个。

word的下面的信息就是状态栏

![](https://img-blog.csdnimg.cn/d7b64cf3c46e42e7a6999d0289acb3aa.png)

 （1）添加状态栏（头文件QStatusBar）

```cpp
QStatusBar* sBar = statusBar();
```

注意：这里不用于new

（2）将状态栏添加到窗口

```cpp
// 添加到窗口
this->setStatusBar(sBar);
```

（3）给状态栏添加信息

状态栏一般是提示信息（头文件QLabel）

```cpp
// 添加标签。提示的文本和父窗口
QLabel* label1 = new QLabel("左侧信息", this);
sBar->addWidget(label1);
```

效果

![](https://img-blog.csdnimg.cn/3bacc40b9cee4737a9faac28f635f5cd.png)

也可以在右测添加信息、也可以插入信息

```cpp
// 加到右侧信息
QLabel* label2 = new QLabel("右侧信息", this);
sBar->addPermanentWidget(label2);
 
// 中间插入信息
QLabel* label3 = new QLabel("中间信息", this);
sBar->insertWidget(1, label3);
```

![](https://img-blog.csdnimg.cn/32f15d1e171a41a68bcf9cf53731fe07.png)

完整代码

```cpp
#include "mainwindow.h"
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QLabel>
 
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
   
 
    // 3、状态栏。只能有一个，不用new
   QStatusBar* sBar = statusBar();
   // 添加到窗口
   this->setStatusBar(sBar);
   // 添加标签。提示的文本和父窗口
   QLabel* label1 = new QLabel("左侧信息", this);
   sBar->addWidget(label1);
 
   // 加到右侧信息
   QLabel* label2 = new QLabel("右侧信息", this);
   sBar->addPermanentWidget(label2);
 
   // 中间插入信息
   QLabel* label3 = new QLabel("中间信息", this);
   sBar->insertWidget(1, label3);
}
```

### 4 铆接部件和核心部件

铆接部件 QDockWidget，也称浮动窗口，可以有多个。

头文件QDockWidget

添加铆接部件

```cpp
QDockWidget* dock = new QDockWidget("浮动窗口", this);
```

设置到窗口中

```cpp
// 设置到窗口中，添加到下侧，围绕中间， 没有中心部件，就在上侧
this->addDockWidget(Qt::BottomDockWidgetArea ,dock);
```

效果

![](https://img-blog.csdnimg.cn/40a7d269bc604819842bb8f47e114c43.png)

因为没有中心部件，所以铆接部件在上侧

添加中心部件：除了以上几个部件，中心显示的部件都可以作为核心部件，例如一个记事本文件，可以利用QTextEdit做核心部件

```cpp
// 5、中心部件，核心部件，也只能有一个
QTextEdit* edit = new QTextEdit(this);
// 添加到窗口
setCentralWidget(edit);
```

效果

![](https://img-blog.csdnimg.cn/f578f7381fe5400b955a449e942e0d6b.png)

 铆接部件也可以只设置在某些位置，比如只设置在上下位置

```cpp
// 设置只允许在上侧和下侧
dock->setAllowedAreas(Qt::BottomDockWidgetArea | Qt::TopDockWidgetArea);
```

 效果

![](https://img-blog.csdnimg.cn/1e447206eab04f9fa3596c4f0265ad0d.png)

无法移动到其他位置

### 5 小总结 

如果只有一个，像菜单栏、中心部件，则添加到窗口时，使用set函数；

如果有多个，像工具栏、状态栏，则添加到窗口时，使用add函数；

本文转自 <https://blog.csdn.net/Zhouzi_heng/article/details/125411487>，如有侵权，请联系删除。