 

(1)文件->新建文件或者项目。或者在右侧的【Protects->new】

![](https://img-blog.csdnimg.cn/2021052521473448.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L1pob3V6aV9oZW5n,size_16,color_FFFFFF,t_70)

(2)Application->Qt Widght Application

![](https://img-blog.csdnimg.cn/20210525214918676.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L1pob3V6aV9oZW5n,size_16,color_FFFFFF,t_70)

(3)名称、路径【都不要有中文，名称不要有空格】

![](https://img-blog.csdnimg.cn/20210525215014750.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L1pob3V6aV9oZW5n,size_16,color_FFFFFF,t_70)

（4）默认即可（[qmake](https://so.csdn.net/so/search?q=qmake&spm=1001.2101.3001.7020)）

![](https://img-blog.csdnimg.cn/20210525215154268.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L1pob3V6aV9oZW5n,size_16,color_FFFFFF,t_70)

(5)Detail

![](https://img-blog.csdnimg.cn/20210525215333747.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L1pob3V6aV9oZW5n,size_16,color_FFFFFF,t_70)

初学可去掉 Generate form

Base class 这里可选：QMainWindow(主窗口)、**QWidget(窗口)**、[QDialog](https://so.csdn.net/so/search?q=QDialog&spm=1001.2101.3001.7020)(对话框)。初学可选**QWidget(窗口)**

![](https://img-blog.csdnimg.cn/20210525215442839.png)

[QWidget](https://so.csdn.net/so/search?q=QWidget&spm=1001.2101.3001.7020)、QMainWindow、QDiglog的关系

![](https://img-blog.csdnimg.cn/e8c30793d7394fca8440898c8ee60ad4.png)

(6)Translation(可默认，也可选Chinese)

![](https://img-blog.csdnimg.cn/20210525215745980.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L1pob3V6aV9oZW5n,size_16,color_FFFFFF,t_70)

（7）Kits(默认)

![](https://img-blog.csdnimg.cn/20210525215846901.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L1pob3V6aV9oZW5n,size_16,color_FFFFFF,t_70)

(8)Summary(默认)

![](https://img-blog.csdnimg.cn/20210525220009807.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L1pob3V6aV9oZW5n,size_16,color_FFFFFF,t_70)

(9)界面

![](https://img-blog.csdnimg.cn/20210525220344457.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L1pob3V6aV9oZW5n,size_16,color_FFFFFF,t_70)

（10）各个文件说明

**02second.pro**

```bash
QT       += core gui            //包含的模块
 
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets    //大于Qt4版本 才包含widget模块
 
CONFIG += c++11               // c++11
 
# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
 
# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
 
SOURCES += \             //源文件
    main.cpp \
    widget.cpp
 
HEADERS += \             //头文件
    widget.h
 
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
```

****.pro就是工程文件(project)，它是qmake自动生成的用于生产makefile的配置文件****。.pro文件的写法如下：

1.  注释

从“#”开始，到这一行结束。

1.  模板变量告诉qmake为这个应用程序生成哪种makefile。下面是可供使用的选择：****TEMPLATE**** = app
    1.  app -建立一个应用程序的makefile。这是默认值，所以如果模板没有被指定，这个将被使用。
    2.  lib - 建立一个库的makefile。
    3.  vcapp - 建立一个应用程序的VisualStudio项目文件。
    4.  vclib - 建立一个库的VisualStudio项目文件。
    5.  subdirs -这是一个特殊的模板，它可以创建一个能够进入特定目录并且为一个项目文件生成makefile并且为它调用make的makefile。
2.  #指定生成的应用程序名：

****TARGET**** = QtDemo

#工程中包含的头文件

****HEADERS**** += include/painter.h

#工程中包含的.ui设计文件

****FORMS**** += forms/painter.ui

#工程中包含的源文件

****SOURCES**** += sources/main.cpp sources

#工程中包含的资源文件

****RESOURCES**** += qrc/painter.qrc

****greaterThan(QT\_MAJOR\_VERSION, 4): QT += widgets****

****这条********语句的含义是，如果QT\_MAJOR\_VERSION********大于4（也就是********当前使用的Qt5********及********更高版本）********需要********增加widgets模块。如果********项目********仅需********支持********Qt5********，********也可以直接添加“QT += widgets”一句。不过为了保持代码********兼容********，最好还是按照QtCreator生成的语句编写。****

#配置信息

CONFIG用来告诉qmake关于应用程序的配置信息。

CONFIG += c++11 //使用c++11的特性

在这里使用“+=”，是因为我们添加我们的配置选项到任何一个已经存在中。这样做比使用“=”那样替换已经指定的所有选项更安全。

**main入口函数中**

```cpp
#include "widget.h" 
#include <QApplication> 
int main(int argc, char *argv[])
{    
	QApplication a(argc, argv);    
	Widget w;    
	w.show();    
	return a.exec();
}
```

解释：

1.  Qt系统提供的标准类名声明头文件没有.h后缀
2.  Qt一个类对应一个头文件，类名就是头文件名
3.  QApplication应用程序类
    1.  管理图形用户界面应用程序的控制流和主要设置。
    2.  是Qt的整个后台管理的命脉它****包含主事件循环****，在其中来自窗口系统和其它资源的****所有事件处理和调度****。它也处理****应用程序的初始化和结束****，并且****提供对话管理****。
    3.  对于任何一个使用Qt的图形用户界面应用程序，都正好存在一个QApplication 对象，而不论这个应用程序在同一时间内是不是有0、1、2或更多个窗口。
4.  a.exec()

****程序进入消息循环****，等待对用户输入进行响应。这里main()把控制权转交给Qt，Qt完成事件处理工作，当应用程序退出的时候exec()的值就会返回。****在exec()中，Qt接受并处理用户和系统的事件并且把它们传递给适当的窗口部件。****

**头文件**

![](https://img-blog.csdnimg.cn/71b33e44235d4e2a8a431348dfe95971.png)

```h
#ifndef MYTEST_H
#define MYTEST_H

#include <QWidget>

class MyTest : public QWidget
{
    Q_OBJECT    // Q_OBJECT支持Qt中的信号和槽

public:
    MyTest(QWidget *parent = nullptr);
    ~MyTest();
};
#endif // MYTEST_H
```

命名规范：

（1）类名首字母大写，单词之间首字母大写；

（2）函数名、变量名小写，单词之间首字母大写；

**快捷键**

    注释 ctrl + /
    运行 ctrl + r
    编译 ctrl + b 
    查找 ctrl + f
    整行的移动 ctrl + shift + 上键/下键 
    帮助文档 F1
    自动对齐 ctrl + i
    同名之间的.h和.cpp切换  F4

本文转自 <https://blog.csdn.net/Zhouzi_heng/article/details/117265307>，如有侵权，请联系删除。