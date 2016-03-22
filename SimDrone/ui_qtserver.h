/********************************************************************************
** Form generated from reading UI file 'qtserver.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTSERVER_H
#define UI_QTSERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtServer
{
public:
    QGroupBox *serverState;
    QLabel *PORTLab;
    QLabel *IPLab;
    QLabel *PORT;
    QLabel *IP;
    QGroupBox *flightPara;
    QLineEdit *long_text;
    QLineEdit *lati_text;
    QLineEdit *hei_text;
    QLineEdit *pitch_angle;
    QLineEdit *roll_angle;
    QLineEdit *yaw_angle;
    QSplitter *splitter;
    QLabel *longitude;
    QLabel *label;
    QSplitter *splitter_2;
    QLabel *latitude;
    QLabel *label_3;
    QSplitter *splitter_3;
    QLabel *height;
    QLabel *label_2;
    QSplitter *splitter_5;
    QLabel *label_4;
    QSplitter *splitter_4;
    QLineEdit *time_interval;
    QPushButton *send_para;

    void setupUi(QWidget *QtServer)
    {
        if (QtServer->objectName().isEmpty())
            QtServer->setObjectName(QStringLiteral("QtServer"));
        QtServer->resize(544, 468);
        serverState = new QGroupBox(QtServer);
        serverState->setObjectName(QStringLiteral("serverState"));
        serverState->setGeometry(QRect(9, 410, 231, 51));
        PORTLab = new QLabel(serverState);
        PORTLab->setObjectName(QStringLiteral("PORTLab"));
        PORTLab->setGeometry(QRect(150, 20, 22, 16));
        PORTLab->setAlignment(Qt::AlignCenter);
        IPLab = new QLabel(serverState);
        IPLab->setObjectName(QStringLiteral("IPLab"));
        IPLab->setGeometry(QRect(20, 20, 32, 16));
        IPLab->setAlignment(Qt::AlignCenter);
        PORT = new QLabel(serverState);
        PORT->setObjectName(QStringLiteral("PORT"));
        PORT->setGeometry(QRect(180, 20, 46, 16));
        IP = new QLabel(serverState);
        IP->setObjectName(QStringLiteral("IP"));
        IP->setGeometry(QRect(57, 20, 81, 16));
        flightPara = new QGroupBox(QtServer);
        flightPara->setObjectName(QStringLiteral("flightPara"));
        flightPara->setGeometry(QRect(9, 9, 521, 381));
        long_text = new QLineEdit(flightPara);
        long_text->setObjectName(QStringLiteral("long_text"));
        long_text->setGeometry(QRect(60, 30, 91, 20));
        lati_text = new QLineEdit(flightPara);
        lati_text->setObjectName(QStringLiteral("lati_text"));
        lati_text->setGeometry(QRect(200, 30, 91, 20));
        hei_text = new QLineEdit(flightPara);
        hei_text->setObjectName(QStringLiteral("hei_text"));
        hei_text->setGeometry(QRect(340, 30, 91, 20));
        pitch_angle = new QLineEdit(flightPara);
        pitch_angle->setObjectName(QStringLiteral("pitch_angle"));
        pitch_angle->setGeometry(QRect(60, 60, 91, 20));
        roll_angle = new QLineEdit(flightPara);
        roll_angle->setObjectName(QStringLiteral("roll_angle"));
        roll_angle->setGeometry(QRect(200, 60, 91, 20));
        yaw_angle = new QLineEdit(flightPara);
        yaw_angle->setObjectName(QStringLiteral("yaw_angle"));
        yaw_angle->setGeometry(QRect(340, 60, 91, 20));
        splitter = new QSplitter(flightPara);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(20, 30, 33, 51));
        splitter->setOrientation(Qt::Vertical);
        longitude = new QLabel(splitter);
        longitude->setObjectName(QStringLiteral("longitude"));
        longitude->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        splitter->addWidget(longitude);
        label = new QLabel(splitter);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        splitter->addWidget(label);
        splitter_2 = new QSplitter(flightPara);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setGeometry(QRect(160, 30, 33, 51));
        splitter_2->setOrientation(Qt::Vertical);
        latitude = new QLabel(splitter_2);
        latitude->setObjectName(QStringLiteral("latitude"));
        latitude->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        splitter_2->addWidget(latitude);
        label_3 = new QLabel(splitter_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        splitter_2->addWidget(label_3);
        splitter_3 = new QSplitter(flightPara);
        splitter_3->setObjectName(QStringLiteral("splitter_3"));
        splitter_3->setGeometry(QRect(300, 30, 33, 51));
        splitter_3->setOrientation(Qt::Vertical);
        height = new QLabel(splitter_3);
        height->setObjectName(QStringLiteral("height"));
        height->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        splitter_3->addWidget(height);
        label_2 = new QLabel(splitter_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        splitter_3->addWidget(label_2);
        splitter_5 = new QSplitter(QtServer);
        splitter_5->setObjectName(QStringLiteral("splitter_5"));
        splitter_5->setGeometry(QRect(260, 420, 252, 23));
        splitter_5->setOrientation(Qt::Horizontal);
        label_4 = new QLabel(splitter_5);
        label_4->setObjectName(QStringLiteral("label_4"));
        splitter_5->addWidget(label_4);
        splitter_4 = new QSplitter(splitter_5);
        splitter_4->setObjectName(QStringLiteral("splitter_4"));
        splitter_4->setOrientation(Qt::Horizontal);
        time_interval = new QLineEdit(splitter_4);
        time_interval->setObjectName(QStringLiteral("time_interval"));
        splitter_4->addWidget(time_interval);
        send_para = new QPushButton(splitter_4);
        send_para->setObjectName(QStringLiteral("send_para"));
        splitter_4->addWidget(send_para);
        splitter_5->addWidget(splitter_4);

        retranslateUi(QtServer);

        QMetaObject::connectSlotsByName(QtServer);
    } // setupUi

    void retranslateUi(QWidget *QtServer)
    {
        QtServer->setWindowTitle(QApplication::translate("QtServer", "QtServer", 0));
        serverState->setTitle(QApplication::translate("QtServer", "\346\234\215\345\212\241\345\231\250\347\212\266\346\200\201", 0));
        PORTLab->setText(QApplication::translate("QtServer", "\347\253\257\345\217\243", 0));
        IPLab->setText(QApplication::translate("QtServer", "IP\345\234\260\345\235\200", 0));
        PORT->setText(QApplication::translate("QtServer", "TextLabel", 0));
        IP->setText(QApplication::translate("QtServer", "TextLabel", 0));
        flightPara->setTitle(QApplication::translate("QtServer", "\351\243\236\350\241\214\345\217\202\346\225\260", 0));
        longitude->setText(QApplication::translate("QtServer", "\347\273\217\345\272\246", 0));
        label->setText(QApplication::translate("QtServer", "\344\277\257\344\273\260\350\247\222", 0));
        latitude->setText(QApplication::translate("QtServer", "\347\272\254\345\272\246", 0));
        label_3->setText(QApplication::translate("QtServer", "\346\273\232\350\275\254\350\247\222", 0));
        height->setText(QApplication::translate("QtServer", "\351\253\230\345\272\246", 0));
        label_2->setText(QApplication::translate("QtServer", "\345\201\217\350\210\252\350\247\222", 0));
        label_4->setText(QApplication::translate("QtServer", "\346\227\266\351\227\264\351\227\264\351\232\224", 0));
        send_para->setText(QApplication::translate("QtServer", "\345\256\232\346\227\266\345\217\221\351\200\201", 0));
    } // retranslateUi

};

namespace Ui {
    class QtServer: public Ui_QtServer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTSERVER_H
