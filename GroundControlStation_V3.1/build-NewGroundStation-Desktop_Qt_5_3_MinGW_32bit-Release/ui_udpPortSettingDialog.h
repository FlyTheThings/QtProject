/********************************************************************************
** Form generated from reading UI file 'udpPortSettingDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UDPPORTSETTINGDIALOG_H
#define UI_UDPPORTSETTINGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_QUdpPortSettingDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLabel *label_7;

    void setupUi(QDialog *QUdpPortSettingDialog)
    {
        if (QUdpPortSettingDialog->objectName().isEmpty())
            QUdpPortSettingDialog->setObjectName(QStringLiteral("QUdpPortSettingDialog"));
        QUdpPortSettingDialog->resize(236, 195);
        buttonBox = new QDialogButtonBox(QUdpPortSettingDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(60, 160, 156, 23));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(QUdpPortSettingDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 91, 20));
        lineEdit = new QLineEdit(QUdpPortSettingDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(110, 10, 101, 20));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        lineEdit->setFont(font);
        lineEdit->setAlignment(Qt::AlignCenter);
        lineEdit_2 = new QLineEdit(QUdpPortSettingDialog);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(110, 40, 51, 20));
        label_5 = new QLabel(QUdpPortSettingDialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 90, 91, 20));
        label_6 = new QLabel(QUdpPortSettingDialog);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(50, 120, 51, 21));
        lineEdit_3 = new QLineEdit(QUdpPortSettingDialog);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(110, 90, 101, 20));
        lineEdit_3->setFont(font);
        lineEdit_3->setAlignment(Qt::AlignCenter);
        lineEdit_4 = new QLineEdit(QUdpPortSettingDialog);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(110, 120, 51, 20));
        label_7 = new QLabel(QUdpPortSettingDialog);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(50, 40, 51, 21));

        retranslateUi(QUdpPortSettingDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), QUdpPortSettingDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), QUdpPortSettingDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(QUdpPortSettingDialog);
    } // setupUi

    void retranslateUi(QDialog *QUdpPortSettingDialog)
    {
        QUdpPortSettingDialog->setWindowTitle(QApplication::translate("QUdpPortSettingDialog", "Dialog", 0));
        label->setText(QApplication::translate("QUdpPortSettingDialog", "xPlane IP \345\234\260\345\235\200", 0));
        label_5->setText(QApplication::translate("QUdpPortSettingDialog", "\346\234\254 \345\234\260 IP \345\234\260\345\235\200", 0));
        label_6->setText(QApplication::translate("QUdpPortSettingDialog", "  \347\253\257\345\217\243\345\217\267", 0));
        label_7->setText(QApplication::translate("QUdpPortSettingDialog", "  \347\253\257\345\217\243\345\217\267", 0));
    } // retranslateUi

};

namespace Ui {
    class QUdpPortSettingDialog: public Ui_QUdpPortSettingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UDPPORTSETTINGDIALOG_H
