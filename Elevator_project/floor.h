#ifndef FLOOR_H
#define FLOOR_H
#include "QGraphicsRectItem"
#include "QGraphicsItemGroup"
#include "QPen"

class Floor : public QGraphicsItemGroup
{
public:
    Floor();
    void drawfloor();
private:
    QPen floorpen;
    QGraphicsRectItem* plate;
    QGraphicsRectItem* rightwall;
    QGraphicsRectItem* leftwall;
    QGraphicsRectItem* beam;
    QGraphicsRectItem* leftdoor;
    QGraphicsRectItem* rightdoor;
    QGraphicsRectItem* background;
};

#endif // FLOOR_H
