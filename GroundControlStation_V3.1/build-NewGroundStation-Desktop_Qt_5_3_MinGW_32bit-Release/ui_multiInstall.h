/********************************************************************************
** Form generated from reading UI file 'multiInstall.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MULTIINSTALL_H
#define UI_MULTIINSTALL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_multiInstallDialog
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QGroupBox *groupBox_2;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit__IMU_POSSETX;
    QLineEdit *lineEdit__IMU_POSSETY;
    QLineEdit *lineEdit__IMU_POSSETZ;
    QPushButton *pushButton__IMU_POSSET;
    QPushButton *pushButton_IMU_POSASK;
    QGroupBox *groupBox_3;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *lineEdit_GPS_POSSETX;
    QLineEdit *lineEdit_GPS_POSSETY;
    QLineEdit *lineEdit_GPS_POSSETZ;
    QPushButton *pushButton__GPS_POSSET;
    QPushButton *pushButton__GPS_POSASK;

    void setupUi(QWidget *multiInstallDialog)
    {
        if (multiInstallDialog->objectName().isEmpty())
            multiInstallDialog->setObjectName(QStringLiteral("multiInstallDialog"));
        multiInstallDialog->resize(500, 350);
        groupBox = new QGroupBox(multiInstallDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(0, 5, 500, 350));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 15, 300, 340));
        label->setPixmap(QPixmap(QString::fromUtf8(":/qfi/images/devicepos.png")));
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(330, 10, 150, 160));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 30, 20, 20));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 80, 20, 20));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 130, 20, 20));
        lineEdit__IMU_POSSETX = new QLineEdit(groupBox_2);
        lineEdit__IMU_POSSETX->setObjectName(QStringLiteral("lineEdit__IMU_POSSETX"));
        lineEdit__IMU_POSSETX->setGeometry(QRect(30, 30, 60, 20));
        lineEdit__IMU_POSSETY = new QLineEdit(groupBox_2);
        lineEdit__IMU_POSSETY->setObjectName(QStringLiteral("lineEdit__IMU_POSSETY"));
        lineEdit__IMU_POSSETY->setGeometry(QRect(30, 80, 60, 20));
        lineEdit__IMU_POSSETZ = new QLineEdit(groupBox_2);
        lineEdit__IMU_POSSETZ->setObjectName(QStringLiteral("lineEdit__IMU_POSSETZ"));
        lineEdit__IMU_POSSETZ->setGeometry(QRect(30, 130, 60, 20));
        pushButton__IMU_POSSET = new QPushButton(groupBox_2);
        pushButton__IMU_POSSET->setObjectName(QStringLiteral("pushButton__IMU_POSSET"));
        pushButton__IMU_POSSET->setGeometry(QRect(95, 50, 51, 23));
        pushButton_IMU_POSASK = new QPushButton(groupBox_2);
        pushButton_IMU_POSASK->setObjectName(QStringLiteral("pushButton_IMU_POSASK"));
        pushButton_IMU_POSASK->setGeometry(QRect(95, 100, 51, 23));
        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(330, 180, 150, 160));
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 30, 20, 20));
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 80, 20, 20));
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 130, 20, 20));
        lineEdit_GPS_POSSETX = new QLineEdit(groupBox_3);
        lineEdit_GPS_POSSETX->setObjectName(QStringLiteral("lineEdit_GPS_POSSETX"));
        lineEdit_GPS_POSSETX->setGeometry(QRect(30, 30, 60, 20));
        lineEdit_GPS_POSSETY = new QLineEdit(groupBox_3);
        lineEdit_GPS_POSSETY->setObjectName(QStringLiteral("lineEdit_GPS_POSSETY"));
        lineEdit_GPS_POSSETY->setGeometry(QRect(30, 80, 60, 20));
        lineEdit_GPS_POSSETZ = new QLineEdit(groupBox_3);
        lineEdit_GPS_POSSETZ->setObjectName(QStringLiteral("lineEdit_GPS_POSSETZ"));
        lineEdit_GPS_POSSETZ->setGeometry(QRect(30, 130, 60, 20));
        pushButton__GPS_POSSET = new QPushButton(groupBox_3);
        pushButton__GPS_POSSET->setObjectName(QStringLiteral("pushButton__GPS_POSSET"));
        pushButton__GPS_POSSET->setGeometry(QRect(95, 50, 51, 23));
        pushButton__GPS_POSASK = new QPushButton(groupBox_3);
        pushButton__GPS_POSASK->setObjectName(QStringLiteral("pushButton__GPS_POSASK"));
        pushButton__GPS_POSASK->setGeometry(QRect(95, 100, 51, 23));

        retranslateUi(multiInstallDialog);

        QMetaObject::connectSlotsByName(multiInstallDialog);
    } // setupUi

    void retranslateUi(QWidget *multiInstallDialog)
    {
        multiInstallDialog->setWindowTitle(QApplication::translate("multiInstallDialog", "Form", 0));
        groupBox->setTitle(QApplication::translate("multiInstallDialog", "\345\256\211\350\243\205\344\275\215\347\275\256", 0));
        label->setText(QString());
        groupBox_2->setTitle(QApplication::translate("multiInstallDialog", "IMU", 0));
        label_2->setText(QApplication::translate("multiInstallDialog", "X\350\275\264", 0));
        label_3->setText(QApplication::translate("multiInstallDialog", "Y\350\275\264", 0));
        label_4->setText(QApplication::translate("multiInstallDialog", "Z\350\275\264", 0));
        pushButton__IMU_POSSET->setText(QApplication::translate("multiInstallDialog", "\350\256\276\347\275\256", 0));
        pushButton_IMU_POSASK->setText(QApplication::translate("multiInstallDialog", "\346\237\245\350\257\242", 0));
        groupBox_3->setTitle(QApplication::translate("multiInstallDialog", "GPS", 0));
        label_5->setText(QApplication::translate("multiInstallDialog", "X\350\275\264", 0));
        label_6->setText(QApplication::translate("multiInstallDialog", "Y\350\275\264", 0));
        label_7->setText(QApplication::translate("multiInstallDialog", "Z\350\275\264", 0));
        pushButton__GPS_POSSET->setText(QApplication::translate("multiInstallDialog", "\350\256\276\347\275\256", 0));
        pushButton__GPS_POSASK->setText(QApplication::translate("multiInstallDialog", "\346\237\245\350\257\242", 0));
    } // retranslateUi

};

namespace Ui {
    class multiInstallDialog: public Ui_multiInstallDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MULTIINSTALL_H
