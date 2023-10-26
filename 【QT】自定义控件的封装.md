 

对[QT自定义控件](https://so.csdn.net/so/search?q=QT%E8%87%AA%E5%AE%9A%E4%B9%89%E6%8E%A7%E4%BB%B6&spm=1001.2101.3001.7020)的封装。

1 创建工程，选择[UI界面](https://so.csdn.net/so/search?q=UI%E7%95%8C%E9%9D%A2&spm=1001.2101.3001.7020)，继承Widget类。

2 创建设计师界面类，右键项目

![](https://img-blog.csdnimg.cn/9a62e926fd84478b9ec3613281d39c72.png)

![](https://img-blog.csdnimg.cn/49fe41b7a9494ae6a2a6cbb59e96b387.png)

![](https://img-blog.csdnimg.cn/9dbfa7c65a8543e9a1c16267cdb8ab16.png)

类名自己取，到完成即可。最后会生成,h/.cpp/.ui文件

3 点击生成的UI文件

![](https://img-blog.csdnimg.cn/b412a92d61a941449c558f19e076126d.png)

将需要的控件拖过来。这里使用Horizontal [Slider](https://so.csdn.net/so/search?q=Slider&spm=1001.2101.3001.7020)和Spin Box。

最终效果就是拖动Horizontal Slider，Spin Box的数字会变；修改Spin Box的数字，Horizontal Slider会滑动。

![](https://img-blog.csdnimg.cn/68ed04ac51bc402d87bdf310c57e1c5e.png)

还可以修改初始化，两个要对应

![](https://img-blog.csdnimg.cn/82eb5f491f004c88a1174f4b153903b8.png)

 4 在ui界面里添加widget控件，将其提升为之前创建的设计师界面类

![](https://img-blog.csdnimg.cn/59f59c31539f42aeb07f0c20dd0bc76d.png)

5 创建设计师界面类（名称自取）

![](https://img-blog.csdnimg.cn/cdcf26be3be74538a28ea9da9d829e6d.png)

6 使用信号的槽来完成需求；

6.1  首先设置【spinBox数字改变，是slider跟着滑动】

查看QSpinBox，它有一个重载的版本，使用函数指针来完成， 

![](https://img-blog.csdnimg.cn/f928bcf33d4549f993a1142b0f63d0f8.png)

```cpp
// spinBox数字改变，是slider跟着滑动
// 函数指针
void(QSpinBox::* spin)(int) = &QSpinBox::valueChanged;
connect(ui->spinBox, spin, ui->horizontalSlider,&QSlider::setValue);
```

 接着，同理

```cpp
// slider移动，spinBox数字跟着变化
connect(ui->horizontalSlider, &QSlider::valueChanged, ui->spinBox, &QSpinBox::setValue);
```

![](https://img-blog.csdnimg.cn/8a9300fa38154dd68f1701e736ececf1.png)

6.2 在widget.ui添加两个按钮，【设置到一半】和【设置到一半】

![](https://img-blog.csdnimg.cn/68eddafe46724ecab6bd25cd98c83714.png)

在Smallwidget类中添加两个函数【设置数据】和【获取数据】

![](https://img-blog.csdnimg.cn/687992351287462380160824c2b74271.png)

实现

![](https://img-blog.csdnimg.cn/3298bfa04e1240aba8d6abb7496626a0.png)

 在Widget.cpp中实现按钮的信号和槽

```cpp
// 点击设置一半
connect(ui->btn_set, &QPushButton::clicked, this, [=](){
    ui->widget->setVal(50);
});
 
// 点击获取当前值
connect(ui->btn_get, &QPushButton::clicked, this, [=](){
    qDebug() << ui->widget->getVal();
});
```

![](https://img-blog.csdnimg.cn/48d81b97f7b94b17b058cb69587e22bd.png)

 效果

![](https://img-blog.csdnimg.cn/ce3ea94cf53742e48e207174ea119765.png)

本文转自 <https://blog.csdn.net/Zhouzi_heng/article/details/125573720?csdn_share_tail=%7B%22type%22%3A%22blog%22%2C%22rType%22%3A%22article%22%2C%22rId%22%3A%22125573720%22%2C%22source%22%3A%22Zhouzi_heng%22%7D>，如有侵权，请联系删除。