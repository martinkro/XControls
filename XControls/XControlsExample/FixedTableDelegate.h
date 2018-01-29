#pragma once

#include <QStyledItemDelegate>

class FixedTableDelegate:public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit FixedTableDelegate(QObject* parent = 0);
    void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index)const;
    QSize sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const;

public:
    void setColWidths(const QVector<int>& widths) { colWidths = widths; }

private:
    void paintButton(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index,
        const QColor textColor,
        const QColor borderColor,
        const QColor hoverTextColor,
        const QColor hoverBorderColor)const;
    void paintProgressBar(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index,
        QColor textColor,
        QColor chunkColor,
        const QString& text,
        int progress)const;

private:
    QVector<int> colWidths;

};