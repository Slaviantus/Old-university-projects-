#include "floor.h"
#include "QGraphicsRectItem"
#include "QGraphicsItem"
#include "QRect"

using namespace std;

Floor::Floor()
{
    floorpen.setColor(Qt::gray);
    floorpen.setWidth(5);
    plate = new QGraphicsRectItem;
    plate->setPen(floorpen);
    plate->setBrush(Qt::green);
    QRect platerect;
    platerect.setWidth(741);
    platerect.setHeight(30);
    plate->setRect(platerect);
    plate->setPos(0, 200);
    addToGroup(plate);
    setPos(0, 400);
    leftwall = new QGraphicsRectItem;
    leftwall->setPen(floorpen);
    leftwall->setBrush(Qt::green);
    QRect leftwallrect;
    leftwallrect.setWidth(280);
    leftwallrect.setHeight(200);
    leftwall->setPos(0,0);
    addToGroup(leftwall);



}

void Floor::drawfloor()
{

}
