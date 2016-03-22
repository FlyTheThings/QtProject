#include "panelPlotWidget.h"
#include "ui_panelPlotWidget.h"

QPanelPlotWidget::QPanelPlotWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QPanelPlotWidget)
{
    ui->setupUi(this);
    
    this->setStyleSheet("QWidget{background:red}");
    this->setContentsMargins(0,0,0,0);
        
    initQMenu();
    initHeightPlot();
    initVoltagePlot();
    initControlPlot();
    
    p_plotLayout = new QHBoxLayout();
    p_plotLayout->setContentsMargins(0,0,0,0);
    p_plotLayout->setSpacing(0);    
    p_plotLayout->addWidget(p_heightPlot);
    p_plotLayout->addWidget(p_voltagePlot);
    p_plotLayout->addWidget(p_controlPlot);
    this->setLayout(p_plotLayout);
    
    connect(menu_voltage, SIGNAL(triggered(QAction*)),     this,SLOT(slot_ActionSelected(QAction*)));
    connect(menu_height,  SIGNAL(triggered(QAction*)),     this,SLOT(slot_ActionSelected(QAction*)));
    connect(menu_control, SIGNAL(triggered(QAction*)),     this,SLOT(slot_ActionSelected(QAction*)));
    connect(p_controlPlot,SIGNAL(mousePress(QMouseEvent*)),this,SLOT(slot_Controlmousepress(QMouseEvent*)));
    connect(p_heightPlot, SIGNAL(mousePress(QMouseEvent*)),this,SLOT(slot_Heightmousepress(QMouseEvent*)));
    connect(p_voltagePlot,SIGNAL(mousePress(QMouseEvent*)),this,SLOT(slot_Voltagemousepress(QMouseEvent*)));
}

QPanelPlotWidget::~QPanelPlotWidget()
{
    delete ui;
}

void QPanelPlotWidget::initQMenu()
{
    menu_control=new QMenu();    
    action_ele=new QAction("纵向",this);
    action_ail=new QAction("横向",this);
    action_rud=new QAction("尾桨",this);
    action_col=new QAction("总距",this);
    menu_control->addAction(action_ele);
    menu_control->addAction(action_ail);
    menu_control->addAction(action_rud);
    menu_control->addAction(action_col);
    action_ele->setCheckable(true);     action_ele->setChecked(true);
    action_ail->setCheckable(true);     action_ail->setChecked(true);
    action_rud->setCheckable(true);     action_rud->setChecked(true);
    action_col->setCheckable(true);     action_col->setChecked(true);
    
    menu_voltage=new QMenu();
    action_vd=new QAction("地速",this);
    action_vk=new QAction("空速",this);
    menu_voltage->addAction(action_vd);
    menu_voltage->addAction(action_vk);
    action_vd->setCheckable(true);      action_vd->setChecked(true);
    action_vk->setCheckable(true);      action_vk->setChecked(true);
   
    menu_height=new QMenu();
    action_rh=new QAction("绝对高度",this);
    action_ah=new QAction("相对高度",this);
    menu_height->addAction(action_ah);
    menu_height->addAction(action_rh);
    action_rh->setCheckable(true);      action_rh->setChecked(true);
    action_ah->setCheckable(true);      action_ah->setChecked(true);    
}

