#pragma once

#include "xcontrols_global.h"
#include "XWidget.h"

class QLineEdit;
class XPushButton;

class XCONTROLS_EXPORT XLineEditWithButton:public XWidget
{
    Q_OBJECT
public:
    explicit XLineEditWithButton(QWidget* parent = 0);

private:
    QLineEdit* pathLineEdit;
    XPushButton* pathButton;
};