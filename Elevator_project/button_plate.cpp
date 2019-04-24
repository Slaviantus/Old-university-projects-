#include "button_plate.h"
#include "iostream"
#include "QGraphicsView"
#include "QGraphicsItem"

using namespace std;



Button_plate::Button_plate()
{

}

void Button_plate::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    cout << "Hernya!!! forever!" << endl;
}
