#ifndef _DATAFRAME_H
#define _DATAFRAME_H

#include <QWidget>       
#include <QFont>  
#include <QDateTime>     //tmp for test!
#include "Shared/dataProtocol.h"

namespace Ui {
    class QPanelDataFrameWidget;
}

class QPanelDataFrameWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QPanelDataFrameWidget(QWidget *parent = 0);
    ~QPanelDataFrameWidget();

    void setSerialProtocol(QDataProtocol *comProtocol);
    void updatePageDisplay();

public slots:
    void slot_sim(float *addr, quint8 length);

private:
    Ui::QPanelDataFrameWidget *ui; 
        
    QDataProtocol  *dProtocol,*Protocol;
    
    void initTableWidget1();     
    void initTableWidget2();
    void initTableWidget3();

    void DataPage1Display();
    void DataPage2Display();      
    void DataPage3Display(); 
};

#endif // DATAFRAME_H
