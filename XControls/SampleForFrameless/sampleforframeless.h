#pragma once

#include "framelesswindow.h"

#include <QtWidgets/QWidget>


class SampleForFrameless : public CFramelessWindow
{
    Q_OBJECT

public:
    SampleForFrameless(QWidget *parent = Q_NULLPTR);

private:
};
