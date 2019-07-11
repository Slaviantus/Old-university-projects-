#include "commonitem.h"
#include "modelscene.h"
#include <QKeyEvent>
#include <QDebug>

/**
 * @brief CommonItem::CommonItem
 * Конструктор класса.
 * @param font
 * Шрифт, используемый в качестве базового для отображения текста непосредственно в элементе.
 * Для дочерних элементов, по умолчанию используется такой же шрифт, однако, при необходимости,
 * может модифицироваться.
 * @param iNum
 * Количество дочерних элементов. Конкретное значение зависит от типа элемента, поэтому задается
 * в конструкторах производных классов.
 * @param parent
 * Родительский объект. По умолчанию NULL
 */
CommonItem::CommonItem(const QFont &font, int iNum, QObject *parent) :
    QGraphicsObject(NULL),
    m_iNum(iNum)
{
    items.resize(m_iNum);               // установка размера вектора дочерних элементов
    this->font = font;                  // установка шрифта в качестве текущего для элемента
}

/**
 * @brief CommonItem::paint
 * Переопределенный метод для рисования содержимого элемента. Метод в данном классе является пустым;
 * в производных классах элементов должен переопределяться в случаях, когда изображение элемента содержит
 * графические нетекстовые элементы (например, дробная черта, скобки вектора и т.п.).
 * @param painter
 * Указатель на объект типа QPainter, методы которого используются для рисования.
 * @param option
 * См. справку по классу QStyleOptionGraphicsItem. В обычной ситуации аргумент не используется.
 * @param widget
 * Указатель на виджет, на котором выполняется рисование. В обычной ситуации аргумент не используется.
 */
void CommonItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

}

/**
 * @brief CommonItem::updateSize
 * Обновление размеров данного элемента.
 * Так как размер элемента формулы зависит от размеров всех его дочерних элементов,
 * то поэтому вначале выполняется определение их размеров. Далее обновляются их позиции.
 * И после этого вычисляется размер данного элемента.
 * Следует учесть, что при определении размера элемента в целом учитываются только габаритные размеры
 * дочерних элементов. Если необходимо учесть использование дополнительного места для, например, графических
 * элементов, бордюров и т.п., то следует переопределить метод в производном классе.
 * Данный метод переопределяется в производных классах, если алгоритм обновления размеров отличается
 * от реализованного здесь. При переопределении, если необходимо, можно вызвать метод данного класса совместно
 * с дополнительными инструкциями (см., например, метод VectorItem::updateSize).
 * Размеры элемента сохраняются в поле sz.
**/
void CommonItem::updateSize()
{
    prepareGeometryChange();                   // нужно вызвать этот метод перед изменением геометрических параметров объекта (размеров)
    for (int i(0); i<m_iNum; ++i) {            // обновление размеров дочерних элементов
        items[i]->updateSize();
    }
    setChildPos();                             // вычисление позиций дочерних элементов
    QRectF br;
    for (int i(0); i<m_iNum; ++i) {            // вычисляется габаритный прямоугольник элемента как объединение габаритных прямоугольников дочерних элементов
        br = br.united(mapRectFromItem(items[i], items[i]->boundingRect()));
    }
    qreal b = border();                        // устанавливается "бордюр" по краям элемента (чтобы не "слипались" оседние элементы). В данный момент border возвращает 0
    br = br.adjusted(-b, -b, b, b);
    m_sz = br.size();                          // размер вычисленного прямоугольника сохраняется в объекте
    m_topLeft = br.topLeft();                      // координаты ЛВУ также сохраняются в объекте
}

/**
 * @brief CommonItem::border
 * Вычисляет ширину бордюра, используемую в CommonItem::updateSize.
 * Бордюр необходим для обеспечения промежутков между соседними элементами.
 * @return
 * Возвращает ширину бордюра.
 */
