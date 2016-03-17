/********************************************************************************
** Form generated from reading UI file 'multianalogcfgwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MULTIANALOGCFGWIDGET_H
#define UI_MULTIANALOGCFGWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_multiAnalogCfgWidget
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit_Vol_CH0;
    QLineEdit *lineEdit_Vol_CH1;
    QLineEdit *lineEdit_Vol_CH2;
    QLineEdit *lineEdit_Vol_CH3;
    QLineEdit *lineEdit_Ratio_CH2;
    QLineEdit *lineEdit_Ratio_CH3;
    QLineEdit *lineEdit_Ratio_CH0;
    QLineEdit *lineEdit_Ratio_CH1;
    QLineEdit *lineEdit_Offset_CH0;
    QLineEdit *lineEdit_Offset_CH3;
    QLineEdit *lineEdit_Offset_CH2;
    QLineEdit *lineEdit_Offset_CH1;
    QLineEdit *lineEdit_Val_CH0;
    QLineEdit *lineEdit_Val_CH3;
    QLineEdit *lineEdit_Val_CH1;
    QLineEdit *lineEdit_Val_CH2;
    QPushButton *pushButton_Set_CH0;
    QPushButton *pushButton_Ask_CH0;
    QPushButton *pushButton_Ask_CH1;
    QPushButton *pushButton_Set_CH1;
    QPushButton *pushButton_Ask_CH2;
    QPushButton *pushButton_Set_CH2;
    QPushButton *pushButton_Ask_CH3;
    QPushButton *pushButton_Set_CH3;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;

    void setupUi(QWidget *multiAnalogCfgWidget)
    {
        if (multiAnalogCfgWidget->objectName().isEmpty())
            multiAnalogCfgWidget->setObjectName(QStringLiteral("multiAnalogCfgWidget"));
        multiAnalogCfgWidget->resize(370, 152);
        label = new QLabel(multiAnalogCfgWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(6, 30, 42, 16));
        label_2 = new QLabel(multiAnalogCfgWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(6, 59, 42, 16));
        label_3 = new QLabel(multiAnalogCfgWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(6, 88, 42, 16));
        label_4 = new QLabel(multiAnalogCfgWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(6, 117, 42, 16));
        lineEdit_Vol_CH0 = new QLineEdit(multiAnalogCfgWidget);
        lineEdit_Vol_CH0->setObjectName(QStringLiteral("lineEdit_Vol_CH0"));
        lineEdit_Vol_CH0->setGeometry(QRect(54, 31, 50, 20));
        lineEdit_Vol_CH1 = new QLineEdit(multiAnalogCfgWidget);
        lineEdit_Vol_CH1->setObjectName(QStringLiteral("lineEdit_Vol_CH1"));
        lineEdit_Vol_CH1->setGeometry(QRect(54, 60, 50, 20));
        lineEdit_Vol_CH2 = new QLineEdit(multiAnalogCfgWidget);
        lineEdit_Vol_CH2->setObjectName(QStringLiteral("lineEdit_Vol_CH2"));
        lineEdit_Vol_CH2->setGeometry(QRect(54, 89, 50, 20));
        lineEdit_Vol_CH3 = new QLineEdit(multiAnalogCfgWidget);
        lineEdit_Vol_CH3->setObjectName(QStringLiteral("lineEdit_Vol_CH3"));
        lineEdit_Vol_CH3->setGeometry(QRect(54, 118, 50, 20));
        lineEdit_Ratio_CH2 = new QLineEdit(multiAnalogCfgWidget);
        lineEdit_Ratio_CH2->setObjectName(QStringLiteral("lineEdit_Ratio_CH2"));
        lineEdit_Ratio_CH2->setGeometry(QRect(110, 89, 50, 20));
        lineEdit_Ratio_CH3 = new QLineEdit(multiAnalogCfgWidget);
        lineEdit_Ratio_CH3->setObjectName(QStringLiteral("lineEdit_Ratio_CH3"));
        lineEdit_Ratio_CH3->setGeometry(QRect(110, 118, 50, 20));
        lineEdit_Ratio_CH0 = new QLineEdit(multiAnalogCfgWidget);
        lineEdit_Ratio_CH0->setObjectName(QStringLiteral("lineEdit_Ratio_CH0"));
        lineEdit_Ratio_CH0->setGeometry(QRect(110, 31, 50, 20));
        lineEdit_Ratio_CH1 = new QLineEdit(multiAnalogCfgWidget);
        lineEdit_Ratio_CH1->setObjectName(QStringLiteral("lineEdit_Ratio_CH1"));
        lineEdit_Ratio_CH1->setGeometry(QRect(110, 60, 50, 20));
        lineEdit_Offset_CH0 = new QLineEdit(multiAnalogCfgWidget);
        lineEdit_Offset_CH0->setObjectName(QStringLiteral("lineEdit_Offset_CH0"));
        lineEdit_Offset_CH0->setGeometry(QRect(166, 31, 51, 20));
        lineEdit_Offset_CH3 = new QLineEdit(multiAnalogCfgWidget);
        lineEdit_Offset_CH3->setObjectName(QStringLiteral("lineEdit_Offset_CH3"));
        lineEdit_Offset_CH3->setGeometry(QRect(166, 118, 51, 20));
        lineEdit_Offset_CH2 = new QLineEdit(multiAnalogCfgWidget);
        lineEdit_Offset_CH2->setObjectName(QStringLiteral("lineEdit_Offset_CH2"));
        lineEdit_Offset_CH2->setGeometry(QRect(166, 89, 51, 20));
        lineEdit_Offset_CH1 = new QLineEdit(multiAnalogCfgWidget);
        lineEdit_Offset_CH1->setObjectName(QStringLiteral("lineEdit_Offset_CH1"));
        lineEdit_Offset_CH1->setGeometry(QRect(166, 60, 51, 20));
        lineEdit_Val_CH0 = new QLineEdit(multiAnalogCfgWidget);
        lineEdit_Val_CH0->setObjectName(QStringLiteral("lineEdit_Val_CH0"));
        lineEdit_Val_CH0->setGeometry(QRect(223, 31, 50, 20));
        lineEdit_Val_CH3 = new QLineEdit(multiAnalogCfgWidget);
        lineEdit_Val_CH3->setObjectName(QStringLiteral("lineEdit_Val_CH3"));
        lineEdit_Val_CH3->setGeometry(QRect(223, 118, 50, 20));
        lineEdit_Val_CH1 = new QLineEdit(multiAnalogCfgWidget);
        lineEdit_Val_CH1->setObjectName(QStringLiteral("lineEdit_Val_CH1"));
        lineEdit_Val_CH1->setGeometry(QRect(223, 60, 50, 20));
        lineEdit_Val_CH2 = new QLineEdit(multiAnalogCfgWidget);
        lineEdit_Val_CH2->setObjectName(QStringLiteral("lineEdit_Val_CH2"));
        lineEdit_Val_CH2->setGeometry(QRect(223, 89, 50, 20));
        pushButton_Set_CH0 = new QPushButton(multiAnalogCfgWidget);
        pushButton_Set_CH0->setObjectName(QStringLiteral("pushButton_Set_CH0"));
        pushButton_Set_CH0->setGeometry(QRect(279, 30, 40, 23));
        pushButton_Ask_CH0 = new QPushButton(multiAnalogCfgWidget);
        pushButton_Ask_CH0->setObjectName(QStringLiteral("pushButton_Ask_CH0"));
        pushButton_Ask_CH0->setGeometry(QRect(320, 30, 40, 23));
        pushButton_Ask_CH1 = new QPushButton(multiAnalogCfgWidget);
        pushButton_Ask_CH1->setObjectName(QStringLiteral("pushButton_Ask_CH1"));
        pushButton_Ask_CH1->setGeometry(QRect(320, 59, 40, 23));
        pushButton_Set_CH1 = new QPushButton(multiAnalogCfgWidget);
        pushButton_Set_CH1->setObjectName(QStringLiteral("pushButton_Set_CH1"));
        pushButton_Set_CH1->setGeometry(QRect(279, 59, 40, 23));
        pushButton_Ask_CH2 = new QPushButton(multiAnalogCfgWidget);
        pushButton_Ask_CH2->setObjectName(QStringLiteral("pushButton_Ask_CH2"));
        pushButton_Ask_CH2->setGeometry(QRect(320, 88, 40, 23));
        pushButton_Set_CH2 = new QPushButton(multiAnalogCfgWidget);
        pushButton_Set_CH2->setObjectName(QStringLiteral("pushButton_Set_CH2"));
        pushButton_Set_CH2->setGeometry(QRect(279, 88, 40, 23));
        pushButton_Ask_CH3 = new QPushButton(multiAnalogCfgWidget);
        pushButton_Ask_CH3->setObjectName(QStringLiteral("pushButton_Ask_CH3"));
        pushButton_Ask_CH3->setGeometry(QRect(320, 117, 40, 23));
        pushButton_Set_CH3 = new QPushButton(multiAnalogCfgWidget);
        pushButton_Set_CH3->setObjectName(QStringLiteral("pushButton_Set_CH3"));
        pushButton_Set_CH3->setGeometry(QRect(279, 117, 40, 23));
        label_5 = new QLabel(multiAnalogCfgWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(58, 9, 48, 16));
        label_6 = new QLabel(multiAnalogCfgWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(117, 9, 24, 16));
        label_7 = new QLabel(multiAnalogCfgWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(170, 9, 36, 16));
        label_8 = new QLabel(multiAnalogCfgWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(230, 9, 36, 16));

        retranslateUi(multiAnalogCfgWidget);

        QMetaObject::connectSlotsByName(multiAnalogCfgWidget);
    } // setupUi

    void retranslateUi(QWidget *multiAnalogCfgWidget)
    {
        multiAnalogCfgWidget->setWindowTitle(QApplication::translate("multiAnalogCfgWidget", "Form", 0));
        label->setText(QApplication::translate("multiAnalogCfgWidget", "\351\200\232\351\201\2230\357\274\232", 0));
        label_2->setText(QApplication::translate("multiAnalogCfgWidget", "\351\200\232\351\201\2231\357\274\232", 0));
        label_3->setText(QApplication::translate("multiAnalogCfgWidget", "\351\200\232\351\201\2232\357\274\232", 0));
        label_4->setText(QApplication::translate("multiAnalogCfgWidget", "\351\200\232\351\201\2233\357\274\232", 0));
        pushButton_Set_CH0->setText(QApplication::translate("multiAnalogCfgWidget", "\350\256\276\347\275\256", 0));
        pushButton_Ask_CH0->setText(QApplication::translate("multiAnalogCfgWidget", "\346\237\245\350\257\242", 0));
        pushButton_Ask_CH1->setText(QApplication::translate("multiAnalogCfgWidget", "\346\237\245\350\257\242", 0));
        pushButton_Set_CH1->setText(QApplication::translate("multiAnalogCfgWidget", "\350\256\276\347\275\256", 0));
        pushButton_Ask_CH2->setText(QApplication::translate("multiAnalogCfgWidget", "\346\237\245\350\257\242", 0));
        pushButton_Set_CH2->setText(QApplication::translate("multiAnalogCfgWidget", "\350\256\276\347\275\256", 0));
        pushButton_Ask_CH3->setText(QApplication::translate("multiAnalogCfgWidget", "\346\237\245\350\257\242", 0));
        pushButton_Set_CH3->setText(QApplication::translate("multiAnalogCfgWidget", "\350\256\276\347\275\256", 0));
        label_5->setText(QApplication::translate("multiAnalogCfgWidget", "\351\207\207\346\240\267\347\224\265\345\216\213", 0));
        label_6->setText(QApplication::translate("multiAnalogCfgWidget", "\345\242\236\347\233\212", 0));
        label_7->setText(QApplication::translate("multiAnalogCfgWidget", "\345\201\217\347\247\273\351\207\217", 0));
        label_8->setText(QApplication::translate("multiAnalogCfgWidget", "\347\211\251\347\220\206\351\207\217", 0));
    } // retranslateUi

};

namespace Ui {
    class multiAnalogCfgWidget: public Ui_multiAnalogCfgWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MULTIANALOGCFGWIDGET_H
