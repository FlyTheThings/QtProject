#include "panelDataFrameWidget.h"
#include "ui_panelDataFrameWidget.h"

QPanelDataFrameWidget::QPanelDataFrameWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QPanelDataFrameWidget)
{
    ui->setupUi(this);
    setMinimumSize(300,120);

    Protocol = new QDataProtocol(this);
    initTableWidget1();
    initTableWidget2();
    initTableWidget3();
}

QPanelDataFrameWidget::~QPanelDataFrameWidget()
{
    delete ui;
}

void QPanelDataFrameWidget::setSerialProtocol(QDataProtocol *comProtocol)
{
    dProtocol = comProtocol;
}

void QPanelDataFrameWidget::initTableWidget1()
{
    ui->tableWidget->clear();
    ui->tableWidget->setMinimumSize(300,120);
    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->horizontalHeader()->setVisible(false);
    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setRowCount(5);
    ui->tableWidget->setRowHeight(0,20);
    ui->tableWidget->setRowHeight(1,20);
    ui->tableWidget->setRowHeight(2,20);
    ui->tableWidget->setRowHeight(3,20);
    ui->tableWidget->setRowHeight(4,20);
    ui->tableWidget->setColumnWidth(0,42);
    ui->tableWidget->setColumnWidth(1,50);
    ui->tableWidget->setColumnWidth(2,42);
    ui->tableWidget->setColumnWidth(3,50);
    ui->tableWidget->setColumnWidth(4,42);
    ui->tableWidget->setColumnWidth(5,68);
    ui->tableWidget->setShowGrid(true);

    setFont(QFont("Times", 8, QFont::Bold));
    ui->tableWidget->setItem(0, 0, new QTableWidgetItem("Theta"));
    ui->tableWidget->setItem(1, 0, new QTableWidgetItem("Phi"));
    ui->tableWidget->setItem(2, 0, new QTableWidgetItem("Psi"));
    ui->tableWidget->setItem(3, 0, new QTableWidgetItem("Ele"));
    ui->tableWidget->setItem(4, 0, new QTableWidgetItem("Col"));

    ui->tableWidget->setItem(0, 2, new QTableWidgetItem("Q-Wx"));
    ui->tableWidget->setItem(1, 2, new QTableWidgetItem("P-Wy"));
    ui->tableWidget->setItem(2, 2, new QTableWidgetItem("R-Wz"));
    ui->tableWidget->setItem(3, 2, new QTableWidgetItem("Ail"));
    ui->tableWidget->setItem(4, 2, new QTableWidgetItem("Eng"));
    
    ui->tableWidget->setItem(0, 4, new QTableWidgetItem("Axb"));
    ui->tableWidget->setItem(1, 4, new QTableWidgetItem("Ayb"));
    ui->tableWidget->setItem(2, 4, new QTableWidgetItem("Azb"));
    ui->tableWidget->setItem(3, 4, new QTableWidgetItem("Rud"));
    ui->tableWidget->setItem(4, 4, new QTableWidgetItem("RPM"));
}

void QPanelDataFrameWidget::initTableWidget2()
{
    ui->tableWidget_2->clear();
    ui->tableWidget_2->setMinimumSize(300,120);
    ui->tableWidget_2->verticalHeader()->setVisible(false);
    ui->tableWidget_2->horizontalHeader()->setVisible(false);
    ui->tableWidget_2->setColumnCount(6);
    ui->tableWidget_2->setRowCount(5);
    ui->tableWidget_2->setRowHeight(0,20);
    ui->tableWidget_2->setRowHeight(1,20);
    ui->tableWidget_2->setRowHeight(2,20);
    ui->tableWidget_2->setRowHeight(3,20);
    ui->tableWidget_2->setRowHeight(4,20);
    ui->tableWidget_2->setColumnWidth(0,38);
    ui->tableWidget_2->setColumnWidth(1,70);
    ui->tableWidget_2->setColumnWidth(2,50);
    ui->tableWidget_2->setColumnWidth(3,40);
    ui->tableWidget_2->setColumnWidth(4,45);
    ui->tableWidget_2->setColumnWidth(5,50);
    ui->tableWidget_2->setShowGrid(true);

    setFont(QFont("Times", 8, QFont::Bold));
    ui->tableWidget_2->setItem(0, 0, new QTableWidgetItem("Lon"));
    ui->tableWidget_2->setItem(1, 0, new QTableWidgetItem("Lat"));
    ui->tableWidget_2->setItem(2, 0, new QTableWidgetItem("Alt"));
    ui->tableWidget_2->setItem(3, 0, new QTableWidgetItem("Vd."));
    ui->tableWidget_2->setItem(4, 0, new QTableWidgetItem("Hdot"));
               
    ui->tableWidget_2->setItem(0, 2, new QTableWidgetItem("Track"));
    ui->tableWidget_2->setItem(1, 2, new QTableWidgetItem("Star"));
    ui->tableWidget_2->setItem(2, 2, new QTableWidgetItem("G.freq"));
    ui->tableWidget_2->setItem(3, 2, new QTableWidgetItem("I.freq"));
    ui->tableWidget_2->setItem(4, 2, new QTableWidgetItem("H.freq"));
                 
    ui->tableWidget_2->setItem(0, 4, new QTableWidgetItem("eleRC"));
    ui->tableWidget_2->setItem(1, 4, new QTableWidgetItem("ailRC"));
    ui->tableWidget_2->setItem(2, 4, new QTableWidgetItem("rudRC"));
    ui->tableWidget_2->setItem(3, 4, new QTableWidgetItem("colRC"));
    ui->tableWidget_2->setItem(4, 4, new QTableWidgetItem("engRC"));
}

