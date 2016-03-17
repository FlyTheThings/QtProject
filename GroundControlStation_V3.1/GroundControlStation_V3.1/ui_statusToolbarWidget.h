/********************************************************************************
** Form generated from reading UI file 'statusToolbarWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATUSTOOLBARWIDGET_H
#define UI_STATUSTOOLBARWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QStatusToolbarWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QLabel *label_mode;
    QLabel *label;
    QLabel *label_num;
    QLabel *label_3;
    QLabel *label_state;
    QLabel *label_5;
    QToolButton *toolButton_light;
    QLabel *label_7;
    QLabel *label_time;

    void setupUi(QWidget *QStatusToolbarWidget)
    {
        if (QStatusToolbarWidget->objectName().isEmpty())
            QStatusToolbarWidget->setObjectName(QStringLiteral("QStatusToolbarWidget"));
        QStatusToolbarWidget->setEnabled(true);
        QStatusToolbarWidget->resize(596, 38);
        QStatusToolbarWidget->setMinimumSize(QSize(0, 20));
        QStatusToolbarWidget->setMaximumSize(QSize(16777215, 38));
        horizontalLayout = new QHBoxLayout(QStatusToolbarWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(223, 5, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_2 = new QLabel(QStatusToolbarWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(0, 0));

        horizontalLayout->addWidget(label_2);

        label_mode = new QLabel(QStatusToolbarWidget);
        label_mode->setObjectName(QStringLiteral("label_mode"));
        label_mode->setMinimumSize(QSize(60, 8));

        horizontalLayout->addWidget(label_mode);

        label = new QLabel(QStatusToolbarWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 0));

        horizontalLayout->addWidget(label);

        label_num = new QLabel(QStatusToolbarWidget);
        label_num->setObjectName(QStringLiteral("label_num"));
        label_num->setMinimumSize(QSize(0, 0));

        horizontalLayout->addWidget(label_num);

        label_3 = new QLabel(QStatusToolbarWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        label_state = new QLabel(QStatusToolbarWidget);
        label_state->setObjectName(QStringLiteral("label_state"));

        horizontalLayout->addWidget(label_state);

        label_5 = new QLabel(QStatusToolbarWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout->addWidget(label_5);

        toolButton_light = new QToolButton(QStatusToolbarWidget);
        toolButton_light->setObjectName(QStringLiteral("toolButton_light"));
        toolButton_light->setEnabled(true);
        toolButton_light->setMinimumSize(QSize(15, 15));
        QIcon icon;
        icon.addFile(QStringLiteral(":/qfi/images/light_red.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_light->setIcon(icon);
        toolButton_light->setIconSize(QSize(15, 15));
        toolButton_light->setCheckable(false);
        toolButton_light->setChecked(false);
        toolButton_light->setToolButtonStyle(Qt::ToolButtonIconOnly);
        toolButton_light->setAutoRaise(true);

        horizontalLayout->addWidget(toolButton_light);

        label_7 = new QLabel(QStatusToolbarWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout->addWidget(label_7);

        label_time = new QLabel(QStatusToolbarWidget);
        label_time->setObjectName(QStringLiteral("label_time"));

        horizontalLayout->addWidget(label_time);


        retranslateUi(QStatusToolbarWidget);

        QMetaObject::connectSlotsByName(QStatusToolbarWidget);
    } // setupUi

    void retranslateUi(QWidget *QStatusToolbarWidget)
    {
        QStatusToolbarWidget->setWindowTitle(QApplication::translate("QStatusToolbarWidget", "Form", 0));
        label_2->setText(QApplication::translate("QStatusToolbarWidget", "\346\250\241\345\274\217\357\274\232", 0));
        label_mode->setText(QApplication::translate("QStatusToolbarWidget", "\345\205\263\351\227\255      ", 0));
        label->setText(QApplication::translate("QStatusToolbarWidget", "\351\243\236\346\234\272\346\225\260\357\274\232", 0));
        label_num->setText(QApplication::translate("QStatusToolbarWidget", "1/2", 0));
        label_3->setText(QApplication::translate("QStatusToolbarWidget", "    \347\212\266\346\200\201\357\274\232", 0));
        label_state->setText(QApplication::translate("QStatusToolbarWidget", "1", 0));
        label_5->setText(QApplication::translate("QStatusToolbarWidget", "    \351\223\276\350\267\257\357\274\232", 0));
        toolButton_light->setText(QString());
        label_7->setText(QApplication::translate("QStatusToolbarWidget", "    \346\227\266\351\227\264\357\274\232", 0));
        label_time->setText(QApplication::translate("QStatusToolbarWidget", "23:00:00", 0));
    } // retranslateUi

};

namespace Ui {
    class QStatusToolbarWidget: public Ui_QStatusToolbarWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATUSTOOLBARWIDGET_H
