#include "gview.h"
#include "iostream"
#include "QDebug"
#include "floor.h"
#include "QRect"

using namespace std;

Gview::Gview(QWidget *parent):QGraphicsView (parent)//конструктор графического представления
{
    scene = new QGraphicsScene(0, 0, 741, 1000, this);
    scene->addRect(scene->sceneRect());//рисуем прямоугольник границы сцены
    setScene(scene);

    myRectTimer = new QTimer(this);
    myRectTimer->start(1000);
    connect(myRectTimer, SIGNAL(timeout()), this, SLOT(myTimerRect()));
    rectItem = new QGraphicsRectItem(0, 0, 200, 200);//координаты в QGraphicscene
    rectItem->setPen(QPen(Qt::blue, 2, Qt::DotLine));//редактирование обводки объекта
    rectItem->setBrush(Qt::green);//заливка объекта
    scene->addItem(rectItem);
    Floor *fl = new Floor;
    QRect rect;
    rect.setWidth(100);
    rect.setHeight(100);
    fl->setRect(rect);
    fl->setPos(0, 0);
    fl->setPen(QPen(Qt::red, 7));
    fl->setBrush(Qt::blue);
    scene->addItem(fl);
}

void Gview::myTimerRect()
{
  static int i = 0;
  i++;
  rectItem->setPos(i,0);
}
