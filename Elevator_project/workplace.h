#ifndef WORKPLACE_H
#define WORKPLACE_H

#include <QWidget>
#include <QRect>
#include <QPoint>
#include <QPainter>
#include "QGraphicsView"

class workplace : public QWidget, public QGraphicsView
{
public:
    workplace();
    void setdata(int x, int y, int height, int wingth);
public slots:
    void paintEvent(QPaintEvent * event);
private:
    QRect rect;
    QPoint point;
    QTransform t;

};

#endif // WORKPLACE_H
