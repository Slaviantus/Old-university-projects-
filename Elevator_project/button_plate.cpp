#include "button_plate.h"
#include "iostream"
#include "QGraphicsView"
#include "QGraphicsItem"
#include <QEvent>

using namespace std;



Button_plate::Button_plate()
{

}

bool Button_plate::sceneEvent(QEvent *event)
{
    if (event->type() == QEvent::GraphicsSceneMouseRelease)
    {
        emit button_clicked();
    }
}
