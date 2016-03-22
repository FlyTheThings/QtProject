#include "panelMap2DWidget.h"
#include "ui_panelMap2DWidget.h"

QPanelMap2DWidget::QPanelMap2DWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QPanelMap2DWidget)
{
    ui->setupUi(this);

   ui->webView->settings()->setAttribute(QWebSettings::LocalStorageEnabled, true);
   ui->webView->settings()->enablePersistentStorage(QDir::currentPath());
   ui->webView->load(QUrl("file:///"+QDir::currentPath()+"/MapFile/DIYbaidumap.html"));
   ui->webView->show();

    QNetworkDiskCache *diskCache = new QNetworkDiskCache(this);

    QString location = QStandardPaths::writableLocation(QStandardPaths::GenericDataLocation) + "/data/organization/application";
    diskCache->setCacheDirectory(location);
    ui->webView->page()->networkAccessManager()->setCache(diskCache);
    
    connect(ui->webView->page()->mainFrame(),SIGNAL(javaScriptWindowObjectCleared()), this, SIGNAL(signal_addToJava()));


}

QPanelMap2DWidget::~QPanelMap2DWidget()
{
    delete ui;
}

void QPanelMap2DWidget::TOJavaScript(QString content)
{
    ui->webView->page()->currentFrame()->evaluateJavaScript(content);
}

void QPanelMap2DWidget::MaptoolTOJava(int sign)
{
    switch(sign) {
        case 1: TOJavaScript(QString("show_frame();"));    break;
        case 2: TOJavaScript(QString("hide_frame();"));    break;
        case 3: TOJavaScript(QString("show_line();"));     break;
        case 4: TOJavaScript(QString("hide_line();"));     break;
        case 5: TOJavaScript(QString("plane_follow();"));  break;
        case 6: TOJavaScript(QString("line_center();"));   break;
        case 7: TOJavaScript(QString("clear_timepath();"));break;
        case 8: TOJavaScript(QString("hide_timeline();")); break;
        case 9: TOJavaScript(QString("show_timeline();")); break;
        case 10:TOJavaScript(QString("frame_center();")); break;
        case 11:TOJavaScript(QString("plane_center();")); break;
        case 12:TOJavaScript(QString("clear_frame();"));   break;
    }
}

void QPanelMap2DWidget::addNametoJava(QString name, QObject * object)
{
    ui->webView->page()->mainFrame()->addToJavaScriptWindowObject(name,object);
}

