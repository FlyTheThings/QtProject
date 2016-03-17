#include "maptoolbar.h"
#include "ui_maptoolbar.h"

QMaptoolbar::QMaptoolbar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QMaptoolbar)
{
    ui->setupUi(this);
    action_clearframe = new QAction(tr("航线边界"),this);
    action_clearline  = new QAction(tr("预设轨迹"),this);
    QMenu *menu_clear = new QMenu(this);
    menu_clear->addAction(action_clearframe);
    menu_clear->addAction(action_clearline);
    action_clearframe->setCheckable(true);
    action_clearline->setCheckable(true);
    action_clearframe->setChecked(true);
    action_clearline->setChecked(true);
    ui->toolButton_line->setMenu(menu_clear);
    connect(menu_clear, SIGNAL(triggered(QAction*)), this, SLOT(slot_actionSelected(QAction *)));

    QAction *action_planecenter    = new QAction(tr("飞机跟随"),this);
    QAction *action_timelinecenter = new QAction(tr("轨迹跟随"),this);
    QMenu *menu_auto = new QMenu(this);
    menu_auto->addAction(action_planecenter);
    menu_auto->addAction(action_timelinecenter);
    ui->toolButton_auto->setMenu(menu_auto);
    connect(menu_auto,SIGNAL(triggered(QAction*)), this,SLOT(slot_actionSelected(QAction *)));
    
    QAction *action_delete       = new QAction(tr("轨迹清除"),this);
    QAction *action_timelineshow = new QAction(tr("轨迹隐藏"),this);
    QMenu *menu_timeline = new QMenu(this);
    menu_timeline->addAction(action_delete);
    menu_timeline->addAction(action_timelineshow);
    ui->toolButton_timeline->setMenu(menu_timeline);
    connect(menu_timeline,SIGNAL(triggered(QAction*)),this,SLOT(slot_actionSelected(QAction *)));

    QAction *action_plane = new QAction(tr("飞机居中"),this);
    QAction *action_frame = new QAction(tr("航线居中"),this);
    QMenu *menu_cen = new QMenu(this);
    menu_cen->addAction(action_plane);
    menu_cen->addAction(action_frame);
    ui->toolButton_cen->setMenu(menu_cen);
    connect(menu_cen,SIGNAL(triggered(QAction*)),this,SLOT(slot_actionSelected(QAction *)));
    
    connect(ui->toolButton_3, SIGNAL(clicked()),  this, SIGNAL(signal_hideToolbar()));
}

QMaptoolbar::~QMaptoolbar()
{
    delete ui;
}

void QMaptoolbar::slot_actionSelected(QAction *action)
{
    if (action_clearframe->isChecked())  emit signal_TOJavaScript(1); 
    else                                 emit signal_TOJavaScript(2); 
        
    if (action_clearline->isChecked())   emit signal_TOJavaScript(3);
    else                                 emit signal_TOJavaScript(4);
        
    if     (action->text()=="飞机跟随")  emit signal_TOJavaScript(5);
    else if(action->text()=="轨迹跟随")  emit signal_TOJavaScript(6);
    else if(action->text()=="轨迹清除")  emit signal_TOJavaScript(7);
    else if(action->text()=="轨迹隐藏"){ emit signal_TOJavaScript(8); action->setText("轨迹显示"); }
    else if(action->text()=="轨迹显示"){ emit signal_TOJavaScript(9); action->setText("轨迹隐藏"); }
    else if(action->text()=="航线居中")  emit signal_TOJavaScript(10);
    else if(action->text()=="飞机居中")  emit signal_TOJavaScript(11);
}

void QMaptoolbar::hidebutton(bool flag)
{
    if(flag==0) ui->toolButton_auto->hide();
    if(flag==1) ui->toolButton_auto->show();
}

void QMaptoolbar::actionset()
{
    action_clearframe->setChecked(true);
}
