#include "firmwareUupdateDialog.h"
#include "ui_firmwareUupdateDialog.h"

QFirmwareUpdateDialog::QFirmwareUpdateDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QFirmwareUpdateDialog)
{
    ui->setupUi(this);
    ui->lineEdit->setText("None");
    ui->pushButton->setDisabled(false);
    ui->pushButton_2->setDisabled(false);
    ui->progressBar->setRange(0,100);
    ui->progressBar->setValue(0);
    ui->label->setText("Nan");
    
    m_pFile = new QFile(this);
    
    connect(ui->pushButton,  SIGNAL(clicked()), this, SLOT(slot_openFile()));
    connect(ui->pushButton_2,SIGNAL(clicked()), this, SLOT(slot_startUpdate()));
    connect(ui->pushButton_3,SIGNAL(clicked()), this, SLOT(slot_enableUpdate()));        
}

QFirmwareUpdateDialog::~QFirmwareUpdateDialog()
{
    delete ui;
    if (m_pFile) delete m_pFile;
}

void QFirmwareUpdateDialog::slot_openFile()
{
    fileName = QFileDialog::getOpenFileName(
                                    this,
                                    "打开固件升级文件",
                                    QDir::currentPath(),
                                    "bin files (*.bin);;All files(*.*)");

    if (!fileName.isNull()) {  
        ui->lineEdit->setText(fileName);
        ui->pushButton_2->setDisabled(false);
    }
    else {
        ui->lineEdit->setText("None");
        ui->pushButton_2->setDisabled(true);
        QMessageBox::critical(this,tr("错误"),tr("文件打开失败！"));
    }
}

void QFirmwareUpdateDialog::slot_enableUpdate()
{
    quint8  payload[1];        
    emit signal_cmdOutput(1, UAV_COMP_ID_IAP, UAV_MSG_IAP_ENABLE, payload, 0);
}

void QFirmwareUpdateDialog::slot_startUpdate()
{
    quint8  upData[4];
    
    if (fileName.isEmpty()) {
        QMessageBox::critical(this,tr("error"),tr("请选择固件!"));
        return;
    }
    else    m_pFile->setFileName(fileName);

    if (m_pFile->open(QIODevice::ReadOnly)) { 
        image_size   = m_pFile->size();
        updated_size = 0;
        packet_serial= 0;
        
        frame_push_uint32_t(upData,0,image_size);
        emit signal_cmdOutput(1, UAV_COMP_ID_IAP, UAV_MSG_IAP_START, upData, 4);        
    }
    else {
        QMessageBox::critical(this,tr("error"),tr("File error!"));
        return;
    }
}

void QFirmwareUpdateDialog::slot_IAPCmdEchoOk(quint8 x, quint8 *data, quint8 len)
{
    quint32 tmpI;
    quint8  byteread=0, payload[DATALINK_MAX_PAYLOAD_LEN];

    switch (x) {        
        case 1:  //echo enable!
            ui->label->setText(tr("准备固件升级..."));
            break;        
        case 2:  //echo start! 
            updated_size = 0;
            packet_serial= 0;
            
            byteread = ((image_size-updated_size)>DATALINK_MAX_PAYLOAD_LEN-4-1) ? DATALINK_MAX_PAYLOAD_LEN-4-1:(image_size-updated_size);
            frame_push_uint32_t(upData_cur, 0, packet_serial);    //包序列
            
            m_pFile->seek(updated_size);
            m_pFile->read((char *)&upData_cur[4], byteread);      //包数据
            
            upDataLen_cur = byteread + 4;
            emit signal_cmdOutput(1, UAV_COMP_ID_IAP, UAV_MSG_IAP_UPLOAD, upData_cur, upDataLen_cur);
            
            ui->progressBar->setValue(updated_size*100/image_size);
            ui->label->setText(QString::number(updated_size)+"/"+QString::number(image_size));                
            break; 
        case 3:  //echo upload!  
            memcpy(payload, data, len);
            tmpI = frame_return_uint32_t(data,0);
            
            if ((ComparePacket(upData_cur,payload,upDataLen_cur)==true)||(tmpI==packet_serial)) {                
                packet_serial++;
                updated_size = updated_size + (upDataLen_cur - 4);
                if (updated_size==image_size) {
                    upDataLen_cur=0;
                    emit signal_cmdOutput(1, UAV_COMP_ID_IAP, UAV_MSG_IAP_FINISHED, upData_cur, upDataLen_cur);        
                }
                else {
                    byteread = ((image_size-updated_size)>DATALINK_MAX_PAYLOAD_LEN-4-1) ? DATALINK_MAX_PAYLOAD_LEN-4-1:(image_size-updated_size);
                    frame_push_uint32_t(upData_cur, 0, packet_serial);    //包序列
                    
                    m_pFile->seek(updated_size);
                    m_pFile->read((char *)&upData_cur[4], byteread);      //包数据
                    
                    upDataLen_cur = byteread + 4;
                    emit signal_cmdOutput(1, UAV_COMP_ID_IAP, UAV_MSG_IAP_UPLOAD, upData_cur, upDataLen_cur);
                }
                
                ui->progressBar->setValue(updated_size*100/image_size);
                ui->label->setText(QString::number(updated_size)+"/"+QString::number(image_size));
            }
            break;        
        case 4:  //echo finished!              
            ui->progressBar->setValue(updated_size*100/image_size);
            ui->label->setText(QString::number(updated_size)+"/"+QString::number(image_size));
            
            memcpy(payload, data, len);
            tmpI = frame_return_uint32_t(data,0);
            if (tmpI==image_size) {
                QMessageBox::information(this,tr("固件升级"),tr("升级成功，请重启飞控计算机"),QMessageBox::Ok); 
            } 
            else {
                QMessageBox::critical(this, tr("Critical Error"), QString("升级错误:")+QString::number(image_size)+QString("/")+QString::number(tmpI));
            }  

            break;      
    }
}    

bool QFirmwareUpdateDialog::ComparePacket(quint8 *src, quint8 *dest, quint8 len)
{
    unsigned int idx=0;

    for(idx=0;idx<len;idx++)
        if(*(src+idx)!=*(dest+idx)) return false;

    return true;
}                                                                                                                                 
