#include "floors.h"
#include "QPainter"
#include "QPoint"

floors::floors()
{
    point.setX(50);
    point.setY(50);
    rect.setTopLeft(point);
    rect.setHeight(100);
    rect.setWidth(100);
}

void floors::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(Qt::red);
    painter.drawRect(rect);
}
