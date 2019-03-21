#ifndef FLOOR_H
#define FLOOR_H
#include "QGraphicsRectItem"
#include "QPen"

class Floor : public QGraphicsRectItem
{
public:
    Floor();
    void drawfloor();
private:
    QPen floorpen;
};

#endif // FLOOR_H
