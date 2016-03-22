#include "swashplatewidget.h"
#include "ui_swashplatewidget.h" 

QSwashplateWidget::QSwashplateWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QSwashplateWidget)
{
    ui->setupUi(this);

    font = new QFont;

    *font = ui->radioButton_H1->font();

    
    initButtonGroup1();
    initButtonGroup2();
    initSliders();
}

QSwashplateWidget::~QSwashplateWidget()
{
    delete ui;
    if (p_QButtongroup)  delete p_QButtongroup;
    if (p_QButtongroup1) delete p_QButtongroup1;
    if (flag)            delete []flag;
    if (font)            delete font;
}

void QSwashplateWidget::initButtonGroup1()
{
    flag = new int[7]{1,1,1,1,1,1,1};
    p_QButtongroup = new QButtonGroup();
    p_QButtongroup->addButton(ui->pushButton_ELEDIRECT,0);
    p_QButtongroup->addButton(ui->pushButton_AILDIRECT,1);
    p_QButtongroup->addButton(ui->pushButton_COLDIRECT,2);
    p_QButtongroup->addButton(ui->pushButton_S1DIR,    3);
    p_QButtongroup->addButton(ui->pushButton_S2DIR,    4);
    p_QButtongroup->addButton(ui->pushButton_S3DIR,    5);
    p_QButtongroup->addButton(ui->pushButton_S4DIR,    6); 
    connect(p_QButtongroup,SIGNAL(buttonClicked(int)), this,SLOT(slot_dirButtonClicked(int)));
}

void QSwashplateWidget::initButtonGroup2()
{ 
    p_QButtongroup1 = new QButtonGroup();
    p_QButtongroup1->addButton(ui->pushButton_TILTTYPESET,  0);
    p_QButtongroup1->addButton(ui->pushButton_TILTTYPEASK,  1);
    p_QButtongroup1->addButton(ui->pushButton_TILTPHASESET, 2);
    p_QButtongroup1->addButton(ui->pushButton_TILTPHASEASK, 3);
    p_QButtongroup1->addButton(ui->pushButton_TILTDIRSET,   4);
    p_QButtongroup1->addButton(ui->pushButton_TILTDIRASK,   5);  
    p_QButtongroup1->addButton(ui->pushButton_TILTS1SET,    6);
    p_QButtongroup1->addButton(ui->pushButton_TILTS1ASK,    7);
    p_QButtongroup1->addButton(ui->pushButton_TILTS2SET,    8);
    p_QButtongroup1->addButton(ui->pushButton_TILTS2ASK,    9);
    p_QButtongroup1->addButton(ui->pushButton_TILTS3SET,    10);
    p_QButtongroup1->addButton(ui->pushButton_TILTS3ASK,    11); 
    p_QButtongroup1->addButton(ui->pushButton_TILTS4SET,    12);
    p_QButtongroup1->addButton(ui->pushButton_TILTS4ASK,    13); 
    connect(p_QButtongroup1,SIGNAL(buttonClicked(int)), this,SLOT(slot_cmdButtonClicked(int)));
}

void QSwashplateWidget::initSliders()
{
    ui->horizontalSlider_phase->setSingleStep(1);

    connect(ui->horizontalSlider_phase,SIGNAL(valueChanged(int)),this,SLOT(slot_sliderPhase(int)));
    connect(ui->horizontalSlider_MIXAIL,SIGNAL(valueChanged(int)),this,SLOT(slot_sliderMixail(int)));
    connect(ui->horizontalSlider_MIXCOL,SIGNAL(valueChanged(int)),this,SLOT(slot_sliderMixcol(int)));
    connect(ui->horizontalSlider_MIXELE,SIGNAL(valueChanged(int)),this,SLOT(slot_sliderMixele(int)));
    connect(ui->horizontalSlider_S1,SIGNAL(valueChanged(int)),this,SLOT(slot_sliderS1(int)));
    connect(ui->horizontalSlider_S2,SIGNAL(valueChanged(int)),this,SLOT(slot_sliderS2(int)));
    connect(ui->horizontalSlider_S3,SIGNAL(valueChanged(int)),this,SLOT(slot_sliderS3(int)));
    connect(ui->horizontalSlider_S4,SIGNAL(valueChanged(int)),this,SLOT(slot_sliderS4(int)));
}