void QPanelDataFrameWidget::initTableWidget3()
{
    ui->tableWidget_3->clear();
    ui->tableWidget_3->setMinimumSize(300,120);
    ui->tableWidget_3->verticalHeader()->setVisible(false);
    ui->tableWidget_3->horizontalHeader()->setVisible(false);
    ui->tableWidget_3->setColumnCount(6);
    ui->tableWidget_3->setRowCount(5);
    ui->tableWidget_3->setRowHeight(0,20);
    ui->tableWidget_3->setRowHeight(1,20);
    ui->tableWidget_3->setRowHeight(2,20);
    ui->tableWidget_3->setRowHeight(3,20);
    ui->tableWidget_3->setRowHeight(4,20);
    ui->tableWidget_3->setColumnWidth(0,40);
    ui->tableWidget_3->setColumnWidth(1,68);
    ui->tableWidget_3->setColumnWidth(2,40);
    ui->tableWidget_3->setColumnWidth(3,50);
    ui->tableWidget_3->setColumnWidth(4,45);
    ui->tableWidget_3->setColumnWidth(5,50);
    ui->tableWidget_3->setShowGrid(true);

    setFont(QFont("Times", 8, QFont::Bold));
    ui->tableWidget_3->setItem(0, 0, new QTableWidgetItem("Hdot_opt"));
    ui->tableWidget_3->setItem(1, 0, new QTableWidgetItem("R_opt"));
    ui->tableWidget_3->setItem(2, 0, new QTableWidgetItem("Vx_opt"));
    ui->tableWidget_3->setItem(3, 0, new QTableWidgetItem("Vy_opt"));
    ui->tableWidget_3->setItem(4, 0, new QTableWidgetItem("OSCPUUsage"));
               
    ui->tableWidget_3->setItem(0, 2, new QTableWidgetItem("Hdot_var"));
    ui->tableWidget_3->setItem(1, 2, new QTableWidgetItem("R_var"));
    ui->tableWidget_3->setItem(2, 2, new QTableWidgetItem("Vx_var"));
    ui->tableWidget_3->setItem(3, 2, new QTableWidgetItem("Vy_var"));
    ui->tableWidget_3->setItem(4, 2, new QTableWidgetItem("dX_mix"));
                 
    ui->tableWidget_3->setItem(0, 4, new QTableWidgetItem("height_var"));
    ui->tableWidget_3->setItem(1, 4, new QTableWidgetItem("psi_var"));
    ui->tableWidget_3->setItem(2, 4, new QTableWidgetItem("ac_dX"));
    ui->tableWidget_3->setItem(3, 4, new QTableWidgetItem("ac_dY"));
    ui->tableWidget_3->setItem(4, 4, new QTableWidgetItem("dY_mix"));
}

void QPanelDataFrameWidget::updatePageDisplay()
{
    DataPage1Display();
    DataPage2Display();
    DataPage3Display();
}

