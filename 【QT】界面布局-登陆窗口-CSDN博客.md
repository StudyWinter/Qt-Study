 

记录页面布局-登陆窗口的流程

（1）继承QWidget

![](https://img-blog.csdnimg.cn/067483825b22409abe09a20a3200a416.png)

（2）设置标签

![](https://img-blog.csdnimg.cn/05cfedd1c362440186086f1924890dee.png)

（3）单行文本编辑

![](https://img-blog.csdnimg.cn/1b7a5f8c684943d0b47b221bb2ae1644.png)

（4）按钮

![](https://img-blog.csdnimg.cn/77ee551572574d18a6a5f0190d55389f.png)

开始设置布局，

法1：使用Horizontal layout，但是不方便

![](https://img-blog.csdnimg.cn/99c5520d55524573bf46179faadf6e51.png)

法2：Widget 常用，灵活

![](https://img-blog.csdnimg.cn/d4258af722c74523b2cb318d8ed6ea10.png)

![](https://img-blog.csdnimg.cn/216c3cb00099449db75de61c1c72939a.png)

![](https://img-blog.csdnimg.cn/b5b41da5c5ab44b39489198db855f4e0.png)

所有控件都做过布局，界面会随着调整而调整。

登陆、退出页面会很难看，加弹簧

![](https://img-blog.csdnimg.cn/ac46ac605ada447e8e8c0effb06493b0.png)

![](https://img-blog.csdnimg.cn/cc00e85085b949738bddb0c5a48d321c.png)

左右不变，上下变

修改弹簧属性

![](https://img-blog.csdnimg.cn/d83ca98534a4488fb50928b99940db5c.png)

打破布局法一

![](https://img-blog.csdnimg.cn/14e31ad8545d45419e89da93b8fdf59a.png)

打破布局法二：由外向内

![](https://img-blog.csdnimg.cn/d101a3fb8c9544bc838bce89389a32fd.png)

重新布局

![](https://img-blog.csdnimg.cn/74fe45ff84064a618f33f61409e5ae07.png)

![](https://img-blog.csdnimg.cn/c8444d8863294284bb09d670679b9247.png)

![](https://img-blog.csdnimg.cn/92d19eaf9f57411b83a588661edef28f.png)成品，可以拉缩

![](https://img-blog.csdnimg.cn/f026e4b9b989406ba6f13a521da6f867.png)

Widget比控件宽，调整

![](https://img-blog.csdnimg.cn/aa80a8073a784a67b7e56c5be5386f57.png)

![](https://img-blog.csdnimg.cn/b9f18d03a5444e5cbdd8464160d2f8ca.png)

控件和widget之间有9像素的间隙，调整

![](https://img-blog.csdnimg.cn/6b51d789224248f78393c5adbd8c485b.png)

效果

![](https://img-blog.csdnimg.cn/8dfc5f5d8d4c419d8d031d4bf9754d3a.png)

用户名和密码太近了，调整

![](https://img-blog.csdnimg.cn/d6d77cbe0bae473b95fb0caf96d0193e.png)

调整窗口并且不允许用户拉伸。最大值和最小值相同

![](https://img-blog.csdnimg.cn/fbff54ef4d144d1faf1346ec5e6bd64f.png)

窗口标题

![](https://img-blog.csdnimg.cn/a4b34b9933d84e9f83c36d72e9ac8a7a.png)

窗口太小了，看不到

![](https://img-blog.csdnimg.cn/afa76238dd1c472e8ea3d89b9cc5bc03.png)

本文转自 <https://blog.csdn.net/Zhouzi_heng/article/details/133893111?csdn_share_tail=%7B%22type%22%3A%22blog%22%2C%22rType%22%3A%22article%22%2C%22rId%22%3A%22133893111%22%2C%22source%22%3A%22Zhouzi_heng%22%7D>，如有侵权，请联系删除。