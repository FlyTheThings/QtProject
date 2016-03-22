/********************************************************************************
** Form generated from reading UI file 'multiCenterDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MULTICENTERDIALOG_H
#define UI_MULTICENTERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_multiCenterDialog
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QPushButton *pushButton_Install;
    QPushButton *pushButton_Frame;
    QPushButton *pushButton_RCCfg;
    QPushButton *pushButton_AutoCfg;
    QPushButton *pushButton_controlset;
    QPushButton *pushButton_analogset;
    QPushButton *pushButton_HMCSet;
    QPushButton *pushButton_slashset;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *page_2;

    void setupUi(QDialog *multiCenterDialog)
    {
        if (multiCenterDialog->objectName().isEmpty())
            multiCenterDialog->setObjectName(QStringLiteral("multiCenterDialog"));
        multiCenterDialog->resize(621, 407);
        scrollArea = new QScrollArea(multiCenterDialog);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(0, 0, 621, 411));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 619, 409));
        scrollArea_2 = new QScrollArea(scrollAreaWidgetContents);
        scrollArea_2->setObjectName(QStringLiteral("scrollArea_2"));
        scrollArea_2->setGeometry(QRect(0, 0, 111, 411));
        scrollArea_2->setStyleSheet(QStringLiteral(""));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 109, 409));
        pushButton_Install = new QPushButton(scrollAreaWidgetContents_2);
        pushButton_Install->setObjectName(QStringLiteral("pushButton_Install"));
        pushButton_Install->setGeometry(QRect(0, 10, 100, 40));
        pushButton_Install->setStyleSheet(QStringLiteral(""));
        QIcon icon;
        icon.addFile(QStringLiteral(":/qfi/images/set.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Install->setIcon(icon);
        pushButton_Frame = new QPushButton(scrollAreaWidgetContents_2);
        pushButton_Frame->setObjectName(QStringLiteral("pushButton_Frame"));
        pushButton_Frame->setGeometry(QRect(0, 60, 100, 40));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/X\345\236\213\345\233\233\346\227\213\347\277\274.PNG"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Frame->setIcon(icon1);
        pushButton_Frame->setIconSize(QSize(32, 16));
        pushButton_RCCfg = new QPushButton(scrollAreaWidgetContents_2);
        pushButton_RCCfg->setObjectName(QStringLiteral("pushButton_RCCfg"));
        pushButton_RCCfg->setGeometry(QRect(0, 160, 100, 41));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/qfi/images/remote1.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_RCCfg->setIcon(icon2);
        pushButton_RCCfg->setIconSize(QSize(50, 30));
        pushButton_AutoCfg = new QPushButton(scrollAreaWidgetContents_2);
        pushButton_AutoCfg->setObjectName(QStringLiteral("pushButton_AutoCfg"));
        pushButton_AutoCfg->setGeometry(QRect(0, 210, 100, 40));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/qfi/images/airplane.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_AutoCfg->setIcon(icon3);
        pushButton_controlset = new QPushButton(scrollAreaWidgetContents_2);
        pushButton_controlset->setObjectName(QStringLiteral("pushButton_controlset"));
        pushButton_controlset->setGeometry(QRect(0, 260, 101, 38));
        pushButton_controlset->setMaximumSize(QSize(210, 16777215));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/qfi/images/ask.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_controlset->setIcon(icon4);
        pushButton_controlset->setIconSize(QSize(50, 30));
        pushButton_analogset = new QPushButton(scrollAreaWidgetContents_2);
        pushButton_analogset->setObjectName(QStringLiteral("pushButton_analogset"));
        pushButton_analogset->setGeometry(QRect(0, 310, 101, 38));
        pushButton_analogset->setMaximumSize(QSize(210, 16777215));
        pushButton_analogset->setIconSize(QSize(50, 30));
        pushButton_HMCSet = new QPushButton(scrollAreaWidgetContents_2);
        pushButton_HMCSet->setObjectName(QStringLiteral("pushButton_HMCSet"));
        pushButton_HMCSet->setGeometry(QRect(0, 110, 101, 38));
        pushButton_HMCSet->setMaximumSize(QSize(210, 16777215));
        pushButton_HMCSet->setIconSize(QSize(50, 30));
        pushButton_slashset = new QPushButton(scrollAreaWidgetContents_2);
        pushButton_slashset->setObjectName(QStringLiteral("pushButton_slashset"));
        pushButton_slashset->setGeometry(QRect(0, 360, 101, 38));
        pushButton_slashset->setMaximumSize(QSize(210, 16777215));
        pushButton_slashset->setIconSize(QSize(50, 30));
        scrollArea_2->setWidget(scrollAreaWidgetContents_2);
        stackedWidget = new QStackedWidget(scrollAreaWidgetContents);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(120, 0, 501, 361));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        stackedWidget->addWidget(page_2);
        scrollArea->setWidget(scrollAreaWidgetContents);

        retranslateUi(multiCenterDialog);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(multiCenterDialog);
    } // setupUi

    void retranslateUi(QDialog *multiCenterDialog)
    {
        multiCenterDialog->setWindowTitle(QApplication::translate("multiCenterDialog", "Dialog", 0));
        pushButton_Install->setText(QApplication::translate("multiCenterDialog", "\345\256\211\350\243\205\346\226\271\345\274\217", 0));
        pushButton_Frame->setText(QApplication::translate("multiCenterDialog", "\346\234\272\346\236\266\351\200\211\346\213\251", 0));
        pushButton_RCCfg->setText(QApplication::translate("multiCenterDialog", "RC\351\205\215\347\275\256", 0));
        pushButton_AutoCfg->setText(QApplication::translate("multiCenterDialog", "\350\207\252\351\251\276\345\217\202\346\225\260\351\205\215\347\275\256", 0));
        pushButton_controlset->setText(QApplication::translate("multiCenterDialog", "\346\216\247\345\210\266\345\276\213\351\205\215\347\275\256", 0));
        pushButton_analogset->setText(QApplication::translate("multiCenterDialog", "\346\250\241\346\213\237\351\207\217\346\240\207\345\256\232", 0));
        pushButton_HMCSet->setText(QApplication::translate("multiCenterDialog", "\347\243\201\345\212\233\350\256\241\346\240\241\345\207\206", 0));
        pushButton_slashset->setText(QApplication::translate("multiCenterDialog", "\345\226\267\346\264\222\347\263\273\347\273\237\351\205\215\347\275\256", 0));
    } // retranslateUi

};

namespace Ui {
    class multiCenterDialog: public Ui_multiCenterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MULTICENTERDIALOG_H
