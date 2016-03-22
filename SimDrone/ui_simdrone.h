/********************************************************************************
** Form generated from reading UI file 'simdrone.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMDRONE_H
#define UI_SIMDRONE_H

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

class Ui_simDrone
{
public:
    QGroupBox *groupBox;
    QSplitter *splitter;
    QLabel *label;
    QLabel *server_port;
    QSplitter *splitter_2;
    QLabel *label_2;
    QLabel *client_ip;
    QGroupBox *groupBox_2;
    QSplitter *splitter_3;
    QLabel *label_3;
    QLabel *label_4;
    QSplitter *splitter_4;
    QLabel *label_5;
    QLabel *label_6;
    QSplitter *splitter_5;
    QLineEdit *uav_type_num;
    QLineEdit *uav_state;
    QSplitter *splitter_6;
    QLineEdit *uav_contralmode;
    QLineEdit *uav_flymode;
    QSplitter *splitter_7;
    QLabel *label_7;
    QLineEdit *uav_longitude;
    QLabel *label_8;
    QLineEdit *uav_latitude;
    QSplitter *splitter_8;
    QLabel *label_10;
    QLineEdit *uav_grouundspeed;
    QLabel *label_11;
    QLineEdit *uav_verticalspeed;
    QLabel *label_9;
    QLineEdit *uav_altitude;
    QSplitter *splitter_9;
    QLabel *label_12;
    QLineEdit *uav_line_angle;
    QLabel *label_13;
    QLineEdit *uav_flight_angle;
    QLabel *label_14;
    QLineEdit *uav_flight_time;
    QSplitter *splitter_10;
    QLabel *label_15;
    QLineEdit *uav_oil_meter;
    QLabel *label_16;
    QLineEdit *uav_voltage;
    QLabel *label_17;
    QLineEdit *uav_cpuratio;
    QGroupBox *groupBox_3;
    QSplitter *splitter_12;
    QLabel *label_18;
    QLineEdit *row_angle;
    QLabel *label_19;
    QLineEdit *yaw_angle;
    QLabel *label_20;
    QLineEdit *pitch_angle;
    QSplitter *splitter_11;
    QPushButton *send_heartbeat;
    QPushButton *send_attitude;

    void setupUi(QWidget *simDrone)
    {
        if (simDrone->objectName().isEmpty())
            simDrone->setObjectName(QStringLiteral("simDrone"));
        simDrone->setEnabled(true);
        simDrone->resize(359, 393);
        groupBox = new QGroupBox(simDrone);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 330, 341, 51));
        splitter = new QSplitter(groupBox);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(20, 20, 111, 16));
        splitter->setOrientation(Qt::Horizontal);
        label = new QLabel(splitter);
        label->setObjectName(QStringLiteral("label"));
        splitter->addWidget(label);
        server_port = new QLabel(splitter);
        server_port->setObjectName(QStringLiteral("server_port"));
        splitter->addWidget(server_port);
        splitter_2 = new QSplitter(groupBox);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setGeometry(QRect(160, 20, 141, 16));
        splitter_2->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(splitter_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        splitter_2->addWidget(label_2);
        client_ip = new QLabel(splitter_2);
        client_ip->setObjectName(QStringLiteral("client_ip"));
        splitter_2->addWidget(client_ip);
        groupBox_2 = new QGroupBox(simDrone);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(9, 9, 341, 201));
        splitter_3 = new QSplitter(groupBox_2);
        splitter_3->setObjectName(QStringLiteral("splitter_3"));
        splitter_3->setGeometry(QRect(10, 20, 91, 51));
        splitter_3->setOrientation(Qt::Vertical);
        label_3 = new QLabel(splitter_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        splitter_3->addWidget(label_3);
        label_4 = new QLabel(splitter_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        splitter_3->addWidget(label_4);
        splitter_4 = new QSplitter(groupBox_2);
        splitter_4->setObjectName(QStringLiteral("splitter_4"));
        splitter_4->setGeometry(QRect(170, 20, 81, 51));
        splitter_4->setOrientation(Qt::Vertical);
        label_5 = new QLabel(splitter_4);
        label_5->setObjectName(QStringLiteral("label_5"));
        splitter_4->addWidget(label_5);
        label_6 = new QLabel(splitter_4);
        label_6->setObjectName(QStringLiteral("label_6"));
        splitter_4->addWidget(label_6);
        splitter_5 = new QSplitter(groupBox_2);
        splitter_5->setObjectName(QStringLiteral("splitter_5"));
        splitter_5->setGeometry(QRect(110, 20, 51, 51));
        splitter_5->setOrientation(Qt::Vertical);
        uav_type_num = new QLineEdit(splitter_5);
        uav_type_num->setObjectName(QStringLiteral("uav_type_num"));
        uav_type_num->setLayoutDirection(Qt::RightToLeft);
        uav_type_num->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        splitter_5->addWidget(uav_type_num);
        uav_state = new QLineEdit(splitter_5);
        uav_state->setObjectName(QStringLiteral("uav_state"));
        uav_state->setLayoutDirection(Qt::RightToLeft);
        uav_state->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        splitter_5->addWidget(uav_state);
        splitter_6 = new QSplitter(groupBox_2);
        splitter_6->setObjectName(QStringLiteral("splitter_6"));
        splitter_6->setGeometry(QRect(260, 20, 71, 51));
        splitter_6->setOrientation(Qt::Vertical);
        uav_contralmode = new QLineEdit(splitter_6);
        uav_contralmode->setObjectName(QStringLiteral("uav_contralmode"));
        uav_contralmode->setLayoutDirection(Qt::RightToLeft);
        uav_contralmode->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        splitter_6->addWidget(uav_contralmode);
        uav_flymode = new QLineEdit(splitter_6);
        uav_flymode->setObjectName(QStringLiteral("uav_flymode"));
        uav_flymode->setLayoutDirection(Qt::RightToLeft);
        uav_flymode->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        splitter_6->addWidget(uav_flymode);
        splitter_7 = new QSplitter(groupBox_2);
        splitter_7->setObjectName(QStringLiteral("splitter_7"));
        splitter_7->setGeometry(QRect(10, 80, 321, 20));
        splitter_7->setOrientation(Qt::Horizontal);
        label_7 = new QLabel(splitter_7);
        label_7->setObjectName(QStringLiteral("label_7"));
        splitter_7->addWidget(label_7);
        uav_longitude = new QLineEdit(splitter_7);
        uav_longitude->setObjectName(QStringLiteral("uav_longitude"));
        uav_longitude->setLayoutDirection(Qt::RightToLeft);
        uav_longitude->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        splitter_7->addWidget(uav_longitude);
        label_8 = new QLabel(splitter_7);
        label_8->setObjectName(QStringLiteral("label_8"));
        splitter_7->addWidget(label_8);
        uav_latitude = new QLineEdit(splitter_7);
        uav_latitude->setObjectName(QStringLiteral("uav_latitude"));
        uav_latitude->setLayoutDirection(Qt::RightToLeft);
        uav_latitude->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        splitter_7->addWidget(uav_latitude);
        splitter_8 = new QSplitter(groupBox_2);
        splitter_8->setObjectName(QStringLiteral("splitter_8"));
        splitter_8->setGeometry(QRect(10, 110, 321, 21));
        splitter_8->setOrientation(Qt::Horizontal);
        label_10 = new QLabel(splitter_8);
        label_10->setObjectName(QStringLiteral("label_10"));
        splitter_8->addWidget(label_10);
        uav_grouundspeed = new QLineEdit(splitter_8);
        uav_grouundspeed->setObjectName(QStringLiteral("uav_grouundspeed"));
        uav_grouundspeed->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        splitter_8->addWidget(uav_grouundspeed);
        label_11 = new QLabel(splitter_8);
        label_11->setObjectName(QStringLiteral("label_11"));
        splitter_8->addWidget(label_11);
        uav_verticalspeed = new QLineEdit(splitter_8);
        uav_verticalspeed->setObjectName(QStringLiteral("uav_verticalspeed"));
        uav_verticalspeed->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        splitter_8->addWidget(uav_verticalspeed);
        label_9 = new QLabel(splitter_8);
        label_9->setObjectName(QStringLiteral("label_9"));
        splitter_8->addWidget(label_9);
        uav_altitude = new QLineEdit(splitter_8);
        uav_altitude->setObjectName(QStringLiteral("uav_altitude"));
        uav_altitude->setLayoutDirection(Qt::RightToLeft);
        uav_altitude->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        splitter_8->addWidget(uav_altitude);
        splitter_9 = new QSplitter(groupBox_2);
        splitter_9->setObjectName(QStringLiteral("splitter_9"));
        splitter_9->setGeometry(QRect(10, 140, 321, 21));
        splitter_9->setOrientation(Qt::Horizontal);
        label_12 = new QLabel(splitter_9);
        label_12->setObjectName(QStringLiteral("label_12"));
        splitter_9->addWidget(label_12);
        uav_line_angle = new QLineEdit(splitter_9);
        uav_line_angle->setObjectName(QStringLiteral("uav_line_angle"));
        uav_line_angle->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        splitter_9->addWidget(uav_line_angle);
        label_13 = new QLabel(splitter_9);
        label_13->setObjectName(QStringLiteral("label_13"));
        splitter_9->addWidget(label_13);
        uav_flight_angle = new QLineEdit(splitter_9);
        uav_flight_angle->setObjectName(QStringLiteral("uav_flight_angle"));
        uav_flight_angle->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        splitter_9->addWidget(uav_flight_angle);
        label_14 = new QLabel(splitter_9);
        label_14->setObjectName(QStringLiteral("label_14"));
        splitter_9->addWidget(label_14);
        uav_flight_time = new QLineEdit(splitter_9);
        uav_flight_time->setObjectName(QStringLiteral("uav_flight_time"));
        uav_flight_time->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        splitter_9->addWidget(uav_flight_time);
        splitter_10 = new QSplitter(groupBox_2);
        splitter_10->setObjectName(QStringLiteral("splitter_10"));
        splitter_10->setGeometry(QRect(10, 170, 321, 20));
        splitter_10->setOrientation(Qt::Horizontal);
        label_15 = new QLabel(splitter_10);
        label_15->setObjectName(QStringLiteral("label_15"));
        splitter_10->addWidget(label_15);
        uav_oil_meter = new QLineEdit(splitter_10);
        uav_oil_meter->setObjectName(QStringLiteral("uav_oil_meter"));
        uav_oil_meter->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        splitter_10->addWidget(uav_oil_meter);
        label_16 = new QLabel(splitter_10);
        label_16->setObjectName(QStringLiteral("label_16"));
        splitter_10->addWidget(label_16);
        uav_voltage = new QLineEdit(splitter_10);
        uav_voltage->setObjectName(QStringLiteral("uav_voltage"));
        uav_voltage->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        splitter_10->addWidget(uav_voltage);
        label_17 = new QLabel(splitter_10);
        label_17->setObjectName(QStringLiteral("label_17"));
        splitter_10->addWidget(label_17);
        uav_cpuratio = new QLineEdit(splitter_10);
        uav_cpuratio->setObjectName(QStringLiteral("uav_cpuratio"));
        uav_cpuratio->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        splitter_10->addWidget(uav_cpuratio);
        groupBox_3 = new QGroupBox(simDrone);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 250, 341, 51));
        splitter_12 = new QSplitter(groupBox_3);
        splitter_12->setObjectName(QStringLiteral("splitter_12"));
        splitter_12->setGeometry(QRect(10, 20, 321, 21));
        splitter_12->setOrientation(Qt::Horizontal);
        label_18 = new QLabel(splitter_12);
        label_18->setObjectName(QStringLiteral("label_18"));
        splitter_12->addWidget(label_18);
        row_angle = new QLineEdit(splitter_12);
        row_angle->setObjectName(QStringLiteral("row_angle"));
        splitter_12->addWidget(row_angle);
        label_19 = new QLabel(splitter_12);
        label_19->setObjectName(QStringLiteral("label_19"));
        splitter_12->addWidget(label_19);
        yaw_angle = new QLineEdit(splitter_12);
        yaw_angle->setObjectName(QStringLiteral("yaw_angle"));
        splitter_12->addWidget(yaw_angle);
        label_20 = new QLabel(splitter_12);
        label_20->setObjectName(QStringLiteral("label_20"));
        splitter_12->addWidget(label_20);
        pitch_angle = new QLineEdit(splitter_12);
        pitch_angle->setObjectName(QStringLiteral("pitch_angle"));
        splitter_12->addWidget(pitch_angle);
        splitter_11 = new QSplitter(simDrone);
        splitter_11->setObjectName(QStringLiteral("splitter_11"));
        splitter_11->setGeometry(QRect(9, 215, 150, 23));
        splitter_11->setOrientation(Qt::Horizontal);
        send_heartbeat = new QPushButton(splitter_11);
        send_heartbeat->setObjectName(QStringLiteral("send_heartbeat"));
        splitter_11->addWidget(send_heartbeat);
        send_attitude = new QPushButton(splitter_11);
        send_attitude->setObjectName(QStringLiteral("send_attitude"));
        splitter_11->addWidget(send_attitude);

        retranslateUi(simDrone);

        QMetaObject::connectSlotsByName(simDrone);
    } // setupUi

    void retranslateUi(QWidget *simDrone)
    {
        simDrone->setWindowTitle(QApplication::translate("simDrone", "simDrone", 0));
        groupBox->setTitle(QApplication::translate("simDrone", "\346\234\215\345\212\241\345\231\250\347\212\266\346\200\201", 0));
        label->setText(QApplication::translate("simDrone", "\347\253\257\345\217\243", 0));
        server_port->setText(QApplication::translate("simDrone", "TextLabel", 0));
        label_2->setText(QApplication::translate("simDrone", "\345\256\242\346\210\267\347\253\257IP", 0));
        client_ip->setText(QApplication::translate("simDrone", "NULL", 0));
        groupBox_2->setTitle(QApplication::translate("simDrone", "\345\221\250\346\234\2371s\347\232\204\344\270\213\350\241\214\347\263\273\347\273\237\345\277\203\350\267\263\346\225\260\346\215\256", 0));
        label_3->setText(QApplication::translate("simDrone", "\351\243\236\346\234\272\347\261\273\345\236\213\344\270\216\347\274\226\345\217\267", 0));
        label_4->setText(QApplication::translate("simDrone", "\346\277\200\346\264\273\344\270\216\350\277\220\350\241\214\347\212\266\346\200\201", 0));
        label_5->setText(QApplication::translate("simDrone", "\350\277\220\350\241\214\346\216\247\345\210\266\346\250\241\345\274\217", 0));
        label_6->setText(QApplication::translate("simDrone", "\351\243\236\350\241\214\346\250\241\345\274\217", 0));
        label_7->setText(QApplication::translate("simDrone", "\347\273\217\345\272\246", 0));
        label_8->setText(QApplication::translate("simDrone", "\347\272\254\345\272\246", 0));
        label_10->setText(QApplication::translate("simDrone", "\345\234\260\351\200\237", 0));
        label_11->setText(QApplication::translate("simDrone", "\345\215\207\351\231\215\351\200\237\345\272\246", 0));
        label_9->setText(QApplication::translate("simDrone", "\351\253\230\345\272\246", 0));
        label_12->setText(QApplication::translate("simDrone", "\350\275\250\350\277\271\350\247\222", 0));
        label_13->setText(QApplication::translate("simDrone", "\350\210\252\345\220\221\350\247\222", 0));
        label_14->setText(QApplication::translate("simDrone", "\351\243\236\350\241\214\346\227\266\351\227\264", 0));
        label_15->setText(QApplication::translate("simDrone", "\346\262\271\351\207\217", 0));
        label_16->setText(QApplication::translate("simDrone", "\347\224\265\346\261\240\347\224\265\345\216\213", 0));
        label_17->setText(QApplication::translate("simDrone", "CPU\345\210\251\347\224\250\347\216\207", 0));
        groupBox_3->setTitle(QApplication::translate("simDrone", "\345\247\277\346\200\201\346\225\260\346\215\256", 0));
        label_18->setText(QApplication::translate("simDrone", "\346\273\232\350\275\254\350\247\222", 0));
        label_19->setText(QApplication::translate("simDrone", "\345\201\217\350\210\252\350\247\222", 0));
        label_20->setText(QApplication::translate("simDrone", "\344\277\257\344\273\260\350\247\222", 0));
        send_heartbeat->setText(QApplication::translate("simDrone", "\345\217\221\351\200\201\345\277\203\350\267\263\346\225\260\346\215\256", 0));
        send_attitude->setText(QApplication::translate("simDrone", "\345\217\221\351\200\201\345\247\277\346\200\201\346\225\260\346\215\256", 0));
    } // retranslateUi

};

namespace Ui {
    class simDrone: public Ui_simDrone {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMDRONE_H
