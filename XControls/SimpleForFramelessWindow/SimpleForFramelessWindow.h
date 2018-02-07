#pragma once

#include <QtWidgets/QWidget>
#include "ui_SimpleForFramelessWindow.h"

class SimpleForFramelessWindow : public QWidget
{
    Q_OBJECT

public:
    SimpleForFramelessWindow(QWidget *parent = Q_NULLPTR);

private:
    Ui::SimpleForFramelessWindowClass ui;
};
