/********************************************************************************
** Form generated from reading UI file 'rpmgyroWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RPMGYROWIDGET_H
#define UI_RPMGYROWIDGET_H

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
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QRpmgyroWidget
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
    QPushButton *pushButton_PSIOFFASK;
    QPushButton *pushButton_PSIOFFSET;
    QGroupBox *groupBox_43;
    QRadioButton *radioButton_RPMTYPE2;
    QLabel *label_132;
    QRadioButton *radioButton_RPMTYPE1;
    QPushButton *pushButton_RPMTYPESET;
    QPushButton *pushButton_RPMTYPEASK;
    QGroupBox *groupBox_97;
    QGridLayout *gridLayout_10;
    QPushButton *pushButton_COLSERVORANGEASK;
    QLabel *label_COLSERVORANGEMAX;
    QLabel *label_134;
    QPushButton *pushButton_COLDIR;
    QLabel *label_133;
    QLabel *label_284;
    QPushButton *pushButton_COLSERVORANGESET;
    QLabel *label_COLSERVORANGEMIN;
    QSlider *horizontalSlider_COLSERVORANGEMAX;
    QSlider *horizontalSlider_COLSERVORANGEMIN;
    QSlider *horizontalSlider_engoffset;
    QLabel *label_10;
    QLabel *label_engoffset;
    QGroupBox *groupBox_;
    QSlider *horizontalSlider_ENG;
    QPushButton *pushButton_IDLINGSET;
    QPushButton *pushButton_FLAMEOUTSET;
    QPushButton *pushButton_SPEEDTEST;
    QPushButton *pushButton_SPEEDSET;
    QPushButton *pushButton_HIGHSPEEDSET;
    QPushButton *pushButton_FLAMEOUTTEST;
    QPushButton *pushButton_IDLINGTEST;
    QPushButton *pushButton_HIGHSPEEDTEST;
    QLabel *label_COL;
    QLabel *label_114;
    QLabel *label_135;
    QLineEdit *lineEdit_RPM1;
    QLineEdit *lineEdit_RPM2;
    QLabel *label_136;
    QLabel *label_137;
    QLabel *label_138;
    QLineEdit *lineEdit_RPM;
    QPushButton *pushButton_RPMASK;
    QPushButton *pushButton_RPMSET;
    QGroupBox *groupBox_41;
    QLabel *label_RPMI;
    QPushButton *pushButton_CONSTANT_SPEEDASK;
    QPushButton *pushButton_CONSTANT_SPEEDSET;
    QSlider *horizontalSlider_RPMI;

    void setupUi(QWidget *QRpmgyroWidget)
    {
        if (QRpmgyroWidget->objectName().isEmpty())
            QRpmgyroWidget->setObjectName(QStringLiteral("QRpmgyroWidget"));
        QRpmgyroWidget->resize(799, 466);
        groupBox_46 = new QGroupBox(QRpmgyroWidget);
        groupBox_46->setObjectName(QStringLiteral("groupBox_46"));
        groupBox_46->setGeometry(QRect(400, 0, 391, 161));
        label_82 = new QLabel(groupBox_46);
        label_82->setObjectName(QStringLiteral("label_82"));
        label_82->setGeometry(QRect(20, 22, 48, 16));
        lineEdit_PSIOFF = new QLineEdit(groupBox_46);
        lineEdit_PSIOFF->setObjectName(QStringLiteral("lineEdit_PSIOFF"));
        lineEdit_PSIOFF->setGeometry(QRect(80, 22, 111, 20));
        groupBox_48 = new QGroupBox(groupBox_46);
        groupBox_48->setObjectName(QStringLiteral("groupBox_48"));
        groupBox_48->setGeometry(QRect(0, 50, 391, 111));
        pushButton_CALSTART = new QPushButton(groupBox_48);
        pushButton_CALSTART->setObjectName(QStringLiteral("pushButton_CALSTART"));
        pushButton_CALSTART->setGeometry(QRect(20, 70, 75, 23));
        pushButton_CALEND = new QPushButton(groupBox_48);
        pushButton_CALEND->setObjectName(QStringLiteral("pushButton_CALEND"));
        pushButton_CALEND->setGeometry(QRect(210, 70, 75, 23));
        pushButton_CALASK = new QPushButton(groupBox_48);
        pushButton_CALASK->setObjectName(QStringLiteral("pushButton_CALASK"));
        pushButton_CALASK->setGeometry(QRect(300, 70, 75, 23));
        pushButton_CALSTOP = new QPushButton(groupBox_48);
        pushButton_CALSTOP->setObjectName(QStringLiteral("pushButton_CALSTOP"));
        pushButton_CALSTOP->setGeometry(QRect(120, 70, 75, 23));
        label_22 = new QLabel(groupBox_48);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(20, 30, 41, 16));
        lineEdit_KX = new QLineEdit(groupBox_48);
        lineEdit_KX->setObjectName(QStringLiteral("lineEdit_KX"));
        lineEdit_KX->setGeometry(QRect(60, 30, 41, 20));
        label_25 = new QLabel(groupBox_48);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(110, 30, 41, 16));
        lineEdit_KY = new QLineEdit(groupBox_48);
        lineEdit_KY->setObjectName(QStringLiteral("lineEdit_KY"));
        lineEdit_KY->setGeometry(QRect(150, 30, 41, 20));
        label_26 = new QLabel(groupBox_48);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(200, 30, 41, 16));
        lineEdit_BX = new QLineEdit(groupBox_48);
        lineEdit_BX->setObjectName(QStringLiteral("lineEdit_BX"));
        lineEdit_BX->setGeometry(QRect(240, 30, 41, 20));
        label_27 = new QLabel(groupBox_48);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setGeometry(QRect(290, 30, 41, 16));
        lineEdit_BY = new QLineEdit(groupBox_48);
        lineEdit_BY->setObjectName(QStringLiteral("lineEdit_BY"));
        lineEdit_BY->setGeometry(QRect(330, 30, 41, 20));
        pushButton_PSIOFFASK = new QPushButton(groupBox_46);
        pushButton_PSIOFFASK->setObjectName(QStringLiteral("pushButton_PSIOFFASK"));
        pushButton_PSIOFFASK->setGeometry(QRect(290, 20, 75, 23));
        pushButton_PSIOFFSET = new QPushButton(groupBox_46);
        pushButton_PSIOFFSET->setObjectName(QStringLiteral("pushButton_PSIOFFSET"));
        pushButton_PSIOFFSET->setGeometry(QRect(207, 20, 75, 23));
        groupBox_43 = new QGroupBox(QRpmgyroWidget);
        groupBox_43->setObjectName(QStringLiteral("groupBox_43"));
        groupBox_43->setGeometry(QRect(0, 0, 381, 461));
        radioButton_RPMTYPE2 = new QRadioButton(groupBox_43);
        radioButton_RPMTYPE2->setObjectName(QStringLiteral("radioButton_RPMTYPE2"));
        radioButton_RPMTYPE2->setGeometry(QRect(150, 23, 59, 16));
        label_132 = new QLabel(groupBox_43);
        label_132->setObjectName(QStringLiteral("label_132"));
        label_132->setGeometry(QRect(10, 21, 71, 21));
        radioButton_RPMTYPE1 = new QRadioButton(groupBox_43);
        radioButton_RPMTYPE1->setObjectName(QStringLiteral("radioButton_RPMTYPE1"));
        radioButton_RPMTYPE1->setGeometry(QRect(90, 23, 59, 16));
        pushButton_RPMTYPESET = new QPushButton(groupBox_43);
        pushButton_RPMTYPESET->setObjectName(QStringLiteral("pushButton_RPMTYPESET"));
        pushButton_RPMTYPESET->setGeometry(QRect(209, 20, 75, 23));
        pushButton_RPMTYPESET->setMouseTracking(false);
        pushButton_RPMTYPESET->setFocusPolicy(Qt::StrongFocus);
        pushButton_RPMTYPESET->setContextMenuPolicy(Qt::DefaultContextMenu);
        pushButton_RPMTYPESET->setCheckable(false);
        pushButton_RPMTYPESET->setChecked(false);
        pushButton_RPMTYPESET->setAutoRepeat(false);
        pushButton_RPMTYPESET->setAutoExclusive(false);
        pushButton_RPMTYPESET->setAutoRepeatDelay(300);
        pushButton_RPMTYPESET->setFlat(false);
        pushButton_RPMTYPEASK = new QPushButton(groupBox_43);
        pushButton_RPMTYPEASK->setObjectName(QStringLiteral("pushButton_RPMTYPEASK"));
        pushButton_RPMTYPEASK->setGeometry(QRect(290, 20, 75, 23));
        groupBox_97 = new QGroupBox(groupBox_43);
        groupBox_97->setObjectName(QStringLiteral("groupBox_97"));
        groupBox_97->setGeometry(QRect(10, 50, 361, 151));
        gridLayout_10 = new QGridLayout(groupBox_97);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        pushButton_COLSERVORANGEASK = new QPushButton(groupBox_97);
        pushButton_COLSERVORANGEASK->setObjectName(QStringLiteral("pushButton_COLSERVORANGEASK"));

        gridLayout_10->addWidget(pushButton_COLSERVORANGEASK, 3, 5, 1, 1);

        label_COLSERVORANGEMAX = new QLabel(groupBox_97);
        label_COLSERVORANGEMAX->setObjectName(QStringLiteral("label_COLSERVORANGEMAX"));

        gridLayout_10->addWidget(label_COLSERVORANGEMAX, 2, 4, 1, 1);

        label_134 = new QLabel(groupBox_97);
        label_134->setObjectName(QStringLiteral("label_134"));

        gridLayout_10->addWidget(label_134, 0, 0, 1, 2);

        pushButton_COLDIR = new QPushButton(groupBox_97);
        pushButton_COLDIR->setObjectName(QStringLiteral("pushButton_COLDIR"));
        pushButton_COLDIR->setEnabled(true);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/dir1.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_COLDIR->setIcon(icon);
        pushButton_COLDIR->setIconSize(QSize(22, 22));
        pushButton_COLDIR->setCheckable(true);

        gridLayout_10->addWidget(pushButton_COLDIR, 0, 2, 1, 1);

        label_133 = new QLabel(groupBox_97);
        label_133->setObjectName(QStringLiteral("label_133"));

        gridLayout_10->addWidget(label_133, 2, 0, 1, 1);

        label_284 = new QLabel(groupBox_97);
        label_284->setObjectName(QStringLiteral("label_284"));

        gridLayout_10->addWidget(label_284, 3, 0, 1, 1);

        pushButton_COLSERVORANGESET = new QPushButton(groupBox_97);
        pushButton_COLSERVORANGESET->setObjectName(QStringLiteral("pushButton_COLSERVORANGESET"));

        gridLayout_10->addWidget(pushButton_COLSERVORANGESET, 2, 5, 1, 1);

        label_COLSERVORANGEMIN = new QLabel(groupBox_97);
        label_COLSERVORANGEMIN->setObjectName(QStringLiteral("label_COLSERVORANGEMIN"));

        gridLayout_10->addWidget(label_COLSERVORANGEMIN, 3, 4, 1, 1);

        horizontalSlider_COLSERVORANGEMAX = new QSlider(groupBox_97);
        horizontalSlider_COLSERVORANGEMAX->setObjectName(QStringLiteral("horizontalSlider_COLSERVORANGEMAX"));
        horizontalSlider_COLSERVORANGEMAX->setEnabled(true);
        horizontalSlider_COLSERVORANGEMAX->setMaximum(150);
        horizontalSlider_COLSERVORANGEMAX->setOrientation(Qt::Horizontal);
        horizontalSlider_COLSERVORANGEMAX->setTickPosition(QSlider::TicksBelow);

        gridLayout_10->addWidget(horizontalSlider_COLSERVORANGEMAX, 2, 1, 1, 3);

        horizontalSlider_COLSERVORANGEMIN = new QSlider(groupBox_97);
        horizontalSlider_COLSERVORANGEMIN->setObjectName(QStringLiteral("horizontalSlider_COLSERVORANGEMIN"));
        horizontalSlider_COLSERVORANGEMIN->setEnabled(true);
        horizontalSlider_COLSERVORANGEMIN->setMaximum(150);
        horizontalSlider_COLSERVORANGEMIN->setOrientation(Qt::Horizontal);
        horizontalSlider_COLSERVORANGEMIN->setTickPosition(QSlider::TicksBelow);

        gridLayout_10->addWidget(horizontalSlider_COLSERVORANGEMIN, 3, 1, 1, 3);

        horizontalSlider_engoffset = new QSlider(groupBox_97);
        horizontalSlider_engoffset->setObjectName(QStringLiteral("horizontalSlider_engoffset"));
        horizontalSlider_engoffset->setMinimum(-100);
        horizontalSlider_engoffset->setMaximum(100);
        horizontalSlider_engoffset->setOrientation(Qt::Horizontal);
        horizontalSlider_engoffset->setTickPosition(QSlider::TicksBelow);

        gridLayout_10->addWidget(horizontalSlider_engoffset, 1, 1, 1, 3);

        label_10 = new QLabel(groupBox_97);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_10->addWidget(label_10, 1, 0, 1, 1);

        label_engoffset = new QLabel(groupBox_97);
        label_engoffset->setObjectName(QStringLiteral("label_engoffset"));

        gridLayout_10->addWidget(label_engoffset, 1, 4, 1, 1);

        groupBox_ = new QGroupBox(groupBox_43);
        groupBox_->setObjectName(QStringLiteral("groupBox_"));
        groupBox_->setGeometry(QRect(10, 210, 361, 121));
        horizontalSlider_ENG = new QSlider(groupBox_);
        horizontalSlider_ENG->setObjectName(QStringLiteral("horizontalSlider_ENG"));
        horizontalSlider_ENG->setGeometry(QRect(10, 90, 321, 21));
        horizontalSlider_ENG->setMinimum(-150);
        horizontalSlider_ENG->setMaximum(150);
        horizontalSlider_ENG->setValue(0);
        horizontalSlider_ENG->setOrientation(Qt::Horizontal);
        pushButton_IDLINGSET = new QPushButton(groupBox_);
        pushButton_IDLINGSET->setObjectName(QStringLiteral("pushButton_IDLINGSET"));
        pushButton_IDLINGSET->setGeometry(QRect(100, 20, 75, 23));
        pushButton_FLAMEOUTSET = new QPushButton(groupBox_);
        pushButton_FLAMEOUTSET->setObjectName(QStringLiteral("pushButton_FLAMEOUTSET"));
        pushButton_FLAMEOUTSET->setGeometry(QRect(10, 20, 75, 23));
        pushButton_SPEEDTEST = new QPushButton(groupBox_);
        pushButton_SPEEDTEST->setObjectName(QStringLiteral("pushButton_SPEEDTEST"));
        pushButton_SPEEDTEST->setGeometry(QRect(190, 60, 75, 23));
        pushButton_SPEEDSET = new QPushButton(groupBox_);
        pushButton_SPEEDSET->setObjectName(QStringLiteral("pushButton_SPEEDSET"));
        pushButton_SPEEDSET->setGeometry(QRect(190, 20, 75, 23));
        pushButton_HIGHSPEEDSET = new QPushButton(groupBox_);
        pushButton_HIGHSPEEDSET->setObjectName(QStringLiteral("pushButton_HIGHSPEEDSET"));
        pushButton_HIGHSPEEDSET->setGeometry(QRect(280, 20, 75, 23));
        pushButton_FLAMEOUTTEST = new QPushButton(groupBox_);
        pushButton_FLAMEOUTTEST->setObjectName(QStringLiteral("pushButton_FLAMEOUTTEST"));
        pushButton_FLAMEOUTTEST->setGeometry(QRect(10, 60, 75, 23));
        pushButton_IDLINGTEST = new QPushButton(groupBox_);
        pushButton_IDLINGTEST->setObjectName(QStringLiteral("pushButton_IDLINGTEST"));
        pushButton_IDLINGTEST->setGeometry(QRect(100, 60, 75, 23));
        pushButton_HIGHSPEEDTEST = new QPushButton(groupBox_);
        pushButton_HIGHSPEEDTEST->setObjectName(QStringLiteral("pushButton_HIGHSPEEDTEST"));
        pushButton_HIGHSPEEDTEST->setGeometry(QRect(280, 60, 75, 23));
        label_COL = new QLabel(groupBox_);
        label_COL->setObjectName(QStringLiteral("label_COL"));
        label_COL->setGeometry(QRect(330, 86, 34, 26));
        label_114 = new QLabel(groupBox_43);
        label_114->setObjectName(QStringLiteral("label_114"));
        label_114->setGeometry(QRect(10, 336, 54, 20));
        label_135 = new QLabel(groupBox_43);
        label_135->setObjectName(QStringLiteral("label_135"));
        label_135->setGeometry(QRect(74, 339, 54, 16));
        lineEdit_RPM1 = new QLineEdit(groupBox_43);
        lineEdit_RPM1->setObjectName(QStringLiteral("lineEdit_RPM1"));
        lineEdit_RPM1->setGeometry(QRect(10, 360, 51, 20));
        lineEdit_RPM1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_RPM2 = new QLineEdit(groupBox_43);
        lineEdit_RPM2->setObjectName(QStringLiteral("lineEdit_RPM2"));
        lineEdit_RPM2->setGeometry(QRect(72, 360, 41, 20));
        lineEdit_RPM2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_136 = new QLabel(groupBox_43);
        label_136->setObjectName(QStringLiteral("label_136"));
        label_136->setGeometry(QRect(60, 360, 16, 21));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_136->setFont(font);
        label_137 = new QLabel(groupBox_43);
        label_137->setObjectName(QStringLiteral("label_137"));
        label_137->setGeometry(QRect(120, 360, 16, 21));
        label_137->setFont(font);
        label_138 = new QLabel(groupBox_43);
        label_138->setObjectName(QStringLiteral("label_138"));
        label_138->setGeometry(QRect(130, 330, 91, 31));
        lineEdit_RPM = new QLineEdit(groupBox_43);
        lineEdit_RPM->setObjectName(QStringLiteral("lineEdit_RPM"));
        lineEdit_RPM->setGeometry(QRect(140, 360, 71, 20));
        lineEdit_RPM->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pushButton_RPMASK = new QPushButton(groupBox_43);
        pushButton_RPMASK->setObjectName(QStringLiteral("pushButton_RPMASK"));
        pushButton_RPMASK->setGeometry(QRect(300, 360, 75, 23));
        pushButton_RPMSET = new QPushButton(groupBox_43);
        pushButton_RPMSET->setObjectName(QStringLiteral("pushButton_RPMSET"));
        pushButton_RPMSET->setGeometry(QRect(220, 360, 75, 23));
        groupBox_41 = new QGroupBox(groupBox_43);
        groupBox_41->setObjectName(QStringLiteral("groupBox_41"));
        groupBox_41->setGeometry(QRect(0, 400, 381, 61));
        label_RPMI = new QLabel(groupBox_41);
        label_RPMI->setObjectName(QStringLiteral("label_RPMI"));
        label_RPMI->setGeometry(QRect(180, 20, 40, 24));
        pushButton_CONSTANT_SPEEDASK = new QPushButton(groupBox_41);
        pushButton_CONSTANT_SPEEDASK->setObjectName(QStringLiteral("pushButton_CONSTANT_SPEEDASK"));
        pushButton_CONSTANT_SPEEDASK->setGeometry(QRect(290, 20, 75, 23));
        pushButton_CONSTANT_SPEEDSET = new QPushButton(groupBox_41);
        pushButton_CONSTANT_SPEEDSET->setObjectName(QStringLiteral("pushButton_CONSTANT_SPEEDSET"));
        pushButton_CONSTANT_SPEEDSET->setGeometry(QRect(209, 20, 75, 23));
        horizontalSlider_RPMI = new QSlider(groupBox_41);
        horizontalSlider_RPMI->setObjectName(QStringLiteral("horizontalSlider_RPMI"));
        horizontalSlider_RPMI->setEnabled(true);
        horizontalSlider_RPMI->setGeometry(QRect(10, 23, 161, 26));
        horizontalSlider_RPMI->setMaximum(500);
        horizontalSlider_RPMI->setOrientation(Qt::Horizontal);
        horizontalSlider_RPMI->setTickPosition(QSlider::TicksBelow);

        retranslateUi(QRpmgyroWidget);

        QMetaObject::connectSlotsByName(QRpmgyroWidget);
    } // setupUi

    void retranslateUi(QWidget *QRpmgyroWidget)
    {
        QRpmgyroWidget->setWindowTitle(QApplication::translate("QRpmgyroWidget", "Form", 0));
        groupBox_46->setTitle(QApplication::translate("QRpmgyroWidget", "\347\275\227\347\233\230\346\240\241\345\207\206", 0));
        label_82->setText(QApplication::translate("QRpmgyroWidget", "\345\234\260\347\243\201\345\201\217\350\247\222", 0));
        groupBox_48->setTitle(QApplication::translate("QRpmgyroWidget", "\346\240\241\345\207\206", 0));
        pushButton_CALSTART->setText(QApplication::translate("QRpmgyroWidget", "\345\274\200\345\247\213\346\240\241\345\207\206", 0));
        pushButton_CALEND->setText(QApplication::translate("QRpmgyroWidget", "\346\240\241\345\207\206\345\256\214\346\210\220", 0));
        pushButton_CALASK->setText(QApplication::translate("QRpmgyroWidget", "\346\225\260\346\215\256\346\237\245\350\257\242", 0));
        pushButton_CALSTOP->setText(QApplication::translate("QRpmgyroWidget", "\346\240\241\345\207\206\344\270\255\346\255\242", 0));
        label_22->setText(QApplication::translate("QRpmgyroWidget", "X\345\242\236\347\233\212\357\274\232", 0));
        label_25->setText(QApplication::translate("QRpmgyroWidget", "Y\345\242\236\347\233\212\357\274\232", 0));
        label_26->setText(QApplication::translate("QRpmgyroWidget", "X\345\201\217\345\267\256\357\274\232", 0));
        label_27->setText(QApplication::translate("QRpmgyroWidget", "Y\345\201\217\345\267\256\357\274\232", 0));
        pushButton_PSIOFFASK->setText(QApplication::translate("QRpmgyroWidget", "\346\237\245\350\257\242", 0));
        pushButton_PSIOFFSET->setText(QApplication::translate("QRpmgyroWidget", "\350\256\276\347\275\256", 0));
        groupBox_43->setTitle(QApplication::translate("QRpmgyroWidget", "\345\217\221\345\212\250\346\234\272\351\205\215\347\275\256", 0));
        radioButton_RPMTYPE2->setText(QApplication::translate("QRpmgyroWidget", "\345\244\226\347\275\256", 0));
        label_132->setText(QApplication::translate("QRpmgyroWidget", "\345\256\232\351\200\237\344\273\252\347\261\273\345\236\213\357\274\232", 0));
        radioButton_RPMTYPE1->setText(QApplication::translate("QRpmgyroWidget", "\345\206\205\347\275\256", 0));
        pushButton_RPMTYPESET->setText(QApplication::translate("QRpmgyroWidget", "\350\256\276\347\275\256", 0));
        pushButton_RPMTYPEASK->setText(QApplication::translate("QRpmgyroWidget", "\346\237\245\350\257\242", 0));
        groupBox_97->setTitle(QApplication::translate("QRpmgyroWidget", "\346\262\271\351\227\250\350\210\265\346\234\272", 0));
        pushButton_COLSERVORANGEASK->setText(QApplication::translate("QRpmgyroWidget", "\346\237\245\350\257\242", 0));
        label_COLSERVORANGEMAX->setText(QApplication::translate("QRpmgyroWidget", " 0 ", 0));
        label_134->setText(QApplication::translate("QRpmgyroWidget", "\350\210\265\346\234\272\346\236\201\346\200\247\357\274\232", 0));
        pushButton_COLDIR->setText(QApplication::translate("QRpmgyroWidget", "\346\255\243\345\220\221", 0));
        label_133->setText(QApplication::translate("QRpmgyroWidget", "\351\231\220\344\275\215A", 0));
        label_284->setText(QApplication::translate("QRpmgyroWidget", "\351\231\220\344\275\215B", 0));
        pushButton_COLSERVORANGESET->setText(QApplication::translate("QRpmgyroWidget", "\350\256\276\347\275\256", 0));
        label_COLSERVORANGEMIN->setText(QApplication::translate("QRpmgyroWidget", " 0", 0));
        label_10->setText(QApplication::translate("QRpmgyroWidget", "\345\276\256\350\260\203", 0));
        label_engoffset->setText(QApplication::translate("QRpmgyroWidget", " 0", 0));
        groupBox_->setTitle(QApplication::translate("QRpmgyroWidget", "\346\262\271\351\227\250\344\275\215\347\275\256\350\256\276\347\275\256", 0));
        pushButton_IDLINGSET->setText(QApplication::translate("QRpmgyroWidget", "\350\256\276\347\275\256\346\200\240\351\200\237\347\202\271", 0));
        pushButton_FLAMEOUTSET->setText(QApplication::translate("QRpmgyroWidget", "\350\256\276\347\275\256\347\206\204\347\201\253\347\202\271", 0));
        pushButton_SPEEDTEST->setText(QApplication::translate("QRpmgyroWidget", "\346\265\213\350\257\225\345\256\232\351\200\237\347\202\271", 0));
        pushButton_SPEEDSET->setText(QApplication::translate("QRpmgyroWidget", "\350\256\276\347\275\256\345\256\232\351\200\237\347\202\271", 0));
        pushButton_HIGHSPEEDSET->setText(QApplication::translate("QRpmgyroWidget", "\350\256\276\347\275\256\346\234\200\351\253\230\347\202\271", 0));
        pushButton_FLAMEOUTTEST->setText(QApplication::translate("QRpmgyroWidget", "\346\265\213\350\257\225\347\206\204\347\201\253\347\202\271", 0));
        pushButton_IDLINGTEST->setText(QApplication::translate("QRpmgyroWidget", "\346\265\213\350\257\225\346\200\240\351\200\237\347\202\271", 0));
        pushButton_HIGHSPEEDTEST->setText(QApplication::translate("QRpmgyroWidget", "\346\265\213\350\257\225\346\234\200\351\253\230\347\202\271", 0));
        label_COL->setText(QApplication::translate("QRpmgyroWidget", " 0 ", 0));
        label_114->setText(QApplication::translate("QRpmgyroWidget", "\346\227\213\347\277\274\350\275\254\351\200\237", 0));
        label_135->setText(QApplication::translate("QRpmgyroWidget", "\351\275\277\350\275\256\346\257\224", 0));
        lineEdit_RPM1->setText(QApplication::translate("QRpmgyroWidget", "0", 0));
        lineEdit_RPM2->setText(QApplication::translate("QRpmgyroWidget", "0", 0));
        label_136->setText(QApplication::translate("QRpmgyroWidget", "\303\227", 0));
        label_137->setText(QApplication::translate("QRpmgyroWidget", "==", 0));
        label_138->setText(QApplication::translate("QRpmgyroWidget", "\345\217\221\345\212\250\346\234\272\350\275\254\351\200\237/RPM", 0));
        lineEdit_RPM->setText(QApplication::translate("QRpmgyroWidget", "0", 0));
        pushButton_RPMASK->setText(QApplication::translate("QRpmgyroWidget", "\346\237\245\350\257\242", 0));
        pushButton_RPMSET->setText(QApplication::translate("QRpmgyroWidget", "\350\256\276\347\275\256", 0));
        groupBox_41->setTitle(QApplication::translate("QRpmgyroWidget", "\345\256\232\351\200\237\345\242\236\347\233\212", 0));
        label_RPMI->setText(QApplication::translate("QRpmgyroWidget", " 0 ", 0));
        pushButton_CONSTANT_SPEEDASK->setText(QApplication::translate("QRpmgyroWidget", "\346\237\245\350\257\242", 0));
        pushButton_CONSTANT_SPEEDSET->setText(QApplication::translate("QRpmgyroWidget", "\350\256\276\347\275\256", 0));
    } // retranslateUi

};

namespace Ui {
    class QRpmgyroWidget: public Ui_QRpmgyroWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RPMGYROWIDGET_H
