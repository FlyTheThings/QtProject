#include "selfflywidget.h"
#include "ui_selfflywidget.h"

QSelfflyWidget::QSelfflyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QSelfflyWidget)
{
    ui->setupUi(this);
    
    initButtonGroup(); 
    initSlider();
}

QSelfflyWidget::~QSelfflyWidget()
{
    delete ui;
    if (p_QButtongroup)  delete p_QButtongroup;
}

void QSelfflyWidget::initButtonGroup()
{
    p_QButtongroup = new QButtonGroup();
    p_QButtongroup->addButton(ui->pushButton_AUTO_ELESET, 0);
    p_QButtongroup->addButton(ui->pushButton_AUTO_ELEASK, 1);
    p_QButtongroup->addButton(ui->pushButton_AUTO_AILSET, 2);
    p_QButtongroup->addButton(ui->pushButton_AUTO_AILASK, 3);
    p_QButtongroup->addButton(ui->pushButton_AUTO_RUDSET, 4);
    p_QButtongroup->addButton(ui->pushButton_AUTO_RUDASK, 5);
    p_QButtongroup->addButton(ui->pushButton_AUTO_COLSET, 6);
    p_QButtongroup->addButton(ui->pushButton_AUTO_COLASK, 7);  
    connect(p_QButtongroup,SIGNAL(buttonClicked(int)), this,SLOT(slot_cmdButtonClicked(int)));
}

void QSelfflyWidget::initSlider()
{
    connect(ui->horizontalSlider_AUTO_COL,SIGNAL(valueChanged(int)),this,SLOT(slot_sliderCOL(int)));
    connect(ui->horizontalSlider_AUTO_RUD,SIGNAL(valueChanged(int)),this,SLOT(slot_sliderRUD(int)));
    connect(ui->horizontalSlider_PHI2AIL,SIGNAL(valueChanged(int)),this,SLOT(slot_sliderPHI2AIL(int)));
    connect(ui->horizontalSlider_THETA2ELE,SIGNAL(valueChanged(int)),this,SLOT(slot_sliderTHETA2ELE(int)));
    connect(ui->horizontalSlider_VX2ELE,SIGNAL(valueChanged(int)),this,SLOT(slot_sliderVX2ELE(int)));
    connect(ui->horizontalSlider_VY2AIL,SIGNAL(valueChanged(int)),this,SLOT(slot_sliderVY2AIL(int)));
}

void QSelfflyWidget::slot_sliderCOL(int value)
{
    ui->label_AUTO_COL->setText(QString::number(value));
}

void QSelfflyWidget::slot_sliderRUD(int value)
{
    ui->label_AUTO_RUD->setText(QString::number(value));
}

void QSelfflyWidget::slot_sliderPHI2AIL(int value)
{
    ui->label_PHI2AIL->setText(QString::number(value));
}

void QSelfflyWidget::slot_sliderTHETA2ELE(int value)
{
    ui->label_THETA2ELE->setText(QString::number(value));
}

void QSelfflyWidget::slot_sliderVX2ELE(int value)
{
    ui->label_VX2ELE->setText(QString::number(value));
}

void QSelfflyWidget::slot_sliderVY2AIL(int value)
{
    ui->label_VY2AIL->setText(QString::number(value));
}

void QSelfflyWidget::slot_cmdButtonClicked(int ButtonID)
{ 
    quint8  Data[10];   
    int     tmpI; 
    float   tmpF;
    QString tmpS;
    
    switch(ButtonID) {
        case  0: //pushButton_AUTO_ELESET
            tmpI = ui->horizontalSlider_THETA2ELE->value();  frame_push_uint16_t(Data, 0, tmpI);
            tmpI = ui->horizontalSlider_VX2ELE->value();     frame_push_uint16_t(Data, 2, tmpI);
            tmpS = ui->lineEdit_ELEMIN->text();
            tmpF = tmpS.toFloat();                           frame_push_float(Data, 4, tmpF);
            tmpS = ui->lineEdit_ELEMAX->text();
            tmpF = tmpS.toFloat();                           frame_push_float(Data, 8, tmpF);
            
            emit signal_cmdOutput(1, UAV_COMP_ID_CTRLCHANNAL, UAV_GNC_AUTO_ELESET, Data, 12);
            break;
        case  1: //pushButton_AUTO_ELEASK 
            emit signal_cmdOutput(1, UAV_COMP_ID_CTRLCHANNAL, UAV_GNC_AUTO_ELEASK, Data, 0); 
            break;
        case  2: //pushButton_AUTO_AILSET
            tmpI = ui->horizontalSlider_PHI2AIL->value();    frame_push_uint16_t(Data, 0, tmpI);
            tmpI = ui->horizontalSlider_VY2AIL->value();     frame_push_uint16_t(Data, 2, tmpI);
            tmpS = ui->lineEdit_AILMIN->text();
            tmpF = tmpS.toFloat();                           frame_push_float(Data, 4, tmpF);
            tmpS = ui->lineEdit_AILMAX->text();
            tmpF = tmpS.toFloat();                           frame_push_float(Data, 8, tmpF);
            
            emit signal_cmdOutput(1, UAV_COMP_ID_CTRLCHANNAL, UAV_GNC_AUTO_AILSET, Data, 12);
            break;
        case  3: //pushButton_AUTO_AILASK
            emit signal_cmdOutput(1, UAV_COMP_ID_CTRLCHANNAL, UAV_GNC_AUTO_AILASK, Data, 0); 
            break;
        case  4: //pushButton_AUTO_RUDSET                                                         
            tmpI = ui->horizontalSlider_AUTO_RUD->value();   frame_push_uint16_t(Data, 0, tmpI);
            tmpS = ui->lineEdit_RUDMIN->text();
            tmpF = tmpS.toFloat();                           frame_push_float(Data, 2, tmpF);
            tmpS = ui->lineEdit_RUDMAX->text();
            tmpF = tmpS.toFloat();                           frame_push_float(Data, 6, tmpF);
            
            emit signal_cmdOutput(1, UAV_COMP_ID_CTRLCHANNAL, UAV_GNC_AUTO_RUDSET, Data, 10);
            break;
        case  5: //pushButton_AUTO_RUDASK
            emit signal_cmdOutput(1, UAV_COMP_ID_CTRLCHANNAL, UAV_GNC_AUTO_RUDASK, Data, 0); 
            break;
        case  6: //pushButton_AUTO_COLSET 
            tmpI = ui->horizontalSlider_AUTO_COL->value();   frame_push_uint16_t(Data, 0, tmpI);
            tmpS = ui->lineEdit_COLMIN->text();
            tmpF = tmpS.toFloat();                           frame_push_float(Data, 2, tmpF);
            tmpS = ui->lineEdit_COLMAX->text();
            tmpF = tmpS.toFloat();                           frame_push_float(Data, 6, tmpF);
            
            emit signal_cmdOutput(1, UAV_COMP_ID_CTRLCHANNAL, UAV_GNC_AUTO_COLSET, Data, 10);
            break;
        case  7: //pushButton_AUTO_COLASK 
            emit signal_cmdOutput(1, UAV_COMP_ID_CTRLCHANNAL, UAV_GNC_AUTO_COLASK, Data, 0); 
            break;    
    }
}