void QPanelDataFrameWidget::DataPage1Display()
{
    QTableWidgetItem *newItem[5][3];
    for (int i=0; i<5; i++) {
        for (int j=0; j<3; j++) {
            newItem[i][j] = new QTableWidgetItem;
            newItem[i][j]->setFont(QFont("Times", 8, QFont::Bold));
            newItem[i][j]->setBackgroundColor(Qt::cyan);
        }
    }        

    newItem[0][0]->setText(QString::number(dProtocol->data_imu.theta,'f',2));
    ui->tableWidget->setItem(0, 1, newItem[0][0]);
    newItem[1][0]->setText(QString::number(dProtocol->data_imu.phi,'f',2));
    ui->tableWidget->setItem(1, 1, newItem[1][0]);
    newItem[2][0]->setText(QString::number(dProtocol->data_imu.psi,'f',1));
    ui->tableWidget->setItem(2, 1, newItem[2][0]);
    newItem[3][0]->setText(QString::number(dProtocol->ele_law,'f',1));
    ui->tableWidget->setItem(3, 1, newItem[3][0]);
    newItem[4][0]->setText(QString::number(dProtocol->col_law,'f',1));
    ui->tableWidget->setItem(4, 1, newItem[4][0]);

    newItem[0][1]->setText(QString::number(dProtocol->data_imu.Q,'f',1));
    ui->tableWidget->setItem(0, 3, newItem[0][1]);
    newItem[1][1]->setText(QString::number(dProtocol->data_imu.P,'f',1));
    ui->tableWidget->setItem(1, 3, newItem[1][1]);
    newItem[2][1]->setText(QString::number(dProtocol->data_imu.R,'f',1));
    ui->tableWidget->setItem(2, 3, newItem[2][1]);
    newItem[3][1]->setText(QString::number(dProtocol->ail_law,'f',1));
    ui->tableWidget->setItem(3, 3, newItem[3][1]);
    newItem[4][1]->setText(QString::number(dProtocol->eng_law,'f',1));
    ui->tableWidget->setItem(4, 3, newItem[4][1]);
    
    newItem[0][2]->setText(QString::number(dProtocol->data_imu.Axb,'f',2));
    ui->tableWidget->setItem(0, 5, newItem[0][2]);
    newItem[1][2]->setText(QString::number(dProtocol->data_imu.Ayb,'f',2));
    ui->tableWidget->setItem(1, 5, newItem[1][2]);
    newItem[2][2]->setText(QString::number(dProtocol->data_imu.Azb,'f',2));
    ui->tableWidget->setItem(2, 5, newItem[2][2]);
    newItem[3][2]->setText(QString::number(dProtocol->rud_law,'f',1));
    ui->tableWidget->setItem(3, 5, newItem[3][2]);
    newItem[4][2]->setText(QString::number(dProtocol->data_rpm,'g',0));
    ui->tableWidget->setItem(4, 5, newItem[4][2]);
}

void QPanelDataFrameWidget::DataPage2Display()
{
    QTableWidgetItem *newItem[5][3];
    for (int i=0; i<5; i++) {
        for (int j=0; j<3; j++) {
            newItem[i][j] = new QTableWidgetItem;
            newItem[i][j]->setFont(QFont("Times", 8, QFont::Bold));
            newItem[i][j]->setBackgroundColor(Qt::cyan);
        }
    }        

    newItem[0][0]->setText(QString::number(dProtocol->data_gps.lon,'f',6));
    ui->tableWidget_2->setItem(0, 1, newItem[0][0]);
    newItem[1][0]->setText(QString::number(dProtocol->data_gps.lat,'f',6));
    ui->tableWidget_2->setItem(1, 1, newItem[1][0]);
    newItem[2][0]->setText(QString::number(dProtocol->data_gps.alt,'f',1));
    ui->tableWidget_2->setItem(2, 1, newItem[2][0]);
    newItem[3][0]->setText(QString::number(dProtocol->data_gps.Vd,'f',1));
    ui->tableWidget_2->setItem(3, 1, newItem[3][0]);
    newItem[4][0]->setText(QString::number(dProtocol->data_gps.Hdot,'f',1));
    ui->tableWidget_2->setItem(4, 1, newItem[4][0]);
    
    newItem[0][1]->setText(QString::number(dProtocol->data_gps.track,'f',1));
    ui->tableWidget_2->setItem(0, 3, newItem[0][1]);
    newItem[1][1]->setText(QString::number(dProtocol->data_gps.used));
    ui->tableWidget_2->setItem(1, 3, newItem[1][1]);
    newItem[2][1]->setText(QString::number(dProtocol->data_gps.freq));
    ui->tableWidget_2->setItem(2, 3, newItem[2][1]);
    newItem[3][1]->setText(QString::number(dProtocol->data_imu.freq));
    ui->tableWidget_2->setItem(3, 3, newItem[3][1]);
    newItem[4][1]->setText(QString::number(dProtocol->data_hmc.freq));
    ui->tableWidget_2->setItem(4, 3, newItem[4][1]);
    
    newItem[0][2]->setText(QString::number(dProtocol->ele_RC,'f',1));
    ui->tableWidget_2->setItem(0, 5, newItem[0][2]);
    newItem[1][2]->setText(QString::number(dProtocol->ail_RC,'f',1));
    ui->tableWidget_2->setItem(1, 5, newItem[1][2]);
    newItem[2][2]->setText(QString::number(dProtocol->rud_RC,'f',1));
    ui->tableWidget_2->setItem(2, 5, newItem[2][2]);
    newItem[3][2]->setText(QString::number(dProtocol->col_RC,'f',1));
    ui->tableWidget_2->setItem(3, 5, newItem[3][2]);
    newItem[4][2]->setText(QString::number(dProtocol->eng_RC,'f',1));
    ui->tableWidget_2->setItem(4, 5, newItem[4][2]);
}

