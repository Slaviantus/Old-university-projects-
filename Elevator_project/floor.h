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

class Floor : public QObject
{
    //Q_OBJECT
public:
    Floor();
    void drawfloor();
    QGraphicsRectItem* Getplate();
    QGraphicsItemGroup* Getgroup();
private:
    QPen floorpen;
    QGraphicsPixmapItem* plate;
    QGraphicsPixmapItem* rightwall;
    QGraphicsPixmapItem* leftwall;
    QGraphicsPixmapItem* beam;
    QGraphicsPixmapItem* leftdoor;
    QGraphicsPixmapItem* rightdoor;
    QGraphicsRectItem* background;
    QGraphicsItemGroup* floorgroup;
    QRect backgroundrect;
    QPoint point_left_wall;
    QPoint point_right_wall;
    QPoint point_right_door;
    QPoint point_left_door;
    QPoint point_plate;
    QPoint point_beam;
    QPixmap right_door_pixmap;
    QPixmap left_door_pixmap;
    QPixmap left_wall_pixmap;
    QPixmap right_wall_pixmap;
    QPixmap plate_pixmap;
    QPixmap beam_pixmap;
    QPixmap background_pixmap;

    void doors();
    QTimer* doorstimer;
private slots:
    void Opendoors();
    int i;
};

#endif // FLOOR_H
