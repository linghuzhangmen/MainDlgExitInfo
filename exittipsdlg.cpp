#include "exittipsdlg.h"
#include "ui_exittipsdlg.h"
#include <QSettings>

ExitTipsDlg::ExitTipsDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExitTipsDlg)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint);
    m_IniPath = "D:\\Qt_Project\\MessageBox\\config\\project.ini";

    QPixmap *pmp = new QPixmap("D:\\Qt_Project\\MessageBox\\img\\th.png");
    pmp->scaled(ui->label_img->size(), Qt::KeepAspectRatio);
    ui->label_img->setScaledContents(true);
    ui->label_img->setPixmap(*pmp);

    connect(ui->checkBox,&QCheckBox::clicked,this,&ExitTipsDlg::SaveCheckValue);

    if(readIni() == "1")
    {
        m_NextShow = 1;
    }
    else
    {
        m_NextShow = 0;
    }
}

ExitTipsDlg::~ExitTipsDlg()
{
    delete ui;
}

void ExitTipsDlg::on_btnNotSave_clicked()
{
    emit sig_CloseMainDlg();
    close();
}

void ExitTipsDlg::on_btnSave_clicked()
{
    /*

        其它操作代码

    */

    emit sig_CloseMainDlg();
    close();  
}

void ExitTipsDlg::writeIni(QString value)
{
    QSettings *configIniWrite = new QSettings(m_IniPath, QSettings::IniFormat);
    configIniWrite->setValue("/project/nextshow", value);

    //写入完成后删除指针
    delete configIniWrite;
}

QString ExitTipsDlg::readIni()
{
    QSettings *configIniRead = new QSettings(m_IniPath, QSettings::IniFormat);
    QString result = configIniRead->value("/project/nextshow").toString();

    //读入入完成后删除指针
    delete configIniRead;
    return result;
}

void ExitTipsDlg::SaveCheckValue()
{
    if(ui->checkBox->isChecked())
    {
        writeIni("1");
    }
    else
    {
        writeIni("0");
    }
}

void ExitTipsDlg::on_btnClose_clicked()
{
    emit sig_NotCloseMainDlg();  //在窗口关闭前抛信号
    this->close();
}
