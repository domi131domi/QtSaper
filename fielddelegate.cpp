#include "fielddelegate.h"
#include <iostream>

void FieldDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option,
                         const QModelIndex &index) const
{
    if (index.data().canConvert<Field>())
    {
        Field field = qvariant_cast<Field>(index.data());


        if (option.state & QStyle::State_Selected)
            painter->fillRect(option.rect, option.palette.highlight());
        if(field.state == FieldState::unrevieled)
        {
            if(!UNREVIELED_IMG.isNull())
                painter->drawImage(QRect(option.rect.x(), option.rect.y(), option.rect.width(), option.rect.height()), UNREVIELED_IMG);
        }
        else if(field.state == FieldState::flag)
        {
            if(!FLAG_IMG.isNull())
                painter->drawImage(QRect(option.rect.x(), option.rect.y(), option.rect.width(), option.rect.height()), FLAG_IMG);
        }
        else if(field.isBomb)
        {
            if(!BOMB_IMG.isNull())
                painter->drawImage(QRect(option.rect.x(), option.rect.y(), option.rect.width(), option.rect.height()), BOMB_IMG);
        }
        else if(field.nextToBombs == 0)
        {
            if(!REVIELED_EMPTY_IMG.isNull())
                painter->drawImage(QRect(option.rect.x(), option.rect.y(), option.rect.width(), option.rect.height()), REVIELED_EMPTY_IMG);
        }
        else if(field.nextToBombs == 1)
        {
            if(!REVIELED_1_IMG.isNull())
                painter->drawImage(QRect(option.rect.x(), option.rect.y(), option.rect.width(), option.rect.height()), REVIELED_1_IMG);
        }
        else if(field.nextToBombs == 2)
        {
            if(!REVIELED_2_IMG.isNull())
                painter->drawImage(QRect(option.rect.x(), option.rect.y(), option.rect.width(), option.rect.height()), REVIELED_2_IMG);
        }
        else if(field.nextToBombs == 3)
        {
            if(!REVIELED_3_IMG.isNull())
                painter->drawImage(QRect(option.rect.x(), option.rect.y(), option.rect.width(), option.rect.height()), REVIELED_3_IMG);
        }
        else if(field.nextToBombs == 4)
        {
            if(!REVIELED_4_IMG.isNull())
                painter->drawImage(QRect(option.rect.x(), option.rect.y(), option.rect.width(), option.rect.height()), REVIELED_4_IMG);
        }
        else if(field.nextToBombs == 5)
        {
            if(!REVIELED_5_IMG.isNull())
                painter->drawImage(QRect(option.rect.x(), option.rect.y(), option.rect.width(), option.rect.height()), REVIELED_5_IMG);
        }
        else if(field.nextToBombs == 6)
        {
            if(!REVIELED_6_IMG.isNull())
                painter->drawImage(QRect(option.rect.x(), option.rect.y(), option.rect.width(), option.rect.height()), REVIELED_6_IMG);
        }
        else if(field.nextToBombs == 7)
        {
            if(!REVIELED_7_IMG.isNull())
                painter->drawImage(QRect(option.rect.x(), option.rect.y(), option.rect.width(), option.rect.height()), REVIELED_7_IMG);
        }
        else if(field.nextToBombs == 8)
        {
            if(!REVIELED_8_IMG.isNull())
                painter->drawImage(QRect(option.rect.x(), option.rect.y(), option.rect.width(), option.rect.height()), REVIELED_8_IMG);
        }

    }
    else
    {
        QStyledItemDelegate::paint(painter, option, index);
    }
}

QSize FieldDelegate::sizeHint(const QStyleOptionViewItem &option,
                             const QModelIndex &index) const
{
    if (index.data().canConvert<Field>()) {
        Field field = qvariant_cast<Field>(index.data());
        return QSize(50,50);
    }
    return QStyledItemDelegate::sizeHint(option, index);
}

bool FieldDelegate::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index)
{
    if(((gameBoardModel*)model)->gameRunning)
    {
        if(event->type() == QEvent::MouseButtonRelease && ((QMouseEvent*)event)->button() == Qt::LeftButton)
        {
            if(model->data(index).value<Field>().state == FieldState::unrevieled)
                model->setData(index,FieldState::revieled);
        }
        if(event->type() == QEvent::MouseButtonRelease && ((QMouseEvent*)event)->button() == Qt::RightButton)
        {
            if(model->data(index).value<Field>().state == FieldState::unrevieled)
                model->setData(index,FieldState::flag);
            else if(model->data(index).value<Field>().state == FieldState::flag)
                model->setData(index,FieldState::unrevieled);
        }
    }
    return true;
}

Q_DECLARE_METATYPE(Field)
