#ifndef MYTEST_H
#define MYTEST_H

#include <QWidget>

class MyTest : public QWidget
{
    Q_OBJECT

public:
    MyTest(QWidget *parent = nullptr);
    ~MyTest();
};
#endif // MYTEST_H
