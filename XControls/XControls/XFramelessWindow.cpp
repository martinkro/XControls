#include "XFramelessWindow.h"

#include <QMouseEvent>
#include <windows.h>
#include <windows.h>
#include <WinUser.h>
#include <windowsx.h>
#include <dwmapi.h>
#include <objidl.h> // Fixes error C2504: 'IUnknown' : base class undefined
#include <gdiplus.h>
#include <GdiPlusColor.h>
#pragma comment (lib,"Dwmapi.lib") // Adds missing library, fixes error LNK2019: unresolved external symbol __imp__DwmExtendFrameIntoClientArea
#pragma comment (lib,"user32.lib")

XFramelessWindow::XFramelessWindow(QWidget* parent) :
    XWidget(parent),
    isPressed(false),
    currentPos(0,0),
    titleBarHeight(100)
{
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());
    HWND hwnd = (HWND)this->winId();
    DWORD style = ::GetWindowLong(hwnd, GWL_STYLE);
    ::SetWindowLong(hwnd, GWL_STYLE, style | WS_MAXIMIZEBOX | WS_THICKFRAME | WS_CAPTION);
}

void XFramelessWindow::paintEvent(QPaintEvent* event)
{
    XWidget::paintEvent(event);
}

void XFramelessWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (this->isPressed)
    {
        QPoint point = event->pos();
        move(point - currentPos + pos());
    }

}
void XFramelessWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        this->currentPos = event->pos();
        if (this->currentPos.y() < titleBarHeight)
        {
           this->isPressed = true;
        }
    }
}
void XFramelessWindow::mouseReleaseEvent(QMouseEvent *event)
{
    this->isPressed = false;
}

bool XFramelessWindow::nativeEvent(const QByteArray &eventType, void *message, long *result)
{
    MSG* msg = (MSG *)message;
    switch (msg->message)
    {
    case WM_NCCALCSIZE:
        *result = 0;
        return true;
    default:
        return XWidget::nativeEvent(eventType, message, result);
    }
}