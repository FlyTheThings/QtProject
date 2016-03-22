/********************************************************************************
** Form generated from reading UI file 'speedCmdDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPEEDCMDDIALOG_H
#define UI_SPEEDCMDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_QSpeedCmdDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBox_2;
    QLabel *label_4;
    QPushButton *sendButton_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QDoubleSpinBox *doubleSpinBox_3;
    QLabel *label_6;
    QPushButton *sendButton_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label_2;
    QPushButton *sendButton;

    void setupUi(QDialog *QSpeedCmdDialog)
    {
        if (QSpeedCmdDialog->objectName().isEmpty())
            QSpeedCmdDialog->setObjectName(QStringLiteral("QSpeedCmdDialog"));
        QSpeedCmdDialog->resize(400, 137);
        QSpeedCmdDialog->setStyleSheet(QLatin1String("color: rgb(0, 0, 0);\n"
"background-color: rgb(234, 234, 223);"));
        verticalLayout = new QVBoxLayout(QSpeedCmdDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(QSpeedCmdDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setLayoutDirection(Qt::LeftToRight);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_3);

        doubleSpinBox_2 = new QDoubleSpinBox(groupBox);
        doubleSpinBox_2->setObjectName(QStringLiteral("doubleSpinBox_2"));
        doubleSpinBox_2->setMinimum(-5);
        doubleSpinBox_2->setMaximum(5);

        horizontalLayout_2->addWidget(doubleSpinBox_2);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_2->addWidget(label_4);

        sendButton_2 = new QPushButton(groupBox);
        sendButton_2->setObjectName(QStringLiteral("sendButton_2"));

        horizontalLayout_2->addWidget(sendButton_2);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setLayoutDirection(Qt::LeftToRight);
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_5);

        doubleSpinBox_3 = new QDoubleSpinBox(groupBox);
        doubleSpinBox_3->setObjectName(QStringLiteral("doubleSpinBox_3"));
        doubleSpinBox_3->setMinimum(-2);
        doubleSpinBox_3->setMaximum(4);

        horizontalLayout_3->addWidget(doubleSpinBox_3);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_3->addWidget(label_6);

        sendButton_3 = new QPushButton(groupBox);
        sendButton_3->setObjectName(QStringLiteral("sendButton_3"));

        horizontalLayout_3->addWidget(sendButton_3);


        gridLayout->addLayout(horizontalLayout_3, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label);

        doubleSpinBox = new QDoubleSpinBox(groupBox);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setMinimum(-20);
        doubleSpinBox->setMaximum(20);

        horizontalLayout->addWidget(doubleSpinBox);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        sendButton = new QPushButton(groupBox);
        sendButton->setObjectName(QStringLiteral("sendButton"));

        horizontalLayout->addWidget(sendButton);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        verticalLayout->addWidget(groupBox);


        retranslateUi(QSpeedCmdDialog);

        QMetaObject::connectSlotsByName(QSpeedCmdDialog);
    } // setupUi

    void retranslateUi(QDialog *QSpeedCmdDialog)
    {
        QSpeedCmdDialog->setWindowTitle(QApplication::translate("QSpeedCmdDialog", "\351\200\237\345\272\246\351\201\245\350\260\203", 0));
        groupBox->setTitle(QString());
        label_3->setText(QApplication::translate("QSpeedCmdDialog", "\346\250\252\345\220\221\351\200\237\345\272\246\351\201\245\350\260\203\357\274\232", 0));
        label_4->setText(QApplication::translate("QSpeedCmdDialog", "\357\274\210-5\357\275\2365\357\274\211", 0));
        sendButton_2->setText(QApplication::translate("QSpeedCmdDialog", "\347\241\256\345\256\232", 0));
        label_5->setText(QApplication::translate("QSpeedCmdDialog", "\345\236\202\345\220\221\351\200\237\345\272\246\351\201\245\350\260\203\357\274\232", 0));
        label_6->setText(QApplication::translate("QSpeedCmdDialog", "\357\274\210-2\357\275\2364\357\274\211", 0));
        sendButton_3->setText(QApplication::translate("QSpeedCmdDialog", "\347\241\256\345\256\232", 0));
        label->setText(QApplication::translate("QSpeedCmdDialog", "\347\272\265\345\220\221\351\200\237\345\272\246\351\201\245\350\260\203\357\274\232", 0));
        label_2->setText(QApplication::translate("QSpeedCmdDialog", "\357\274\210-20\357\275\23620\357\274\211", 0));
        sendButton->setText(QApplication::translate("QSpeedCmdDialog", "\347\241\256\345\256\232", 0));
    } // retranslateUi

};

namespace Ui {
    class QSpeedCmdDialog: public Ui_QSpeedCmdDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPEEDCMDDIALOG_H
