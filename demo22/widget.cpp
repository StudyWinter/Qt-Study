#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextCodec>
#include <QFileInfo>
#include <QDebug>
#include <QDateTime>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 点击选择文件按钮。弹出问价对话框，读取文件，将文件路径放入在lineEdit，内容放在TextEdit
    connect(ui->addFile, &QPushButton::clicked, this, [=]() {
        // 弹出对话框
        // 父窗口，标题，路径，过滤格式。返回值是路径
        QString filePath = QFileDialog::getOpenFileName(this, "打开文件", "D:\\code\\QT\\demo22", "(*.txt)");
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

            //文件信息类
            QFileInfo info(filePath);
            qDebug() << "后缀名:" << info.suffix().toUtf8().data() << "大小:"<< info.size()
                     << "文件名:" << info.fileName().toUtf8().data() << "文件路径" << info.filePath().toUtf8().data();



            // 创建日期
            qDebug() << "创建日期" << info.birthTime().toString("yyyy-MM-dd hh:mm:ss")
                     << "最后修改日期:" << info.lastModified().toString("yyyy/MM/dd hh:mm:ss");

        }


    });
}

Widget::~Widget()
{
    delete ui;
}
