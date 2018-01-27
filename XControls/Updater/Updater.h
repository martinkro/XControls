#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Updater.h"

class Updater : public QMainWindow
{
    Q_OBJECT

public:
    Updater(QWidget *parent = Q_NULLPTR);

private:
    Ui::UpdaterClass ui;
};
