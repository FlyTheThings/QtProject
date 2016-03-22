/********************************************************************************
** Form generated from reading UI file 'panelDataFrameWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PANELDATAFRAMEWIDGET_H
#define UI_PANELDATAFRAMEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QPanelDataFrameWidget
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab_6;
    QTableWidget *tableWidget;
    QWidget *tab_7;
    QTableWidget *tableWidget_2;
    QWidget *tab_3;
    QTableWidget *tableWidget_3;

    void setupUi(QWidget *QPanelDataFrameWidget)
    {
        if (QPanelDataFrameWidget->objectName().isEmpty())
            QPanelDataFrameWidget->setObjectName(QStringLiteral("QPanelDataFrameWidget"));
        QPanelDataFrameWidget->resize(300, 146);
        QPanelDataFrameWidget->setMinimumSize(QSize(300, 0));
        QPanelDataFrameWidget->setMaximumSize(QSize(300, 16777209));
        gridLayout = new QGridLayout(QPanelDataFrameWidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(QPanelDataFrameWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setLayoutDirection(Qt::LeftToRight);
        tabWidget->setTabPosition(QTabWidget::South);
        tabWidget->setTabShape(QTabWidget::Triangular);
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        tableWidget = new QTableWidget(tab_6);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(0, 0, 291, 121));
        tabWidget->addTab(tab_6, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QStringLiteral("tab_7"));
        tableWidget_2 = new QTableWidget(tab_7);
        tableWidget_2->setObjectName(QStringLiteral("tableWidget_2"));
        tableWidget_2->setGeometry(QRect(0, 0, 291, 121));
        tabWidget->addTab(tab_7, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tableWidget_3 = new QTableWidget(tab_3);
        tableWidget_3->setObjectName(QStringLiteral("tableWidget_3"));
        tableWidget_3->setGeometry(QRect(0, 0, 291, 121));
        tabWidget->addTab(tab_3, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(QPanelDataFrameWidget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(QPanelDataFrameWidget);
    } // setupUi

    void retranslateUi(QWidget *QPanelDataFrameWidget)
    {
        QPanelDataFrameWidget->setWindowTitle(QApplication::translate("QPanelDataFrameWidget", "Form", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QApplication::translate("QPanelDataFrameWidget", "\347\212\266\346\200\2011", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_7), QApplication::translate("QPanelDataFrameWidget", "\347\212\266\346\200\2012", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("QPanelDataFrameWidget", "\347\212\266\346\200\2013", 0));
    } // retranslateUi

};

namespace Ui {
    class QPanelDataFrameWidget: public Ui_QPanelDataFrameWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PANELDATAFRAMEWIDGET_H
