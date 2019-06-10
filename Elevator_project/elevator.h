#ifndef ELEVATOR_H
#define ELEVATOR_H
#include "QGraphicsScene"
#include "QList"
#include "QVector"
#include "floor.h"
#include "QTimeLine"
#include "QString"
#include "QGraphicsLineItem"
#include "QGraphicsItemGroup"
#include "QPen"
#include "QPoint"
#include "QTimer"
#include "QPixmap"


enum Elevator_state
{
    MOVING,
    STOPPING
};

enum Elevator_direction
{
    UP,
    DOWN,
    NOTHING
};



class Elevator : public QObject
{
    Q_OBJECT
private:
    QVector<bool> floors_table;
    QVector<int> stop_points;
    void Go();
    void Change_direction();
    bool check_floors();
    void Stopping();
    void Elevator_manager();
    QList <Floor*> floors;
    QList <Floor*>::iterator it;
    QGraphicsScene *scene;
    QTimer *timer_up;
    QTimer *timer_down;
    QTimeLine timer_stopping;
    int floor_difference_up;
    int floor_difference_down;
    int state;
    int direction;
    int number;
    int current_floor;
    int departure_floor;
    QPen pen;
    QGraphicsLineItem* left_vertical;
    QGraphicsLineItem* right_vertical;
    QGraphicsLineItem* horizontal_up;
    QGraphicsLineItem* horizontal_down;
    QGraphicsPixmapItem* background;
    QGraphicsItemGroup* elevator_shape;
    QPixmap background_pixmap;
    QPoint new_position;
    QPoint stop_position;
    int new_y;
    int iup;
    int i;
    bool still_stopping;
    bool transparency;
    bool elevator_away;
    bool uskoreniye;
    bool is_elevator_on_current_floor;




signals:
    void floor_Changed();
    void carry_on();
    void doors_are_closed();
    void pointer_up();
    void pointer_down();
    void no_pointer();
    void stop();

  public:
    Elevator();
    ~Elevator();
    void setscene(QGraphicsScene *pointer_scene);
    int get_current_floor();
    void add_floor();
    void delete_floor();
    bool is_elevator_shown();
    bool is_elevator_away();
private slots:
    void go_up();
    void go_down();
    void Check_moving();
    void Closing_doors();
    void control_carry_on();
    void floor_button_clicked();

public slots:
    void calling_the_floor();
    void show_elevator();
    void hide_elevator();
   };

#endif // ELEVATOR_H
