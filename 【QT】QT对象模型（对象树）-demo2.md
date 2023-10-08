 

在Qt中创建对象的时候会提供一个Parent对象指针，下面来解释这个parent到底是干什么的。

*   （1）QObject是以对象树的形式组织起来的；
    *           （a）当创建一个QObject对象时，会看到QObject的构造函数接收一个QObject指针作为参数，这个参数就是 parent，也就是父对象指针。这相当于，**在创建QObject对象时，可以提供一个其父对象，我们创建的这个QObject对象会自动添加到其父对象的children()列表。**
        *           （b）**当父对象析构的时候，这个列表中的所有对象也会被析构。（注意，这里的父对象并不是继承意义上的父类！）**这种机制在 GUI 程序设计中相当有用。例如，一个按钮有一个QShortcut（快捷键）对象作为其子对象。当我们删除按钮的时候，这个快捷键理应被删除。这是合理的。
    
*   （2）QWidget是能够在屏幕上显示的一切组件的父类；
    *           （a）**QWidget****继承自QObject，因此也继承了这种对象树关系。一个孩子自动地成为父组件的一个子组件**。因此，它会显示在父组件的坐标系统中，被父组件的边界剪裁。例如，当用户关闭一个对话框的时候，应用程序将其删除，那么，我们希望属于这个对话框的按钮、图标等应该一起被删除。事实就是如此，因为这些都是对话框的子组件。
        *           （b）当然，**我们也可以自己删除子对象，它们会自动从其父对象列表中删除。**比如，当我们删除了一个工具栏时，其所在的主窗口会自动将该工具栏从其子对象列表中删除，并且自动调整屏幕显示。
        
        *   **（3）Qt 引入对象树的概念，在一定程度上解决了内存问题。**
            
            *           （a）当一个[QObject](https://so.csdn.net/so/search?q=QObject&spm=1001.2101.3001.7020)对象在堆上创建的时候，Qt 会同时为其创建一个对象树。不过，对象树中对象的顺序是没有定义的。这意味着，销毁这些对象的顺序也是未定义的。
                    
                
                *           （b）任何对象树中的 QObject对象 delete 的时候，如果这个对象有 parent，则自动将其从 parent 的children()列表中删除；如果有孩子，则自动 delete 每一个孩子。Qt 保证没有QObject会被 delete 两次，这是由析构顺序决定的。
                
            *   **只要定义的对象继承自QObject或者OBject的子类，就不用delete对象**
                
            *   测试：
                
            *   （1）新建按钮项目，继承自[QWidget](https://so.csdn.net/so/search?q=QWidget&spm=1001.2101.3001.7020)
                
            *   ![](https://img-blog.csdnimg.cn/91b6ed81947847199accdff71a0e116f.png)
                
            *   （2）新建cpp文件，也继承自 QWidget
                
            *   ![](https://img-blog.csdnimg.cn/63b7697afd714758b179fd00d5423487.png)
                
            *   结果如下
                
                ![](https://img-blog.csdnimg.cn/bd588043346a4153972e084fd771acf9.png)
                
                （3）因为是按钮，就不能继承QWidget，需要改成继承QPushButton
            *   改三处：头文件中的include名、头文件中的继承对象、源文件父类对象都改成[QPushButton](https://so.csdn.net/so/search?q=QPushButton&spm=1001.2101.3001.7020)
                
            *   ![](https://img-blog.csdnimg.cn/06cc5233ac814abba9dd7f4b84b332c3.png)
                
            *   ![](https://img-blog.csdnimg.cn/3c45d31a9d014df7abab00133fb3d1db.png)
                
                （4）给QMyPushButton添加析构函数，并实现
                
                ![](https://img-blog.csdnimg.cn/88976072b8574fffbd8c808cd289c1ed.png)
                
                ![](https://img-blog.csdnimg.cn/8a5d71cb39a9419ca36065022ed6d028.png)
                
                （5）测试
                
                ![](https://img-blog.csdnimg.cn/b47fdc88d5474a28aae5b9332316650a.png)
                
                 
                
                ```cpp
                // 测试析构函数
                QMyPushButton* mybtn = new QMyPushButton;
                mybtn->setParent(this);
                mybtn->move(0, 300);
                mybtn->setText("我的按钮");
                ```
                
                （6）运行，并关掉窗口
                
                ![](https://img-blog.csdnimg.cn/d69e029067af4e66b54d3533a1c5f97a.png)
                
                析构函数被调用，说明系统会自动调用析构。
                
                （7）如果给QWidget析构函数中输出一句话，哪句话先输出？
                
                这里先理一下类之间的关系。
                
                ![](https://img-blog.csdnimg.cn/14b1090b00ea416ea61f8cb9e7a8010f.png)
                
                ![](https://img-blog.csdnimg.cn/8f54bcdfa8c44ff69316a78ec7faee0b.png)
                
                也就是说QPushButton是QWdiget子类的子类。
                
                而自定义的QMyPushButton是QPushButton的子类。
                
                **按照c++对象的初始化个析构规则，构造时，先构造父类对象，在构造子类对象；而析构时则正好相反；即应该先析构QMyPushButton对象，再析构QWdiget对象**
                
                **测试**
                
                ![](https://img-blog.csdnimg.cn/48e34c89a9b04b13afdf96b984df7da7.png)会发现和预想的不一样。
                
                **这是因为这些对象构造时都在对象树上（未必是二叉树），父类是父结点，子类是子节点。**
                
                **而析构的时候，则是从树根开始调用析构，调用析构函数（析构中如果有输出，则输出），但是此时并没有销毁对象，一直析构到叶子节点，最后再由下之上的销毁对象，所以会出现【先销毁父类对象，后销毁子类对象】的错觉。**

本文转自 <https://blog.csdn.net/Zhouzi_heng/article/details/125362825>，如有侵权，请联系删除。