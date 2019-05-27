#include "floor.h"
#include "QGraphicsRectItem"
#include "QGraphicsItem"
#include "QRect"
#include "QTimer"
#include "QGraphicsPixmapItem"
#include "QPixmap"
#include "QTimeLine"
#include "iostream"
#include "QGraphicsTextItem"
#include "QGraphicsScene"
#include "QFont"

using namespace std;

Floor::Floor(int number, QGraphicsScene* scene)
{
    this->number = number;
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
    point_button_plate.setX(305);
    point_button_plate.setY(90);


    doorsTimeLine.setFrameRange(0, 30);//диапазон изменённых значений
    doorsTimeLine.setDuration(2000);// время движения в сек
    doorsTimeLine.setCurveShape(QTimeLine::CurveShape::EaseInOutCurve);//плавность
    connect(&doorsTimeLine, &QTimeLine::frameChanged, this, &Floor::setDoorsPos_open);
    closing_doors_time_line.setFrameRange(0, 30);
    closing_doors_time_line.setDuration(2000);
    closing_doors_time_line.setCurveShape(QTimeLine::CurveShape::EaseInOutCurve);
    connect(&closing_doors_time_line, &QTimeLine::frameChanged, this, &Floor::setDoorsPos_close);
    connect(&closing_doors_time_line, &QTimeLine::finished, this, &Floor::emmiting_closing_door);




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
    button_plate = new Button_plate;
    button_plate->setPos(point_button_plate);
    button_plate->setZValue(1);
    button_plate_pixmap.load(":/textures/images/buttonplate.PNG");
    button_plate->setPixmap(button_plate_pixmap);
    pushed_button_plate_pixmap.load(":/textures/images/pushed_button_plate.png");


    text_floor = new QGraphicsTextItem;
    font_text_floor.setFamily("stencil");
    font_text_floor.setPointSize(12);
    text_floor->setZValue(1);
    text_floor->setFont(font_text_floor);
    text_floor->setPlainText(QVariant(this->number).toString() + " floor");
    color_of_text_floor.setRed(84);
    color_of_text_floor.setGreen(144);
    color_of_text_floor.setBlue(145);
    text_floor->setDefaultTextColor(color_of_text_floor);
    text_floor->setPos(150, 60);



    floorgroup = new QGraphicsItemGroup;
    floorgroup->addToGroup(plate);
    floorgroup->addToGroup(leftwall);
    floorgroup->addToGroup(rightwall);
    floorgroup->addToGroup(beam);
    floorgroup->addToGroup(leftdoor);
    floorgroup->addToGroup(rightdoor);
    floorgroup->addToGroup(text_floor);
    floorgroup->addToGroup(button_plate);
    floorgroup->setPos(0,-scene->height());
    elevator_stop_point.setX(342);
    elevator_stop_point.setY(-scene->height() + 30);

    button_plate_clicked = false;

    connect(button_plate, SIGNAL(button_clicked()), this, SLOT(emmiting_button_clicked()));
}


void Floor::setDoorsPos_open(int x)
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

Floor::~Floor()
{
    delete plate;
    delete rightwall;
    delete leftwall;
    delete beam;
    delete leftdoor;
    delete rightdoor;
    delete floorgroup;
}

void Floor::Opendoors()
{
    button_no_active();
    doorsTimeLine.start();
}

void Floor::Closedoors()
{
    closing_doors_time_line.start();
}

QPoint Floor::Get_floor_stop_position() const
{
    return elevator_stop_point;
}

int Floor::Get_Y_position() const
{
    return elevator_stop_point.y();
}

bool Floor::is_button_clicked()
{
    return button_plate_clicked;
}

int Floor::Get_number()
{
    return number;
}

void Floor::cancel_button_clicked()
{
    button_plate_clicked = false;
}

void Floor::transparency()
{
    floorgroup->setOpacity(0.5);
}

void Floor::transparency_off()
{
    floorgroup->setOpacity(1);
}

void Floor::push_button_plate()
{
    button_plate->setPixmap(pushed_button_plate_pixmap);
}

void Floor::button_no_active()
{
    button_plate->setPixmap(button_plate_pixmap);
}

void Floor::set_y(int y)
{
    floorgroup->setY(y);
}

void Floor::setDoorsPos_close(int x)
{
    rightdoor->setPos((point_right_door.x() + 30) - x, 30);
    leftdoor->setPos((point_left_door.x() - 30) + x, 30);
}

void Floor::emmiting_closing_door()
{
    emit doors_are_closed();
}

void Floor::emmiting_button_clicked()
{
    button_plate_clicked = true;
    emit button_clicked();
}


