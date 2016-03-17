/********************************************************************************
** Form generated from reading UI file 'framDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRAMDIALOG_H
#define UI_FRAMDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frameDialog
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;

    void setupUi(QWidget *frameDialog)
    {
        if (frameDialog->objectName().isEmpty())
            frameDialog->setObjectName(QStringLiteral("frameDialog"));
        frameDialog->resize(500, 350);
        pushButton = new QPushButton(frameDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 10, 100, 100));
        pushButton->setStyleSheet(QLatin1String("QPushButton:hover{background-color: rgb(255,160,200);}\n"
"QPushButton:focus{background-color: rgb(255,49,80);}\n"
"QPushButton{border-top-left-radius:10px;\n"
"			border-top-right-radius:10px;\n"
"			border-bottom-left-radius:10px;\n"
"			border-bottom-right-radius:10px;\n"
"			background-color: rgb(200,200,200)}\n"
"\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/IY\345\236\213\345\205\261\350\275\264\345\217\214\346\241\250\345\205\255\346\227\213\347\277\274.PNG"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(95, 95));
        pushButton->setFlat(false);
        pushButton_2 = new QPushButton(frameDialog);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(130, 10, 100, 100));
        pushButton_2->setStyleSheet(QLatin1String("QPushButton:hover{background-color: rgb(255,160,200);}\n"
"QPushButton:focus{background-color: rgb(255,49,80);}\n"
"QPushButton{border-top-left-radius:10px;\n"
"			border-top-right-radius:10px;\n"
"			border-bottom-left-radius:10px;\n"
"			border-bottom-right-radius:10px;\n"
"			background-color: rgb(200,200,200)}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/Y\345\236\213\345\205\261\350\275\264\345\217\214\346\241\250\345\205\255\346\227\213\347\277\274.PNG"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon1);
        pushButton_2->setIconSize(QSize(95, 95));
        pushButton_3 = new QPushButton(frameDialog);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(250, 10, 100, 100));
        pushButton_3->setStyleSheet(QLatin1String("QPushButton:hover{background-color: rgb(255,160,200);}\n"
"QPushButton:focus{background-color: rgb(255,49,80);}\n"
"QPushButton{border-top-left-radius:10px;\n"
"			border-top-right-radius:10px;\n"
"			border-bottom-left-radius:10px;\n"
"			border-bottom-right-radius:10px;\n"
"			background-color: rgb(200,200,200)}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/I\345\236\213\345\233\233\346\227\213\347\277\274.PNG"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon2);
        pushButton_3->setIconSize(QSize(95, 95));
        pushButton_4 = new QPushButton(frameDialog);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(370, 10, 100, 100));
        pushButton_4->setStyleSheet(QLatin1String("QPushButton:hover{background-color: rgb(255,160,200);}\n"
"QPushButton:focus{background-color: rgb(255,49,80);}\n"
"QPushButton{border-top-left-radius:10px;\n"
"			border-top-right-radius:10px;\n"
"			border-bottom-left-radius:10px;\n"
"			border-bottom-right-radius:10px;\n"
"			background-color: rgb(200,200,200)}"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/X\345\236\213\345\233\233\346\227\213\347\277\274.PNG"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon3);
        pushButton_4->setIconSize(QSize(95, 95));
        pushButton_5 = new QPushButton(frameDialog);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(10, 120, 100, 100));
        pushButton_5->setStyleSheet(QLatin1String("QPushButton:hover{background-color: rgb(255,160,200);}\n"
"QPushButton:focus{background-color: rgb(255,49,80);}\n"
"QPushButton{border-top-left-radius:10px;\n"
"			border-top-right-radius:10px;\n"
"			border-bottom-left-radius:10px;\n"
"			border-bottom-right-radius:10px;\n"
"			background-color: rgb(200,200,200)}"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/I\345\236\213\345\205\261\350\275\264\345\217\214\346\241\250\345\205\253\346\227\213\347\277\274.PNG"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_5->setIcon(icon4);
        pushButton_5->setIconSize(QSize(95, 95));
        pushButton_6 = new QPushButton(frameDialog);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(130, 120, 100, 100));
        pushButton_6->setStyleSheet(QLatin1String("QPushButton:hover{background-color: rgb(255,160,200);}\n"
"QPushButton:focus{background-color: rgb(255,49,80);}\n"
"QPushButton{border-top-left-radius:10px;\n"
"			border-top-right-radius:10px;\n"
"			border-bottom-left-radius:10px;\n"
"			border-bottom-right-radius:10px;\n"
"			background-color: rgb(200,200,200)}"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/X\345\236\213\345\205\261\350\275\264\345\217\214\346\241\250\345\205\253\346\227\213\347\277\274.PNG"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_6->setIcon(icon5);
        pushButton_6->setIconSize(QSize(95, 95));
        pushButton_7 = new QPushButton(frameDialog);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(250, 120, 100, 100));
        pushButton_7->setStyleSheet(QLatin1String("QPushButton:hover{background-color: rgb(255,160,200);}\n"
"QPushButton:focus{background-color: rgb(255,49,80);}\n"
"QPushButton{border-top-left-radius:10px;\n"
"			border-top-right-radius:10px;\n"
"			border-bottom-left-radius:10px;\n"
"			border-bottom-right-radius:10px;\n"
"			background-color: rgb(200,200,200)}"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/I\345\236\213\345\205\255\346\227\213\347\277\274.PNG"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_7->setIcon(icon6);
        pushButton_7->setIconSize(QSize(95, 95));
        pushButton_8 = new QPushButton(frameDialog);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(370, 120, 100, 100));
        pushButton_8->setStyleSheet(QLatin1String("QPushButton:hover{background-color: rgb(255,160,200);}\n"
"QPushButton:focus{background-color: rgb(255,49,80);}\n"
"QPushButton{border-top-left-radius:10px;\n"
"			border-top-right-radius:10px;\n"
"			border-bottom-left-radius:10px;\n"
"			border-bottom-right-radius:10px;\n"
"			background-color: rgb(200,200,200)}"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/V\345\236\213\345\205\255\346\227\213\347\277\274.PNG"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_8->setIcon(icon7);
        pushButton_8->setIconSize(QSize(95, 95));
        pushButton_9 = new QPushButton(frameDialog);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(10, 230, 100, 100));
        pushButton_9->setStyleSheet(QLatin1String("QPushButton:hover{background-color: rgb(255,160,200);}\n"
"QPushButton:focus{background-color: rgb(255,49,80);}\n"
"QPushButton{border-top-left-radius:10px;\n"
"			border-top-right-radius:10px;\n"
"			border-bottom-left-radius:10px;\n"
"			border-bottom-right-radius:10px;\n"
"			background-color: rgb(200,200,200)}"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/I\345\236\213\345\205\253\346\227\213\347\277\274.PNG"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_9->setIcon(icon8);
        pushButton_9->setIconSize(QSize(95, 95));
        pushButton_10 = new QPushButton(frameDialog);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setGeometry(QRect(130, 230, 100, 100));
        pushButton_10->setStyleSheet(QLatin1String("QPushButton:hover{background-color: rgb(255,160,200);}\n"
"QPushButton:focus{background-color: rgb(255,49,80);}\n"
"QPushButton{border-top-left-radius:10px;\n"
"			border-top-right-radius:10px;\n"
"			border-bottom-left-radius:10px;\n"
"			border-bottom-right-radius:10px;\n"
"			background-color: rgb(200,200,200)}"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/V\345\236\213\345\205\253\346\227\213\347\277\274.PNG"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_10->setIcon(icon9);
        pushButton_10->setIconSize(QSize(95, 95));

        retranslateUi(frameDialog);

        QMetaObject::connectSlotsByName(frameDialog);
    } // setupUi

    void retranslateUi(QWidget *frameDialog)
    {
        frameDialog->setWindowTitle(QApplication::translate("frameDialog", "Form", 0));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        pushButton_4->setText(QString());
        pushButton_5->setText(QString());
        pushButton_6->setText(QString());
        pushButton_7->setText(QString());
        pushButton_8->setText(QString());
        pushButton_9->setText(QString());
        pushButton_10->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class frameDialog: public Ui_frameDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRAMDIALOG_H
