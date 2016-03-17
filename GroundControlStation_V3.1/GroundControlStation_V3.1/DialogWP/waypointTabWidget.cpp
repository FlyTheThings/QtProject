#include "waypointTabWidget.h"
#include "ui_waypointTabWidget.h"
#include "qheaderview.h"

QWaypointTabWidget::QWaypointTabWidget(QWidget *parent) :
    QTabWidget(parent),
    ui(new Ui::QWaypointTabWidget)
{
    ui->setupUi(this);
    
    initTableWidget1();                              //Tab1
    connect(ui->pushButton,  SIGNAL(clicked()), this,SLOT(slot_openFile()));
    connect(ui->pushButton_2,SIGNAL(clicked()), this,SLOT(slot_deleteFile()));
    connect(ui->pushButton_3,SIGNAL(clicked()), this,SLOT(slot_saveFile()));    
    //connect(ui->pushButton_4,SIGNAL(clicked()), this,SLOT(slot_OnDrawWP()));
   // connect(ui->tableWidget,SIGNAL(cellChanged(int,int)),this,SLOT(slot_OnDrawWP(int,int)));
    connect(ui->pushButton_5,SIGNAL(clicked()), this,SLOT(slot_cmdCheckFCCWP()));
    connect(ui->pushButton_6,SIGNAL(clicked()), this,SLOT(slot_cmdUploadFCCWP()));
    connect(ui->pushButton_7,SIGNAL(clicked()), this,SLOT(slot_cmdDeleteFCCWP()));
    cmdID = 0;
    cmdTimer = new QTimer(this); 
    connect(cmdTimer,SIGNAL(timeout()), this,SLOT(slot_waypointcmdEchoOverTimer()));
    
    initTableWidget2();                              //Tab2
    connect(ui->pushButton_10,SIGNAL(clicked()), this,SLOT(slot_addDotWaypoint()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this,SLOT(slot_modifyDotWaypoint()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this,SLOT(slot_delDotWaypoint()));    
    connect(ui->pushButton_11,SIGNAL(clicked()), this,SLOT(slot_refreshWaypoint()));
    connect(ui->pushButton_12,SIGNAL(clicked()), this,SLOT(slot_deleteWaypoint()));
    connect(ui->pushButton_13,SIGNAL(clicked()), this,SLOT(slot_saveWaypoint()));

    initTableWidget3();                              //Tab3
//  connect(newAirline, SIGNAL(triggered()), this,SLOT(slot_newAirline()));
    row_current=-1;
    connect(ui->pushButton_deletee,SIGNAL(clicked()),this,SLOT(slot_deletePoint_table1()));
    connect(ui->tableWidget,SIGNAL(itemClicked(QTableWidgetItem*)),this,SLOT(slot_showcurrentpoint(QTableWidgetItem*)));
    connect(ui->pushButton_addpoint,SIGNAL(clicked()),SLOT(slot_findpostion()));
    connect(ui->pushButton_getpoint,SIGNAL(clicked()),SIGNAL(signal_picklonlat()));
}

QWaypointTabWidget::~QWaypointTabWidget()
{
    delete ui;    
    if (cmdTimer)  delete cmdTimer;
}

void QWaypointTabWidget::initTableWidget1()
{ 
    curFileName = "";
    numDot_tab1 = 0;    curDot_tab1 = 0;
    ui->lineEdit->setText("None");
    ui->lineEdit_2->setText(QString::number(curDot_tab1));
    ui->spinBox_6->setValue(0);
    
    ui->tableWidget->clear();
    ui->tableWidget->setMinimumSize(300,120);
    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->horizontalHeader()->setVisible(true);
    
    ui->tableWidget->setColumnCount(9);
    QStringList header;
    header<<"L."<<"Dot"<<"Lon"<<"Lat"<<"Alt"<<"SP1"<<"SP2"<<"SP3"<<"SP4";
    ui->tableWidget->setHorizontalHeaderLabels(header);

    ui->tableWidget->setColumnCount(9);
    ui->tableWidget->setColumnWidth(0,25);
    ui->tableWidget->setColumnWidth(1,35);
    ui->tableWidget->setColumnWidth(2,80);
    ui->tableWidget->setColumnWidth(3,80);
    ui->tableWidget->setColumnWidth(4,50);
    ui->tableWidget->setColumnWidth(5,35);
    ui->tableWidget->setColumnWidth(6,35);
    ui->tableWidget->setColumnWidth(7,35);
    ui->tableWidget->setColumnWidth(8,35);
    setFont(QFont("Times", 9, QFont::Normal));
    ui->tableWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
    ui->tableWidget->setShowGrid(true);

    ui->tableWidget->setSelectionBehavior (QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode (QAbstractItemView::SingleSelection);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
}

void QWaypointTabWidget::slot_openFile()
{
    int num=0; 
    QString  line;
    QFile   *m_pFileData;
    
    QString filename = QFileDialog::getOpenFileName(
                                    this,
                                    "打开航线文件",
                                    QDir::currentPath(),
                                    "txt files (*.txt);;All files(*.*)");
    if (filename==curFileName) return;
    
    if (!filename.isNull()) {  
        m_pFileData = new QFile(this);  
        m_pFileData->setFileName(filename);
        
        if (m_pFileData->open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(m_pFileData);
            
            curFileName = filename;
            while (!in.atEnd()) {
                line = in.readLine();
                
                if (!line.isEmpty()) {
                    processWaypointData(line, num);
                    num++;
                }
            }

            if (numDot_tab1>0) {
                ui->lineEdit->setText("本地航线");
                ui->lineEdit_2->setText(QString::number(numDot_tab1));
                
                QStringList fields = line.split(',');
                QString     text = fields.takeAt(0);
                ui->spinBox_6->setValue(text.toInt());
            }
        }
        else {
            QMessageBox::critical(this,tr("error"),tr("File error!"));
            return;
        }
        
        m_pFileData->close();
        if (m_pFileData) delete m_pFileData;
    }
    else QMessageBox::critical(this,tr("错误"),tr("文件打开失败！"));
}

void QWaypointTabWidget::slot_deleteFile()
{
    if (numDot_tab1<=0) return;
    int a=ui->tableWidget->rowCount();
    for(int i=0;i<a;i++){

        ui->tableWidget->removeRow(0);
    }
    curFileName = "";    
    numDot_tab1 = 0;    curDot_tab1 = 0;
    
    ui->lineEdit->setText("None");
    ui->lineEdit_2->setText(QString::number(numDot_tab1));
    ui->spinBox_6->setValue(0);
    
    emit signal_cmdOnDelWP(); 
    emit signal_cmdOnDrawWP();
}

void QWaypointTabWidget::slot_saveFile()
{
    if (numDot_tab1<=0) return;
        
    QFile   *m_pFileSave;
    QTableWidgetItem *newItem;    
    QString  sField[9];        
    QString fileName = QFileDialog::getSaveFileName(
                                    this,
                                    "航线文件另存",
                                    QDir::currentPath(),
                                    "txt files (*.txt)");
    m_pFileSave = new QFile(this);
    if (!fileName.isNull()) {        
        m_pFileSave->setFileName(fileName);
        if (m_pFileSave->open(QIODevice::WriteOnly | QIODevice::Text)==false) {
            QMessageBox::critical(this,tr("error"),tr("File error!"));
            return;
        }
    }
    else {
        QMessageBox::critical(this,tr("错误"),tr("文件打开失败！"));
        return;
    }

    QTextStream   out(m_pFileSave);
    for (int row=0; row<numDot_tab1; row++) {
        for (int col=0; col<9; col++) {
            newItem = ui->tableWidget->item(row, col);
            sField[col] = newItem->text();
            
            out<<sField[col];
            if (col<8) out<<",";
        }
        out<<"\n";
    }

    m_pFileSave->close();
    if (m_pFileSave) delete m_pFileSave;
}

void QWaypointTabWidget::processWaypointData(QString dotData, int num)
{
    QTableWidgetItem *newItem[9];
    QStringList fields = dotData.split(',');

    if (num==0) {
       slot_deleteFile();
        //for (int idx=1; idx<=numDot_tab1; idx++)
           // ui->tableWidget->removeRow(0);
    }
    ui->tableWidget->insertRow(num);
    ui->tableWidget->setRowHeight(num,20);

    numDot_tab1 = num + 1;

    if (fields.size()==9) {        
        for (int i=0; i<9; ++i) {
            newItem[i] = new QTableWidgetItem;
            newItem[i]->setFont(QFont("Times", 8, QFont::Bold));
            //newItem[i]->setBackgroundColor(Qt::cyan);
            
            QString textItem = fields.takeAt(0);
            newItem[i]->setText(textItem);    ui->tableWidget->setItem(num, i, newItem[i]);

        }        
    }
    else {
        for (int i=0; i<9; ++i) {
            newItem[i] = new QTableWidgetItem;
            newItem[i]->setFont(QFont("Times", 8, QFont::Bold));
            newItem[i]->setBackgroundColor(Qt::red);
            
            newItem[i]->setText("Error");    ui->tableWidget->setItem(num, i, newItem[i]);
        }   
    }
   slot_OnDrawWP();
}      

void QWaypointTabWidget::slot_OnDrawWP()
{
    QTableWidgetItem *newItem;    
    QString  sField[2];
    QPointF lonLat;
    int num=1;
    
    numDot_tab1 = 0;
    newItem = ui->tableWidget->item(num-1, 1);

    while (newItem) {
        newItem = ui->tableWidget->item(num-1, 2);
        sField[0] = newItem->text();
        newItem = ui->tableWidget->item(num-1, 3);
        sField[1] = newItem->text();

        lonLat.setX(sField[0].toDouble());
        lonLat.setY(sField[1].toDouble());
        mDataPF[num] = lonLat;
        numDot_tab1 = num;        
        
        num++;
        newItem = ui->tableWidget->item(num-1, 1);
    }

    emit signal_cmdOnDrawWP();         
}

void QWaypointTabWidget::slot_cmdCheckFCCWP()
{
    int temp;
    int wpNum = ui->spinBox_6->value();
    if (wpNum<=0) { 
        QMessageBox::critical(this,tr("错误"),tr("请选择查询航线号[1-4]！"));
        return;
    }
    temp = numDot_tab1;
    slot_deleteFile();                    //清除当前数据    
    numDot_tab1 = temp;
    ui->pushButton_5->setEnabled(false);  
    quint8  wpData[2];                    //启动查询,请求第一个航点
    wpData[0]=wpNum;  wpData[1]=1;   
    curDot_tab1=1;    cmdID = 2;     cmdTimer->start(1800);
    emit signal_cmdOutput(1, UAV_COMP_ID_WAYPOINT, UAV_MSG_WP_ASK, wpData, 2); 
}

void QWaypointTabWidget::slot_cmdUploadFCCWP()
{
    if (numDot_tab1<=1) {
        QMessageBox::critical(this,tr("错误"),tr("显示区没有航线数据！"));
        return;
    }
    int wpNum = ui->spinBox_6->value();
    if (wpNum<=0) { 
        QMessageBox::critical(this,tr("错误"),tr("请选择注入航线号！"));
        return;
    }    
    
    QTableWidgetItem *newItem;    
    QString           sField;
    quint8            wpData[26];
    float             tmpF;
    double            tmpD;
        
    curDot_tab1=1;
    newItem = ui->tableWidget->item(curDot_tab1-1, 0);    sField = newItem->text();
    frame_push_uint8_t(wpData, 0, (quint8)sField.toUInt());
    newItem = ui->tableWidget->item(curDot_tab1-1, 1);    sField = newItem->text();
    frame_push_uint8_t(wpData, 1, (quint8)sField.toUInt());
    newItem = ui->tableWidget->item(curDot_tab1-1, 2);    sField = newItem->text();  tmpD = sField.toDouble();
    frame_push_double(wpData, 2, tmpD);
    newItem = ui->tableWidget->item(curDot_tab1-1, 3);    sField = newItem->text();  tmpD = sField.toDouble();
    frame_push_double(wpData, 10, tmpD);
    newItem = ui->tableWidget->item(curDot_tab1-1, 4);    sField = newItem->text();  tmpF = sField.toFloat();
    frame_push_float(wpData,18, tmpF);
    newItem = ui->tableWidget->item(curDot_tab1-1, 5);    sField = newItem->text();
    frame_push_uint8_t(wpData,22, (quint8)sField.toUInt());
    newItem = ui->tableWidget->item(curDot_tab1-1, 6);    sField = newItem->text();
    frame_push_uint8_t(wpData,23, (quint8)sField.toUInt());
    newItem = ui->tableWidget->item(curDot_tab1-1, 7);    sField = newItem->text();
    frame_push_uint8_t(wpData,24, (quint8)sField.toUInt());
    newItem = ui->tableWidget->item(curDot_tab1-1, 8);    sField = newItem->text();
    frame_push_uint8_t(wpData,25, (quint8)sField.toUInt());
    
    ui->pushButton_6->setEnabled(false);   
    cmdID = 1;     cmdTimer->start(1800);  
    emit signal_cmdOutput(1, UAV_COMP_ID_WAYPOINT, UAV_MSG_WP_SET, wpData, 26);
}

void QWaypointTabWidget::slot_cmdDeleteFCCWP()
{
    int wpNum = ui->spinBox_6->value();
    if (wpNum<=0) { 
        QMessageBox::critical(this,tr("错误"),tr("请选择要删除的航线号[1-4]！"));
        return;
    }
    
    slot_deleteFile();                    //清除当前数据 
    ui->pushButton_7->setEnabled(false);
    
    quint8  wpData[1]; 
    wpData[0]=wpNum; 
    cmdID = 3;     cmdTimer->start(1800);
    emit signal_cmdOutput(1, UAV_COMP_ID_WAYPOINT, UAV_MSG_WP_DEL, wpData, 1); 
}

void QWaypointTabWidget::slot_waypointCmdEchoOK(quint8 idx, WayPoint_Struc_t dataWP)
{
    QTableWidgetItem *newItem,*item[9];
    QString           sField;
    quint8            wpData[26];
    float             tmpF;
    double            tmpD;
    
    switch (idx) {
        case 1: //注入echo
            if (curDot_tab1==dataWP.dot) {
                cmdTimer->stop();                      
                
                for (int i=0; i<9; ++i) {                                //回馈正确,改变已发送成功航点信息颜色
                    newItem = ui->tableWidget->item(curDot_tab1-1, i);
                    newItem->setBackgroundColor(Qt::green);
                }
                                
                if (dataWP.dot==1) {
                    ui->lineEdit->setText("本地航线-注入");
                    ui->spinBox_6->setValue(dataWP.num);
                }    
                ui->lineEdit_2->setText(QString::number(dataWP.dot));                           
                
                if (curDot_tab1<numDot_tab1) {               
                    curDot_tab1 = dataWP.dot+1;
                    newItem = ui->tableWidget->item(curDot_tab1-1, 0);    sField = newItem->text();
                    frame_push_uint8_t(wpData, 0, (quint8)sField.toUInt());
                    newItem = ui->tableWidget->item(curDot_tab1-1, 1);    sField = newItem->text();
                    frame_push_uint8_t(wpData, 1, (quint8)sField.toUInt());
                    newItem = ui->tableWidget->item(curDot_tab1-1, 2);    sField = newItem->text();  tmpD = sField.toDouble();
                    frame_push_double(wpData, 2, tmpD);
                    newItem = ui->tableWidget->item(curDot_tab1-1, 3);    sField = newItem->text();  tmpD = sField.toDouble();
                    frame_push_double(wpData, 10, tmpD);
                    newItem = ui->tableWidget->item(curDot_tab1-1, 4);    sField = newItem->text();  tmpF = sField.toDouble();
                    frame_push_float(wpData,18, tmpF);
                    newItem = ui->tableWidget->item(curDot_tab1-1, 5);    sField = newItem->text();
                    frame_push_uint8_t(wpData,22, (quint8)sField.toUInt());
                    newItem = ui->tableWidget->item(curDot_tab1-1, 6);    sField = newItem->text();
                    frame_push_uint8_t(wpData,23, (quint8)sField.toUInt());
                    newItem = ui->tableWidget->item(curDot_tab1-1, 7);    sField = newItem->text();
                    frame_push_uint8_t(wpData,24, (quint8)sField.toUInt());
                    newItem = ui->tableWidget->item(curDot_tab1-1, 8);    sField = newItem->text();
                    frame_push_uint8_t(wpData,25, (quint8)sField.toUInt());
                    
                    cmdID = 1;     cmdTimer->start(1800);  
                    emit signal_cmdOutput(1, UAV_COMP_ID_WAYPOINT, UAV_MSG_WP_SET, wpData, 26);
                }
                else {
                    cmdID = 0;    cmdTimer->stop();
                    ui->pushButton_6->setEnabled(true);            
                    QMessageBox::critical(this,tr("结束"),tr("航线注入完成...请核实！")); 
                }
            }
            else {
                cmdID = 0;    cmdTimer->stop();
                ui->pushButton_6->setEnabled(true);
                QMessageBox::critical(this,tr("错误"),tr("航线注入回馈错误...中止！"));
            } 
            break;
        case 2: //查询echo
                if (curDot_tab1==dataWP.dot) {
                    cmdTimer->stop();
                    ui->tableWidget->insertRow(curDot_tab1-1);
                    ui->tableWidget->setRowHeight(curDot_tab1-1,20);
                    for( int i = 0;i<9;i++)
                    {
                        item[i] = new QTableWidgetItem;
                        item[i]->setFont(QFont("Times", 8, QFont::Bold));
                        item[i]->setBackgroundColor(Qt::green);
                    }
                    item[0]->setText(QString::number(dataWP.num));       ui->tableWidget->setItem(dataWP.dot-1, 0, item[0]);
                    item[1]->setText(QString::number(dataWP.dot));       ui->tableWidget->setItem(dataWP.dot-1, 1, item[1]);
                    item[2]->setText(QString::number(dataWP.lon,'g',9)); ui->tableWidget->setItem(dataWP.dot-1, 2, item[2]);
                    item[3]->setText(QString::number(dataWP.lat,'g',8)); ui->tableWidget->setItem(dataWP.dot-1, 3, item[3]);
                    item[4]->setText(QString::number(dataWP.alt,'g',5)); ui->tableWidget->setItem(dataWP.dot-1, 4, item[4]);
                    item[5]->setText(QString::number(dataWP.vxd[0]));    ui->tableWidget->setItem(dataWP.dot-1, 5, item[5]);
                    item[6]->setText(QString::number(dataWP.vxd[1]));    ui->tableWidget->setItem(dataWP.dot-1, 6, item[6]);
                    item[7]->setText(QString::number(dataWP.vxd[2]));    ui->tableWidget->setItem(dataWP.dot-1, 7, item[7]);
                    item[8]->setText(QString::number(dataWP.vxd[3]));    ui->tableWidget->setItem(dataWP.dot-1, 8, item[8]);
                
                    if (dataWP.dot==1) {
                        ui->lineEdit->setText("机载航线-查询");
                        ui->spinBox_6->setValue(dataWP.num);
                    }
                    ui->lineEdit_2->setText(QString::number(dataWP.dot));
                 
                    wpData[0]=dataWP.num;   wpData[1]=dataWP.dot+1;
                    curDot_tab1=wpData[1];  cmdID = 2;   cmdTimer->start(1800);
                    emit signal_cmdOutput(1, UAV_COMP_ID_WAYPOINT, UAV_MSG_WP_ASK, wpData, 2);
                }
                else {
                    cmdID = 0;    cmdTimer->stop();
                    ui->pushButton_5->setEnabled(true);
                    QMessageBox::critical(this,tr("错误"),tr("航线查询回馈错误...中止！"));
                }
            break;
        case 3: //删除echo
            cmdID = 0;    cmdTimer->stop();
            ui->pushButton_7->setEnabled(true);
            QMessageBox::critical(this,tr("正确"),tr("航线删除...成功！"));
            break;
    }    
}

void QWaypointTabWidget::slot_waypointcmdEchoOverTimer()
{    
    switch (cmdID) {
        case 1:            
            cmdID = 0;    cmdTimer->stop();
            ui->pushButton_6->setEnabled(true);            
            QMessageBox::critical(this,tr("错误"),tr("航线注入...失败！"));
            break;
        case 2: 
            cmdID = 0;    cmdTimer->stop();
            ui->pushButton_5->setEnabled(true);
            if (curDot_tab1<=1) QMessageBox::critical(this,tr("错误"),tr("航线查询...失败或无数据！"));
            else                QMessageBox::critical(this,tr("结束"),tr("航线查询完成...请核实！"));
            break;
        case 3: 
            cmdID = 0;    cmdTimer->stop();
            ui->pushButton_7->setEnabled(true);
            QMessageBox::critical(this,tr("错误"),tr("航线删除...失败！"));
            break;
    }    
}

void QWaypointTabWidget::setline_lonlat(QString lng,QString lat)
{
    ui->lineEdit_lng->setText(lng);
    ui->lineEdit_lat->setText(lat);
}

void QWaypointTabWidget::slot_showcurrentpoint(QTableWidgetItem * item)
{
    row_current=item->row();
    ui->spinBox_lineway->setValue(ui->tableWidget->item(item->row(),0)->text().toInt());
    ui->spinBox_pointway->setValue(ui->tableWidget->item(item->row(),1)->text().toInt());
    ui->lineEdit_lng->setText(ui->tableWidget->item(item->row(),2)->text());
    ui->lineEdit_lat->setText(ui->tableWidget->item(item->row(),3)->text());
    ui->lineEdit_height->setText(ui->tableWidget->item(item->row(),3)->text());
}

void QWaypointTabWidget::slot_deletePoint_table1()
{
    if(row_current>-1) {
        ui->tableWidget->removeRow(row_current);
        row_current=-1;
    }
    slot_OnDrawWP();
}

void QWaypointTabWidget::slot_findpostion()
{
    int linecount=ui->spinBox_lineway->value();
    int pointcount=ui->spinBox_pointway->value();
    if(linecount<1||pointcount<1)  {
        QMessageBox::critical(this,tr("错误"),tr("请选择合适的航线号[1-4]或航段号！"));
        return;
    }
    int position=-1;
    for(int i=0;i<ui->tableWidget->rowCount();i++){
        if(linecount==ui->tableWidget->item(i,0)->text().toInt()){
            QVector<int>vector_point;
            for(int t=i;t<ui->tableWidget->rowCount();t++){
                int pointexist=ui->tableWidget->item(t,1)->text().toInt();
                int lineexist=ui->tableWidget->item(t,0)->text().toInt();
                if(lineexist==linecount&&!vector_point.contains(pointexist))
                    vector_point.push_back(pointexist);
            }
            for(int t=0;t<vector_point.size();t++){
                if(pointcount==vector_point.at(t)){
                    addDotWaypoint_table_1(i+t);
                    return;
                }
                else if (pointcount>vector_point.at(t))
                    position++;
            }


                ui->tableWidget->insertRow(i+position+1);
                for(int t=0;t<ui->tableWidget->columnCount();t++){
                    QTableWidgetItem *newItem = new QTableWidgetItem(tr("new"));
                    ui->tableWidget->setItem(position+1+i, t, newItem);
                }
                addDotWaypoint_table_1(position+1+i);
                return;


        }

      }
    int row=ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);
    for(int t=0;t<ui->tableWidget->columnCount();t++){
        QTableWidgetItem *newItem = new QTableWidgetItem(tr("new"));
        ui->tableWidget->setItem(row, t, newItem);
    }
   addDotWaypoint_table_1(row);
}

void QWaypointTabWidget:: addDotWaypoint_table_1(int row)
{

    ui->tableWidget->setRowHeight(row,20);
    ui->tableWidget->item(row,0)->setText(QString("%1").arg(ui->spinBox_lineway->value()));
    ui->tableWidget->item(row,1)->setText(QString("%1").arg(ui->spinBox_pointway->value()));
    ui->tableWidget->item(row,2)->setText(ui->lineEdit_lng->text());
    ui->tableWidget->item(row,3)->setText(ui->lineEdit_lat->text());
    ui->tableWidget->item(row,4)->setText(ui->lineEdit_height->text());
    ui->tableWidget->selectRow(row);
    numDot_tab1++;
    slot_OnDrawWP();
}

/* -------------------------------------------- */
/* tab2 */
/* -------------------------------------------- */
void QWaypointTabWidget::initTableWidget2()
{
    ui->tableWidget_2->clear();
    ui->tableWidget_2->setMinimumSize(300,120);
    ui->tableWidget_2->verticalHeader()->setVisible(false);
    ui->tableWidget_2->horizontalHeader()->setVisible(true);
    
    ui->tableWidget_2->setColumnCount(9);
    QStringList header;
    header<<"L."<<"Dot"<<"Lon"<<"Lat"<<"Alt"<<"SP1"<<"SP2"<<"SP3"<<"SP4";
    ui->tableWidget_2->setHorizontalHeaderLabels(header);
    
    ui->tableWidget_2->setColumnCount(9);
    ui->tableWidget_2->setColumnWidth(0,25);
    ui->tableWidget_2->setColumnWidth(1,34);
    ui->tableWidget_2->setColumnWidth(2,75);
    ui->tableWidget_2->setColumnWidth(3,75);
    ui->tableWidget_2->setColumnWidth(4,45);
    ui->tableWidget_2->setColumnWidth(5,34);
    ui->tableWidget_2->setColumnWidth(6,34);
    ui->tableWidget_2->setColumnWidth(7,34);
    ui->tableWidget_2->setColumnWidth(8,34);

    setFont(QFont("Times", 9, QFont::Normal));
    ui->tableWidget_2->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
    ui->tableWidget_2->setShowGrid(true);
}

void QWaypointTabWidget::slot_addDotWaypoint()
{
    int  nRow, iLine, iDot;
    QTableWidgetItem *newItem[9];
    QString eStr, nStr, lStr, pStr, hStr, wpStr[9];
    
    iLine = ui->spinBox->value();
    iDot  = ui->spinBox_2->value();
    if ((iLine==0)||(iDot==0)) {
        QMessageBox::critical(this,tr("错误"),tr("请选择合适的航线号[1-4]或航段号！"));
        return;
    }
    eStr = ui->lineEdit_3->text();  nStr = ui->lineEdit_4->text();
    lStr = ui->lineEdit_7->text();  pStr = ui->lineEdit_6->text();  hStr = ui->lineEdit_5->text();
    if (eStr.isEmpty()||nStr.isEmpty()||lStr.isEmpty()||pStr.isEmpty()||hStr.isEmpty()) {
        QMessageBox::critical(this,tr("错误"),tr("请输入正确的设计参数！"));
        return;
    }
    
    int tRow;
    if (iDot>1) {
        tRow = ui->tableWidget_2->rowCount();        
        if (tRow!=iDot) {
            QMessageBox::critical(this,tr("错误"),tr("请<追加依次>添加航点[暂时不支持插入添加]！"));
            return;
        }
    } 
    else {
        tRow = ui->tableWidget_2->rowCount();
        if (tRow>1) {
            QMessageBox::critical(this,tr("错误"),tr("请<追加依次>添加航点[暂时不支持插入添加]！"));
            return;
        }
    }
            
    quint8  rVxd[4];
    double  AxEN, AyEN;
    double  R_lat, lon, lat;
    int     sp1, sp2;
    QString sp1_Str, sp2_Str;
    #define Rad2Deg 57.2957795130823208767981548141052  
    
    if (iDot==1) {
        nRow = 0;
        ui->tableWidget_2->insertRow(0);    ui->tableWidget_2->setRowHeight(nRow,20);

        wpStr[0] = QString::number(iLine);   wpStr[1] = QString::number(iDot);
        wpStr[2] = eStr;  wpStr[3] = nStr;   wpStr[4] = hStr;
        wpStr[5] = QString::number(0, 16).toUpper();  wpStr[6] = QString::number(0, 16).toUpper();
        wpStr[7] = QString::number(0, 16).toUpper();  wpStr[8] = QString::number(0, 16).toUpper();

        for (int idx=0; idx<9; idx++) {
            newItem[idx] = new QTableWidgetItem;
            newItem[idx]->setFont(QFont("Times", 8, QFont::Bold));
            newItem[idx]->setBackgroundColor(Qt::cyan);
            newItem[idx]->setText(wpStr[idx]);  ui->tableWidget_2->setItem(nRow, idx, newItem[idx]);
        }
   
        nRow = iDot; 
        ui->tableWidget_2->insertRow(nRow);    ui->tableWidget_2->setRowHeight(nRow,20);

        AxEN = lStr.toDouble() * qSin(pStr.toDouble()/Rad2Deg);
        AyEN = lStr.toDouble() * qCos(pStr.toDouble()/Rad2Deg);
        R_lat= 6378165.0*qCos(nStr.toDouble()/Rad2Deg);
        lon = eStr.toDouble() + (AxEN/     R_lat)*Rad2Deg;   ref_lon = lon;
        lat = nStr.toDouble() + (AyEN/6378165.0 )*Rad2Deg;   ref_lat = lat;
        
        sp1 = ui->comboBox->currentIndex()+1; sp1_Str = ui->lineEdit_8->text();
        sp2 = ui->comboBox_2->currentIndex(); sp2_Str = ui->lineEdit_9->text();
        getVxdFromInut(sp1, sp1_Str, sp2, sp2_Str, &rVxd[0]);
        
        wpStr[0] = QString::number(iLine);                  wpStr[1] = QString::number(iDot+1);
        wpStr[2] = QString::number(lon,'g',9);              wpStr[3] = QString::number(lat,'g',9);        wpStr[4] = hStr;
        wpStr[5] = QString::number(rVxd[0], 16).toUpper();  wpStr[6] = QString::number(rVxd[1], 16).toUpper();
        wpStr[7] = QString::number(rVxd[2], 16).toUpper();  wpStr[8] = QString::number(rVxd[3], 16).toUpper();

        for (int idx=0; idx<9; idx++) {
            newItem[idx] = new QTableWidgetItem;
            newItem[idx]->setFont(QFont("Times", 8, QFont::Bold));
            newItem[idx]->setBackgroundColor(Qt::cyan);
            newItem[idx]->setText(wpStr[idx]);  ui->tableWidget_2->setItem(nRow, idx, newItem[idx]);
        }

        ui->spinBox_2->setValue(iDot+1);
    }
    else {
        nRow = iDot; 
        ui->tableWidget_2->insertRow(nRow);    ui->tableWidget_2->setRowHeight(nRow,20);        

        AxEN = lStr.toDouble() * qSin(pStr.toDouble()/Rad2Deg);
        AyEN = lStr.toDouble() * qCos(pStr.toDouble()/Rad2Deg);
        R_lat= 6378165.0*qCos(nStr.toDouble()/Rad2Deg);
        lon = ref_lon + (AxEN/     R_lat)*Rad2Deg;     ref_lon = lon; 
        lat = ref_lat + (AyEN/6378165.0 )*Rad2Deg;     ref_lat = lat; 
        
        sp1 = ui->comboBox->currentIndex()+1; sp1_Str = ui->lineEdit_8->text();
        sp2 = ui->comboBox_2->currentIndex(); sp2_Str = ui->lineEdit_9->text();
        getVxdFromInut(sp1, sp1_Str, sp2, sp2_Str, &rVxd[0]);
        
        wpStr[0] = QString::number(iLine);                  wpStr[1] = QString::number(iDot+1);
        wpStr[2] = QString::number(lon,'g',9);              wpStr[3] = QString::number(lat,'g',9);        wpStr[4] = hStr;
        wpStr[5] = QString::number(rVxd[0], 16).toUpper();  wpStr[6] = QString::number(rVxd[1], 16).toUpper();
        wpStr[7] = QString::number(rVxd[2], 16).toUpper();  wpStr[8] = QString::number(rVxd[3], 16).toUpper();
     
        for (int idx=0; idx<9; idx++) {
            newItem[idx] = new QTableWidgetItem;
            newItem[idx]->setFont(QFont("Times", 8, QFont::Bold));
            newItem[idx]->setBackgroundColor(Qt::cyan);
            newItem[idx]->setText(wpStr[idx]);  ui->tableWidget_2->setItem(nRow, idx, newItem[idx]);
        }

        ui->spinBox_2->setValue(iDot+1);
    }
}    
    
void QWaypointTabWidget::slot_modifyDotWaypoint()
{
    int  iLine, iDot;
    QTableWidgetItem *Item;
    QString eStr, nStr, lStr, pStr, hStr, wpStr[9];
    
    iDot  = ui->spinBox_2->value();
    if (iDot<2) {
        QMessageBox::critical(this,tr("错误"),tr("请选择合适的航点号[>2]！"));
        return;
    }
    
    QString  sFieldLine;
    Item = new QTableWidgetItem;
    Item = ui->tableWidget_2->item(iDot-1, 0);
    if (Item==0) {
        QMessageBox::critical(this,tr("错误"),tr("航点编号不存在！"));
        return;
    }
    sFieldLine= Item->text();    
    iLine = ui->spinBox->value();
    if (sFieldLine.toInt()!=iLine) {
        QMessageBox::critical(this,tr("错误"),tr("航段编号不匹配！"));
        return;
    }

    Item = ui->tableWidget_2->item(iDot-1, 1);
    sFieldLine= Item->text();   
    if (iDot!=sFieldLine.toInt()) {
        QMessageBox::critical(this,tr("错误"),tr("航点编号不匹配或不存在！"));
        return;
    }
          
    eStr = ui->lineEdit_3->text();  nStr = ui->lineEdit_4->text();
    lStr = ui->lineEdit_7->text();  pStr = ui->lineEdit_6->text();  hStr = ui->lineEdit_5->text();
    if (eStr.isEmpty()||nStr.isEmpty()||lStr.isEmpty()||pStr.isEmpty()||hStr.isEmpty()) {
        QMessageBox::critical(this,tr("错误"),tr("请输入正确的设计参数！"));
        return;
    }
    
    quint8  rVxd[4];
    double  AxEN, AyEN;
    double  R_lat, lon, lat, baseLon, baseLat;
    int     sp1, sp2;
    QString sp1_Str, sp2_Str;
    #define Rad2Deg 57.2957795130823208767981548141052  
    
    Item = ui->tableWidget_2->item(iDot-2, 2);    sFieldLine= Item->text();
    baseLon = sFieldLine.toDouble();
    Item = ui->tableWidget_2->item(iDot-2, 3);    sFieldLine= Item->text();
    baseLat = sFieldLine.toDouble();

    AxEN = lStr.toDouble() * qSin(pStr.toDouble()/Rad2Deg);
    AyEN = lStr.toDouble() * qCos(pStr.toDouble()/Rad2Deg);
    R_lat= 6378165.0*qCos(nStr.toDouble()/Rad2Deg);
    lon = baseLon + (AxEN/     R_lat)*Rad2Deg;
    lat = baseLat + (AyEN/6378165.0 )*Rad2Deg;

    sp1 = ui->comboBox->currentIndex()+1; sp1_Str = ui->lineEdit_8->text();
    sp2 = ui->comboBox_2->currentIndex(); sp2_Str = ui->lineEdit_9->text();
    getVxdFromInut(sp1, sp1_Str, sp2, sp2_Str, &rVxd[0]);

    wpStr[0] = QString::number(iLine);                  wpStr[1] = QString::number(iDot);
    wpStr[2] = QString::number(lon,'g',9);              wpStr[3] = QString::number(lat,'g',9);        wpStr[4] = hStr;
    wpStr[5] = QString::number(rVxd[0], 16).toUpper();  wpStr[6] = QString::number(rVxd[1], 16).toUpper();
    wpStr[7] = QString::number(rVxd[2], 16).toUpper();  wpStr[8] = QString::number(rVxd[3], 16).toUpper();
    
    QTableWidgetItem *newItem[9];
    for (int idx=0; idx<9; idx++) {
        newItem[idx] = new QTableWidgetItem;
        newItem[idx]->setFont(QFont("Times", 8, QFont::Bold));
        newItem[idx]->setBackgroundColor(Qt::cyan);
        newItem[idx]->setText(wpStr[idx]);  ui->tableWidget_2->setItem(iDot-1, idx, newItem[idx]);
    }
}    

void QWaypointTabWidget::slot_delDotWaypoint()
{
    int  iLine, iDot;
    QTableWidgetItem *Item;
    
    iDot  = ui->spinBox_2->value();
    if (iDot<1) {
        QMessageBox::critical(this,tr("错误"),tr("请选择合适的航点号[>1]！"));
        return;
    }
    
    QString  sFieldLine;
    Item = new QTableWidgetItem;
    Item = ui->tableWidget_2->item(iDot-1, 1);
    if (Item==0) {
        QMessageBox::critical(this,tr("错误"),tr("航点编号不存在！"));
        return;
    } 
    sFieldLine= Item->text();  
    if (sFieldLine.toInt()!=iDot) {
        QMessageBox::critical(this,tr("错误"),tr("航点编号不匹配！"));
        return;
    }
        
    Item = ui->tableWidget_2->item(iDot-1, 0);
    if (Item==0) {
        QMessageBox::critical(this,tr("错误"),tr("航点编号不存在！"));
        return;
    }
    sFieldLine= Item->text();    
    iLine = ui->spinBox->value();
    if (sFieldLine.toInt()!=iLine) {
        QMessageBox::critical(this,tr("错误"),tr("航段编号不匹配！"));
        return;
    }

    int nDot, nRow = ui->tableWidget_2->rowCount();
    for (int idx=iDot; idx<=(nRow-1); idx++) {
        Item = ui->tableWidget_2->item(idx,   0);  sFieldLine= Item->text();
        Item = ui->tableWidget_2->item(idx-1, 0);  Item->setText(sFieldLine);
        
        Item = ui->tableWidget_2->item(idx,   1);  sFieldLine= Item->text();   nDot = sFieldLine.toInt()-1;
        Item = ui->tableWidget_2->item(idx-1, 1);  Item->setText(QString::number(nDot));
        
        for (int jdx=2; jdx<9; jdx++) {
            Item = ui->tableWidget_2->item(idx,   jdx);  sFieldLine= Item->text();
            Item = ui->tableWidget_2->item(idx-1, jdx);  Item->setText(sFieldLine);
        }       
    }    
    
    ui->tableWidget_2->removeRow(nRow-1);
}        

void QWaypointTabWidget::getVxdFromInut(int sp1, QString sp1_Str, int sp2, QString sp2_Str, quint8* rVxd)
{
    quint8 iTmp;
    
                                                 frame_push_uint8_t(rVxd,0,sp1);
    if (sp1_Str.isEmpty())                       frame_push_uint8_t(rVxd,1,0);
    else {
        iTmp = (quint8)(sp1_Str.toFloat()*1.0f); frame_push_uint8_t(rVxd,1,iTmp);
    }
                                                 frame_push_uint8_t(rVxd,2,sp2);
    if (sp2_Str.isEmpty())                       frame_push_uint8_t(rVxd,3,0);
    else {
        iTmp = (quint8)(sp2_Str.toFloat()*1.0f); frame_push_uint8_t(rVxd,3,iTmp);
    }
}
    
void QWaypointTabWidget::slot_refreshWaypoint()
{
    QTableWidgetItem *newItem;    
    QString  sField[2];
    QPointF lonLat;
    int num=1;
    
    newItem = new QTableWidgetItem;
    numDot_tab1 = 0;
    newItem = ui->tableWidget_2->item(num-1, 1);
    
    if (newItem==0) {
        numDot_tab1 = 0;
        emit signal_cmdOnDelWP(); 
        return;
    }
    while (newItem) {
        newItem = ui->tableWidget_2->item(num-1, 2);
        sField[0] = newItem->text();
        newItem = ui->tableWidget_2->item(num-1, 3);
        sField[1] = newItem->text();

        lonLat.setX(sField[0].toDouble());
        lonLat.setY(sField[1].toDouble());
        mDataPF[num] = lonLat;
        numDot_tab1 = num;        
        
        num++;
        newItem = ui->tableWidget_2->item(num-1, 1);
    }

    emit signal_cmdOnDrawWP(); 
}    

void QWaypointTabWidget::slot_deleteWaypoint()
{ 
    int tRow = ui->tableWidget_2->rowCount();
    for (int idx=1; idx<=tRow; idx++)
        ui->tableWidget_2->removeRow(0);    
  
    ui->spinBox_2->setValue(1);
    numDot_tab1 = 0;
    emit signal_cmdOnDelWP(); 
}    

void QWaypointTabWidget::slot_saveWaypoint()
{
    if (numDot_tab1<=0) return;

    QFile   *m_pFileSave; 
    QTableWidgetItem *newItem;    
    QString  sField[9];        
    QString fileName = QFileDialog::getSaveFileName(
                                    this,
                                    "航线文件另存",
                                    QDir::currentPath(),
                                    "txt files (*.txt)");
    m_pFileSave = new QFile(this);                                
    if (!fileName.isNull()) {
        m_pFileSave->setFileName(fileName);
        if (m_pFileSave->open(QIODevice::WriteOnly | QIODevice::Text)==false) {
            QMessageBox::critical(this,tr("error"),tr("File error!"));
            return;
        }
    }
    else {
        QMessageBox::critical(this,tr("错误"),tr("文件打开失败！"));
        return;
    }

    QTextStream   out(m_pFileSave);
    int tRow = ui->tableWidget_2->rowCount();
    for (int row=0; row<tRow; row++) {
        for (int col=0; col<9; col++) {
            newItem = ui->tableWidget_2->item(row, col);
            sField[col] = newItem->text();
            
            out<<sField[col];
            if (col<8) out<<",";
        }
        out<<"\n";
    }

    m_pFileSave->close();
}    

/* -------------------------------------------- */
/* tab3 */
/* -------------------------------------------- */
void QWaypointTabWidget::initTableWidget3()
{
    QString header = QObject::tr("航点");
    ui->treeWidget->setHeaderLabel(header);
    ui->treeWidget->setContextMenuPolicy(Qt::CustomContextMenu);

    ui->tableWidget_3->verticalHeader()->setVisible(false);
    ui->tableWidget_3->horizontalHeader()->setVisible(false);
    ui->tableWidget_3->setColumnCount(2);
    ui->tableWidget_3->setRowCount(5);
    ui->tableWidget_3->setRowHeight(0,20);
    ui->tableWidget_3->setRowHeight(1,20);
    ui->tableWidget_3->setRowHeight(2,20);
    ui->tableWidget_3->setRowHeight(3,20);
    ui->tableWidget_3->setRowHeight(4,20);
    ui->tableWidget_3->setColumnWidth(0,100);
    ui->tableWidget_3->setColumnWidth(1,250);
    ui->tableWidget_3->setShowGrid(true);

    popMenu = new QMenu(ui->treeWidget);
    newAirline = new QAction(tr("新建航线"),popMenu);
    popMenu->addAction(newAirline);
    connect(newAirline, SIGNAL(triggered()), this,SLOT(slot_newAirline()));

    waypointPopMenu = new QMenu(ui->treeWidget);
    newWaypoint = new QAction(tr("新建航点"),waypointPopMenu);
    deleteAirline = new QAction(tr("删除该航线"),waypointPopMenu);
    waypointPopMenu->addAction(newWaypoint);
    waypointPopMenu->addAction(deleteAirline);
    connect(newWaypoint, SIGNAL(triggered()), this, SLOT(slot_newWaypoint()));
    connect(deleteAirline,SIGNAL(triggered()),this, SLOT(slot_deleAirline()));

    waypointCfgPopMenu = new QMenu(ui->treeWidget);
    editWaypoint = new QAction(tr("编辑此航点"),waypointCfgPopMenu);
    deleteWaypoint = new QAction(tr("删除此航点"),waypointCfgPopMenu);
    waypointCfgPopMenu->addAction(editWaypoint);
    waypointCfgPopMenu->addAction(deleteWaypoint);
    connect(editWaypoint,SIGNAL(triggered()),  this,SLOT(slot_editWaypoint()));
    connect(deleteWaypoint,SIGNAL(triggered()),this,SLOT(slot_deletePoint()));
}



void QWaypointTabWidget::slot_customContextMenuRequested(const QPoint &pos)
{
    QTreeWidgetItem *curItem = ui->treeWidget->itemAt(pos);
    if(curItem == NULL) {
        popMenu->exec(QCursor::pos());
    }
    else if(curItem->parent() == NULL) {
        waypointPopMenu->exec(QCursor::pos());
    }
    else {
        waypointCfgPopMenu->exec(QCursor::pos());
    }
}

void QWaypointTabWidget::slot_newAirline()
{
    static qint8 i = 0;
    QString airlineName;
    airlineName = QObject::tr("航线");
        
    i++;
    airlineName += QString::number(i);
    QTreeWidgetItem *newAirline = new QTreeWidgetItem(ui->treeWidget,QStringList(airlineName));
    ui->treeWidget->addTopLevelItem(newAirline);
}

void QWaypointTabWidget::slot_newWaypoint()
{
    static qint8 i = 0;
    QString waypointName;
    waypointName = QObject::tr("航点");
        
    i++;
    waypointName += QString::number(i);
    QTreeWidgetItem *newWaypoint = new QTreeWidgetItem(ui->treeWidget->currentItem(),QStringList(waypointName));
    ui->treeWidget->currentItem()->addChild(newWaypoint);
}

void QWaypointTabWidget::slot_deleAirline()
{
    delete ui->treeWidget->takeTopLevelItem(ui->treeWidget->currentIndex().row());
}

void QWaypointTabWidget::slot_editWaypoint()
{
    ;
}

void QWaypointTabWidget::slot_deletePoint()
{
    delete ui->treeWidget->currentItem()->parent()->takeChild(ui->treeWidget->currentIndex().row());
}

