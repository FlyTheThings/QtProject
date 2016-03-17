/********************************************************************************
** Form generated from reading UI file 'rcWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RCWIDGET_H
#define UI_RCWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QRcWidget
{
public:
    QGroupBox *groupBox_11;
    QGridLayout *gridLayout_4;
    QPushButton *pushButton_rc_receiveset;
    QPushButton *pushButton_rc_receiveask;
    QComboBox *comboBox_captype;
    QGroupBox *groupBox_9;
    QLabel *label_160;
    QLabel *label_153;
    QLabel *label_154;
    QLabel *label_157;
    QLabel *label_161;
    QLabel *label_159;
    QLabel *label_166;
    QLabel *label_282;
    QLabel *label_165;
    QLabel *label_158;
    QLabel *label_162;
    QLabel *label_164;
    QLabel *label_155;
    QLabel *label_28;
    QLabel *label_156;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QProgressBar *progressBar_cap1;
    QProgressBar *progressBar_cap2;
    QProgressBar *progressBar_cap3;
    QProgressBar *progressBar_cap4;
    QProgressBar *progressBar_cap5;
    QProgressBar *progressBar_cap6;
    QProgressBar *progressBar_cap7;
    QProgressBar *progressBar_cap8;
    QProgressBar *progressBar_cap9;
    QProgressBar *progressBar_cap10;
    QWidget *widget1;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_switch;
    QPushButton *pushButton_ele;
    QPushButton *pushButton_ail;
    QPushButton *pushButton_col;
    QPushButton *pushButton_rud;
    QPushButton *pushButton_oil;
    QPushButton *pushButton_en;
    QPushButton *pushButton_water;
    QPushButton *pushButton_flow;
    QPushButton *pushButton_rc10;
    QWidget *widget2;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *lineEdit_cap1max;
    QLineEdit *lineEdit_cap2max;
    QLineEdit *lineEdit_cap3max;
    QLineEdit *lineEdit_cap4max;
    QLineEdit *lineEdit_cap5max;
    QLineEdit *lineEdit_cap6max;
    QLineEdit *lineEdit_cap7max;
    QLineEdit *lineEdit_cap8max;
    QLineEdit *lineEdit_cap9max;
    QLineEdit *lineEdit_cap10max;
    QWidget *widget3;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *lineEdit_cap1mid;
    QLineEdit *lineEdit_cap2mid;
    QLineEdit *lineEdit_cap3mid;
    QLineEdit *lineEdit_cap4mid;
    QLineEdit *lineEdit_cap5mid;
    QLineEdit *lineEdit_cap6mid;
    QLineEdit *lineEdit_cap7mid;
    QLineEdit *lineEdit_cap8mid;
    QLineEdit *lineEdit_cap9mid;
    QLineEdit *lineEdit_cap10mid;
    QWidget *widget4;
    QVBoxLayout *verticalLayout_5;
    QLineEdit *lineEdit_cap1min;
    QLineEdit *lineEdit_cap2min;
    QLineEdit *lineEdit_cap3min;
    QLineEdit *lineEdit_cap4min;
    QLineEdit *lineEdit_cap5min;
    QLineEdit *lineEdit_cap6min;
    QLineEdit *lineEdit_cap7min;
    QLineEdit *lineEdit_cap8min;
    QLineEdit *lineEdit_cap9min;
    QLineEdit *lineEdit_cap10min;
    QGroupBox *groupBox_10;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_rccali_end;
    QPushButton *pushButton_rccali_mid;
    QPushButton *pushButton_rccali_start;
    QPushButton *pushButton_rcask;

    void setupUi(QWidget *QRcWidget)
    {
        if (QRcWidget->objectName().isEmpty())
            QRcWidget->setObjectName(QStringLiteral("QRcWidget"));
        QRcWidget->resize(826, 585);
        QRcWidget->setMinimumSize(QSize(624, 522));
        groupBox_11 = new QGroupBox(QRcWidget);
        groupBox_11->setObjectName(QStringLiteral("groupBox_11"));
        groupBox_11->setGeometry(QRect(550, 10, 261, 58));
        gridLayout_4 = new QGridLayout(groupBox_11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        pushButton_rc_receiveset = new QPushButton(groupBox_11);
        pushButton_rc_receiveset->setObjectName(QStringLiteral("pushButton_rc_receiveset"));
        pushButton_rc_receiveset->setMinimumSize(QSize(0, 25));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/set.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_rc_receiveset->setIcon(icon);
        pushButton_rc_receiveset->setIconSize(QSize(22, 22));

        gridLayout_4->addWidget(pushButton_rc_receiveset, 0, 1, 1, 1);

        pushButton_rc_receiveask = new QPushButton(groupBox_11);
        pushButton_rc_receiveask->setObjectName(QStringLiteral("pushButton_rc_receiveask"));
        pushButton_rc_receiveask->setMinimumSize(QSize(0, 25));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/ask.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_rc_receiveask->setIcon(icon1);
        pushButton_rc_receiveask->setIconSize(QSize(22, 22));

        gridLayout_4->addWidget(pushButton_rc_receiveask, 0, 2, 1, 1);

        comboBox_captype = new QComboBox(groupBox_11);
        comboBox_captype->setObjectName(QStringLiteral("comboBox_captype"));

        gridLayout_4->addWidget(comboBox_captype, 0, 0, 1, 1);

        groupBox_9 = new QGroupBox(QRcWidget);
        groupBox_9->setObjectName(QStringLiteral("groupBox_9"));
        groupBox_9->setGeometry(QRect(0, 80, 811, 585));
        groupBox_9->setMinimumSize(QSize(811, 585));
        groupBox_9->setMaximumSize(QSize(811, 585));
        label_160 = new QLabel(groupBox_9);
        label_160->setObjectName(QStringLiteral("label_160"));
        label_160->setGeometry(QRect(10, 10, 36, 16));
        label_153 = new QLabel(groupBox_9);
        label_153->setObjectName(QStringLiteral("label_153"));
        label_153->setGeometry(QRect(10, 70, 24, 16));
        label_154 = new QLabel(groupBox_9);
        label_154->setObjectName(QStringLiteral("label_154"));
        label_154->setGeometry(QRect(10, 112, 24, 16));
        label_157 = new QLabel(groupBox_9);
        label_157->setObjectName(QStringLiteral("label_157"));
        label_157->setGeometry(QRect(10, 238, 24, 16));
        label_161 = new QLabel(groupBox_9);
        label_161->setObjectName(QStringLiteral("label_161"));
        label_161->setGeometry(QRect(10, 364, 24, 16));
        label_159 = new QLabel(groupBox_9);
        label_159->setObjectName(QStringLiteral("label_159"));
        label_159->setGeometry(QRect(10, 322, 24, 16));
        label_166 = new QLabel(groupBox_9);
        label_166->setObjectName(QStringLiteral("label_166"));
        label_166->setGeometry(QRect(599, 10, 36, 16));
        label_282 = new QLabel(groupBox_9);
        label_282->setObjectName(QStringLiteral("label_282"));
        label_282->setGeometry(QRect(408, 10, 24, 16));
        label_165 = new QLabel(groupBox_9);
        label_165->setObjectName(QStringLiteral("label_165"));
        label_165->setGeometry(QRect(703, 10, 36, 16));
        label_158 = new QLabel(groupBox_9);
        label_158->setObjectName(QStringLiteral("label_158"));
        label_158->setGeometry(QRect(10, 280, 36, 16));
        label_162 = new QLabel(groupBox_9);
        label_162->setObjectName(QStringLiteral("label_162"));
        label_162->setGeometry(QRect(10, 400, 36, 16));
        label_164 = new QLabel(groupBox_9);
        label_164->setObjectName(QStringLiteral("label_164"));
        label_164->setGeometry(QRect(495, 10, 36, 16));
        label_155 = new QLabel(groupBox_9);
        label_155->setObjectName(QStringLiteral("label_155"));
        label_155->setGeometry(QRect(10, 154, 24, 16));
        label_28 = new QLabel(groupBox_9);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setGeometry(QRect(10, 28, 24, 16));
        label_156 = new QLabel(groupBox_9);
        label_156->setObjectName(QStringLiteral("label_156"));
        label_156->setGeometry(QRect(10, 196, 24, 16));
        widget = new QWidget(groupBox_9);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(52, 20, 346, 431));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        progressBar_cap1 = new QProgressBar(widget);
        progressBar_cap1->setObjectName(QStringLiteral("progressBar_cap1"));
        progressBar_cap1->setMinimumSize(QSize(0, 0));
        progressBar_cap1->setMinimum(-150);
        progressBar_cap1->setMaximum(150);
        progressBar_cap1->setValue(0);
        progressBar_cap1->setTextVisible(true);
        progressBar_cap1->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(progressBar_cap1);

        progressBar_cap2 = new QProgressBar(widget);
        progressBar_cap2->setObjectName(QStringLiteral("progressBar_cap2"));
        progressBar_cap2->setMinimumSize(QSize(0, 0));
        progressBar_cap2->setMinimum(-150);
        progressBar_cap2->setMaximum(150);
        progressBar_cap2->setValue(0);
        progressBar_cap2->setTextVisible(true);
        progressBar_cap2->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(progressBar_cap2);

        progressBar_cap3 = new QProgressBar(widget);
        progressBar_cap3->setObjectName(QStringLiteral("progressBar_cap3"));
        progressBar_cap3->setMinimumSize(QSize(0, 0));
        progressBar_cap3->setMinimum(-150);
        progressBar_cap3->setMaximum(150);
        progressBar_cap3->setValue(0);
        progressBar_cap3->setTextVisible(true);
        progressBar_cap3->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(progressBar_cap3);

        progressBar_cap4 = new QProgressBar(widget);
        progressBar_cap4->setObjectName(QStringLiteral("progressBar_cap4"));
        progressBar_cap4->setMinimumSize(QSize(0, 0));
        progressBar_cap4->setMinimum(-150);
        progressBar_cap4->setMaximum(150);
        progressBar_cap4->setValue(0);
        progressBar_cap4->setTextVisible(true);
        progressBar_cap4->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(progressBar_cap4);

        progressBar_cap5 = new QProgressBar(widget);
        progressBar_cap5->setObjectName(QStringLiteral("progressBar_cap5"));
        progressBar_cap5->setMinimumSize(QSize(0, 0));
        progressBar_cap5->setMinimum(-150);
        progressBar_cap5->setMaximum(150);
        progressBar_cap5->setValue(0);
        progressBar_cap5->setTextVisible(true);
        progressBar_cap5->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(progressBar_cap5);

        progressBar_cap6 = new QProgressBar(widget);
        progressBar_cap6->setObjectName(QStringLiteral("progressBar_cap6"));
        progressBar_cap6->setMinimumSize(QSize(0, 0));
        progressBar_cap6->setMinimum(-150);
        progressBar_cap6->setMaximum(150);
        progressBar_cap6->setValue(0);
        progressBar_cap6->setTextVisible(true);
        progressBar_cap6->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(progressBar_cap6);

        progressBar_cap7 = new QProgressBar(widget);
        progressBar_cap7->setObjectName(QStringLiteral("progressBar_cap7"));
        progressBar_cap7->setMinimumSize(QSize(0, 0));
        progressBar_cap7->setMinimum(-150);
        progressBar_cap7->setMaximum(150);
        progressBar_cap7->setValue(0);
        progressBar_cap7->setTextVisible(true);
        progressBar_cap7->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(progressBar_cap7);

        progressBar_cap8 = new QProgressBar(widget);
        progressBar_cap8->setObjectName(QStringLiteral("progressBar_cap8"));
        progressBar_cap8->setMinimumSize(QSize(0, 0));
        progressBar_cap8->setMinimum(-150);
        progressBar_cap8->setMaximum(150);
        progressBar_cap8->setValue(0);
        progressBar_cap8->setTextVisible(true);
        progressBar_cap8->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(progressBar_cap8);

        progressBar_cap9 = new QProgressBar(widget);
        progressBar_cap9->setObjectName(QStringLiteral("progressBar_cap9"));
        progressBar_cap9->setMinimumSize(QSize(0, 0));
        progressBar_cap9->setMinimum(-150);
        progressBar_cap9->setMaximum(150);
        progressBar_cap9->setValue(0);
        progressBar_cap9->setTextVisible(true);
        progressBar_cap9->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(progressBar_cap9);

        progressBar_cap10 = new QProgressBar(widget);
        progressBar_cap10->setObjectName(QStringLiteral("progressBar_cap10"));
        progressBar_cap10->setMinimumSize(QSize(344, 0));
        progressBar_cap10->setMinimum(-150);
        progressBar_cap10->setMaximum(150);
        progressBar_cap10->setValue(0);
        progressBar_cap10->setTextVisible(true);
        progressBar_cap10->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(progressBar_cap10);

        widget1 = new QWidget(groupBox_9);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(402, 28, 83, 421));
        verticalLayout = new QVBoxLayout(widget1);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_switch = new QPushButton(widget1);
        pushButton_switch->setObjectName(QStringLiteral("pushButton_switch"));
        pushButton_switch->setMinimumSize(QSize(81, 0));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/dir1.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_switch->setIcon(icon2);
        pushButton_switch->setIconSize(QSize(22, 22));

        verticalLayout->addWidget(pushButton_switch);

        pushButton_ele = new QPushButton(widget1);
        pushButton_ele->setObjectName(QStringLiteral("pushButton_ele"));
        pushButton_ele->setIcon(icon2);
        pushButton_ele->setIconSize(QSize(22, 22));

        verticalLayout->addWidget(pushButton_ele);

        pushButton_ail = new QPushButton(widget1);
        pushButton_ail->setObjectName(QStringLiteral("pushButton_ail"));
        pushButton_ail->setMaximumSize(QSize(81, 16777215));
        pushButton_ail->setIcon(icon2);
        pushButton_ail->setIconSize(QSize(22, 22));

        verticalLayout->addWidget(pushButton_ail);

        pushButton_col = new QPushButton(widget1);
        pushButton_col->setObjectName(QStringLiteral("pushButton_col"));
        pushButton_col->setMinimumSize(QSize(81, 0));
        pushButton_col->setMaximumSize(QSize(81, 16777215));
        pushButton_col->setIcon(icon2);
        pushButton_col->setIconSize(QSize(22, 22));

        verticalLayout->addWidget(pushButton_col);

        pushButton_rud = new QPushButton(widget1);
        pushButton_rud->setObjectName(QStringLiteral("pushButton_rud"));
        pushButton_rud->setIcon(icon2);
        pushButton_rud->setIconSize(QSize(22, 22));

        verticalLayout->addWidget(pushButton_rud);

        pushButton_oil = new QPushButton(widget1);
        pushButton_oil->setObjectName(QStringLiteral("pushButton_oil"));
        pushButton_oil->setIcon(icon2);
        pushButton_oil->setIconSize(QSize(22, 22));

        verticalLayout->addWidget(pushButton_oil);

        pushButton_en = new QPushButton(widget1);
        pushButton_en->setObjectName(QStringLiteral("pushButton_en"));
        pushButton_en->setIcon(icon2);
        pushButton_en->setIconSize(QSize(22, 22));

        verticalLayout->addWidget(pushButton_en);

        pushButton_water = new QPushButton(widget1);
        pushButton_water->setObjectName(QStringLiteral("pushButton_water"));
        pushButton_water->setIcon(icon2);
        pushButton_water->setIconSize(QSize(22, 22));

        verticalLayout->addWidget(pushButton_water);

        pushButton_flow = new QPushButton(widget1);
        pushButton_flow->setObjectName(QStringLiteral("pushButton_flow"));
        pushButton_flow->setIcon(icon2);
        pushButton_flow->setIconSize(QSize(22, 22));

        verticalLayout->addWidget(pushButton_flow);

        pushButton_rc10 = new QPushButton(widget1);
        pushButton_rc10->setObjectName(QStringLiteral("pushButton_rc10"));
        pushButton_rc10->setIcon(icon2);
        pushButton_rc10->setIconSize(QSize(22, 22));

        verticalLayout->addWidget(pushButton_rc10);

        widget2 = new QWidget(groupBox_9);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setGeometry(QRect(495, 23, 102, 431));
        verticalLayout_3 = new QVBoxLayout(widget2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        lineEdit_cap1max = new QLineEdit(widget2);
        lineEdit_cap1max->setObjectName(QStringLiteral("lineEdit_cap1max"));
        lineEdit_cap1max->setMinimumSize(QSize(52, 0));
        lineEdit_cap1max->setMaximumSize(QSize(100, 16777215));
        lineEdit_cap1max->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(lineEdit_cap1max);

        lineEdit_cap2max = new QLineEdit(widget2);
        lineEdit_cap2max->setObjectName(QStringLiteral("lineEdit_cap2max"));
        lineEdit_cap2max->setMaximumSize(QSize(100, 16777215));
        lineEdit_cap2max->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(lineEdit_cap2max);

        lineEdit_cap3max = new QLineEdit(widget2);
        lineEdit_cap3max->setObjectName(QStringLiteral("lineEdit_cap3max"));
        lineEdit_cap3max->setMaximumSize(QSize(100, 16777215));
        lineEdit_cap3max->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(lineEdit_cap3max);

        lineEdit_cap4max = new QLineEdit(widget2);
        lineEdit_cap4max->setObjectName(QStringLiteral("lineEdit_cap4max"));
        lineEdit_cap4max->setMaximumSize(QSize(100, 16777215));
        lineEdit_cap4max->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(lineEdit_cap4max);

        lineEdit_cap5max = new QLineEdit(widget2);
        lineEdit_cap5max->setObjectName(QStringLiteral("lineEdit_cap5max"));
        lineEdit_cap5max->setMaximumSize(QSize(100, 16777215));
        lineEdit_cap5max->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(lineEdit_cap5max);

        lineEdit_cap6max = new QLineEdit(widget2);
        lineEdit_cap6max->setObjectName(QStringLiteral("lineEdit_cap6max"));
        lineEdit_cap6max->setMaximumSize(QSize(100, 16777215));
        lineEdit_cap6max->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(lineEdit_cap6max);

        lineEdit_cap7max = new QLineEdit(widget2);
        lineEdit_cap7max->setObjectName(QStringLiteral("lineEdit_cap7max"));
        lineEdit_cap7max->setMaximumSize(QSize(100, 16777215));
        lineEdit_cap7max->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(lineEdit_cap7max);

        lineEdit_cap8max = new QLineEdit(widget2);
        lineEdit_cap8max->setObjectName(QStringLiteral("lineEdit_cap8max"));
        lineEdit_cap8max->setMaximumSize(QSize(100, 16777215));
        lineEdit_cap8max->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(lineEdit_cap8max);

        lineEdit_cap9max = new QLineEdit(widget2);
        lineEdit_cap9max->setObjectName(QStringLiteral("lineEdit_cap9max"));
        lineEdit_cap9max->setMaximumSize(QSize(100, 16777215));
        lineEdit_cap9max->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(lineEdit_cap9max);

        lineEdit_cap10max = new QLineEdit(widget2);
        lineEdit_cap10max->setObjectName(QStringLiteral("lineEdit_cap10max"));
        lineEdit_cap10max->setMaximumSize(QSize(100, 16777215));
        lineEdit_cap10max->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(lineEdit_cap10max);

        widget3 = new QWidget(groupBox_9);
        widget3->setObjectName(QStringLiteral("widget3"));
        widget3->setGeometry(QRect(599, 23, 102, 431));
        verticalLayout_4 = new QVBoxLayout(widget3);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        lineEdit_cap1mid = new QLineEdit(widget3);
        lineEdit_cap1mid->setObjectName(QStringLiteral("lineEdit_cap1mid"));
        lineEdit_cap1mid->setMinimumSize(QSize(52, 0));
        lineEdit_cap1mid->setMaximumSize(QSize(100, 16777215));
        lineEdit_cap1mid->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(lineEdit_cap1mid);

        lineEdit_cap2mid = new QLineEdit(widget3);
        lineEdit_cap2mid->setObjectName(QStringLiteral("lineEdit_cap2mid"));
        lineEdit_cap2mid->setMaximumSize(QSize(100, 16777215));
        lineEdit_cap2mid->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(lineEdit_cap2mid);

        lineEdit_cap3mid = new QLineEdit(widget3);
        lineEdit_cap3mid->setObjectName(QStringLiteral("lineEdit_cap3mid"));
        lineEdit_cap3mid->setMaximumSize(QSize(100, 16777215));
        lineEdit_cap3mid->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(lineEdit_cap3mid);

        lineEdit_cap4mid = new QLineEdit(widget3);
        lineEdit_cap4mid->setObjectName(QStringLiteral("lineEdit_cap4mid"));
        lineEdit_cap4mid->setMaximumSize(QSize(100, 16777215));
        lineEdit_cap4mid->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(lineEdit_cap4mid);

        lineEdit_cap5mid = new QLineEdit(widget3);
        lineEdit_cap5mid->setObjectName(QStringLiteral("lineEdit_cap5mid"));
        lineEdit_cap5mid->setMaximumSize(QSize(100, 16777215));
        lineEdit_cap5mid->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(lineEdit_cap5mid);

        lineEdit_cap6mid = new QLineEdit(widget3);
        lineEdit_cap6mid->setObjectName(QStringLiteral("lineEdit_cap6mid"));
        lineEdit_cap6mid->setMaximumSize(QSize(100, 16777215));
        lineEdit_cap6mid->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(lineEdit_cap6mid);

        lineEdit_cap7mid = new QLineEdit(widget3);
        lineEdit_cap7mid->setObjectName(QStringLiteral("lineEdit_cap7mid"));
        lineEdit_cap7mid->setMaximumSize(QSize(100, 16777215));
        lineEdit_cap7mid->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(lineEdit_cap7mid);

        lineEdit_cap8mid = new QLineEdit(widget3);
        lineEdit_cap8mid->setObjectName(QStringLiteral("lineEdit_cap8mid"));
        lineEdit_cap8mid->setMaximumSize(QSize(100, 16777215));
        lineEdit_cap8mid->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(lineEdit_cap8mid);

        lineEdit_cap9mid = new QLineEdit(widget3);
        lineEdit_cap9mid->setObjectName(QStringLiteral("lineEdit_cap9mid"));
        lineEdit_cap9mid->setMaximumSize(QSize(100, 16777215));
        lineEdit_cap9mid->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(lineEdit_cap9mid);

        lineEdit_cap10mid = new QLineEdit(widget3);
        lineEdit_cap10mid->setObjectName(QStringLiteral("lineEdit_cap10mid"));
        lineEdit_cap10mid->setMaximumSize(QSize(100, 16777215));
        lineEdit_cap10mid->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(lineEdit_cap10mid);

        widget4 = new QWidget(groupBox_9);
        widget4->setObjectName(QStringLiteral("widget4"));
        widget4->setGeometry(QRect(703, 23, 102, 431));
        verticalLayout_5 = new QVBoxLayout(widget4);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        lineEdit_cap1min = new QLineEdit(widget4);
        lineEdit_cap1min->setObjectName(QStringLiteral("lineEdit_cap1min"));
        lineEdit_cap1min->setMinimumSize(QSize(52, 0));
        lineEdit_cap1min->setMaximumSize(QSize(100, 16777215));
        lineEdit_cap1min->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(lineEdit_cap1min);

        lineEdit_cap2min = new QLineEdit(widget4);
        lineEdit_cap2min->setObjectName(QStringLiteral("lineEdit_cap2min"));
        lineEdit_cap2min->setMaximumSize(QSize(100, 16777215));
        lineEdit_cap2min->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(lineEdit_cap2min);

        lineEdit_cap3min = new QLineEdit(widget4);
        lineEdit_cap3min->setObjectName(QStringLiteral("lineEdit_cap3min"));
        lineEdit_cap3min->setMaximumSize(QSize(100, 16777215));
        lineEdit_cap3min->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(lineEdit_cap3min);

        lineEdit_cap4min = new QLineEdit(widget4);
        lineEdit_cap4min->setObjectName(QStringLiteral("lineEdit_cap4min"));
        lineEdit_cap4min->setMaximumSize(QSize(100, 16777215));
        lineEdit_cap4min->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(lineEdit_cap4min);

        lineEdit_cap5min = new QLineEdit(widget4);
        lineEdit_cap5min->setObjectName(QStringLiteral("lineEdit_cap5min"));
        lineEdit_cap5min->setMaximumSize(QSize(100, 16777215));
        lineEdit_cap5min->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(lineEdit_cap5min);

        lineEdit_cap6min = new QLineEdit(widget4);
        lineEdit_cap6min->setObjectName(QStringLiteral("lineEdit_cap6min"));
        lineEdit_cap6min->setMaximumSize(QSize(100, 16777215));
        lineEdit_cap6min->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(lineEdit_cap6min);

        lineEdit_cap7min = new QLineEdit(widget4);
        lineEdit_cap7min->setObjectName(QStringLiteral("lineEdit_cap7min"));
        lineEdit_cap7min->setMaximumSize(QSize(100, 16777215));
        lineEdit_cap7min->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(lineEdit_cap7min);

        lineEdit_cap8min = new QLineEdit(widget4);
        lineEdit_cap8min->setObjectName(QStringLiteral("lineEdit_cap8min"));
        lineEdit_cap8min->setMaximumSize(QSize(100, 16777215));
        lineEdit_cap8min->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(lineEdit_cap8min);

        lineEdit_cap9min = new QLineEdit(widget4);
        lineEdit_cap9min->setObjectName(QStringLiteral("lineEdit_cap9min"));
        lineEdit_cap9min->setMaximumSize(QSize(100, 16777215));
        lineEdit_cap9min->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(lineEdit_cap9min);

        lineEdit_cap10min = new QLineEdit(widget4);
        lineEdit_cap10min->setObjectName(QStringLiteral("lineEdit_cap10min"));
        lineEdit_cap10min->setMaximumSize(QSize(100, 16777215));
        lineEdit_cap10min->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(lineEdit_cap10min);

        groupBox_10 = new QGroupBox(QRcWidget);
        groupBox_10->setObjectName(QStringLiteral("groupBox_10"));
        groupBox_10->setGeometry(QRect(0, 10, 341, 51));
        gridLayout_2 = new QGridLayout(groupBox_10);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        pushButton_rccali_end = new QPushButton(groupBox_10);
        pushButton_rccali_end->setObjectName(QStringLiteral("pushButton_rccali_end"));
        pushButton_rccali_end->setMinimumSize(QSize(0, 30));

        gridLayout_2->addWidget(pushButton_rccali_end, 0, 2, 1, 1);

        pushButton_rccali_mid = new QPushButton(groupBox_10);
        pushButton_rccali_mid->setObjectName(QStringLiteral("pushButton_rccali_mid"));
        pushButton_rccali_mid->setMinimumSize(QSize(0, 30));

        gridLayout_2->addWidget(pushButton_rccali_mid, 0, 1, 1, 1);

        pushButton_rccali_start = new QPushButton(groupBox_10);
        pushButton_rccali_start->setObjectName(QStringLiteral("pushButton_rccali_start"));
        pushButton_rccali_start->setMinimumSize(QSize(0, 30));

        gridLayout_2->addWidget(pushButton_rccali_start, 0, 0, 1, 1);

        pushButton_rcask = new QPushButton(groupBox_10);
        pushButton_rcask->setObjectName(QStringLiteral("pushButton_rcask"));
        pushButton_rcask->setMinimumSize(QSize(0, 30));

        gridLayout_2->addWidget(pushButton_rcask, 0, 3, 1, 1);


        retranslateUi(QRcWidget);

        QMetaObject::connectSlotsByName(QRcWidget);
    } // setupUi

    void retranslateUi(QWidget *QRcWidget)
    {
        QRcWidget->setWindowTitle(QApplication::translate("QRcWidget", "Form", 0));
        groupBox_11->setTitle(QApplication::translate("QRcWidget", "\346\216\245\346\224\266\346\234\272\347\261\273\345\236\213", 0));
        pushButton_rc_receiveset->setText(QApplication::translate("QRcWidget", "\350\256\276\347\275\256", 0));
        pushButton_rc_receiveask->setText(QApplication::translate("QRcWidget", "\346\237\245\350\257\242", 0));
        comboBox_captype->clear();
        comboBox_captype->insertItems(0, QStringList()
         << QApplication::translate("QRcWidget", "PWM", 0)
         << QApplication::translate("QRcWidget", "STU", 0)
         << QApplication::translate("QRcWidget", "DSM2", 0)
         << QApplication::translate("QRcWidget", "S-BUS", 0)
         << QApplication::translate("QRcWidget", "X-BUS", 0)
        );
        groupBox_9->setTitle(QString());
        label_160->setText(QApplication::translate("QRcWidget", "\351\200\232\351\201\223\345\217\267", 0));
        label_153->setText(QApplication::translate("QRcWidget", "\347\272\265\345\220\221", 0));
        label_154->setText(QApplication::translate("QRcWidget", "\346\250\252\345\220\221", 0));
        label_157->setText(QApplication::translate("QRcWidget", "\346\262\271\351\227\250", 0));
        label_161->setText(QApplication::translate("QRcWidget", "\346\265\201\351\207\217", 0));
        label_159->setText(QApplication::translate("QRcWidget", "\346\260\264\346\263\265", 0));
        label_166->setText(QApplication::translate("QRcWidget", "\344\270\255\347\253\213\344\275\215", 0));
        label_282->setText(QApplication::translate("QRcWidget", "\346\236\201\346\200\247", 0));
        label_165->setText(QApplication::translate("QRcWidget", "\346\234\200\345\260\217\344\275\215", 0));
        label_158->setText(QApplication::translate("QRcWidget", "\345\217\221\345\212\250\346\234\272", 0));
        label_162->setText(QApplication::translate("QRcWidget", "\351\200\232\351\201\22310", 0));
        label_164->setText(QApplication::translate("QRcWidget", "\346\234\200\345\244\247\344\275\215", 0));
        label_155->setText(QApplication::translate("QRcWidget", "\346\200\273\350\267\235", 0));
        label_28->setText(QApplication::translate("QRcWidget", "\345\274\200\345\205\263", 0));
        label_156->setText(QApplication::translate("QRcWidget", "\345\260\276\346\241\250", 0));
        progressBar_cap1->setFormat(QApplication::translate("QRcWidget", "%v", 0));
        progressBar_cap2->setFormat(QApplication::translate("QRcWidget", "%v", 0));
        progressBar_cap3->setFormat(QApplication::translate("QRcWidget", "%v", 0));
        progressBar_cap4->setFormat(QApplication::translate("QRcWidget", "%v", 0));
        progressBar_cap5->setFormat(QApplication::translate("QRcWidget", "%v", 0));
        progressBar_cap6->setFormat(QApplication::translate("QRcWidget", "%v", 0));
        progressBar_cap7->setFormat(QApplication::translate("QRcWidget", "%v", 0));
        progressBar_cap8->setFormat(QApplication::translate("QRcWidget", "%v", 0));
        progressBar_cap9->setFormat(QApplication::translate("QRcWidget", "%v", 0));
        progressBar_cap10->setFormat(QApplication::translate("QRcWidget", "%v", 0));
        pushButton_switch->setText(QApplication::translate("QRcWidget", "\346\255\243\345\220\221", 0));
        pushButton_ele->setText(QApplication::translate("QRcWidget", "\346\255\243\345\220\221", 0));
        pushButton_ail->setText(QApplication::translate("QRcWidget", "\346\255\243\345\220\221", 0));
        pushButton_col->setText(QApplication::translate("QRcWidget", "\346\255\243\345\220\221", 0));
        pushButton_rud->setText(QApplication::translate("QRcWidget", "\346\255\243\345\220\221", 0));
        pushButton_oil->setText(QApplication::translate("QRcWidget", "\346\255\243\345\220\221", 0));
        pushButton_en->setText(QApplication::translate("QRcWidget", "\346\255\243\345\220\221", 0));
        pushButton_water->setText(QApplication::translate("QRcWidget", "\346\255\243\345\220\221", 0));
        pushButton_flow->setText(QApplication::translate("QRcWidget", "\346\255\243\345\220\221", 0));
        pushButton_rc10->setText(QApplication::translate("QRcWidget", "\346\255\243\345\220\221", 0));
        groupBox_10->setTitle(QString());
        pushButton_rccali_end->setText(QApplication::translate("QRcWidget", "\346\240\241\345\207\206\345\256\214\346\210\220", 0));
        pushButton_rccali_mid->setText(QApplication::translate("QRcWidget", "\346\240\241\345\207\206\344\270\255\344\275\215", 0));
        pushButton_rccali_start->setText(QApplication::translate("QRcWidget", "\346\240\241\345\207\206\345\274\200\345\247\213", 0));
        pushButton_rcask->setText(QApplication::translate("QRcWidget", "\346\225\260\346\215\256\346\237\245\350\257\242", 0));
    } // retranslateUi

};

namespace Ui {
    class QRcWidget: public Ui_QRcWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RCWIDGET_H