void QPanelPlotWidget::initHeightPlot()
{
    p_heightPlot = new QCustomPlot();
    p_heightPlot->addGraph();                         // blue line
    p_heightPlot->graph(0)->setPen(QPen(Qt::blue));

    p_heightPlot->addGraph();                         // blue dot
    p_heightPlot->graph(1)->setPen(QPen(Qt::blue));
    p_heightPlot->graph(1)->setLineStyle(QCPGraph::lsNone);
    p_heightPlot->graph(1)->setScatterStyle(QCPScatterStyle::ssDisc);

    p_heightPlot->addGraph();                         // blue line
    p_heightPlot->graph(2)->setPen(QPen(Qt::green));

    p_heightPlot->addGraph();                         // blue dot
    p_heightPlot->graph(3)->setPen(QPen(Qt::green));
    p_heightPlot->graph(3)->setLineStyle(QCPGraph::lsNone);
    p_heightPlot->graph(3)->setScatterStyle(QCPScatterStyle::ssDisc);

    p_heightPlot->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    p_heightPlot->xAxis->setDateTimeFormat("mm:ss");
    p_heightPlot->xAxis->setAutoTickStep(false);
    p_heightPlot->xAxis->setTickStep(4);
        
    textLabel_6 = new QCPItemText(p_heightPlot);
    p_heightPlot->addItem(textLabel_6);
    textLabel_6->setPositionAlignment(Qt::AlignTop|Qt::AlignLeft);
    textLabel_6->position->setType(QCPItemPosition::ptAxisRectRatio);
    textLabel_6->position->setCoords(0.4, 0);                         // place position at center/top of axis rect
    textLabel_6->setText("绝对高度");
    textLabel_6->setFont(QFont(font().family(), 8));
    textLabel_6->setColor(QColor(0,0,255));
}

void QPanelPlotWidget::initVoltagePlot()
{
    p_voltagePlot = new QCustomPlot();
    p_voltagePlot->addGraph();                        // blue line
    p_voltagePlot->graph(0)->setPen(QPen(Qt::blue));

    p_voltagePlot->addGraph();                        // blue dot
    p_voltagePlot->graph(1)->setPen(QPen(Qt::blue));
    p_voltagePlot->graph(1)->setLineStyle(QCPGraph::lsNone);
    p_voltagePlot->graph(1)->setScatterStyle(QCPScatterStyle::ssDisc);

    p_voltagePlot->addGraph();                        // blue line
    p_voltagePlot->graph(2)->setPen(QPen(Qt::green));

    p_voltagePlot->addGraph();                        // blue dot
    p_voltagePlot->graph(3)->setPen(QPen(Qt::green));
    p_voltagePlot->graph(3)->setLineStyle(QCPGraph::lsNone);
    p_voltagePlot->graph(3)->setScatterStyle(QCPScatterStyle::ssDisc);

    p_voltagePlot->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    p_voltagePlot->xAxis->setDateTimeFormat("mm:ss");
    p_voltagePlot->xAxis->setAutoTickStep(false);
    p_voltagePlot->xAxis->setTickStep(4);
    
    textLabel_5 = new QCPItemText(p_voltagePlot);
    p_voltagePlot->addItem(textLabel_5);
    textLabel_5->setPositionAlignment(Qt::AlignTop|Qt::AlignLeft);
    textLabel_5->position->setType(QCPItemPosition::ptAxisRectRatio);
    textLabel_5->position->setCoords(0.2, 0);                           // place position at center/top of axis rect
    textLabel_5->setText("地速");
    textLabel_5->setFont(QFont(font().family(), 8));
    textLabel_5->setColor(QColor(0,0,255));
}

