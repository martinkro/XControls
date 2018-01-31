#pragma once

#include <QWidget>

class QLineEdit;
class QMovie;
class QLabel;
class QPushButton;

class LineEditPage :public QWidget
{
    Q_OBJECT
public:
    explicit LineEditPage(QWidget* parent = 0);

private:
    QLineEdit* testLineEdit;
    QLabel* loadingLabel;
    QMovie* loadingMovie;
    QPushButton* startButton;
    QPushButton* stopButton;
};