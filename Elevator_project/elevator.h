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
   // QTimeLine timer_up;
   // QTimeLine timer_down;
    QTimer *timer_up;
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
    QGraphicsItemGroup* elevator_shape;
    QPoint new_position;
    QPoint stop_position;
    int new_y;
    int iup;
    int i;



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
    void setscene(QGraphicsScene *pointer_scene);
    int get_current_floor();
    void add_floor();
private slots:
    void floor_button_clicked(QString string);
   // void go_up(int y);
    void go_up_exp();
    //void go_down(int y);
    void Check_moving();
    void Closing_doors();
    void control_carry_on();
public slots:
    void calling_the_floor();
   };

#endif // ELEVATOR_H
