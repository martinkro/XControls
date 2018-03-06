#pragma once

#include <QObject>
#include <QtTest/QtTest>

class TestQString : public QObject
{
    Q_OBJECT

public:
    TestQString(QObject *parent = 0);
    ~TestQString();

private slots:
    void toUpper();
    void toUpper_data();
};
