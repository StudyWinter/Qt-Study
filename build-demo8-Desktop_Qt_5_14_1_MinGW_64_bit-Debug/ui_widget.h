/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *pushButton;
    QToolButton *toolButton;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *rBtn_woman;
    QRadioButton *rBtn_man;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QPushButton *commit;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(160, 80, 80, 20));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Luffy.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(16, 16));
        toolButton = new QToolButton(Widget);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(310, 80, 101, 31));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/OnePiece.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon1);
        toolButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        toolButton->setAutoRaise(true);
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(100, 130, 151, 81));
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        rBtn_woman = new QRadioButton(groupBox);
        rBtn_woman->setObjectName(QString::fromUtf8("rBtn_woman"));

        horizontalLayout_2->addWidget(rBtn_woman);

        rBtn_man = new QRadioButton(groupBox);
        rBtn_man->setObjectName(QString::fromUtf8("rBtn_man"));

        horizontalLayout_2->addWidget(rBtn_man);

        groupBox_2 = new QGroupBox(Widget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(340, 130, 161, 91));
        horizontalLayout = new QHBoxLayout(groupBox_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        radioButton_3 = new QRadioButton(groupBox_2);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));

        horizontalLayout->addWidget(radioButton_3);

        radioButton_4 = new QRadioButton(groupBox_2);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));

        horizontalLayout->addWidget(radioButton_4);

        commit = new QPushButton(Widget);
        commit->setObjectName(QString::fromUtf8("commit"));
        commit->setGeometry(QRect(190, 270, 80, 20));
        groupBox_3 = new QGroupBox(Widget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(340, 250, 161, 231));
        verticalLayout = new QVBoxLayout(groupBox_3);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        checkBox = new QCheckBox(groupBox_3);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        verticalLayout->addWidget(checkBox);

        checkBox_2 = new QCheckBox(groupBox_3);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));

        verticalLayout->addWidget(checkBox_2);

        checkBox_3 = new QCheckBox(groupBox_3);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));

        verticalLayout->addWidget(checkBox_3);

        checkBox_4 = new QCheckBox(groupBox_3);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));

        verticalLayout->addWidget(checkBox_4);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "\350\267\257\351\243\236", nullptr));
        toolButton->setText(QCoreApplication::translate("Widget", "123", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Widget", "GroupBox", nullptr));
        rBtn_woman->setText(QCoreApplication::translate("Widget", "\345\245\263", nullptr));
        rBtn_man->setText(QCoreApplication::translate("Widget", "\347\224\267", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Widget", "GroupBox", nullptr));
        radioButton_3->setText(QCoreApplication::translate("Widget", "\345\267\262\345\251\232", nullptr));
        radioButton_4->setText(QCoreApplication::translate("Widget", "\346\234\252\345\251\232", nullptr));
        commit->setText(QCoreApplication::translate("Widget", "\346\217\220\344\272\244", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("Widget", "\350\260\203\346\237\245\351\227\256\345\215\267", nullptr));
        checkBox->setText(QCoreApplication::translate("Widget", "\347\216\257\345\242\203\344\274\230\351\233\205", nullptr));
        checkBox_2->setText(QCoreApplication::translate("Widget", "\344\273\267\346\240\274\345\256\236\346\203\240", nullptr));
        checkBox_3->setText(QCoreApplication::translate("Widget", "\346\234\215\345\212\241\345\221\250\345\210\260", nullptr));
        checkBox_4->setText(QCoreApplication::translate("Widget", "\345\235\220\346\240\207\345\245\275", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
