#include "fielddelegate.h"

void FieldDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option,
                         const QModelIndex &index) const
{
    if (index.data().canConvert<FieldState>())
    {
        FieldState fieldState = qvariant_cast<FieldState>(index.data());


        if (option.state & QStyle::State_Selected)
            painter->fillRect(option.rect, option.palette.highlight());
        if(fieldState == FieldState::number_unrevieled)
        {
            if(!UNREVIELED_IMG.isNull())
                painter->drawImage(QRect(option.rect.x(), option.rect.y(), 50, 50), UNREVIELED_IMG);
        }
        else if(fieldState == FieldState::bomb_unrevieled)
            if(!BOMB_IMG.isNull())
                painter->drawImage(QRect(option.rect.x(), option.rect.y(), 50, 50), BOMB_IMG);

    }
    else
    {
        QStyledItemDelegate::paint(painter, option, index);
    }
}

QSize FieldDelegate::sizeHint(const QStyleOptionViewItem &option,
                             const QModelIndex &index) const
{
    if (index.data().canConvert<FieldState>()) {
        FieldState fieldState = qvariant_cast<FieldState>(index.data());
        return QSize(50,50);
    }
    return QStyledItemDelegate::sizeHint(option, index);
}

QWidget *FieldDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{

}

void FieldDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{

}

void FieldDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{

}

Q_DECLARE_METATYPE(FieldState)
