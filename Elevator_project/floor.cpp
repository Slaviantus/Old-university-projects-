#include "floor.h"
#include "QGraphicsRectItem"
#include "QGraphicsItem"
#include "QRect"

using namespace std;

Floor::Floor()
{
    floorpen.setColor(Qt::gray);
    floorpen.setWidth(1);
    plate = new QGraphicsRectItem;
    plate->setPen(floorpen);
    plate->setBrush(Qt::green);
    platerect.setWidth(741);
    platerect.setHeight(30);
    plate->setRect(platerect);
    plate->setPos(0, 200);
    plate->setZValue(0);
    rightwall = new QGraphicsRectItem;
    rightwall->setPen(floorpen);
    rightwall->setBrush(Qt::green);
    rightwall->setZValue(0);
    rightwall->setPos(461, 0);
    rightwallrect.setHeight(200);
    rightwallrect.setWidth(280);
    rightwall->setRect(rightwallrect);
    leftwall = new QGraphicsRectItem;
    leftwall->setPen(floorpen);
    leftwall->setBrush(Qt::green);
    leftwallrect.setWidth(280);
    leftwallrect.setHeight(200);
    leftwall->setRect(leftwallrect);
    leftwall->setPos(0,0);
    leftwall->setZValue(0);
    beam = new QGraphicsRectItem;
    beam->setPen(floorpen);
    beam->setBrush(Qt::green);
    beamrect.setHeight(30);
    beamrect.setWidth(170);
    beam->setRect(beamrect);
    beam->setPos(280, 0);
    beam->setZValue(0);
    floorgroup = new QGraphicsItemGroup;
    floorgroup->addToGroup(plate);
    floorgroup->addToGroup(leftwall);
    floorgroup->addToGroup(rightwall);
    floorgroup->addToGroup(beam);
    floorgroup->setPos(0,500);



}

void Floor::drawfloor()
{

}

QGraphicsRectItem *Floor::Getplate()
{
    return plate;
}

QGraphicsItemGroup *Floor::Getgroup()
{
    return floorgroup;
}
