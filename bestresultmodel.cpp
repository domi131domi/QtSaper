#include "bestresultmodel.h"

QVariant BestResultModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
            return QVariant();

        if (orientation == Qt::Horizontal)
            if(section == 0)
                return QString("Name");
            else
                return QString("time (sec)");
        else
            return QString(QString::number(section+1) + ".");
}

int BestResultModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return results.size();
}

int BestResultModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return width;
}

QVariant BestResultModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    if (role != Qt::DisplayRole)
        return QVariant();
    if(index.row() >= results.size())
        return QVariant();
    if(index.column() == 0)
    {
       return results.at(index.row()).name;
    }
    else if(index.column() == 1)
    {
        return results.at(index.row()).time;
    }
    else
        return QVariant();
}
