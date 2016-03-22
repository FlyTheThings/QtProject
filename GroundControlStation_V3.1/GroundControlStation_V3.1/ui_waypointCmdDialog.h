/********************************************************************************
** Form generated from reading UI file 'waypointCmdDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAYPOINTCMDDIALOG_H
#define UI_WAYPOINTCMDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_QWaypointCmdDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *spinBox;
    QLabel *label_2;
    QPushButton *sendButton;

    void setupUi(QDialog *QWaypointCmdDialog)
    {
        if (QWaypointCmdDialog->objectName().isEmpty())
            QWaypointCmdDialog->setObjectName(QStringLiteral("QWaypointCmdDialog"));
        QWaypointCmdDialog->resize(400, 86);
        QWaypointCmdDialog->setStyleSheet(QLatin1String("color: rgb(0, 0, 0);\n"
"\n"
"background-color: rgb(234, 234, 223);"));
        verticalLayout = new QVBoxLayout(QWaypointCmdDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(QWaypointCmdDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label);

        spinBox = new QSpinBox(QWaypointCmdDialog);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMinimum(1);
        spinBox->setMaximum(255);

        horizontalLayout->addWidget(spinBox);

        label_2 = new QLabel(QWaypointCmdDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        sendButton = new QPushButton(QWaypointCmdDialog);
        sendButton->setObjectName(QStringLiteral("sendButton"));

        horizontalLayout->addWidget(sendButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(QWaypointCmdDialog);

        QMetaObject::connectSlotsByName(QWaypointCmdDialog);
    } // setupUi

    void retranslateUi(QDialog *QWaypointCmdDialog)
    {
        QWaypointCmdDialog->setWindowTitle(QApplication::translate("QWaypointCmdDialog", "Dialog", 0));
        label->setText(QApplication::translate("QWaypointCmdDialog", "\350\210\252\347\202\271\351\201\245\350\260\203\357\274\232", 0));
        label_2->setText(QApplication::translate("QWaypointCmdDialog", "\357\274\2101\357\275\236255\357\274\211", 0));
        sendButton->setText(QApplication::translate("QWaypointCmdDialog", "\347\241\256\345\256\232", 0));
    } // retranslateUi

};

namespace Ui {
    class QWaypointCmdDialog: public Ui_QWaypointCmdDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAYPOINTCMDDIALOG_H
