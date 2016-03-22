/********************************************************************************
** Form generated from reading UI file 'recorddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECORDDIALOG_H
#define UI_RECORDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QRecordDialog
{
public:
    QSlider *horizontalSlider;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_back;
    QPushButton *pushButton_play;
    QPushButton *pushButton_ahead;

    void setupUi(QDialog *QRecordDialog)
    {
        if (QRecordDialog->objectName().isEmpty())
            QRecordDialog->setObjectName(QStringLiteral("QRecordDialog"));
        QRecordDialog->resize(361, 99);
        QRecordDialog->setMinimumSize(QSize(361, 99));
        QRecordDialog->setMaximumSize(QSize(361, 99));
        horizontalSlider = new QSlider(QRecordDialog);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(10, 70, 331, 22));
        horizontalSlider->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(QRecordDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(81, 1, 192, 70));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_back = new QPushButton(layoutWidget);
        pushButton_back->setObjectName(QStringLiteral("pushButton_back"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/qfi/images/back.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_back->setIcon(icon);
        pushButton_back->setIconSize(QSize(41, 41));
        pushButton_back->setAutoDefault(false);
        pushButton_back->setFlat(true);

        horizontalLayout->addWidget(pushButton_back);

        pushButton_play = new QPushButton(layoutWidget);
        pushButton_play->setObjectName(QStringLiteral("pushButton_play"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/qfi/images/pause.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_play->setIcon(icon1);
        pushButton_play->setIconSize(QSize(60, 60));
        pushButton_play->setCheckable(true);
        pushButton_play->setChecked(false);
        pushButton_play->setAutoExclusive(false);
        pushButton_play->setAutoDefault(true);
        pushButton_play->setFlat(true);

        horizontalLayout->addWidget(pushButton_play);

        pushButton_ahead = new QPushButton(layoutWidget);
        pushButton_ahead->setObjectName(QStringLiteral("pushButton_ahead"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/qfi/images/ahead.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_ahead->setIcon(icon2);
        pushButton_ahead->setIconSize(QSize(41, 41));
        pushButton_ahead->setAutoDefault(false);
        pushButton_ahead->setFlat(true);

        horizontalLayout->addWidget(pushButton_ahead);


        retranslateUi(QRecordDialog);

        QMetaObject::connectSlotsByName(QRecordDialog);
    } // setupUi

    void retranslateUi(QDialog *QRecordDialog)
    {
        QRecordDialog->setWindowTitle(QApplication::translate("QRecordDialog", "Dialog", 0));
        pushButton_back->setText(QString());
        pushButton_play->setText(QString());
        pushButton_ahead->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class QRecordDialog: public Ui_QRecordDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECORDDIALOG_H
