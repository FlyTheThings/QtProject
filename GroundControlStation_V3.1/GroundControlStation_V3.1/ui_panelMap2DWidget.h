/********************************************************************************
** Form generated from reading UI file 'panelMap2DWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PANELMAP2DWIDGET_H
#define UI_PANELMAP2DWIDGET_H

#include <QtCore/QVariant>
#include <QtWebKitWidgets/QWebView>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QPanelMap2DWidget
{
public:
    QGridLayout *gridLayout_2;
    QWebView *webView;

    void setupUi(QWidget *QPanelMap2DWidget)
    {
        if (QPanelMap2DWidget->objectName().isEmpty())
            QPanelMap2DWidget->setObjectName(QStringLiteral("QPanelMap2DWidget"));
        QPanelMap2DWidget->resize(520, 405);
        gridLayout_2 = new QGridLayout(QPanelMap2DWidget);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        webView = new QWebView(QPanelMap2DWidget);
        webView->setObjectName(QStringLiteral("webView"));
        webView->setUrl(QUrl(QStringLiteral("about:blank")));

        gridLayout_2->addWidget(webView, 0, 0, 1, 1);


        retranslateUi(QPanelMap2DWidget);

        QMetaObject::connectSlotsByName(QPanelMap2DWidget);
    } // setupUi

    void retranslateUi(QWidget *QPanelMap2DWidget)
    {
        QPanelMap2DWidget->setWindowTitle(QApplication::translate("QPanelMap2DWidget", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class QPanelMap2DWidget: public Ui_QPanelMap2DWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PANELMAP2DWIDGET_H
