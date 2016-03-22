#include "speedCmdDialog.h"
#include "ui_speedCmdDialog.h"

QSpeedCmdDialog::QSpeedCmdDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QSpeedCmdDialog)
{
    ui->setupUi(this);

    Qt::WindowFlags flags = Qt::Dialog;
    flags |= Qt::WindowMinimizeButtonHint|Qt::WindowCloseButtonHint;
    setWindowFlags(flags);
    this->setModal(0);
    
    bGroup = new QButtonGroup(this);
    bGroup->addButton(ui->sendButton,  1);
    bGroup->addButton(ui->sendButton_2,2);
    bGroup->addButton(ui->sendButton_3,3);
    connect(bGroup,SIGNAL(buttonClicked(int)), this,SLOT(slot_clickedSendCmd(int)));
}

QSpeedCmdDialog::~QSpeedCmdDialog()
{
    delete ui;
    if (bGroup)  delete bGroup;
}

void QSpeedCmdDialog::slot_clickedSendCmd(int i)
{
    float   tmp;
    quint8  cmdData[4];
    
    switch(i) {
        case 1:
            tmp = (float) ui->doubleSpinBox->value();
            frame_push_float(cmdData, 0, tmp);
            emit  signal_sendSpeedCmd(16, cmdData, 4);
            break;
        case 2:
            tmp = (float) ui->doubleSpinBox_2->value();        
            frame_push_float(cmdData, 0, tmp);
            emit  signal_sendSpeedCmd(17, cmdData, 4);
            break;
        case 3:
            tmp = (float) ui->doubleSpinBox_3->value();
            frame_push_float(cmdData, 0, tmp);
            emit  signal_sendSpeedCmd(18, cmdData, 4);
            break;
    }
}
