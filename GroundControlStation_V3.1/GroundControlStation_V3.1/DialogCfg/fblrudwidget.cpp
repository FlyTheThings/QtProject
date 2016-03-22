#include "fblrudwidget.h"
#include "ui_fblrudwidget.h"
#include "QDebug"

QFblrudWidget::QFblrudWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QFblrudWidget)
{
    ui->setupUi(this);
    flag = new int;  *flag =1;
    font = new QFont;

    *font = ui->radioButton_FBL->font();

    initButtonGroup();
    initSlider();
    connect(ui->pushButton_RUDSERVODIR, SIGNAL(clicked()), this,SLOT(slot_RudServoDir()));
}

QFblrudWidget::~QFblrudWidget()
{
    delete ui;
    if (p_QButtongroup)  delete p_QButtongroup;
    if (flag)            delete flag;
    if (font)            delete font;
}

void QFblrudWidget::initButtonGroup()
{
    p_QButtongroup = new QButtonGroup();
    p_QButtongroup->addButton(ui->pushButton_FBLSET,     0);
    p_QButtongroup->addButton(ui->pushButton_FBLASK,     1);
    p_QButtongroup->addButton(ui->pushButton_GYROTYPESET,2);
    p_QButtongroup->addButton(ui->pushButton_GYROTYPEASK,3);
    p_QButtongroup->addButton(ui->pushButton_RUDSERVOSET,4);
    p_QButtongroup->addButton(ui->pushButton_RUDSERVOASK,5);
    p_QButtongroup->addButton(ui->pushButton_RUDRANGESET,6);
    p_QButtongroup->addButton(ui->pushButton_RUDRANGEASK,7);  
    connect(p_QButtongroup,SIGNAL(buttonClicked(int)),this,SLOT(slot_cmdButtonClicked(int)));
}

void QFblrudWidget::initSlider()
{
    connect(ui->horizontalSlider_FBL_AIL,SIGNAL(valueChanged(int)),this,SLOT(slot_sliderFBLAIL(int)));
    connect(ui->horizontalSlider_FBL_ELE,SIGNAL(valueChanged(int)),this,SLOT(slot_sliderFBLELE(int)));
    connect(ui->horizontalSlider_RUDRANGEMAX,SIGNAL(valueChanged(int)),this,SLOT(slot_sliderRUDMax(int)));
    connect(ui->horizontalSlider_RUDRANGEMIN,SIGNAL(valueChanged(int)),this,SLOT(slot_sliderRUDMin(int)));
    connect(ui->horizontalSlider_SOFFSET,SIGNAL(valueChanged(int)),this,SLOT(slot_sliderSOFFSET(int)));
}

void QFblrudWidget::slot_sliderFBLAIL(int value)
{
    ui->label_FBL_AIL->setText(QString::number(value));
}

void QFblrudWidget::slot_sliderFBLELE(int value)
{
    ui->label_FBL_ELE->setText(QString::number(value));
}

void QFblrudWidget::slot_sliderRUDMax(int value)
{
    ui->label_RUDRANGEMAX->setText(QString::number(value));
}

void QFblrudWidget::slot_sliderRUDMin(int value)
{
    ui->label_RUDRANGEMIN->setText(QString::number(value));
}

void QFblrudWidget::slot_sliderSOFFSET(int value)
{
    ui->label_SOFFSET->setText(QString::number(value));
}

void QFblrudWidget::slot_RudServoDir()
{
    *flag = -(*flag);
    if (*flag == -1)     ui->pushButton_RUDSERVODIR->setText(tr("反向"));
    else            ui->pushButton_RUDSERVODIR->setText(tr("正向"));
}

void QFblrudWidget::slot_cmdButtonClicked(int ButtonID)
{ 
    quint8  Data[7];
    int     tmpI;
    
    switch(ButtonID) {
        case  0: //pushButton_FBLSET
            if(ui->radioButton_FBL->isChecked())            frame_push_uint8_t(Data, 0, 0);
            if(ui->radioButton_NOFBL->isChecked())          frame_push_uint8_t(Data, 0, 1);
            tmpI = ui->horizontalSlider_FBL_ELE->value();   frame_push_uint16_t(Data, 1, tmpI);
            tmpI = ui->horizontalSlider_FBL_AIL->value();   frame_push_uint16_t(Data, 3, tmpI);
            emit signal_cmdOutput(1, UAV_COMP_ID_ACS, UAV_MSG_ACS_FBLSET, Data, 5);
            break;
        case  1: //pushButton_FBLASK 
            emit signal_cmdOutput(1, UAV_COMP_ID_ACS, UAV_MSG_ACS_FBLASK, Data, 0); 
            break;
        case  2: //pushButton_GYROTYPESET
            if(ui->radioButton_GYROTYPE1->isChecked())  Data[0] = 0;
            if(ui->radioButton_GYROTYPE2->isChecked())  Data[0] = 1;
            emit signal_cmdOutput(1, UAV_COMP_ID_ACS, UAV_MSG_ACS_GYROTYPESET, Data, 1);   
            break;
        case  3: //pushButton_GYROTYPEASK
            emit signal_cmdOutput(1, UAV_COMP_ID_ACS, UAV_MSG_ACS_GYROTYPEASK, Data, 0); 
            break;
        case  4: //pushButton_RUDSERVOSET                                                 
            Data[0] = (quint8)ui->comboBox_RUDSERVO->currentIndex();
            emit signal_cmdOutput(1, UAV_COMP_ID_ACS, UAV_MSG_ACS_RUDSERVOSET, Data, 1);
            break;
        case  5: //pushButton_RUDSERVOASK 
            emit signal_cmdOutput(1, UAV_COMP_ID_ACS, UAV_MSG_ACS_RUDSERVOASK, Data, 0); 
            break;
        case  6: //pushButton_RUDRANGESET
            frame_push_int8_t(Data, 0,*flag);
            tmpI = ui->horizontalSlider_SOFFSET->value();     frame_push_int16_t(Data, 1, tmpI);
            tmpI = ui->horizontalSlider_RUDRANGEMAX->value(); frame_push_int16_t(Data, 3, tmpI);
            tmpI = ui->horizontalSlider_RUDRANGEMIN->value(); tmpI = tmpI-1; frame_push_int16_t(Data, 5, tmpI);

            emit signal_cmdOutput(1, UAV_COMP_ID_ACS, UAV_MSG_ACS_RUDRANGESET, Data, 7);
            break;
        case  7: //pushButton_RUDRANGEASK 
            emit signal_cmdOutput(1, UAV_COMP_ID_ACS, UAV_MSG_ACS_RUDRANGEASK, Data, 0); 
            break;
    }
}