void QSelfflyWidget::echoMessagePacket(datalink_message_t *msg)
{
    quint8 echoMsg;
    quint8 tmpData[12];
    
    switch (msg->msgid) {
	    case UAV_MSG_REQU_ECHO:    
	        echoMsg = msg->payload[0];	        
	        switch (echoMsg) {
                case UAV_GNC_AUTO_ELESET:                                        //auto-parameter
                case UAV_GNC_AUTO_ELEASK:
                    for (int idx=0; idx<12; idx++) tmpData[idx] = msg->payload[idx+1];
                    autoCmdEchoOk(1, tmpData);
                    break;
                case UAV_GNC_AUTO_AILSET:
                case UAV_GNC_AUTO_AILASK:
                    for (int idx=0; idx<12; idx++) tmpData[idx] = msg->payload[idx+1];
                    autoCmdEchoOk(2, tmpData);
                    break;
                case UAV_GNC_AUTO_RUDSET:
                case UAV_GNC_AUTO_RUDASK:
                    for (int idx=0; idx<10; idx++) tmpData[idx] = msg->payload[idx+1];
                    autoCmdEchoOk(3, tmpData);
                    break;
                case UAV_GNC_AUTO_COLSET:
                case UAV_GNC_AUTO_COLASK:
                    for (int idx=0; idx<10; idx++) tmpData[idx] = msg->payload[idx+1];
                    autoCmdEchoOk(4, tmpData);
                    break;
                case UAV_GNC_AUTO_FBLSET:
                case UAV_GNC_AUTO_FBLASK:
                  //cfg_autoCtrl.Sen_eleFlybar=frame_return_uint16_t(msg->payload,1);
                  //cfg_autoCtrl.Sen_ailFlybar=frame_return_uint16_t(msg->payload,3);
                    break;
	            default:  break;    
	        }
	        break;
        default: break;
	}
}

void QSelfflyWidget::autoCmdEchoOk(quint8 x, quint8 *data)
{
    QString tmpS;
    float   tmpF;
    int     tmpI;

    switch (x) {
        case 1:
            tmpI = frame_return_uint16_t(data, 0); ui->horizontalSlider_THETA2ELE->setValue(tmpI);
            tmpI = frame_return_uint16_t(data, 2); ui->horizontalSlider_VX2ELE->setValue(tmpI);
            tmpF = frame_return_float(data,4);    ui->lineEdit_ELEMIN->setText(QString::number(tmpF,'g',5));
            tmpF = frame_return_float(data,8);    ui->lineEdit_ELEMAX->setText(QString::number(tmpF,'g',5));
            break;
        case 2:
            tmpI = frame_return_uint16_t(data, 0); ui->horizontalSlider_PHI2AIL->setValue(tmpI);
            tmpI = frame_return_uint16_t(data, 2); ui->horizontalSlider_VY2AIL->setValue(tmpI);
            tmpF = frame_return_float(data,4);    ui->lineEdit_AILMIN->setText(QString::number(tmpF,'g',5));
            tmpF = frame_return_float(data,8);    ui->lineEdit_AILMAX->setText(QString::number(tmpF,'g',5));
            break;
        case 3:
            tmpI = frame_return_uint16_t(data, 0); ui->horizontalSlider_AUTO_RUD->setValue(tmpI);
            tmpF = frame_return_float(data,2);    ui->lineEdit_RUDMIN->setText(QString::number(tmpF,'g',5));
            tmpF = frame_return_float(data,6);    ui->lineEdit_RUDMAX->setText(QString::number(tmpF,'g',5));
            break;
        case 4:
            tmpI = frame_return_uint16_t(data, 0); ui->horizontalSlider_AUTO_COL->setValue(tmpI);
            tmpF = frame_return_float(data,2);    ui->lineEdit_COLMIN->setText(QString::number(tmpF,'g',5));
            tmpF = frame_return_float(data,6);    ui->lineEdit_COLMAX->setText(QString::number(tmpF,'g',5));
            break;
    }
}
