/********************************************************************************
** Form generated from reading UI file 'analogwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANALOGWIDGET_H
#define UI_ANALOGWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_analogWidget
{
public:
    QLabel *label_7;
    QLabel *label_6;
    QLabel *label_5;
    QLabel *label_8;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_Vol_CH0;
    QLineEdit *lineEdit_Ratio_CH0;
    QLineEdit *lineEdit_Offset_CH0;
    QLineEdit *lineEdit_Val_CH0;
    QPushButton *pushButton_Set_CH0;
    QPushButton *pushButton_Ask_CH0;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_Vol_CH1;
    QLineEdit *lineEdit_Ratio_CH1;
    QLineEdit *lineEdit_Offset_CH1;
    QLineEdit *lineEdit_Val_CH1;
    QPushButton *pushButton_Set_CH1;
    QPushButton *pushButton_Ask_CH1;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEdit_Vol_CH2;
    QLineEdit *lineEdit_Ratio_CH2;
    QLineEdit *lineEdit_Offset_CH2;
    QLineEdit *lineEdit_Val_CH2;
    QPushButton *pushButton_Set_CH2;
    QPushButton *pushButton_Ask_CH2;
    QWidget *widget3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *lineEdit_Vol_CH3;
    QLineEdit *lineEdit_Ratio_CH3;
    QLineEdit *lineEdit_Offset_CH3;
    QLineEdit *lineEdit_Val_CH3;
    QPushButton *pushButton_Set_CH3;
    QPushButton *pushButton_Ask_CH3;

    void setupUi(QWidget *analogWidget)
    {
        if (analogWidget->objectName().isEmpty())
            analogWidget->setObjectName(QStringLiteral("analogWidget"));
        analogWidget->resize(492, 300);
        label_7 = new QLabel(analogWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(167, 19, 36, 16));
        label_6 = new QLabel(analogWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(114, 19, 24, 16));
        label_5 = new QLabel(analogWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(55, 19, 48, 16));
        label_8 = new QLabel(analogWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(227, 19, 36, 16));
        widget = new QWidget(analogWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 40, 431, 25));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit_Vol_CH0 = new QLineEdit(widget);
        lineEdit_Vol_CH0->setObjectName(QStringLiteral("lineEdit_Vol_CH0"));

        horizontalLayout->addWidget(lineEdit_Vol_CH0);

        lineEdit_Ratio_CH0 = new QLineEdit(widget);
        lineEdit_Ratio_CH0->setObjectName(QStringLiteral("lineEdit_Ratio_CH0"));

        horizontalLayout->addWidget(lineEdit_Ratio_CH0);

        lineEdit_Offset_CH0 = new QLineEdit(widget);
        lineEdit_Offset_CH0->setObjectName(QStringLiteral("lineEdit_Offset_CH0"));

        horizontalLayout->addWidget(lineEdit_Offset_CH0);

        lineEdit_Val_CH0 = new QLineEdit(widget);
        lineEdit_Val_CH0->setObjectName(QStringLiteral("lineEdit_Val_CH0"));

        horizontalLayout->addWidget(lineEdit_Val_CH0);

        pushButton_Set_CH0 = new QPushButton(widget);
        pushButton_Set_CH0->setObjectName(QStringLiteral("pushButton_Set_CH0"));

        horizontalLayout->addWidget(pushButton_Set_CH0);

        pushButton_Ask_CH0 = new QPushButton(widget);
        pushButton_Ask_CH0->setObjectName(QStringLiteral("pushButton_Ask_CH0"));

        horizontalLayout->addWidget(pushButton_Ask_CH0);

        widget1 = new QWidget(analogWidget);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(0, 70, 431, 25));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget1);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit_Vol_CH1 = new QLineEdit(widget1);
        lineEdit_Vol_CH1->setObjectName(QStringLiteral("lineEdit_Vol_CH1"));

        horizontalLayout_2->addWidget(lineEdit_Vol_CH1);

        lineEdit_Ratio_CH1 = new QLineEdit(widget1);
        lineEdit_Ratio_CH1->setObjectName(QStringLiteral("lineEdit_Ratio_CH1"));

        horizontalLayout_2->addWidget(lineEdit_Ratio_CH1);

        lineEdit_Offset_CH1 = new QLineEdit(widget1);
        lineEdit_Offset_CH1->setObjectName(QStringLiteral("lineEdit_Offset_CH1"));

        horizontalLayout_2->addWidget(lineEdit_Offset_CH1);

        lineEdit_Val_CH1 = new QLineEdit(widget1);
        lineEdit_Val_CH1->setObjectName(QStringLiteral("lineEdit_Val_CH1"));

        horizontalLayout_2->addWidget(lineEdit_Val_CH1);

        pushButton_Set_CH1 = new QPushButton(widget1);
        pushButton_Set_CH1->setObjectName(QStringLiteral("pushButton_Set_CH1"));

        horizontalLayout_2->addWidget(pushButton_Set_CH1);

        pushButton_Ask_CH1 = new QPushButton(widget1);
        pushButton_Ask_CH1->setObjectName(QStringLiteral("pushButton_Ask_CH1"));

        horizontalLayout_2->addWidget(pushButton_Ask_CH1);

        widget2 = new QWidget(analogWidget);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setGeometry(QRect(0, 100, 431, 25));
        horizontalLayout_3 = new QHBoxLayout(widget2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget2);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        lineEdit_Vol_CH2 = new QLineEdit(widget2);
        lineEdit_Vol_CH2->setObjectName(QStringLiteral("lineEdit_Vol_CH2"));

        horizontalLayout_3->addWidget(lineEdit_Vol_CH2);

        lineEdit_Ratio_CH2 = new QLineEdit(widget2);
        lineEdit_Ratio_CH2->setObjectName(QStringLiteral("lineEdit_Ratio_CH2"));

        horizontalLayout_3->addWidget(lineEdit_Ratio_CH2);

        lineEdit_Offset_CH2 = new QLineEdit(widget2);
        lineEdit_Offset_CH2->setObjectName(QStringLiteral("lineEdit_Offset_CH2"));

        horizontalLayout_3->addWidget(lineEdit_Offset_CH2);

        lineEdit_Val_CH2 = new QLineEdit(widget2);
        lineEdit_Val_CH2->setObjectName(QStringLiteral("lineEdit_Val_CH2"));

        horizontalLayout_3->addWidget(lineEdit_Val_CH2);

        pushButton_Set_CH2 = new QPushButton(widget2);
        pushButton_Set_CH2->setObjectName(QStringLiteral("pushButton_Set_CH2"));

        horizontalLayout_3->addWidget(pushButton_Set_CH2);

        pushButton_Ask_CH2 = new QPushButton(widget2);
        pushButton_Ask_CH2->setObjectName(QStringLiteral("pushButton_Ask_CH2"));

        horizontalLayout_3->addWidget(pushButton_Ask_CH2);

        widget3 = new QWidget(analogWidget);
        widget3->setObjectName(QStringLiteral("widget3"));
        widget3->setGeometry(QRect(0, 130, 431, 25));
        horizontalLayout_4 = new QHBoxLayout(widget3);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(widget3);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        lineEdit_Vol_CH3 = new QLineEdit(widget3);
        lineEdit_Vol_CH3->setObjectName(QStringLiteral("lineEdit_Vol_CH3"));

        horizontalLayout_4->addWidget(lineEdit_Vol_CH3);

        lineEdit_Ratio_CH3 = new QLineEdit(widget3);
        lineEdit_Ratio_CH3->setObjectName(QStringLiteral("lineEdit_Ratio_CH3"));

        horizontalLayout_4->addWidget(lineEdit_Ratio_CH3);

        lineEdit_Offset_CH3 = new QLineEdit(widget3);
        lineEdit_Offset_CH3->setObjectName(QStringLiteral("lineEdit_Offset_CH3"));

        horizontalLayout_4->addWidget(lineEdit_Offset_CH3);

        lineEdit_Val_CH3 = new QLineEdit(widget3);
        lineEdit_Val_CH3->setObjectName(QStringLiteral("lineEdit_Val_CH3"));

        horizontalLayout_4->addWidget(lineEdit_Val_CH3);

        pushButton_Set_CH3 = new QPushButton(widget3);
        pushButton_Set_CH3->setObjectName(QStringLiteral("pushButton_Set_CH3"));

        horizontalLayout_4->addWidget(pushButton_Set_CH3);

        pushButton_Ask_CH3 = new QPushButton(widget3);
        pushButton_Ask_CH3->setObjectName(QStringLiteral("pushButton_Ask_CH3"));

        horizontalLayout_4->addWidget(pushButton_Ask_CH3);


        retranslateUi(analogWidget);

        QMetaObject::connectSlotsByName(analogWidget);
    } // setupUi

    void retranslateUi(QWidget *analogWidget)
    {
        analogWidget->setWindowTitle(QApplication::translate("analogWidget", "Form", 0));
        label_7->setText(QApplication::translate("analogWidget", "\345\201\217\347\247\273\351\207\217", 0));
        label_6->setText(QApplication::translate("analogWidget", "\345\242\236\347\233\212", 0));
        label_5->setText(QApplication::translate("analogWidget", "\351\207\207\346\240\267\347\224\265\345\216\213", 0));
        label_8->setText(QApplication::translate("analogWidget", "\347\211\251\347\220\206\351\207\217", 0));
        label->setText(QApplication::translate("analogWidget", "\351\200\232\351\201\2230\357\274\232", 0));
        pushButton_Set_CH0->setText(QApplication::translate("analogWidget", "\350\256\276\347\275\256", 0));
        pushButton_Ask_CH0->setText(QApplication::translate("analogWidget", "\346\237\245\350\257\242", 0));
        label_2->setText(QApplication::translate("analogWidget", "\351\200\232\351\201\2231\357\274\232", 0));
        pushButton_Set_CH1->setText(QApplication::translate("analogWidget", "\350\256\276\347\275\256", 0));
        pushButton_Ask_CH1->setText(QApplication::translate("analogWidget", "\346\237\245\350\257\242", 0));
        label_3->setText(QApplication::translate("analogWidget", "\351\200\232\351\201\2232\357\274\232", 0));
        pushButton_Set_CH2->setText(QApplication::translate("analogWidget", "\350\256\276\347\275\256", 0));
        pushButton_Ask_CH2->setText(QApplication::translate("analogWidget", "\346\237\245\350\257\242", 0));
        label_4->setText(QApplication::translate("analogWidget", "\351\200\232\351\201\2233\357\274\232", 0));
        pushButton_Set_CH3->setText(QApplication::translate("analogWidget", "\350\256\276\347\275\256", 0));
        pushButton_Ask_CH3->setText(QApplication::translate("analogWidget", "\346\237\245\350\257\242", 0));
    } // retranslateUi

};

namespace Ui {
    class analogWidget: public Ui_analogWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANALOGWIDGET_H
