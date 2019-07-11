#ifndef VECTORITEM_H
#define VECTORITEM_H
#include "commonitem.h"
#include "place.h"

/**
 * @brief The VectorItem class
 * Класс элемента "вектор-столбец".
 * Элемент представляется в виде совокупности дочерних элементов, отображаемых
 * друг под другом в виде столбца, заключенного в квадратные скобки.
 * Количество элементов задается при создании элемента-вектора.
 */
class VectorItem : public CommonItem
{
    Q_OBJECT

public:
    // Конструктор
    explicit VectorItem(const QFont &font, const int iNum, QObject *parent = 0);

    // Переопределенные виртуальные методы:
    // - задание взаимного расположения дочерних элементов
    void setChildPos();
    // - обновление размера элемента после изменения дочернего элемента
    void updateSize();
    // - рисование скобок
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

signals:

public slots:

};
#endif // VECTORITEM_H
