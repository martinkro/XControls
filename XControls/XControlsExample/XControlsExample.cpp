#include "XControlsExample.h"
#include <QLabel>
#include <QVBoxLayout>

const int MAIN_WINDOW_WIDTH = 960;
const int MAIN_WINDOW_HEIGHT = 600;
XControlsExample::XControlsExample(QWidget *parent)
    : QMainWindow(parent)
{
    QLabel* testLabel = new QLabel(tr("Test"));

    auto layoutCenter = new QVBoxLayout;
    layoutCenter->setContentsMargins(0, 0, 0, 0);
    layoutCenter->setSpacing(0);
    layoutCenter->addWidget(testLabel);

    QWidget* center = new QWidget;
    center->setObjectName("center");
    center->setLayout(layoutCenter);
    setCentralWidget(center);

    setWindowTitle(tr("XControlsExample"));
    resize(MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT);
}