void QSwashplateWidget::slot_dirButtonClicked(int ButtonID)
{ 
    switch(ButtonID) {
        case  0: //pushButton_ELEDIRECT
            flag[0] = -flag[0];
            if (flag[0]==-1) ui->pushButton_ELEDIRECT->setText(tr("反向"));
            else            ui->pushButton_ELEDIRECT->setText(tr("正向"));
            break;
        case  1: //pushButton_AILDIRECT 
            flag[1] = -flag[1];
            if (flag[1]==-1) ui->pushButton_AILDIRECT->setText(tr("反向"));
            else            ui->pushButton_AILDIRECT->setText(tr("正向"));
            break;
        case  2: //pushButton_COLDIRECT
            flag[2] = -flag[2];
            if (flag[2]==-1) ui->pushButton_COLDIRECT->setText(tr("反向"));
            else            ui->pushButton_COLDIRECT->setText(tr("正向"));
            break;
        case  3: //pushButton_S1DIR
            flag[3] = -flag[3];
            if (flag[3]==-1) ui->pushButton_S1DIR->setText(tr("反向"));
            else            ui->pushButton_S1DIR->setText(tr("正向")); 
            break;
        case  4: //pushButton_S2DIR                      
            flag[4] = -flag[4];
            if (flag[4]==-1) ui->pushButton_S2DIR->setText(tr("反向"));
            else            ui->pushButton_S2DIR->setText(tr("正向"));
            break;
        case  5: //pushButton_S3DIR 
            flag[5] = -flag[5];
            if (flag[5]==-1) ui->pushButton_S3DIR->setText(tr("反向"));
            else            ui->pushButton_S3DIR->setText(tr("正向"));
            break;
        case  6: //pushButton_S4DIR
            flag[6] = -flag[6];
            if (flag[6]==-1) ui->pushButton_S4DIR->setText(tr("反向"));
            else            ui->pushButton_S4DIR->setText(tr("正向")); 
            break;
    }
}

