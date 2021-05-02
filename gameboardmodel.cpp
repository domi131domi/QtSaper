#include "gameboardmodel.h"

gameBoardModel::gameBoardModel(QObject *parent) : QAbstractTableModel(parent)
{
    prepareGame(H_EASY, W_EASY, BOMBS_EASY);
    width = W_EASY;
    height = H_EASY;
}

QVariant gameBoardModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    return QVariant();
}

int gameBoardModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return height;
}

int gameBoardModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return width;
}

QVariant gameBoardModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    if(index.row() >= height || index.column() >= width)
        return QVariant();
    return fields[index.row()][index.column()].state;
}

void gameBoardModel::prepareGame(int h, int w, int bombs)
{
    for(int i=0; i < h; i++)
    {
        for(int e = 0; e < w; e++)
        {
            fields[i][e].state = FieldState::number_unrevieled;
        }
    }
    int x,y;
    for(int i = 0; i < bombs; i++)
    {
        x = QRandomGenerator::global()->generate()%h;
        y = QRandomGenerator::global()->generate()%w;
        while(fields[x][y].state == FieldState::bomb_unrevieled)
        {
            x = QRandomGenerator::global()->generate()%h;
            y = QRandomGenerator::global()->generate()%w;
        }
        fields[x][y].state = FieldState::bomb_unrevieled;
    }
}

void gameBoardModel::changegDifficulty(GameDifficulty diff)
{
    if(diff == GameDifficulty::EASY)
        prepareGame(H_EASY, W_EASY, BOMBS_EASY);
    else if(diff == GameDifficulty::MEDIUM)
        prepareGame(H_MEDIUM, W_MEDIUM, BOMBS_MEDIUM);
    else
        prepareGame(H_HARD, W_HARD, BOMBS_HARD);
}
