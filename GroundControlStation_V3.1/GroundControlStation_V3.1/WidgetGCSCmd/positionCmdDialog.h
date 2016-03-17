#ifndef QPOSITIONMIXWIDGET_H
#define QPOSITIONMIXWIDGET_H

#include <QDialog>
#include <QButtonGroup>
#include "Shared/buff.h"

namespace Ui {
    class QPositionCmdDialog;
}

class QPositionCmdDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QPositionCmdDialog(QWidget *parent = 0);
    ~QPositionCmdDialog();
    
signals:
    void signal_sendPositionCmd(int count, quint8 *cmdData, quint8 dataLen);
        
private slots:
    void slot_clickedSendCmd(int i);
    
private:
    Ui::QPositionCmdDialog *ui;
        
    QButtonGroup *bGroup;    
};

#endif // QPOSITIONMIXWIDGET_H