void QSwashplateWidget::slot_cmdButtonClicked(int ButtonID)
{ 
    quint8  Data[9];  
    float     tmpF;
    int       tmpI;
    
    switch(ButtonID) {
        case  0: //pushButton_TILTTYPESET
            if(ui->radioButton_H1->isChecked())
                Data[0] = 0;
            else if(ui->radioButton_H3->isChecked())
                Data[0] = 1;
            else if(ui->radioButton_HR3->isChecked())
                Data[0] = 2;
            else if(ui->radioButton_H140->isChecked())
                Data[0] = 3;
            else if(ui->radioButton_HE3->isChecked())
                Data[0] = 4;
            else if(ui->radioButton_H4->isChecked())
                Data[0] = 5;
            emit signal_cmdOutput(1, UAV_COMP_ID_ACS, UAV_MSG_ACS_TILTTYPESET, Data, 1);   
            break;
        case  1: //pushButton_TILTTYPEASK 
            emit signal_cmdOutput(1, UAV_COMP_ID_ACS, UAV_MSG_ACS_TILTTYPEASK, Data, 0);   
            break;
        case  2: //pushButton_TILTPHASESET
            tmpF = ui->horizontalSlider_phase->value();
            frame_push_float(Data, 0, tmpF);
            emit signal_cmdOutput(1, UAV_COMP_ID_ACS, UAV_MSG_ACS_TILTPHASESET, Data, 4);
            break;
        case  3: //pushButton_TILTPHASEASK
            emit signal_cmdOutput(1, UAV_COMP_ID_ACS, UAV_MSG_ACS_TILTPHASEASK, Data, 0);  
            break;
        case  4: //pushButton_TILTDIRSET 
            frame_push_int8_t(Data, 0,flag[0]);
            tmpI = ui->horizontalSlider_MIXELE->value(); frame_push_uint8_t(Data, 1, tmpI);
            
            frame_push_int8_t(Data, 2,flag[1]);
            tmpI = ui->horizontalSlider_MIXAIL->value(); frame_push_uint8_t(Data, 3, tmpI);
            
            frame_push_int8_t(Data, 4,flag[2]);
            tmpI = ui->horizontalSlider_MIXCOL->value(); frame_push_uint8_t(Data, 5, tmpI);
            
            emit signal_cmdOutput(1, UAV_COMP_ID_ACS, UAV_MSG_ACS_TILTMIXSET, Data, 6);
            break;
        case  5: //pushButton_TILTDIRASK 
            emit signal_cmdOutput(1, UAV_COMP_ID_ACS, UAV_MSG_ACS_TILTMIXASK, Data, 0); 
            break;
        case  6: //pushButton_TILTS1SET
            frame_push_int8_t(Data, 0,flag[3]);
            tmpI = ui->horizontalSlider_S1->value(); frame_push_int16_t(Data, 1, tmpI);
            
            emit signal_cmdOutput(1, UAV_COMP_ID_ACS, UAV_MSG_ACS_TILTS1SET, Data, 3); 
            break;
        case  7: //pushButton_TILTS1ASK 
            emit signal_cmdOutput(1, UAV_COMP_ID_ACS, UAV_MSG_ACS_TILTS1ASK, Data, 0); 
            break;
        case  8: //pushButton_TILTS2SET
            frame_push_int8_t(Data, 0,flag[4]);
            tmpI = ui->horizontalSlider_S2->value(); frame_push_int16_t(Data, 1, tmpI);
            
            emit signal_cmdOutput(1, UAV_COMP_ID_ACS, UAV_MSG_ACS_TILTS2SET, Data, 3);  
            break;
        case  9: //pushButton_TILTS2ASK
            emit signal_cmdOutput(1, UAV_COMP_ID_ACS, UAV_MSG_ACS_TILTS2ASK, Data, 0); 
            break;
        case 10: //pushButton_TILTS3SET
            frame_push_int8_t(Data, 0,flag[5]);
            tmpI = ui->horizontalSlider_S3->value(); frame_push_int16_t(Data, 1, tmpI);
            
            emit signal_cmdOutput(1, UAV_COMP_ID_ACS, UAV_MSG_ACS_TILTS3SET, Data, 3);
            break;
        case 11: //pushButton_TILTS3ASK 
            emit signal_cmdOutput(1, UAV_COMP_ID_ACS, UAV_MSG_ACS_TILTS3ASK, Data, 0); 
            break;            
        case 12: //pushButton_TILTS4SET
            frame_push_int8_t(Data, 0,flag[6]);
            tmpI = ui->horizontalSlider_S4->value(); frame_push_int16_t(Data, 1, tmpI);
            
            emit signal_cmdOutput(1, UAV_COMP_ID_ACS, UAV_MSG_ACS_TILTS4SET, Data, 3);
            break;
        case 13: //pushButton_TILTS4ASK 
            emit signal_cmdOutput(1, UAV_COMP_ID_ACS, UAV_MSG_ACS_TILTS4ASK, Data, 0); 
            break; 
    }
}

void QSwashplateWidget::slot_sliderPhase(int value)
{
    ui->label_phase->setText(QString::number(value)+"°");
}

void QSwashplateWidget::slot_sliderMixail(int value)
{
    ui->label_MIXAIL->setText(QString::number(value)+"%");
}

