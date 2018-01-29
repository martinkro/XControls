#pragma once

#include <QPushButton>

class XPushButton:public QPushButton
{
    Q_OBJECT
public:
    explicit XPushButton(QWidget *parent = Q_NULLPTR);
    explicit XPushButton(const QString &text, QWidget *parent = Q_NULLPTR);
    XPushButton(const QIcon& icon, const QString &text, QWidget *parent = Q_NULLPTR);

public slots:
    void setEnabled(bool);
    void setDisabled(bool);
};