qreal CommonItem::border() const
{
    qreal res = 0.05 * qAbs(qMin(m_sz.width(), m_sz.height()));
    // см. код 1
    return 0; //res;
}

/**
 * @brief CommonItem::getRootItem
 * Корневой родительский элемент для данного элемента (this)
 * @return
 */
QGraphicsItem *CommonItem::getRootItem()
{
    return getRootItem(this);
}

/**
 * @brief CommonItem::select
 * Делает данный элемент выбранным либо отменяет его выделение.
 * @param s
 * Если true (по умолчанию), то данный элемент делается выбранным.
 * Иначе любое выделение сбрасывается.
 */
void CommonItem::select(bool s)
{
    ModelScene *ms(static_cast<ModelScene *>(scene()));
    if (s)
        ms->setSelectedItem(this);
    else
        ms->unselectItem();
}

/**
 * @brief CommonItem::isSelected
 * Проверка состояния элемента: выделен / не выделен
 * @return
 * Возвращает true, если данный элемент выделен, и
 * false в противном случае.
 */
bool CommonItem::isSelected() const
{
    ModelScene *ms(static_cast<ModelScene *>(scene()));
    return this == ms->getSelectedItem();
}

/**
 * @brief CommonItem::removeChildItems
 * Удаление содержимого всех дочерних элементов.
 */
void CommonItem::removeChildItems()
{
    int sz(items.size());
    for (int i(0); i<sz; ++i) {
        items[i]->removeItem();
    }
}

/**
 * @brief CommonItem::getFirstEditablePlace
 * Указатель на первый редактируемый дочерний элемент данного элемента.
 * Порядок элементов определяется порядком их размещения в массиве items
 * @return
 * Возвращает указатель на первый редактируемый дочерний элемент.
 */
Place *CommonItem::getFirstEditablePlace()
{
    Place *place(0);
    int i(0);
    int n(items.size());
    do {
        place = items[i++];
    } while (i<n && !place->isEditable());
    return place;
}

/**
 * @brief CommonItem::getNextEditablePlace
 * Указатель на следующий после заданного редактируемый дочерний элемент.
 * Порядок элементов определяется порядком их размещения в массиве items.
 * @param place
 * Указатель на дочерний элемент, после которого метод должен найти следующий редактируемый
 * элемент
 * @return
 * Возвращает указатель на найденный дочерний элемент, либо NULL, если требуемый элемент не найден.
 */
Place *CommonItem::getNextEditablePlace(Place *place)
{
    if (!place) return NULL;
    Place *nextPlace(NULL);
    int i(0);
    int n(items.size());

    do {
    } while (i<n && items[i++] != place);
    if (i == n) return NULL;
    do {
        nextPlace = items[i++];
    } while (i<n && !nextPlace->isEditable());
    return nextPlace;
}

/**
 * @brief CommonItem::getFont
 * Текущий шрифт, установленный для элемента.
 * @return
 * Возвращает текущий шрифт элемента.
 */
const QFont &CommonItem::getFont() const
{
    return font;
}

/**
 * @brief CommonItem::getRootItem
 * Перегруженный метод для определения корневого элемента в иерархии элементов формулы.
 * @param item
 * Указатель на элемент, для которого требуется найти корневой элемент.
 * @return
 * Возвращает указатель на найденный корневой элемент для элемента item.
 */
QGraphicsItem *CommonItem::getRootItem(QGraphicsItem *item)
{
    if (item->parentItem()) {
        return getRootItem(item->parentItem());
    } else {
        return item;
    }
}

/**
 * @brief CommonItem::boundingRect
 * Габаритный прямоугольник элемента.
 * В координатной системе родительского элемента.
 * @return
 * Возвращает габаритный прямоугольник элемента.
 */
QRectF CommonItem::boundingRect() const
{
    QRectF br;
    br.setTopLeft(m_topLeft);
    br.setSize(m_sz);
    return (br);
}

void CommonItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    select();
}
