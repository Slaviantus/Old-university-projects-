#ifndef AEQUATION_H
#define AEQUATION_H
#include "equation.h"

/**
  Класс алгебраического уравнения.
  К АУ относятся также определения константных параметров, определения входных и выходных параметров.
**/
class AEquation : public Equation
{
    Q_OBJECT
public:
    explicit AEquation(const QFont &font, QObject *parent = 0);

signals:

public slots:

};

#endif // AEQUATION_H
