/********************************************************************************
** Form generated from reading UI file 'serialSettingsDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERIALSETTINGSDIALOG_H
#define UI_SERIALSETTINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_QSerialSettingsDialog
{
public:
    QGridLayout *gridLayout_3;
    QGroupBox *selectBox;
    QGridLayout *gridLayout;
    QComboBox *serialPortInfoListBox;
    QLabel *descriptionLabel;
    QLabel *manufacturerLabel;
    QLabel *locationLabel;
    QLabel *vidLabel;
    QLabel *pidLabel;
    QGroupBox *parametersBox;
    QGridLayout *gridLayout_2;
    QLabel *baudRateLabel;
    QComboBox *baudRateBox;
    QLabel *dataBitsLabel;
    QComboBox *dataBitsBox;
    QLabel *parityLabel;
    QComboBox *parityBox;
    QLabel *stopBitsLabel;
    QComboBox *stopBitsBox;
    QLabel *flowControlLabel;
    QComboBox *flowControlBox;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *applyButton;

    void setupUi(QDialog *QSerialSettingsDialog)
    {
        if (QSerialSettingsDialog->objectName().isEmpty())
            QSerialSettingsDialog->setObjectName(QStringLiteral("QSerialSettingsDialog"));
        QSerialSettingsDialog->resize(329, 205);
        gridLayout_3 = new QGridLayout(QSerialSettingsDialog);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        selectBox = new QGroupBox(QSerialSettingsDialog);
        selectBox->setObjectName(QStringLiteral("selectBox"));
        gridLayout = new QGridLayout(selectBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        serialPortInfoListBox = new QComboBox(selectBox);
        serialPortInfoListBox->setObjectName(QStringLiteral("serialPortInfoListBox"));

        gridLayout->addWidget(serialPortInfoListBox, 0, 0, 1, 1);

        descriptionLabel = new QLabel(selectBox);
        descriptionLabel->setObjectName(QStringLiteral("descriptionLabel"));

        gridLayout->addWidget(descriptionLabel, 1, 0, 1, 1);

        manufacturerLabel = new QLabel(selectBox);
        manufacturerLabel->setObjectName(QStringLiteral("manufacturerLabel"));

        gridLayout->addWidget(manufacturerLabel, 2, 0, 1, 1);

        locationLabel = new QLabel(selectBox);
        locationLabel->setObjectName(QStringLiteral("locationLabel"));

        gridLayout->addWidget(locationLabel, 3, 0, 1, 1);

        vidLabel = new QLabel(selectBox);
        vidLabel->setObjectName(QStringLiteral("vidLabel"));

        gridLayout->addWidget(vidLabel, 4, 0, 1, 1);

        pidLabel = new QLabel(selectBox);
        pidLabel->setObjectName(QStringLiteral("pidLabel"));

        gridLayout->addWidget(pidLabel, 5, 0, 1, 1);


        gridLayout_3->addWidget(selectBox, 0, 0, 1, 1);

        parametersBox = new QGroupBox(QSerialSettingsDialog);
        parametersBox->setObjectName(QStringLiteral("parametersBox"));
        gridLayout_2 = new QGridLayout(parametersBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        baudRateLabel = new QLabel(parametersBox);
        baudRateLabel->setObjectName(QStringLiteral("baudRateLabel"));

        gridLayout_2->addWidget(baudRateLabel, 0, 0, 1, 1);

        baudRateBox = new QComboBox(parametersBox);
        baudRateBox->setObjectName(QStringLiteral("baudRateBox"));

        gridLayout_2->addWidget(baudRateBox, 0, 1, 1, 1);

        dataBitsLabel = new QLabel(parametersBox);
        dataBitsLabel->setObjectName(QStringLiteral("dataBitsLabel"));

        gridLayout_2->addWidget(dataBitsLabel, 1, 0, 1, 1);

        dataBitsBox = new QComboBox(parametersBox);
        dataBitsBox->setObjectName(QStringLiteral("dataBitsBox"));

        gridLayout_2->addWidget(dataBitsBox, 1, 1, 1, 1);

        parityLabel = new QLabel(parametersBox);
        parityLabel->setObjectName(QStringLiteral("parityLabel"));

        gridLayout_2->addWidget(parityLabel, 2, 0, 1, 1);

        parityBox = new QComboBox(parametersBox);
        parityBox->setObjectName(QStringLiteral("parityBox"));

        gridLayout_2->addWidget(parityBox, 2, 1, 1, 1);

        stopBitsLabel = new QLabel(parametersBox);
        stopBitsLabel->setObjectName(QStringLiteral("stopBitsLabel"));

        gridLayout_2->addWidget(stopBitsLabel, 3, 0, 1, 1);

        stopBitsBox = new QComboBox(parametersBox);
        stopBitsBox->setObjectName(QStringLiteral("stopBitsBox"));

        gridLayout_2->addWidget(stopBitsBox, 3, 1, 1, 1);

        flowControlLabel = new QLabel(parametersBox);
        flowControlLabel->setObjectName(QStringLiteral("flowControlLabel"));

        gridLayout_2->addWidget(flowControlLabel, 4, 0, 1, 1);

        flowControlBox = new QComboBox(parametersBox);
        flowControlBox->setObjectName(QStringLiteral("flowControlBox"));

        gridLayout_2->addWidget(flowControlBox, 4, 1, 1, 1);


        gridLayout_3->addWidget(parametersBox, 0, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(96, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        applyButton = new QPushButton(QSerialSettingsDialog);
        applyButton->setObjectName(QStringLiteral("applyButton"));

        horizontalLayout->addWidget(applyButton);


        gridLayout_3->addLayout(horizontalLayout, 1, 0, 1, 2);


        retranslateUi(QSerialSettingsDialog);

        QMetaObject::connectSlotsByName(QSerialSettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *QSerialSettingsDialog)
    {
        QSerialSettingsDialog->setWindowTitle(QApplication::translate("QSerialSettingsDialog", "Settings", 0));
        selectBox->setTitle(QApplication::translate("QSerialSettingsDialog", "Select Serial Port", 0));
        descriptionLabel->setText(QApplication::translate("QSerialSettingsDialog", "Description:", 0));
        manufacturerLabel->setText(QApplication::translate("QSerialSettingsDialog", "Manufacturer:", 0));
        locationLabel->setText(QApplication::translate("QSerialSettingsDialog", "Location:", 0));
        vidLabel->setText(QApplication::translate("QSerialSettingsDialog", "Vendor ID:", 0));
        pidLabel->setText(QApplication::translate("QSerialSettingsDialog", "Product ID:", 0));
        parametersBox->setTitle(QApplication::translate("QSerialSettingsDialog", "Select Parameters", 0));
        baudRateLabel->setText(QApplication::translate("QSerialSettingsDialog", "BaudRate:", 0));
        dataBitsLabel->setText(QApplication::translate("QSerialSettingsDialog", "Data bits:", 0));
        parityLabel->setText(QApplication::translate("QSerialSettingsDialog", "Parity:", 0));
        stopBitsLabel->setText(QApplication::translate("QSerialSettingsDialog", "Stop bits:", 0));
        flowControlLabel->setText(QApplication::translate("QSerialSettingsDialog", "Flow control:", 0));
        applyButton->setText(QApplication::translate("QSerialSettingsDialog", "Apply", 0));
    } // retranslateUi

};

namespace Ui {
    class QSerialSettingsDialog: public Ui_QSerialSettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIALSETTINGSDIALOG_H
