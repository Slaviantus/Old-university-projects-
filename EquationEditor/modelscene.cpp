#include "modelscene.h"
#include "binaryitem.h"
#include "summa.h"
#include "poweritem.h"
#include "vectoritem.h"
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include "matrixitem3x3.h"
#include "matrixitem2x2.h"
#include "iostream"
#include <QGraphicsTextItem>  // временно

using namespace std;

ModelScene::ModelScene(QObject *parent) :
    QGraphicsScene(parent),
    commonFont("Times New Roman", 20)
{
    selBrush = QBrush(QColor(200, 200, 255, 255));
    selPen = QPen(Qt::NoPen);

    selRectItem = new QGraphicsRectItem();
    addItem(selRectItem);
    selRectItem->setPen(selPen);
    selRectItem->setBrush(selBrush);
    selRectItem->setVisible(false);

    // дл¤ отладки - создание тестовых уравнений
    addDEquation();

    DEquation *deq = static_cast<DEquation *>(equations.last());
    deq->getLeft()->setText("X");

    BinaryItem *mult = new BinaryItem(commonFont, "*");
    mult->getLeft()->setText("x");
    mult->getRight()->setText("y");
    deq->getRight()->insertItem(mult);

    addDEquation();

    deq = static_cast<DEquation *>(equations.last());
    deq->getLeft()->setText("y_4");
    PowerItem *pwr1 = new PowerItem(commonFont);
    pwr1->getFirstEditablePlace()->setText("X");
    pwr1->getNextEditablePlace(pwr1->getFirstEditablePlace())->setText("5");
    deq->getRight()->insertItem(pwr1);

    addDEquation();
    deq = static_cast<DEquation *>(equations.last());
    deq->getLeft()->setText("l");
    MatrixItem3x3 *matrix3x3 = new MatrixItem3x3(commonFont);
    Matrixitem2x2 *matrix2x2 = new Matrixitem2x2(commonFont);


    deq->getRight()->insertItem(matrix3x3);
    deq->getLeft()->insertItem(matrix2x2);



    updateEquations();

}

void ModelScene::addDEquation(DEquation *equation)
{
    if (!equation) {
        equation = new DEquation(commonFont);
    }
    addItem(equation);
    QRectF  prevEqRect = equations.size() ? equations.last()->boundingRect() : QRectF(20.0, 0.0, 1.0, 1.0);
    QPointF prevEqPos = equations.size() ? equations.last()->pos() : QPointF(20.0, 0.0);
    equation->setPos(20.0,
                     prevEqPos.y() + equation->boundingRect().bottom()  + interval());

    qDebug() << "ModelScene::addDEquation" << equation->pos() << prevEqRect.bottom();

    equations << equation;
}

qreal ModelScene::interval()
{
    return 20.0;            // временно!
}

void ModelScene::setCommonFontSize(const int size)
{
    commonFont.setPointSize(size);
}

QFont ModelScene::getCommonFont()
{
    return commonFont;
}

void ModelScene::setSelectedItem(CommonItem *item)
{
    selItem = item;
    selRectItem->setRect(selItem->mapRectToScene(selItem->boundingRect()));
    selRectItem->setVisible(true);
    update();
}

void ModelScene::unselectItem()
{
    selItem = NULL;
    selRectItem->setVisible(false);
    update();
}

CommonItem *ModelScene::getSelectedItem()
{
    return selItem;
}

void ModelScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "ModelScene::mousePressEvent: mouse pressed, scene: " << event->pos();
    unselectItem();
    QGraphicsScene::mousePressEvent(event);
}

void ModelScene::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Delete:
    case Qt::Key_Backspace:
        if (selItem) {
            Place * parItem = static_cast<Place *>(selItem->parentItem());
            if (parItem) {
                parItem->removeItem();
            } else {
                equations.removeOne(static_cast<Equation *>(selItem));
            }

            removeItem(selItem);
            unselectItem();

            update();
            event->accept();
        }
    }
    QGraphicsScene::keyPressEvent(event);
}

