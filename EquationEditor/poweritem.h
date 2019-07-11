#ifndef POWERITEM_H
#define POWERITEM_H

#include "commonitem.h"
#include "place.h"

#define ST_NUM_OF_PARTS 2                                      // количество дочерних элементов

/**
 * @brief The PowerItem class
 * Класс операции возведения в степень.
 * Операция является формально бинарной, но визуальное представление
 * ее отличается от "линейных" бинарных операций наподобие сложения:
 * основание выровнено по горизонтали с соседними элементами, а показатель
 * отображается в виде верхнего индекса с уменьшенным до 70% относительно основания
 * размером шрифта.
 */
class PowerItem : public CommonItem
{
    Q_OBJECT

public:
    // Конструктор
    explicit PowerItem(const QFont &font,  QObject *parent = 0);
    // Определение позиций дочерних элементов - основаниия и показателя.
    void setChildPos();

signals:

public slots:

};

#endif // POWERITEM_H
