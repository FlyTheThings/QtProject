#include "menuToolbarWidget.h"
#include "ui_menuToolbarWidget.h"

QMenuToolbarWidget::QMenuToolbarWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QMenuToolbarWidget)
{
    ui->setupUi(this);
    
    initMenuFile();
    initMenuCommu();
    initMenuConfig(); 
    initMenuWaypoint();
    initMenuWindows(); 
    initMenuHelp();    
}

QMenuToolbarWidget::~QMenuToolbarWidget()
{
    delete ui;
}

void QMenuToolbarWidget::initMenuFile()
{
    QAction *tmpAction;
    
    tmpAction = new QAction(tr("直升机"),this);    action_File.insert(1, tmpAction);   tmpAction->setCheckable(true);
    tmpAction = new QAction(tr("多旋翼"),this);    action_File.insert(2, tmpAction);   tmpAction->setCheckable(true);
    tmpAction = new QAction(tr("测试"),this);      action_File.insert(3, tmpAction);   tmpAction->setCheckable(true);
    tmpAction = new QAction(tr("仿真"),this);      action_File.insert(4, tmpAction);   tmpAction->setCheckable(true);
    tmpAction = new QAction(tr("飞行"),this);      action_File.insert(5, tmpAction);   tmpAction->setCheckable(true);
    tmpAction = new QAction(tr("数据记录"),this);  action_File.insert(6, tmpAction);   tmpAction->setCheckable(true);
    tmpAction = new QAction(tr("数据回放"),this);  action_File.insert(7, tmpAction);   tmpAction->setCheckable(true);
    tmpAction = new QAction(tr("退出"),this);      action_File.insert(8, tmpAction);
             
    QMenu *menu_file    = new QMenu(this);
    QMenu *menuInitial  = new QMenu(this);
    QMenu *menu_runmode = new QMenu(this);

    menuInitial->setTitle(tr("机型选择"));
    menuInitial->addSeparator();    menuInitial->addAction(action_File[1]);
    menuInitial->addSeparator();    menuInitial->addAction(action_File[2]);

    menu_runmode->setTitle("运行模式");
    menu_runmode->addSeparator();    menu_runmode->addAction(action_File[3]);
    menu_runmode->addSeparator();    menu_runmode->addAction(action_File[4]);
    menu_runmode->addSeparator();    menu_runmode->addAction(action_File[5]);
    menu_runmode->addSeparator();    menu_runmode->setSeparatorsCollapsible(0);
   
    menu_file->addSeparator();       menu_file->addMenu(menuInitial);
    menu_file->addSeparator();       menu_file->addMenu(menu_runmode);
    menu_file->addSeparator();       menu_file->addAction(action_File[6]);
                                     menu_file->addAction(action_File[7]);
    menu_file->addSeparator();       menu_file->addAction(action_File[8]);
    menu_file->addSeparator();       menu_file->setSeparatorsCollapsible(0);
    ui->fileButton->setMenu(menu_file);
    
    connect(menu_file, SIGNAL(triggered(QAction*)),  this, SLOT(slot_ActionFileSelected(QAction*)));  
}

void QMenuToolbarWidget::slot_ActionFileSelected(QAction *action)
{
    emit signal_menu_action(1, action_File.key(action));    
}

void QMenuToolbarWidget::initMenuCommu()
{
    QAction *tmpAction;
    
    tmpAction = new QAction(tr("串口设置"),this);  action_Commu.insert(1, tmpAction); 
    tmpAction = new QAction(tr("串口打开"),this);  action_Commu.insert(2, tmpAction);   tmpAction->setCheckable(true); 
    tmpAction = new QAction(tr("串口关闭"),this);  action_Commu.insert(3, tmpAction);   tmpAction->setCheckable(true); 
    tmpAction = new QAction(tr("UDP设置"),this);   action_Commu.insert(4, tmpAction);
    tmpAction = new QAction(tr("UDP打开"),this);   action_Commu.insert(5, tmpAction);   tmpAction->setCheckable(true);
    tmpAction = new QAction(tr("UDP关闭"),this);   action_Commu.insert(6, tmpAction);   tmpAction->setCheckable(true);

    QMenu *menu_commu = new QMenu(this);                             
    menu_commu->addSeparator();    menu_commu->addAction(action_Commu[1]);
                                   menu_commu->addAction(action_Commu[2]);
                                   menu_commu->addAction(action_Commu[3]);
    menu_commu->addSeparator();    menu_commu->addAction(action_Commu[4]);
                                   menu_commu->addAction(action_Commu[5]);
                                   menu_commu->addAction(action_Commu[6]);
    menu_commu->addSeparator();    menu_commu->setSeparatorsCollapsible(0);
    ui->comuButton->setMenu(menu_commu);
    
    connect(menu_commu, SIGNAL(triggered(QAction*)),  this, SLOT(slot_ActionCommuSelected(QAction*)));  
}

void QMenuToolbarWidget::slot_ActionCommuSelected(QAction *action)
{
    emit signal_menu_action(2, action_Commu.key(action));     
}

