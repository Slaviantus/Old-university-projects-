#ifndef FLOOR_H
#define FLOOR_H
#include "QGraphicsRectItem"
#include "QGraphicsItemGroup"
#include "QPen"

class Floor
{
public:
    Floor();
    void drawfloor();
    QGraphicsRectItem* Getplate();
    QGraphicsItemGroup* Getgroup();
private:
    QPen floorpen;
    QGraphicsRectItem* plate;
    QGraphicsRectItem* rightwall;
    QGraphicsRectItem* leftwall;
    QGraphicsRectItem* beam;
    QGraphicsRectItem* leftdoor;
    QGraphicsRectItem* rightdoor;
    QGraphicsRectItem* background;
    QGraphicsItemGroup* floorgroup;
    QRect platerect;
    QRect rightwallrect;
    QRect leftwallrect;
    QRect beamrect;
    QRect rightdoorrect;
    QRect leftdoorrect;
    QRect backgroundrect;
};

#endif // FLOOR_H
