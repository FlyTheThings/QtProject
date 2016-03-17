/********************************************************************************
** Form generated from reading UI file 'firmwareUupdateDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIRMWAREUUPDATEDIALOG_H
#define UI_FIRMWAREUUPDATEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_QFirmwareUpdateDialog
{
public:
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QProgressBar *progressBar;
    QLabel *label_UpdateProgress;
    QLabel *label_Firmwarepath;
    QLabel *label_UpdateProgress_2;
    QPushButton *pushButton_3;
    QLabel *label;

    void setupUi(QDialog *QFirmwareUpdateDialog)
    {
        if (QFirmwareUpdateDialog->objectName().isEmpty())
            QFirmwareUpdateDialog->setObjectName(QStringLiteral("QFirmwareUpdateDialog"));
        QFirmwareUpdateDialog->resize(351, 143);
        lineEdit = new QLineEdit(QFirmwareUpdateDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(50, 20, 221, 31));
        lineEdit->setLayoutDirection(Qt::LeftToRight);
        lineEdit->setMaxLength(32767);
        lineEdit->setReadOnly(true);
        pushButton = new QPushButton(QFirmwareUpdateDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(280, 20, 61, 31));
        pushButton_2 = new QPushButton(QFirmwareUpdateDialog);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(280, 100, 61, 31));
        progressBar = new QProgressBar(QFirmwareUpdateDialog);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(50, 60, 291, 31));
        progressBar->setValue(24);
        progressBar->setTextVisible(false);
        progressBar->setOrientation(Qt::Horizontal);
        progressBar->setInvertedAppearance(false);
        progressBar->setTextDirection(QProgressBar::BottomToTop);
        label_UpdateProgress = new QLabel(QFirmwareUpdateDialog);
        label_UpdateProgress->setObjectName(QStringLiteral("label_UpdateProgress"));
        label_UpdateProgress->setGeometry(QRect(10, 70, 41, 16));
        label_Firmwarepath = new QLabel(QFirmwareUpdateDialog);
        label_Firmwarepath->setObjectName(QStringLiteral("label_Firmwarepath"));
        label_Firmwarepath->setGeometry(QRect(10, 25, 41, 21));
        label_UpdateProgress_2 = new QLabel(QFirmwareUpdateDialog);
        label_UpdateProgress_2->setObjectName(QStringLiteral("label_UpdateProgress_2"));
        label_UpdateProgress_2->setGeometry(QRect(10, 100, 51, 31));
        pushButton_3 = new QPushButton(QFirmwareUpdateDialog);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(210, 100, 61, 31));
        label = new QLabel(QFirmwareUpdateDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 105, 101, 21));

        retranslateUi(QFirmwareUpdateDialog);

        QMetaObject::connectSlotsByName(QFirmwareUpdateDialog);
    } // setupUi

    void retranslateUi(QDialog *QFirmwareUpdateDialog)
    {
        QFirmwareUpdateDialog->setWindowTitle(QApplication::translate("QFirmwareUpdateDialog", "\345\233\272\344\273\266\345\215\207\347\272\247", 0));
        pushButton->setText(QApplication::translate("QFirmwareUpdateDialog", "\346\211\223\345\274\200\346\226\207\344\273\266", 0));
        pushButton_2->setText(QApplication::translate("QFirmwareUpdateDialog", "\345\233\272\344\273\266\345\215\207\347\272\247", 0));
        label_UpdateProgress->setText(QApplication::translate("QFirmwareUpdateDialog", "\350\277\233\345\272\246\357\274\232", 0));
        label_Firmwarepath->setText(QApplication::translate("QFirmwareUpdateDialog", "\345\233\272\344\273\266\357\274\232", 0));
        label_UpdateProgress_2->setText(QApplication::translate("QFirmwareUpdateDialog", "\347\212\266\346\200\201\357\274\232", 0));
        pushButton_3->setText(QApplication::translate("QFirmwareUpdateDialog", "\345\233\272\344\273\266\344\275\277\350\203\275", 0));
        label->setText(QApplication::translate("QFirmwareUpdateDialog", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class QFirmwareUpdateDialog: public Ui_QFirmwareUpdateDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIRMWAREUUPDATEDIALOG_H
