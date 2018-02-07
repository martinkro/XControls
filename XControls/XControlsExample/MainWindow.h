#pragma once

#include "XControls/XFramelessWindow.h"

class MainWindow:public XFramelessWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget* parent = 0);

protected:
    void paintEvent(QPaintEvent* event);
    void showEvent(QShowEvent* e)override;
    void changeEvent(QEvent* e) override;
};