#ifndef DEQUATION_H
#define DEQUATION_H
#include "equation.h"
#include "place.h"

#define DE_NUM_OF_PARTS 8

/**
  Класс дифференциального уравнения
**/
class DEquation : public Equation
{
    Q_OBJECT

    static const QString icTmpl;      // строка-шаблон фрагмента ДУ: ", %1(0) = "
    qreal varWidth;    // ширина области, занимаемой именем переменной в левой части ДУ
    qreal dWidth;      // ширина области, занимаемой символом 'd' в числителе левой части ДУ
    qreal leftWidth;   // ширина левой части ДУ целиком
    qreal maxHeight;   // высота уравнения

public:
    explicit DEquation(const QFont &font, QObject *parent = 0);
    void setChildPos();
    void updateSize();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    Place *getLeft();
    Place *getRight();


signals:

public slots:

};

#endif // DEQUATION_H