void QPanelPlotWidget::initControlPlot()
{    
    p_controlPlot = new QCustomPlot();    
    
    p_controlPlot->addGraph(); // blue line
    p_controlPlot->graph(0)->setPen(QPen(Qt::blue));
    p_controlPlot->addGraph(); // blue dot
    p_controlPlot->graph(1)->setPen(QPen(Qt::blue));
    p_controlPlot->graph(1)->setLineStyle(QCPGraph::lsNone);
    p_controlPlot->graph(1)->setScatterStyle(QCPScatterStyle::ssDisc);

    p_controlPlot->addGraph();
    p_controlPlot->graph(2)->setPen(QPen(Qt::green));
    p_controlPlot->addGraph(); // blue dot
    p_controlPlot->graph(3)->setPen(QPen(Qt::green));
    p_controlPlot->graph(3)->setLineStyle(QCPGraph::lsNone);
    p_controlPlot->graph(3)->setScatterStyle(QCPScatterStyle::ssDisc);

    p_controlPlot->addGraph();
    p_controlPlot->graph(4)->setPen(QPen(Qt::red));
    p_controlPlot->addGraph(); // blue dot
    p_controlPlot->graph(5)->setPen(QPen(Qt::red));
    p_controlPlot->graph(5)->setLineStyle(QCPGraph::lsNone);
    p_controlPlot->graph(5)->setScatterStyle(QCPScatterStyle::ssDisc);

    p_controlPlot->addGraph();
    p_controlPlot->graph(6)->setPen(QPen(Qt::black));
    p_controlPlot->addGraph(); // blue dot
    p_controlPlot->graph(7)->setPen(QPen(Qt::black));
    p_controlPlot->graph(7)->setLineStyle(QCPGraph::lsNone);
    p_controlPlot->graph(7)->setScatterStyle(QCPScatterStyle::ssDisc);

    p_controlPlot->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    p_controlPlot->xAxis->setDateTimeFormat("mm:ss");
    p_controlPlot->xAxis->setAutoTickStep(false);
    p_controlPlot->xAxis->setTickStep(4);
    
    textLabel = new QCPItemText(p_controlPlot);
    p_controlPlot->addItem(textLabel);
    textLabel->setPositionAlignment(Qt::AlignTop|Qt::AlignLeft);
    textLabel->position->setType(QCPItemPosition::ptAxisRectRatio);
    textLabel->position->setCoords(0.2, 0);                           // place position at center/top of axis rect
    textLabel->setText("纵向");
    textLabel->setFont(QFont(font().family(), 8));
    textLabel->setColor(QColor(0,0,255));

    textLabel_2 = new QCPItemText(p_controlPlot);
    p_controlPlot->addItem(textLabel_2);
    textLabel_2->setPositionAlignment(Qt::AlignTop|Qt::AlignLeft);
    textLabel_2->position->setType(QCPItemPosition::ptAxisRectRatio);
    textLabel_2->position->setCoords(0.4, 0);                         // place position at center/top of axis rect
    textLabel_2->setText("横向");
    textLabel_2->setFont(QFont(font().family(), 8));
    textLabel_2->setColor(QColor(0,255,0));

    textLabel_3 = new QCPItemText(p_controlPlot);
    p_controlPlot->addItem(textLabel_3);
    textLabel_3->setPositionAlignment(Qt::AlignTop|Qt::AlignLeft);
    textLabel_3->position->setType(QCPItemPosition::ptAxisRectRatio);
    textLabel_3->position->setCoords(0.6, 0);                         // place position at center/top of axis rect
    textLabel_3->setText("尾桨");
    textLabel_3->setFont(QFont(font().family(), 8));
    textLabel_3->setColor(QColor(255,0,0));

    textLabel_4 = new QCPItemText(p_controlPlot);
    p_controlPlot->addItem(textLabel_4);
    textLabel_4->setPositionAlignment(Qt::AlignTop|Qt::AlignLeft);
    textLabel_4->position->setType(QCPItemPosition::ptAxisRectRatio);
    textLabel_4->position->setCoords(0.8, 0);                         // place position at center/top of axis rect
    textLabel_4->setText("总距");
    textLabel_4->setFont(QFont(font().family(), 8));
    textLabel_4->setColor(QColor(0,0,0));
}

