#include "statusToolbarWidget.h"
#include "ui_statusToolbarWidget.h"

QStatusToolbarWidget::QStatusToolbarWidget(QWidget *parent) :
    QWidget(parent),
    flag_light(1),
    ui(new Ui::QStatusToolbarWidget)
{
    ui->setupUi(this);

    timer = new QTimer();
    timer->start(100);
    
    connect(timer,SIGNAL(timeout()), this,SLOT(slot_timer()));
}

QStatusToolbarWidget::~QStatusToolbarWidget()
{
    delete ui;
    if (timer)  delete timer;
}

void QStatusToolbarWidget::displayGcsRunMode(quint8 idx)
{
    switch(idx) {
        case 0: ui->label_mode->setText(tr("NaN")); break;
        case 1: ui->label_mode->setText(tr("飞行")); break;
        case 2: ui->label_mode->setText(tr("测试")); break;
        case 3: ui->label_mode->setText(tr("仿真")); break;
    }    
}

void QStatusToolbarWidget::displayUavActiveNumber(quint8 activeID, quint8 totaleNum)
{
    QString tmpS;
    if (activeID==0) tmpS = "NaN / " + QString::number(0);
    if (activeID==1) tmpS = "Helic / " + QString::number(totaleNum);
    if (activeID==2) tmpS = "Rotor / " + QString::number(totaleNum);
    ui->label_num->setText(tmpS);
}

void QStatusToolbarWidget::displayUavFlyStatus(quint8 idx)
{
    switch(idx) {
        case 0: ui->label_state->setText(tr("NaN"));  break;
        case 1: ui->label_state->setText(tr("正常")); break;
        case 2: ui->label_state->setText(tr("异常")); break;
        case 3: ui->label_state->setText(tr("    ")); break;
    }
}

void QStatusToolbarWidget::displaylight(int flag)
{
   flag_light=flag;
}

void QStatusToolbarWidget::displayLocalTime(QString time)
{
    ui->label_time->setText(time);  
}

void QStatusToolbarWidget::slot_timer()
{
    static int count=1;
    switch(flag_light) {
        case 0: ui->toolButton_light->setIcon(QIcon(":/qfi/images/black.png"));        break;        //黑色
        case 1: ui->toolButton_light->setIcon(QIcon(":/qfi/images/light_red.png"));    break;        //红色
        case 2: ui->toolButton_light->setIcon(QIcon(":/qfi/images/light_gren.png"));   break;        //绿色
        case 3: ui->toolButton_light->setIcon(QIcon(":/qfi/images/light_yellow.png")); break;        //黄色
        case 4: if (count==1) ui->toolButton_light->setIcon(QIcon(":/qfi/images/black.png"));        //绿色闪烁
                else          ui->toolButton_light->setIcon(QIcon(":/qfi/images/light_gren.png"));
                break;
        case 5: if (count==1) ui->toolButton_light->setIcon(QIcon(":/qfi/images/black.png"));        //红灯闪烁
                else          ui->toolButton_light->setIcon(QIcon(":/qfi/images/light_red.png"));
                break;
    }
    count=-count;
}
