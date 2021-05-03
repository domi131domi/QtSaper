#include "gameboardmodel.h"

gameBoardModel::gameBoardModel(QObject *parent) : QAbstractTableModel(parent)
{
    prepareGame(H_EASY, W_EASY, BOMBS_EASY);
    width = W_EASY;
    height = H_EASY;
    bombs_count = BOMBS_EASY;
    points = 0;
    multi = E_MULTI;
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this,&gameBoardModel::timeMinusPoints);
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
    return QVariant::fromValue<Field>(fields[index.row()][index.column()]);
}

bool gameBoardModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(value.value<FieldState>() == FieldState::revieled)
    {
        if(firstMove)
        {
            timer->start(TIMER);
            firstMove = false;
        }
        if(fields[index.row()][index.column()].nextToBombs == 0 && !fields[index.row()][index.column()].isBomb)
        {
            show_empty(index.row(),index.column());
            emit dataChanged(this->index(0,0), this->index(height-1,width-1));
            return true;
        }
        else if(fields[index.row()][index.column()].isBomb)
        {
            gameRunning = false;
            timer->stop();
            emit gameOver();
            fields[index.row()][index.column()].state = value.value<FieldState>();
        }
        else
        {
           revieled_count++;
           points+=multi;
           emit pointsChanged(QString("%1").arg(points, 4, 10, QLatin1Char('0')));
           fields[index.row()][index.column()].state = value.value<FieldState>();
        }
    }
    else
        fields[index.row()][index.column()].state = value.value<FieldState>();
    emit dataChanged(index, index);
    if(revieled_count == width*height - bombs_count)
    {
        gameRunning = false;
        timer->stop();
        emit winGame();
    }
    return true;
}

int gameBoardModel::getWidth()
{
    return width;
}

int gameBoardModel::getHeight()
{
    return height;
}

void gameBoardModel::show_empty(int y, int x)
{
    if(fields[y][x].state == FieldState::unrevieled && fields[y][x].nextToBombs == 0 && !fields[y][x].isBomb)
    {
        fields[y][x].state = FieldState::revieled;
        revieled_count++;
    }
    else
        return;
    if(y-1 >= 0)
        show_empty(y-1,x);
    if(x-1 >= 0)
        show_empty(y,x-1);
    if(y+1 < height)
        show_empty(y+1,x);
    if(x+1 < width)
        show_empty(y,x+1);
}

void gameBoardModel::prepareGame(int h, int w, int bombs)
{
    firstMove = true;
    gameRunning = true;
    revieled_count = 0;
    points = 0;
    for(int i=0; i < h; i++)
    {
        for(int e = 0; e < w; e++)
        {
            fields[i][e].state = FieldState::unrevieled;
            fields[i][e].isBomb = false;
            fields[i][e].nextToBombs = 0;
        }
    }
    int x,y;
    for(int i = 0; i < bombs; i++)
    {
        x = QRandomGenerator::global()->generate()%h;
        y = QRandomGenerator::global()->generate()%w;
        while(fields[x][y].isBomb)
        {
            x = QRandomGenerator::global()->generate()%h;
            y = QRandomGenerator::global()->generate()%w;
        }
        fields[x][y].isBomb = true;
        if(x+1 < h)
        {
            fields[x+1][y].nextToBombs++;
            if( y+1 < w)
                fields[x+1][y+1].nextToBombs++;
            if( y-1 >= 0)
                fields[x+1][y-1].nextToBombs++;
        }
        if(x-1 >= 0)
        {
            fields[x-1][y].nextToBombs++;
            if( y+1 < w)
                fields[x-1][y+1].nextToBombs++;
            if( y-1 >= 0)
                fields[x-1][y-1].nextToBombs++;
        }
        if( y+1 < w)
            fields[x][y+1].nextToBombs++;
        if( y-1 >= 0)
            fields[x][y-1].nextToBombs++;

    }
    emit newGame();
}

void gameBoardModel::changeDifficulty(GameDifficulty diff)
{
    if(diff == GameDifficulty::EASY)
    {
        width = W_EASY;
        height = H_EASY;
        bombs_count = BOMBS_EASY;
        multi = E_MULTI;
    }
    else if(diff == GameDifficulty::MEDIUM)
    {
        width = W_MEDIUM;
        height = H_MEDIUM;
        bombs_count = BOMBS_MEDIUM;
        multi = M_MULTI;
    }
    else
    {
        width = W_HARD;
        height = H_HARD;
        bombs_count = BOMBS_HARD;
        multi = H_MULTI;
    }
    prepareGame(height, width, bombs_count);
    emit headerDataChanged(Qt::Horizontal,0, height);
    emit headerDataChanged(Qt::Vertical,0,width);
    emit dataChanged(index(0,0),index(width,height));
    emit pointsChanged(QString("%1").arg(0, 4, 10, QLatin1Char('0')));
}

int gameBoardModel::getPoints()
{
    return points;
}

void gameBoardModel::startNewGame()
{
    emit pointsChanged(QString("%1").arg(0, 4, 10, QLatin1Char('0')));
    prepareGame(width,height,bombs_count);
}

void gameBoardModel::timeMinusPoints()
{
    points-=TIMER_MINUS_POINTS;
    if(points < 0)
        points = 0;
    emit pointsChanged(QString("%1").arg(points, 4, 10, QLatin1Char('0')));
}

Q_DECLARE_METATYPE(Field)
Q_DECLARE_METATYPE(FieldState)
