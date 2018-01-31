#include "LineEditPage.h"
#include "XControls/XLineEditWithButton.h"

#include <QLineEdit>
#include <QVBoxLayout>
#include <QAction>
#include <QPushButton>
#include <QLabel>
#include <QMovie>

LineEditPage::LineEditPage(QWidget* parent) :
    QWidget(parent)
{
    testLineEdit = new QLineEdit;
    testLineEdit->setReadOnly(true);
    QAction* action = testLineEdit->addAction(QIcon(":/images/folder"), QLineEdit::TrailingPosition);
    action->setToolTip(tr("Test Action"));
    testLineEdit->setToolTip(tr("Test LineEdit"));
    testLineEdit->setCursor(Qt::PointingHandCursor);

    XLineEditWithButton* pathLineEdit = new XLineEditWithButton;

    loadingLabel = new QLabel;
    loadingMovie = new QMovie(this);

    startButton = new QPushButton(tr("Start"));
    stopButton = new QPushButton(tr("Stop"));

    auto layoutButton = new QHBoxLayout;
    layoutButton->addWidget(startButton);
    layoutButton->addWidget(stopButton);

    auto main = new QVBoxLayout;
    main->addWidget(testLineEdit, 0, Qt::AlignHCenter);
    main->addWidget(pathLineEdit, 0, Qt::AlignHCenter);
    main->addWidget(loadingLabel, 0, Qt::AlignHCenter);
    main->addLayout(layoutButton);
    setLayout(main);

    loadingMovie->setFileName("images/loading/ajax-loader_3.gif");
    loadingLabel->setMovie(loadingMovie);

    connect(startButton, &QPushButton::clicked, [=]() {loadingMovie->start(); });
    connect(stopButton, &QPushButton::clicked, [=]() {loadingMovie->stop(); });

    //setCursor(Qt::ArrowCursor);
}