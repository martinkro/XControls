#pragma once

#include <QObject>

class TestXWidget:public QObject
{
    Q_OBJECT
public:
    explicit TestXWidget(QObject* parent = 0);
};