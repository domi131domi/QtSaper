#ifndef FIELDDELEGATE_H
#define FIELDDELEGATE_H
#include <QStyledItemDelegate>
#include <QPainter>
#include "gameboardmodel.h"
#include "settings.h"
#include <QImage>

static QImage UNREVIELED_IMG("D:\\Projekty\\Saper\\UnrevieledField.png");
static QImage BOMB_IMG("D:\\Projekty\\Saper\\bomb.png");

class FieldDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    using QStyledItemDelegate::QStyledItemDelegate;

    void paint(QPainter *painter, const QStyleOptionViewItem &option,
               const QModelIndex &index) const override;
    QSize sizeHint(const QStyleOptionViewItem &option,
                   const QModelIndex &index) const override;
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const override;
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const override;

};

#endif // FIELDDELEGATE_H
