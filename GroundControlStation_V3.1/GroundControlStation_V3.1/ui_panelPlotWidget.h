/********************************************************************************
** Form generated from reading UI file 'panelPlotWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PANELPLOTWIDGET_H
#define UI_PANELPLOTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QPanelPlotWidget
{
public:

    void setupUi(QWidget *QPanelPlotWidget)
    {
        if (QPanelPlotWidget->objectName().isEmpty())
            QPanelPlotWidget->setObjectName(QStringLiteral("QPanelPlotWidget"));
        QPanelPlotWidget->resize(667, 248);
        QPanelPlotWidget->setMinimumSize(QSize(0, 248));
        QPanelPlotWidget->setMaximumSize(QSize(16777215, 248));

        retranslateUi(QPanelPlotWidget);

        QMetaObject::connectSlotsByName(QPanelPlotWidget);
    } // setupUi

    void retranslateUi(QWidget *QPanelPlotWidget)
    {
        QPanelPlotWidget->setWindowTitle(QApplication::translate("QPanelPlotWidget", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class QPanelPlotWidget: public Ui_QPanelPlotWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PANELPLOTWIDGET_H
