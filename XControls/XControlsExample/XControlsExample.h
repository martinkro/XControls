#pragma once

#include <QtWidgets/QMainWindow>
#include <QComboBox>
#include <QLabel>
#include <QPushButton>
#include <QStackedWidget>
#include <QTableView>

class LineEditPage;

class XControlsExample : public QMainWindow
{
    Q_OBJECT

public:
    XControlsExample(QWidget *parent = Q_NULLPTR);

protected:
    void paintEvent(QPaintEvent* e)override;

private:
    void createMiddleWidget();
    void createTableView();

private slots:
    void onCurrentPageChanged(int index);

private:
    QComboBox* typeComboBox;
    QStackedWidget* pageManager;

    QTableView* fixedTableView;
    QLabel* testLabel;

    LineEditPage* lineeditPage;

};
