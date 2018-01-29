#ifndef XWIDGET_H
#define XWIDGET_H

#include "xcontrols_global.h"
#include <QWidget>

class XCONTROLS_EXPORT XWidget:public QWidget
{
    Q_OBJECT
public:
    explicit XWidget(QWidget* parent = 0);
    
protected:
    void paintEvent(QPaintEvent* event)override;
};


#endif