#ifndef UPDATER_H
#define UPDATER_H

#include "XControls/XWidget.h"

class QProgressBar;
class Updater : public XWidget
{
    Q_OBJECT

public:
    Updater(QWidget *parent = Q_NULLPTR);

private:
    QProgressBar* progress;
};

#endif
