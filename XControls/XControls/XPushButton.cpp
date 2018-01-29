#include "XPushButton.h"


XPushButton::XPushButton(QWidget *parent):
    QPushButton(parent)
{
    setCursor(Qt::PointingHandCursor);
}
XPushButton::XPushButton(const QString &text, QWidget *parent):
    QPushButton(text,parent)
{
    setCursor(Qt::PointingHandCursor);
}
XPushButton::XPushButton(const QIcon& icon, const QString &text, QWidget *parent):
    QPushButton(icon,text,parent)
{
    setCursor(Qt::PointingHandCursor);
}

void XPushButton::setEnabled(bool value)
{
    QPushButton::setEnabled(value);
    if (value)
    {
        setCursor(Qt::PointingHandCursor);
    }
    else
    {
        setCursor(Qt::ArrowCursor);
    }
}
void XPushButton::setDisabled(bool value)
{
    QPushButton::setDisabled(value);
    if (!value)
    {
        setCursor(Qt::PointingHandCursor);
    }
    else
    {
        setCursor(Qt::ArrowCursor);
    }
}