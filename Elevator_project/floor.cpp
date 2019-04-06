#include "floor.h"
#include "QGraphicsRectItem"
#include "QGraphicsItem"
#include "QRect"
#include "QTimer"
#include "QGraphicsPixmapItem"
#include "QPixmap"
#include "QTimeLine"

using namespace std;

Floor::Floor(int number, int scene_height)
{
    floorpen.setColor(Qt::gray);
    floorpen.setWidth(1);
    point_plate.setX(0);
    point_plate.setY(200);
    point_right_door.setX(371);
    point_right_door.setY(30);
    point_left_door.setX(342);
    point_left_door.setY(30);
    point_right_wall.setX(400);
    point_right_wall.setY(0);
    point_left_wall.setX(1);
    point_left_wall.setY(0);
    point_beam.setX(342);
    point_beam.setY(0);
    point_plate.setX(0);
    point_plate.setY(200);
    point_background.setX(342);
    point_background.setY(30);


    doorsTimeLine.setFrameRange(0, 90);//диапазон изменённых значений
    doorsTimeLine.setDuration(3000);// время движения в сек
    doorsTimeLine.setCurveShape(QTimeLine::CurveShape::EaseInOutCurve);//плавность
    connect(&doorsTimeLine, &QTimeLine::frameChanged, this, &Floor::setDoorsPos);



    plate = new QGraphicsPixmapItem;
    plate->setPos(point_plate);
    plate->setZValue(0);
    plate_pixmap.load(":/textures/images/plate.png");
    plate->setPixmap(plate_pixmap);
    rightwall = new QGraphicsPixmapItem;
    rightwall->setZValue(0);
    rightwall->setPos(point_right_wall);
    right_wall_pixmap.load(":/textures/images/right_wall.png");
    rightwall->setPixmap(right_wall_pixmap);
    leftwall = new QGraphicsPixmapItem;
    leftwall->setPos(point_left_wall);
    leftwall->setZValue(0);
    left_wall_pixmap.load(":/textures/images/left_wall.png");
    leftwall->setPixmap(left_wall_pixmap);
    beam = new QGraphicsPixmapItem;
    beam->setPos(point_beam);
    beam->setZValue(0);
    beam_pixmap.load(":/textures/images/beam.png");
    beam->setPixmap(beam_pixmap);
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
    background = new QGraphicsPixmapItem;
    background->setPos(point_background);
    background->setZValue(-2);
    background_pixmap.load(":/textures/images/background.png");
    background->setPixmap(background_pixmap);



    floorgroup = new QGraphicsItemGroup;
    floorgroup->addToGroup(plate);
    floorgroup->addToGroup(leftwall);
    floorgroup->addToGroup(rightwall);
    floorgroup->addToGroup(beam);
    floorgroup->addToGroup(leftdoor);
    floorgroup->addToGroup(rightdoor);
    floorgroup->addToGroup(background);
    floorgroup->setPos(0, scene_height - 220 * number);


//    auto timer = new QTimer(this);
//    connect(timer, &QTimer::timeout, [this]()
//    {
//        Opendoors();
//    });
//    timer->setSingleShot(true);
//    timer->start(1000);

}

void Floor::drawfloor()
{


}

QGraphicsRectItem *Floor::Getplate()
{
    //return plate;
}

void Floor::setDoorsPos(int x)
{
    rightdoor->setPos(point_right_door.x() + x, 30);
    leftdoor->setPos(point_left_door.x() - x, 30);
}

QGraphicsItemGroup *Floor::Getgroup()
{
    return floorgroup;
}

void Floor::setnumber(int num)
{
    number = num;
}

void Floor::Opendoors()
{
    doorsTimeLine.start();
}



