#include "poweritem.h"
#include <QFontMetrics>
#include <QPainter>
#include <QDebug>

/**
 * @brief PowerItem::PowerItem
 * Конструктор
 * @param font
 * Шрифт, используемый для вывода текста.
 * @param parent
 * Родительский объект (не задается).
 */
PowerItem::PowerItem(const QFont &font, QObject *parent) :
    CommonItem(font, ST_NUM_OF_PARTS, parent)
{
    // создание и настройка редактируемого элемента для основания
    items[0] = new Place(font);
    items[0]->setParentItem(this);
    items[0]->setRestriction(Place::None);
    items[0]->enableEditable(true);

    // создание и настройка редактируемого элемента для показателя степени
    items[1] = new Place(QFont(font.family(), font.pointSizeF()*0.7));
    items[1]->setParentItem(this);
    items[1]->setRestriction(Place::None);
    items[1]->enableEditable(true);
    setChildPos();
}

/**
 * @brief PowerItem::setChildPos
 * Вычисление позиций дочерних элементов. Виртуальный метод.
 * Позиции дочерних элементов зависят от типа родительского элемента и определяют их взаимное расположение.
 * Позиции задаются в системе координат родительского элемента. Так как для правильной "расстановки" дочерних
 * элементов необходимо знать их габаритные размеры, то для их определения вызывается виртуальный метод
 * boundingRect().
 */
void PowerItem::setChildPos()
{
    // основание позиционируется по базовой линии (оси Х родительской СК)
    items[0]->setPos(0.0, 0.0);
    // показатель степени смещается вверх на уровень верхнего края основания степени
    items[1]->setPos(items[0]->pos().x() + items[0]->boundingRect().width(),
            items[0]->boundingRect().top());
}
