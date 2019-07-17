#include "vectoritem.h"
#include <QFontMetrics>
#include <QPainter>
#include <QPen>
#include <iostream>

using namespace std;

/**
 * @brief VectorItem::VectorItem
 * Конструктор.
 * @param font
 * Шрифт, используемый для вывода текста.
 * @param iNum
 * Количество элементов вектора
 * @param parent
 * Родительский объект (не задается).
 */
VectorItem::VectorItem(const QFont &font, const int iNum,  QObject *parent) :
    CommonItem(font, iNum, parent)
{
    for (int i(0); i < m_iNum; ++i) {
        items[i] = new Place(font);                // создание
        items[i]->setParentItem(this);             // данный объект задается дочерним в качестве родителя
        items[i]->enableEditable();                // дочерние элементы - редактируемые
    }
    setChildPos();                                 // вычисляются позиции всех дочерних элементов
}

/**
 * @brief VectorItem::setChildPos
 * Вычисление позиций дочерних элементов. Виртуальный метод.
 * Позиции дочерних элементов зависят от типа родительского элемента и определяют их взаимное расположение.
 * Позиции задаются в системе координат родительского элемента. Так как для правильной "расстановки" дочерних
 * элементов необходимо знать их габаритные размеры, то для их определения вызывается виртуальный метод
 * boundingRect().
 */
void VectorItem::setChildPos()
{
    qreal maxWidth(0.0);
    qreal w;
    for (int i(0); i < m_iNum; ++i) {                        // определяется ширина самого "широкого" дочернего элемента
        w = items[i]->boundingRect().width();
        if (w > maxWidth) {  maxWidth = w; }
    }

    qreal hPos; // вспомогательная переменная для вычисления вертикальных позиций элементов вектора

    if (m_iNum % 2) {  // если количество элементов вектора нечетное,
        // то в hPos - ордината верхнего края центрального элемента вектора
        hPos = items[m_iNum/2]->boundingRect().top();
        // устанавливаем позицию центрального элемента вектора
        items[m_iNum/2]->setPos((maxWidth - items[m_iNum/2]->boundingRect().width()) / 2 + 10,
                                    0.0);
    }
    else               // иначе hPos - 0
        hPos = 0.0;

    // Вычисление позиций всех элементов вектора, расположенных выше середины (среднего элемента)
    for (int i(0); i < m_iNum / 2; ++i) {
        hPos -= items[m_iNum / 2 - i - 1]->boundingRect().bottom() + 5.0;
        items[m_iNum / 2 - i - 1]->setPos(
                    (maxWidth - items[m_iNum / 2 - i - 1]->boundingRect().width()) / 2.0 + 10.0,
                hPos);
    }

    // повторное вычисление hPos для обновления позиций элементов вектора ниже середины (среднего элемента)
    if (m_iNum % 2)
        hPos = items[m_iNum/2]->boundingRect().bottom();
    else
        hPos = 0.0;
    // Вычисление позиций всех элементов вектора, расположенных ниже середины  D (среднего элемента)
    for (int i(0); i < m_iNum / 2; ++i) {
        hPos += -items[m_iNum / 2 + i + m_iNum % 2]->boundingRect().top() + 5.0;
        items[m_iNum / 2 + i + m_iNum % 2]->setPos(
                    (maxWidth - items[m_iNum / 2 + i + m_iNum % 2]->boundingRect().width()) / 2.0 + 10.0,
                hPos);
    }
}

/**
 * @brief VectorItem::updateSize
 * Обновление размера элемента. Дополняет реализацию метода в базовом классе:
 * размер элемента дополнительно увеличивается, чтобы учесть бордюры слева и справа,
 * используемые для скобок.
 * См. описание метода CommonItem::updateSize.
 */
void VectorItem::updateSize()
{
    cout << "Glory to Arstotzka!!" << endl;
    CommonItem::updateSize();

    m_topLeft += QPointF(-10.0, -2.0);
    m_sz += QSizeF(2*10.0, 4.0);
}

/**
  В методе осуществляется рисовка линий по бокам вектора.
**/

/**
 * @brief VectorItem::paint
 * Рисование квадратных скобок слева и справа.
 * @param painter
 * См. описание для метода CommonItem::paint.
 * @param option
 * См. описание для метода CommonItem::paint.
 * @param widget
 * См. описание для метода CommonItem::paint.
 */
void VectorItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    qreal maxWidth(0.0);
    qreal pw(5.0);                                    // длина горизонтальной части скобок
    qreal w(0.0);
    for (int i (0); i < m_iNum; ++i) {                // определяется высота самого "широкого" дочернего элемента
        w = items[i]->boundingRect().width();
        if (w > maxWidth) {  maxWidth = w; }
    }

    QFontMetrics fm(font);
    // Перо, используемое для рисования линий скобок.
    // Горизонтальные части скобок в 2 раза уже вертикальных.
    // Толщина вертикальных линий задана, как 5% от высоты шрифта
    QPen pen;

    // Вертикальные линии
    pen.setWidthF(fm.size(Qt::TextSingleLine, "0").height()*0.05);
    painter->setPen(pen);
    painter->drawLine(QPointF(2.0, boundingRect().top()),
                      QPointF(2.0, boundingRect().bottom()));

    painter->drawLine(QPointF(boundingRect().width()-2.0, boundingRect().top()),
                      QPointF(boundingRect().width()-2.0, boundingRect().bottom()));

    // Горизонтальные линии
    pen.setWidthF(pen.widthF() / 2.0);
    painter->setPen(pen);
    painter->drawLine(QPointF(2.0, boundingRect().top()),
                      QPointF(2.0 + pw, boundingRect().top()));
    painter->drawLine(QPointF(2.0, boundingRect().bottom()),
                      QPointF(2.0 + pw, boundingRect().bottom()));
    painter->drawLine(QPointF(boundingRect().width()-2.0, boundingRect().top()),
                      QPointF(boundingRect().width()-(2.0 + pw), boundingRect().top()));
    painter->drawLine(QPointF(boundingRect().width()-2.0, boundingRect().bottom()),
                      QPointF(boundingRect().width()-(2.0 + pw), boundingRect().bottom()));

}
