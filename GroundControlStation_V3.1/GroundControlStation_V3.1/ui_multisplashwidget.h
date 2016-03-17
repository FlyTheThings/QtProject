/********************************************************************************
** Form generated from reading UI file 'multisplashwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MULTISPLASHWIDGET_H
#define UI_MULTISPLASHWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_multisplashWidget
{
public:
    QGroupBox *groupBox_99;
    QGridLayout *gridLayout_31;
    QLineEdit *lineEdit_SPRAY_LOW_V;
    QLabel *label_152;
    QLineEdit *lineEdit_SPRAY_AVE;
    QLabel *label_SPRAYI;
    QDoubleSpinBox *doubleSpinBox_SPRAYP;
    QDoubleSpinBox *doubleSpinBox_SPRAYI;
    QPushButton *pushButton_SPRAYASK;
    QPushButton *pushButton_SPRAYSET;
    QLabel *label_288;
    QLabel *label_289;
    QLabel *label_SPRAYP;
    QLabel *label_285;
    QLabel *label_286;
    QLineEdit *lineEdit_SPRAY_RANGE;
    QLabel *label_287;
    QGroupBox *groupBox_39;
    QGridLayout *gridLayout_17;
    QPushButton *pushButton_SPRAY_VSET;
    QLabel *label_142;
    QProgressBar *progressBar_SPRAY_INPUT;
    QLabel *label_143;
    QProgressBar *progressBar_SPRAY_OUTPUT;
    QLabel *label_145;
    QLineEdit *lineEdit_SPRAY_MODE;
    QLabel *label_148;
    QLineEdit *lineEdit_SPRAY_V;
    QLabel *label_150;
    QLabel *label_146;
    QLineEdit *lineEdit_SPRAY_VSET;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_149;
    QLineEdit *lineEdit_SPRAY_FLOW;
    QLabel *label_151;
    QLabel *label_144;
    QLabel *label_147;
    QPushButton *pushButton_SPRAY_RUNMODE;
    QPushButton *pushButton_SPRAY_TESTMODE;

    void setupUi(QWidget *multisplashWidget)
    {
        if (multisplashWidget->objectName().isEmpty())
            multisplashWidget->setObjectName(QStringLiteral("multisplashWidget"));
        multisplashWidget->resize(500, 350);
        groupBox_99 = new QGroupBox(multisplashWidget);
        groupBox_99->setObjectName(QStringLiteral("groupBox_99"));
        groupBox_99->setGeometry(QRect(10, 180, 481, 171));
        gridLayout_31 = new QGridLayout(groupBox_99);
        gridLayout_31->setObjectName(QStringLiteral("gridLayout_31"));
        lineEdit_SPRAY_LOW_V = new QLineEdit(groupBox_99);
        lineEdit_SPRAY_LOW_V->setObjectName(QStringLiteral("lineEdit_SPRAY_LOW_V"));
        lineEdit_SPRAY_LOW_V->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_31->addWidget(lineEdit_SPRAY_LOW_V, 3, 1, 1, 3);

        label_152 = new QLabel(groupBox_99);
        label_152->setObjectName(QStringLiteral("label_152"));

        gridLayout_31->addWidget(label_152, 0, 0, 1, 1);

        lineEdit_SPRAY_AVE = new QLineEdit(groupBox_99);
        lineEdit_SPRAY_AVE->setObjectName(QStringLiteral("lineEdit_SPRAY_AVE"));
        lineEdit_SPRAY_AVE->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_31->addWidget(lineEdit_SPRAY_AVE, 1, 1, 1, 3);

        label_SPRAYI = new QLabel(groupBox_99);
        label_SPRAYI->setObjectName(QStringLiteral("label_SPRAYI"));

        gridLayout_31->addWidget(label_SPRAYI, 5, 0, 1, 1);

        doubleSpinBox_SPRAYP = new QDoubleSpinBox(groupBox_99);
        doubleSpinBox_SPRAYP->setObjectName(QStringLiteral("doubleSpinBox_SPRAYP"));

        gridLayout_31->addWidget(doubleSpinBox_SPRAYP, 4, 1, 1, 3);

        doubleSpinBox_SPRAYI = new QDoubleSpinBox(groupBox_99);
        doubleSpinBox_SPRAYI->setObjectName(QStringLiteral("doubleSpinBox_SPRAYI"));

        gridLayout_31->addWidget(doubleSpinBox_SPRAYI, 5, 1, 1, 3);

        pushButton_SPRAYASK = new QPushButton(groupBox_99);
        pushButton_SPRAYASK->setObjectName(QStringLiteral("pushButton_SPRAYASK"));

        gridLayout_31->addWidget(pushButton_SPRAYASK, 1, 6, 1, 1);

        pushButton_SPRAYSET = new QPushButton(groupBox_99);
        pushButton_SPRAYSET->setObjectName(QStringLiteral("pushButton_SPRAYSET"));

        gridLayout_31->addWidget(pushButton_SPRAYSET, 1, 5, 1, 1);

        label_288 = new QLabel(groupBox_99);
        label_288->setObjectName(QStringLiteral("label_288"));

        gridLayout_31->addWidget(label_288, 0, 4, 1, 1);

        label_289 = new QLabel(groupBox_99);
        label_289->setObjectName(QStringLiteral("label_289"));

        gridLayout_31->addWidget(label_289, 3, 4, 1, 1);

        label_SPRAYP = new QLabel(groupBox_99);
        label_SPRAYP->setObjectName(QStringLiteral("label_SPRAYP"));

        gridLayout_31->addWidget(label_SPRAYP, 4, 0, 1, 1);

        label_285 = new QLabel(groupBox_99);
        label_285->setObjectName(QStringLiteral("label_285"));

        gridLayout_31->addWidget(label_285, 1, 0, 1, 1);

        label_286 = new QLabel(groupBox_99);
        label_286->setObjectName(QStringLiteral("label_286"));

        gridLayout_31->addWidget(label_286, 3, 0, 1, 1);

        lineEdit_SPRAY_RANGE = new QLineEdit(groupBox_99);
        lineEdit_SPRAY_RANGE->setObjectName(QStringLiteral("lineEdit_SPRAY_RANGE"));
        lineEdit_SPRAY_RANGE->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_31->addWidget(lineEdit_SPRAY_RANGE, 0, 1, 1, 3);

        label_287 = new QLabel(groupBox_99);
        label_287->setObjectName(QStringLiteral("label_287"));

        gridLayout_31->addWidget(label_287, 1, 4, 1, 1);

        groupBox_39 = new QGroupBox(multisplashWidget);
        groupBox_39->setObjectName(QStringLiteral("groupBox_39"));
        groupBox_39->setGeometry(QRect(10, 10, 481, 162));
        gridLayout_17 = new QGridLayout(groupBox_39);
        gridLayout_17->setObjectName(QStringLiteral("gridLayout_17"));
        pushButton_SPRAY_VSET = new QPushButton(groupBox_39);
        pushButton_SPRAY_VSET->setObjectName(QStringLiteral("pushButton_SPRAY_VSET"));

        gridLayout_17->addWidget(pushButton_SPRAY_VSET, 4, 3, 1, 1);

        label_142 = new QLabel(groupBox_39);
        label_142->setObjectName(QStringLiteral("label_142"));

        gridLayout_17->addWidget(label_142, 0, 0, 1, 1);

        progressBar_SPRAY_INPUT = new QProgressBar(groupBox_39);
        progressBar_SPRAY_INPUT->setObjectName(QStringLiteral("progressBar_SPRAY_INPUT"));
        progressBar_SPRAY_INPUT->setMinimum(-100);
        progressBar_SPRAY_INPUT->setValue(0);

        gridLayout_17->addWidget(progressBar_SPRAY_INPUT, 0, 1, 1, 8);

        label_143 = new QLabel(groupBox_39);
        label_143->setObjectName(QStringLiteral("label_143"));

        gridLayout_17->addWidget(label_143, 1, 0, 1, 1);

        progressBar_SPRAY_OUTPUT = new QProgressBar(groupBox_39);
        progressBar_SPRAY_OUTPUT->setObjectName(QStringLiteral("progressBar_SPRAY_OUTPUT"));
        progressBar_SPRAY_OUTPUT->setMinimum(-100);
        progressBar_SPRAY_OUTPUT->setValue(0);

        gridLayout_17->addWidget(progressBar_SPRAY_OUTPUT, 1, 1, 1, 8);

        label_145 = new QLabel(groupBox_39);
        label_145->setObjectName(QStringLiteral("label_145"));

        gridLayout_17->addWidget(label_145, 2, 6, 1, 1);

        lineEdit_SPRAY_MODE = new QLineEdit(groupBox_39);
        lineEdit_SPRAY_MODE->setObjectName(QStringLiteral("lineEdit_SPRAY_MODE"));
        lineEdit_SPRAY_MODE->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_17->addWidget(lineEdit_SPRAY_MODE, 2, 7, 1, 1);

        label_148 = new QLabel(groupBox_39);
        label_148->setObjectName(QStringLiteral("label_148"));

        gridLayout_17->addWidget(label_148, 3, 6, 1, 1);

        lineEdit_SPRAY_V = new QLineEdit(groupBox_39);
        lineEdit_SPRAY_V->setObjectName(QStringLiteral("lineEdit_SPRAY_V"));
        lineEdit_SPRAY_V->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_17->addWidget(lineEdit_SPRAY_V, 3, 7, 1, 1);

        label_150 = new QLabel(groupBox_39);
        label_150->setObjectName(QStringLiteral("label_150"));

        gridLayout_17->addWidget(label_150, 3, 8, 1, 1);

        label_146 = new QLabel(groupBox_39);
        label_146->setObjectName(QStringLiteral("label_146"));

        gridLayout_17->addWidget(label_146, 4, 0, 1, 1);

        lineEdit_SPRAY_VSET = new QLineEdit(groupBox_39);
        lineEdit_SPRAY_VSET->setObjectName(QStringLiteral("lineEdit_SPRAY_VSET"));
        lineEdit_SPRAY_VSET->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_17->addWidget(lineEdit_SPRAY_VSET, 4, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(28, 19, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_17->addItem(horizontalSpacer_3, 4, 5, 1, 1);

        label_149 = new QLabel(groupBox_39);
        label_149->setObjectName(QStringLiteral("label_149"));

        gridLayout_17->addWidget(label_149, 4, 6, 1, 1);

        lineEdit_SPRAY_FLOW = new QLineEdit(groupBox_39);
        lineEdit_SPRAY_FLOW->setObjectName(QStringLiteral("lineEdit_SPRAY_FLOW"));
        lineEdit_SPRAY_FLOW->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_17->addWidget(lineEdit_SPRAY_FLOW, 4, 7, 1, 1);

        label_151 = new QLabel(groupBox_39);
        label_151->setObjectName(QStringLiteral("label_151"));

        gridLayout_17->addWidget(label_151, 4, 8, 1, 1);

        label_144 = new QLabel(groupBox_39);
        label_144->setObjectName(QStringLiteral("label_144"));

        gridLayout_17->addWidget(label_144, 2, 0, 2, 1);

        label_147 = new QLabel(groupBox_39);
        label_147->setObjectName(QStringLiteral("label_147"));

        gridLayout_17->addWidget(label_147, 4, 2, 1, 1);

        pushButton_SPRAY_RUNMODE = new QPushButton(groupBox_39);
        pushButton_SPRAY_RUNMODE->setObjectName(QStringLiteral("pushButton_SPRAY_RUNMODE"));

        gridLayout_17->addWidget(pushButton_SPRAY_RUNMODE, 3, 1, 1, 1);

        pushButton_SPRAY_TESTMODE = new QPushButton(groupBox_39);
        pushButton_SPRAY_TESTMODE->setObjectName(QStringLiteral("pushButton_SPRAY_TESTMODE"));

        gridLayout_17->addWidget(pushButton_SPRAY_TESTMODE, 2, 1, 1, 1);


        retranslateUi(multisplashWidget);

        QMetaObject::connectSlotsByName(multisplashWidget);
    } // setupUi

    void retranslateUi(QWidget *multisplashWidget)
    {
        multisplashWidget->setWindowTitle(QApplication::translate("multisplashWidget", "Form", 0));
        groupBox_99->setTitle(QApplication::translate("multisplashWidget", "\346\216\247\345\210\266\350\256\276\345\256\232", 0));
        lineEdit_SPRAY_LOW_V->setText(QApplication::translate("multisplashWidget", "N/A", 0));
        label_152->setText(QApplication::translate("multisplashWidget", "  \345\226\267\345\271\205\357\274\232", 0));
        lineEdit_SPRAY_AVE->setText(QApplication::translate("multisplashWidget", "N/A", 0));
        label_SPRAYI->setText(QApplication::translate("multisplashWidget", "  \347\247\257\345\210\206\357\274\232", 0));
        pushButton_SPRAYASK->setText(QApplication::translate("multisplashWidget", "\346\237\245\350\257\242", 0));
        pushButton_SPRAYSET->setText(QApplication::translate("multisplashWidget", "\350\256\276\347\275\256", 0));
        label_288->setText(QApplication::translate("multisplashWidget", "\347\261\263", 0));
        label_289->setText(QApplication::translate("multisplashWidget", "\347\261\263/\347\247\222", 0));
        label_SPRAYP->setText(QApplication::translate("multisplashWidget", "  \346\257\224\344\276\213\357\274\232", 0));
        label_285->setText(QApplication::translate("multisplashWidget", "  \350\215\257\351\207\217\357\274\232", 0));
        label_286->setText(QApplication::translate("multisplashWidget", "\346\234\200\344\275\216\351\200\237\357\274\232", 0));
        lineEdit_SPRAY_RANGE->setText(QApplication::translate("multisplashWidget", "N/A", 0));
        label_287->setText(QApplication::translate("multisplashWidget", "\346\257\253\345\215\207/\344\272\251", 0));
        groupBox_39->setTitle(QApplication::translate("multisplashWidget", "\345\226\267\346\264\222\347\263\273\347\273\237\346\265\213\350\257\225", 0));
        pushButton_SPRAY_VSET->setText(QApplication::translate("multisplashWidget", "\346\237\245\350\257\242", 0));
        label_142->setText(QApplication::translate("multisplashWidget", "  \350\276\223\345\205\245\357\274\232", 0));
        progressBar_SPRAY_INPUT->setFormat(QApplication::translate("multisplashWidget", "%v", 0));
        label_143->setText(QApplication::translate("multisplashWidget", "  \350\276\223\345\207\272\357\274\232", 0));
        progressBar_SPRAY_OUTPUT->setFormat(QApplication::translate("multisplashWidget", "%v", 0));
        label_145->setText(QApplication::translate("multisplashWidget", "\345\275\223\345\211\215\346\250\241\345\274\217\357\274\232", 0));
        lineEdit_SPRAY_MODE->setText(QApplication::translate("multisplashWidget", "N/A", 0));
        label_148->setText(QApplication::translate("multisplashWidget", "\345\275\223\345\211\215\351\200\237\345\272\246\357\274\232", 0));
        lineEdit_SPRAY_V->setText(QApplication::translate("multisplashWidget", "N/A", 0));
        label_150->setText(QApplication::translate("multisplashWidget", "\347\261\263/\347\247\222", 0));
        label_146->setText(QApplication::translate("multisplashWidget", "\351\200\237\345\272\246\350\256\276\345\256\232\357\274\232", 0));
        lineEdit_SPRAY_VSET->setText(QApplication::translate("multisplashWidget", "N/A", 0));
        label_149->setText(QApplication::translate("multisplashWidget", "\345\275\223\345\211\215\346\265\201\351\207\217\357\274\232", 0));
        lineEdit_SPRAY_FLOW->setText(QApplication::translate("multisplashWidget", "N/A", 0));
        label_151->setText(QApplication::translate("multisplashWidget", "\346\257\253\345\215\207/\347\247\222", 0));
        label_144->setText(QApplication::translate("multisplashWidget", "\346\250\241\345\274\217\351\200\211\346\213\251\357\274\232", 0));
        label_147->setText(QApplication::translate("multisplashWidget", "\347\261\263/\347\247\222", 0));
        pushButton_SPRAY_RUNMODE->setText(QApplication::translate("multisplashWidget", "\350\277\220\350\241\214\346\250\241\345\274\217", 0));
        pushButton_SPRAY_TESTMODE->setText(QApplication::translate("multisplashWidget", "\346\265\213\350\257\225\346\250\241\345\274\217", 0));
    } // retranslateUi

};

namespace Ui {
    class multisplashWidget: public Ui_multisplashWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MULTISPLASHWIDGET_H
