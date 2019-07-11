#include "summa.h"
#include "place.h"
#include <QPainter>
#include "modelscene.h"
#include <QDebug>
#include <QGraphicsSceneMouseEvent>

Summa::Summa(const QFont &font, bool sum, QObject *parent):
    CommonItem(font, SUM_NUM_OF_PARTS, parent)
{
    isSum = sum;
    Symbol = QFont("Symbol", font.pointSize() * 1.5); //для знака суммы устанавливаем шрифт "symbol" и увеличиваем его размер в 1.5 раза
    Elements = QFont(font);  //стандартный шрифт
    Elements.setPointSize(font.pointSize() * 0.75);//размер уменьшили до 75% от базового


    items[5] = new Place(font);
    items[5]->setParentItem(this);

    for (int i(1); i < m_iNum - 1; ++i) {
        items[i] = new Place(Elements);
        items[i]->setParentItem(this);
    }

    items[0] = new Place(Symbol);
    items[0]->setParentItem(this);

    items[0]->setRestriction(Place::IDOnly);    // только для текста
    items[0]->enableEditable(false);                // нередактируемый
    if (isSum)
        items[0]->setText("S");  //в шрифте "symbol" буква S выглядит как символ суммы
    else
        items[0]->setText("P");  //в шрифте "symbol" буква P выглядит как символ произведения

    items[1]->setRestriction(Place::IDOnly);    // только для текста
    items[1]->enableEditable(true);                // редактируемый

    items[2]->setRestriction(Place::IDOnly);   // только для текста
    items[2]->enableEditable(true);                // редактируемый

    items[3]->setRestriction(Place::IDOnly);    // только для текста
    items[3]->enableEditable(false);                // нередактируемый
    items[3]->setText("=");

    items[4]->setRestriction(Place::IDOnly);    // только для текста
    items[4]->enableEditable(true);                   // редактируемый

    items[5]->setRestriction(Place::None);    // все вставляется
    items[5]->enableEditable(true);                // редактируемый

    this->updateSize();
}

void Summa::setChildPos()
{

    qreal h, yh0, leftWidthL, leftWidthR, maxHeight(0.0); //
    for (int i(2); i < m_iNum - 1; ++i)   // определяется высота самого "высокого" дочернего элемента из нижних
    {
        h = items[i]->boundingRect().height();
        if (h > maxHeight)
            maxHeight = h;
    }

    yh0 = items[0]->pos().y() + items[0]->boundingRect().height(); //коорд-та по У верхней границы для нижних элементов

    //координата по Х для левой границы правой части
    leftWidthR = 1.05 * qMax(items[1]->boundingRect().width() + items[1]->pos().x(),
            items[4]->boundingRect().width() + items[4]->pos().x());
    //переменная, чтоб левая часть не "налезала" на другой элемент справа
    leftWidthL = 1.05 * qMax(items[1]->boundingRect().width(),
            (items[2]->boundingRect().width() + items[3]->boundingRect().width() / 2) * 2);
    //устанавливаем позиции всех элементов
    items[0]->setPos((leftWidthL - items[0]->boundingRect().width())/2, items[1]->boundingRect().height()); //символ суммы
    items[1]->setPos(items[0]->pos().x() + (items[0]->boundingRect().width() - items[1]->boundingRect().width()) / 2, 0.0); //верхний
    items[3]->setPos(items[0]->pos().x() + (items[0]->boundingRect().width() - items[3]->boundingRect().width()) / 2,
            (maxHeight - items[1]->boundingRect().height()) / 2 + yh0); //нижний знак равно
    items[2]->setPos(items[3]->pos().x() - items[2]->boundingRect().width() ,
            (maxHeight - items[1]->boundingRect().height()) / 2 + yh0); //нижний левый
    items[4]->setPos(items[3]->pos().x() + items[3]->boundingRect().width(),
            (maxHeight - items[2]->boundingRect().height()) / 2 + yh0); //нижний правый
    items[5]->setPos(leftWidthR,
                     (items[0]->boundingRect().height() - items[5]->boundingRect().height()) / 2 + items[0]->pos().y()); //правый главный
}


