#ifndef FIELDDELEGATE_H
#define FIELDDELEGATE_H
#include <QStyledItemDelegate>
#include <QPainter>
#include "gameboardmodel.h"
#include "settings.h"
#include <QImage>
#include <QEvent>
#include <QMouseEvent>
#include <QTableView>

static QImage UNREVIELED_IMG("D:\\Projekty\\Saper\\UnrevieledField.png");
static QImage BOMB_IMG("D:\\Projekty\\Saper\\bomb.png");
static QImage FLAG_IMG("D:\\Projekty\\Saper\\flag.png");
static QImage REVIELED_EMPTY_IMG("D:\\Projekty\\Saper\\empty.png");
static QImage REVIELED_1_IMG("D:\\Projekty\\Saper\\1.png");
static QImage REVIELED_2_IMG("D:\\Projekty\\Saper\\2.png");
static QImage REVIELED_3_IMG("D:\\Projekty\\Saper\\3.png");
static QImage REVIELED_4_IMG("D:\\Projekty\\Saper\\4.png");
static QImage REVIELED_5_IMG("D:\\Projekty\\Saper\\5.png");
static QImage REVIELED_6_IMG("D:\\Projekty\\Saper\\6.png");
static QImage REVIELED_7_IMG("D:\\Projekty\\Saper\\7.png");
static QImage REVIELED_8_IMG("D:\\Projekty\\Saper\\8.png");

class FieldDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    using QStyledItemDelegate::QStyledItemDelegate;

    void paint(QPainter *painter, const QStyleOptionViewItem &option,
               const QModelIndex &index) const override;
    QSize sizeHint(const QStyleOptionViewItem &option,
                   const QModelIndex &index) const override;
    bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index) override;
private:
    float X,Y;
};

#endif // FIELDDELEGATE_H
