#include "recorddialog.h"
#include "ui_recorddialog.h"

QRecordDialog::QRecordDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QRecordDialog)
{
    ui->setupUi(this);
    
    QButtonGroup *group =new QButtonGroup(this);
    group->addButton(ui->pushButton_back,3);
    group->addButton(ui->pushButton_ahead,4);
    
    connect(group,               SIGNAL(buttonClicked(int)),this,SLOT(buttoncliked(int)));
    connect(ui->pushButton_play, SIGNAL(clicked(bool)),     this,SLOT(playchecked(bool)));
    connect(ui->horizontalSlider,SIGNAL(valueChanged(int)), this,SIGNAL(signal_valuechanged(int)));
    connect(ui->horizontalSlider,SIGNAL(valueChanged(int)), this,SIGNAL(signal_sliderchanged(int)));
    
    ui->horizontalSlider->setMinimum(0);
    ui->horizontalSlider->setMaximum(100);
}

QRecordDialog::~QRecordDialog()
{
    delete ui;
}

void QRecordDialog::setvalue(int a)
{
    ui->horizontalSlider->setValue(a);
}

void QRecordDialog:: playchecked(bool check)
{
    check = check;
    if (ui->pushButton_play->isChecked()) {
        ui->pushButton_play->setIcon(QIcon(":/qfi/images/play.png"));
        emit signal_setplayback(1);
    }
    else {
        ui->pushButton_play->setIcon(QIcon(":/qfi/images/pause.png"));
        emit signal_setplayback(2);
    }
}

void QRecordDialog:: buttoncliked(int button)
{
    emit signal_setplayback(button);
}


