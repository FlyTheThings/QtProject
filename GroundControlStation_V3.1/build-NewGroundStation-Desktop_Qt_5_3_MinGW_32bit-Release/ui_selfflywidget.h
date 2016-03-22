/********************************************************************************
** Form generated from reading UI file 'selfflywidget.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELFFLYWIDGET_H
#define UI_SELFFLYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QSelfflyWidget
{
public:
    QGroupBox *groupBox_13;
    QGridLayout *gridLayout_5;
    QLabel *label_8;
    QSlider *horizontalSlider_THETA2ELE;
    QLabel *label_THETA2ELE;
    QLabel *label_9;
    QSlider *horizontalSlider_VX2ELE;
    QLabel *label_VX2ELE;
    QLabel *label_13;
    QLineEdit *lineEdit_ELEMIN;
    QLabel *label_232;
    QLineEdit *lineEdit_ELEMAX;
    QLabel *label_233;
    QPushButton *pushButton_AUTO_ELEASK;
    QPushButton *pushButton_AUTO_ELESET;
    QGroupBox *groupBox_73;
    QGridLayout *gridLayout_12;
    QLabel *label_23;
    QLabel *label_19;
    QLabel *label_236;
    QLineEdit *lineEdit_RUDMIN;
    QPushButton *pushButton_AUTO_RUDASK;
    QLabel *label_AUTO_RUD;
    QPushButton *pushButton_AUTO_RUDSET;
    QLabel *label_237;
    QLineEdit *lineEdit_RUDMAX;
    QSlider *horizontalSlider_AUTO_RUD;
    QGroupBox *groupBox_74;
    QGridLayout *gridLayout_13;
    QLabel *label_AUTO_COL;
    QLineEdit *lineEdit_COLMAX;
    QLineEdit *lineEdit_COLMIN;
    QPushButton *pushButton_AUTO_COLASK;
    QPushButton *pushButton_AUTO_COLSET;
    QLabel *label_239;
    QLabel *label_238;
    QLabel *label_24;
    QLabel *label_29;
    QSlider *horizontalSlider_AUTO_COL;
    QGroupBox *groupBox_71;
    QGridLayout *gridLayout_6;
    QLabel *label_14;
    QSlider *horizontalSlider_PHI2AIL;
    QLabel *label_PHI2AIL;
    QLabel *label_16;
    QSlider *horizontalSlider_VY2AIL;
    QLabel *label_VY2AIL;
    QLabel *label_18;
    QLineEdit *lineEdit_AILMIN;
    QLabel *label_234;
    QLineEdit *lineEdit_AILMAX;
    QLabel *label_235;
    QPushButton *pushButton_AUTO_AILASK;
    QPushButton *pushButton_AUTO_AILSET;

    void setupUi(QWidget *QSelfflyWidget)
    {
        if (QSelfflyWidget->objectName().isEmpty())
            QSelfflyWidget->setObjectName(QStringLiteral("QSelfflyWidget"));
        QSelfflyWidget->resize(763, 566);
        groupBox_13 = new QGroupBox(QSelfflyWidget);
        groupBox_13->setObjectName(QStringLiteral("groupBox_13"));
        groupBox_13->setGeometry(QRect(0, 0, 331, 135));
        gridLayout_5 = new QGridLayout(groupBox_13);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        label_8 = new QLabel(groupBox_13);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_5->addWidget(label_8, 0, 0, 1, 1);

        horizontalSlider_THETA2ELE = new QSlider(groupBox_13);
        horizontalSlider_THETA2ELE->setObjectName(QStringLiteral("horizontalSlider_THETA2ELE"));
        horizontalSlider_THETA2ELE->setMinimum(0);
        horizontalSlider_THETA2ELE->setMaximum(500);
        horizontalSlider_THETA2ELE->setOrientation(Qt::Horizontal);
        horizontalSlider_THETA2ELE->setTickPosition(QSlider::TicksAbove);

        gridLayout_5->addWidget(horizontalSlider_THETA2ELE, 0, 1, 1, 4);

        label_THETA2ELE = new QLabel(groupBox_13);
        label_THETA2ELE->setObjectName(QStringLiteral("label_THETA2ELE"));

        gridLayout_5->addWidget(label_THETA2ELE, 0, 5, 1, 1);

        label_9 = new QLabel(groupBox_13);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_5->addWidget(label_9, 1, 0, 1, 1);

        horizontalSlider_VX2ELE = new QSlider(groupBox_13);
        horizontalSlider_VX2ELE->setObjectName(QStringLiteral("horizontalSlider_VX2ELE"));
        horizontalSlider_VX2ELE->setMinimum(0);
        horizontalSlider_VX2ELE->setMaximum(500);
        horizontalSlider_VX2ELE->setOrientation(Qt::Horizontal);
        horizontalSlider_VX2ELE->setTickPosition(QSlider::TicksAbove);

        gridLayout_5->addWidget(horizontalSlider_VX2ELE, 1, 1, 1, 4);

        label_VX2ELE = new QLabel(groupBox_13);
        label_VX2ELE->setObjectName(QStringLiteral("label_VX2ELE"));

        gridLayout_5->addWidget(label_VX2ELE, 1, 5, 1, 1);

        label_13 = new QLabel(groupBox_13);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout_5->addWidget(label_13, 2, 0, 1, 1);

        lineEdit_ELEMIN = new QLineEdit(groupBox_13);
        lineEdit_ELEMIN->setObjectName(QStringLiteral("lineEdit_ELEMIN"));

        gridLayout_5->addWidget(lineEdit_ELEMIN, 2, 1, 1, 1);

        label_232 = new QLabel(groupBox_13);
        label_232->setObjectName(QStringLiteral("label_232"));

        gridLayout_5->addWidget(label_232, 2, 2, 1, 1);

        lineEdit_ELEMAX = new QLineEdit(groupBox_13);
        lineEdit_ELEMAX->setObjectName(QStringLiteral("lineEdit_ELEMAX"));

        gridLayout_5->addWidget(lineEdit_ELEMAX, 2, 3, 1, 1);

        label_233 = new QLabel(groupBox_13);
        label_233->setObjectName(QStringLiteral("label_233"));

        gridLayout_5->addWidget(label_233, 2, 4, 1, 1);

        pushButton_AUTO_ELEASK = new QPushButton(groupBox_13);
        pushButton_AUTO_ELEASK->setObjectName(QStringLiteral("pushButton_AUTO_ELEASK"));

        gridLayout_5->addWidget(pushButton_AUTO_ELEASK, 3, 3, 1, 1);

        pushButton_AUTO_ELESET = new QPushButton(groupBox_13);
        pushButton_AUTO_ELESET->setObjectName(QStringLiteral("pushButton_AUTO_ELESET"));

        gridLayout_5->addWidget(pushButton_AUTO_ELESET, 3, 1, 1, 1);

        label_9->raise();
        label_8->raise();
        horizontalSlider_THETA2ELE->raise();
        horizontalSlider_VX2ELE->raise();
        label_THETA2ELE->raise();
        label_VX2ELE->raise();
        label_13->raise();
        label_233->raise();
        label_232->raise();
        lineEdit_ELEMAX->raise();
        lineEdit_ELEMIN->raise();
        pushButton_AUTO_ELEASK->raise();
        pushButton_AUTO_ELESET->raise();
        groupBox_73 = new QGroupBox(QSelfflyWidget);
        groupBox_73->setObjectName(QStringLiteral("groupBox_73"));
        groupBox_73->setGeometry(QRect(0, 160, 331, 121));
        gridLayout_12 = new QGridLayout(groupBox_73);
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        label_23 = new QLabel(groupBox_73);
        label_23->setObjectName(QStringLiteral("label_23"));

        gridLayout_12->addWidget(label_23, 1, 0, 1, 1);

        label_19 = new QLabel(groupBox_73);
        label_19->setObjectName(QStringLiteral("label_19"));

        gridLayout_12->addWidget(label_19, 0, 0, 1, 1);

        label_236 = new QLabel(groupBox_73);
        label_236->setObjectName(QStringLiteral("label_236"));

        gridLayout_12->addWidget(label_236, 1, 2, 1, 1);

        lineEdit_RUDMIN = new QLineEdit(groupBox_73);
        lineEdit_RUDMIN->setObjectName(QStringLiteral("lineEdit_RUDMIN"));

        gridLayout_12->addWidget(lineEdit_RUDMIN, 1, 1, 1, 1);

        pushButton_AUTO_RUDASK = new QPushButton(groupBox_73);
        pushButton_AUTO_RUDASK->setObjectName(QStringLiteral("pushButton_AUTO_RUDASK"));

        gridLayout_12->addWidget(pushButton_AUTO_RUDASK, 2, 3, 1, 1);

        label_AUTO_RUD = new QLabel(groupBox_73);
        label_AUTO_RUD->setObjectName(QStringLiteral("label_AUTO_RUD"));

        gridLayout_12->addWidget(label_AUTO_RUD, 0, 5, 1, 1);

        pushButton_AUTO_RUDSET = new QPushButton(groupBox_73);
        pushButton_AUTO_RUDSET->setObjectName(QStringLiteral("pushButton_AUTO_RUDSET"));

        gridLayout_12->addWidget(pushButton_AUTO_RUDSET, 2, 1, 1, 1);

        label_237 = new QLabel(groupBox_73);
        label_237->setObjectName(QStringLiteral("label_237"));

        gridLayout_12->addWidget(label_237, 1, 4, 1, 1);

        lineEdit_RUDMAX = new QLineEdit(groupBox_73);
        lineEdit_RUDMAX->setObjectName(QStringLiteral("lineEdit_RUDMAX"));

        gridLayout_12->addWidget(lineEdit_RUDMAX, 1, 3, 1, 1);

        horizontalSlider_AUTO_RUD = new QSlider(groupBox_73);
        horizontalSlider_AUTO_RUD->setObjectName(QStringLiteral("horizontalSlider_AUTO_RUD"));
        horizontalSlider_AUTO_RUD->setMinimum(0);
        horizontalSlider_AUTO_RUD->setMaximum(500);
        horizontalSlider_AUTO_RUD->setOrientation(Qt::Horizontal);
        horizontalSlider_AUTO_RUD->setTickPosition(QSlider::TicksAbove);

        gridLayout_12->addWidget(horizontalSlider_AUTO_RUD, 0, 1, 1, 4);

        groupBox_74 = new QGroupBox(QSelfflyWidget);
        groupBox_74->setObjectName(QStringLiteral("groupBox_74"));
        groupBox_74->setGeometry(QRect(360, 160, 331, 121));
        gridLayout_13 = new QGridLayout(groupBox_74);
        gridLayout_13->setObjectName(QStringLiteral("gridLayout_13"));
        label_AUTO_COL = new QLabel(groupBox_74);
        label_AUTO_COL->setObjectName(QStringLiteral("label_AUTO_COL"));

        gridLayout_13->addWidget(label_AUTO_COL, 0, 5, 1, 1);

        lineEdit_COLMAX = new QLineEdit(groupBox_74);
        lineEdit_COLMAX->setObjectName(QStringLiteral("lineEdit_COLMAX"));

        gridLayout_13->addWidget(lineEdit_COLMAX, 1, 3, 1, 1);

        lineEdit_COLMIN = new QLineEdit(groupBox_74);
        lineEdit_COLMIN->setObjectName(QStringLiteral("lineEdit_COLMIN"));

        gridLayout_13->addWidget(lineEdit_COLMIN, 1, 1, 1, 1);

        pushButton_AUTO_COLASK = new QPushButton(groupBox_74);
        pushButton_AUTO_COLASK->setObjectName(QStringLiteral("pushButton_AUTO_COLASK"));

        gridLayout_13->addWidget(pushButton_AUTO_COLASK, 2, 3, 1, 1);

        pushButton_AUTO_COLSET = new QPushButton(groupBox_74);
        pushButton_AUTO_COLSET->setObjectName(QStringLiteral("pushButton_AUTO_COLSET"));

        gridLayout_13->addWidget(pushButton_AUTO_COLSET, 2, 1, 1, 1);

        label_239 = new QLabel(groupBox_74);
        label_239->setObjectName(QStringLiteral("label_239"));

        gridLayout_13->addWidget(label_239, 1, 4, 1, 1);

        label_238 = new QLabel(groupBox_74);
        label_238->setObjectName(QStringLiteral("label_238"));

        gridLayout_13->addWidget(label_238, 1, 2, 1, 1);

        label_24 = new QLabel(groupBox_74);
        label_24->setObjectName(QStringLiteral("label_24"));

        gridLayout_13->addWidget(label_24, 0, 0, 1, 1);

        label_29 = new QLabel(groupBox_74);
        label_29->setObjectName(QStringLiteral("label_29"));

        gridLayout_13->addWidget(label_29, 1, 0, 1, 1);

        horizontalSlider_AUTO_COL = new QSlider(groupBox_74);
        horizontalSlider_AUTO_COL->setObjectName(QStringLiteral("horizontalSlider_AUTO_COL"));
        horizontalSlider_AUTO_COL->setMinimum(0);
        horizontalSlider_AUTO_COL->setMaximum(500);
        horizontalSlider_AUTO_COL->setOrientation(Qt::Horizontal);
        horizontalSlider_AUTO_COL->setTickPosition(QSlider::TicksAbove);

        gridLayout_13->addWidget(horizontalSlider_AUTO_COL, 0, 1, 1, 4);

        groupBox_71 = new QGroupBox(QSelfflyWidget);
        groupBox_71->setObjectName(QStringLiteral("groupBox_71"));
        groupBox_71->setGeometry(QRect(360, 0, 331, 135));
        gridLayout_6 = new QGridLayout(groupBox_71);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        label_14 = new QLabel(groupBox_71);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout_6->addWidget(label_14, 0, 0, 1, 1);

        horizontalSlider_PHI2AIL = new QSlider(groupBox_71);
        horizontalSlider_PHI2AIL->setObjectName(QStringLiteral("horizontalSlider_PHI2AIL"));
        horizontalSlider_PHI2AIL->setMinimum(0);
        horizontalSlider_PHI2AIL->setMaximum(500);
        horizontalSlider_PHI2AIL->setOrientation(Qt::Horizontal);
        horizontalSlider_PHI2AIL->setTickPosition(QSlider::TicksAbove);

        gridLayout_6->addWidget(horizontalSlider_PHI2AIL, 0, 1, 1, 4);

        label_PHI2AIL = new QLabel(groupBox_71);
        label_PHI2AIL->setObjectName(QStringLiteral("label_PHI2AIL"));

        gridLayout_6->addWidget(label_PHI2AIL, 0, 5, 1, 1);

        label_16 = new QLabel(groupBox_71);
        label_16->setObjectName(QStringLiteral("label_16"));

        gridLayout_6->addWidget(label_16, 1, 0, 1, 1);

        horizontalSlider_VY2AIL = new QSlider(groupBox_71);
        horizontalSlider_VY2AIL->setObjectName(QStringLiteral("horizontalSlider_VY2AIL"));
        horizontalSlider_VY2AIL->setMinimum(0);
        horizontalSlider_VY2AIL->setMaximum(500);
        horizontalSlider_VY2AIL->setOrientation(Qt::Horizontal);
        horizontalSlider_VY2AIL->setTickPosition(QSlider::TicksAbove);

        gridLayout_6->addWidget(horizontalSlider_VY2AIL, 1, 1, 1, 4);

        label_VY2AIL = new QLabel(groupBox_71);
        label_VY2AIL->setObjectName(QStringLiteral("label_VY2AIL"));

        gridLayout_6->addWidget(label_VY2AIL, 1, 5, 1, 1);

        label_18 = new QLabel(groupBox_71);
        label_18->setObjectName(QStringLiteral("label_18"));

        gridLayout_6->addWidget(label_18, 2, 0, 1, 1);

        lineEdit_AILMIN = new QLineEdit(groupBox_71);
        lineEdit_AILMIN->setObjectName(QStringLiteral("lineEdit_AILMIN"));

        gridLayout_6->addWidget(lineEdit_AILMIN, 2, 1, 1, 1);

        label_234 = new QLabel(groupBox_71);
        label_234->setObjectName(QStringLiteral("label_234"));

        gridLayout_6->addWidget(label_234, 2, 2, 1, 1);

        lineEdit_AILMAX = new QLineEdit(groupBox_71);
        lineEdit_AILMAX->setObjectName(QStringLiteral("lineEdit_AILMAX"));

        gridLayout_6->addWidget(lineEdit_AILMAX, 2, 3, 1, 1);

        label_235 = new QLabel(groupBox_71);
        label_235->setObjectName(QStringLiteral("label_235"));

        gridLayout_6->addWidget(label_235, 2, 4, 1, 1);

        pushButton_AUTO_AILASK = new QPushButton(groupBox_71);
        pushButton_AUTO_AILASK->setObjectName(QStringLiteral("pushButton_AUTO_AILASK"));

        gridLayout_6->addWidget(pushButton_AUTO_AILASK, 3, 3, 1, 1);

        pushButton_AUTO_AILSET = new QPushButton(groupBox_71);
        pushButton_AUTO_AILSET->setObjectName(QStringLiteral("pushButton_AUTO_AILSET"));

        gridLayout_6->addWidget(pushButton_AUTO_AILSET, 3, 1, 1, 1);


        retranslateUi(QSelfflyWidget);

        QMetaObject::connectSlotsByName(QSelfflyWidget);
    } // setupUi

    void retranslateUi(QWidget *QSelfflyWidget)
    {
        QSelfflyWidget->setWindowTitle(QApplication::translate("QSelfflyWidget", "Form", 0));
        groupBox_13->setTitle(QApplication::translate("QSelfflyWidget", "\347\272\265\345\220\221\350\256\276\347\275\256", 0));
        label_8->setText(QApplication::translate("QSelfflyWidget", "\345\206\205\347\216\257\347\201\265\346\225\217\345\272\246", 0));
        label_THETA2ELE->setText(QApplication::translate("QSelfflyWidget", "0", 0));
        label_9->setText(QApplication::translate("QSelfflyWidget", "\345\244\226\347\216\257\347\201\265\346\225\217\345\272\246", 0));
        label_VX2ELE->setText(QApplication::translate("QSelfflyWidget", "0  ", 0));
        label_13->setText(QApplication::translate("QSelfflyWidget", "\351\200\237\345\272\246\350\214\203\345\233\264", 0));
        label_232->setText(QApplication::translate("QSelfflyWidget", "\342\200\224", 0));
        label_233->setText(QApplication::translate("QSelfflyWidget", "\345\272\246/\347\247\222", 0));
        pushButton_AUTO_ELEASK->setText(QApplication::translate("QSelfflyWidget", "\346\237\245\350\257\242", 0));
        pushButton_AUTO_ELESET->setText(QApplication::translate("QSelfflyWidget", "\350\256\276\347\275\256", 0));
        groupBox_73->setTitle(QApplication::translate("QSelfflyWidget", "\350\210\252\345\220\221\350\256\276\347\275\256", 0));
        label_23->setText(QApplication::translate("QSelfflyWidget", "\351\200\237\345\272\246\350\214\203\345\233\264", 0));
        label_19->setText(QApplication::translate("QSelfflyWidget", "\350\210\252\345\220\221\347\201\265\346\225\217\345\272\246", 0));
        label_236->setText(QApplication::translate("QSelfflyWidget", "\342\200\224", 0));
        pushButton_AUTO_RUDASK->setText(QApplication::translate("QSelfflyWidget", "\346\237\245\350\257\242", 0));
        label_AUTO_RUD->setText(QApplication::translate("QSelfflyWidget", "0  ", 0));
        pushButton_AUTO_RUDSET->setText(QApplication::translate("QSelfflyWidget", "\350\256\276\347\275\256", 0));
        label_237->setText(QApplication::translate("QSelfflyWidget", "\345\272\246/\347\247\222", 0));
        groupBox_74->setTitle(QApplication::translate("QSelfflyWidget", "\345\215\207\351\231\215\350\256\276\347\275\256", 0));
        label_AUTO_COL->setText(QApplication::translate("QSelfflyWidget", "0  ", 0));
        pushButton_AUTO_COLASK->setText(QApplication::translate("QSelfflyWidget", "\346\237\245\350\257\242", 0));
        pushButton_AUTO_COLSET->setText(QApplication::translate("QSelfflyWidget", "\350\256\276\347\275\256", 0));
        label_239->setText(QApplication::translate("QSelfflyWidget", "\345\272\246/\347\247\222", 0));
        label_238->setText(QApplication::translate("QSelfflyWidget", "\342\200\224", 0));
        label_24->setText(QApplication::translate("QSelfflyWidget", "\345\215\207\351\231\215\347\201\265\346\225\217\345\272\246", 0));
        label_29->setText(QApplication::translate("QSelfflyWidget", "\351\200\237\345\272\246\350\214\203\345\233\264", 0));
        groupBox_71->setTitle(QApplication::translate("QSelfflyWidget", "\346\250\252\345\220\221\350\256\276\347\275\256", 0));
        label_14->setText(QApplication::translate("QSelfflyWidget", "\345\206\205\347\216\257\347\201\265\346\225\217\345\272\246", 0));
        label_PHI2AIL->setText(QApplication::translate("QSelfflyWidget", "0", 0));
        label_16->setText(QApplication::translate("QSelfflyWidget", "\345\244\226\347\216\257\347\201\265\346\225\217\345\272\246", 0));
        label_VY2AIL->setText(QApplication::translate("QSelfflyWidget", "0  ", 0));
        label_18->setText(QApplication::translate("QSelfflyWidget", "\351\200\237\345\272\246\350\214\203\345\233\264", 0));
        label_234->setText(QApplication::translate("QSelfflyWidget", "\342\200\224", 0));
        label_235->setText(QApplication::translate("QSelfflyWidget", "\345\272\246/\347\247\222", 0));
        pushButton_AUTO_AILASK->setText(QApplication::translate("QSelfflyWidget", "\346\237\245\350\257\242", 0));
        pushButton_AUTO_AILSET->setText(QApplication::translate("QSelfflyWidget", "\350\256\276\347\275\256", 0));
    } // retranslateUi

};

namespace Ui {
    class QSelfflyWidget: public Ui_QSelfflyWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELFFLYWIDGET_H
