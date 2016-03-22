#ifndef MAPTOOLBAR_H
#define MAPTOOLBAR_H

#include <QWidget>
#include <QMenu>
#include "WidgetMap2D/panelMap2DWidget.h"

namespace Ui {
class QMaptoolbar;
}

class QMaptoolbar : public QWidget
{
    Q_OBJECT

public:
    explicit QMaptoolbar(QWidget *parent = 0);
    ~QMaptoolbar();
    
    void hidebutton(bool flag);
    void actionset();
signals:
    void signal_hideToolbar();
    void signal_TOJavaScript(int sign);

private slots:
    void slot_actionSelected(QAction *action);
    
private:
    Ui::QMaptoolbar *ui;
        
    QAction *action_clearframe,
            *action_clearline;
};

#endif // MAPTOOLBAR_H
