 

信号槽是 Qt 框架引以为豪的机制之一。所谓信号槽，实际就是观察者模式。**当某个事件发生之后**，比如，按钮检测到自己被点击了一下，**它就会发出一个信号（signal）**。这种发出是没有目的的，类似广播。**如果有对象对这个信号感兴趣，它就会使用连接（connect）函数**，意思是，**将想要处理的信号和自己的一个函数（称为槽（slot））绑定来处理这个信号**。也就是说，**当信号发出时，被连接的槽函数会自动被回调**。这就类似观察者模式：当发生了感兴趣的事件，某一个操作就会被自动触发。

### 1 系统自带的信号和槽

创建工程，继承自QWidth

在widget,cpp的构造函数中定义按钮

```cpp
// 定义按钮，引入头文件
QPushButton* btn = new QPushButton("按钮", this);
    
// 移动按钮
btn->move(0, 200);
 
// 设置窗口大小
this->setFixedSize(600, 400);
 
// 设置窗口标题
this->setWindowTitle("按钮");
```

如果不加其他代码，点了这点按钮，不会有什么反应。现在想点了这个按钮后，关闭窗口。

引入**connect函数**

```cpp
conncet(信号发送者， 发送的信号， 信号的接受者， 槽函数)   // 槽函数就是对应的操作事件
```

那么在本案例中，这样写：

```cpp
// 参数：1信号发送者（指针）， 2发送的信号地址， 3信号的接收者, 4槽函数
connect(btn, &QPushButton::clicked, this, &Widget::close);
```

也就是说：

（1）信号的发送者是btn按钮；

（2）发送的信号是关闭当前窗口（这个需要在帮助文档里面查询）；