void QMenuToolbarWidget::initMenuConfig()
{
    QAction *tmpAction;
    
    tmpAction = new QAction(tr("查询开"),this);    action_Config.insert(1, tmpAction);
    tmpAction = new QAction(tr("查询关"),this);    action_Config.insert(2, tmpAction);
    tmpAction = new QAction(tr("设置开"),this);    action_Config.insert(3, tmpAction);
    tmpAction = new QAction(tr("设置关"),this);    action_Config.insert(4, tmpAction);
    tmpAction = new QAction(tr("数据配置"),this);  action_Config.insert(5, tmpAction);
    tmpAction = new QAction(tr("数据保存"),this);  action_Config.insert(6, tmpAction);
    tmpAction = new QAction(tr("数据删除"),this);  action_Config.insert(7, tmpAction);

    QMenu *menu_config = new QMenu(this); 
    menu_config->addSeparator();    menu_config->addAction(action_Config[1]);
                                    menu_config->addAction(action_Config[2]);
    menu_config->addSeparator();    menu_config->addAction(action_Config[3]);
                                    menu_config->addAction(action_Config[4]);
    menu_config->addSeparator();    menu_config->addAction(action_Config[5]);
    menu_config->addSeparator();    menu_config->addAction(action_Config[6]);
                                    menu_config->addAction(action_Config[7]);
    menu_config->addSeparator();    menu_config->setSeparatorsCollapsible(0);
    ui->configButton->setMenu(menu_config);
    
    connect(menu_config, SIGNAL(triggered(QAction*)),  this, SLOT(slot_ActionConfigSelected(QAction*)));   
}

void QMenuToolbarWidget::slot_ActionConfigSelected(QAction *action)
{
    emit signal_menu_action(3, action_Config.key(action));     
}

void QMenuToolbarWidget::initMenuWaypoint()
{
    QAction *tmpAction;
    
    tmpAction = new QAction(tr("航线加载"),this);  action_Waypoint.insert(1, tmpAction);  tmpAction->setCheckable(true); 
    tmpAction = new QAction(tr("航线清除"),this);  action_Waypoint.insert(2, tmpAction);  tmpAction->setCheckable(true); 
    tmpAction = new QAction(tr("航线管理"),this);  action_Waypoint.insert(3, tmpAction);

    QMenu *menu_wp = new QMenu(this);                             
    menu_wp->addSeparator();    menu_wp->addAction(action_Waypoint[1]);
                                menu_wp->addAction(action_Waypoint[2]);
    menu_wp->addSeparator();    menu_wp->addAction(action_Waypoint[3]);
    menu_wp->addSeparator();    menu_wp->setSeparatorsCollapsible(0);
    ui->lineButton->setMenu(menu_wp);
    
    connect(menu_wp, SIGNAL(triggered(QAction*)),  this, SLOT(slot_ActionWaypointSelected(QAction*)));   
}

void QMenuToolbarWidget::slot_ActionWaypointSelected(QAction *action)
{
    emit signal_menu_action(4, action_Waypoint.key(action));
}

void QMenuToolbarWidget::initMenuWindows()
{
    QAction *tmpAction;
    
    tmpAction = new QAction(tr("百度地图"),this);   action_Windows.insert(1, tmpAction); 
                                                    tmpAction->setCheckable(true);       tmpAction->setChecked(true);
    tmpAction = new QAction(tr("谷歌地图"),this);   action_Windows.insert(2, tmpAction); tmpAction->setCheckable(true);
    tmpAction = new QAction(tr("本地地图"),this);   action_Windows.insert(3, tmpAction); tmpAction->setCheckable(true);
    tmpAction = new QAction(tr("高度绘制"),this);   action_Windows.insert(4, tmpAction); tmpAction->setCheckable(true);                                                    
    tmpAction = new QAction(tr("速度绘制"),this);   action_Windows.insert(5, tmpAction); tmpAction->setCheckable(true);
    tmpAction = new QAction(tr("变矩绘制"),this);   action_Windows.insert(6, tmpAction); tmpAction->setCheckable(true);

    QMenu *menu_plot = new QMenu(this); 
    QMenu *menu_map  = new QMenu(this);
    menu_map->setTitle("地图选择");
    menu_map->addSeparator();     menu_map->addAction(action_Windows[1]);
    menu_map->addSeparator();     menu_map->addAction(action_Windows[2]);
    menu_map->addSeparator();     menu_map->addAction(action_Windows[3]);
    menu_map->addSeparator();     menu_map->setSeparatorsCollapsible(0);
    
    menu_plot->addSeparator();    menu_plot->addMenu(menu_map);
    menu_plot->addSeparator();    menu_plot->addAction(action_Windows[4]);
                                  menu_plot->addAction(action_Windows[5]);
                                  menu_plot->addAction(action_Windows[6]);   
    menu_plot->addSeparator();    menu_plot->setSeparatorsCollapsible(0);   
    ui->plotButton->setMenu(menu_plot); 
    
    connect(menu_plot,SIGNAL(triggered(QAction*)),this,SLOT(slot_ActionWindowsSelected(QAction*)));
}