void QPanelPlotWidget::setPlotData(float height_j, float height_r,float v_d, float v_k,float ele, float ail,float rud, float col)
{
    double key = QDateTime::currentDateTime().toMSecsSinceEpoch()/1000.0;
    static double lastPointKey = 0.0;
    
    if (key-lastPointKey > 0.01) {      // at most add point every 10 ms
        p_heightPlot->graph(0)->addData(key, height_j);
        p_heightPlot->graph(0)->rescaleValueAxis();
        p_heightPlot->graph(0)->removeDataBefore(key-20);
        p_heightPlot->graph(1)->clearData();
        p_heightPlot->graph(1)->addData(key, height_j);
        p_heightPlot->graph(0)->removeDataBefore(key-20);

        p_heightPlot->graph(2)->addData(key, height_r);
        p_heightPlot->graph(2)->rescaleValueAxis();
        p_heightPlot->graph(2)->removeDataBefore(key-20);
        p_heightPlot->graph(3)->clearData();
        p_heightPlot->graph(3)->addData(key, height_r);
        p_heightPlot->graph(2)->removeDataBefore(key-20);
        p_heightPlot->xAxis->setRange(key+0.25, 20, Qt::AlignRight);
        if ((height_j-height_r)>=0.0f)
             p_heightPlot->yAxis->setRange(height_r-10.0f,height_j+10.0f);
        else p_heightPlot->yAxis->setRange(height_j-10.0f,height_r+10.0f);
        p_heightPlot->replot();
        
        p_voltagePlot->graph(0)->addData(key, v_d);
        p_voltagePlot->graph(0)->rescaleValueAxis();
        p_voltagePlot->graph(0)->removeDataBefore(key-20);
        p_voltagePlot->graph(1)->clearData();
        p_voltagePlot->graph(1)->addData(key, v_d);
        p_voltagePlot->graph(0)->removeDataBefore(key-20);

        p_voltagePlot->graph(2)->addData(key, v_k);
        p_voltagePlot->graph(2)->rescaleValueAxis();
        p_voltagePlot->graph(2)->removeDataBefore(key-20);
        p_voltagePlot->graph(3)->clearData();
        p_voltagePlot->graph(3)->addData(key, v_k);
        p_voltagePlot->graph(2)->removeDataBefore(key-20);
        p_voltagePlot->xAxis->setRange(key+0.25, 20, Qt::AlignRight);
        if ((v_d-v_k)>=0.0f)
             p_voltagePlot->yAxis->setRange(v_k-5.0f,v_d+5.0f);
        else p_voltagePlot->yAxis->setRange(v_d-5.0f,v_k+5.0f);
        p_voltagePlot->replot();
        
        p_controlPlot->graph(0)->addData(key, ele);
        p_controlPlot->graph(0)->rescaleValueAxis();
        p_controlPlot->graph(0)->removeDataBefore(key-20);
        p_controlPlot->graph(1)->clearData();
        p_controlPlot->graph(1)->addData(key, ele);
        p_controlPlot->graph(0)->removeDataBefore(key-20);
 
        p_controlPlot->graph(2)->addData(key, ail);
        p_controlPlot->graph(2)->rescaleValueAxis();
        p_controlPlot->graph(2)->removeDataBefore(key-20);
        p_controlPlot->graph(3)->clearData();
        p_controlPlot->graph(3)->addData(key, ail);
        p_controlPlot->graph(2)->removeDataBefore(key-20);

        p_controlPlot->graph(4)->addData(key, rud);
        p_controlPlot->graph(4)->rescaleValueAxis();
        p_controlPlot->graph(4)->removeDataBefore(key-20);
        p_controlPlot->graph(5)->clearData();
        p_controlPlot->graph(5)->addData(key, rud);
        p_controlPlot->graph(4)->removeDataBefore(key-20);

        p_controlPlot->graph(6)->addData(key, col);
        p_controlPlot->graph(6)->rescaleValueAxis();
        p_controlPlot->graph(6)->removeDataBefore(key-20);
        p_controlPlot->graph(7)->clearData();
        p_controlPlot->graph(7)->addData(key, col);
        p_controlPlot->graph(6)->removeDataBefore(key-20);
        p_controlPlot->xAxis->setRange(key+0.25, 20, Qt::AlignRight);
        p_controlPlot->yAxis->setRange(-100,100);
        p_controlPlot->replot();
        
        lastPointKey = key;    
    }
}

void QPanelPlotWidget::showHeightPlot(bool flag)
{
    if (flag==true) p_heightPlot->show();
    else            p_heightPlot->hide();
}

void QPanelPlotWidget::showVoltagePlot(bool flag)
{
    if (flag==true) p_voltagePlot->show();
    else            p_voltagePlot->hide();
}

