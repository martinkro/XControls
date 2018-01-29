#include "XControlsExample.h"
#include "FixedTableDelegate.h"
#include "FixedTableModel.h"

#include "LineEditPage.h"

#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QStringListModel>
#include <QHeaderView>
#include <QScrollBar>
#include <QDebug>

const int MAIN_WINDOW_WIDTH = 960;
const int MAIN_WINDOW_HEIGHT = 600;
XControlsExample::XControlsExample(QWidget *parent)
    : QMainWindow(parent)
{
   
    createMiddleWidget();

    // top
    QLabel* typeLabel = new QLabel(tr("Page Type:"));
    typeComboBox = new QComboBox;
    QStringList typeList;
    typeList << tr("QLabel") << tr("QTableView - Fixed") << tr("LineEdit");
    QStringListModel* typeModel = new QStringListModel(typeList);
    typeComboBox->setModel(typeModel);

    auto hbox = new QHBoxLayout;
    hbox->setContentsMargins(0, 0, 0, 0);
    hbox->setSpacing(0);
    hbox->addWidget(typeLabel);
    hbox->addWidget(typeComboBox, 1);
    QWidget* topWidget = new QWidget;
    topWidget->setObjectName("top");
    topWidget->setLayout(hbox);

    // center widget
    auto layoutCenter = new QVBoxLayout;
    layoutCenter->setContentsMargins(30, 15, 30, 15);
    layoutCenter->setSpacing(10);
    layoutCenter->addWidget(topWidget);
    layoutCenter->addWidget(pageManager);

    QWidget* center = new QWidget;
    center->setObjectName("center");
    center->setLayout(layoutCenter);
    setCentralWidget(center);

    setWindowTitle(tr("XControlsExample"));
    resize(MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT);

    connect(typeComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(onCurrentPageChanged(int)));
}

void XControlsExample::onCurrentPageChanged(int index)
{
    qDebug() << "current index:" << index;
    pageManager->setCurrentIndex(index);
}

void XControlsExample::createMiddleWidget()
{
    testLabel = new QLabel(tr("Test"));
    pageManager = new QStackedWidget;
    pageManager->setObjectName("middle");
    pageManager->addWidget(testLabel);

    createTableView();

    lineeditPage = new LineEditPage;
    pageManager->addWidget(lineeditPage);
}

void XControlsExample::createTableView()
{
    fixedTableView = new QTableView;
    fixedTableView->setObjectName("fixed");

    QVector<int> widths = { 40,80,40,80 };
    FixedTableModel* fixedModel = new FixedTableModel(fixedTableView);
    fixedTableView->setModel(fixedModel);

    FixedTableDelegate* fixedDelegate = new FixedTableDelegate(fixedTableView);
    fixedDelegate->setColWidths(widths);
    fixedTableView->setItemDelegate(fixedDelegate);

    for (int i = 0; i < fixedTableView->horizontalHeader()->count(); i++) {
        fixedTableView->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);
    }

    fixedTableView->verticalHeader()->hide();
    fixedTableView->horizontalHeader()->hide();
    fixedTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    fixedTableView->setSelectionBehavior(QAbstractItemView::SelectItems);
    fixedTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    fixedTableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    fixedTableView->horizontalScrollBar()->hide();
    //table->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    //fixedTableView->setFrameShape(QFrame::NoFrame);
    //fixedTableView->setShowGrid(false); //设置不显示格子线

    fixedTableView->resizeColumnsToContents();
    fixedTableView->resizeRowsToContents();

    pageManager->addWidget(fixedTableView);
}
