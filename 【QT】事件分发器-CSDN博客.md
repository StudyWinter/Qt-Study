 

![](https://img-blog.csdnimg.cn/4061f352f5434d169a4de8235ac99488.png)

event事件分发器，用于分发事件，在这里也可以做拦截，返回值boo。如果返回的是true代表拦截处理，不再向下分发。

**展示事件拦截**

上一段代码：[【QT】鼠标常用事件-CSDN博客](https://blog.csdn.net/Zhouzi_heng/article/details/134128618?csdn_share_tail=%7B%22type%22%3A%22blog%22%2C%22rType%22%3A%22article%22%2C%22rId%22%3A%22134128618%22%2C%22source%22%3A%22Zhouzi_heng%22%7D "【QT】鼠标常用事件-CSDN博客")

![](https://img-blog.csdnimg.cn/21f245732c184b95843c384342caa6fc.png)

代码

```cpp
// 事件分发器
// 拦截鼠标按下
// QEvent是所有事件的父类
bool MyLabel::event(QEvent* e) {
    if (e->type() == QEvent::MouseButtonPress) {
        // 转换一下
        QMouseEvent* ev = static_cast<QMouseEvent*>(e);
        QString str = QString("在event中鼠标按下, x = %1, y = %2").arg(ev->x()).arg(ev->y());
        qDebug() << str;
        // 拦截
        return true;
    }
    // 其他事件交给父类
    return QLabel::event(e);
}
```

.h文件中声明该函数

**效果**

![](https://img-blog.csdnimg.cn/1f44e33d0ab545578262c89fec5f1103.png)

忘记返回true。没拦截住。

![](https://img-blog.csdnimg.cn/8c8182cf1af745059314f6712ba79cc5.png)

不建议做拦截

本文转自 <https://blog.csdn.net/Zhouzi_heng/article/details/134149585?csdn_share_tail=%7B%22type%22%3A%22blog%22%2C%22rType%22%3A%22article%22%2C%22rId%22%3A%22134149585%22%2C%22source%22%3A%22Zhouzi_heng%22%7D>，如有侵权，请联系删除。