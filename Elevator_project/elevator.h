#ifndef ELEVATOR_H
#define ELEVATOR_H
#include "QGraphicsScene"
#include "QList"
#include "QVector"
#include "floor.h"
#include "QTimeLine"

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



class Elevator
{
private:
    QVector<bool> floors_table;
    int current_floor;
    void Go_one_floor();
    void Go();
    bool check_floors();
    void Stopping();
    QList <Floor*> floors;
    QList <Floor*>::iterator it;
    QGraphicsScene *scene;
    QTimeLine timer;
  public:
    Elevator();
    void setscene(QGraphicsScene *pointer_scene);
    void Show();
    void add_floor();
private slots:
   };

#endif // ELEVATOR_H
