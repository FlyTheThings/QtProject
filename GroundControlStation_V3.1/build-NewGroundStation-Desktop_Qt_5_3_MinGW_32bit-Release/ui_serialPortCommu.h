/********************************************************************************
** Form generated from reading UI file 'serialPortCommu.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERIALPORTCOMMU_H
#define UI_SERIALPORTCOMMU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QSerialPortCommu
{
public:
    QGridLayout *gridLayout;

    void setupUi(QWidget *QSerialPortCommu)
    {
        if (QSerialPortCommu->objectName().isEmpty())
            QSerialPortCommu->setObjectName(QStringLiteral("QSerialPortCommu"));
        QSerialPortCommu->resize(400, 300);
        gridLayout = new QGridLayout(QSerialPortCommu);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));

        retranslateUi(QSerialPortCommu);

        QMetaObject::connectSlotsByName(QSerialPortCommu);
    } // setupUi

    void retranslateUi(QWidget *QSerialPortCommu)
    {
        QSerialPortCommu->setWindowTitle(QApplication::translate("QSerialPortCommu", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class QSerialPortCommu: public Ui_QSerialPortCommu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIALPORTCOMMU_H
