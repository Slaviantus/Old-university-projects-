#include "itemtrain.h"

Itemtrain::Itemtrain(int trainnumber, double price, QString departure, QString destination, QTime departuretime, QTime arrivaltime)
{
    this->trainnumber = trainnumber;
    this->price = price;
    this->departure = departure;
    this->destination = destination;
    this->departuretime = departuretime;
    this->arrivaltime = arrivaltime;
}

Itemtrain::Itemtrain(const Itemtrain &train)
{
    trainnumber = train.trainnumber;
    price = train.price;
    departure = train.departure;
    destination = train.destination;
    departuretime = train.departuretime;
    arrivaltime = train.arrivaltime;
}

QString Itemtrain::getFieldValueS(int fieldNum) const
{
    switch (fieldNum)
    {
    case 0:
        return QString::number(trainnumber);
    case 1:
        return QString::number(price);
    case 2:
        return departure;
    case 3:
        return destination;
    case 4:
        return departuretime.toString("hh:mm");
    case 5:
        return arrivaltime.toString("hh:mm");
    default:
        return QString("");
    }
}

QVariant Itemtrain::getFieldValue(int fieldNum) const
{
    switch (fieldNum)
    {
    case 0:
        return QVariant::fromValue(trainnumber);
    case 1:
        return QVariant::fromValue(price);
    case 2:
        return QVariant::fromValue(departure);
    case 3:
        return QVariant::fromValue(destination);
    case 4:
        return QVariant::fromValue(departuretime);
    case 5:
        return QVariant::fromValue(arrivaltime);
    default:
        return QVariant();

    }
}

int Itemtrain::setFieldValue(QVariant value, int fieldNum)
{
    bool res = true;
    QString s;
    switch (fieldNum)
    {
    case 0:
        trainnumber = value.toInt(&res);
        return 0;
    case 1:
        price = value.toDouble(&res);
        return 1;
    case 2:
        departure = value.toString();
        return 2;
    case 3:
        destination = value.toString();
        return 3;
    case 4:
        departuretime = value.toTime();
        return 4;
    case 5:
        arrivaltime = value.toTime();
        return 5;
    default:
        return -1;
    }
}

Itemtrain &Itemtrain::operator =(const Itemtrain &other)
{
    trainnumber = other.trainnumber;
    price = other.price;
    departure = other.departure;
    destination = other.destination;
    departuretime = other.departuretime;
    arrivaltime = other.arrivaltime;
    return *this;
}

void Itemtrain::setSortKey(int key)
{
    if(key >= 0 && key <= 5)
    {
        m_sortkey = key;
    }
}

int Itemtrain::getSortKey()
{
    return m_sortkey;
}

Itemtrain::Itemtrain(QObject *parent) : QObject(parent)
{

}
