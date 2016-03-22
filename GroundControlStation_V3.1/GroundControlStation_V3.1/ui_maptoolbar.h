/********************************************************************************
** Form generated from reading UI file 'maptoolbar.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAPTOOLBAR_H
#define UI_MAPTOOLBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QMaptoolbar
{
public:
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QToolButton *toolButton_timeline;
    QToolButton *toolButton_line;
    QToolButton *toolButton_auto;
    QToolButton *toolButton_cen;
    QToolButton *toolButton_3;

    void setupUi(QWidget *QMaptoolbar)
    {
        if (QMaptoolbar->objectName().isEmpty())
            QMaptoolbar->setObjectName(QStringLiteral("QMaptoolbar"));
        QMaptoolbar->resize(583, 31);
        QMaptoolbar->setMaximumSize(QSize(16777215, 48));
        horizontalLayout = new QHBoxLayout(QMaptoolbar);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(339, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        toolButton_timeline = new QToolButton(QMaptoolbar);
        toolButton_timeline->setObjectName(QStringLiteral("toolButton_timeline"));
        toolButton_timeline->setEnabled(true);
        toolButton_timeline->setMinimumSize(QSize(0, 0));
        toolButton_timeline->setMaximumSize(QSize(16777215, 16777215));
        toolButton_timeline->setPopupMode(QToolButton::InstantPopup);

        horizontalLayout->addWidget(toolButton_timeline);

        toolButton_line = new QToolButton(QMaptoolbar);
        toolButton_line->setObjectName(QStringLiteral("toolButton_line"));
        toolButton_line->setPopupMode(QToolButton::InstantPopup);

        horizontalLayout->addWidget(toolButton_line);

        toolButton_auto = new QToolButton(QMaptoolbar);
        toolButton_auto->setObjectName(QStringLiteral("toolButton_auto"));
        toolButton_auto->setPopupMode(QToolButton::InstantPopup);

        horizontalLayout->addWidget(toolButton_auto);

        toolButton_cen = new QToolButton(QMaptoolbar);
        toolButton_cen->setObjectName(QStringLiteral("toolButton_cen"));
        toolButton_cen->setPopupMode(QToolButton::InstantPopup);

        horizontalLayout->addWidget(toolButton_cen);

        toolButton_3 = new QToolButton(QMaptoolbar);
        toolButton_3->setObjectName(QStringLiteral("toolButton_3"));
        toolButton_3->setMinimumSize(QSize(16, 30));
        toolButton_3->setMaximumSize(QSize(16, 30));
        toolButton_3->setPopupMode(QToolButton::InstantPopup);
        toolButton_3->setAutoRaise(false);

        horizontalLayout->addWidget(toolButton_3);


        retranslateUi(QMaptoolbar);

        QMetaObject::connectSlotsByName(QMaptoolbar);
    } // setupUi

    void retranslateUi(QWidget *QMaptoolbar)
    {
        QMaptoolbar->setWindowTitle(QApplication::translate("QMaptoolbar", "Form", 0));
        toolButton_timeline->setText(QApplication::translate("QMaptoolbar", "\345\256\236\346\227\266\350\275\250\350\277\271", 0));
        toolButton_line->setText(QApplication::translate("QMaptoolbar", "\350\210\252\347\272\277\346\230\276\347\244\272", 0));
        toolButton_auto->setText(QApplication::translate("QMaptoolbar", "\350\207\252\345\212\250\350\267\237\351\232\217", 0));
        toolButton_cen->setText(QApplication::translate("QMaptoolbar", "\350\207\252\345\212\250\345\261\205\344\270\255", 0));
        toolButton_3->setText(QApplication::translate("QMaptoolbar", ">", 0));
    } // retranslateUi

};

namespace Ui {
    class QMaptoolbar: public Ui_QMaptoolbar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAPTOOLBAR_H
