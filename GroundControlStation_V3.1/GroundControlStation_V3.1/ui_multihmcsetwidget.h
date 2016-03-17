/********************************************************************************
** Form generated from reading UI file 'multihmcsetwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MULTIHMCSETWIDGET_H
#define UI_MULTIHMCSETWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_multiHMCsetWidget
{
public:
    QGroupBox *groupBox_46;
    QLabel *label_82;
    QLineEdit *lineEdit_PSIOFF;
    QGroupBox *groupBox_48;
    QPushButton *pushButton_CALSTART;
    QPushButton *pushButton_CALEND;
    QPushButton *pushButton_CALASK;
    QPushButton *pushButton_CALSTOP;
    QLabel *label_22;
    QLineEdit *lineEdit_KX;
    QLabel *label_25;
    QLineEdit *lineEdit_KY;
    QLabel *label_26;
    QLineEdit *lineEdit_BX;
    QLabel *label_27;
    QLineEdit *lineEdit_BY;
    QPushButton *pushButton_CALSave;
    QPushButton *pushButton_PSIOFFASK;
    QPushButton *pushButton_PSIOFFSET;
    QGroupBox *groupBox;
    QLabel *label_83;
    QComboBox *comboBox_HMCDIR;
    QPushButton *pushButton_HMCdir_Ask;
    QPushButton *pushButton_HMCdir_Set;

    void setupUi(QWidget *multiHMCsetWidget)
    {
        if (multiHMCsetWidget->objectName().isEmpty())
            multiHMCsetWidget->setObjectName(QStringLiteral("multiHMCsetWidget"));
        multiHMCsetWidget->resize(440, 300);
        groupBox_46 = new QGroupBox(multiHMCsetWidget);
        groupBox_46->setObjectName(QStringLiteral("groupBox_46"));
        groupBox_46->setGeometry(QRect(10, 80, 391, 201));
        label_82 = new QLabel(groupBox_46);
        label_82->setObjectName(QStringLiteral("label_82"));
        label_82->setGeometry(QRect(20, 22, 48, 16));
        lineEdit_PSIOFF = new QLineEdit(groupBox_46);
        lineEdit_PSIOFF->setObjectName(QStringLiteral("lineEdit_PSIOFF"));
        lineEdit_PSIOFF->setGeometry(QRect(80, 22, 111, 20));
        groupBox_48 = new QGroupBox(groupBox_46);
        groupBox_48->setObjectName(QStringLiteral("groupBox_48"));
        groupBox_48->setGeometry(QRect(0, 50, 391, 151));
        pushButton_CALSTART = new QPushButton(groupBox_48);
        pushButton_CALSTART->setObjectName(QStringLiteral("pushButton_CALSTART"));
        pushButton_CALSTART->setGeometry(QRect(31, 111, 61, 23));
        pushButton_CALEND = new QPushButton(groupBox_48);
        pushButton_CALEND->setObjectName(QStringLiteral("pushButton_CALEND"));
        pushButton_CALEND->setGeometry(QRect(98, 111, 61, 23));
        pushButton_CALASK = new QPushButton(groupBox_48);
        pushButton_CALASK->setObjectName(QStringLiteral("pushButton_CALASK"));
        pushButton_CALASK->setGeometry(QRect(299, 111, 61, 23));
        pushButton_CALSTOP = new QPushButton(groupBox_48);
        pushButton_CALSTOP->setObjectName(QStringLiteral("pushButton_CALSTOP"));
        pushButton_CALSTOP->setGeometry(QRect(165, 111, 61, 23));
        label_22 = new QLabel(groupBox_48);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(20, 30, 41, 16));
        lineEdit_KX = new QLineEdit(groupBox_48);
        lineEdit_KX->setObjectName(QStringLiteral("lineEdit_KX"));
        lineEdit_KX->setGeometry(QRect(60, 30, 91, 20));
        label_25 = new QLabel(groupBox_48);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(20, 60, 41, 16));
        lineEdit_KY = new QLineEdit(groupBox_48);
        lineEdit_KY->setObjectName(QStringLiteral("lineEdit_KY"));
        lineEdit_KY->setGeometry(QRect(60, 60, 91, 20));
        label_26 = new QLabel(groupBox_48);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(190, 30, 41, 16));
        lineEdit_BX = new QLineEdit(groupBox_48);
        lineEdit_BX->setObjectName(QStringLiteral("lineEdit_BX"));
        lineEdit_BX->setGeometry(QRect(230, 30, 91, 20));
        label_27 = new QLabel(groupBox_48);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setGeometry(QRect(190, 60, 41, 16));
        lineEdit_BY = new QLineEdit(groupBox_48);
        lineEdit_BY->setObjectName(QStringLiteral("lineEdit_BY"));
        lineEdit_BY->setGeometry(QRect(230, 60, 91, 20));
        pushButton_CALSave = new QPushButton(groupBox_48);
        pushButton_CALSave->setObjectName(QStringLiteral("pushButton_CALSave"));
        pushButton_CALSave->setGeometry(QRect(232, 111, 61, 23));
        pushButton_PSIOFFASK = new QPushButton(groupBox_46);
        pushButton_PSIOFFASK->setObjectName(QStringLiteral("pushButton_PSIOFFASK"));
        pushButton_PSIOFFASK->setGeometry(QRect(290, 20, 75, 23));
        pushButton_PSIOFFSET = new QPushButton(groupBox_46);
        pushButton_PSIOFFSET->setObjectName(QStringLiteral("pushButton_PSIOFFSET"));
        pushButton_PSIOFFSET->setGeometry(QRect(207, 20, 75, 23));
        groupBox = new QGroupBox(multiHMCsetWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 391, 61));
        label_83 = new QLabel(groupBox);
        label_83->setObjectName(QStringLiteral("label_83"));
        label_83->setGeometry(QRect(20, 27, 61, 16));
        comboBox_HMCDIR = new QComboBox(groupBox);
        comboBox_HMCDIR->setObjectName(QStringLiteral("comboBox_HMCDIR"));
        comboBox_HMCDIR->setGeometry(QRect(90, 25, 81, 22));
        pushButton_HMCdir_Ask = new QPushButton(groupBox);
        pushButton_HMCdir_Ask->setObjectName(QStringLiteral("pushButton_HMCdir_Ask"));
        pushButton_HMCdir_Ask->setGeometry(QRect(250, 25, 60, 23));
        pushButton_HMCdir_Set = new QPushButton(groupBox);
        pushButton_HMCdir_Set->setObjectName(QStringLiteral("pushButton_HMCdir_Set"));
        pushButton_HMCdir_Set->setGeometry(QRect(187, 25, 60, 23));

        retranslateUi(multiHMCsetWidget);

        QMetaObject::connectSlotsByName(multiHMCsetWidget);
    } // setupUi

    void retranslateUi(QWidget *multiHMCsetWidget)
    {
        multiHMCsetWidget->setWindowTitle(QApplication::translate("multiHMCsetWidget", "Form", 0));
        groupBox_46->setTitle(QApplication::translate("multiHMCsetWidget", "\347\275\227\347\233\230\346\240\241\345\207\206", 0));
        label_82->setText(QApplication::translate("multiHMCsetWidget", "\345\234\260\347\243\201\345\201\217\350\247\222", 0));
        groupBox_48->setTitle(QApplication::translate("multiHMCsetWidget", "\346\240\241\345\207\206", 0));
        pushButton_CALSTART->setText(QApplication::translate("multiHMCsetWidget", "\345\274\200\345\247\213\346\240\241\345\207\206", 0));
        pushButton_CALEND->setText(QApplication::translate("multiHMCsetWidget", "\346\240\241\345\207\206\345\256\214\346\210\220", 0));
        pushButton_CALASK->setText(QApplication::translate("multiHMCsetWidget", "\346\225\260\346\215\256\346\237\245\350\257\242", 0));
        pushButton_CALSTOP->setText(QApplication::translate("multiHMCsetWidget", "\345\217\226\346\266\210\346\240\241\345\207\206", 0));
        label_22->setText(QApplication::translate("multiHMCsetWidget", "X\345\242\236\347\233\212\357\274\232", 0));
        label_25->setText(QApplication::translate("multiHMCsetWidget", "Y\345\242\236\347\233\212\357\274\232", 0));
        label_26->setText(QApplication::translate("multiHMCsetWidget", "X\345\201\217\345\267\256\357\274\232", 0));
        label_27->setText(QApplication::translate("multiHMCsetWidget", "Y\345\201\217\345\267\256\357\274\232", 0));
        pushButton_CALSave->setText(QApplication::translate("multiHMCsetWidget", "\344\277\235\345\255\230\346\240\241\345\207\206", 0));
        pushButton_PSIOFFASK->setText(QApplication::translate("multiHMCsetWidget", "\346\237\245\350\257\242", 0));
        pushButton_PSIOFFSET->setText(QApplication::translate("multiHMCsetWidget", "\350\256\276\347\275\256", 0));
        groupBox->setTitle(QApplication::translate("multiHMCsetWidget", "\347\275\227\347\233\230\345\256\211\350\243\205\350\256\276\347\275\256", 0));
        label_83->setText(QApplication::translate("multiHMCsetWidget", "\345\256\211\350\243\205\346\226\271\345\220\221\357\274\232", 0));
        comboBox_HMCDIR->clear();
        comboBox_HMCDIR->insertItems(0, QStringList()
         << QApplication::translate("multiHMCsetWidget", "X\345\211\215  Y\345\217\263", 0)
         << QApplication::translate("multiHMCsetWidget", "X\345\211\215  Y\345\267\246", 0)
         << QApplication::translate("multiHMCsetWidget", "X\345\220\216  Y\345\217\263", 0)
         << QApplication::translate("multiHMCsetWidget", "X\345\220\216  Y\345\267\246", 0)
         << QApplication::translate("multiHMCsetWidget", "X\345\217\263  Y\345\211\215", 0)
         << QApplication::translate("multiHMCsetWidget", "X\345\267\246  Y\345\211\215", 0)
         << QApplication::translate("multiHMCsetWidget", "X\345\217\263  Y\345\220\216", 0)
         << QApplication::translate("multiHMCsetWidget", "X\345\267\246  Y\345\220\216", 0)
        );
        pushButton_HMCdir_Ask->setText(QApplication::translate("multiHMCsetWidget", "\346\237\245\350\257\242", 0));
        pushButton_HMCdir_Set->setText(QApplication::translate("multiHMCsetWidget", "\350\256\276\347\275\256", 0));
    } // retranslateUi

};

namespace Ui {
    class multiHMCsetWidget: public Ui_multiHMCsetWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MULTIHMCSETWIDGET_H
