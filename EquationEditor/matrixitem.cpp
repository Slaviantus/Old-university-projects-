#include "matrixitem.h"
#include "place.h"
#include "iostream"

using namespace std;



MatrixItem::MatrixItem(const QFont &font, QObject *parent) : CommonItem(font, MATRIX_PARTS, parent)
{
    for (int i(0); i<m_iNum; ++i) {                           // создание и настройка типа дочерних элементов - зависит от типа родительского элемента
        items[i] = new Place(font);                                     // создание
        items[i]->setParentItem(this);                                  // данный объект задается дочерним в качестве родителя
        //items[i]->setRestriction(i == 1 ? Place::IDOnly : Place::None); // второй из трех дочерний элемент может содержать только текст
        //items[i]->enableEditable(i == 1 ? false : true);
         items[i]->enableEditable(true);
    }
    setChildPos();
}

void MatrixItem::setChildPos()
{
    qreal maxHeight(0.0);
    qreal h;
    for (int i(0); i<m_iNum; ++i) {             // определяется высота самого "высокого" дочернего элемента
        h = items[i]->boundingRect().height();
        if (h > maxHeight) {
            maxHeight = h;
        }
    }
    //****************experiment**************
    items[0]->setPos(0.0, 0.0);
    //items[0]->setText("r");
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

