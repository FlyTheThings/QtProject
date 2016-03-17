#ifndef QSPEEDMIXWIDGET_H
#define QSPEEDMIXWIDGET_H

#include <QDialog>
#include <QButtonGroup>
#include "Shared/buff.h"

namespace Ui {
    class QSpeedCmdDialog;
}

class QSpeedCmdDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QSpeedCmdDialog(QWidget *parent = 0);
    ~QSpeedCmdDialog();
    
signals:
    void signal_sendSpeedCmd(int count, quint8 *cmdData, quint8 dataLen); 
        
private slots:
    void slot_clickedSendCmd(int i);
        
private:
    Ui::QSpeedCmdDialog *ui;
        
    QButtonGroup *bGroup;
        
};

#endif // QSPEEDMIXWIDGET_H
