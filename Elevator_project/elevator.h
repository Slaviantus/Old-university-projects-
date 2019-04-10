#ifndef ELEVATOR_H
#define ELEVATOR_H
#include "QGraphicsScene"
#include "QList"
#include "QVector"
#include "floor.h"
#include "QTimeLine"


class Elevator
{
private:
    QList<Floor*> *floors;
    QList<Floor*>::iterator it;
    QVector<bool> floors_table;
    int current_floor;
    void Go_one_floor();
    QTimeLine timer;
public:
    Elevator();
    void set_list(QList<Floor*> *pointer_list);
    void Goto_floor(int floornum);
    void add_floor();
    void Show();
   };

#endif // ELEVATOR_H