void QPanelDataFrameWidget::DataPage3Display()
{
    QTableWidgetItem *newItem[5][3];
    for (int i=0; i<5; i++) {
        for (int j=0; j<3; j++) {
            newItem[i][j] = new QTableWidgetItem;
            newItem[i][j]->setFont(QFont("Times", 8, QFont::Bold));
            newItem[i][j]->setBackgroundColor(Qt::cyan);
        }
    }

    newItem[0][0]->setText(QString::number(dProtocol->Hdot_opt,'f',1));
    ui->tableWidget_3->setItem(0, 1, newItem[0][0]);
    newItem[1][0]->setText(QString::number(dProtocol->R_opt,'f',1));
    ui->tableWidget_3->setItem(1, 1, newItem[1][0]);
    newItem[2][0]->setText(QString::number(dProtocol->Vx_opt,'f',1));
    ui->tableWidget_3->setItem(2, 1, newItem[2][0]);
    newItem[3][0]->setText(QString::number(dProtocol->Vy_opt,'f',1));
    ui->tableWidget_3->setItem(3, 1, newItem[3][0]);
    newItem[4][0]->setText(QString::number(dProtocol->OSCPUUsage,'f',1));
    ui->tableWidget_3->setItem(4, 1, newItem[4][0]);
    
    newItem[0][1]->setText(QString::number(dProtocol->Hdot_var,'f',1));
    ui->tableWidget_3->setItem(0, 3, newItem[0][1]);
    newItem[1][1]->setText(QString::number(dProtocol->R_var,'f',1));
    ui->tableWidget_3->setItem(1, 3, newItem[1][1]);
    newItem[2][1]->setText(QString::number(dProtocol->Vx_var,'f',1));
    ui->tableWidget_3->setItem(2, 3, newItem[2][1]);
    newItem[3][1]->setText(QString::number(dProtocol->Vy_var,'f',1));
    ui->tableWidget_3->setItem(3, 3, newItem[3][1]);
    newItem[4][1]->setText(QString::number(dProtocol->dX_mix,'f',1));
    ui->tableWidget_3->setItem(4, 3, newItem[4][1]);
    
    newItem[0][2]->setText(QString::number(dProtocol->height_var,'f',1));
    ui->tableWidget_3->setItem(0, 5, newItem[0][2]);
    newItem[1][2]->setText(QString::number(dProtocol->psi_var,'f',1));
    ui->tableWidget_3->setItem(1, 5, newItem[1][2]);
    newItem[2][2]->setText(QString::number(dProtocol->ac_dX,'f',1));
    ui->tableWidget_3->setItem(2, 5, newItem[2][2]);
    newItem[3][2]->setText(QString::number(dProtocol->ac_dY,'f',1));
    ui->tableWidget_3->setItem(3, 5, newItem[3][2]);
    newItem[4][2]->setText(QString::number(dProtocol->dY_mix,'f',1));
    ui->tableWidget_3->setItem(4, 5, newItem[4][2]);
}

void QPanelDataFrameWidget::slot_sim(float *addr, quint8 length)
{
    length = length;
    Protocol->data_imu.theta = addr[0];
    Protocol->data_imu.phi   = addr[1];
    Protocol->data_imu.psi   = addr[2];
    Protocol->data_imu.Q     = addr[3];
    Protocol->data_imu.P     = addr[4];
    Protocol->data_imu.R     = addr[5];
    Protocol->data_gps.Vd    = addr[6];
    Protocol->data_gps.Hdot  = addr[7];
    Protocol->data_gps.track = addr[8];
    Protocol->data_gps.lon   = addr[9];
    Protocol->data_gps.lat   = addr[10];
    Protocol->data_gps.alt   = addr[11];
    Protocol->data_imu.Axb    = addr[12];
    Protocol->data_imu.Ayb    = addr[13];
    Protocol->data_imu.Azb    = addr[14];

}










