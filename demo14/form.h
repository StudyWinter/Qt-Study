#ifndef FORM_H
#define FORM_H

#include <QWidget>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

    // 设置数据
    void setVal(int val);

    // 获取数据
    int getVal();


private:
    Ui::Form *ui;
};

#endif // FORM_H
