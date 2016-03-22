#include "positionCmdDialog.h"
#include "ui_positionCmdDialog.h"

QPositionCmdDialog::QPositionCmdDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QPositionCmdDialog)
{
    ui->setupUi(this);

    Qt::WindowFlags flags = Qt::Dialog;
    flags |= Qt::WindowMinimizeButtonHint|Qt::WindowCloseButtonHint;
    setWindowFlags(flags);
    this->setModal(0);
    
    ui->doubleSpinBox_5->setDecimals(7);
    ui->doubleSpinBox_6->setDecimals(7);
    
    bGroup = new QButtonGroup(this);
    bGroup->addButton(ui->sendButton,1);
    bGroup->addButton(ui->sendButton_2,2);
    bGroup->addButton(ui->sendButton_3,3);
    bGroup->addButton(ui->sendButton_4,4);
    bGroup->addButton(ui->sendButton_5,5);
    connect(bGroup,SIGNAL(buttonClicked(int)), this,SLOT(slot_clickedSendCmd(int)));
}

QPositionCmdDialog::~QPositionCmdDialog()
{
    delete ui;
    if (bGroup)  delete bGroup;
}

void QPositionCmdDialog::slot_clickedSendCmd(int i)
{
    float   tmpF;
    double  tmpDB;
    quint8  cmdData[20];
    
    switch(i) {
        case 1:
            tmpF = (float) ui->doubleSpinBox->value();
            frame_push_float(cmdData, 0, tmpF);
            emit  signal_sendPositionCmd(20, cmdData, 4);
            break;
        case 2:
            tmpF = (float) ui->doubleSpinBox_2->value();
            frame_push_float(cmdData, 0, tmpF);
            emit  signal_sendPositionCmd(21, cmdData, 4);
            break;
        case 3:
            tmpF = (float) ui->doubleSpinBox_3->value();
            frame_push_float(cmdData, 0, tmpF);
            emit  signal_sendPositionCmd(22, cmdData, 4);
            break;
        case 4:
            tmpF = (float) ui->doubleSpinBox_4->value();
            frame_push_float(cmdData, 0, tmpF);
            emit  signal_sendPositionCmd(19, cmdData, 4);
            break;
        case 5:
            tmpDB = ui->doubleSpinBox_5->value();
            frame_push_double(cmdData, 0, tmpDB);
            tmpDB = ui->doubleSpinBox_6->value();
            frame_push_double(cmdData, 8, tmpDB);
            tmpF = (float) ui->doubleSpinBox_7->value();
            frame_push_float(cmdData, 16, tmpF);            
            emit  signal_sendPositionCmd(24, cmdData, 20);
            break;
    }
}
