#include "rpmgyroWidget.h"
#include "ui_rpmgyroWidget.h"
#include "QDebug"

QRpmgyroWidget::QRpmgyroWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QRpmgyroWidget)
{
    ui->setupUi(this);
    flag = new int(1);
    rpm = new int[2]{0};
    font = new QFont;

    *font = ui->radioButton_RPMTYPE1->font();
    
    initButtonGroup();
    initSlider();
    initLineEdit();
    connect(ui->pushButton_COLDIR, SIGNAL(clicked()),  this, SLOT(slot_colServoDir()));
}

QRpmgyroWidget::~QRpmgyroWidget()
{
    delete ui;
    if (p_QButtongroup)  delete p_QButtongroup;
    if (flag)            delete flag;
    if (rpm)             delete []rpm;
    if (font)            delete font;
}

void QRpmgyroWidget::initButtonGroup()
{
    p_QButtongroup = new QButtonGroup();
    p_QButtongroup->addButton(ui->pushButton_RPMTYPESET,        0);
    p_QButtongroup->addButton(ui->pushButton_RPMTYPEASK,        1);
    p_QButtongroup->addButton(ui->pushButton_COLSERVORANGESET,  2);
    p_QButtongroup->addButton(ui->pushButton_COLSERVORANGEASK,  3);
    p_QButtongroup->addButton(ui->pushButton_FLAMEOUTSET,       4);
    p_QButtongroup->addButton(ui->pushButton_FLAMEOUTTEST,      5);
    p_QButtongroup->addButton(ui->pushButton_IDLINGSET,         6);
    p_QButtongroup->addButton(ui->pushButton_IDLINGTEST,        7);  
    p_QButtongroup->addButton(ui->pushButton_SPEEDSET,          8);
    p_QButtongroup->addButton(ui->pushButton_SPEEDTEST,         9);
    p_QButtongroup->addButton(ui->pushButton_HIGHSPEEDSET,      10);
    p_QButtongroup->addButton(ui->pushButton_HIGHSPEEDTEST,     11);
    p_QButtongroup->addButton(ui->pushButton_RPMSET,            12);
    p_QButtongroup->addButton(ui->pushButton_RPMASK,            13);
    p_QButtongroup->addButton(ui->pushButton_CONSTANT_SPEEDSET, 14);
    p_QButtongroup->addButton(ui->pushButton_CONSTANT_SPEEDASK, 15); 
    p_QButtongroup->addButton(ui->pushButton_PSIOFFSET,         16);
    p_QButtongroup->addButton(ui->pushButton_PSIOFFASK,         17);
    p_QButtongroup->addButton(ui->pushButton_CALSTART,          18);
    p_QButtongroup->addButton(ui->pushButton_CALSTOP,           19);
    p_QButtongroup->addButton(ui->pushButton_CALEND,            20);
    p_QButtongroup->addButton(ui->pushButton_CALASK,            21);
    connect(p_QButtongroup,SIGNAL(buttonClicked(int)), this,SLOT(slot_cmdButtonClicked(int)));
}

void QRpmgyroWidget::initSlider()
{
    connect(ui->horizontalSlider_COLSERVORANGEMAX,SIGNAL(valueChanged(int)),this,SLOT(slot_sliderColMax(int)));
    connect(ui->horizontalSlider_COLSERVORANGEMIN,SIGNAL(valueChanged(int)),this,SLOT(slot_sliderColMin(int)));
    connect(ui->horizontalSlider_ENG,SIGNAL(valueChanged(int)),this,SLOT(slot_sliderEng(int)));
    connect(ui->horizontalSlider_engoffset,SIGNAL(valueChanged(int)),this,SLOT(slot_sliderEngOffset(int)));
    connect(ui->horizontalSlider_RPMI,SIGNAL(valueChanged(int)),this,SLOT(slot_sliderRPMI(int)));
}


void QRpmgyroWidget::initLineEdit()
{
    connect(ui->lineEdit_RPM1,SIGNAL(textChanged(QString)),this,SLOT(slot_lineEditRPM1(QString)));
    connect(ui->lineEdit_RPM2,SIGNAL(textChanged(QString)),this,SLOT(slot_lineEditRPM2(QString)));
}

