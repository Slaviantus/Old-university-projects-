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
#include "QFont"
#include "QColor"
#include "button_plate.h"

class Floor : public QObject
{
    Q_OBJECT
public:
    Floor(int number, QGraphicsScene *scene);
    QGraphicsItemGroup* Getgroup();
    void setnumber(int num);
    void Opendoors();
    void Closedoors();
    QPoint Get_floor_stop_position() const;
    int Get_Y_position() const;
    bool is_button_clicked();
    int Get_number();
    void cancel_button_clicked();
    void transparency();
    void transparency_off();
    void push_button_plate();
    void button_no_active();
    void set_y(int y);
    ~Floor();
private:
    QPen floorpen;
    QGraphicsPixmapItem* plate;
    QGraphicsPixmapItem* rightwall;
    QGraphicsPixmapItem* leftwall;
    QGraphicsPixmapItem* beam;
    QGraphicsPixmapItem* leftdoor;
    QGraphicsPixmapItem* rightdoor;
    QGraphicsTextItem* text_floor;
    Button_plate* button_plate;
    QGraphicsItemGroup* floorgroup;
    QPoint point_left_wall;
    QPoint point_right_wall;
    QPoint point_right_door;
    QPoint point_left_door;
    QPoint point_plate;
    QPoint point_beam;
    QPoint point_background;
    QPoint elevator_stop_point;
    QPoint point_button_plate;
    QFont font_text_floor;
    QPixmap right_door_pixmap;
    QPixmap left_door_pixmap;
    QPixmap left_wall_pixmap;
    QPixmap right_wall_pixmap;
    QPixmap plate_pixmap;
    QPixmap beam_pixmap;
    QPixmap button_plate_pixmap;
    QPixmap pushed_button_plate_pixmap;
    QColor color_of_text_floor;
    QTimeLine doorsTimeLine;
    QTimeLine closing_doors_time_line;
    int number;
    bool button_plate_clicked;
signals:
    void doors_are_closed();
    void button_clicked();
private slots:
    void setDoorsPos_open(int x);
    void setDoorsPos_close(int x);
    void emmiting_closing_door();
    void emmiting_button_clicked();
};

#endif // FLOOR_H
