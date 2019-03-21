#include "floor.h"
#include "QGraphicsRectItem"
#include "QGraphicsItem"

using namespace std;

Floor::Floor()
{
    floorpen.setColor(Qt::gray);
    floorpen.setWidth(7);
    setZValue(-1);
}

void Floor::drawfloor()
{

}
