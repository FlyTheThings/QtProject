#ifndef QWPMIXWIDGET_H
#define QWPMIXWIDGET_H

#include <QDialog>
#include "Shared/buff.h"

namespace Ui {
    class QWaypointCmdDialog;
}

class QWaypointCmdDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QWaypointCmdDialog(QWidget *parent = 0);
    ~QWaypointCmdDialog();
    
signals:
    void signal_sendWaypointCmd(int count, quint8 *cmdData, quint8 dataLen);

private slots:
    void slot_clickedSendCmd();

private:
    Ui::QWaypointCmdDialog *ui;
};

#endif // QWPMIXWIDGET_H
