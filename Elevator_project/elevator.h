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


enum Elevator_state
{
    MOVING,
    STOPPING
};

enum Elevator_direction
{
    UP,
    DOWN
};



class Elevator : public QObject
{
    Q_OBJECT
private:
    QVector<bool> floors_table;
    int current_floor;
    void Go_One_floor();
    void Go();
    bool check_floors();
    void Stopping();
    QList <Floor*> floors;
    QList <Floor*>::iterator it;
    QGraphicsScene *scene;
    QTimeLine timer_one_floor;
    int floor_difference_up;
    int floor_difference_down;
    QPen pen;
    QGraphicsLineItem* left_vertical;
    QGraphicsLineItem* right_vertical;
    QGraphicsLineItem* horizontal_up;
    QGraphicsLineItem* horizontal_down;
    QGraphicsItemGroup* elevator_shape;


signals:
    void floor_Changed();

  public:
    Elevator();
    void setscene(QGraphicsScene *pointer_scene);
    int get_current_floor();
    void add_floor();
    void calling_the_floor(int floor_number);
private slots:
    void floor_button_clicked(QString string);
   };

#endif // ELEVATOR_H
