#ifndef TRAINSMODEL_H
#define TRAINSMODEL_H
#include <QAbstractTableModel>
#include <QList>
#include <itemtrain.h>
#include <QVariant>

using namespace std;

class Trainsmodel: public QAbstractTableModel
{
    QList<Itemtrain> trains;
public:
    int rowCount(const QModelIndex &) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    int columnCount(const QModelIndex &) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    Trainsmodel(QObject *parent = 0);
    Trainsmodel(QList<Itemtrain> list);
};

#endif // TRAINSMODEL_H
