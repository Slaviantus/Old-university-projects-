#include "matrixitem.h"
#include "place.h"



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
    items[1]->setText("x");
    items[1]->setPos(40, 0);
    items[0]->setText("e");
    items[0]->setPos(5, this->boundingRect().height()/(-2) + 5);
    items[2]->setText("p");
    items[3]->setText("e");
    items[4]->setText("r");
    items[5]->setText("i");
    items[6]->setText("m");
    items[7]->setText("e");
    items[8]->setText("n");
 }
