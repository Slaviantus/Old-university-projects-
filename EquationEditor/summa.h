#ifndef SUMMA_H
#define SUMMA_H
#include "equation.h"
#include "place.h"
#include <QFont>
#include "commonitem.h"
#define SUM_NUM_OF_PARTS 6 //столько дочерних элементов


class Summa : public CommonItem
{
    Q_OBJECT

    bool isSum;  //при значении true - сумма, false - произведение
    QFont Symbol;  //шрифт для знака суммы
    QFont Elements; //шрифт для мелких элементов

public:
    explicit Summa(const QFont &font, bool sum, QObject *parent = 0);
    void setChildPos();

signals:

public slots:

};

#endif // SUMMA_H
