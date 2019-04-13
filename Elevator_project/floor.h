#ifndef FLOOR_H
#define FLOOR_H
#include "QGraphicsRectItem"
#include "QGraphicsItemGroup"
#include "QPen"
#include "QTimer"
#include "QObject"
#include "QGraphicsItem"
#include "QPoint"
#include "QGraphicsPixmapItem"
#include "QPixmap"
#include "QTimeLine"

class Floor : public QObject
{
    //Q_OBJECT
public:
    Floor(int number, QGraphicsScene *scene);
    void drawfloor();
    QGraphicsItemGroup* Getgroup();
    void setnumber(int num);
    void Opendoors();
    void Closedoors();
    int Get_number();
    ~Floor();
private:
    QPen floorpen;
    QGraphicsPixmapItem* plate;
    QGraphicsPixmapItem* rightwall;
    QGraphicsPixmapItem* leftwall;
    QGraphicsPixmapItem* beam;
    QGraphicsPixmapItem* leftdoor;
    QGraphicsPixmapItem* rightdoor;
    QGraphicsPixmapItem* background;
    QGraphicsItemGroup* floorgroup;
    QPoint point_left_wall;
    QPoint point_right_wall;
    QPoint point_right_door;
    QPoint point_left_door;
    QPoint point_plate;
    QPoint point_beam;
    QPoint point_background;
    QPixmap right_door_pixmap;
    QPixmap left_door_pixmap;
    QPixmap left_wall_pixmap;
    QPixmap right_wall_pixmap;
    QPixmap plate_pixmap;
    QPixmap beam_pixmap;
    QPixmap background_pixmap;
    QTimeLine doorsTimeLine;
    int number;
private slots:
    void setDoorsPos_open(int x);
    void setDoorsPos_close(int x);
    int i;
};

#endif // FLOOR_H
