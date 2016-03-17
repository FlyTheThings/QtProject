/********************************************************************************
** Form generated from reading UI file 'fblrudwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FBLRUDWIDGET_H
#define UI_FBLRUDWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QFblrudWidget
{
public:
    QGroupBox *groupBox_38;
    QGroupBox *groupBox_40;
    QComboBox *comboBox_RUDSERVO;
    QLabel *label_124;
    QPushButton *pushButton_RUDSERVOSET;
    QPushButton *pushButton_RUDSERVOASK;
    QGroupBox *groupBox_98;
    QGridLayout *gridLayout_15;
    QPushButton *pushButton_RUDRANGEASK;
    QLabel *label_RUDRANGEMAX;
    QLabel *label_139;
    QPushButton *pushButton_RUDSERVODIR;
    QLabel *label_167;
    QLabel *label_290;
    QPushButton *pushButton_RUDRANGESET;
    QLabel *label_RUDRANGEMIN;
    QSlider *horizontalSlider_RUDRANGEMAX;
    QSlider *horizontalSlider_RUDRANGEMIN;
    QSlider *horizontalSlider_SOFFSET;
    QLabel *label_11;
    QLabel *label_SOFFSET;
    QLabel *label_141;
    QPushButton *pushButton_GYROTYPEASK;
    QRadioButton *radioButton_GYROTYPE1;
    QPushButton *pushButton_GYROTYPESET;
    QRadioButton *radioButton_GYROTYPE2;
    QGroupBox *groupBox_36;
    QLabel *label_130;
    QPushButton *pushButton_FBLASK;
    QRadioButton *radioButton_FBL;
    QRadioButton *radioButton_NOFBL;
    QPushButton *pushButton_FBLSET;
    QGroupBox *groupBox_4;
    QLabel *label_FBL_ELE;
    QLabel *label_292;
    QLabel *label_FBL_AIL;
    QSlider *horizontalSlider_FBL_AIL;
    QSlider *horizontalSlider_FBL_ELE;
    QLabel *label_163;

    void setupUi(QWidget *QFblrudWidget)
    {
        if (QFblrudWidget->objectName().isEmpty())
            QFblrudWidget->setObjectName(QStringLiteral("QFblrudWidget"));
        QFblrudWidget->resize(621, 497);
        groupBox_38 = new QGroupBox(QFblrudWidget);
        groupBox_38->setObjectName(QStringLiteral("groupBox_38"));
        groupBox_38->setGeometry(QRect(0, 220, 481, 281));
        groupBox_40 = new QGroupBox(groupBox_38);
        groupBox_40->setObjectName(QStringLiteral("groupBox_40"));
        groupBox_40->setGeometry(QRect(10, 50, 461, 221));
        comboBox_RUDSERVO = new QComboBox(groupBox_40);
        comboBox_RUDSERVO->setObjectName(QStringLiteral("comboBox_RUDSERVO"));
        comboBox_RUDSERVO->setGeometry(QRect(81, 21, 91, 20));
        label_124 = new QLabel(groupBox_40);
        label_124->setObjectName(QStringLiteral("label_124"));
        label_124->setGeometry(QRect(10, 20, 71, 20));
        pushButton_RUDSERVOSET = new QPushButton(groupBox_40);
        pushButton_RUDSERVOSET->setObjectName(QStringLiteral("pushButton_RUDSERVOSET"));
        pushButton_RUDSERVOSET->setGeometry(QRect(210, 20, 75, 23));
        pushButton_RUDSERVOASK = new QPushButton(groupBox_40);
        pushButton_RUDSERVOASK->setObjectName(QStringLiteral("pushButton_RUDSERVOASK"));
        pushButton_RUDSERVOASK->setGeometry(QRect(290, 20, 75, 23));
        groupBox_98 = new QGroupBox(groupBox_40);
        groupBox_98->setObjectName(QStringLiteral("groupBox_98"));
        groupBox_98->setGeometry(QRect(0, 60, 451, 151));
        gridLayout_15 = new QGridLayout(groupBox_98);
        gridLayout_15->setObjectName(QStringLiteral("gridLayout_15"));
        pushButton_RUDRANGEASK = new QPushButton(groupBox_98);
        pushButton_RUDRANGEASK->setObjectName(QStringLiteral("pushButton_RUDRANGEASK"));

        gridLayout_15->addWidget(pushButton_RUDRANGEASK, 3, 5, 1, 1);

        label_RUDRANGEMAX = new QLabel(groupBox_98);
        label_RUDRANGEMAX->setObjectName(QStringLiteral("label_RUDRANGEMAX"));

        gridLayout_15->addWidget(label_RUDRANGEMAX, 2, 4, 1, 1);

        label_139 = new QLabel(groupBox_98);
        label_139->setObjectName(QStringLiteral("label_139"));

        gridLayout_15->addWidget(label_139, 0, 0, 1, 2);

        pushButton_RUDSERVODIR = new QPushButton(groupBox_98);
        pushButton_RUDSERVODIR->setObjectName(QStringLiteral("pushButton_RUDSERVODIR"));
        pushButton_RUDSERVODIR->setEnabled(true);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/dir1.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_RUDSERVODIR->setIcon(icon);
        pushButton_RUDSERVODIR->setIconSize(QSize(22, 22));
        pushButton_RUDSERVODIR->setCheckable(true);

        gridLayout_15->addWidget(pushButton_RUDSERVODIR, 0, 2, 1, 1);

        label_167 = new QLabel(groupBox_98);
        label_167->setObjectName(QStringLiteral("label_167"));

        gridLayout_15->addWidget(label_167, 2, 0, 1, 1);

        label_290 = new QLabel(groupBox_98);
        label_290->setObjectName(QStringLiteral("label_290"));

        gridLayout_15->addWidget(label_290, 3, 0, 1, 1);

        pushButton_RUDRANGESET = new QPushButton(groupBox_98);
        pushButton_RUDRANGESET->setObjectName(QStringLiteral("pushButton_RUDRANGESET"));

        gridLayout_15->addWidget(pushButton_RUDRANGESET, 2, 5, 1, 1);

        label_RUDRANGEMIN = new QLabel(groupBox_98);
        label_RUDRANGEMIN->setObjectName(QStringLiteral("label_RUDRANGEMIN"));

        gridLayout_15->addWidget(label_RUDRANGEMIN, 3, 4, 1, 1);

        horizontalSlider_RUDRANGEMAX = new QSlider(groupBox_98);
        horizontalSlider_RUDRANGEMAX->setObjectName(QStringLiteral("horizontalSlider_RUDRANGEMAX"));
        horizontalSlider_RUDRANGEMAX->setEnabled(true);
        horizontalSlider_RUDRANGEMAX->setMaximum(150);
        horizontalSlider_RUDRANGEMAX->setOrientation(Qt::Horizontal);
        horizontalSlider_RUDRANGEMAX->setTickPosition(QSlider::TicksBelow);

        gridLayout_15->addWidget(horizontalSlider_RUDRANGEMAX, 2, 1, 1, 3);

        horizontalSlider_RUDRANGEMIN = new QSlider(groupBox_98);
        horizontalSlider_RUDRANGEMIN->setObjectName(QStringLiteral("horizontalSlider_RUDRANGEMIN"));
        horizontalSlider_RUDRANGEMIN->setEnabled(true);
        horizontalSlider_RUDRANGEMIN->setMaximum(150);
        horizontalSlider_RUDRANGEMIN->setOrientation(Qt::Horizontal);
        horizontalSlider_RUDRANGEMIN->setTickPosition(QSlider::TicksBelow);

        gridLayout_15->addWidget(horizontalSlider_RUDRANGEMIN, 3, 1, 1, 3);

        horizontalSlider_SOFFSET = new QSlider(groupBox_98);
        horizontalSlider_SOFFSET->setObjectName(QStringLiteral("horizontalSlider_SOFFSET"));
        horizontalSlider_SOFFSET->setMinimum(-100);
        horizontalSlider_SOFFSET->setMaximum(100);
        horizontalSlider_SOFFSET->setOrientation(Qt::Horizontal);
        horizontalSlider_SOFFSET->setTickPosition(QSlider::TicksBelow);

        gridLayout_15->addWidget(horizontalSlider_SOFFSET, 1, 1, 1, 3);

        label_11 = new QLabel(groupBox_98);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_15->addWidget(label_11, 1, 0, 1, 1);

        label_SOFFSET = new QLabel(groupBox_98);
        label_SOFFSET->setObjectName(QStringLiteral("label_SOFFSET"));

        gridLayout_15->addWidget(label_SOFFSET, 1, 4, 1, 1);

        label_141 = new QLabel(groupBox_38);
        label_141->setObjectName(QStringLiteral("label_141"));
        label_141->setGeometry(QRect(10, 20, 81, 21));
        pushButton_GYROTYPEASK = new QPushButton(groupBox_38);
        pushButton_GYROTYPEASK->setObjectName(QStringLiteral("pushButton_GYROTYPEASK"));
        pushButton_GYROTYPEASK->setGeometry(QRect(300, 20, 75, 23));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/ask.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_GYROTYPEASK->setIcon(icon1);
        pushButton_GYROTYPEASK->setIconSize(QSize(22, 22));
        radioButton_GYROTYPE1 = new QRadioButton(groupBox_38);
        radioButton_GYROTYPE1->setObjectName(QStringLiteral("radioButton_GYROTYPE1"));
        radioButton_GYROTYPE1->setGeometry(QRect(103, 23, 47, 16));
        pushButton_GYROTYPESET = new QPushButton(groupBox_38);
        pushButton_GYROTYPESET->setObjectName(QStringLiteral("pushButton_GYROTYPESET"));
        pushButton_GYROTYPESET->setGeometry(QRect(220, 20, 75, 23));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/set1.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_GYROTYPESET->setIcon(icon2);
        pushButton_GYROTYPESET->setIconSize(QSize(22, 22));
        radioButton_GYROTYPE2 = new QRadioButton(groupBox_38);
        radioButton_GYROTYPE2->setObjectName(QStringLiteral("radioButton_GYROTYPE2"));
        radioButton_GYROTYPE2->setGeometry(QRect(156, 23, 47, 16));
        groupBox_36 = new QGroupBox(QFblrudWidget);
        groupBox_36->setObjectName(QStringLiteral("groupBox_36"));
        groupBox_36->setGeometry(QRect(0, 10, 481, 181));
        label_130 = new QLabel(groupBox_36);
        label_130->setObjectName(QStringLiteral("label_130"));
        label_130->setGeometry(QRect(20, 21, 54, 21));
        pushButton_FBLASK = new QPushButton(groupBox_36);
        pushButton_FBLASK->setObjectName(QStringLiteral("pushButton_FBLASK"));
        pushButton_FBLASK->setGeometry(QRect(270, 150, 75, 23));
        radioButton_FBL = new QRadioButton(groupBox_36);
        radioButton_FBL->setObjectName(QStringLiteral("radioButton_FBL"));
        radioButton_FBL->setGeometry(QRect(89, 23, 59, 16));
        radioButton_NOFBL = new QRadioButton(groupBox_36);
        radioButton_NOFBL->setObjectName(QStringLiteral("radioButton_NOFBL"));
        radioButton_NOFBL->setGeometry(QRect(154, 23, 59, 16));
        pushButton_FBLSET = new QPushButton(groupBox_36);
        pushButton_FBLSET->setObjectName(QStringLiteral("pushButton_FBLSET"));
        pushButton_FBLSET->setGeometry(QRect(120, 150, 75, 23));
        groupBox_4 = new QGroupBox(groupBox_36);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 50, 451, 81));
        label_FBL_ELE = new QLabel(groupBox_4);
        label_FBL_ELE->setObjectName(QStringLiteral("label_FBL_ELE"));
        label_FBL_ELE->setGeometry(QRect(320, 20, 40, 24));
        label_292 = new QLabel(groupBox_4);
        label_292->setObjectName(QStringLiteral("label_292"));
        label_292->setGeometry(QRect(10, 50, 40, 24));
        label_FBL_AIL = new QLabel(groupBox_4);
        label_FBL_AIL->setObjectName(QStringLiteral("label_FBL_AIL"));
        label_FBL_AIL->setGeometry(QRect(320, 50, 40, 24));
        horizontalSlider_FBL_AIL = new QSlider(groupBox_4);
        horizontalSlider_FBL_AIL->setObjectName(QStringLiteral("horizontalSlider_FBL_AIL"));
        horizontalSlider_FBL_AIL->setEnabled(true);
        horizontalSlider_FBL_AIL->setGeometry(QRect(50, 50, 271, 24));
        horizontalSlider_FBL_AIL->setMaximum(500);
        horizontalSlider_FBL_AIL->setPageStep(50);
        horizontalSlider_FBL_AIL->setOrientation(Qt::Horizontal);
        horizontalSlider_FBL_AIL->setTickPosition(QSlider::TicksBelow);
        horizontalSlider_FBL_ELE = new QSlider(groupBox_4);
        horizontalSlider_FBL_ELE->setObjectName(QStringLiteral("horizontalSlider_FBL_ELE"));
        horizontalSlider_FBL_ELE->setEnabled(true);
        horizontalSlider_FBL_ELE->setGeometry(QRect(50, 20, 271, 24));
        horizontalSlider_FBL_ELE->setMaximum(500);
        horizontalSlider_FBL_ELE->setPageStep(50);
        horizontalSlider_FBL_ELE->setOrientation(Qt::Horizontal);
        horizontalSlider_FBL_ELE->setTickPosition(QSlider::TicksBelow);
        label_163 = new QLabel(groupBox_4);
        label_163->setObjectName(QStringLiteral("label_163"));
        label_163->setGeometry(QRect(10, 20, 51, 24));

        retranslateUi(QFblrudWidget);

        QMetaObject::connectSlotsByName(QFblrudWidget);
    } // setupUi

    void retranslateUi(QWidget *QFblrudWidget)
    {
        QFblrudWidget->setWindowTitle(QApplication::translate("QFblrudWidget", "Form", 0));
        groupBox_38->setTitle(QApplication::translate("QFblrudWidget", "\351\224\201\345\260\276\351\205\215\347\275\256", 0));
        groupBox_40->setTitle(QApplication::translate("QFblrudWidget", "\351\224\201\345\260\276\350\210\265\346\234\272", 0));
        comboBox_RUDSERVO->clear();
        comboBox_RUDSERVO->insertItems(0, QStringList()
         << QApplication::translate("QFblrudWidget", "1520us 50HZ", 0)
         << QApplication::translate("QFblrudWidget", "1520us 125HZ", 0)
         << QApplication::translate("QFblrudWidget", "1520us 333HZ", 0)
         << QApplication::translate("QFblrudWidget", "760us  333HZ", 0)
         << QApplication::translate("QFblrudWidget", "760us  560HZ", 0)
        );
        label_124->setText(QApplication::translate("QFblrudWidget", "\345\260\276\350\210\265\346\234\272\347\261\273\345\236\213\357\274\232", 0));
        pushButton_RUDSERVOSET->setText(QApplication::translate("QFblrudWidget", "\350\256\276\347\275\256", 0));
        pushButton_RUDSERVOASK->setText(QApplication::translate("QFblrudWidget", "\346\237\245\350\257\242", 0));
        groupBox_98->setTitle(QApplication::translate("QFblrudWidget", "\346\236\201\346\200\247/\350\241\214\347\250\213", 0));
        pushButton_RUDRANGEASK->setText(QApplication::translate("QFblrudWidget", "\346\237\245\350\257\242", 0));
        label_RUDRANGEMAX->setText(QApplication::translate("QFblrudWidget", " 0 ", 0));
        label_139->setText(QApplication::translate("QFblrudWidget", "\350\210\265\346\234\272\346\236\201\346\200\247\357\274\232", 0));
        pushButton_RUDSERVODIR->setText(QApplication::translate("QFblrudWidget", "\346\255\243\345\220\221", 0));
        label_167->setText(QApplication::translate("QFblrudWidget", "\351\231\220\344\275\215A", 0));
        label_290->setText(QApplication::translate("QFblrudWidget", "\351\231\220\344\275\215B", 0));
        pushButton_RUDRANGESET->setText(QApplication::translate("QFblrudWidget", "\350\256\276\347\275\256", 0));
        label_RUDRANGEMIN->setText(QApplication::translate("QFblrudWidget", " 0", 0));
        label_11->setText(QApplication::translate("QFblrudWidget", "\345\276\256\350\260\203", 0));
        label_SOFFSET->setText(QApplication::translate("QFblrudWidget", " 0", 0));
        label_141->setText(QApplication::translate("QFblrudWidget", "\351\224\201\345\260\276\351\231\200\350\236\272\347\261\273\345\236\213\357\274\232", 0));
        pushButton_GYROTYPEASK->setText(QApplication::translate("QFblrudWidget", "\346\237\245\350\257\242", 0));
        radioButton_GYROTYPE1->setText(QApplication::translate("QFblrudWidget", "\345\206\205\347\275\256", 0));
        pushButton_GYROTYPESET->setText(QApplication::translate("QFblrudWidget", "\350\256\276\347\275\256", 0));
        radioButton_GYROTYPE2->setText(QApplication::translate("QFblrudWidget", "\345\244\226\347\275\256", 0));
        groupBox_36->setTitle(QApplication::translate("QFblrudWidget", "\346\227\213\347\277\274\351\205\215\347\275\256", 0));
        label_130->setText(QApplication::translate("QFblrudWidget", "\346\227\213\347\277\274\347\261\273\345\236\213\357\274\232", 0));
        pushButton_FBLASK->setText(QApplication::translate("QFblrudWidget", "\346\237\245\350\257\242", 0));
        radioButton_FBL->setText(QApplication::translate("QFblrudWidget", "\346\234\211\345\211\257\347\277\274", 0));
        radioButton_NOFBL->setText(QApplication::translate("QFblrudWidget", "\346\227\240\345\211\257\347\277\274", 0));
        pushButton_FBLSET->setText(QApplication::translate("QFblrudWidget", "\350\256\276\347\275\256", 0));
        groupBox_4->setTitle(QApplication::translate("QFblrudWidget", "\345\217\202\346\225\260", 0));
        label_FBL_ELE->setText(QApplication::translate("QFblrudWidget", " 0 ", 0));
        label_292->setText(QApplication::translate("QFblrudWidget", "\345\267\246\345\217\263", 0));
        label_FBL_AIL->setText(QApplication::translate("QFblrudWidget", " 0", 0));
        label_163->setText(QApplication::translate("QFblrudWidget", "\345\215\207\351\231\215", 0));
    } // retranslateUi

};

namespace Ui {
    class QFblrudWidget: public Ui_QFblrudWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FBLRUDWIDGET_H
