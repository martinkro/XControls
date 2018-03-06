#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Sample2.h"

class Sample2 : public QMainWindow
{
    Q_OBJECT

public:
    Sample2(QWidget *parent = Q_NULLPTR);

private:
    Ui::Sample2Class ui;
};
