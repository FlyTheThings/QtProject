/********************************************************************************
** Form generated from reading UI file 'dialogconfigure.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGCONFIGURE_H
#define UI_DIALOGCONFIGURE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QDialogConfigure
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QGridLayout *gridLayout_18;
    QPushButton *pushButton_controlset;
    QPushButton *pushButton_rpmset;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_selflyset;
    QPushButton *pushButton_tiltset;
    QPushButton *pushButton_ailset;
    QPushButton *pushButton_install;
    QPushButton *pushButton_spayset;
    QPushButton *pushButton_rcset;
    QPushButton *pushButton_anologset;
    QStackedWidget *stackedWidget;

    void setupUi(QDialog *QDialogConfigure)
    {
        if (QDialogConfigure->objectName().isEmpty())
            QDialogConfigure->setObjectName(QStringLiteral("QDialogConfigure"));
        QDialogConfigure->resize(1097, 701);
        scrollArea = new QScrollArea(QDialogConfigure);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(0, 0, 180, 697));
        scrollArea->setMinimumSize(QSize(180, 0));
        scrollArea->setMaximumSize(QSize(180, 16777215));
        QFont font;
        font.setPointSize(9);
        scrollArea->setFont(font);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 178, 695));
        gridLayout_18 = new QGridLayout(scrollAreaWidgetContents_2);
        gridLayout_18->setObjectName(QStringLiteral("gridLayout_18"));
        pushButton_controlset = new QPushButton(scrollAreaWidgetContents_2);
        pushButton_controlset->setObjectName(QStringLiteral("pushButton_controlset"));
        pushButton_controlset->setMaximumSize(QSize(210, 16777215));
        QIcon icon;
        icon.addFile(QStringLiteral(":/qfi/images/ask.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_controlset->setIcon(icon);
        pushButton_controlset->setIconSize(QSize(50, 30));

        gridLayout_18->addWidget(pushButton_controlset, 7, 0, 1, 1);

        pushButton_rpmset = new QPushButton(scrollAreaWidgetContents_2);
        pushButton_rpmset->setObjectName(QStringLiteral("pushButton_rpmset"));
        pushButton_rpmset->setMaximumSize(QSize(210, 16777215));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/qfi/images/sensors.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_rpmset->setIcon(icon1);
        pushButton_rpmset->setIconSize(QSize(50, 30));

        gridLayout_18->addWidget(pushButton_rpmset, 5, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_18->addItem(verticalSpacer, 11, 0, 1, 1);

        pushButton_selflyset = new QPushButton(scrollAreaWidgetContents_2);
        pushButton_selflyset->setObjectName(QStringLiteral("pushButton_selflyset"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_selflyset->sizePolicy().hasHeightForWidth());
        pushButton_selflyset->setSizePolicy(sizePolicy);
        pushButton_selflyset->setMaximumSize(QSize(150, 16777215));
        pushButton_selflyset->setFont(font);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/qfi/images/airplane.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_selflyset->setIcon(icon2);
        pushButton_selflyset->setIconSize(QSize(50, 30));

        gridLayout_18->addWidget(pushButton_selflyset, 9, 0, 1, 1);

        pushButton_tiltset = new QPushButton(scrollAreaWidgetContents_2);
        pushButton_tiltset->setObjectName(QStringLiteral("pushButton_tiltset"));
        pushButton_tiltset->setMaximumSize(QSize(210, 16777215));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/qfi/images/HE32.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_tiltset->setIcon(icon3);
        pushButton_tiltset->setIconSize(QSize(50, 30));

        gridLayout_18->addWidget(pushButton_tiltset, 3, 0, 1, 1);

        pushButton_ailset = new QPushButton(scrollAreaWidgetContents_2);
        pushButton_ailset->setObjectName(QStringLiteral("pushButton_ailset"));
        pushButton_ailset->setMaximumSize(QSize(210, 16777215));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/qfi/images/donate.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_ailset->setIcon(icon4);
        pushButton_ailset->setIconSize(QSize(50, 30));

        gridLayout_18->addWidget(pushButton_ailset, 4, 0, 1, 1);

        pushButton_install = new QPushButton(scrollAreaWidgetContents_2);
        pushButton_install->setObjectName(QStringLiteral("pushButton_install"));
        pushButton_install->setMaximumSize(QSize(150, 16777215));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/qfi/images/set.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_install->setIcon(icon5);
        pushButton_install->setIconSize(QSize(50, 30));

        gridLayout_18->addWidget(pushButton_install, 1, 0, 1, 1);

        pushButton_spayset = new QPushButton(scrollAreaWidgetContents_2);
        pushButton_spayset->setObjectName(QStringLiteral("pushButton_spayset"));
        pushButton_spayset->setMaximumSize(QSize(210, 16777215));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/qfi/images/simulation.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_spayset->setIcon(icon6);
        pushButton_spayset->setIconSize(QSize(50, 30));

        gridLayout_18->addWidget(pushButton_spayset, 8, 0, 1, 1);

        pushButton_rcset = new QPushButton(scrollAreaWidgetContents_2);
        pushButton_rcset->setObjectName(QStringLiteral("pushButton_rcset"));
        pushButton_rcset->setMaximumSize(QSize(210, 16777215));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/qfi/images/remote1.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_rcset->setIcon(icon7);
        pushButton_rcset->setIconSize(QSize(50, 30));

        gridLayout_18->addWidget(pushButton_rcset, 6, 0, 1, 1);

        pushButton_anologset = new QPushButton(scrollAreaWidgetContents_2);
        pushButton_anologset->setObjectName(QStringLiteral("pushButton_anologset"));
        sizePolicy.setHeightForWidth(pushButton_anologset->sizePolicy().hasHeightForWidth());
        pushButton_anologset->setSizePolicy(sizePolicy);
        pushButton_anologset->setMaximumSize(QSize(150, 16777215));
        pushButton_anologset->setFont(font);
        pushButton_anologset->setIcon(icon2);
        pushButton_anologset->setIconSize(QSize(50, 30));

        gridLayout_18->addWidget(pushButton_anologset, 10, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents_2);
        stackedWidget = new QStackedWidget(QDialogConfigure);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(185, 10, 881, 595));
        stackedWidget->setMinimumSize(QSize(827, 595));
        stackedWidget->setFont(font);

        retranslateUi(QDialogConfigure);

        stackedWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(QDialogConfigure);
    } // setupUi

    void retranslateUi(QDialog *QDialogConfigure)
    {
        QDialogConfigure->setWindowTitle(QApplication::translate("QDialogConfigure", "Dialog", 0));
        pushButton_controlset->setText(QApplication::translate("QDialogConfigure", "\346\216\247\345\210\266\345\276\213\351\205\215\347\275\256", 0));
        pushButton_rpmset->setText(QApplication::translate("QDialogConfigure", "RPM/\347\275\227\347\233\230\351\205\215\347\275\256", 0));
        pushButton_selflyset->setText(QApplication::translate("QDialogConfigure", "\350\207\252\351\251\276\345\217\202\346\225\260\351\205\215\347\275\256", 0));
        pushButton_tiltset->setText(QApplication::translate("QDialogConfigure", "\345\215\201\345\255\227\347\233\230\351\205\215\347\275\256", 0));
        pushButton_ailset->setText(QApplication::translate("QDialogConfigure", "\345\211\257\347\277\274/\351\224\201\345\260\276\351\205\215\347\275\256", 0));
        pushButton_install->setText(QApplication::translate("QDialogConfigure", "\350\256\276\345\244\207\345\256\211\350\243\205", 0));
        pushButton_spayset->setText(QApplication::translate("QDialogConfigure", "\345\226\267\346\264\222\347\263\273\347\273\237\351\205\215\347\275\256", 0));
        pushButton_rcset->setText(QApplication::translate("QDialogConfigure", "RC\351\205\215\347\275\256", 0));
        pushButton_anologset->setText(QApplication::translate("QDialogConfigure", "\346\250\241\346\213\237\351\207\217\346\240\207\345\256\232", 0));
    } // retranslateUi

};

namespace Ui {
    class QDialogConfigure: public Ui_QDialogConfigure {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGCONFIGURE_H
