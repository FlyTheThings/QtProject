#ifndef SPLASHWIDGET_H
#define SPLASHWIDGET_H

#include <QWidget>
#include <QButtonGroup>
#include <QMessageBox>
#include "Shared/dataStructureDefine.H"
#include "Shared/messageIDDefine.h"
#include "Shared/buff.h"

namespace Ui {
class QSplashWidget;
}

class QSplashWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QSplashWidget(QWidget *parent = 0);
    ~QSplashWidget();

    void echoMessagePacket(datalink_message_t *msg); 
    
private:
    Ui::QSplashWidget *ui;
};

#endif // SPLASHWIDGET_H
