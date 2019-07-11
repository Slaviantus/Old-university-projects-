#include "binaryitem.h"
#include <QFontMetrics>
#include <QPainter>
#include <QDebug>

/**
 * @brief BinaryItem::BinaryItem
 * Конструктор.
 * @param font
 * Шрифт, используемый для вывода текста.
 * @param os
 * Символ(ы) операции. Могут быть:  +  -  *  /  .*  ./
 * @param parent
 * Родительский объект (не задается).
 */
BinaryItem::BinaryItem(const QFont &font, const QString os, QObject *parent) :
    CommonItem(font, BIN_NUM_OF_PARTS, parent),
    operatorSymbol(os)
{
    for (int i(0); i<m_iNum; ++i) {                           // создание и настройка типа дочерних элементов - зависит от типа родительского элемента
        items[i] = new Place(font);                                     // создание
        items[i]->setParentItem(this);                                  // данный объект задается дочерним в качестве родителя
        items[i]->setRestriction(i == 1 ? Place::IDOnly : Place::None); // второй из трех дочерний элемент может содержать только текст
        items[i]->enableEditable(i == 1 ? false : true);                // первый и последний дочерние элементы - редактируемые
    }
    items[1]->setText(" " + operatorSymbol + " ");                      // задается текст для среднего элемента, содержащего символ(ы) операции
    setChildPos();                                                      // вычисляются позиции всех дочерних элементов
}

/**
 * @brief BinaryItem::setChildPos
 * Вычисление позиций дочерних элементов. Виртуальный метод.
 * Позиции дочерних элементов зависят от типа родительского элемента и определяют их взаимное расположение.
 * Позиции задаются в системе координат родительского элемента. Так как для правильной "расстановки" дочерних
 * элементов необходимо знать их габаритные размеры, то для их определения вызывается виртуальный метод
 * boundingRect().
 */
void BinaryItem::setChildPos()
{
    qreal maxHeight(0.0);
    qreal h;
    for (int i(0); i<m_iNum; ++i) {             // определяется высота самого "высокого" дочернего элемента
        h = items[i]->boundingRect().height();
        if (h > maxHeight) {
            maxHeight = h;
        }
    }

    // - левый операнд
    items[0]->setPos(0.0, 0.0);
    // - символ(ы) операции
    items[1]->setPos(items[0]->boundingRect().width(), 0.0);
    // - правый операнд
    items[2]->setPos(items[1]->pos().x() + items[1]->boundingRect().width(), 0.0);

}

/**
 * @brief BinaryItem::getLeft
 * Обеспечивает доступ дочернему элементу, представляющему левый
 * операнд бинарной операции.
 * Этот метод не нужно определять в классах других элементов!
 * @return
 * Возвращает указатель на элемент, представляющий левый операнд.
 */
Place *BinaryItem::getLeft()
{
    return items[0];
}

/**
 * @brief BinaryItem::getRight
 * Обеспечивает доступ дочернему элементу, представляющему правый
 * операнд бинарной операции.
 * Этот метод не нужно определять в классах других элементов!
 * @return
 * Возвращает указатель на элемент, представляющий правый операнд.
 */
Place *BinaryItem::getRight()
{
    return items[2];
}
