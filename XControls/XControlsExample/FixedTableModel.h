#pragma once

#include <QAbstractTableModel>

enum FixedTableColName {
    COL_NAME = 0,
    COL_PROGRESS_DOWNLOAD,
    COL_PROGRESS_UPLOAD,
    COL_BUTTON,
};

struct FixedTableItem
{
    QString name;
    int downloadProgress;
    int uploadProgress;
    int buttonType;

    enum Type{Browser,Cancel,Download};
};

class FixedTableModel:public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit FixedTableModel(QObject* parent = 0);

    int rowCount(const QModelIndex& parent) const;
    int columnCount(const QModelIndex& parent) const;
    QVariant data(const QModelIndex& index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;

private:
    QList<FixedTableItem> dataSet;
    const QStringList headerDataSet = { tr("Name"),tr("Progress"),tr("Progress"), tr("Button") };
};