#ifndef MULTISPLASHWIDGET_H
#define MULTISPLASHWIDGET_H

#include <QWidget>

namespace Ui {
class multisplashWidget;
}

class multisplashWidget : public QWidget
{
    Q_OBJECT

public:
    explicit multisplashWidget(QWidget *parent = 0);
    ~multisplashWidget();

private:
    Ui::multisplashWidget *ui;
};

#endif // MULTISPLASHWIDGET_H
