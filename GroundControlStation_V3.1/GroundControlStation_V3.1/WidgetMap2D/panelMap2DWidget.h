#ifndef _GOOGLEMAP_H
#define _GOOGLEMAP_H

#include <QWidget>
#include <QtWebKitWidgets/QWebFrame>
#include <QtWebKitWidgets/QWebView>
#include <QNetworkDiskCache>
#include <QDesktopServices>
#include <QToolButton>
#include <QDir>
#include <QEvent>
#include <QMenu>

namespace Ui {
    class QPanelMap2DWidget;
}

class QPanelMap2DWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QPanelMap2DWidget(QWidget *parent = 0);
    ~QPanelMap2DWidget();
    
    void TOJavaScript(QString content);
    void MaptoolTOJava(int sign);
    void addNametoJava(QString name, QObject * object);

signals:
    void signal_addToJava();


private:
    Ui::QPanelMap2DWidget *ui;
};

#endif // GOOGLEMAP_H
