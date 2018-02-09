#pragma once

#include "xcontrols_global.h"
#include "XWidget.h"

class XCONTROLS_EXPORT XFramelessWindow:public XWidget
{
    Q_OBJECT
public:
    explicit XFramelessWindow(QWidget* parent = 0);

public:
    void setTitleBarHeight(int h) { titleBarHeight = h; }

protected:
    virtual void paintEvent(QPaintEvent* event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);

    bool nativeEvent(const QByteArray &eventType, void *message, long *result);

private:
    bool isPressed;
    QPoint currentPos;
    int titleBarHeight;
};