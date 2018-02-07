#include "MainWindow.h"
#include <QPixmap>
#include <QBitmap>
#include <QPainter>
#include <QDebug>

MainWindow::MainWindow(QWidget* parent) :
    XFramelessWindow(parent)
{
    //QPixmap pixmap("images/background-2.png");
    //QPalette pal = palette();
    //pal.setBrush(backgroundRole(), QBrush(pixmap));
    ////pal.setColor(QPalette::Background, QColor(0x00, 0xff, 0x00, 0x00));
    //setPalette(pal);
    //setAutoFillBackground(true);

    setFixedSize(960, 600);
}

void MainWindow::paintEvent(QPaintEvent* event)
{
    qDebug() << "QPaintEvent";
    //QPainter p(this);
    //p.drawPixmap(this->rect(), QPixmap("images/bg.png"));
    XFramelessWindow::paintEvent(event);
}

void MainWindow::showEvent(QShowEvent* e)
{
    qDebug() << "QShowEvent";
}
void MainWindow::changeEvent(QEvent* e)
{
    qDebug() << "changeEvent";
}