void QFblrudWidget::echoMessagePacket(datalink_message_t *msg)
{
    quint8 echoMsg;
    quint8 tmpData[7];
    
    switch (msg->msgid) {
	    case UAV_MSG_REQU_ECHO:    
	        echoMsg = msg->payload[0];
	        
	        switch (echoMsg) {
            case UAV_MSG_ACS_FBLSET:
            case UAV_MSG_ACS_FBLASK:
                for (int idx=0; idx<5; idx++) tmpData[idx] = msg->payload[idx+1];
                fblRudCmdEchoOk(1, tmpData);
                break;
            case UAV_MSG_ACS_RUDSERVOSET:
            case UAV_MSG_ACS_RUDSERVOASK:
                for (int idx=0; idx<1; idx++) tmpData[idx] = msg->payload[idx+1];
                fblRudCmdEchoOk(3, tmpData);
                break;
            case UAV_MSG_ACS_GYROTYPESET:
            case UAV_MSG_ACS_GYROTYPEASK:
                for (int idx=0; idx<1; idx++) tmpData[idx] = msg->payload[idx+1];
                fblRudCmdEchoOk(2, tmpData);
                break;
            case UAV_MSG_ACS_RUDRANGESET:
            case UAV_MSG_ACS_RUDRANGEASK:
                for (int idx=0; idx<7; idx++) tmpData[idx] = msg->payload[idx+1];
                fblRudCmdEchoOk(4, tmpData);
                break;
	        }
	        break;
        default: break;
	}
}

void QFblrudWidget::fblRudCmdEchoOk(quint8 x, quint8 *data)
{
    QString tmpS;
    int     tmpI;

    switch (x) {
        case 1:
            ui->radioButton_FBL->setFont(*font);
            ui->radioButton_NOFBL->setFont(*font);
            if(frame_return_uint8_t(data,0)==0)
            {
                ui->radioButton_FBL->setChecked(true);
                ui->radioButton_FBL->setFont(QFont("Times", 8, QFont::Bold));
                tmpS = ui->radioButton_FBL->text();
                ui->radioButton_FBL->setText(tmpS);
            }
            if(frame_return_uint8_t(data,0)==1)
            {
                ui->radioButton_NOFBL->setChecked(true);
                ui->radioButton_NOFBL->setFont(QFont("Times", 8, QFont::Bold));
                tmpS = ui->radioButton_NOFBL->text();
                ui->radioButton_NOFBL->setText(tmpS);
            }

            tmpI = frame_return_uint16_t(data, 1); ui->horizontalSlider_FBL_ELE->setValue(tmpI);
            tmpI = frame_return_uint16_t(data, 3); ui->horizontalSlider_FBL_AIL->setValue(tmpI);
            break;
        case 2:
            ui->radioButton_GYROTYPE1->setFont(*font);
            ui->radioButton_GYROTYPE2->setFont(*font);
            if(data[0] == 0)
            {
                ui->radioButton_GYROTYPE1->setChecked(true);
                ui->radioButton_GYROTYPE1->setFont(QFont("Times", 8, QFont::Bold));
                tmpS = ui->radioButton_GYROTYPE1->text();
                ui->radioButton_GYROTYPE1->setText(tmpS);
            }
            else if(data[0] == 1)
            {
                ui->radioButton_GYROTYPE2->setChecked(true);
                ui->radioButton_GYROTYPE2->setFont(QFont("Times", 8, QFont::Bold));
                tmpS = ui->radioButton_GYROTYPE2->text();
                ui->radioButton_GYROTYPE2->setText(tmpS);
            }
            break;
        case 3:
            tmpI = frame_return_uint8_t(data, 0);
            ui->comboBox_RUDSERVO->setFont(QFont("Times", 8, QFont::Bold));
            ui->comboBox_RUDSERVO->setCurrentIndex(tmpI);
            break;
        case 4:
            if (frame_return_int8_t(data, 0)==1)   ui->pushButton_RUDSERVODIR->setText(tr("正向"));
            else                                   ui->pushButton_RUDSERVODIR->setText(tr("反向"));
            tmpI = frame_return_int16_t(data, 1); ui->horizontalSlider_SOFFSET->setValue(tmpI);
            tmpI = frame_return_int16_t(data, 3); ui->horizontalSlider_RUDRANGEMAX->setValue(tmpI);
            tmpI = frame_return_int16_t(data, 5); ui->horizontalSlider_RUDRANGEMIN->setValue(tmpI);
            break;
    }
}
   
