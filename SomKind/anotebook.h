#ifndef ANOTEBOOK_H
#define ANOTEBOOK_H

#include <QMainWindow>

class QAction;
class ANoteBook;
class QMenu;
class QPlainTextEdit;

class ANoteBook : public QMainWindow
{
    Q_OBJECT

public:
    ANoteBook();
    ~ANoteBook();

protected:
    void closeEvent(QCloseEvent *) Q_DECL_OVERRIDE;

private slots:
    void newFile();
    void open();
    bool save();
    bool saveAs();
    void about();
    void documentWasModified();

private:
    void createActions();
    void createMenus();
    void createToolBars();
    void createStatusBar();
    void readSettings();
    void writeSettings();
    bool maybeSave();
    void loadFile(const QString &fileName);
    bool saveFile(const QString &filename);
    void setCurrentFile(const QString &filename);
    QString strippedName(const QString &fullFileName);

    QPlainTextEdit *textEdit;
    QString curFile;

    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *helpMenu;
    QToolBar *fileToolBar;
    QToolBar *editToolBar;
    QAction  *newAct;
    QAction  *openAct;
    QAction  *saveAct;
    QAction  *saveAsAct;
    QAction  *exitAct;
    QAction  *cutAct;
    QAction  *copyAct;
    QAction  *pasteAct;
    QAction  *aboutAct;
    QAction  *aboutQtAct;
};

#endif // ANOTEBOOK_H
