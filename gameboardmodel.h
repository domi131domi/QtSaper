#ifndef GAMEBOARDMODEL_H
#define GAMEBOARDMODEL_H

#include <QAbstractTableModel>
#include "settings.h"
#include <QRandomGenerator>

enum FieldState
{
    bomb_revieled,
    flag,
    bomb_unrevieled,
    number_unrevieled,
    number_revieled
};

struct Field
{
    FieldState state;
    int nextToBombs;
};

class gameBoardModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit gameBoardModel(QObject *parent = nullptr);

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

public slots:
    void changegDifficulty(GameDifficulty diff);
private:
    Field fields[MAX_HEIGHT][MAX_WIDTH];
    int width;
    int height;
    GameDifficulty actualDiff;
    void prepareGame(int h, int w, int bombs);
};

#endif // GAMEBOARDMODEL_H
