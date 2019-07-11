#ifndef MODELSCENE_H
#define MODELSCENE_H

#include <QGraphicsScene>
#include <QList>
#include "dequation.h"

/**
  Класс модели.
  Является производным от класса графической сцены.
  Представляет в приложении математическую модель, т.к. агрегирует в себе все уравнения модели, как дочерние объекты.
**/
class ModelScene : public QGraphicsScene
{
    Q_OBJECT

    QList<Equation *> equations;
    QFont commonFont;                                   // шрифт с общими (глобальными) параметрами
    QBrush selBrush;
    QPen selPen;
    CommonItem *selItem;
    QGraphicsRectItem *selRectItem;

public:
    enum ItemTypes { ITUnknown,
        ITAE, ITDE, ITBinDiv, ITBinMult, ITBinPlus, ITBinMinus, ITBinPwr, ITMatrix2, ITMatrix3,
        ITVector2, ITVector3, ITSumma, ITProduct, ITRoundPars, ITSquareRoot, ITUnaryFunction, ITUnaryMinus,
        ITFracion, ITTimeDer, ITTranspose, ITCrossProduct, ITScalarProduct, ITAbsValue
    };

public:
    explicit ModelScene(QObject *parent = 0);
    void addDEquation(DEquation *equation = 0);
    qreal interval();
    void setCommonFontSize(const int size);
    QFont getCommonFont();
    void setSelectedItem(CommonItem *item);
    void unselectItem();
    CommonItem *getSelectedItem();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    Place *activePlace();
    void updateEquations(int index = -1);
private:
    void insertItem(CommonItem *item, Place *place);
    Place *getPlaceToInsert();
    CommonItem *getNewItem(const ItemTypes itemType, const QFont font);
signals:

public slots:
    void insertItemWrapper(ModelScene::ItemTypes itemType);


};

#endif // MODELSCENE_H
