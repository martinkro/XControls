#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_SampleGUI.h"

class SampleGUI : public QMainWindow
{
    Q_OBJECT

public:
    SampleGUI(QWidget *parent = Q_NULLPTR);

private:
    Ui::SampleGUIClass ui;
};
