#-------------------------------------------------
#
# Project created by QtCreator 2015-06-30T10:08:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets serialport webkitwidgets printsupport svg network

TARGET = NewGroundStation
TEMPLATE = app

SOURCES +=  MainWindow/main.cpp \
    WidgetDataFrame/panelDataFrameWidget.cpp \
    WidgetFPD/qfi_PFD.cpp \
    WidgetFPD/panelFPDWidget.cpp \
    WidgetGCSCmd/waypointCmdDialog.cpp \
    WidgetGCSCmd/speedCmdDialog.cpp \
    WidgetGCSCmd/positionCmdDialog.cpp \
    WidgetGCSCmd/panelCmdWidget.cpp \
    WidgetMap2D/panelMap2DWidget.cpp \
    WidgetUAS/panelUASWidget.cpp \
    WidgetUAS/multiUASForm.cpp \
    WidgetPlot/qcustomplot.cpp \
    WidgetPlot/panelPlotWidget.cpp \
    MainWindow/menuToolbarWidget.cpp \
    MainWindow/statusToolbarWidget.cpp \
    MainWindow/mainWindow.cpp \
    SerialPort/serialSettingsDialog.cpp \
    SerialPort/serialPortCommu.cpp \
    UdpPort/udpPortSettingDialog.cpp \
    Shared/dataProtocol.cpp \
    UdpPort/udpCommu.cpp \
    DialogCfg/firmwareUupdateDialog.cpp \
    DialogWP/waypointDialog.cpp \
    DialogWP/waypointTabWidget.cpp \
    DialogCfg/swashplatewidget.cpp \
    DialogCfg/splashwidget.cpp \
    DialogCfg/selfflywidget.cpp \
    DialogCfg/rpmgyroWidget.cpp \
    DialogCfg/rcWidget.cpp \
    DialogCfg/installwidget.cpp \
    DialogCfg/fblrudwidget.cpp \
    DialogCfg/controlWidget.cpp \
    WidgetMap2D/panellocalmapwidget.cpp \
    WidgetMap2D/maptoolbar.cpp \
    MutirotorsCfg/multiCenterDialog.cpp \
    MutirotorsCfg/cfg.cpp \
    MutirotorsCfg/frameDialog.cpp \
    MutirotorsCfg/multiInstall.cpp \
    MutirotorsCfg/multiRC.cpp \
    DialogCfg/dialogconfigure.cpp \
    UdpPort/flightgearCom.cpp \
    UdpPort/flightgearCtrls.cpp \
    MutirotorsCfg/multicontrol.cpp \
    MutirotorsCfg/multianalogcfgwidget.cpp \
    MutirotorsCfg/multihmcsetwidget.cpp \
    MutirotorsCfg/multisplashwidget.cpp \
    DialogCfg/analogwidget.cpp \
    RecordData/recorddialog.cpp


HEADERS  += \
    WidgetDataFrame/panelDataFrameWidget.h \
    WidgetFPD/panelFPDWidget.h \
    WidgetFPD/qfi_PFD.h \
    WidgetGCSCmd/waypointCmdDialog.h \
    WidgetGCSCmd/speedCmdDialog.h \
    WidgetGCSCmd/positionCmdDialog.h \
    WidgetGCSCmd/panelCmdWidget.h \
    WidgetMap2D/panelMap2DWidget.h \
    WidgetUAS/panelUASWidget.h \
    WidgetUAS/multiUASForm.h \
    WidgetPlot/panelPlotWidget.h \
    WidgetPlot/qcustomplot.h \
    MainWindow/menuToolbarWidget.h \
    MainWindow/statusToolbarWidget.h \
    MainWindow/mainWindow.h \
    Shared/checksum.h \
    SerialPort/serialPortCommu.h \
    SerialPort/serialSettingsDialog.h \
    UdpPort/udpPortSettingDialog.h \
    Shared/dataProtocol.h \
    UdpPort/udpCommu.h \
    DialogCfg/firmwareUupdateDialog.h \
    DialogWP/waypointDialog.h \
    Shared/dataStructureDefine.H \
    DialogWP/waypointTabWidget.h \
    Shared/messageIDDefine.h \
    Shared/buff.h \
    DialogCfg/swashplatewidget.h \
    DialogCfg/splashwidget.h \
    DialogCfg/selfflywidget.h \
    DialogCfg/rpmgyroWidget.h \
    DialogCfg/rcWidget.h \
    DialogCfg/installwidget.h \
    DialogCfg/fblrudwidget.h \
    DialogCfg/controlWidget.h \
    WidgetMap2D/panellocalmapwidget.h \
    WidgetMap2D/maptoolbar.h \
    MutirotorsCfg/multiCenterDialog.h \
    MutirotorsCfg/cfg.h \
    MutirotorsCfg/frameDialog.h \
    MutirotorsCfg/multiInstall.h \
    MutirotorsCfg/multiRC.h \
    DialogCfg/dialogconfigure.h \
    UdpPort/flightgearCom.h \
    UdpPort/flightgearCtrls.h \
    MutirotorsCfg/multicontrol.h \
    MutirotorsCfg/multianalogcfgwidget.h \
    MutirotorsCfg/multihmcsetwidget.h \
    MutirotorsCfg/multisplashwidget.h \
    DialogCfg/analogwidget.h \
    RecordData/recorddialog.h

