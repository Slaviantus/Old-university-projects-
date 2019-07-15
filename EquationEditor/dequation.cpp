#include "dequation.h"
#include "place.h"
#include <QPainter>
#include "modelscene.h"
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
//static QPlainTextEdit editWidget();

const QString DEquation::icTmpl(",    %1(0) = ");

DEquation::DEquation(const QFont &font, QObject *parent):
    Equation(font, DE_NUM_OF_PARTS, parent)
{
    for (int i(0); i<m_iNum; ++i) {
        items[i] = new Place(font);
        items[i]->setParentItem(this);
    }
    // 'd' в числ. ЛЧ ДУ
    items[0]->setRestriction(Place::IDOnly);    // только для текста
    items[0]->enableEditable(false);                // нередактируемый
    items[0]->setText("d");
    // 'dt' в знам. ЛЧ ДУ
    items[1]->setRestriction(Place::IDOnly);    // только для текста
    items[1]->enableEditable(false);                // нередактируемый
    items[1]->setText("dt");
    // перем. под знаком произв. в ЛЧ ДУ
    items[2]->setRestriction(Place::IDOnly);   // только для текста
    items[2]->enableEditable(true);                // редактируемый
    // ' = '
    items[3]->setRestriction(Place::IDOnly);    // только для текста
    items[3]->enableEditable(false);                // нередактируемый
    items[3]->setText(" = ");
    // ПЧ  ДУ
    items[4]->setRestriction(Place::None);
    items[4]->enableEditable(true);                   // редактируемый
    // ',   %1(0) = '
    items[5]->setRestriction(Place::IDOnly);    // только для текста
    items[5]->enableEditable(false);                // нередактируемый (имя переменной будет вставляться автоматически)
    items[5]->setText(icTmpl.arg("<...>"));
    // значение н.у.
    items[6]->setRestriction(Place::None);
    items[6]->enableEditable(true);                // редактируемый
    // ' = '
    items[7]->setRestriction(Place::IDOnly);    // только для текста
    items[7]->enableEditable(false);                // нередактируемый
    items[7]->setText(";");

    updateSize();
}

void DEquation::setChildPos()
{
    QFontMetrics fm(font);
    varWidth  = items[2]->boundingRect().width();
    dWidth = items[0]->boundingRect().width();
    leftWidth = 1.1 * qMax(dWidth + varWidth,
                           items[1]->boundingRect().width());
    maxHeight = qMax(fm.height()*2.2, items[4]->boundingRect().height());
    qreal textY((maxHeight - fm.height())/2);
//    items[0]->setPos(0.5 * (leftWidth - dWidth - varWidth),
//                     maxHeight/2 - fm.height()*1.1);
//    items[1]->setPos(0.5 * (leftWidth - fm.width("dt")),
//                     maxHeight/2 + fm.height()*0.1);
//    items[2]->setPos(0.5 * (leftWidth - dWidth - varWidth) + dWidth,
//                 maxHeight/2 - fm.height()*1.1);
//    items[3]->setPos(leftWidth,
//                     textY);
//    items[4]->setPos(items[3]->pos().x() + items[3]->boundingRect().width(),
//                  (maxHeight - items[4]->boundingRect().height())/2);
//    items[5]->setPos(items[4]->pos().x() + items[4]->boundingRect().width(),
//                     textY);
//    items[6]->setPos(items[5]->pos().x() + items[5]->boundingRect().width(),
//                     textY );
//    items[7]->setPos(items[6]->pos().x() + items[6]->boundingRect().width(),
//                     textY);
    items[0]->setPos(0.5 * (leftWidth - dWidth - varWidth),
                     -0.5 * items[2]->boundingRect().height());
    items[1]->setPos(0.5 * (leftWidth - fm.width("dt")),
                     0.5 * items[1]->boundingRect().height());
    items[2]->setPos(0.5 * (leftWidth - dWidth - varWidth) + dWidth,
                     -0.5 * items[2]->boundingRect().height());
    items[3]->setPos(leftWidth,
                     0.0);
    items[4]->setPos(items[3]->pos().x() + items[3]->boundingRect().width(),
            0.0);
    items[5]->setPos(items[4]->pos().x() + items[4]->boundingRect().width(),
            0.0);
    items[6]->setPos(items[5]->pos().x() + items[5]->boundingRect().width(),
            0.0 );
    items[7]->setPos(items[6]->pos().x() + items[6]->boundingRect().width(),
            0.0);

//    qDebug() << "DEquation::setChildPos: maxHeight = " << maxHeight;
}

void DEquation::updateSize()
{
    QString IC_ID;
    if (!(items[2]->getText().isEmpty())) {
        IC_ID = items[2]->getText();
    } else {
        IC_ID = "<...>";
    }
    items[5]->setText(icTmpl.arg(IC_ID));

    CommonItem::updateSize();
}

void DEquation::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::black);

    // дробная линия в ЛЧ ДУ
    painter->drawLine(0.0, 0.0, leftWidth, 0.0);

    // временно контур уравнения!!
    QPen penTemp(Qt::red);
    penTemp.setStyle(Qt::DotLine);
    painter->setPen(penTemp);
    painter->drawRect(boundingRect());
    //painter->drawRect(QRectF(QPointF(), boundingRect().size()));
}

/**
  В данном классе возвращает указатель на знакоместо, содержащее идентификатор переменной,
  стоящей в левой части ДУ под знаком производной.
**/
Place *DEquation::getLeft()
{
    return items[2];
}

/**
  В данном классе возвращает указатель на знакоместо, содержащее правую часть ДУ.
**/
Place *DEquation::getRight()
{
    return items[4];
}
