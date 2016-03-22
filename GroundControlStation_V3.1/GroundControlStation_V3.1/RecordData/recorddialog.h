#ifndef RECORDDIALOG_H
#define RECORDDIALOG_H

#include <QDialog>

namespace Ui {
class QRecordDialog;
}

class QRecordDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QRecordDialog(QWidget *parent = 0);
    ~QRecordDialog();
    
    void setvalue(int a);

signals:
    void signal_setplayback(int opt);
    void signal_valuechanged(int b);
    void signal_sliderchanged(int val);
    
private slots:
    void buttoncliked(int button);
    void playchecked(bool check);
    
private:
    Ui::QRecordDialog *ui;
};

#endif // RECORDDIALOG_H