void QSwashplateWidget::slot_sliderMixcol(int value)
{
    ui->label_MIXCOL->setText(QString::number(value)+"%");
}

void QSwashplateWidget::slot_sliderMixele(int value)
{
    ui->label_MIXELE->setText(QString::number(value)+"%");
}

void QSwashplateWidget::slot_sliderS1(int value)
{
    ui->label_S1->setText(QString::number(value));
}

void QSwashplateWidget::slot_sliderS2(int value)
{
    ui->label_S2->setText(QString::number(value));
}

void QSwashplateWidget::slot_sliderS3(int value)
{
    ui->label_S3->setText(QString::number(value));
}

void QSwashplateWidget::slot_sliderS4(int value)
{
    ui->label_S4->setText(QString::number(value));
}

void QSwashplateWidget::echoMessagePacket(datalink_message_t *msg)
{
    quint8 echoMsg;
    quint8 tmpData[8];

    switch (msg->msgid) {
	    case UAV_MSG_REQU_ECHO:    
	        echoMsg = msg->payload[0];	        
	        switch (echoMsg) {
                case UAV_MSG_ACS_TILTTYPESET:
                case UAV_MSG_ACS_TILTTYPEASK:
                    tmpData[0] = msg->payload[1];
                    tiltCmdEchoOk(1, tmpData);
                    break;
                case UAV_MSG_ACS_TILTMIXSET:
                case UAV_MSG_ACS_TILTMIXASK:
                    for (int idx=0; idx<8; idx++) tmpData[idx] = msg->payload[idx+1];
                    tiltCmdEchoOk(3, tmpData);
                    break;
                case UAV_MSG_ACS_TILTPHASESET:
                case UAV_MSG_ACS_TILTPHASEASK:
                    for (int idx=0; idx<4; idx++) tmpData[idx] = msg->payload[idx+1];
                    tiltCmdEchoOk(2, tmpData);
                    break;
                case UAV_MSG_ACS_TILTS1SET:
                case UAV_MSG_ACS_TILTS1ASK:
                    for (int idx=0; idx<3; idx++) tmpData[idx] = msg->payload[idx+1];
                    tiltCmdEchoOk(4, tmpData);
                    break;
                case UAV_MSG_ACS_TILTS2SET:
                case UAV_MSG_ACS_TILTS2ASK:
                    for (int idx=0; idx<3; idx++) tmpData[idx] = msg->payload[idx+1];
                    tiltCmdEchoOk(5, tmpData);
                    break;
                case UAV_MSG_ACS_TILTS3SET:
                case UAV_MSG_ACS_TILTS3ASK:
                    for (int idx=0; idx<3; idx++) tmpData[idx] = msg->payload[idx+1];
                    tiltCmdEchoOk(6, tmpData);
                    break;
                case UAV_MSG_ACS_TILTS4SET:
                case UAV_MSG_ACS_TILTS4ASK:
                    for (int idx=0; idx<3; idx++) tmpData[idx] = msg->payload[idx+1];
                    tiltCmdEchoOk(7, tmpData);
                    break;
                default:  break;
	        }
	        break;
        default: break;
	}
}

