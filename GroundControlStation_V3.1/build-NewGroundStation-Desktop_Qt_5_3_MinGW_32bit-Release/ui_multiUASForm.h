/********************************************************************************
** Form generated from reading UI file 'multiUASForm.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MULTIUASFORM_H
#define UI_MULTIUASFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QMultiUASForm
{
public:
    QGroupBox *groupBox;
    QFrame *frame_2;
    QPushButton *activeButton;
    QLabel *label_2;
    QTableWidget *tableWidget;
    QTableWidget *tableWidget_2;
    QTableWidget *tableWidget_3;

    void setupUi(QWidget *QMultiUASForm)
    {
        if (QMultiUASForm->objectName().isEmpty())
            QMultiUASForm->setObjectName(QStringLiteral("QMultiUASForm"));
        QMultiUASForm->resize(350, 200);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QMultiUASForm->sizePolicy().hasHeightForWidth());
        QMultiUASForm->setSizePolicy(sizePolicy);
        QMultiUASForm->setMinimumSize(QSize(350, 200));
        QMultiUASForm->setMaximumSize(QSize(350, 200));
        QMultiUASForm->setStyleSheet(QStringLiteral(""));
        groupBox = new QGroupBox(QMultiUASForm);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 341, 133));
        QSizePolicy sizePolicy1(QSizePolicy::Ignored, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        groupBox->setMinimumSize(QSize(0, 133));
        groupBox->setMaximumSize(QSize(16777215, 300));
        groupBox->setStyleSheet(QStringLiteral("border-color: rgb(255, 0, 0);"));
        groupBox->setFlat(false);
        frame_2 = new QFrame(groupBox);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(0, 0, 40, 100));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        activeButton = new QPushButton(frame_2);
        activeButton->setObjectName(QStringLiteral("activeButton"));
        activeButton->setGeometry(QRect(0, 56, 40, 40));
        activeButton->setCheckable(false);
        activeButton->setFlat(false);
        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 10, 40, 40));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/qfi/images/aircraft.png")));
        label_2->setScaledContents(true);
        tableWidget = new QTableWidget(groupBox);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(40, 0, 260, 25));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy2);
        tableWidget_2 = new QTableWidget(groupBox);
        tableWidget_2->setObjectName(QStringLiteral("tableWidget_2"));
        tableWidget_2->setEnabled(true);
        tableWidget_2->setGeometry(QRect(40, 25, 260, 25));
        tableWidget_3 = new QTableWidget(groupBox);
        tableWidget_3->setObjectName(QStringLiteral("tableWidget_3"));
        tableWidget_3->setGeometry(QRect(40, 50, 260, 51));

        retranslateUi(QMultiUASForm);

        QMetaObject::connectSlotsByName(QMultiUASForm);
    } // setupUi

    void retranslateUi(QWidget *QMultiUASForm)
    {
        QMultiUASForm->setWindowTitle(QApplication::translate("QMultiUASForm", "Form", 0));
        activeButton->setText(QApplication::translate("QMultiUASForm", "\346\277\200\346\264\273", 0));
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class QMultiUASForm: public Ui_QMultiUASForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MULTIUASFORM_H
