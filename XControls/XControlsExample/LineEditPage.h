#pragma once

#include <QWidget>

class QLineEdit;

class LineEditPage :public QWidget
{
    Q_OBJECT
public:
    explicit LineEditPage(QWidget* parent = 0);

private:
    QLineEdit* testLineEdit;
};