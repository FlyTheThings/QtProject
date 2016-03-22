/********************************************************************************
** Form generated from reading UI file 'panelUASWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PANELUASWIDGET_H
#define UI_PANELUASWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QPanelUASWidget
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;

    void setupUi(QWidget *QPanelUASWidget)
    {
        if (QPanelUASWidget->objectName().isEmpty())
            QPanelUASWidget->setObjectName(QStringLiteral("QPanelUASWidget"));
        QPanelUASWidget->resize(285, 147);
        QPanelUASWidget->setMinimumSize(QSize(0, 0));
        QPanelUASWidget->setMaximumSize(QSize(300, 300));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        QPanelUASWidget->setFont(font);
        QPanelUASWidget->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        verticalLayout = new QVBoxLayout(QPanelUASWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(QPanelUASWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setMinimumSize(QSize(0, 115));
        tabWidget->setMaximumSize(QSize(16777215, 250));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font1.setPointSize(9);
        font1.setBold(false);
        font1.setWeight(50);
        tabWidget->setFont(font1);
        tabWidget->setTabPosition(QTabWidget::South);
        tabWidget->setTabShape(QTabWidget::Triangular);
        tabWidget->setElideMode(Qt::ElideNone);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(QPanelUASWidget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(QPanelUASWidget);
    } // setupUi

    void retranslateUi(QWidget *QPanelUASWidget)
    {
        QPanelUASWidget->setWindowTitle(QApplication::translate("QPanelUASWidget", "Form", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("QPanelUASWidget", "Tab 1", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("QPanelUASWidget", "Tab 2", 0));
    } // retranslateUi

};

namespace Ui {
    class QPanelUASWidget: public Ui_QPanelUASWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PANELUASWIDGET_H
