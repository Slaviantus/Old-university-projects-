#ifndef COMMONITEM_H
#define COMMONITEM_H

#include <QGraphicsObject>
#include <QRectF>
#include <QSizeF>
#include <QFont>
#include <QBrush>
#include <QPen>

class Place;

/**
 * @brief The CommonItem class
 * Абстрактный класс графического элемента формулы.
 * Все элементы формул наследуются от данного класса.
 */
class CommonItem : public QGraphicsObject
{
    Q_OBJECT

protected:
    int m_iNum;                 // количество элементов
    QSizeF m_sz;                // размер элемента
    QPointF m_topLeft;          // координаты ЛВУ элемента
    QFont font;                 // базовый шрифт элемента
    QVector<Place *> items;     // дочерние элементы
public:
    explicit CommonItem(const QFont &font,  int iNum = 1, QObject *parent = 0);

    // виртуальные методы:
    // - задание взаимного расположения дочерних элементов
    virtual void setChildPos() = 0;
    // - рисование нетекстовых элементов (находящихся вне текстовых знакомест)
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    // - обновление размера элемента после изменения дочернего элемента
    virtual void updateSize();
    // - возврат габаритного прямоугольника элемента
    QRectF boundingRect() const;
    // - возврат ширины бордюра вокруг элемента
    qreal border() const;
    // - возврат корневого элемента
    QGraphicsItem *getRootItem();
    void select(bool s = true);
    // - возврат статуса элемента: выделен / не выделен
    bool isSelected() const;
    // - удаление всех дочерних элементов
    void removeChildItems();
    // - возврат первого редактируемого дочернего элемента
    Place *getFirstEditablePlace();
    // - возврат следующего ближайшего по порядку редактируемого дочернего элемента после place
    Place *getNextEditablePlace(Place *place);
    // - возврат шрифта
    const QFont &getFont() const;
    // обработка нажатия мыши
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

signals:
public slots:
private:
    // - возврат корневого элемента иерархии для item. Используется
    // - в перегруженном методе QGraphicsItem *CommonItem::getRootItem();
    QGraphicsItem *getRootItem(QGraphicsItem * item);

};

#endif // COMMONITEM_H
