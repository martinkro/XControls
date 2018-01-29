#include "FixedTableDelegate.h"
#include "FixedTableModel.h"

#include <QPainter>
#include <QDebug>

FixedTableDelegate::FixedTableDelegate(QObject* parent)
    :QStyledItemDelegate(parent) {

}

void FixedTableDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index)const
{
    int col = index.column();
    qDebug() << "fixed:" << index.row() << "|" << index.column() << ":" << option.rect;

    if (col == FixedTableColName::COL_PROGRESS_DOWNLOAD)
    {
            
        int progress = index.data(Qt::DisplayRole).toInt();
        QString text = tr("Download %1%").arg(progress);
        QColor textColor(0x4886ff);
        QColor chunkColor(0x85b1e3);
        return paintProgressBar(painter, option, index, textColor, chunkColor, text, progress);
    }
    else if (col == FixedTableColName::COL_BUTTON)
    {
        int buttonType = index.data(Qt::DisplayRole).toInt();
        QColor textColor(0x71ace9);
        QColor borderColor(0x71ace9);
        QColor hoverTextColor(Qt::white);
        QColor hoverBorderColor(0x71ace9);

        if (buttonType == FixedTableItem::Cancel)
        {
            textColor = QColor(0xff4848);
            borderColor = QColor(0xff4848);
            hoverTextColor = QColor(Qt::white);
            hoverBorderColor = QColor(0xf06060);
        }
        else if (buttonType == FixedTableItem::Browser)
        {
            // download
        }
        paintButton(painter, option, index, textColor, borderColor, hoverTextColor, hoverBorderColor);
        
    }
    else
    {
        QStyledItemDelegate::paint(painter, option, index);
    }


}

QSize FixedTableDelegate::sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const
{
    QSize size = QStyledItemDelegate::sizeHint(option, index);
    int padding_h = 1;
    int padding_w = 1;
    size.setHeight(35 + padding_h);
    size.setWidth(colWidths[index.column()]);
    return size;
}

void FixedTableDelegate::paintButton(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index,
    const QColor textColor,
    const QColor borderColor,
    const QColor hoverTextColor,
    const QColor hoverBorderColor)const
{
    if (!index.isValid()) return;
    QStyleOptionViewItem opt = option;
    initStyleOption(&opt, index);
    QRect area(0, 0, 51, 28);
    area.moveCenter(opt.rect.center());

    QStringList texts = { tr("Browser"),tr("Cancel"),tr("Download") };
    QString text = texts[index.data(Qt::DisplayRole).toInt()];

    qDebug() << "2:" << opt.state;
    if (opt.state & QStyle::State_MouseOver)
    {
        //qDebug() << "2:" << option.state;
        //qDebug() << "2:" << option.checkState;
        painter->save();
        //painter->fillRect(area, QColor(0xf06060));
        painter->setRenderHint(QPainter::Antialiasing);
        QPainterPath path;
        path.addRoundedRect(area, 1, 1);
        QPen pen(hoverBorderColor, 1);
        painter->setPen(pen);
        painter->fillPath(path, hoverBorderColor);
        painter->drawPath(path);
        painter->restore();
        painter->save();

        QFont textFont = painter->font();
        textFont.setPixelSize(12);
        QPen textPen = painter->pen();
        textPen.setColor(hoverTextColor);
        painter->setPen(textPen);
        painter->setFont(textFont);
        painter->drawText(area, Qt::AlignCenter, text);
        painter->restore();
    }
    else
    {
        //qDebug() << "3:" << option.state;
        //qDebug() << "3:" << option.checkState;
        painter->save();
        QPen pen(borderColor, 1);
        painter->setPen(pen);
        painter->drawRoundedRect(area, 1, 1);
        painter->restore();

        painter->save();
        QFont textFont = painter->font();
        textFont.setPixelSize(12);
        QPen textPen = painter->pen();
        textPen.setColor(textColor);
        painter->setPen(textPen);
        painter->setFont(textFont);
        painter->drawText(area, Qt::AlignCenter, text);
        painter->restore();
    }
}
void FixedTableDelegate::paintProgressBar(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index,
    QColor textColor,
    QColor chunkColor,
    const QString& text,
    int progress)const
{
    QRect area(0, 0, option.rect.width() - 2, option.rect.height() - 2);
    QPixmap pixmapMemory(area.width(), area.height());
    pixmapMemory.fill(Qt::transparent);
    QPainter painterMemory(&pixmapMemory);
    painterMemory.setRenderHint(QPainter::Antialiasing, true);
    //painterMemory.setCompositionMode(QPainter::CompositionMode_SourceOut);        // ok
    painterMemory.setCompositionMode(QPainter::CompositionMode_Xor);                // ok                                                                
    QRect rectMemory(0, 0, area.width(), area.height());

    // draw text
    //QColor color(0x4886ff);
    painterMemory.save();
    QFont textFont = painter->font();
    textFont.setPixelSize(12);
    QPen textPen = painter->pen();
    textPen.setColor(textColor);
    painterMemory.setPen(textPen);
    painterMemory.setFont(textFont);
    painterMemory.drawText(rectMemory, Qt::AlignCenter, text);
    painterMemory.restore();

    // chunk
    //QColor brushColor(0x85b1e3);
    painterMemory.save();
    QRect rectBackground = rectMemory;
    rectBackground.setWidth(area.width() * progress / 100);
    painterMemory.fillRect(rectBackground, chunkColor);
    painterMemory.restore();

    area.moveCenter(option.rect.center());
    painter->drawPixmap(area, pixmapMemory);
}