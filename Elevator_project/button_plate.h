#ifndef BUTTON_PLATE_H
#define BUTTON_PLATE_H
#include "QGraphicsPixmapItem"


class Button_plate : public QGraphicsPixmapItem
{
public:
    Button_plate();
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);

};

#endif // BUTTON_PLATE_H
