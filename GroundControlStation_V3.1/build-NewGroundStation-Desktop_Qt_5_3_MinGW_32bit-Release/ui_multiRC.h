/********************************************************************************
** Form generated from reading UI file 'multiRC.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MULTIRC_H
#define UI_MULTIRC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mutiRCDialog
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QProgressBar *progressBar;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QProgressBar *progressBar_2;
    QProgressBar *progressBar_3;
    QProgressBar *progressBar_4;
    QProgressBar *progressBar_5;
    QGroupBox *groupBox_2;
    QRadioButton *radioButton_PWM;
    QRadioButton *radioButton_STU;
    QRadioButton *radioButton_DSM2;
    QRadioButton *radioButton_S_BUS;
    QRadioButton *radioButton_X_BUS;
    QPushButton *pushButton_rc_receiveset;
    QPushButton *pushButton_rc_receiveask;
    QPushButton *pushButton_rccali;
    QPushButton *pushButton_switch;
    QPushButton *pushButton_ele;
    QPushButton *pushButton_ail;
    QPushButton *pushButton_rud;
    QPushButton *pushButton_col;

    void setupUi(QWidget *mutiRCDialog)
    {
        if (mutiRCDialog->objectName().isEmpty())
            mutiRCDialog->setObjectName(QStringLiteral("mutiRCDialog"));
        mutiRCDialog->resize(500, 350);
        groupBox = new QGroupBox(mutiRCDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(0, 5, 500, 345));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 30, 25, 25));
        progressBar = new QProgressBar(groupBox);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(50, 30, 271, 25));
        progressBar->setValue(0);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 80, 25, 25));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 130, 25, 25));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 180, 25, 25));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 230, 25, 25));
        progressBar_2 = new QProgressBar(groupBox);
        progressBar_2->setObjectName(QStringLiteral("progressBar_2"));
        progressBar_2->setGeometry(QRect(50, 80, 271, 25));
        progressBar_2->setValue(0);
        progressBar_3 = new QProgressBar(groupBox);
        progressBar_3->setObjectName(QStringLiteral("progressBar_3"));
        progressBar_3->setGeometry(QRect(50, 130, 271, 25));
        progressBar_3->setValue(0);
        progressBar_4 = new QProgressBar(groupBox);
        progressBar_4->setObjectName(QStringLiteral("progressBar_4"));
        progressBar_4->setGeometry(QRect(50, 180, 271, 25));
        progressBar_4->setValue(0);
        progressBar_5 = new QProgressBar(groupBox);
        progressBar_5->setObjectName(QStringLiteral("progressBar_5"));
        progressBar_5->setGeometry(QRect(50, 230, 271, 25));
        progressBar_5->setValue(0);
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(390, 20, 100, 291));
        radioButton_PWM = new QRadioButton(groupBox_2);
        radioButton_PWM->setObjectName(QStringLiteral("radioButton_PWM"));
        radioButton_PWM->setGeometry(QRect(20, 30, 50, 16));
        radioButton_STU = new QRadioButton(groupBox_2);
        radioButton_STU->setObjectName(QStringLiteral("radioButton_STU"));
        radioButton_STU->setGeometry(QRect(20, 70, 50, 16));
        radioButton_DSM2 = new QRadioButton(groupBox_2);
        radioButton_DSM2->setObjectName(QStringLiteral("radioButton_DSM2"));
        radioButton_DSM2->setGeometry(QRect(20, 110, 50, 16));
        radioButton_S_BUS = new QRadioButton(groupBox_2);
        radioButton_S_BUS->setObjectName(QStringLiteral("radioButton_S_BUS"));
        radioButton_S_BUS->setGeometry(QRect(20, 150, 50, 16));
        radioButton_X_BUS = new QRadioButton(groupBox_2);
        radioButton_X_BUS->setObjectName(QStringLiteral("radioButton_X_BUS"));
        radioButton_X_BUS->setGeometry(QRect(20, 190, 50, 16));
        pushButton_rc_receiveset = new QPushButton(groupBox_2);
        pushButton_rc_receiveset->setObjectName(QStringLiteral("pushButton_rc_receiveset"));
        pushButton_rc_receiveset->setGeometry(QRect(10, 230, 75, 23));
        pushButton_rc_receiveask = new QPushButton(groupBox_2);
        pushButton_rc_receiveask->setObjectName(QStringLiteral("pushButton_rc_receiveask"));
        pushButton_rc_receiveask->setGeometry(QRect(10, 260, 75, 23));
        pushButton_rccali = new QPushButton(groupBox);
        pushButton_rccali->setObjectName(QStringLiteral("pushButton_rccali"));
        pushButton_rccali->setGeometry(QRect(120, 290, 75, 30));
        pushButton_rccali->setCheckable(true);
        pushButton_rccali->setAutoRepeat(false);
        pushButton_rccali->setAutoExclusive(false);
        pushButton_rccali->setFlat(false);
        pushButton_switch = new QPushButton(groupBox);
        pushButton_switch->setObjectName(QStringLiteral("pushButton_switch"));
        pushButton_switch->setGeometry(QRect(330, 25, 40, 30));
        pushButton_ele = new QPushButton(groupBox);
        pushButton_ele->setObjectName(QStringLiteral("pushButton_ele"));
        pushButton_ele->setGeometry(QRect(330, 80, 40, 30));
        pushButton_ail = new QPushButton(groupBox);
        pushButton_ail->setObjectName(QStringLiteral("pushButton_ail"));
        pushButton_ail->setGeometry(QRect(330, 130, 40, 30));
        pushButton_rud = new QPushButton(groupBox);
        pushButton_rud->setObjectName(QStringLiteral("pushButton_rud"));
        pushButton_rud->setGeometry(QRect(330, 180, 40, 30));
        pushButton_col = new QPushButton(groupBox);
        pushButton_col->setObjectName(QStringLiteral("pushButton_col"));
        pushButton_col->setGeometry(QRect(330, 230, 40, 30));

        retranslateUi(mutiRCDialog);

        QMetaObject::connectSlotsByName(mutiRCDialog);
    } // setupUi

    void retranslateUi(QWidget *mutiRCDialog)
    {
        mutiRCDialog->setWindowTitle(QApplication::translate("mutiRCDialog", "Form", 0));
        groupBox->setTitle(QApplication::translate("mutiRCDialog", "\351\201\245\346\216\247\345\231\250\346\240\241\345\207\206", 0));
        label->setText(QApplication::translate("mutiRCDialog", "\345\274\200\345\205\263", 0));
        progressBar->setFormat(QApplication::translate("mutiRCDialog", "%v", 0));
        label_2->setText(QApplication::translate("mutiRCDialog", "\347\272\265\345\220\221", 0));
        label_3->setText(QApplication::translate("mutiRCDialog", "\346\250\252\345\220\221", 0));
        label_4->setText(QApplication::translate("mutiRCDialog", "\350\210\252\345\220\221", 0));
        label_5->setText(QApplication::translate("mutiRCDialog", "\345\215\207\351\231\215", 0));
        progressBar_2->setFormat(QApplication::translate("mutiRCDialog", "%v", 0));
        progressBar_3->setFormat(QApplication::translate("mutiRCDialog", "%v", 0));
        progressBar_4->setFormat(QApplication::translate("mutiRCDialog", "%v", 0));
        progressBar_5->setFormat(QApplication::translate("mutiRCDialog", "%v", 0));
        groupBox_2->setTitle(QApplication::translate("mutiRCDialog", "\346\216\245\346\224\266\346\234\272\347\261\273\345\236\213", 0));
        radioButton_PWM->setText(QApplication::translate("mutiRCDialog", "PWM", 0));
        radioButton_STU->setText(QApplication::translate("mutiRCDialog", "STU", 0));
        radioButton_DSM2->setText(QApplication::translate("mutiRCDialog", "DSM2", 0));
        radioButton_S_BUS->setText(QApplication::translate("mutiRCDialog", "S-BUS", 0));
        radioButton_X_BUS->setText(QApplication::translate("mutiRCDialog", "X-BUS", 0));
        pushButton_rc_receiveset->setText(QApplication::translate("mutiRCDialog", "\350\256\276\347\275\256", 0));
        pushButton_rc_receiveask->setText(QApplication::translate("mutiRCDialog", "\346\237\245\350\257\242", 0));
        pushButton_rccali->setText(QApplication::translate("mutiRCDialog", "\346\240\241\345\207\206\345\274\200\345\247\213", 0));
        pushButton_switch->setText(QApplication::translate("mutiRCDialog", "\346\255\243\345\220\221", 0));
        pushButton_ele->setText(QApplication::translate("mutiRCDialog", "\346\255\243\345\220\221", 0));
        pushButton_ail->setText(QApplication::translate("mutiRCDialog", "\346\255\243\345\220\221", 0));
        pushButton_rud->setText(QApplication::translate("mutiRCDialog", "\346\255\243\345\220\221", 0));
        pushButton_col->setText(QApplication::translate("mutiRCDialog", "\346\255\243\345\220\221", 0));
    } // retranslateUi

};

namespace Ui {
    class mutiRCDialog: public Ui_mutiRCDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MULTIRC_H
