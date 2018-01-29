#include "XWidget.h"
#include <QStyleOption>
#include <QStylePainter>

XWidget::XWidget(QWidget* parent) :
    QWidget(parent)
{

}

void XWidget::paintEvent(QPaintEvent*)
{
    QStylePainter p(this);
    QStyleOption opt;
    opt.initFrom(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}