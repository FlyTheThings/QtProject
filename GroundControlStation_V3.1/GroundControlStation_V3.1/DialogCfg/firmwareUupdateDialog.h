#ifndef FIRMWAREUUPDATEDIALOG_H
#define FIRMWAREUUPDATEDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include "shared/buff.h"
#include "Shared/messageIDDefine.h"

namespace Ui {
class QFirmwareUpdateDialog;
}

class QFirmwareUpdateDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QFirmwareUpdateDialog(QWidget *parent = 0);
    ~QFirmwareUpdateDialog();

signals:
    void signal_cmdOutput(quint8 sysid,quint8 compid, quint8 msgid, const quint8 *packet, quint8 length);

private slots:
    void slot_openFile();
    void slot_enableUpdate();
    void slot_startUpdate();     
    void slot_IAPCmdEchoOk(quint8 x, quint8 *data, quint8 len);

private:
    bool ComparePacket(quint8 *src, quint8 *dest, quint8 len);
    
private:
    Ui::QFirmwareUpdateDialog *ui;
        
    QFile   *m_pFile;   
    QString  fileName;   
    
    quint32  image_size;
    quint32  updated_size;
    quint32  packet_serial; 
    quint8   upData_cur[DATALINK_MAX_PAYLOAD_LEN], upDataLen_cur; 
};

#endif // FIRMWAREUUPDATEDIALOG_H
