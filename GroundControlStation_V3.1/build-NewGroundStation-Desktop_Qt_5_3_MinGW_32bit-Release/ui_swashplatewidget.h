/********************************************************************************
** Form generated from reading UI file 'swashplatewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SWASHPLATEWIDGET_H
#define UI_SWASHPLATEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QSwashplateWidget
{
public:
    QGroupBox *groupBox_2;
    QRadioButton *radioButton_H1;
    QRadioButton *radioButton_H3;
    QRadioButton *radioButton_HR3;
    QRadioButton *radioButton_H140;
    QRadioButton *radioButton_HE3;
    QRadioButton *radioButton_H4;
    QPushButton *pushButton_TILTTYPESET;
    QPushButton *pushButton_TILTTYPEASK;
    QGroupBox *groupBox_37;
    QPushButton *pushButton_TILTPHASESET;
    QLabel *label_phase;
    QSlider *horizontalSlider_phase;
    QPushButton *pushButton_TILTPHASEASK;
    QGroupBox *groupBox_72;
    QPushButton *pushButton_TILTDIRSET;
    QPushButton *pushButton_TILTDIRASK;
    QLabel *label;
    QPushButton *pushButton_ELEDIRECT;
    QPushButton *pushButton_AILDIRECT;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton_COLDIRECT;
    QLabel *label_MIXELE;
    QSlider *horizontalSlider_MIXELE;
    QSlider *horizontalSlider_MIXAIL;
    QLabel *label_MIXCOL;
    QSlider *horizontalSlider_MIXCOL;
    QLabel *label_MIXAIL;
    QLabel *label_115;
    QGroupBox *groupBox_s;
    QLabel *label_116;
    QLabel *label_117;
    QLabel *label_118;
    QLabel *label_119;
    QLabel *label_120;
    QPushButton *pushButton_S1DIR;
    QPushButton *pushButton_S2DIR;
    QPushButton *pushButton_S3DIR;
    QPushButton *pushButton_S4DIR;
    QSlider *horizontalSlider_S1;
    QSlider *horizontalSlider_S2;
    QSlider *horizontalSlider_S3;
    QSlider *horizontalSlider_S4;
    QLabel *label_121;
    QLabel *label_S1;
    QLabel *label_S2;
    QLabel *label_S3;
    QLabel *label_S4;
    QPushButton *pushButton_TILTS1ASK;
    QPushButton *pushButton_TILTS1SET;
    QPushButton *pushButton_TILTS2SET;
    QPushButton *pushButton_TILTS2ASK;
    QPushButton *pushButton_TILTS3SET;
    QPushButton *pushButton_TILTS3ASK;
    QPushButton *pushButton_TILTS4SET;
    QPushButton *pushButton_TILTS4ASK;
    QLabel *label_TILTTYPE;

    void setupUi(QWidget *QSwashplateWidget)
    {
        if (QSwashplateWidget->objectName().isEmpty())
            QSwashplateWidget->setObjectName(QStringLiteral("QSwashplateWidget"));
        QSwashplateWidget->resize(853, 420);
        groupBox_2 = new QGroupBox(QSwashplateWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 0, 271, 101));
        radioButton_H1 = new QRadioButton(groupBox_2);
        radioButton_H1->setObjectName(QStringLiteral("radioButton_H1"));
        radioButton_H1->setGeometry(QRect(10, 30, 35, 16));
        radioButton_H3 = new QRadioButton(groupBox_2);
        radioButton_H3->setObjectName(QStringLiteral("radioButton_H3"));
        radioButton_H3->setGeometry(QRect(70, 30, 35, 16));
        radioButton_HR3 = new QRadioButton(groupBox_2);
        radioButton_HR3->setObjectName(QStringLiteral("radioButton_HR3"));
        radioButton_HR3->setGeometry(QRect(130, 30, 47, 16));
        radioButton_H140 = new QRadioButton(groupBox_2);
        radioButton_H140->setObjectName(QStringLiteral("radioButton_H140"));
        radioButton_H140->setGeometry(QRect(11, 70, 47, 16));
        radioButton_HE3 = new QRadioButton(groupBox_2);
        radioButton_HE3->setObjectName(QStringLiteral("radioButton_HE3"));
        radioButton_HE3->setGeometry(QRect(70, 70, 41, 16));
        radioButton_H4 = new QRadioButton(groupBox_2);
        radioButton_H4->setObjectName(QStringLiteral("radioButton_H4"));
        radioButton_H4->setGeometry(QRect(130, 70, 35, 16));
        pushButton_TILTTYPESET = new QPushButton(groupBox_2);
        pushButton_TILTTYPESET->setObjectName(QStringLiteral("pushButton_TILTTYPESET"));
        pushButton_TILTTYPESET->setGeometry(QRect(190, 30, 75, 23));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/set.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_TILTTYPESET->setIcon(icon);
        pushButton_TILTTYPESET->setIconSize(QSize(22, 22));
        pushButton_TILTTYPEASK = new QPushButton(groupBox_2);
        pushButton_TILTTYPEASK->setObjectName(QStringLiteral("pushButton_TILTTYPEASK"));
        pushButton_TILTTYPEASK->setGeometry(QRect(190, 64, 75, 23));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/ask.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_TILTTYPEASK->setIcon(icon1);
        pushButton_TILTTYPEASK->setIconSize(QSize(22, 22));
        groupBox_37 = new QGroupBox(QSwashplateWidget);
        groupBox_37->setObjectName(QStringLiteral("groupBox_37"));
        groupBox_37->setGeometry(QRect(280, 0, 191, 101));
        QFont font;
        font.setUnderline(false);
        groupBox_37->setFont(font);
        pushButton_TILTPHASESET = new QPushButton(groupBox_37);
        pushButton_TILTPHASESET->setObjectName(QStringLiteral("pushButton_TILTPHASESET"));
        pushButton_TILTPHASESET->setGeometry(QRect(10, 70, 75, 23));
        pushButton_TILTPHASESET->setIcon(icon);
        pushButton_TILTPHASESET->setIconSize(QSize(22, 22));
        label_phase = new QLabel(groupBox_37);
        label_phase->setObjectName(QStringLiteral("label_phase"));
        label_phase->setGeometry(QRect(160, 36, 31, 16));
        horizontalSlider_phase = new QSlider(groupBox_37);
        horizontalSlider_phase->setObjectName(QStringLiteral("horizontalSlider_phase"));
        horizontalSlider_phase->setGeometry(QRect(10, 30, 141, 26));
        horizontalSlider_phase->setMinimum(-180);
        horizontalSlider_phase->setMaximum(180);
        horizontalSlider_phase->setOrientation(Qt::Horizontal);
        horizontalSlider_phase->setTickPosition(QSlider::TicksAbove);
        pushButton_TILTPHASEASK = new QPushButton(groupBox_37);
        pushButton_TILTPHASEASK->setObjectName(QStringLiteral("pushButton_TILTPHASEASK"));
        pushButton_TILTPHASEASK->setGeometry(QRect(90, 70, 75, 23));
        pushButton_TILTPHASEASK->setIcon(icon1);
        pushButton_TILTPHASEASK->setIconSize(QSize(22, 22));
        groupBox_72 = new QGroupBox(QSwashplateWidget);
        groupBox_72->setObjectName(QStringLiteral("groupBox_72"));
        groupBox_72->setGeometry(QRect(0, 110, 471, 111));
        pushButton_TILTDIRSET = new QPushButton(groupBox_72);
        pushButton_TILTDIRSET->setObjectName(QStringLiteral("pushButton_TILTDIRSET"));
        pushButton_TILTDIRSET->setEnabled(true);
        pushButton_TILTDIRSET->setGeometry(QRect(370, 30, 75, 23));
        pushButton_TILTDIRSET->setIcon(icon);
        pushButton_TILTDIRSET->setIconSize(QSize(22, 22));
        pushButton_TILTDIRASK = new QPushButton(groupBox_72);
        pushButton_TILTDIRASK->setObjectName(QStringLiteral("pushButton_TILTDIRASK"));
        pushButton_TILTDIRASK->setEnabled(true);
        pushButton_TILTDIRASK->setGeometry(QRect(370, 70, 75, 23));
        pushButton_TILTDIRASK->setIcon(icon1);
        pushButton_TILTDIRASK->setIconSize(QSize(22, 22));
        label = new QLabel(groupBox_72);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(15, 22, 24, 24));
        pushButton_ELEDIRECT = new QPushButton(groupBox_72);
        pushButton_ELEDIRECT->setObjectName(QStringLiteral("pushButton_ELEDIRECT"));
        pushButton_ELEDIRECT->setEnabled(true);
        pushButton_ELEDIRECT->setGeometry(QRect(60, 22, 64, 24));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/dir1.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_ELEDIRECT->setIcon(icon2);
        pushButton_ELEDIRECT->setIconSize(QSize(22, 22));
        pushButton_ELEDIRECT->setCheckable(true);
        pushButton_ELEDIRECT->setAutoDefault(false);
        pushButton_ELEDIRECT->setDefault(false);
        pushButton_ELEDIRECT->setFlat(false);
        pushButton_AILDIRECT = new QPushButton(groupBox_72);
        pushButton_AILDIRECT->setObjectName(QStringLiteral("pushButton_AILDIRECT"));
        pushButton_AILDIRECT->setEnabled(true);
        pushButton_AILDIRECT->setGeometry(QRect(59, 50, 64, 24));
        pushButton_AILDIRECT->setIcon(icon2);
        pushButton_AILDIRECT->setIconSize(QSize(22, 22));
        pushButton_AILDIRECT->setCheckable(true);
        pushButton_AILDIRECT->setChecked(false);
        label_2 = new QLabel(groupBox_72);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(16, 50, 24, 24));
        label_3 = new QLabel(groupBox_72);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(16, 80, 24, 24));
        pushButton_COLDIRECT = new QPushButton(groupBox_72);
        pushButton_COLDIRECT->setObjectName(QStringLiteral("pushButton_COLDIRECT"));
        pushButton_COLDIRECT->setEnabled(true);
        pushButton_COLDIRECT->setGeometry(QRect(59, 80, 64, 24));
        pushButton_COLDIRECT->setIcon(icon2);
        pushButton_COLDIRECT->setIconSize(QSize(22, 22));
        pushButton_COLDIRECT->setCheckable(true);
        label_MIXELE = new QLabel(groupBox_72);
        label_MIXELE->setObjectName(QStringLiteral("label_MIXELE"));
        label_MIXELE->setGeometry(QRect(330, 16, 31, 26));
        horizontalSlider_MIXELE = new QSlider(groupBox_72);
        horizontalSlider_MIXELE->setObjectName(QStringLiteral("horizontalSlider_MIXELE"));
        horizontalSlider_MIXELE->setGeometry(QRect(130, 20, 191, 21));
        horizontalSlider_MIXELE->setMinimum(0);
        horizontalSlider_MIXELE->setMaximum(150);
        horizontalSlider_MIXELE->setValue(60);
        horizontalSlider_MIXELE->setOrientation(Qt::Horizontal);
        horizontalSlider_MIXELE->setTickPosition(QSlider::TicksAbove);
        horizontalSlider_MIXAIL = new QSlider(groupBox_72);
        horizontalSlider_MIXAIL->setObjectName(QStringLiteral("horizontalSlider_MIXAIL"));
        horizontalSlider_MIXAIL->setGeometry(QRect(130, 50, 191, 21));
        horizontalSlider_MIXAIL->setMinimum(0);
        horizontalSlider_MIXAIL->setMaximum(150);
        horizontalSlider_MIXAIL->setValue(60);
        horizontalSlider_MIXAIL->setOrientation(Qt::Horizontal);
        horizontalSlider_MIXAIL->setTickPosition(QSlider::TicksAbove);
        label_MIXCOL = new QLabel(groupBox_72);
        label_MIXCOL->setObjectName(QStringLiteral("label_MIXCOL"));
        label_MIXCOL->setGeometry(QRect(330, 76, 31, 26));
        horizontalSlider_MIXCOL = new QSlider(groupBox_72);
        horizontalSlider_MIXCOL->setObjectName(QStringLiteral("horizontalSlider_MIXCOL"));
        horizontalSlider_MIXCOL->setGeometry(QRect(130, 80, 191, 21));
        horizontalSlider_MIXCOL->setMinimum(0);
        horizontalSlider_MIXCOL->setMaximum(150);
        horizontalSlider_MIXCOL->setValue(60);
        horizontalSlider_MIXCOL->setOrientation(Qt::Horizontal);
        horizontalSlider_MIXCOL->setTickPosition(QSlider::TicksAbove);
        label_MIXAIL = new QLabel(groupBox_72);
        label_MIXAIL->setObjectName(QStringLiteral("label_MIXAIL"));
        label_MIXAIL->setGeometry(QRect(330, 46, 31, 26));
        label_115 = new QLabel(QSwashplateWidget);
        label_115->setObjectName(QStringLiteral("label_115"));
        label_115->setGeometry(QRect(600, 260, 108, 16));
        groupBox_s = new QGroupBox(QSwashplateWidget);
        groupBox_s->setObjectName(QStringLiteral("groupBox_s"));
        groupBox_s->setGeometry(QRect(0, 230, 471, 181));
        label_116 = new QLabel(groupBox_s);
        label_116->setObjectName(QStringLiteral("label_116"));
        label_116->setGeometry(QRect(10, 50, 16, 16));
        label_117 = new QLabel(groupBox_s);
        label_117->setObjectName(QStringLiteral("label_117"));
        label_117->setGeometry(QRect(10, 80, 16, 16));
        label_118 = new QLabel(groupBox_s);
        label_118->setObjectName(QStringLiteral("label_118"));
        label_118->setGeometry(QRect(10, 110, 16, 16));
        label_119 = new QLabel(groupBox_s);
        label_119->setObjectName(QStringLiteral("label_119"));
        label_119->setGeometry(QRect(10, 140, 16, 16));
        label_120 = new QLabel(groupBox_s);
        label_120->setObjectName(QStringLiteral("label_120"));
        label_120->setGeometry(QRect(50, 20, 31, 16));
        pushButton_S1DIR = new QPushButton(groupBox_s);
        pushButton_S1DIR->setObjectName(QStringLiteral("pushButton_S1DIR"));
        pushButton_S1DIR->setEnabled(true);
        pushButton_S1DIR->setGeometry(QRect(30, 45, 64, 23));
        pushButton_S1DIR->setIcon(icon2);
        pushButton_S1DIR->setIconSize(QSize(22, 22));
        pushButton_S1DIR->setCheckable(true);
        pushButton_S2DIR = new QPushButton(groupBox_s);
        pushButton_S2DIR->setObjectName(QStringLiteral("pushButton_S2DIR"));
        pushButton_S2DIR->setEnabled(true);
        pushButton_S2DIR->setGeometry(QRect(30, 76, 64, 23));
        pushButton_S2DIR->setIcon(icon2);
        pushButton_S2DIR->setIconSize(QSize(22, 22));
        pushButton_S2DIR->setCheckable(true);
        pushButton_S3DIR = new QPushButton(groupBox_s);
        pushButton_S3DIR->setObjectName(QStringLiteral("pushButton_S3DIR"));
        pushButton_S3DIR->setEnabled(true);
        pushButton_S3DIR->setGeometry(QRect(30, 107, 64, 23));
        pushButton_S3DIR->setIcon(icon2);
        pushButton_S3DIR->setIconSize(QSize(22, 22));
        pushButton_S3DIR->setCheckable(true);
        pushButton_S4DIR = new QPushButton(groupBox_s);
        pushButton_S4DIR->setObjectName(QStringLiteral("pushButton_S4DIR"));
        pushButton_S4DIR->setEnabled(true);
        pushButton_S4DIR->setGeometry(QRect(30, 136, 64, 23));
        pushButton_S4DIR->setIcon(icon2);
        pushButton_S4DIR->setIconSize(QSize(22, 22));
        pushButton_S4DIR->setCheckable(true);
        horizontalSlider_S1 = new QSlider(groupBox_s);
        horizontalSlider_S1->setObjectName(QStringLiteral("horizontalSlider_S1"));
        horizontalSlider_S1->setGeometry(QRect(100, 46, 171, 21));
        horizontalSlider_S1->setMinimum(-100);
        horizontalSlider_S1->setMaximum(100);
        horizontalSlider_S1->setOrientation(Qt::Horizontal);
        horizontalSlider_S1->setTickPosition(QSlider::TicksAbove);
        horizontalSlider_S2 = new QSlider(groupBox_s);
        horizontalSlider_S2->setObjectName(QStringLiteral("horizontalSlider_S2"));
        horizontalSlider_S2->setGeometry(QRect(100, 79, 171, 21));
        horizontalSlider_S2->setMinimum(-100);
        horizontalSlider_S2->setMaximum(100);
        horizontalSlider_S2->setOrientation(Qt::Horizontal);
        horizontalSlider_S2->setTickPosition(QSlider::TicksAbove);
        horizontalSlider_S3 = new QSlider(groupBox_s);
        horizontalSlider_S3->setObjectName(QStringLiteral("horizontalSlider_S3"));
        horizontalSlider_S3->setGeometry(QRect(100, 109, 171, 21));
        horizontalSlider_S3->setMinimum(-100);
        horizontalSlider_S3->setMaximum(100);
        horizontalSlider_S3->setOrientation(Qt::Horizontal);
        horizontalSlider_S3->setTickPosition(QSlider::TicksAbove);
        horizontalSlider_S4 = new QSlider(groupBox_s);
        horizontalSlider_S4->setObjectName(QStringLiteral("horizontalSlider_S4"));
        horizontalSlider_S4->setGeometry(QRect(100, 139, 171, 21));
        horizontalSlider_S4->setMinimum(-100);
        horizontalSlider_S4->setMaximum(100);
        horizontalSlider_S4->setOrientation(Qt::Horizontal);
        horizontalSlider_S4->setTickPosition(QSlider::TicksAbove);
        label_121 = new QLabel(groupBox_s);
        label_121->setObjectName(QStringLiteral("label_121"));
        label_121->setGeometry(QRect(180, 20, 31, 16));
        label_S1 = new QLabel(groupBox_s);
        label_S1->setObjectName(QStringLiteral("label_S1"));
        label_S1->setGeometry(QRect(280, 42, 31, 26));
        label_S2 = new QLabel(groupBox_s);
        label_S2->setObjectName(QStringLiteral("label_S2"));
        label_S2->setGeometry(QRect(280, 74, 31, 26));
        label_S3 = new QLabel(groupBox_s);
        label_S3->setObjectName(QStringLiteral("label_S3"));
        label_S3->setGeometry(QRect(280, 104, 31, 26));
        label_S4 = new QLabel(groupBox_s);
        label_S4->setObjectName(QStringLiteral("label_S4"));
        label_S4->setGeometry(QRect(280, 134, 31, 26));
        pushButton_TILTS1ASK = new QPushButton(groupBox_s);
        pushButton_TILTS1ASK->setObjectName(QStringLiteral("pushButton_TILTS1ASK"));
        pushButton_TILTS1ASK->setEnabled(true);
        pushButton_TILTS1ASK->setGeometry(QRect(380, 40, 71, 23));
        pushButton_TILTS1ASK->setIcon(icon1);
        pushButton_TILTS1ASK->setIconSize(QSize(22, 22));
        pushButton_TILTS1SET = new QPushButton(groupBox_s);
        pushButton_TILTS1SET->setObjectName(QStringLiteral("pushButton_TILTS1SET"));
        pushButton_TILTS1SET->setEnabled(true);
        pushButton_TILTS1SET->setGeometry(QRect(310, 40, 71, 23));
        pushButton_TILTS1SET->setIcon(icon);
        pushButton_TILTS1SET->setIconSize(QSize(22, 22));
        pushButton_TILTS2SET = new QPushButton(groupBox_s);
        pushButton_TILTS2SET->setObjectName(QStringLiteral("pushButton_TILTS2SET"));
        pushButton_TILTS2SET->setEnabled(true);
        pushButton_TILTS2SET->setGeometry(QRect(310, 74, 71, 23));
        pushButton_TILTS2SET->setIcon(icon);
        pushButton_TILTS2SET->setIconSize(QSize(22, 22));
        pushButton_TILTS2ASK = new QPushButton(groupBox_s);
        pushButton_TILTS2ASK->setObjectName(QStringLiteral("pushButton_TILTS2ASK"));
        pushButton_TILTS2ASK->setEnabled(true);
        pushButton_TILTS2ASK->setGeometry(QRect(380, 74, 71, 23));
        pushButton_TILTS2ASK->setIcon(icon1);
        pushButton_TILTS2ASK->setIconSize(QSize(22, 22));
        pushButton_TILTS3SET = new QPushButton(groupBox_s);
        pushButton_TILTS3SET->setObjectName(QStringLiteral("pushButton_TILTS3SET"));
        pushButton_TILTS3SET->setEnabled(true);
        pushButton_TILTS3SET->setGeometry(QRect(310, 108, 71, 23));
        pushButton_TILTS3SET->setIcon(icon);
        pushButton_TILTS3SET->setIconSize(QSize(22, 22));
        pushButton_TILTS3ASK = new QPushButton(groupBox_s);
        pushButton_TILTS3ASK->setObjectName(QStringLiteral("pushButton_TILTS3ASK"));
        pushButton_TILTS3ASK->setEnabled(true);
        pushButton_TILTS3ASK->setGeometry(QRect(380, 108, 71, 23));
        pushButton_TILTS3ASK->setIcon(icon1);
        pushButton_TILTS3ASK->setIconSize(QSize(22, 22));
        pushButton_TILTS4SET = new QPushButton(groupBox_s);
        pushButton_TILTS4SET->setObjectName(QStringLiteral("pushButton_TILTS4SET"));
        pushButton_TILTS4SET->setEnabled(true);
        pushButton_TILTS4SET->setGeometry(QRect(310, 140, 71, 23));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/set1.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_TILTS4SET->setIcon(icon3);
        pushButton_TILTS4SET->setIconSize(QSize(22, 22));
        pushButton_TILTS4ASK = new QPushButton(groupBox_s);
        pushButton_TILTS4ASK->setObjectName(QStringLiteral("pushButton_TILTS4ASK"));
        pushButton_TILTS4ASK->setEnabled(true);
        pushButton_TILTS4ASK->setGeometry(QRect(380, 140, 71, 23));
        pushButton_TILTS4ASK->setIcon(icon1);
        pushButton_TILTS4ASK->setIconSize(QSize(22, 22));
        label_TILTTYPE = new QLabel(QSwashplateWidget);
        label_TILTTYPE->setObjectName(QStringLiteral("label_TILTTYPE"));
        label_TILTTYPE->setGeometry(QRect(490, 0, 321, 251));
        label_TILTTYPE->setPixmap(QPixmap(QString::fromUtf8(":/qfi/images/H1.png")));

        retranslateUi(QSwashplateWidget);

        QMetaObject::connectSlotsByName(QSwashplateWidget);
    } // setupUi

    void retranslateUi(QWidget *QSwashplateWidget)
    {
        QSwashplateWidget->setWindowTitle(QApplication::translate("QSwashplateWidget", "Form", 0));
        groupBox_2->setTitle(QApplication::translate("QSwashplateWidget", "\345\215\201\345\255\227\347\233\230\347\261\273\345\236\213", 0));
        radioButton_H1->setText(QApplication::translate("QSwashplateWidget", "H1", 0));
        radioButton_H3->setText(QApplication::translate("QSwashplateWidget", "H3", 0));
        radioButton_HR3->setText(QApplication::translate("QSwashplateWidget", "HR-3", 0));
        radioButton_H140->setText(QApplication::translate("QSwashplateWidget", "H140", 0));
        radioButton_HE3->setText(QApplication::translate("QSwashplateWidget", "HE3", 0));
        radioButton_H4->setText(QApplication::translate("QSwashplateWidget", "H4", 0));
        pushButton_TILTTYPESET->setText(QApplication::translate("QSwashplateWidget", "\350\256\276\347\275\256", 0));
        pushButton_TILTTYPEASK->setText(QApplication::translate("QSwashplateWidget", "\346\237\245\350\257\242", 0));
        groupBox_37->setTitle(QApplication::translate("QSwashplateWidget", "\346\227\213\350\275\254", 0));
        pushButton_TILTPHASESET->setText(QApplication::translate("QSwashplateWidget", "\350\256\276\347\275\256", 0));
        label_phase->setText(QApplication::translate("QSwashplateWidget", " 0 \302\260", 0));
        pushButton_TILTPHASEASK->setText(QApplication::translate("QSwashplateWidget", "\346\237\245\350\257\242", 0));
        groupBox_72->setTitle(QApplication::translate("QSwashplateWidget", "\345\215\201\345\255\227\347\233\230\346\267\267\346\216\247\346\257\224", 0));
        pushButton_TILTDIRSET->setText(QApplication::translate("QSwashplateWidget", "\350\256\276\347\275\256", 0));
        pushButton_TILTDIRASK->setText(QApplication::translate("QSwashplateWidget", "\346\237\245\350\257\242", 0));
        label->setText(QApplication::translate("QSwashplateWidget", "\344\277\257\344\273\260", 0));
        pushButton_ELEDIRECT->setText(QApplication::translate("QSwashplateWidget", "\346\255\243\345\220\221", 0));
        pushButton_AILDIRECT->setText(QApplication::translate("QSwashplateWidget", "\346\255\243\345\220\221", 0));
        label_2->setText(QApplication::translate("QSwashplateWidget", "\346\273\232\350\275\254", 0));
        label_3->setText(QApplication::translate("QSwashplateWidget", "\346\200\273\350\267\235", 0));
        pushButton_COLDIRECT->setText(QApplication::translate("QSwashplateWidget", "\346\255\243\345\220\221", 0));
        label_MIXELE->setText(QApplication::translate("QSwashplateWidget", " 60% ", 0));
        label_MIXCOL->setText(QApplication::translate("QSwashplateWidget", " 60% ", 0));
        label_MIXAIL->setText(QApplication::translate("QSwashplateWidget", " 60% ", 0));
        label_115->setText(QApplication::translate("QSwashplateWidget", "\350\257\267\345\256\214\346\210\220\345\215\201\345\255\227\347\233\230\347\232\204\351\205\215\347\275\256", 0));
        groupBox_s->setTitle(QApplication::translate("QSwashplateWidget", "\345\215\201\345\255\227\347\233\230\350\210\265\346\234\272", 0));
        label_116->setText(QApplication::translate("QSwashplateWidget", "S1", 0));
        label_117->setText(QApplication::translate("QSwashplateWidget", "S2", 0));
        label_118->setText(QApplication::translate("QSwashplateWidget", "S3", 0));
        label_119->setText(QApplication::translate("QSwashplateWidget", "S4", 0));
        label_120->setText(QApplication::translate("QSwashplateWidget", "\346\226\271\345\220\221", 0));
        pushButton_S1DIR->setText(QApplication::translate("QSwashplateWidget", "\346\255\243\345\220\221", 0));
        pushButton_S2DIR->setText(QApplication::translate("QSwashplateWidget", "\346\255\243\345\220\221", 0));
        pushButton_S3DIR->setText(QApplication::translate("QSwashplateWidget", "\346\255\243\345\220\221", 0));
        pushButton_S4DIR->setText(QApplication::translate("QSwashplateWidget", "\346\255\243\345\220\221", 0));
        label_121->setText(QApplication::translate("QSwashplateWidget", "\345\276\256\350\260\203", 0));
        label_S1->setText(QApplication::translate("QSwashplateWidget", " 0 ", 0));
        label_S2->setText(QApplication::translate("QSwashplateWidget", " 0 ", 0));
        label_S3->setText(QApplication::translate("QSwashplateWidget", " 0 ", 0));
        label_S4->setText(QApplication::translate("QSwashplateWidget", " 0 ", 0));
        pushButton_TILTS1ASK->setText(QApplication::translate("QSwashplateWidget", "\346\237\245\350\257\242", 0));
        pushButton_TILTS1SET->setText(QApplication::translate("QSwashplateWidget", "\350\256\276\347\275\256", 0));
        pushButton_TILTS2SET->setText(QApplication::translate("QSwashplateWidget", "\350\256\276\347\275\256", 0));
        pushButton_TILTS2ASK->setText(QApplication::translate("QSwashplateWidget", "\346\237\245\350\257\242", 0));
        pushButton_TILTS3SET->setText(QApplication::translate("QSwashplateWidget", "\350\256\276\347\275\256", 0));
        pushButton_TILTS3ASK->setText(QApplication::translate("QSwashplateWidget", "\346\237\245\350\257\242", 0));
        pushButton_TILTS4SET->setText(QApplication::translate("QSwashplateWidget", "\350\256\276\347\275\256", 0));
        pushButton_TILTS4ASK->setText(QApplication::translate("QSwashplateWidget", "\346\237\245\350\257\242", 0));
        label_TILTTYPE->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class QSwashplateWidget: public Ui_QSwashplateWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SWASHPLATEWIDGET_H
