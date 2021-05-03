#ifndef GAMEBOARDMODEL_H
#define GAMEBOARDMODEL_H

#include <QAbstractTableModel>
#include "settings.h"
#include <QRandomGenerator>
#include <QTimer>

enum FieldState
{
    flag,
    unrevieled,
    revieled
};

struct Field
{
    FieldState state;
    int nextToBombs;
    bool isBomb;
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
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    bool gameRunning;
    int getWidth();
    int getHeight();
    void changeDifficulty(GameDifficulty diff);
    int getPoints();
signals:
    void gameOver();
    void newGame();
    void winGame();
    void pointsChanged(QString);
public slots:
    void startNewGame();
    void timeMinusPoints();
private:
    Field fields[MAX_HEIGHT][MAX_WIDTH];
    int width;
    int height;
    int bombs_count;
    int revieled_count;
    GameDifficulty actualDiff;
    void prepareGame(int h, int w, int bombs);
    void show_empty(int y, int x);
    int points;
    int multi;
    bool firstMove;
    QTimer* timer;
};

#endif // GAMEBOARDMODEL_H
