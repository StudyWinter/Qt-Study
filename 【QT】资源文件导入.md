 

（1）在新建工程时，继承[QMainWindow](https://so.csdn.net/so/search?q=QMainWindow&spm=1001.2101.3001.7020)，并勾选Generate form，如图。

![](https://img-blog.csdnimg.cn/2053727ca1c94e06b64f4b5fcdf7142f.png)

（2）双击mainwindow.ui，出现界面

![](https://img-blog.csdnimg.cn/2f407db3eb5541f89d43494c9cb90605.png)

这个界面就是运行后的结果图，之前是用代码加入菜单栏、工具栏等选项，这里可以手动添加。

![](https://img-blog.csdnimg.cn/f96c285bab2642ef87baeed5934e341f.png)

（3）将new和open改成中文

![](https://img-blog.csdnimg.cn/a9b06e42a7b846bb8ed7e226c77effea.png)

这里的new和objectName选项里面的actionnew对应，代码需要英文字符。我们需要将下面text选项中的new改成我们想要的文字即可。

![](https://img-blog.csdnimg.cn/b26cbfc3fd1c41c6a27e9f8a12cb1c57.png)

在左侧亦可以添加我们需要的组件，这里不赘述。

（4）回到代码。这段代码就是[UI界面](https://so.csdn.net/so/search?q=UI%E7%95%8C%E9%9D%A2&spm=1001.2101.3001.7020)的控制代码，不建议修改。 

![](https://img-blog.csdnimg.cn/c0113918498f4af99fdf008628f3df31.png)

（5）引入本地资源

```cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
 
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);      // 这段代码必须在构造函数的最前面
    // 因为所有的操作都是基于这个界面的
 
    // 而想操作本界面的控件，用ui->引用即可
 
    // 引入本地资源，两种路径
    ui->actionnew->setIcon(QIcon("E:/code/qt/Image/Luffy.png"));
    ui->actionopen->setIcon(QIcon("E:\\code\\qt\\Image\\Luffy.png"));
}
 
MainWindow::~MainWindow()
{
    delete ui;
}
```

![](https://img-blog.csdnimg.cn/303f0104c3d84471ab3b3c1764d83bf0.png)

效果图

![](https://img-blog.csdnimg.cn/04be6dc030d0417a818f5b6a21d3b6f8.png)

这个资源是本地资源，无法实现项目共享时的传递，需要将资源引入到本工程下。

（6） 将资源引入到本工程

（a）右键项目，选择add new

![](https://img-blog.csdnimg.cn/526072823b5f4be198d41b50b6696a2d.png)

（b）选择Qt，选择Qt Resource File，之后命名，点击完成即可。

![](https://img-blog.csdnimg.cn/4d312cf96f2c4069a22dd1705de86e49.png)

（c）选择add Prefix，为资源添加前缀，自行命名

![](https://img-blog.csdnimg.cn/43f290d9f1c94082bdd21557e226f438.png)

（d）将提前准备好的资源放到项目下，然后点击Add Files，将资源添加进来

![](https://img-blog.csdnimg.cn/6f3a145959d54aefa3512a9cf858c92f.png)

 效果图

![](https://img-blog.csdnimg.cn/8cbd5ad516924f84ad1568560e44e587.png)

（e）编译一下

![](https://img-blog.csdnimg.cn/6ab0d1966c3f4086b45f8623b1b7d611.png)

（f）将所需资源引入

```cpp
// 引入格式：":+前缀名+文件名"
ui->actionnew->setIcon(QIcon(":/Image/Luffy.png"));
ui->actionopen->setIcon(QIcon(":/Image/LuffyQ.png"));
```

![](https://img-blog.csdnimg.cn/f487a319432c45b2b464556699c8a373.png)

效果图

![](https://img-blog.csdnimg.cn/a5d7c45e99264dd6a8ef10bd7473d170.png)

本文转自 <https://blog.csdn.net/Zhouzi_heng/article/details/125434467>，如有侵权，请联系删除。