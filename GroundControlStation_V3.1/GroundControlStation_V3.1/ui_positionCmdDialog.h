/********************************************************************************
** Form generated from reading UI file 'positionCmdDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POSITIONCMDDIALOG_H
#define UI_POSITIONCMDDIALOG_H

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

class Ui_QPositionCmdDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label_2;
    QPushButton *sendButton;
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
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_7;
    QDoubleSpinBox *doubleSpinBox_4;
    QLabel *label_8;
    QPushButton *sendButton_4;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QLabel *label_9;
    QDoubleSpinBox *doubleSpinBox_5;
    QLabel *label_10;
    QLabel *label_11;
    QDoubleSpinBox *doubleSpinBox_6;
    QLabel *label_12;
    QLabel *label_13;
    QDoubleSpinBox *doubleSpinBox_7;
    QLabel *label_14;
    QPushButton *sendButton_5;

    void setupUi(QDialog *QPositionCmdDialog)
    {
        if (QPositionCmdDialog->objectName().isEmpty())
            QPositionCmdDialog->setObjectName(QStringLiteral("QPositionCmdDialog"));
        QPositionCmdDialog->resize(400, 251);
        QPositionCmdDialog->setStyleSheet(QLatin1String("color: rgb(0, 0, 0);\n"
"\n"
"background-color: rgb(234, 234, 223);"));
        verticalLayout_2 = new QVBoxLayout(QPositionCmdDialog);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        groupBox = new QGroupBox(QPositionCmdDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label);

        doubleSpinBox = new QDoubleSpinBox(groupBox);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setMinimum(-500);
        doubleSpinBox->setMaximum(500);

        horizontalLayout->addWidget(doubleSpinBox);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        sendButton = new QPushButton(groupBox);
        sendButton->setObjectName(QStringLiteral("sendButton"));

        horizontalLayout->addWidget(sendButton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setLayoutDirection(Qt::LeftToRight);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_3);

        doubleSpinBox_2 = new QDoubleSpinBox(groupBox);
        doubleSpinBox_2->setObjectName(QStringLiteral("doubleSpinBox_2"));
        doubleSpinBox_2->setMinimum(-500);
        doubleSpinBox_2->setMaximum(500);

        horizontalLayout_2->addWidget(doubleSpinBox_2);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_2->addWidget(label_4);

        sendButton_2 = new QPushButton(groupBox);
        sendButton_2->setObjectName(QStringLiteral("sendButton_2"));

        horizontalLayout_2->addWidget(sendButton_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setLayoutDirection(Qt::LeftToRight);
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_5);

        doubleSpinBox_3 = new QDoubleSpinBox(groupBox);
        doubleSpinBox_3->setObjectName(QStringLiteral("doubleSpinBox_3"));
        doubleSpinBox_3->setMinimum(-200);
        doubleSpinBox_3->setMaximum(200);

        horizontalLayout_3->addWidget(doubleSpinBox_3);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_3->addWidget(label_6);

        sendButton_3 = new QPushButton(groupBox);
        sendButton_3->setObjectName(QStringLiteral("sendButton_3"));

        horizontalLayout_3->addWidget(sendButton_3);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setLayoutDirection(Qt::LeftToRight);
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(label_7);

        doubleSpinBox_4 = new QDoubleSpinBox(groupBox);
        doubleSpinBox_4->setObjectName(QStringLiteral("doubleSpinBox_4"));
        doubleSpinBox_4->setMaximum(360);

        horizontalLayout_4->addWidget(doubleSpinBox_4);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_4->addWidget(label_8);

        sendButton_4 = new QPushButton(groupBox);
        sendButton_4->setObjectName(QStringLiteral("sendButton_4"));

        horizontalLayout_4->addWidget(sendButton_4);


        verticalLayout->addLayout(horizontalLayout_4);

        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        groupBox_2->setFont(font);
        groupBox_2->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        groupBox_2->setFlat(false);
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setLayoutDirection(Qt::LeftToRight);
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_9, 0, 0, 1, 1);

        doubleSpinBox_5 = new QDoubleSpinBox(groupBox_2);
        doubleSpinBox_5->setObjectName(QStringLiteral("doubleSpinBox_5"));
        doubleSpinBox_5->setDecimals(8);
        doubleSpinBox_5->setMinimum(-180);
        doubleSpinBox_5->setMaximum(180);

        gridLayout->addWidget(doubleSpinBox_5, 0, 1, 1, 1);

        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout->addWidget(label_10, 0, 2, 1, 1);

        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setLayoutDirection(Qt::LeftToRight);
        label_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_11, 1, 0, 1, 1);

        doubleSpinBox_6 = new QDoubleSpinBox(groupBox_2);
        doubleSpinBox_6->setObjectName(QStringLiteral("doubleSpinBox_6"));
        doubleSpinBox_6->setDecimals(8);
        doubleSpinBox_6->setMinimum(-90);
        doubleSpinBox_6->setMaximum(90);

        gridLayout->addWidget(doubleSpinBox_6, 1, 1, 1, 1);

        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout->addWidget(label_12, 1, 2, 1, 1);

        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setLayoutDirection(Qt::LeftToRight);
        label_13->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_13, 2, 0, 1, 1);

        doubleSpinBox_7 = new QDoubleSpinBox(groupBox_2);
        doubleSpinBox_7->setObjectName(QStringLiteral("doubleSpinBox_7"));
        doubleSpinBox_7->setMinimum(-100);
        doubleSpinBox_7->setMaximum(3000);

        gridLayout->addWidget(doubleSpinBox_7, 2, 1, 1, 1);

        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout->addWidget(label_14, 2, 2, 1, 1);

        sendButton_5 = new QPushButton(groupBox_2);
        sendButton_5->setObjectName(QStringLiteral("sendButton_5"));

        gridLayout->addWidget(sendButton_5, 2, 3, 1, 1);


        verticalLayout->addWidget(groupBox_2);


        verticalLayout_2->addWidget(groupBox);


        retranslateUi(QPositionCmdDialog);

        QMetaObject::connectSlotsByName(QPositionCmdDialog);
    } // setupUi

    void retranslateUi(QDialog *QPositionCmdDialog)
    {
        QPositionCmdDialog->setWindowTitle(QApplication::translate("QPositionCmdDialog", "\344\275\215\347\275\256\351\201\245\350\260\203", 0));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("QPositionCmdDialog", "\347\272\265\345\220\221\344\275\215\347\275\256\351\201\245\350\260\203\357\274\232", 0));
        label_2->setText(QApplication::translate("QPositionCmdDialog", "\357\274\210-500\357\275\236500\357\274\211", 0));
        sendButton->setText(QApplication::translate("QPositionCmdDialog", "\347\241\256\345\256\232", 0));
        label_3->setText(QApplication::translate("QPositionCmdDialog", "\346\250\252\345\220\221\344\275\215\347\275\256\351\201\245\350\260\203\357\274\232", 0));
        label_4->setText(QApplication::translate("QPositionCmdDialog", "\357\274\210-500\357\275\236500\357\274\211", 0));
        sendButton_2->setText(QApplication::translate("QPositionCmdDialog", "\347\241\256\345\256\232", 0));
        label_5->setText(QApplication::translate("QPositionCmdDialog", "\351\253\230\345\272\246\351\201\245\350\260\203\357\274\232", 0));
        label_6->setText(QApplication::translate("QPositionCmdDialog", "\357\274\210-200\357\275\236200\357\274\211", 0));
        sendButton_3->setText(QApplication::translate("QPositionCmdDialog", "\347\241\256\345\256\232", 0));
        label_7->setText(QApplication::translate("QPositionCmdDialog", "\350\210\252\345\220\221\351\201\245\350\260\203\357\274\232", 0));
        label_8->setText(QApplication::translate("QPositionCmdDialog", "\357\274\2100\357\275\236360\357\274\211", 0));
        sendButton_4->setText(QApplication::translate("QPositionCmdDialog", "\347\241\256\345\256\232", 0));
        groupBox_2->setTitle(QApplication::translate("QPositionCmdDialog", "\345\256\232\347\202\271\351\201\245\350\260\203", 0));
        label_9->setText(QApplication::translate("QPositionCmdDialog", "\347\273\217\345\272\246\357\274\232", 0));
        label_10->setText(QApplication::translate("QPositionCmdDialog", "\357\274\210-180\357\275\236180\357\274\211", 0));
        label_11->setText(QApplication::translate("QPositionCmdDialog", "\347\272\254\345\272\246\357\274\232", 0));
        label_12->setText(QApplication::translate("QPositionCmdDialog", "\357\274\210-90\357\275\23690\357\274\211", 0));
        label_13->setText(QApplication::translate("QPositionCmdDialog", "\351\253\230\345\272\246\357\274\232", 0));
        label_14->setText(QApplication::translate("QPositionCmdDialog", "\357\274\210-100\357\275\2363000\357\274\211", 0));
        sendButton_5->setText(QApplication::translate("QPositionCmdDialog", "\347\241\256\345\256\232", 0));
    } // retranslateUi

};

namespace Ui {
    class QPositionCmdDialog: public Ui_QPositionCmdDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POSITIONCMDDIALOG_H
