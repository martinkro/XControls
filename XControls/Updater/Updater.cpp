#include "Updater.h"

#include <QProgressBar>
#include <QVBoxLayout>

Updater::Updater(QWidget *parent)
    : XWidget(parent)
{
    progress = new QProgressBar(this);
    progress->setObjectName("progress");
    progress->setFixedWidth(250);
    progress->setFixedHeight(12);
    progress->setRange(0, 100);
    progress->setValue(70);
    progress->setTextVisible(false);

    auto main = new QVBoxLayout(this);
    main->addWidget(progress, 0, Qt::AlignCenter);
    setLayout(main);

    setFixedSize(400, 300);
}
