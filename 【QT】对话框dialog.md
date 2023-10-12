 

### 1 基本概念

对话框是 GUI 程序中不可或缺的组成部分。很多不能或者不适合放入主窗口的功能组件都必须放在对话框中设置。对话框通常会是一个顶层窗口，出现在程序最上层，用于实现短期任务或者简洁的用户交互。

Qt 中使用[QDialog](https://so.csdn.net/so/search?q=QDialog&spm=1001.2101.3001.7020)类实现对话框。就像主窗口一样，我们通常会设计一个类继承QDialog。QDialog（及其子类，以及所有Qt::Dialog类型的类）的对于其 parent 指针都有额外的解释：**如果 parent 为 NULL，则该对话框会作为一个顶层窗口，否则则作为其父组件的子对话框（此时，其默认出现的位置是 parent 的中心）。顶层窗口与非顶层窗口的区别在于，顶层窗口在任务栏会有自己的位置，而非顶层窗口则会共享其父组件的位置。**

**对话框分为模态对话框和非模态对话框。**

（1）模态对话框，就是会阻塞同一应用程序中其它窗口的输入。

模态对话框很常见，比如“打开文件”功能。你可以尝试一下记事本的打开文件，当打开文件对话框出现时，我们是不能对除此对话框之外的窗口部分进行操作的。

（2）与此相反的是非模态对话框，例如查找对话框，我们可以在显示着查找对话框的同时，继续对记事本的内容进行编辑。

### 2 标准对话框

所谓标准对话框，是 Qt 内置的一系列对话框，用于简化开发。事实上，有很多对话框都是通用的，比如打开文件、设置颜色、打印设置等。这些对话框在所有程序中几乎相同，因此没有必要在每一个程序中都自己实现这么一个对话框。

Qt 的内置对话框大致分为以下几类：

1.  QColorDialog：       选择颜色；
2.  QFileDialog：        选择文件或者目录；
3.  QFontDialog：        选择字体；
4.  QInputDialog：       允许用户输入一个值，并将其值返回；
5.  **QMessageBox：        模态对话框，用于显示信息、询问问题等；**
6.  QPageSetupDialog：   为打印机提供纸张相关的选项；
7.  QPrintDialog：       打印机配置；
8.  QPrintPreviewDialog：打印预览；
9.  QProgressDialog：    显示操作过程。

### 3 自定义消息框

Qt 支持模态对话框和非模态对话框。

#### 3.1 模态对话框

当该种模态的对话框出现时，用户必须首先对对话框进行交互，直到关闭对话框，然后才能访问程序中其他的窗口。

需求：点击新建菜单项，弹出对话框。使用信号和槽、lambda表示式。

在新建项目是选择继承[QMainWindow](https://so.csdn.net/so/search?q=QMainWindow&spm=1001.2101.3001.7020)，并选择UI界面，在UI界面添加菜单项。

```cpp
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
 
    // 点击新建菜单项，弹出对话框，使用信号和槽，lambda表达式
    connect(ui->actionnew, &QAction::triggered, this, [=](){
        // 对话框的分类
        // 模态对话框：不可以对其他窗口操作，起到阻塞
        // 非模态对话框:可以对其他窗口进行操作，不会阻塞
 
        // 创建模态对话框
        QDialog dlg(this);
        dlg.resize(200, 50);
        dlg.exec();              // 在这里阻塞
 
        qDebug() <<"弹出对话框";
    });
 
}
```

效果

![](https://img-blog.csdnimg.cn/6cb0bddcb62e41e69d583b1b9ec38116.png)

当点其他界面时，会阻塞，关掉这个窗口时，才会输出【弹出对话框】。

#### 3.2 非模态对话框

可以在其他窗口进行操作

```cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDialog>
 
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
 
    // 点击新建菜单项，弹出对话框，使用信号和槽，lambda表达式
    connect(ui->actionnew, &QAction::triggered, this, [=](){
        // 对话框的分类
        // 模态对话框：不可以对其他窗口操作，起到阻塞
        // 非模态对话框:可以对其他窗口进行操作，不会阻塞
 
        // 创建非模态对话框，在栈上一闪而过
//        QDialog dlg(this);
//        dlg.resize(200, 50);
//        dlg.show();
 
        // 在堆区创建
        QDialog* dlg = new QDialog(this);
        dlg->resize(200, 50);
        dlg->show();
        // 设置属性，关闭窗口时，释放对象
        dlg->setAttribute(Qt::WA_DeleteOnClose);
 
 
        qDebug() <<"弹出对话框";
    });
 
}
```

效果

![](https://img-blog.csdnimg.cn/eff57bdd8a7345fba9e7edb813b36480.png)

不会阻塞在这个窗口上，并且会直接输出【弹出对话框】，注意两种创建方式。

### 4 消息对话框

QMessageBox用于显示消息提示。我们一般会使用其提供的几个 static 函数：

![](https://img-blog.csdnimg.cn/ec411d079ed2465ba4c998dcd0c39e0d.png)

#### 4.1 错误提示

函数原型

```cpp
StandardButton QMessageBox::critical(QWidget *parent, const QString &title, 
                                     const QString &text, StandardButtons buttons = Ok, 
                                     StandardButton defaultButton = NoButton)
```

参数：

> 参数1：父窗口；
> 参数2：标题；
> 参数3：中间显示文本；
> 参数4：按键类型；
> 参数5：关联回车的按键

```cpp
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
 
    // 点击新建菜单项，弹出对话框，使用信号和槽，lambda表达式
    connect(ui->actionnew, &QAction::triggered, this, [=](){
    
        // 3、QMessageBox
        // 错误提示
        QMessageBox::critical(this, "wrong", "错误");
 
        qDebug() <<"弹出对话框";
    });
 
}
 
```

效果

![](https://img-blog.csdnimg.cn/521bd6e8ab4d4f91858a0b7451621750.png)

#### 4.2 普通信息

```cpp
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
 
    // 点击新建菜单项，弹出对话框，使用信号和槽，lambda表达式
    connect(ui->actionnew, &QAction::triggered, this, [=](){
 
        // 3、QMessageBox
        // 普通信息
        QMessageBox::information(this, "information", "普通信息提示");
        qDebug() <<"弹出对话框";
    });
 
}
```

效果

![](https://img-blog.csdnimg.cn/6e963de6784f471b8ddd5272fd54f1c6.png)

#### 4.3 询问对话框

```cpp
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
 
    // 点击新建菜单项，弹出对话框，使用信号和槽，lambda表达式
    connect(ui->actionnew, &QAction::triggered, this, [=](){
        // 3、QMessageBox
        // 询问对话框，有两个选项yes/no
        // 参数1：父窗口；参数2：标题；参数3：中间显示文本；参数4：按键类型；参数5：关联回车的按键
//        QMessageBox::question(this, "question", "询问！");
//        QMessageBox::question(this, "question", "询问！", QMessageBox::Save|QMessageBox::Cancel);
//        QMessageBox::question(this, "question", "询问！", QMessageBox::Save|QMessageBox::Cancel, QMessageBox::Cancel);
 
        if (QMessageBox::Save == QMessageBox::question(this, 
                                "question", "询问！", 
                                QMessageBox::Save|QMessageBox::Cancel, 
                                QMessageBox::Cancel)) {
            qDebug() << "保存";
        } else {
            qDebug() << "取消";
        }
 
 
        qDebug() <<"弹出对话框";
    });
 
}
```

测试一个。，点击save，效果

![](https://img-blog.csdnimg.cn/e79a1afe9b26444888b863bfc398247f.png)

#### 4.4 警告信息

```cpp
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
 
    // 点击新建菜单项，弹出对话框，使用信号和槽，lambda表达式
    connect(ui->actionnew, &QAction::triggered, this, [=](){
        // 3、QMessageBox
        // 警告提示
        QMessageBox::warning(this, "warning", "警告");
        qDebug() <<"弹出对话框";
    });
 
}
```

效果

![](https://img-blog.csdnimg.cn/a924a0d2df324d3d8d70f10699fc8366.png)

### 5 其他对话框

#### 5.1 颜色对话框

```cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDialog>
#include <QMessageBox>
#include <QColorDialog>     // 颜色对话框头文件
#include <QFontDialog>
#include <QFileDialog>
 
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
 
    // 点击新建菜单项，弹出对话框，使用信号和槽，lambda表达式
    connect(ui->actionnew, &QAction::triggered, this, [=](){
 
        // 颜色对话框
//        QColorDialog::getColor();
        // 设置颜色
//        QColorDialog::getColor(QColor(255, 0, 0));
        // 捕获
        QColor color = QColorDialog::getColor(QColor(255, 0, 0));
        qDebug() << color.red() << color.blue() << color.green();
    });
 
}
```

测试一个即可，效果。

![](https://img-blog.csdnimg.cn/a98c0fa9d56c46eea9f0af11ae23267a.png)

#### 5.2 字体对话框

```cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDialog>
#include <QMessageBox>
#include <QColorDialog>
#include <QFontDialog>      // 字体对话框头文件
#include <QFileDialog>
 
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
 
    // 点击新建菜单项，弹出对话框，使用信号和槽，lambda表达式
    connect(ui->actionnew, &QAction::triggered, this, [=](){
        //  字体对话框
        bool ok;
        QFontDialog::getFont(&ok, QFont("华文彩云", 20));
//        // 捕获
        QFont font = QFontDialog::getFont(&ok, QFont("华文彩云", 20));
        qDebug() << "字体：" << font.family() << "字号：" << font.pointSize()
                 << "加粗：" << font.bold() << "倾斜：" << font.italic();
}
```

测试一个即可，效果。 

![](https://img-blog.csdnimg.cn/c0db8d4fcd3b407a86b50644293b07ce.png)

#### 5.3 文件对话框

```cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDialog>
#include <QMessageBox>
#include <QColorDialog>
#include <QFontDialog>
#include <QFileDialog>
 
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
 
    // 点击新建菜单项，弹出对话框，使用信号和槽，lambda表达式
    connect(ui->actionnew, &QAction::triggered, this, [=](){
 
        // 文件对话框
        // 默认在项目的同级目录
//        QFileDialog::getOpenFileName(this, "打开文件");
        // 修改默认路径
//        QFileDialog::getOpenFileName(this, "打开文件", "C:\\Users\\songdongdong\\Desktop\\coding");
        // 过滤格式，只看exe文件
//        QFileDialog::getOpenFileName(this, "打开文件", "C:\\Users\\songdongdong\\Desktop\\coding", "(*.exe)");
 
        // 捕获
        QString str = QFileDialog::getOpenFileName(this, "打开文件", "C:\\Users\\xxx\\Desktop\\coding", "(*.exe)");
        qDebug() << str;
 
    });
 
}
```

测试一个即可，效果。 

![](https://img-blog.csdnimg.cn/43388a9d198c408dac79eabf9afc7dc4.png)

本文转自 <https://blog.csdn.net/Zhouzi_heng/article/details/125446318>，如有侵权，请联系删除。