#include "splashwidget.h"
#include "ui_splashwidget.h"

QSplashWidget::QSplashWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QSplashWidget)
{
    ui->setupUi(this);
}

QSplashWidget::~QSplashWidget()
{
    delete ui;
}

void QSplashWidget::echoMessagePacket(datalink_message_t *msg)
{
    quint8 echoMsg;
    
    switch (msg->msgid) {
	    case UAV_MSG_REQU_ECHO:    
	        echoMsg = msg->payload[0];
	        
	        switch (echoMsg) {
	            
	            default:                     break;    
	        }
	        break;
        default: break;
	}
}
