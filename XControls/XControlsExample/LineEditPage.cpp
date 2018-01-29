#include "LineEditPage.h"
#include "XControls/XLineEditWithButton.h"

#include <QLineEdit>
#include <QVBoxLayout>
#include <QAction>

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

    auto main = new QVBoxLayout;
    main->addWidget(testLineEdit, 0, Qt::AlignHCenter);
    main->addWidget(pathLineEdit, 0, Qt::AlignHCenter);
    setLayout(main);
}