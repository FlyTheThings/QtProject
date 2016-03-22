#ifndef TOTALDIALOG_H
#define TOTALDIALOG_H

#include <QWidget>
#include <QPixmap>
#include <QMap>
#include <QMessageBox>
#include "Shared/dataStructureDefine.H"

namespace Ui {
    class QMultiUASForm;
}

class QMultiUASForm : public QWidget
{
    Q_OBJECT

public:
    explicit QMultiUASForm(const QString type, const QString name, quint8 sysid, QWidget *parent = 0);
    ~QMultiUASForm();
    
    void updateUASHeartbeat(heartbeat_Struc_t  *data);
     void set_buttonstate(bool state);
    
    QString  uas_Name, uas_Type;

signals:
    void signal_uavActivedButton(quint8 sysid);
        
protected slots:
    void slot_buttonSelected();

private:
    Ui::QMultiUASForm *ui;
        
    quint8   uas_sysID;
    QMap<quint8, QString>  mapCtrlMode,
                           mapPlaneMode,  
                           mapVertMode,  
                           mapGuidMode;         
    bool           active_state;
    void initTableWidget1();
    void initTableWidget2();
    void initTableWidget3(); 
    void initMapData();      
};

#endif // TOTALDIALOG_H