void QMenuToolbarWidget::slot_ActionWindowsSelected(QAction *action)
{
    switch (action_Windows.key(action)) {
        case 1:  
            if (action->isChecked()) {
                emit signal_menu_action(5, 1);
                action_Windows[2]->setChecked(false);
                action_Windows[3]->setChecked(false);
            }
            else action_Windows[1]->setChecked(false);
            break;
        case 2:  
            if (action->isChecked()) {
                emit signal_menu_action(5, 2);
                action_Windows[1]->setChecked(false);
                action_Windows[3]->setChecked(false);
            }
            else action_Windows[2]->setChecked(false);
            break;
        case 3:  
            if (action->isChecked()) {
                emit signal_menu_action(5, 3);
                action_Windows[1]->setChecked(false);
                action_Windows[2]->setChecked(false);
            }
            else action_Windows[3]->setChecked(false);
            break;
        case 4:
            if(action->isChecked())  emit signal_menu_action(5, 4);
            else {
                emit signal_menu_action(5, 7);
                if ((!action_Windows[5]->isChecked()) &&(!action_Windows[6]->isChecked()))
                    emit signal_menu_action(5, 10);
            }
            break;  
        case 5:
            if(action->isChecked())  emit signal_menu_action(5, 5);
            else {  
                emit signal_menu_action(5, 8);
                if ((!action_Windows[4]->isChecked()) &&(!action_Windows[6]->isChecked()))
                    emit signal_menu_action(5, 10);
            }
            break;
        case 6:
            if(action->isChecked())  emit signal_menu_action(5, 6);
            else {                   
                emit signal_menu_action(5, 9);
                if ((!action_Windows[4]->isChecked()) &&(!action_Windows[5]->isChecked()))
                    emit signal_menu_action(5, 10);
            }
            break;            
    }
}

void QMenuToolbarWidget::initMenuHelp()
{
    QAction *tmpAction;
    
    tmpAction = new QAction(tr("帮助"),this);     action_Help.insert(1, tmpAction);
    tmpAction = new QAction(tr("固件升级"),this); action_Help.insert(2, tmpAction);
    tmpAction = new QAction(tr("关于"),this);     action_Help.insert(3, tmpAction);
    
    QMenu *menu_help = new QMenu(this);
    menu_help->addSeparator();    menu_help->addAction(action_Help[1]);
    menu_help->addSeparator();    menu_help->addAction(action_Help[2]);
    menu_help->addSeparator();    menu_help->addAction(action_Help[3]);
    menu_help->addSeparator();    menu_help->setSeparatorsCollapsible(0);
    ui->helpButton->setMenu(menu_help);
    
    connect(menu_help,SIGNAL(triggered(QAction*)), this,SLOT(slot_ActionHelpSelected(QAction*))); 
}

void QMenuToolbarWidget::slot_ActionHelpSelected(QAction *action)
{
    emit signal_menu_action(6, action_Help.key(action));
}

void QMenuToolbarWidget::setEnableMenu(quint8 pID, int cID, bool flag)
{
    switch(pID) {
        case 1: action_File[cID]->setEnabled(flag);     break;
        case 2: action_Commu[cID]->setEnabled(flag);    break;
        case 3: action_Config[cID]->setEnabled(flag);   break;
        case 4: action_Waypoint[cID]->setEnabled(flag); break;
        case 5: action_Windows[cID]->setEnabled(flag);  break;
        case 6: action_Help[cID]->setEnabled(flag);     break;
    }
}

bool QMenuToolbarWidget::isMenuEnable(quint8 pID, int cID)
{
    bool ret;
    switch(pID) {
        case 1: ret = action_File[cID]->isEnabled();     break;
        case 2: ret = action_Commu[cID]->isEnabled();    break;
        case 3: ret = action_Config[cID]->isEnabled();   break;
        case 4: ret = action_Waypoint[cID]->isEnabled(); break;
        case 5: ret = action_Windows[cID]->isEnabled();  break;
        case 6: ret = action_Help[cID]->isEnabled();     break;
        default:ret = false;                             break;
    }
    return (ret);
}

void QMenuToolbarWidget::setCheckMenu(quint8 pID, int cID, bool flag)
{
    switch(pID) {
        case 1: action_File[cID]->setChecked(flag);     break;
        case 2: action_Commu[cID]->setChecked(flag);    break;
        case 3: action_Config[cID]->setChecked(flag);   break;
        case 4: action_Waypoint[cID]->setChecked(flag); break;
        case 5: action_Windows[cID]->setChecked(flag);  break;
        case 6: action_Help[cID]->setChecked(flag);     break;
    }
}

bool QMenuToolbarWidget::isMenuChecked(quint8 pID, int cID)
{
    bool ret;    
    switch(pID) {
        case 1: ret = action_File[cID]->isChecked();     break;
        case 2: ret = action_Commu[cID]->isChecked();    break;
        case 3: ret = action_Config[cID]->isChecked();   break;
        case 4: ret = action_Waypoint[cID]->isChecked(); break;
        case 5: ret = action_Windows[cID]->isChecked();  break;
        case 6: ret = action_Help[cID]->isChecked();     break;  
        default:ret = false;                             break; 
    } 
    return (ret);
}
