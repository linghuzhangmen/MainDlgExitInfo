#ifndef EXITTIPS_H
#define EXITTIPS_H

#include <QDialog>

namespace Ui {
class ExitTipsDlg;
}

class ExitTipsDlg : public QDialog
{
    Q_OBJECT

public:
    explicit ExitTipsDlg(QWidget *parent = nullptr);
    ~ExitTipsDlg();

    void    writeIni(QString value);
    QString readIni();

private slots:
    void on_btnNotSave_clicked();
    void on_btnSave_clicked();
    void SaveCheckValue();
    void on_btnClose_clicked();

private:
    Ui::ExitTipsDlg *ui;

signals:
    void sig_NotCloseMainDlg();
    void sig_CloseMainDlg();

public:
    int m_NextShow;
    QString m_IniPath;
};

#endif // EXITTIPS_H