FORMS    += \
    WidgetDataFrame/panelDataFrameWidget.ui \
    WidgetFPD/panelFPDWidget.ui \
    WidgetGCSCmd/speedCmdDialog.ui \
    WidgetGCSCmd/positionCmdDialog.ui \
    WidgetGCSCmd/panelCmdWidget.ui \
    WidgetGCSCmd/waypointCmdDialog.ui \
    WidgetMap2D/panelMap2DWidget.ui \
    WidgetUAS/multiUASForm.ui \
    WidgetUAS/panelUASWidget.ui \
    WidgetPlot/panelPlotWidget.ui \
    MainWindow/menuToolbarWidget.ui \
    MainWindow/statusToolbarWidget.ui \
    MainWindow/mainWindow.ui \
    SerialPort/serialPortCommu.ui \
    SerialPort/serialSettingsDialog.ui \
    UdpPort/udpPortSettingDialog.ui \
    DialogCfg/firmwareUupdateDialog.ui \
    DialogWP/waypointDialog.ui \
    DialogWP/waypointTabWidget.ui \
    DialogCfg/swashplatewidget.ui \
    DialogCfg/splashwidget.ui \
    DialogCfg/selfflywidget.ui \
    DialogCfg/rpmgyroWidget.ui \
    DialogCfg/rcWidget.ui \
    DialogCfg/installwidget.ui \
    DialogCfg/fblrudwidget.ui \
    DialogCfg/controlWidget.ui \
    WidgetMap2D/maptoolbar.ui \
    WidgetMap2D/panellocalmapwidget.ui \
    MutirotorsCfg/framDialog.ui \
    MutirotorsCfg/multiRC.ui \
    MutirotorsCfg/multiCenterDialog.ui \
    MutirotorsCfg/cfg.ui \
    MutirotorsCfg/multiInstall.ui \
    DialogCfg/dialogconfigure.ui \
    MutirotorsCfg/multicontrol.ui \
    MutirotorsCfg/multianalogcfgwidget.ui \
    MutirotorsCfg/multihmcsetwidget.ui \
    MutirotorsCfg/multisplashwidget.ui \
    DialogCfg/analogwidget.ui \
    RecordData/recorddialog.ui

RESOURCES += \
    qfi.qrc

OTHER_FILES += \
    images/device1.jpg \
    images/device.png \
    images/device2.png \
    images/devicedir.png \
    images/devicepos.png \
    images/deviceset.png \
    images/dir1.png \
    images/dir2.png \
    images/donate.png \
    images/end.png \
    images/flightdata.png \
    images/flightplanner.png \
    images/H1.png \
    images/H3.png \
    images/H4.png \
    images/H12.png \
    images/H32.png \
    images/H41.png \
    images/H42.png \
    images/H140.png \
    images/H1402.png \
    images/hardwareconfig.png \
    images/HE3.png \
    images/HE32.png \
    images/heli.png \
    images/heli_off.png \
    images/heli_on.png \
    images/helicopter.png \
    images/hou.png \
    images/HR3.png \
    images/HR32.png \
    images/qian.png \
    images/set.png \
    images/simulation.png \
    images/yes.png \
    images/you.png \
    images/zuo.png \
    images/go-previous.svg \
    images/go-next.svg \
    images/go-down.svg \
    images/go-up.svg \
    images/background.jpg \
    images/pause.png \
    images/play.png \
    images/ahead.png \
    images/back.png
