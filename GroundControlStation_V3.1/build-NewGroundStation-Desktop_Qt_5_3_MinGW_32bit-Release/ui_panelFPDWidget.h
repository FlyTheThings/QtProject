/********************************************************************************
** Form generated from reading UI file 'panelFPDWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PANELFPDWIDGET_H
#define UI_PANELFPDWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include "WidgetFPD/qfi_PFD.h"

QT_BEGIN_NAMESPACE

class Ui_QPanelFPDWidget
{
public:
    QGridLayout *gridLayout;
    qfi_PFD *graphicsView;

    void setupUi(QWidget *QPanelFPDWidget)
    {
        if (QPanelFPDWidget->objectName().isEmpty())
            QPanelFPDWidget->setObjectName(QStringLiteral("QPanelFPDWidget"));
        QPanelFPDWidget->resize(300, 270);
        QPanelFPDWidget->setMinimumSize(QSize(300, 270));
        QPanelFPDWidget->setMaximumSize(QSize(300, 270));
        QPanelFPDWidget->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        gridLayout = new QGridLayout(QPanelFPDWidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        graphicsView = new qfi_PFD(QPanelFPDWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setMinimumSize(QSize(300, 270));
        graphicsView->setMaximumSize(QSize(300, 270));
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayout->addWidget(graphicsView, 0, 0, 1, 2);


        retranslateUi(QPanelFPDWidget);

        QMetaObject::connectSlotsByName(QPanelFPDWidget);
    } // setupUi

    void retranslateUi(QWidget *QPanelFPDWidget)
    {
        QPanelFPDWidget->setWindowTitle(QApplication::translate("QPanelFPDWidget", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class QPanelFPDWidget: public Ui_QPanelFPDWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PANELFPDWIDGET_H
