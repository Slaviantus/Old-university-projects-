#ifndef EQUATION_H
#define EQUATION_H
#include "commonitem.h"
#include "place.h"

/**
  Класс уравнения.
  Необходим как часть иерархии классов модели, реализует возможность
  создания массива указателей на уравнения (как дифференциальные DEquation,
  так и алгебраические AEquation)
**/
class Equation : public CommonItem
{
    Q_OBJECT
protected:

public:
    explicit Equation(const QFont &font, int iNum, QObject *parent = 0);

signals:

public slots:

};

#endif // EQUATION_H