Place *ModelScene::activePlace()
{
    return static_cast<Place *>(Place::placeEditor()->parentItem());
}

void ModelScene::updateEquations(int index)
{
    int initIndex(index == -1 ? 0 : index);
    int n = equations.size();
    for (int i(initIndex); i<n; ++i) {
        equations[i]->updateSize();
        equations[i]->setPos(20.0,
                             (i
                              ? equations[i-1]->pos().y() + equations[i-1]->boundingRect().bottom()
                             : 0.0)
                - equations[i]->boundingRect().top() + interval());
    }
    update();
}

/**
 * @brief ModelScene::insertItem
 * Добавляет элемент item в знакоместо place. Если имеется выделенный элемент, то он
 * вставляется в первое доступное знакоместо элемента item.
 * @param item
 * Указатель на добавляемый элемент формулы
 * @param place
 * Указатель на знакоместо, в которое вставляется элемент item
 */
void ModelScene::insertItem(CommonItem *item, Place *place)
{
    Place *itemFirstEditablePlace;
    itemFirstEditablePlace = item->getFirstEditablePlace();
    place->insertItem(item);
    if (selItem) {
        itemFirstEditablePlace->insertItem(selItem);
        unselectItem();
        itemFirstEditablePlace = item->getNextEditablePlace(itemFirstEditablePlace);
    }
    place->updateSize();
    updateEquations();
    //item->updateSize();
    if (itemFirstEditablePlace)
        itemFirstEditablePlace->beginEditing();
}

/**
 * @brief ModelScene::getPlaceToInsert
 * Определяет знакоместо, в которое должен быть вставлен новый элемент.
 * Таким знакоместом может быть активное в данный момент знакоместо либо знакоместо,
 * занятое выделенным элементом.
 * @return
 * Возвращается указатель на знакоместо. Если отсутствует активное знакоместо и ни один элемент не выделен,
 * то возвращается NULL.
 */
Place *ModelScene::getPlaceToInsert()
{
    Place *place(NULL);
    place = activePlace();
    if (!place && selItem) {
        place = static_cast<Place *>(selItem->parentItem());
    }
    return place;
}

CommonItem *ModelScene::getNewItem(const ItemTypes itemType, const QFont font)
{
    switch(itemType) {
    case ITBinDiv:
        return new BinaryItem(font, "/");
    case ITBinMinus:
        return new BinaryItem(font, "-");
    case ITBinMult:
        return new BinaryItem(font, "*");
    case ITBinPlus:
        return new BinaryItem(font, "+");
    case ITBinPwr:
        return new PowerItem(font);
    case ITSumma:
        return new Summa(font, true);
    case ITProduct:
        return new Summa(font, false);
    case ITVector2:
        return new VectorItem(font, 2);
    case ITVector3:
        return new VectorItem(font, 3);
    case ITFracion:
        break;
    case ITAE:
        break;
    case ITDE:
        break;
    case ITMatrix2:
        return new Matrixitem2x2(font);
    case ITMatrix3:
        return new MatrixItem3x3(font);
    case ITRoundPars:
        break;
    case ITUnaryFunction:
        break;
    case ITSquareRoot:
        break;
    case ITUnaryMinus:
        break;
    case ITTimeDer:
        break;
    case ITTranspose:
        break;
    case ITCrossProduct:
        break;
    case ITScalarProduct:
        break;
    case ITAbsValue:
        break;
    }
    return NULL;
}
/**
 * @brief ModelScene::insertItemWrapper
 * Обертка для метода insertItem. Вызывает getPlaceToInsert для определения знакоместа для вставки нового элемента.
 * Вызов getNewItem создает новый элемент для вставки в знакоместо. Если selItem хранит
 * указатель на выделенный элемент, то этот элемент будет в insertItem вставлен в первое знакоместо нового элемента,
 * если это возможно. После этого selItem будет очищен.
 */
void ModelScene::insertItemWrapper(ItemTypes itemType)
{
    Place *place = getPlaceToInsert();
    if (!place) return;
    CommonItem *item = getNewItem(itemType, place->getFont());
    if (item)
        insertItem(item, place);
}