void QRpmgyroWidget::slot_colServoDir()
{
    *flag = -(*flag);
    if (*flag==-1) ui->pushButton_COLDIR->setText(tr("反向"));
    else            ui->pushButton_COLDIR->setText(tr("正向"));
}


void QRpmgyroWidget::slot_cmdButtonClicked(int ButtonID)
{ 
    quint8  Data[20];
    int     tmpI; 
    float   tmpF;
    QString tmpS;
    
    switch(ButtonID) {
        case  0: //pushButton_RPMTYPESET
            if(ui->radioButton_RPMTYPE1->isChecked()) Data[0] = 0;
            else if(ui->radioButton_RPMTYPE2->isChecked()) Data[0] = 1;
            emit signal_cmdOutput(1, UAV_COMP_ID_ENGINE, UAV_MSG_ENG_TYPESET, Data, 1); 
            break;
        case  1: //pushButton_RPMTYPEASK 
            emit signal_cmdOutput(1, UAV_COMP_ID_ENGINE, UAV_MSG_ENG_TYPEASK, Data, 0);
            break;
        case  2: //pushButton_COLSERVORANGESET
            frame_push_int8_t(Data, 0,*flag);
            tmpI = ui->horizontalSlider_engoffset->value();        frame_push_int8_t(Data, 1, tmpI);
            tmpI = ui->horizontalSlider_COLSERVORANGEMAX->value(); frame_push_int16_t(Data, 2, tmpI);
            tmpI = ui->horizontalSlider_COLSERVORANGEMIN->value(); frame_push_int16_t(Data, 4, tmpI);
            
            emit signal_cmdOutput(1, UAV_COMP_ID_ENGINE, UAV_MSG_ENG_COLRANGESET, Data, 6);
            break;
        case  3: //pushButton_COLSERVORANGEASK
            emit signal_cmdOutput(1, UAV_COMP_ID_ENGINE, UAV_MSG_ENG_COLRANGEASK, Data, 0); 
            break;
        case  4: //pushButton_FLAMEOUTSET                                                         
            tmpI = ui->horizontalSlider_ENG->value();        frame_push_int16_t(Data, 0, tmpI);
            emit signal_cmdOutput(1, UAV_COMP_ID_ENGINE, UAV_MSG_ENG_FLAMEOUTSET, Data, 2);
            break;
        case  5: //pushButton_FLAMEOUTTEST 
            emit signal_cmdOutput(1, UAV_COMP_ID_ENGINE, UAV_MSG_ENG_FLAMEOUTTEST, Data, 0);
            break;
        case  6: //pushButton_IDLINGSET
            tmpI = ui->horizontalSlider_ENG->value();        frame_push_int16_t(Data, 0, tmpI);
            emit signal_cmdOutput(1, UAV_COMP_ID_ENGINE, UAV_MSG_ENG_IDLINGSET, Data, 2);
            break;
        case  7: //pushButton_IDLINGTEST 
            emit signal_cmdOutput(1, UAV_COMP_ID_ENGINE, UAV_MSG_ENG_IDLINGTEST, Data, 0);
            break;
        case  8: //pushButton_SPEEDSET
            tmpI = ui->horizontalSlider_ENG->value();        frame_push_int16_t(Data, 0, tmpI);
            emit signal_cmdOutput(1, UAV_COMP_ID_ENGINE, UAV_MSG_ENG_SPEEDSET, Data, 2);
            break;
        case  9: //pushButton_SPEEDTEST 
            emit signal_cmdOutput(1, UAV_COMP_ID_ENGINE, UAV_MSG_ENG_SPEEDTEST, Data, 0);
            break;
        case 10: //pushButton_HIGHSPEEDSET
            tmpI = ui->horizontalSlider_ENG->value();        frame_push_int16_t(Data, 0, tmpI);
            emit signal_cmdOutput(1, UAV_COMP_ID_ENGINE, UAV_MSG_ENG_CONSPEEDSET, Data, 2);
            break;
        case 11: //pushButton_HIGHSPEEDTEST
            emit signal_cmdOutput(1, UAV_COMP_ID_ENGINE, UAV_MSG_ENG_CONSPEEDTEST, Data, 0);
            break;
        case 12: //pushButton_RPMSET 
            tmpS = ui->lineEdit_RPM->text();
            tmpF = tmpS.toFloat();    frame_push_float(Data, 0, tmpF);    
            emit signal_cmdOutput(1, UAV_COMP_ID_ENGINE, UAV_MSG_ENG_RPMSET, Data, 4);
            break;
        case 13: //pushButton_RPMASK 
            emit signal_cmdOutput(1, UAV_COMP_ID_ENGINE, UAV_MSG_ENG_RPMASK, Data, 0);
            break;
        case 14: //pushButton_CONSTANT_SPEEDSET
            tmpI = ui->horizontalSlider_RPMI->value();        frame_push_uint16_t(Data, 0, tmpI);
            emit signal_cmdOutput(1, UAV_COMP_ID_ENGINE, UAV_MSG_ENG_SPEEDISET, Data,2);
            break;
        case 15: //pushButton_CONSTANT_SPEEDASK 
            emit signal_cmdOutput(1, UAV_COMP_ID_ENGINE, UAV_MSG_ENG_SPEEDIASK, Data, 0);
            break;
        case 16: //pushButton_PSIOFFSET
            tmpS = ui->lineEdit_PSIOFF->text();
            tmpF = tmpS.toFloat();    frame_push_float(Data, 0, tmpF);    
            emit signal_cmdOutput(1, UAV_COMP_ID_HMR, UAV_MSG_HMR_PSIOFFSET, Data, 4);
            break;
        case 17: //pushButton_PSIOFFASK 
            emit signal_cmdOutput(1, UAV_COMP_ID_HMR, UAV_MSG_HMR_PSIOFFASK, Data, 0);
            break;
        case 18: //pushButton_CALSTART
            emit signal_cmdOutput(1, UAV_COMP_ID_HMR, UAV_MSG_HMR_CALSTART, Data, 0); 
            break;
        case 19: //pushButton_CALSTOP
            emit signal_cmdOutput(1, UAV_COMP_ID_HMR, UAV_MSG_HMR_CALSTOP, Data, 0);
            break;
        case 20: //pushButton_CALEND
            tmpS = ui->lineEdit_KX->text(); tmpF = tmpS.toFloat();
            frame_push_float(Data,0,tmpF);
            tmpS = ui->lineEdit_KY->text(); tmpF = tmpS.toFloat();
            frame_push_float(Data,4,tmpF);
            tmpS = ui->lineEdit_BX->text(); tmpF = tmpS.toFloat();
            frame_push_float(Data,8,tmpF);
            tmpS = ui->lineEdit_BY->text(); tmpF = tmpS.toFloat();
            frame_push_float(Data,12,tmpF);
            emit signal_cmdOutput(1, UAV_COMP_ID_HMR, UAV_MSG_HMR_CALEND, Data, 16);
            break;
        case 21: //pushButton_CALASK 
            emit signal_cmdOutput(1, UAV_COMP_ID_HMR, UAV_MSG_HMR_CALASK, Data, 0);
            break;
    }
}

