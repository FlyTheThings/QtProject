#ifndef MAINTOOLWIDGET_H
#define MAINTOOLWIDGET_H

#include <QWidget>
#include <QMenu>

namespace Ui {
    class QMenuToolbarWidget;
}

class QMenuToolbarWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QMenuToolbarWidget(QWidget *parent = 0);
    ~QMenuToolbarWidget();
    
    bool isMenuChecked(quint8 pID, int cID);
    void setCheckMenu(quint8 pID, int cID, bool flag);
    bool isMenuEnable(quint8 pID, int cID);
    void setEnableMenu(quint8 pID, int cID, bool flag);

signals:
    void signal_menu_action(quint8 pID, quint8 cID);
   
private slots:          
    void slot_ActionFileSelected(QAction *action);
    void slot_ActionCommuSelected(QAction *action);
    void slot_ActionConfigSelected(QAction *action);
    void slot_ActionWaypointSelected(QAction *action);
    void slot_ActionWindowsSelected(QAction *action);
    void slot_ActionHelpSelected(QAction *action);

private:
    Ui::QMenuToolbarWidget *ui;
    
    QMap<int, QAction *>  action_File,
                          action_Commu,
                          action_Config,
                          action_Waypoint,
                          action_Windows,
                          action_Help;
    void initMenuFile();
    void initMenuCommu();
    void initMenuConfig();
    void initMenuWaypoint();
    void initMenuWindows();
    void initMenuHelp();
};

#endif // MAINTOOLWIDGET_H
