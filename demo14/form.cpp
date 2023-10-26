#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    // spinBox数字改变，是slider跟着滑动
    // 函数指针
    void(QSpinBox::* spin)(int) = &QSpinBox::valueChanged;
    connect(ui->spinBox, spin, ui->horizontalSlider,&QSlider::setValue);

    // slider移动，spinBox数字跟着变化
    connect(ui->horizontalSlider, &QSlider::valueChanged, ui->spinBox, &QSpinBox::setValue);
}

// 设置函数
void Form::setVal(int val)
{
    ui->horizontalSlider->setValue(val);
}

// 获取函数
int Form::getVal()
{
    return ui->horizontalSlider->value();
}


Form::~Form()
{
    delete ui;
}