void QRpmgyroWidget::slot_sliderColMax(int value)
{
    ui->label_COLSERVORANGEMAX->setText(QString::number(value));
}

void QRpmgyroWidget::slot_sliderColMin(int value)
{
    ui->label_COLSERVORANGEMIN->setText(QString::number(value));
}

void QRpmgyroWidget::slot_sliderEng(int value)
{
    ui->label_COL->setText(QString::number(value));
}

void QRpmgyroWidget::slot_sliderEngOffset(int value)
{
    ui->label_engoffset->setText(QString::number(value));
}

void QRpmgyroWidget::slot_sliderRPMI(int value)
{
    ui->label_RPMI->setText(QString::number(value));
}

void QRpmgyroWidget::slot_lineEditRPM1(QString str1)
{
    rpm[0] = str1.toInt();
    ui->lineEdit_RPM->setText(QString::number(rpm[0]*rpm[1]));
}

void QRpmgyroWidget::slot_lineEditRPM2(QString str2)
{
    rpm[1] = str2.toInt();
    ui->lineEdit_RPM->setText(QString::number(rpm[0]*rpm[1]));
}

void QRpmgyroWidget::echoMessagePacket(datalink_message_t *msg)
{
    quint8 echoMsg;
    quint8 tmpData[16];

    switch (msg->msgid) {
	    case UAV_MSG_REQU_ECHO:    
	        echoMsg = msg->payload[0];
            switch(msg->compid){
                case UAV_COMP_ID_ENGINE:
                    switch (echoMsg) {
                        case UAV_MSG_REQU_SAVE:        break;
                        case UAV_MSG_REQU_DEL:         break;
                        case UAV_MSG_ENG_TYPESET:
                        case UAV_MSG_ENG_TYPEASK:
                            for (int idx=0; idx<1; idx++) tmpData[idx] = msg->payload[idx+1];
                            engCmdEchoOk(1, tmpData);
                            break;
                        case UAV_MSG_ENG_COLRANGESET:
                        case UAV_MSG_ENG_COLRANGEASK:
                            for (int idx=0; idx<6; idx++) tmpData[idx] = msg->payload[idx+1];
                            engCmdEchoOk(2, tmpData);
                            break;
                        case UAV_MSG_ENG_FLAMEOUTSET:
                        case UAV_MSG_ENG_FLAMEOUTTEST:
                            for (int idx=0; idx<2; idx++) tmpData[idx] = msg->payload[idx+1];
                            engCmdEchoOk(3, tmpData);
                            break;
                        case UAV_MSG_ENG_IDLINGSET:
                        case UAV_MSG_ENG_IDLINGTEST:
                            for (int idx=0; idx<2; idx++) tmpData[idx] = msg->payload[idx+1];
                            engCmdEchoOk(4, tmpData);
                            break;
                        case UAV_MSG_ENG_SPEEDSET:
                        case UAV_MSG_ENG_SPEEDTEST:
                            for (int idx=0; idx<2; idx++) tmpData[idx] = msg->payload[idx+1];
                            engCmdEchoOk(5, tmpData);
                            break;
                        case UAV_MSG_ENG_CONSPEEDSET:
                        case UAV_MSG_ENG_CONSPEEDTEST:
                            for (int idx=0; idx<2; idx++) tmpData[idx] = msg->payload[idx+1];
                            engCmdEchoOk(6, tmpData);
                            break;
                        case UAV_MSG_ENG_RPMSET:
                        case UAV_MSG_ENG_RPMASK:
                            for (int idx=0; idx<4; idx++) tmpData[idx] = msg->payload[idx+1];
                            engCmdEchoOk(7, tmpData);
                            break;
                        case UAV_MSG_ENG_SPEEDISET:
                        case UAV_MSG_ENG_SPEEDIASK:
                            for (int idx=0; idx<2; idx++) tmpData[idx] = msg->payload[idx+1];
                            engCmdEchoOk(8, tmpData);
                            break;
                        default:                     break;
                    }
                    break;
                case UAV_COMP_ID_HMR:
                    switch (echoMsg){
                        case UAV_MSG_REQU_SAVE:      break;
                        case UAV_MSG_REQU_DEL:       break;
                        case UAV_MSG_HMR_CALSTART:   break;
                        case UAV_MSG_HMR_CALSTOP:    break;
                        case UAV_MSG_HMR_CALEND:     break;
                        case UAV_MSG_HMR_CALASK:
                            for (int idx=0; idx<16; idx++) tmpData[idx] = msg->payload[idx+1];
                            hmcCmdEchoOk(1, tmpData);
                            break;
                        case UAV_MSG_HMR_PSIOFFSET:
                        case UAV_MSG_HMR_PSIOFFASK:
                            for (int idx=0; idx<4; idx++) tmpData[idx] = msg->payload[idx+1];
                            hmcCmdEchoOk(2, tmpData);
                            break;
                        case UAV_MSG_HMR_INFOASK:    break;
                        case UAV_MSG_HMR_RAWDATA:    break;
                        case UAV_MSG_HMR_INFODATA:   break;
                        case UAV_MSG_HMR_DIRSET:
                        case UAV_MSG_HMR_DIRASK:
                          //data_hmc.dir  = frame_return_float(msg->payload, 1);
                            break;
                        default:                     break;
                    }
                    break;
                default: break;
            }
            break;
        default: break;
	}
}


