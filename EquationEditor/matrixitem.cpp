#include "matrixitem.h"
#include "place.h"
#include "iostream"
#include "QFontMetrics"
#include "QPen"
#include "QPainter"

using namespace std;



MatrixItem::MatrixItem(const QFont &font, QObject *parent) : CommonItem(font, MATRIX_PARTS, parent)
{
    for (int i(0); i<m_iNum; ++i) {                           // создание и настройка типа дочерних элементов - зависит от типа родительского элемента
        items[i] = new Place(font);                                     // создание
        items[i]->setParentItem(this);                                  // данный объект задается дочерним в качестве родителя
        items[i]->enableEditable(true);
    }
    setChildPos();
}

void MatrixItem::setChildPos()
{
    qreal maxHeight(0.0);
    qreal h;
//    for (int i(0); i<m_iNum; ++i) {             // определяется высота самого "высокого" дочернего элемента
//        h = items[i]->boundingRect().height();
//        if (h > maxHeight) {
//            maxHeight = h;
//        }
//    }
    //****************experiment**************

    items[0]->setPos(0.0, 0.0);
    items[1]->setPos(items[0]->boundingRect().width(), 0.0);
    items[2]->setPos(items[1]->pos().x() + items[1]->boundingRect().width(), 0.0);
    items[3]->setPos(0.0, items[0]->boundingRect().height());
    items[4]->setPos(items[3]->boundingRect().width(), items[0]->boundingRect().height());
    items[5]->setPos(items[4]->pos().x() + items[4]->boundingRect().width(), items[0]->boundingRect().height());
    items[6]->setPos(0.0, items[3]->pos().y() + items[3]->boundingRect().height());
    items[7]->setPos(items[6]->boundingRect().width(), items[3]->pos().y() + items[3]->boundingRect().height());
    items[8]->setPos(items[7]->pos().x() + items[7]->boundingRect().width(), items[3]->pos().y() + items[3]->boundingRect().height());

 }

void MatrixItem::updateSize()
{
    CommonItem::updateSize();
    m_topLeft += QPointF(-3.0, -33.0);
    m_sz += QSizeF(2*10.0, 4.0);
    max_windth = items[0]->boundingRect().width();
    for(int i = 0; i < m_iNum; i = 3 + i)
    {
      if(items[i]->boundingRect().width() >= max_windth)
      {
          max_windth = items[i]->boundingRect().width();
          max_windth_index = i;
      }
    }
    for(int i = 1; i < m_iNum; i = 3 + i)
    {
        items[i]->setX(items[max_windth_index]->boundingRect().width());
    }
    max_windth = items[1]->boundingRect().width();
    for(int i = 1; i < m_iNum; i = 3 + i)
    {
        if(items[i]->boundingRect().width() >= max_windth)
        {
            max_windth = items[i]->boundingRect().width();
            max_windth_index = i;
        }
    }
    for(int i = 2; i < m_iNum; i = 3 + i)
    {
        items[i]->setX(items[1]->pos().x() + items[max_windth_index]->boundingRect().width());
    }

}

void MatrixItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QFontMetrics fm(font);

    QPen pen;

    qreal pw = 5.0;

    pen.setWidthF(fm.size(Qt::TextSingleLine, "0").height()*0.05);
    painter->setPen(pen);

    painter->drawLine(QPointF(-2.0, boundingRect().top()),
                      QPointF(-2.0, boundingRect().bottom()));

    painter->drawLine(QPointF(boundingRect().width()+2.0, boundingRect().top()),
                      QPointF(boundingRect().width()+2.0, boundingRect().bottom()));

    pen.setWidthF(pen.widthF() / 2.0);
    painter->setPen(pen);
    painter->drawLine(QPointF(-2.0, boundingRect().top()),
                      QPointF(-2.0 + pw, boundingRect().top()));
    painter->drawLine(QPointF(2.0, boundingRect().bottom()),
                      QPointF(2.0 + pw, boundingRect().bottom()));
    painter->drawLine(QPointF(boundingRect().width()-2.0, boundingRect().top()),
                      QPointF(boundingRect().width()-(2.0 + pw), boundingRect().top()));
    painter->drawLine(QPointF(boundingRect().width()-2.0, boundingRect().bottom()),
                      QPointF(boundingRect().width()-(2.0 + pw), boundingRect().bottom()));


}

