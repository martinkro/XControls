#pragma once

#include <QObject>
#include <QtTest/QtTest>

class TestGui : public QObject
{
    Q_OBJECT

public:
    TestGui(QObject *parent = 0);
    ~TestGui();

private slots:
    void testGui();
    void testGui2_data();
    void testGui2();
};
