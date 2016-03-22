/********************************************************************************
** Form generated from reading UI file 'panellocalmapwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PANELLOCALMAPWIDGET_H
#define UI_PANELLOCALMAPWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include "WidgetPlot/qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_QPanellocalmapWidget
{
public:
    QGridLayout *gridLayout;
    QCustomPlot *waypointPlot;

    void setupUi(QWidget *QPanellocalmapWidget)
    {
        if (QPanellocalmapWidget->objectName().isEmpty())
            QPanellocalmapWidget->setObjectName(QStringLiteral("QPanellocalmapWidget"));
        QPanellocalmapWidget->resize(400, 300);
        gridLayout = new QGridLayout(QPanellocalmapWidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        waypointPlot = new QCustomPlot(QPanellocalmapWidget);
        waypointPlot->setObjectName(QStringLiteral("waypointPlot"));
        waypointPlot->setMinimumSize(QSize(12, 12));

        gridLayout->addWidget(waypointPlot, 0, 0, 1, 1);


        retranslateUi(QPanellocalmapWidget);

        QMetaObject::connectSlotsByName(QPanellocalmapWidget);
    } // setupUi

    void retranslateUi(QWidget *QPanellocalmapWidget)
    {
        QPanellocalmapWidget->setWindowTitle(QApplication::translate("QPanellocalmapWidget", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class QPanellocalmapWidget: public Ui_QPanellocalmapWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PANELLOCALMAPWIDGET_H