void QPanelPlotWidget::showControlPlot(bool flag)
{
    if (flag==true) p_controlPlot->show();     
    else            p_controlPlot->hide(); 
}

void QPanelPlotWidget::slot_Heightmousepress(QMouseEvent *e)
{
    if(e->button()==Qt::RightButton) {
        menu_height->move(cursor().pos());
        menu_height->show();
    }
}

void QPanelPlotWidget::slot_Controlmousepress(QMouseEvent *e)
{
    if(e->button()==Qt::RightButton) {
        menu_control->move(cursor().pos());
        menu_control->show();
    }
}

void QPanelPlotWidget::slot_Voltagemousepress(QMouseEvent *e)
{
    if(e->button()==Qt::RightButton) {
        menu_voltage->move(cursor().pos());
        menu_voltage->show();
    }
}

void QPanelPlotWidget::slot_ActionSelected(QAction *action)
{
    Q_UNUSED(action);
    if(!action_ele->isChecked()&!action_ail->isChecked()
       &!action_rud->isChecked()&!action_col->isChecked()) {
        p_controlPlot->hide();
        emit signal_checkFailMenu(3);
        if ((p_heightPlot->isHidden())&&(p_voltagePlot->isHidden())) hide();
    }
    else {
        if(!action_ele->isChecked()) {
            p_controlPlot->graph(0)->setVisible(0);
            p_controlPlot->graph(1)->setVisible(0);
            textLabel->setText("");
        }
        else {
            p_controlPlot->graph(0)->setVisible(true);
            p_controlPlot->graph(1)->setVisible(true);
            textLabel->setText("纵向");
        }
        
        if(!action_ail->isChecked()) {
            p_controlPlot->graph(2)->setVisible(0);
            p_controlPlot->graph(3)->setVisible(0);
            textLabel_2->setText("");
        }
        else {
            p_controlPlot->graph(2)->setVisible(1);
            p_controlPlot->graph(3)->setVisible(1);
            textLabel_2->setText("横向");
        }
        
        if(!action_rud->isChecked()) {
            p_controlPlot->graph(4)->setVisible(0);
            p_controlPlot->graph(5)->setVisible(0);
            textLabel_3->setText("");
        }
        else {
            p_controlPlot->graph(4)->setVisible(true);
            p_controlPlot->graph(5)->setVisible(true);
            textLabel_3->setText("尾桨");
        }
        
        if(!action_col->isChecked()) {
            p_controlPlot->graph(6)->setVisible(0);
            p_controlPlot->graph(7)->setVisible(0);
            textLabel_4->setText("");
        }
        else {
            p_controlPlot->graph(6)->setVisible(1);
            p_controlPlot->graph(7)->setVisible(1);
            textLabel_4->setText("总距");
        }
    }

    if(!action_ah->isChecked()&!action_rh->isChecked()){
        p_heightPlot->hide();
        emit signal_checkFailMenu(1);
        if ((p_controlPlot->isHidden())&&(p_voltagePlot->isHidden())) hide();
    }
    else {
        if(!action_ah->isChecked()) {
            p_heightPlot->graph(0)->setVisible(false);
            p_heightPlot->graph(1)->setVisible(false);
            textLabel_6->setText("");
        }
        else {
            p_heightPlot->graph(0)->setVisible(true);
            p_heightPlot->graph(1)->setVisible(true);
            textLabel_6->setText("绝对高度");
        }
    }
    if(!action_vd->isChecked()&!action_vk->isChecked()){
        p_voltagePlot->hide();
        emit signal_checkFailMenu(2);
        if ((p_controlPlot->isHidden())&&(p_heightPlot->isHidden())) hide();
    }
    else {
        if(!action_vd->isChecked()) {
            p_voltagePlot->graph(0)->setVisible(false);
            p_voltagePlot->graph(1)->setVisible(false);
            textLabel_5->setText("");
        }
        else {
            p_voltagePlot->graph(0)->setVisible(true);
            p_voltagePlot->graph(1)->setVisible(true);
            textLabel_5->setText("地速");
        }
    }
}
