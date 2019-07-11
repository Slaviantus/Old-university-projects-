#include "matrixitem.h"
#include "place.h"


MatrixItem::MatrixItem(const QFont &font, QObject *parent) : CommonItem(font, MATRIX_PARTS, parent)
{
    for (int i(0); i<m_iNum; ++i) {                           // создание и настройка типа дочерних элементов - зависит от типа родительского элемента
        items[i] = new Place(font);                                     // создание
        items[i]->setParentItem(this);                                  // данный объект задается дочерним в качестве родителя
        //items[i]->setRestriction(i == 1 ? Place::IDOnly : Place::None); // второй из трех дочерний элемент может содержать только текст
        //items[i]->enableEditable(i == 1 ? false : true);                // первый и последний дочерние элементы - редактируемые
    }

    setChildPos();
}

void MatrixItem::setChildPos()
{

}
