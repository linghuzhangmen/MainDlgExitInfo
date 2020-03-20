#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "exittipsdlg.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void closeEvent(QCloseEvent* e);

private:
    Ui::Widget *ui;
    int m_isClose;
    ExitTipsDlg *m_pDlg;
};
#endif // WIDGET_H
