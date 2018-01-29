#include "FixedTableModel.h"

void populateData(QList<FixedTableItem>& dataSet)
{
    FixedTableItem item;
    item.name = QObject::tr("TEST");
    item.downloadProgress = 10;
    item.uploadProgress = 50;
    item.buttonType = FixedTableItem::Browser;

    FixedTableItem item1 = item;
    FixedTableItem item2 = item;
    item2.buttonType = FixedTableItem::Cancel;
    item2.downloadProgress = 60;
    FixedTableItem item3 = item;
    item3.buttonType = FixedTableItem::Download;
    item3.downloadProgress = 100;

    dataSet.append(item1);
    dataSet.append(item2);
    dataSet.append(item3);
}

FixedTableModel::FixedTableModel(QObject* parent):
    QAbstractTableModel(parent)
{
    populateData(dataSet);
}

int FixedTableModel::rowCount(const QModelIndex& parent) const
{
    return dataSet.size();
}


int FixedTableModel::columnCount(const QModelIndex& parent) const
{
    return headerDataSet.size();
}

QVariant FixedTableModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid()) return QVariant();

    int col = index.column();
    const FixedTableItem& item = dataSet.value(index.row());
    if (col == FixedTableColName::COL_NAME)
    {
        if (role == Qt::DisplayRole)
        {
            return item.name;
        }
    }
    else if (col == FixedTableColName::COL_PROGRESS_DOWNLOAD)
    {
        if (role == Qt::DisplayRole)
        {
            return item.downloadProgress;
        }
    }
    else if (col == FixedTableColName::COL_PROGRESS_UPLOAD)
    {
        if (role == Qt::DisplayRole)
        {
            return item.uploadProgress;
        }
    }
    else if (col == FixedTableColName::COL_BUTTON)
    {
        if (role == Qt::DisplayRole)
        {
            return item.buttonType;
        }
    }

    return QVariant();
}
QVariant FixedTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal)
    {
        if (role == Qt::DisplayRole)
        {
            return headerDataSet.value(section);
        }
    }
    return QAbstractTableModel::headerData(section, orientation, role);
}

Qt::ItemFlags FixedTableModel::flags(const QModelIndex &index) const
{
    if (!index.isValid()) {
        return QAbstractTableModel::flags(index);
    }

    Qt::ItemFlags flags = QAbstractTableModel::flags(index);
    flags &= ~Qt::ItemIsSelectable;
    return flags;
}