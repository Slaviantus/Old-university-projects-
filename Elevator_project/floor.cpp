#include "floor.h"
#include "QGraphicsRectItem"
#include "QGraphicsItem"
#include "QRect"
#include "QTimer"
#include "QGraphicsPixmapItem"
#include "QPixmap"

using namespace std;

Floor::Floor()
{
    floorpen.setColor(Qt::gray);
    floorpen.setWidth(1);
    point_plate.setX(0);
    point_plate.setY(200);
    point_right_door.setX(371);
    point_right_door.setY(30);
    point_left_door.setX(342);
    point_left_door.setY(30);

    plate = new QGraphicsRectItem;
    plate->setPen(floorpen);
    plate->setBrush(Qt::green);
    platerect.setWidth(741);
    platerect.setHeight(20);
    plate->setRect(platerect);
    plate->setPos(point_plate);
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
    beamrect.setWidth(181);
    beam->setRect(beamrect);
    beam->setPos(280, 0);
    beam->setZValue(0);
    leftdoor = new QGraphicsPixmapItem;
    leftdoor->setPos(point_left_door);
    leftdoor->setZValue(-1);
    left_door_pixmap.load(":/textures/images/left_door.png");
    leftdoor->setPixmap(left_door_pixmap);
    rightdoor = new QGraphicsPixmapItem;
    rightdoor->setPos(point_right_door);
    rightdoor->setZValue(-1);
    right_door_pixmap.load(":/textures/images/right_door.png");
    rightdoor->setPixmap(right_door_pixmap);
    floorgroup = new QGraphicsItemGroup;
    floorgroup->addToGroup(plate);
    floorgroup->addToGroup(leftwall);
    floorgroup->addToGroup(rightwall);
    floorgroup->addToGroup(beam);
    floorgroup->addToGroup(leftdoor);
    floorgroup->addToGroup(rightdoor);
    floorgroup->setPos(0,500);

    this->doors();
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

void Floor::Opendoors()
{
    rightdoor->setPos(i,0);
    i++;

}

void Floor::doors()
{
    doorstimer = new QTimer(this);
    doorstimer->start(500);
    connect(doorstimer, SIGNAL(timeout()), this, SLOT(Opendoors()));
    i = 371;
}
