#include "TestQString.h"

TestQString::TestQString(QObject *parent)
    : QObject(parent)
{
}

TestQString::~TestQString()
{
}

void TestQString::toUpper()
{
    QString str = "Hello";
    QCOMPARE(str.toUpper(), QString("HELLO"));
}
