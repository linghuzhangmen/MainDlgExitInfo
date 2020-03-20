#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QCloseEvent>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    m_pDlg = new ExitTipsDlg;
    m_isClose = 1;

    connect(m_pDlg, &ExitTipsDlg::sig_NotCloseMainDlg, this, [this]()
    {
        m_isClose = 0;
    });

    connect(m_pDlg, &ExitTipsDlg::sig_CloseMainDlg, this, [this]()
    {
        m_isClose = 1;
    });
}

Widget::~Widget()
{
    delete ui;
}

//重写窗口关闭事件
void Widget::closeEvent(QCloseEvent* e)
{
//    QMessageBox::StandardButton rb = QMessageBox::warning(this, "title", "Do you want to close Dialog?", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
//    if(rb == QMessageBox::Yes)
//    {
//        //关闭
//        e->accept();
//    }
//    else
//    {
//        //不关闭
//        e->ignore();
//    }



    //没有勾选时才弹出
    if(m_pDlg->m_NextShow == 0)
    {
        m_pDlg->exec();
    }

    if(m_isClose == 0)
    {
        e->ignore();
    }
    else if(m_isClose == 1)
    {
        e->accept();
    }
}

