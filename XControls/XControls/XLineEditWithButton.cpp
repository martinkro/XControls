#include "XLineEditWithButton.h"

#include "XPushButton.h"
#include <QLineEdit>

#include <QHBoxLayout>

XLineEditWithButton::XLineEditWithButton(QWidget* parent) :
    XWidget(parent)
{
    pathLineEdit = new QLineEdit(this);
    pathLineEdit->setObjectName("path");
    pathButton = new XPushButton;
    pathButton->setObjectName("path");
    pathLineEdit->setTextMargins(10, 1, 10+33, 1);

    auto hbox = new QHBoxLayout;
    hbox->setContentsMargins(1, 1, 10, 1);
    hbox->setSpacing(0);
    hbox->addWidget(pathButton, 0, Qt::AlignRight | Qt::AlignVCenter);
    pathLineEdit->setLayout(hbox);

    auto main = new QHBoxLayout;
    main->addWidget(pathLineEdit);
    setLayout(main);
}