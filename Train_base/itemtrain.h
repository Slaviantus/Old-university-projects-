#ifndef ITEMTRAIN_H
#define ITEMTRAIN_H

#include <QObject>
#include <QTime>
#include <QString>
#include <QVariant>
#define ITEM_COUNT 6
class Itemtrain : public QObject
{
    Q_OBJECT
    QTime departuretime;
    QTime arrivaltime;
    QString departure;
    QString destination;
    int trainnumber;
    double price;

    static int m_sortkey;
public:
    Itemtrain(int trainnumber, double price, QString departure, QString destination, QTime departuretime, QTime arrivaltime);
    Itemtrain(const Itemtrain &train);
    QString getFieldValueS(int fieldNum) const;
    QVariant getFieldValue(int fieldNum) const;
    int setFieldValue(QVariant value, int fieldNum);
    Itemtrain& operator =(const Itemtrain &other);
    static void setSortKey(int key);
    static int getSortKey();
    explicit Itemtrain(QObject *parent = nullptr);

signals:

public slots:
};

#endif // ITEMTRAIN_H
