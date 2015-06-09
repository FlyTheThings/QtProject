/********************************************************************************
** Form generated from reading UI file 'anotebook.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANOTEBOOK_H
#define UI_ANOTEBOOK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ANoteBook
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ANoteBook)
    {
        if (ANoteBook->objectName().isEmpty())
            ANoteBook->setObjectName(QStringLiteral("ANoteBook"));
        ANoteBook->resize(400, 300);
        menuBar = new QMenuBar(ANoteBook);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        ANoteBook->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ANoteBook);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ANoteBook->addToolBar(mainToolBar);
        centralWidget = new QWidget(ANoteBook);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        ANoteBook->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(ANoteBook);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ANoteBook->setStatusBar(statusBar);

        retranslateUi(ANoteBook);

        QMetaObject::connectSlotsByName(ANoteBook);
    } // setupUi

    void retranslateUi(QMainWindow *ANoteBook)
    {
        ANoteBook->setWindowTitle(QApplication::translate("ANoteBook", "ANoteBook", 0));
    } // retranslateUi

};

namespace Ui {
    class ANoteBook: public Ui_ANoteBook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANOTEBOOK_H
