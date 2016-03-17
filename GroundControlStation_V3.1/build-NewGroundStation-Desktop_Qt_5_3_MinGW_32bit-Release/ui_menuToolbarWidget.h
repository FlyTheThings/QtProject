/********************************************************************************
** Form generated from reading UI file 'menuToolbarWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUTOOLBARWIDGET_H
#define UI_MENUTOOLBARWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QMenuToolbarWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QToolButton *fileButton;
    QToolButton *comuButton;
    QToolButton *configButton;
    QToolButton *lineButton;
    QToolButton *plotButton;
    QToolButton *helpButton;

    void setupUi(QWidget *QMenuToolbarWidget)
    {
        if (QMenuToolbarWidget->objectName().isEmpty())
            QMenuToolbarWidget->setObjectName(QStringLiteral("QMenuToolbarWidget"));
        QMenuToolbarWidget->resize(288, 42);
        QMenuToolbarWidget->setMinimumSize(QSize(0, 0));
        QMenuToolbarWidget->setMaximumSize(QSize(6868678, 16777215));
        horizontalLayout = new QHBoxLayout(QMenuToolbarWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        fileButton = new QToolButton(QMenuToolbarWidget);
        fileButton->setObjectName(QStringLiteral("fileButton"));
        fileButton->setPopupMode(QToolButton::InstantPopup);
        fileButton->setAutoRaise(true);

        horizontalLayout->addWidget(fileButton);

        comuButton = new QToolButton(QMenuToolbarWidget);
        comuButton->setObjectName(QStringLiteral("comuButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comuButton->sizePolicy().hasHeightForWidth());
        comuButton->setSizePolicy(sizePolicy);
        comuButton->setAutoRepeatDelay(300);
        comuButton->setPopupMode(QToolButton::InstantPopup);
        comuButton->setToolButtonStyle(Qt::ToolButtonTextOnly);
        comuButton->setAutoRaise(true);

        horizontalLayout->addWidget(comuButton);

        configButton = new QToolButton(QMenuToolbarWidget);
        configButton->setObjectName(QStringLiteral("configButton"));
        sizePolicy.setHeightForWidth(configButton->sizePolicy().hasHeightForWidth());
        configButton->setSizePolicy(sizePolicy);
        configButton->setPopupMode(QToolButton::InstantPopup);
        configButton->setToolButtonStyle(Qt::ToolButtonTextOnly);
        configButton->setAutoRaise(true);

        horizontalLayout->addWidget(configButton);

        lineButton = new QToolButton(QMenuToolbarWidget);
        lineButton->setObjectName(QStringLiteral("lineButton"));
        sizePolicy.setHeightForWidth(lineButton->sizePolicy().hasHeightForWidth());
        lineButton->setSizePolicy(sizePolicy);
        lineButton->setPopupMode(QToolButton::InstantPopup);
        lineButton->setToolButtonStyle(Qt::ToolButtonTextOnly);
        lineButton->setAutoRaise(true);

        horizontalLayout->addWidget(lineButton);

        plotButton = new QToolButton(QMenuToolbarWidget);
        plotButton->setObjectName(QStringLiteral("plotButton"));
        plotButton->setPopupMode(QToolButton::InstantPopup);
        plotButton->setAutoRaise(true);

        horizontalLayout->addWidget(plotButton);

        helpButton = new QToolButton(QMenuToolbarWidget);
        helpButton->setObjectName(QStringLiteral("helpButton"));
        sizePolicy.setHeightForWidth(helpButton->sizePolicy().hasHeightForWidth());
        helpButton->setSizePolicy(sizePolicy);
        helpButton->setPopupMode(QToolButton::InstantPopup);
        helpButton->setToolButtonStyle(Qt::ToolButtonTextOnly);
        helpButton->setAutoRaise(true);

        horizontalLayout->addWidget(helpButton);


        retranslateUi(QMenuToolbarWidget);

        QMetaObject::connectSlotsByName(QMenuToolbarWidget);
    } // setupUi

    void retranslateUi(QWidget *QMenuToolbarWidget)
    {
        QMenuToolbarWidget->setWindowTitle(QApplication::translate("QMenuToolbarWidget", "Form", 0));
        fileButton->setText(QApplication::translate("QMenuToolbarWidget", "\346\226\207\344\273\266", 0));
        comuButton->setText(QApplication::translate("QMenuToolbarWidget", "\351\200\232\344\277\241", 0));
        configButton->setText(QApplication::translate("QMenuToolbarWidget", "\351\205\215\347\275\256", 0));
        lineButton->setText(QApplication::translate("QMenuToolbarWidget", "\350\210\252\347\272\277", 0));
        plotButton->setText(QApplication::translate("QMenuToolbarWidget", "\347\252\227\345\217\243", 0));
        helpButton->setText(QApplication::translate("QMenuToolbarWidget", "\345\270\256\345\212\251", 0));
    } // retranslateUi

};

namespace Ui {
    class QMenuToolbarWidget: public Ui_QMenuToolbarWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUTOOLBARWIDGET_H
