/********************************************************************************
** Form generated from reading UI file 'installwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSTALLWIDGET_H
#define UI_INSTALLWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QInstallWidget
{
public:
    QLabel *label_31;
    QGroupBox *groupBox;
    QGroupBox *groupBox_8;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton__IMU_DIRSET_FRONT;
    QPushButton *pushButton__IMU_DIRSET_BEHIND;
    QPushButton *pushButton__IMU_DIRSET_LEFT;
    QPushButton *pushButton__IMU_DIRSET_RIGHT;
    QGroupBox *groupBox_14;
    QGridLayout *gridLayout_33;
    QPushButton *pushButton__GPS_DIRSET_FRONT;
    QPushButton *pushButton__GPS_DIRSET_BEHIND;
    QPushButton *pushButton__GPS_DIRSET_LEFT;
    QPushButton *pushButton__GPS_DIRSET_RIGHT;
    QLabel *label_176;
    QLabel *label_DEVICE;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_7;
    QGroupBox *groupBox_7;
    QGridLayout *gridLayout_8;
    QLabel *label_36;
    QLineEdit *lineEdit_GPS_POSSETX;
    QLabel *label_37;
    QLineEdit *lineEdit_GPS_POSSETY;
    QLabel *label_38;
    QLineEdit *lineEdit_GPS_POSSETZ;
    QPushButton *pushButton__GPS_POSSET;
    QPushButton *pushButton__GPS_POSASK;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_9;
    QLabel *label_33;
    QLabel *label_34;
    QLineEdit *lineEdit__IMU_POSSETY;
    QLabel *label_35;
    QLineEdit *lineEdit__IMU_POSSETZ;
    QPushButton *pushButton__IMU_POSSET;
    QPushButton *pushButton_IMU_POSASK;
    QLineEdit *lineEdit__IMU_POSSETX;
    QLabel *label_32;

    void setupUi(QWidget *QInstallWidget)
    {
        if (QInstallWidget->objectName().isEmpty())
            QInstallWidget->setObjectName(QStringLiteral("QInstallWidget"));
        QInstallWidget->resize(826, 585);
        label_31 = new QLabel(QInstallWidget);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setGeometry(QRect(220, 492, 16, 16));
        groupBox = new QGroupBox(QInstallWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 0, 381, 141));
        groupBox_8 = new QGroupBox(groupBox);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        groupBox_8->setGeometry(QRect(10, 20, 351, 56));
        groupBox_8->setMaximumSize(QSize(16777215, 56));
        QFont font;
        font.setPointSize(9);
        font.setBold(false);
        font.setItalic(false);
        font.setUnderline(false);
        font.setWeight(50);
        font.setStrikeOut(false);
        font.setStyleStrategy(QFont::PreferDefault);
        groupBox_8->setFont(font);
        gridLayout_3 = new QGridLayout(groupBox_8);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        pushButton__IMU_DIRSET_FRONT = new QPushButton(groupBox_8);
        pushButton__IMU_DIRSET_FRONT->setObjectName(QStringLiteral("pushButton__IMU_DIRSET_FRONT"));
        pushButton__IMU_DIRSET_FRONT->setMinimumSize(QSize(0, 28));
        QIcon icon;
        icon.addFile(QStringLiteral(":/qfi/images/go-up.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton__IMU_DIRSET_FRONT->setIcon(icon);
        pushButton__IMU_DIRSET_FRONT->setIconSize(QSize(20, 20));

        gridLayout_3->addWidget(pushButton__IMU_DIRSET_FRONT, 0, 0, 1, 1);

        pushButton__IMU_DIRSET_BEHIND = new QPushButton(groupBox_8);
        pushButton__IMU_DIRSET_BEHIND->setObjectName(QStringLiteral("pushButton__IMU_DIRSET_BEHIND"));
        pushButton__IMU_DIRSET_BEHIND->setMinimumSize(QSize(0, 28));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/qfi/images/go-down.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton__IMU_DIRSET_BEHIND->setIcon(icon1);
        pushButton__IMU_DIRSET_BEHIND->setIconSize(QSize(20, 20));

        gridLayout_3->addWidget(pushButton__IMU_DIRSET_BEHIND, 0, 1, 1, 1);

        pushButton__IMU_DIRSET_LEFT = new QPushButton(groupBox_8);
        pushButton__IMU_DIRSET_LEFT->setObjectName(QStringLiteral("pushButton__IMU_DIRSET_LEFT"));
        pushButton__IMU_DIRSET_LEFT->setMinimumSize(QSize(0, 28));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/qfi/images/go-previous.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton__IMU_DIRSET_LEFT->setIcon(icon2);
        pushButton__IMU_DIRSET_LEFT->setIconSize(QSize(20, 20));

        gridLayout_3->addWidget(pushButton__IMU_DIRSET_LEFT, 0, 2, 1, 1);

        pushButton__IMU_DIRSET_RIGHT = new QPushButton(groupBox_8);
        pushButton__IMU_DIRSET_RIGHT->setObjectName(QStringLiteral("pushButton__IMU_DIRSET_RIGHT"));
        pushButton__IMU_DIRSET_RIGHT->setMinimumSize(QSize(0, 28));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/qfi/images/go-next.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton__IMU_DIRSET_RIGHT->setIcon(icon3);
        pushButton__IMU_DIRSET_RIGHT->setIconSize(QSize(20, 20));

        gridLayout_3->addWidget(pushButton__IMU_DIRSET_RIGHT, 0, 3, 1, 1);

        groupBox_14 = new QGroupBox(groupBox);
        groupBox_14->setObjectName(QStringLiteral("groupBox_14"));
        groupBox_14->setGeometry(QRect(10, 80, 351, 56));
        groupBox_14->setMaximumSize(QSize(16777215, 56));
        gridLayout_33 = new QGridLayout(groupBox_14);
        gridLayout_33->setObjectName(QStringLiteral("gridLayout_33"));
        pushButton__GPS_DIRSET_FRONT = new QPushButton(groupBox_14);
        pushButton__GPS_DIRSET_FRONT->setObjectName(QStringLiteral("pushButton__GPS_DIRSET_FRONT"));
        pushButton__GPS_DIRSET_FRONT->setMinimumSize(QSize(0, 28));
        pushButton__GPS_DIRSET_FRONT->setIcon(icon);
        pushButton__GPS_DIRSET_FRONT->setIconSize(QSize(20, 20));

        gridLayout_33->addWidget(pushButton__GPS_DIRSET_FRONT, 0, 0, 1, 1);

        pushButton__GPS_DIRSET_BEHIND = new QPushButton(groupBox_14);
        pushButton__GPS_DIRSET_BEHIND->setObjectName(QStringLiteral("pushButton__GPS_DIRSET_BEHIND"));
        pushButton__GPS_DIRSET_BEHIND->setMinimumSize(QSize(0, 28));
        pushButton__GPS_DIRSET_BEHIND->setIcon(icon1);
        pushButton__GPS_DIRSET_BEHIND->setIconSize(QSize(20, 20));

        gridLayout_33->addWidget(pushButton__GPS_DIRSET_BEHIND, 0, 1, 1, 1);

        pushButton__GPS_DIRSET_LEFT = new QPushButton(groupBox_14);
        pushButton__GPS_DIRSET_LEFT->setObjectName(QStringLiteral("pushButton__GPS_DIRSET_LEFT"));
        pushButton__GPS_DIRSET_LEFT->setMinimumSize(QSize(0, 28));
        pushButton__GPS_DIRSET_LEFT->setIcon(icon2);
        pushButton__GPS_DIRSET_LEFT->setIconSize(QSize(20, 20));

        gridLayout_33->addWidget(pushButton__GPS_DIRSET_LEFT, 0, 2, 1, 1);

        pushButton__GPS_DIRSET_RIGHT = new QPushButton(groupBox_14);
        pushButton__GPS_DIRSET_RIGHT->setObjectName(QStringLiteral("pushButton__GPS_DIRSET_RIGHT"));
        pushButton__GPS_DIRSET_RIGHT->setMinimumSize(QSize(0, 28));
        pushButton__GPS_DIRSET_RIGHT->setIcon(icon3);
        pushButton__GPS_DIRSET_RIGHT->setIconSize(QSize(20, 20));

        gridLayout_33->addWidget(pushButton__GPS_DIRSET_RIGHT, 0, 3, 1, 1);

        label_176 = new QLabel(QInstallWidget);
        label_176->setObjectName(QStringLiteral("label_176"));
        label_176->setGeometry(QRect(420, 360, 330, 16));
        label_DEVICE = new QLabel(QInstallWidget);
        label_DEVICE->setObjectName(QStringLiteral("label_DEVICE"));
        label_DEVICE->setGeometry(QRect(400, 0, 411, 321));
        label_DEVICE->setPixmap(QPixmap(QString::fromUtf8(":/qfi/images/devicedir.png")));
        groupBox_3 = new QGroupBox(QInstallWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 150, 381, 440));
        groupBox_3->setMinimumSize(QSize(0, 440));
        gridLayout_7 = new QGridLayout(groupBox_3);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        groupBox_7 = new QGroupBox(groupBox_3);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        gridLayout_8 = new QGridLayout(groupBox_7);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        label_36 = new QLabel(groupBox_7);
        label_36->setObjectName(QStringLiteral("label_36"));

        gridLayout_8->addWidget(label_36, 0, 0, 1, 1);

        lineEdit_GPS_POSSETX = new QLineEdit(groupBox_7);
        lineEdit_GPS_POSSETX->setObjectName(QStringLiteral("lineEdit_GPS_POSSETX"));
        lineEdit_GPS_POSSETX->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_8->addWidget(lineEdit_GPS_POSSETX, 0, 1, 1, 2);

        label_37 = new QLabel(groupBox_7);
        label_37->setObjectName(QStringLiteral("label_37"));

        gridLayout_8->addWidget(label_37, 1, 0, 1, 1);

        lineEdit_GPS_POSSETY = new QLineEdit(groupBox_7);
        lineEdit_GPS_POSSETY->setObjectName(QStringLiteral("lineEdit_GPS_POSSETY"));
        lineEdit_GPS_POSSETY->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_8->addWidget(lineEdit_GPS_POSSETY, 1, 1, 1, 2);

        label_38 = new QLabel(groupBox_7);
        label_38->setObjectName(QStringLiteral("label_38"));

        gridLayout_8->addWidget(label_38, 2, 0, 1, 1);

        lineEdit_GPS_POSSETZ = new QLineEdit(groupBox_7);
        lineEdit_GPS_POSSETZ->setObjectName(QStringLiteral("lineEdit_GPS_POSSETZ"));
        lineEdit_GPS_POSSETZ->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_8->addWidget(lineEdit_GPS_POSSETZ, 2, 1, 1, 2);

        pushButton__GPS_POSSET = new QPushButton(groupBox_7);
        pushButton__GPS_POSSET->setObjectName(QStringLiteral("pushButton__GPS_POSSET"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/set1.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton__GPS_POSSET->setIcon(icon4);
        pushButton__GPS_POSSET->setIconSize(QSize(22, 22));

        gridLayout_8->addWidget(pushButton__GPS_POSSET, 3, 0, 1, 2);

        pushButton__GPS_POSASK = new QPushButton(groupBox_7);
        pushButton__GPS_POSASK->setObjectName(QStringLiteral("pushButton__GPS_POSASK"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/images/ask.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton__GPS_POSASK->setIcon(icon5);
        pushButton__GPS_POSASK->setIconSize(QSize(22, 22));

        gridLayout_8->addWidget(pushButton__GPS_POSASK, 3, 2, 1, 1);


        gridLayout_7->addWidget(groupBox_7, 1, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_2, 1, 1, 1, 1);

        groupBox_6 = new QGroupBox(groupBox_3);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        gridLayout_9 = new QGridLayout(groupBox_6);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        label_33 = new QLabel(groupBox_6);
        label_33->setObjectName(QStringLiteral("label_33"));

        gridLayout_9->addWidget(label_33, 0, 0, 1, 1);

        label_34 = new QLabel(groupBox_6);
        label_34->setObjectName(QStringLiteral("label_34"));

        gridLayout_9->addWidget(label_34, 1, 0, 1, 1);

        lineEdit__IMU_POSSETY = new QLineEdit(groupBox_6);
        lineEdit__IMU_POSSETY->setObjectName(QStringLiteral("lineEdit__IMU_POSSETY"));
        lineEdit__IMU_POSSETY->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_9->addWidget(lineEdit__IMU_POSSETY, 1, 1, 1, 2);

        label_35 = new QLabel(groupBox_6);
        label_35->setObjectName(QStringLiteral("label_35"));

        gridLayout_9->addWidget(label_35, 2, 0, 1, 1);

        lineEdit__IMU_POSSETZ = new QLineEdit(groupBox_6);
        lineEdit__IMU_POSSETZ->setObjectName(QStringLiteral("lineEdit__IMU_POSSETZ"));
        lineEdit__IMU_POSSETZ->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_9->addWidget(lineEdit__IMU_POSSETZ, 2, 1, 1, 2);

        pushButton__IMU_POSSET = new QPushButton(groupBox_6);
        pushButton__IMU_POSSET->setObjectName(QStringLiteral("pushButton__IMU_POSSET"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/images/set.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton__IMU_POSSET->setIcon(icon6);
        pushButton__IMU_POSSET->setIconSize(QSize(22, 22));

        gridLayout_9->addWidget(pushButton__IMU_POSSET, 3, 0, 1, 2);

        pushButton_IMU_POSASK = new QPushButton(groupBox_6);
        pushButton_IMU_POSASK->setObjectName(QStringLiteral("pushButton_IMU_POSASK"));
        pushButton_IMU_POSASK->setIcon(icon5);
        pushButton_IMU_POSASK->setIconSize(QSize(22, 22));

        gridLayout_9->addWidget(pushButton_IMU_POSASK, 3, 2, 1, 1);

        lineEdit__IMU_POSSETX = new QLineEdit(groupBox_6);
        lineEdit__IMU_POSSETX->setObjectName(QStringLiteral("lineEdit__IMU_POSSETX"));
        lineEdit__IMU_POSSETX->setLayoutDirection(Qt::LeftToRight);
        lineEdit__IMU_POSSETX->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_9->addWidget(lineEdit__IMU_POSSETX, 0, 1, 1, 2);


        gridLayout_7->addWidget(groupBox_6, 1, 0, 1, 1);

        label_32 = new QLabel(groupBox_3);
        label_32->setObjectName(QStringLiteral("label_32"));
        label_32->setTextFormat(Qt::PlainText);
        label_32->setPixmap(QPixmap(QString::fromUtf8(":/qfi/images/devicepos.png")));
        label_32->setScaledContents(true);

        gridLayout_7->addWidget(label_32, 0, 0, 1, 3);


        retranslateUi(QInstallWidget);

        QMetaObject::connectSlotsByName(QInstallWidget);
    } // setupUi

    void retranslateUi(QWidget *QInstallWidget)
    {
        QInstallWidget->setWindowTitle(QApplication::translate("QInstallWidget", "Form", 0));
        label_31->setText(QString());
        groupBox->setTitle(QApplication::translate("QInstallWidget", "\345\256\211\350\243\205\346\226\271\345\220\221", 0));
        groupBox_8->setTitle(QApplication::translate("QInstallWidget", "IMU", 0));
        pushButton__IMU_DIRSET_FRONT->setText(QApplication::translate("QInstallWidget", "\345\211\215", 0));
        pushButton__IMU_DIRSET_BEHIND->setText(QApplication::translate("QInstallWidget", "\345\220\216", 0));
        pushButton__IMU_DIRSET_LEFT->setText(QApplication::translate("QInstallWidget", "\345\267\246", 0));
        pushButton__IMU_DIRSET_RIGHT->setText(QApplication::translate("QInstallWidget", "\345\217\263", 0));
        groupBox_14->setTitle(QApplication::translate("QInstallWidget", "\347\243\201\347\275\227\347\233\230", 0));
        pushButton__GPS_DIRSET_FRONT->setText(QApplication::translate("QInstallWidget", "\345\211\215", 0));
        pushButton__GPS_DIRSET_BEHIND->setText(QApplication::translate("QInstallWidget", "\345\220\216", 0));
        pushButton__GPS_DIRSET_LEFT->setText(QApplication::translate("QInstallWidget", "\345\267\246", 0));
        pushButton__GPS_DIRSET_RIGHT->setText(QApplication::translate("QInstallWidget", "\345\217\263", 0));
        label_176->setText(QApplication::translate("QInstallWidget", "\350\257\267\351\200\211\346\213\251IMU\343\200\201GPS\347\232\204\347\261\273\345\236\213\357\274\214\344\273\245\345\217\212IMU\347\232\204\345\256\211\350\243\205\346\226\271\345\220\221\357\274\214\345\271\266\350\256\276\347\275\256\345\256\211\350\243\205\344\275\215\347\275\256", 0));
        label_DEVICE->setText(QString());
        groupBox_3->setTitle(QApplication::translate("QInstallWidget", "\345\256\211\350\243\205\344\275\215\347\275\256", 0));
        groupBox_7->setTitle(QApplication::translate("QInstallWidget", "GPS", 0));
        label_36->setText(QApplication::translate("QInstallWidget", "X\350\275\264", 0));
        label_37->setText(QApplication::translate("QInstallWidget", "Y\350\275\264", 0));
        label_38->setText(QApplication::translate("QInstallWidget", "Z\350\275\264", 0));
        pushButton__GPS_POSSET->setText(QApplication::translate("QInstallWidget", "\350\256\276\347\275\256", 0));
        pushButton__GPS_POSASK->setText(QApplication::translate("QInstallWidget", "\346\237\245\350\257\242", 0));
        groupBox_6->setTitle(QApplication::translate("QInstallWidget", "IMU", 0));
        label_33->setText(QApplication::translate("QInstallWidget", "X\350\275\264", 0));
        label_34->setText(QApplication::translate("QInstallWidget", "Y\350\275\264", 0));
        label_35->setText(QApplication::translate("QInstallWidget", "Z\350\275\264", 0));
        pushButton__IMU_POSSET->setText(QApplication::translate("QInstallWidget", "\350\256\276\347\275\256", 0));
        pushButton_IMU_POSASK->setText(QApplication::translate("QInstallWidget", "\346\237\245\350\257\242", 0));
        label_32->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class QInstallWidget: public Ui_QInstallWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSTALLWIDGET_H
