/********************************************************************************
** Form generated from reading UI file 'panelCmdWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PANELCMDWIDGET_H
#define UI_PANELCMDWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QPanelCmdWidget
{
public:
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QToolButton *toolButton_mode;
    QToolButton *toolButton_flycmd;
    QToolButton *toolButton_flymix;
    QToolButton *toolButton_device;
    QToolButton *toolButton_4;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *checkBox_c;
    QLabel *label;
    QPushButton *SendButton;
    QPushButton *cancelButton;

    void setupUi(QWidget *QPanelCmdWidget)
    {
        if (QPanelCmdWidget->objectName().isEmpty())
            QPanelCmdWidget->setObjectName(QStringLiteral("QPanelCmdWidget"));
        QPanelCmdWidget->resize(300, 130);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QPanelCmdWidget->sizePolicy().hasHeightForWidth());
        QPanelCmdWidget->setSizePolicy(sizePolicy);
        QPanelCmdWidget->setMinimumSize(QSize(300, 130));
        QPanelCmdWidget->setMaximumSize(QSize(300, 130));
        groupBox = new QGroupBox(QPanelCmdWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 19, 286, 51));
        groupBox->setMinimumSize(QSize(286, 0));
        groupBox->setMaximumSize(QSize(286, 16777215));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        toolButton_mode = new QToolButton(groupBox);
        toolButton_mode->setObjectName(QStringLiteral("toolButton_mode"));
        toolButton_mode->setPopupMode(QToolButton::InstantPopup);
        toolButton_mode->setAutoRaise(true);

        horizontalLayout->addWidget(toolButton_mode);

        toolButton_flycmd = new QToolButton(groupBox);
        toolButton_flycmd->setObjectName(QStringLiteral("toolButton_flycmd"));
        toolButton_flycmd->setPopupMode(QToolButton::InstantPopup);
        toolButton_flycmd->setAutoRaise(true);

        horizontalLayout->addWidget(toolButton_flycmd);

        toolButton_flymix = new QToolButton(groupBox);
        toolButton_flymix->setObjectName(QStringLiteral("toolButton_flymix"));
        toolButton_flymix->setPopupMode(QToolButton::InstantPopup);
        toolButton_flymix->setAutoRaise(true);

        horizontalLayout->addWidget(toolButton_flymix);

        toolButton_device = new QToolButton(groupBox);
        toolButton_device->setObjectName(QStringLiteral("toolButton_device"));
        toolButton_device->setPopupMode(QToolButton::InstantPopup);
        toolButton_device->setAutoRaise(true);

        horizontalLayout->addWidget(toolButton_device);

        toolButton_4 = new QToolButton(groupBox);
        toolButton_4->setObjectName(QStringLiteral("toolButton_4"));
        toolButton_4->setPopupMode(QToolButton::InstantPopup);
        toolButton_4->setAutoRaise(true);

        horizontalLayout->addWidget(toolButton_4);

        layoutWidget = new QWidget(QPanelCmdWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(9, 81, 291, 32));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        checkBox_c = new QCheckBox(layoutWidget);
        checkBox_c->setObjectName(QStringLiteral("checkBox_c"));
        checkBox_c->setMinimumSize(QSize(0, 0));
        checkBox_c->setMaximumSize(QSize(16, 30));

        horizontalLayout_2->addWidget(checkBox_c);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(160, 30));
        label->setMaximumSize(QSize(160, 30));
        label->setFrameShape(QFrame::Panel);
        label->setFrameShadow(QFrame::Plain);
        label->setLineWidth(2);

        horizontalLayout_2->addWidget(label);

        SendButton = new QPushButton(layoutWidget);
        SendButton->setObjectName(QStringLiteral("SendButton"));
        SendButton->setMinimumSize(QSize(40, 30));
        SendButton->setMaximumSize(QSize(40, 30));

        horizontalLayout_2->addWidget(SendButton);

        cancelButton = new QPushButton(layoutWidget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setMinimumSize(QSize(40, 30));
        cancelButton->setMaximumSize(QSize(40, 30));

        horizontalLayout_2->addWidget(cancelButton);


        retranslateUi(QPanelCmdWidget);

        QMetaObject::connectSlotsByName(QPanelCmdWidget);
    } // setupUi

    void retranslateUi(QWidget *QPanelCmdWidget)
    {
        QPanelCmdWidget->setWindowTitle(QApplication::translate("QPanelCmdWidget", "Form", 0));
        groupBox->setTitle(QApplication::translate("QPanelCmdWidget", "\346\214\207\344\273\244\351\200\211\346\213\251", 0));
        toolButton_mode->setText(QApplication::translate("QPanelCmdWidget", "\346\250\241\345\274\217", 0));
        toolButton_flycmd->setText(QApplication::translate("QPanelCmdWidget", "\351\201\245\346\216\247", 0));
        toolButton_flymix->setText(QApplication::translate("QPanelCmdWidget", "\351\201\245\350\260\203", 0));
        toolButton_device->setText(QApplication::translate("QPanelCmdWidget", "\350\256\276\345\244\207", 0));
        toolButton_4->setText(QApplication::translate("QPanelCmdWidget", "\344\273\273\345\212\241", 0));
        checkBox_c->setText(QString());
        label->setText(QApplication::translate("QPanelCmdWidget", "\350\257\267\351\200\211\346\213\251\351\234\200\350\246\201\345\217\221\351\200\201\347\232\204\346\214\207\344\273\244", 0));
        SendButton->setText(QApplication::translate("QPanelCmdWidget", "\345\217\221\351\200\201", 0));
        cancelButton->setText(QApplication::translate("QPanelCmdWidget", "\345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class QPanelCmdWidget: public Ui_QPanelCmdWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PANELCMDWIDGET_H
