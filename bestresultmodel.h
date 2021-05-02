#ifndef BESTRESULTMODEL_H
#define BESTRESULTMODEL_H

#include <QAbstractTableModel>
#include <settings.h>
#include <string>

struct Result {
    QString name;
    int time;
};

class BestResultModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit BestResultModel(std::vector<Result> res, QObject *parent = nullptr) : QAbstractTableModel(parent), results(res) {}

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
    std::vector<Result> results;
    const int width = 2;
};

#endif // BESTRESULTMODEL_H