void QRpmgyroWidget::engCmdEchoOk(quint8 x, quint8 *data)
{
    QString tmpS;
    float   tmpF;
    int     tmpI;

    switch (x) {
        case 1:
            ui->radioButton_RPMTYPE1->setFont(*font);
            ui->radioButton_RPMTYPE2->setFont(*font);
            if(data[0] == 0)
            {
                ui->radioButton_RPMTYPE1->setChecked(true);
                ui->radioButton_RPMTYPE1->setFont(QFont("Times", 8, QFont::Bold));
                tmpS = ui->radioButton_RPMTYPE1->text();
                ui->radioButton_RPMTYPE1->setText(tmpS);
            }
            else if(data[0] == 1)
            {
                ui->radioButton_RPMTYPE2->setChecked(true);
                ui->radioButton_RPMTYPE2->setFont(QFont("Times", 8, QFont::Bold));
                tmpS = ui->radioButton_RPMTYPE2->text();
                ui->radioButton_RPMTYPE2->setText(tmpS);
            }
            break;
        case 2:
            if (frame_return_int8_t(data, 0)==1)   ui->pushButton_COLDIR->setText(tr("正向"));
            else                                   ui->pushButton_COLDIR->setText(tr("反向"));
            tmpI = frame_return_int8_t(data, 1);  ui->horizontalSlider_engoffset->setValue(tmpI);
            tmpI = frame_return_int16_t(data, 2);  ui->horizontalSlider_COLSERVORANGEMAX->setValue(tmpI);
            tmpI = frame_return_int16_t(data, 4);  ui->horizontalSlider_COLSERVORANGEMIN->setValue(tmpI);
            break;
        case 3:
            tmpI = frame_return_int16_t(data, 0);  ui->horizontalSlider_ENG->setValue(tmpI);
            break;
        case 4:
            tmpI = frame_return_int16_t(data, 0);  ui->horizontalSlider_ENG->setValue(tmpI);
            break;
        case 5:
            tmpI = frame_return_int16_t(data, 0);  ui->horizontalSlider_ENG->setValue(tmpI);
            break;
        case 6:
            tmpI = frame_return_int16_t(data, 0);  ui->horizontalSlider_ENG->setValue(tmpI);
            break;
        case 7:
            tmpF = frame_return_float(data,0);     ui->lineEdit_RPM->setText(QString::number(tmpF,'g',5));
            break;
        case 8:
            tmpI = frame_return_uint16_t(data, 0);  ui->horizontalSlider_RPMI->setValue(tmpI);
            break;
    }
}
       
void QRpmgyroWidget::hmcCmdEchoOk(quint8 x, quint8 *data)
{
    float   tmpF;

    switch (x) {
        case 1:
            tmpF = frame_return_float(data,0);    ui->lineEdit_KX->setText(QString::number(tmpF,'g',5));
            tmpF = frame_return_float(data,4);    ui->lineEdit_KY->setText(QString::number(tmpF,'g',5));
            tmpF = frame_return_float(data,8);    ui->lineEdit_BX->setText(QString::number(tmpF,'g',5));
            tmpF = frame_return_float(data,12);   ui->lineEdit_BY->setText(QString::number(tmpF,'g',5));
            break;
        case 2:
            tmpF = frame_return_float(data,0);    ui->lineEdit_PSIOFF->setText(QString::number(tmpF,'g',5));
            break;
    }
}
    
