#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolBar>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QSerialPort>
#include <QMessageBox>
#include <QStackedWidget>
#include <QTimer>
#include <QTextBrowser>
#include <QFile>
#include <QImage>

#include "MainWindow/menuToolbarWidget.h"
#include "MainWindow/statusToolbarWidget.h"
#include "WidgetDataFrame/panelDataFrameWidget.h"
#include "WidgetMap2D/panelMap2DWidget.h"
#include "WidgetMap2D/panellocalmapwidget.h"
#include "WidgetMap2D/maptoolbar.h"
#include "WidgetGCSCmd/panelCmdWidget.h"
#include "WidgetUAS/panelUASWidget.h"
#include "WidgetFPD/panelFPDWidget.h"
#include "WidgetPlot/panelPlotWidget.h"
#include "SerialPort/serialSettingsDialog.h"
#include "SerialPort/serialPortCommu.h"
#include "UdpPort/udpPortSettingDialog.h"
#include "UdpPort/udpCommu.h"
#include "Shared/dataProtocol.h"
#include "Shared/dataStructureDefine.H"
#include "Shared/messageIDDefine.h"
#include "DialogCfg/firmwareUupdateDialog.h"
#include "DialogWP/waypointDialog.h"
#include "DialogCfg/dialogconfigure.h"
#include "MutirotorsCfg/multiCenterDialog.h"
#include "RecordData/recorddialog.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();   
    
signals:
    void signal_cmdOutput(quint8 sysid,quint8 compid, quint8 msgid, const quint8 *packet, quint8 length);
    
public slots:    
    void slot_fromjava(QString lng,QString lat);
    void slot_setlight(int flag);
    void slot_setsendbutton(bool flag);
private slots:
    void slot_enableCmdEchoOK(quint8 idx);
    
    void slot_SerialPortHandleError(QSerialPort::SerialPortError error); 
    void slot_menu_action(quint8 pID, quint8 cID);
    
    void slot_checkWindowsMenu(int idx); 
    void slot_hideRightWidget();
    void slot_hideMapToolbarButton();
    void slot_showMapToolbarButton();
    void slot_MaptoolTOJava(int idx);
    void slot_addToJava();
    
    void slot_setPrintText(QString text,QColor color);
    void slot_RealtimeDisplay();
    void slot_playbackset(int opt);
    void slot_setactiveseqid(quint8 seqid);
    
protected:
    virtual void paintEvent(QPaintEvent *event);

private:
    void closeEvent(QCloseEvent *e);
    
    void initCentralWidget();
    void initToolBar();    
    void initChildDialog();
    void initCommunitcation();        
    void initSignal2Slot();    
       
    bool openSerialPort();
    void closeSerialPort();
    bool openUdpPort();
    void closeUdpPort();

    bool openWaypointLoad();    
    void openFirmwareUpdate();

private:
    Ui::MainWindow *ui;
    quint8                 active_seqid;
    QStackedWidget         *p_centralStack;      //主界面
    QMenuToolbarWidget     *p_menuToolbar;       //菜单工具条
    QStatusToolbarWidget   *p_statusToolbar;     //显示工具条    
    QMaptoolbar            *p_maptoolbar;        //地图工具按钮条
    QPushButton            *p_mapbutton;         //隐藏地图工具按钮条
    QPushButton            *p_rightwidget;       //隐藏右边
    
    QStackedWidget         *p_mapCentralStack;   //地图窗口容器
    QPanellocalmapWidget   *p_localPicture;      //本地图片界面
    QPanelMap2DWidget      *p_mapWidget;         //数字地图界面
    
    QPanelPlotWidget       *p_plotWidget;        //绘图界面   
    QPanelFPDWidget        *p_FPDWidget;         //平显
    QPanelUASWidget        *p_UASWidget;         //系统hearbeat信息
    QPanelDataFrameWidget  *p_dataFrameWidget;   //协议帧显示界面
    QTextBrowser           *p_textBrowserWidget; //文本信息窗口
    QPanelCmdWidget        *p_cmdWidget;         //指令界面    
    
    QDialogConfigure       *p_configureDlg;      //参数配置.直升机
    multiCenterDialog      *p_multiCenterDialog; //参数配置.多旋翼
    QWaypointDialog        *p_waypointDesignDlg; //航线设计
    QFirmwareUpdateDialog  *p_firmwarwUpdate;    //固件升级对话框

    QDataProtocol          *p_dataProtocol;      //通信协议
    QSerialPort            *p_serialPort;        //串口变量
    QSerialPortCommu       *p_serialPortCommu;   //串口收发功能模块
    QSerialSettingsDialog  *p_serialConfigDlg;   //串口设置界面
    QUdpCommu              *p_udpPortCommu;      //网络收发功能模块
    QUdpPortSettingDialog  *p_udpConfigDlg;      //网络设置界面
    QRecordDialog          *p_recordDlg;         //数据回放界面

    QTimer                 *p_realTimer;         //定时器变量    
    quint8                  m_activeNumofUAS;    //当前激活的飞机编号
    quint8                  m_runMode;           //运行模式
    quint8                  m_mapMode;           //地图模式
    bool                    isOpenCom;           
    bool                    isRecordData;
    bool                    isReplayData;
    bool                    isHeliCfg;
    bool                    isMutiCfg;
    bool                    isLoadWP;

};

#endif // MAINWINDOW_H
