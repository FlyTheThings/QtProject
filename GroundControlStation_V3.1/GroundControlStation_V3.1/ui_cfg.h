/********************************************************************************
** Form generated from reading UI file 'cfg.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CFG_H
#define UI_CFG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_cfgWidget
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit_ELEMIN;
    QLineEdit *lineEdit_ELEMAX;
    QLabel *label_4;
    QPushButton *pushButton_AUTO_ELESET;
    QPushButton *pushButton_AUTO_ELEASK;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QSlider *horizontalSlider_VX2ELE;
    QLabel *label_VX2ELE;
    QWidget *horizontalLayoutWidget_7;
    QHBoxLayout *horizontalLayout_8;
    QSlider *horizontalSlider_THETA2ELE;
    QLabel *label_THETA2ELE;
    QGroupBox *groupBox_2;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *lineEdit_AILMIN;
    QLineEdit *lineEdit_AILMAX;
    QLabel *label_8;
    QPushButton *pushButton_AUTO_AILSET;
    QPushButton *pushButton_AUTO_AILASK;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_4;
    QSlider *horizontalSlider_PHI2AIL;
    QLabel *label_PHI2AIL;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_5;
    QSlider *horizontalSlider_VY2AIL;
    QLabel *label_VY2AIL;
    QGroupBox *groupBox_3;
    QLabel *label_15;
    QLineEdit *lineEdit_RUDMIN;
    QLineEdit *lineEdit_RUDMAX;
    QLabel *label_16;
    QPushButton *pushButton_AUTO_RUDSET;
    QPushButton *pushButton_AUTO_RUDASK;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout_6;
    QSlider *horizontalSlider_AUTO_RUD;
    QLabel *label_AUTO_RUD;
    QGroupBox *groupBox_4;
    QLabel *label_19;
    QLineEdit *lineEdit_COLMIN;
    QLineEdit *lineEdit_COLMAX;
    QLabel *label_20;
    QPushButton *pushButton_AUTO_COLSET;
    QPushButton *pushButton_AUTO_COLASK;
    QWidget *horizontalLayoutWidget_6;
    QHBoxLayout *horizontalLayout_7;
    QSlider *horizontalSlider_AUTO_COL;
    QLabel *label_AUTO_COL;

    void setupUi(QWidget *cfgWidget)
    {
        if (cfgWidget->objectName().isEmpty())
            cfgWidget->setObjectName(QStringLiteral("cfgWidget"));
        cfgWidget->resize(500, 350);
        groupBox = new QGroupBox(cfgWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 5, 231, 165));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 60, 20));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 70, 60, 20));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 120, 60, 12));
        label_3->setAlignment(Qt::AlignCenter);
        lineEdit_ELEMIN = new QLineEdit(groupBox);
        lineEdit_ELEMIN->setObjectName(QStringLiteral("lineEdit_ELEMIN"));
        lineEdit_ELEMIN->setGeometry(QRect(10, 140, 70, 20));
        lineEdit_ELEMAX = new QLineEdit(groupBox);
        lineEdit_ELEMAX->setObjectName(QStringLiteral("lineEdit_ELEMAX"));
        lineEdit_ELEMAX->setGeometry(QRect(100, 140, 70, 20));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(80, 140, 20, 20));
        label_4->setAlignment(Qt::AlignCenter);
        pushButton_AUTO_ELESET = new QPushButton(groupBox);
        pushButton_AUTO_ELESET->setObjectName(QStringLiteral("pushButton_AUTO_ELESET"));
        pushButton_AUTO_ELESET->setGeometry(QRect(175, 60, 51, 23));
        pushButton_AUTO_ELEASK = new QPushButton(groupBox);
        pushButton_AUTO_ELEASK->setObjectName(QStringLiteral("pushButton_AUTO_ELEASK"));
        pushButton_AUTO_ELEASK->setGeometry(QRect(175, 110, 51, 23));
        horizontalLayoutWidget_2 = new QWidget(groupBox);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 90, 211, 21));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalSlider_VX2ELE = new QSlider(horizontalLayoutWidget_2);
        horizontalSlider_VX2ELE->setObjectName(QStringLiteral("horizontalSlider_VX2ELE"));
        horizontalSlider_VX2ELE->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(horizontalSlider_VX2ELE);

        label_VX2ELE = new QLabel(horizontalLayoutWidget_2);
        label_VX2ELE->setObjectName(QStringLiteral("label_VX2ELE"));

        horizontalLayout_3->addWidget(label_VX2ELE);

        horizontalLayoutWidget_7 = new QWidget(groupBox);
        horizontalLayoutWidget_7->setObjectName(QStringLiteral("horizontalLayoutWidget_7"));
        horizontalLayoutWidget_7->setGeometry(QRect(10, 40, 211, 21));
        horizontalLayout_8 = new QHBoxLayout(horizontalLayoutWidget_7);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        horizontalSlider_THETA2ELE = new QSlider(horizontalLayoutWidget_7);
        horizontalSlider_THETA2ELE->setObjectName(QStringLiteral("horizontalSlider_THETA2ELE"));
        horizontalSlider_THETA2ELE->setOrientation(Qt::Horizontal);

        horizontalLayout_8->addWidget(horizontalSlider_THETA2ELE);

        label_THETA2ELE = new QLabel(horizontalLayoutWidget_7);
        label_THETA2ELE->setObjectName(QStringLiteral("label_THETA2ELE"));

        horizontalLayout_8->addWidget(label_THETA2ELE);

        groupBox_2 = new QGroupBox(cfgWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(260, 5, 231, 165));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 20, 60, 20));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 70, 60, 20));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 120, 60, 12));
        label_7->setAlignment(Qt::AlignCenter);
        lineEdit_AILMIN = new QLineEdit(groupBox_2);
        lineEdit_AILMIN->setObjectName(QStringLiteral("lineEdit_AILMIN"));
        lineEdit_AILMIN->setGeometry(QRect(10, 140, 70, 20));
        lineEdit_AILMAX = new QLineEdit(groupBox_2);
        lineEdit_AILMAX->setObjectName(QStringLiteral("lineEdit_AILMAX"));
        lineEdit_AILMAX->setGeometry(QRect(100, 140, 70, 20));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(80, 140, 20, 20));
        label_8->setAlignment(Qt::AlignCenter);
        pushButton_AUTO_AILSET = new QPushButton(groupBox_2);
        pushButton_AUTO_AILSET->setObjectName(QStringLiteral("pushButton_AUTO_AILSET"));
        pushButton_AUTO_AILSET->setGeometry(QRect(175, 60, 51, 23));
        pushButton_AUTO_AILASK = new QPushButton(groupBox_2);
        pushButton_AUTO_AILASK->setObjectName(QStringLiteral("pushButton_AUTO_AILASK"));
        pushButton_AUTO_AILASK->setGeometry(QRect(175, 110, 51, 23));
        horizontalLayoutWidget_3 = new QWidget(groupBox_2);
        horizontalLayoutWidget_3->setObjectName(QStringLiteral("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(10, 40, 211, 21));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalSlider_PHI2AIL = new QSlider(horizontalLayoutWidget_3);
        horizontalSlider_PHI2AIL->setObjectName(QStringLiteral("horizontalSlider_PHI2AIL"));
        horizontalSlider_PHI2AIL->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(horizontalSlider_PHI2AIL);

        label_PHI2AIL = new QLabel(horizontalLayoutWidget_3);
        label_PHI2AIL->setObjectName(QStringLiteral("label_PHI2AIL"));

        horizontalLayout_4->addWidget(label_PHI2AIL);

        horizontalLayoutWidget_4 = new QWidget(groupBox_2);
        horizontalLayoutWidget_4->setObjectName(QStringLiteral("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(10, 90, 211, 21));
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalSlider_VY2AIL = new QSlider(horizontalLayoutWidget_4);
        horizontalSlider_VY2AIL->setObjectName(QStringLiteral("horizontalSlider_VY2AIL"));
        horizontalSlider_VY2AIL->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(horizontalSlider_VY2AIL);

        label_VY2AIL = new QLabel(horizontalLayoutWidget_4);
        label_VY2AIL->setObjectName(QStringLiteral("label_VY2AIL"));

        horizontalLayout_5->addWidget(label_VY2AIL);

        groupBox_3 = new QGroupBox(cfgWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(20, 175, 231, 131));
        label_15 = new QLabel(groupBox_3);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(0, 50, 60, 12));
        label_15->setAlignment(Qt::AlignCenter);
        lineEdit_RUDMIN = new QLineEdit(groupBox_3);
        lineEdit_RUDMIN->setObjectName(QStringLiteral("lineEdit_RUDMIN"));
        lineEdit_RUDMIN->setGeometry(QRect(40, 70, 70, 20));
        lineEdit_RUDMAX = new QLineEdit(groupBox_3);
        lineEdit_RUDMAX->setObjectName(QStringLiteral("lineEdit_RUDMAX"));
        lineEdit_RUDMAX->setGeometry(QRect(130, 70, 70, 20));
        label_16 = new QLabel(groupBox_3);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(110, 70, 20, 20));
        label_16->setAlignment(Qt::AlignCenter);
        pushButton_AUTO_RUDSET = new QPushButton(groupBox_3);
        pushButton_AUTO_RUDSET->setObjectName(QStringLiteral("pushButton_AUTO_RUDSET"));
        pushButton_AUTO_RUDSET->setGeometry(QRect(60, 100, 51, 23));
        pushButton_AUTO_RUDASK = new QPushButton(groupBox_3);
        pushButton_AUTO_RUDASK->setObjectName(QStringLiteral("pushButton_AUTO_RUDASK"));
        pushButton_AUTO_RUDASK->setGeometry(QRect(130, 100, 51, 23));
        horizontalLayoutWidget_5 = new QWidget(groupBox_3);
        horizontalLayoutWidget_5->setObjectName(QStringLiteral("horizontalLayoutWidget_5"));
        horizontalLayoutWidget_5->setGeometry(QRect(10, 20, 211, 21));
        horizontalLayout_6 = new QHBoxLayout(horizontalLayoutWidget_5);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalSlider_AUTO_RUD = new QSlider(horizontalLayoutWidget_5);
        horizontalSlider_AUTO_RUD->setObjectName(QStringLiteral("horizontalSlider_AUTO_RUD"));
        horizontalSlider_AUTO_RUD->setOrientation(Qt::Horizontal);

        horizontalLayout_6->addWidget(horizontalSlider_AUTO_RUD);

        label_AUTO_RUD = new QLabel(horizontalLayoutWidget_5);
        label_AUTO_RUD->setObjectName(QStringLiteral("label_AUTO_RUD"));

        horizontalLayout_6->addWidget(label_AUTO_RUD);

        label_15->raise();
        lineEdit_RUDMIN->raise();
        lineEdit_RUDMAX->raise();
        label_16->raise();
        pushButton_AUTO_RUDSET->raise();
        pushButton_AUTO_RUDASK->raise();
        horizontalLayoutWidget_5->raise();
        horizontalSlider_AUTO_RUD->raise();
        groupBox_4 = new QGroupBox(cfgWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(260, 175, 231, 165));
        label_19 = new QLabel(groupBox_4);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(10, 50, 60, 12));
        label_19->setAlignment(Qt::AlignCenter);
        lineEdit_COLMIN = new QLineEdit(groupBox_4);
        lineEdit_COLMIN->setObjectName(QStringLiteral("lineEdit_COLMIN"));
        lineEdit_COLMIN->setGeometry(QRect(30, 70, 70, 20));
        lineEdit_COLMAX = new QLineEdit(groupBox_4);
        lineEdit_COLMAX->setObjectName(QStringLiteral("lineEdit_COLMAX"));
        lineEdit_COLMAX->setGeometry(QRect(120, 70, 70, 20));
        label_20 = new QLabel(groupBox_4);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(100, 70, 20, 20));
        label_20->setAlignment(Qt::AlignCenter);
        pushButton_AUTO_COLSET = new QPushButton(groupBox_4);
        pushButton_AUTO_COLSET->setObjectName(QStringLiteral("pushButton_AUTO_COLSET"));
        pushButton_AUTO_COLSET->setGeometry(QRect(50, 100, 51, 23));
        pushButton_AUTO_COLASK = new QPushButton(groupBox_4);
        pushButton_AUTO_COLASK->setObjectName(QStringLiteral("pushButton_AUTO_COLASK"));
        pushButton_AUTO_COLASK->setGeometry(QRect(120, 100, 51, 23));
        horizontalLayoutWidget_6 = new QWidget(groupBox_4);
        horizontalLayoutWidget_6->setObjectName(QStringLiteral("horizontalLayoutWidget_6"));
        horizontalLayoutWidget_6->setGeometry(QRect(10, 20, 211, 21));
        horizontalLayout_7 = new QHBoxLayout(horizontalLayoutWidget_6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        horizontalSlider_AUTO_COL = new QSlider(horizontalLayoutWidget_6);
        horizontalSlider_AUTO_COL->setObjectName(QStringLiteral("horizontalSlider_AUTO_COL"));
        horizontalSlider_AUTO_COL->setOrientation(Qt::Horizontal);

        horizontalLayout_7->addWidget(horizontalSlider_AUTO_COL);

        label_AUTO_COL = new QLabel(horizontalLayoutWidget_6);
        label_AUTO_COL->setObjectName(QStringLiteral("label_AUTO_COL"));

        horizontalLayout_7->addWidget(label_AUTO_COL);

        label_19->raise();
        lineEdit_COLMIN->raise();
        lineEdit_COLMAX->raise();
        label_20->raise();
        pushButton_AUTO_COLSET->raise();
        pushButton_AUTO_COLASK->raise();
        horizontalLayoutWidget_6->raise();
        horizontalSlider_AUTO_COL->raise();

        retranslateUi(cfgWidget);

        QMetaObject::connectSlotsByName(cfgWidget);
    } // setupUi

    void retranslateUi(QWidget *cfgWidget)
    {
        cfgWidget->setWindowTitle(QApplication::translate("cfgWidget", "Form", 0));
        groupBox->setTitle(QApplication::translate("cfgWidget", "\347\272\265\345\220\221", 0));
        label->setText(QApplication::translate("cfgWidget", "\345\206\205\347\216\257\347\201\265\346\225\217\345\272\246", 0));
        label_2->setText(QApplication::translate("cfgWidget", "\345\244\226\347\216\257\347\201\265\346\225\217\345\272\246", 0));
        label_3->setText(QApplication::translate("cfgWidget", "\351\200\237\345\272\246\350\214\203\345\233\264", 0));
        label_4->setText(QApplication::translate("cfgWidget", "\342\200\224", 0));
        pushButton_AUTO_ELESET->setText(QApplication::translate("cfgWidget", "\350\256\276\347\275\256", 0));
        pushButton_AUTO_ELEASK->setText(QApplication::translate("cfgWidget", "\346\237\245\350\257\242", 0));
        label_VX2ELE->setText(QApplication::translate("cfgWidget", "0", 0));
        label_THETA2ELE->setText(QApplication::translate("cfgWidget", "0", 0));
        groupBox_2->setTitle(QApplication::translate("cfgWidget", "\346\250\252\345\220\221", 0));
        label_5->setText(QApplication::translate("cfgWidget", "\345\206\205\347\216\257\347\201\265\346\225\217\345\272\246", 0));
        label_6->setText(QApplication::translate("cfgWidget", "\345\244\226\347\216\257\347\201\265\346\225\217\345\272\246", 0));
        label_7->setText(QApplication::translate("cfgWidget", "\351\200\237\345\272\246\350\214\203\345\233\264", 0));
        label_8->setText(QApplication::translate("cfgWidget", "\342\200\224", 0));
        pushButton_AUTO_AILSET->setText(QApplication::translate("cfgWidget", "\350\256\276\347\275\256", 0));
        pushButton_AUTO_AILASK->setText(QApplication::translate("cfgWidget", "\346\237\245\350\257\242", 0));
        label_PHI2AIL->setText(QApplication::translate("cfgWidget", "0", 0));
        label_VY2AIL->setText(QApplication::translate("cfgWidget", "0", 0));
        groupBox_3->setTitle(QApplication::translate("cfgWidget", "\350\210\252\345\220\221", 0));
        label_15->setText(QApplication::translate("cfgWidget", "\351\200\237\345\272\246\350\214\203\345\233\264", 0));
        label_16->setText(QApplication::translate("cfgWidget", "\342\200\224", 0));
        pushButton_AUTO_RUDSET->setText(QApplication::translate("cfgWidget", "\350\256\276\347\275\256", 0));
        pushButton_AUTO_RUDASK->setText(QApplication::translate("cfgWidget", "\346\237\245\350\257\242", 0));
        label_AUTO_RUD->setText(QApplication::translate("cfgWidget", "0", 0));
        groupBox_4->setTitle(QApplication::translate("cfgWidget", "\345\236\202\345\220\221", 0));
        label_19->setText(QApplication::translate("cfgWidget", "\351\200\237\345\272\246\350\214\203\345\233\264", 0));
        label_20->setText(QApplication::translate("cfgWidget", "\342\200\224", 0));
        pushButton_AUTO_COLSET->setText(QApplication::translate("cfgWidget", "\350\256\276\347\275\256", 0));
        pushButton_AUTO_COLASK->setText(QApplication::translate("cfgWidget", "\346\237\245\350\257\242", 0));
        label_AUTO_COL->setText(QApplication::translate("cfgWidget", "0", 0));
    } // retranslateUi

};

namespace Ui {
    class cfgWidget: public Ui_cfgWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CFG_H
