#include "workplace.h"
#include "QPainter"


workplace::workplace()
{
  setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
}

void workplace::setdata(int x, int y, int height, int wingth)
{
    rect.setHeight(height);
    rect.setWidth(wingth);
    point.setX(x);
    point.setY(y);
    rect.setTopLeft(point);
}

void workplace::paintEvent(QPaintEvent *event)
{
    //QPainter painter(this);
    //painter.setRenderHint(QPainter::Antialiasing);
    //painter.fillRect(rect, Qt::red);
    //painter.setTransform(t);
    //painter.setPen(Qt::red);
    //painter.drawRect(rect);
}
