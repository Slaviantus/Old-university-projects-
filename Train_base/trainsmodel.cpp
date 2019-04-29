#include "trainsmodel.h"
#include "QModelIndex"

const char * HeaderTitles [ITEM_COUNT] = {"Номер поезда", "Цена билета", "Пункт отправления", "Пункт назначения", "Время отправления", "Время прибытия"};

using namespace std;


int Trainsmodel::rowCount(const QModelIndex &) const
{
    return trains.size();
}

QVariant Trainsmodel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
    {
        return QVariant();
    }
    return (role ==Qt::DisplayRole||role==Qt::EditRole)
            ? QVariant::fromValue(trains.at(index.row())
                                  .getFieldValue(index.column()))
            : QVariant();
}

QVariant Trainsmodel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
    {
        return QVariant();
    }
    return (orientation == Qt::Horizontal)
            ? QString(tr(HeaderTitles[section]))
            : QString("");
}

int Trainsmodel::columnCount(const QModelIndex &) const
{
    return ITEM_COUNT;
}

bool Trainsmodel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    Itemtrain train;
    if (index.isValid() && role == Qt::EditRole)
    {
        train = trains.at(index.row());
        train.setFieldValue(value, index.column());
        trains.replace(index.row(), train);

        emit dataChanged(index,index);
        return true;
    }
    return false;
}

Trainsmodel::Trainsmodel(QObject *parent) : QAbstractTableModel(parent)
{

}

Trainsmodel::Trainsmodel(QList<Itemtrain> list)
{
    trains = list;
}
