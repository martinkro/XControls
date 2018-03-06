#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Sample1.h"

class Sample1 : public QMainWindow
{
    Q_OBJECT

public:
    Sample1(QWidget *parent = Q_NULLPTR);

private:
    Ui::Sample1Class ui;
};
