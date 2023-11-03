 

新建项目

![](https://img-blog.csdnimg.cn/f9cba224dd594137bb096956d362a476.png)加入控件

![](https://img-blog.csdnimg.cn/6f2633f551524a19be659c594b838b46.png)

整体做一个布局

![](https://img-blog.csdnimg.cn/f125e1783c414e24b7c51f63ac0b3396.png)

功能：选择文件路径，打开文件（两种文件格式：utf-8、GBK）

```cpp
#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextCodec>
 
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
 
    // 点击选择文件按钮。弹出问价对话框，读取文件，将文件路径放入在lineEdit，内容放在TextEdit
    connect(ui->addFile, &QPushButton::clicked, this, [=]() {
        // 弹出对话框
        // 父窗口，标题，路径，过滤格式。返回值是路径
        QString filePath = QFileDialog::getOpenFileName(this, "打开文件", "D:\\code\\QT\\demo21", "(*.txt)");
        // 判断空路径
        if (filePath.isEmpty()) {
            QMessageBox::warning(this, "警告", "路径不能为空");
        } else {
//            ui->lineEdit->setText(filePath);
//            // 读取文件信息
//            QFile file(filePath);
//            // 指定打开方式，只读
//            file.open(QIODevice::ReadOnly);
//            // 读取全部信息
//            QByteArray arr;
//            arr = file.readAll();
//            // 将内容放在TextEdit，默认支持utf-8
//            ui->textEdit->setText(arr);
 
 
 
            // 提前指定编码格式
            QTextCodec* codec = QTextCodec::codecForName("gbk");
            ui->lineEdit->setText(filePath);
            // 读取文件信息
            QFile file(filePath);
            // 指定打开方式，只读
            file.open(QIODevice::ReadOnly);
            // 读取全部信息
            QByteArray arr;
            arr = file.readAll();
            // 将内容放在TextEdit，
            ui->textEdit->setText(codec->toUnicode(arr));
 
        }
 
 
 
 
    });
}
 
Widget::~Widget()
{
    delete ui;
}
 
```

效果

![](https://img-blog.csdnimg.cn/3e2a39a4c832491aa9c63887f738c58c.png)

![](https://img-blog.csdnimg.cn/0bee574e722345b3b4d107b315bd2138.png)

读文件：读所有和按行读

```cpp
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
 
    // 点击选择文件按钮。弹出问价对话框，读取文件，将文件路径放入在lineEdit，内容放在TextEdit
    connect(ui->addFile, &QPushButton::clicked, this, [=]() {
        // 弹出对话框
        // 父窗口，标题，路径，过滤格式。返回值是路径
        QString filePath = QFileDialog::getOpenFileName(this, "打开文件", "D:\\code\\QT\\demo21", "(*.txt)");
        // 判断空路径
        if (filePath.isEmpty()) {
            QMessageBox::warning(this, "警告", "路径不能为空");
        } else {
            ui->lineEdit->setText(filePath);
            // 读取文件信息
            QFile file(filePath);
            // 指定打开方式，只读
            file.open(QIODevice::ReadOnly);
            // 读取全部信息
            QByteArray arr;
//            arr = file.readAll();             // 读所有
 
            // 按行读
            while (!file.atEnd()) {
                arr += file.readLine();
            }
            // 将内容放在TextEdit，默认支持utf-8
            ui->textEdit->setText(arr);
 
        }
 
 
 
 
    });
}
```

写文件

```cpp
#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextCodec>
 
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
 
    // 点击选择文件按钮。弹出问价对话框，读取文件，将文件路径放入在lineEdit，内容放在TextEdit
    connect(ui->addFile, &QPushButton::clicked, this, [=]() {
        // 弹出对话框
        // 父窗口，标题，路径，过滤格式。返回值是路径
        QString filePath = QFileDialog::getOpenFileName(this, "打开文件", "D:\\code\\QT\\demo21", "(*.txt)");
        // 判断空路径
        if (filePath.isEmpty()) {
            QMessageBox::warning(this, "警告", "路径不能为空");
        } else {
            ui->lineEdit->setText(filePath);
            // 读取文件信息
            QFile file(filePath);
            // 指定打开方式，只读
            file.open(QIODevice::ReadOnly);
            // 读取全部信息
            QByteArray arr;
//            arr = file.readAll();             // 读所有
 
            // 按行读
            while (!file.atEnd()) {
                arr += file.readLine();
            }
            // 将内容放在TextEdit，默认支持utf-8
            ui->textEdit->setText(arr);
 
            // 关闭文件
            file.close();
            // 写文件，会覆盖前面的内容
//            file.open(QIODevice::WriteOnly);
            file.open(QIODevice::Append);         // 追加
            file.write("123456789");
            file.close();
 
        }
 
 
 
 
    });
}
 
Widget::~Widget()
{
    delete ui;
}
 
```

效果

![](https://img-blog.csdnimg.cn/41805bb6ae784dc39251eee7dbb940ed.png)

全部代码

```cpp
#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextCodec>
 
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
 
    // 点击选择文件按钮。弹出问价对话框，读取文件，将文件路径放入在lineEdit，内容放在TextEdit
    connect(ui->addFile, &QPushButton::clicked, this, [=]() {
        // 弹出对话框
        // 父窗口，标题，路径，过滤格式。返回值是路径
        QString filePath = QFileDialog::getOpenFileName(this, "打开文件", "D:\\code\\QT\\demo21", "(*.txt)");
        // 判断空路径
        if (filePath.isEmpty()) {
            QMessageBox::warning(this, "警告", "路径不能为空");
        } else {
            ui->lineEdit->setText(filePath);
            // 读取文件信息
            QFile file(filePath);
            // 指定打开方式，只读
            file.open(QIODevice::ReadOnly);
            // 读取全部信息
            QByteArray arr;
//            arr = file.readAll();             // 读所有
 
            // 按行读
            while (!file.atEnd()) {
                arr += file.readLine();
            }
            // 将内容放在TextEdit，默认支持utf-8
            ui->textEdit->setText(arr);
 
            // 关闭文件
            file.close();
            // 写文件，会覆盖前面的内容
//            file.open(QIODevice::WriteOnly);
            file.open(QIODevice::Append);         // 追加
            file.write("123456789");
            file.close();
 
 
 
 
//            // 提前指定编码格式
//            QTextCodec* codec = QTextCodec::codecForName("gbk");
//            ui->lineEdit->setText(filePath);
//            // 读取文件信息
//            QFile file(filePath);
//            // 指定打开方式，只读
//            file.open(QIODevice::ReadOnly);
//            // 读取全部信息
//            QByteArray arr;
//            arr = file.readAll();
//            // 将内容放在TextEdit，
//            ui->textEdit->setText(codec->toUnicode(arr));
//            file.close();
 
        }
 
 
 
 
    });
}
 
Widget::~Widget()
{
    delete ui;
}
 
```

本文转自 <https://blog.csdn.net/Zhouzi_heng/article/details/134210867?csdn_share_tail=%7B%22type%22%3A%22blog%22%2C%22rType%22%3A%22article%22%2C%22rId%22%3A%22134210867%22%2C%22source%22%3A%22Zhouzi_heng%22%7D>，如有侵权，请联系删除。