void QSwashplateWidget::tiltCmdEchoOk(quint8 x, quint8 *data)
{
    QString tmpS;
    int     tmpI;
    float   tmpF;

    switch (x) {
        case 1:
            ui->radioButton_H1->setFont(*font);
            ui->radioButton_H3->setFont(*font);
            ui->radioButton_HR3->setFont(*font);
            ui->radioButton_H140->setFont(*font);
            ui->radioButton_HE3->setFont(*font);
            ui->radioButton_H4->setFont(*font);
            switch(data[0]){
                case 0:ui->radioButton_H1->setFont(QFont("Times", 8, QFont::Bold));
                       ui->radioButton_H1->setChecked(true);
                       tmpS = ui->radioButton_H1->text();   ui->radioButton_H1->setText(tmpS);
                       break;
                case 1:ui->radioButton_H3->setFont(QFont("Times", 8, QFont::Bold));
                       ui->radioButton_H3->setChecked(true);
                       tmpS = ui->radioButton_H3->text();   ui->radioButton_H3->setText(tmpS);
                       break;
                case 2:ui->radioButton_HR3->setFont(QFont("Times", 8, QFont::Bold));
                       ui->radioButton_HR3->setChecked(true);
                       tmpS = ui->radioButton_HR3->text();   ui->radioButton_HR3->setText(tmpS);
                       break;
                case 3:ui->radioButton_H140->setFont(QFont("Times", 8, QFont::Bold));
                       ui->radioButton_H140->setChecked(true);
                       tmpS = ui->radioButton_H140->text();   ui->radioButton_H140->setText(tmpS);
                       break;
                case 4:ui->radioButton_HE3->setFont(QFont("Times", 8, QFont::Bold));
                       ui->radioButton_HE3->setChecked(true);
                       tmpS = ui->radioButton_HE3->text();   ui->radioButton_HE3->setText(tmpS);
                       break;
                case 5:ui->radioButton_H4->setFont(QFont("Times", 8, QFont::Bold));
                       ui->radioButton_H4->setChecked(true);
                       tmpS = ui->radioButton_H4->text();   ui->radioButton_H4->setText(tmpS);
                       break;
                default: break;
            }
            break;
        case 2:
            tmpF = frame_return_float(data, 0);  ui->horizontalSlider_phase->setValue(tmpF);
            break;
        case 3:
            if (frame_return_int8_t(data, 0)==1)   ui->pushButton_ELEDIRECT->setText(tr("正向"));
            else                                   ui->pushButton_ELEDIRECT->setText(tr("反向"));
            tmpI = frame_return_uint8_t(data, 1); ui->horizontalSlider_MIXELE->setValue(tmpI);

            if (frame_return_int8_t(data, 2)==1)   ui->pushButton_AILDIRECT->setText(tr("正向"));
            else                                   ui->pushButton_AILDIRECT->setText(tr("反向"));
            tmpI = frame_return_uint8_t(data, 3); ui->horizontalSlider_MIXAIL->setValue(tmpI);

            if (frame_return_int8_t(data, 4)==1)   ui->pushButton_COLDIRECT->setText(tr("正向"));
            else                                   ui->pushButton_COLDIRECT->setText(tr("反向"));
            tmpI = frame_return_uint8_t(data, 5); ui->horizontalSlider_MIXCOL->setValue(tmpI);
            break;
        case 4:
            if (frame_return_int8_t(data, 0)==1)   ui->pushButton_S1DIR->setText(tr("正向"));
            else                                   ui->pushButton_S1DIR->setText(tr("反向"));
            tmpI = frame_return_int16_t(data, 1); ui->horizontalSlider_S1->setValue(tmpI);
            break;
        case 5:
            if (frame_return_int8_t(data, 0)==1)   ui->pushButton_S2DIR->setText(tr("正向"));
            else                                   ui->pushButton_S2DIR->setText(tr("反向"));
            tmpI = frame_return_int16_t(data, 1); ui->horizontalSlider_S2->setValue(tmpI);
            break;
        case 6:
            if (frame_return_int8_t(data, 0)==1)   ui->pushButton_S3DIR->setText(tr("正向"));
            else                                   ui->pushButton_S3DIR->setText(tr("反向"));
            tmpI = frame_return_int16_t(data, 1); ui->horizontalSlider_S3->setValue(tmpI);
            break;
        case 7:
            if (frame_return_int8_t(data, 0)==1)   ui->pushButton_S4DIR->setText(tr("正向"));
            else                                   ui->pushButton_S4DIR->setText(tr("反向"));
            tmpI = frame_return_int16_t(data, 1); ui->horizontalSlider_S4->setValue(tmpI);
            break;
    }
}