> 那么系统自带的信号和槽通常如何查找呢，这个就需要利用帮助文档了，在帮助文档中比如我们上面的按钮的点击信号，在帮助文档中输入[QPushButton](https://so.csdn.net/so/search?q=QPushButton&spm=1001.2101.3001.7020)，首先我们可以在Contents中寻找关键字 signals，信号的意思，但是我们发现并没有找到，这时候我们应该想到也许这个信号的被父类继承下来的，因此我们去他的父类QAbstractButton中就可以找到该关键字，点击signals索引到系统自带的信号有如下几个：
> 
> ![](https://img-blog.csdnimg.cn/e2e3be53712c4f1b85a9bf4faa91b8f7.png)
> 
> 这里的clicked就是我们要找到的。槽函数的寻找方式和信号一样，只不过他的关键字是slot。

（3）信号的接收者是当前窗口；

（4）槽函数是close（也需要在帮助文档里面查询）

> 如果当前类没有槽函数，则一直在父类中找
> 
> ![](https://img-blog.csdnimg.cn/3ba47f65e96a4f548404f15ffa7dec5e.png)

疑问

> 应该说QPushButton中没有clicked，也没有close，这里应该写其父类（或者更上层的父类），但是这样也可以运行；写有对用信号和槽的父类也行
> 
> connect(btn, &QPushButton::clicked, this, &QPushButton::close);
> 
> connect(btn, &QAbstractButton::clicked, this, &Widget::close);

这时点击弹出窗口中的按钮，就可以关闭窗口了。

### 2 自己写一个简单的信号和槽

需求：下课后，老师会发出饿了的信号，学生进行响应，请老师吃饭。

> 分析：
> 
> 信号的发送方是老师；
> 
> 发送的信号是饿了；
> 
> 信号的接收方是学生；
> 
> 槽函数（处理方式）是请老师吃饭。

#### 2.1 自定义老师类

老师类中有信号，写在signals下。

注意点：

（1）返回值是void；

（2）只需要声明，不需要实现；

（3）可以有参数，可以重载；

![](https://img-blog.csdnimg.cn/0a738c34b646496d98630c0091a93a0c.png)

#### 2.2 自定义学生类

学生类中有槽函数，写在public slots下或者public下，或者全局函数，或者lambda表达式。

注意点：

（1）返回值是void；

（2）需要声明，需要实现；

（3）可以有参数，可以重载；

声明：

![](https://img-blog.csdnimg.cn/a1a62e402e084806964a0bd38bb88517.png)

实现：

![](https://img-blog.csdnimg.cn/b467ed8c51cc41f0909cf9dafebcfd03.png)

#### 2.3 在widget.h文件定义相关参数

中定义老师类的指针、学生类的指针，声明下课函数（触发函数）

![](https://img-blog.csdnimg.cn/d17de47a27dc469289e02480cf1e8b8b.png)

#### 2.4 在widget.cpp文件中实现

（1）首先需要创建老师类的指针和学生类的指针，可以考虑挂到对象树上；

```cpp
// 挂对象树上，不用写delete
this->teacher = new Teacher(this);
this->student = new Student(this);
```

（2）实现触发函数；

```cpp
void Widget::classIsOver() {
    // 触发自定义信号，使用emit关键字
    emit this->teacher->hungry();
}
```

 （3）链接信号槽

```cpp
// 链接信号槽
connect(this->teacher, &Teacher::hungry, this->student, &Student::treat);
```

（4）调用触发函数

```cpp
// 调用下课函数
classIsOver();
```

完整代码

![](https://img-blog.csdnimg.cn/3646eac9d3124b2aaa2433567931737f.png)

测试

![](https://img-blog.csdnimg.cn/185432f1d8e046f39d9a0824cb46df07.png)

### 3 写一个重载信号和槽

（1）首先再Teacher类中，重载一个信号。加上形参 

![](https://img-blog.csdnimg.cn/0185e4db677f4e26860e7636bb255f2f.png)（2）在Student类中也重载槽函数

![](https://img-blog.csdnimg.cn/714af0f27adb4864b5cbe0fd1ed56739.png)

实现

![](https://img-blog.csdnimg.cn/28afa04d357a44c09c0f9aaa040cd7e4.png)

```cpp
void Student::treat(QString foodName) {
    // QString转成char*
    // 先调用toUtf-8转为QByteArray
    // 再调用data转为char*
    qDebug() << "请老师吃饭，老师要吃:" << foodName;
    qDebug() << "请老师吃饭，老师要吃:" << foodName.toUtf8().data();
}
```

这里输出的时候，会有""，可以考虑把QString类型转换成char\*

（3）连接

![](https://img-blog.csdnimg.cn/8119da8fbdf843d487029e0c8fa9a228.png)

**这里在使用信号和槽时使用函数指针，实现重载。函数指针在定义的时候要加上作用域。**

**在触发的时候，要传参数。**

```cpp
#include "mainwindow.h"
 
// 下课后，老师发出饿了的信号，学生进行响应，请老师吃饭
 
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
 
    // 初始化老师和学生指针
    this->teacher = new Teacher(this);
    this->student = new Student(this);
 
    // 调用conncet
//    connect(this->teacher, &Teacher::hungry, this->student, &Student::treat);
 
    // 连接有参数的信号和槽
    // 加函数指针 指向函数
    void (Teacher::*teacherSignal)(QString) = &Teacher::hungry;
    void (Student::*studentSignal)(QString) = &Student::treat;
    connect(this->teacher, teacherSignal, this->student, studentSignal);
 
    this->afterClass();
 
 
}
 
MainWindow::~MainWindow()
{
}
 
void MainWindow::afterClass() {
    // 下课后请吃饭
//    emit this->teacher->hungry();
    emit this->teacher->hungry("宫保鸡丁");
}
```

结果

![](https://img-blog.csdnimg.cn/e2ff6e12d57d4f52aa925604ebdbf293.png)

### 4 信号连接信号

需求：按下按钮，出现请老师吃饭

（1）生成按钮控件

```cpp
QPushButton* btn = new QPushButton;
btn->resize(50,50);
btn->setParent(this);
btn->setText("下课");
```

（2）使用无参的信号和槽

函数指针

```cpp
void (Teacher::*teacherSignal2)() = &Teacher::hungry;
void (Student::*studentSignal2)() = &Student::treat;
connect(this->teacher, teacherSignal2, this->student, studentSignal2);
```

（3）连接

```cpp
 // 信号连接信号
connect(btn, &QPushButton::clicked, this->teacher, teacherSignal2);
```

![](https://img-blog.csdnimg.cn/8e99c36befbb46f6b66e94a30092c3ed.png)

（4）执行

![](https://img-blog.csdnimg.cn/3526b3ccb5e24dbd9f0184e4573e4362.png)

### 5 信号和槽拓展

（1）信号可以连接信号；

（2）一个信号可以连接多个槽函数；

（3）多个信号可以同时连接一个槽函数；

（4）信号和槽的参数类型必须一一对应；

（5）信号的参数个数可以多于槽函数的个数，反之不可以；相同参数的参数类型要一一对应；

（6）可以利用disconnect断开信号和槽。

```cpp
// 怎么连接，就怎么断开
disconnect(btn, &QPushButton::clicked, this->teacher, teacherSignal2);
```

本文转自 <https://blog.csdn.net/Zhouzi_heng/article/details/125379017>，如有侵权，请联系删除。