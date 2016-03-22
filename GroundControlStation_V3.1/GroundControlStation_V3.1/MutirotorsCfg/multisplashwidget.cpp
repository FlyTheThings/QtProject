#include "multisplashwidget.h"
#include "ui_multisplashwidget.h"

multisplashWidget::multisplashWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::multisplashWidget)
{
    ui->setupUi(this);
}

multisplashWidget::~multisplashWidget()
{
    delete ui;
}
