#include "gview.h"
#include "iostream"
#include "QDebug"

using namespace std;

Gview::Gview(QWidget *parent):QGraphicsView (parent)//конструктор графического представления
{
    scene = new QGraphicsScene(0, 0, 1000, 800, this);
    scene->addRect(scene->sceneRect());//рисуем прямоугольник границы сцены
    setScene(scene);

    myRectTimer = new QTimer(this);
    myRectTimer->start(1000);
    connect(myRectTimer, SIGNAL(timeout()), this, SLOT(myTimerRect()));
    rectItem = new QGraphicsRectItem(0, 0, 200, 200);//координаты в QGraphicscene
    rectItem->setPen(QPen(Qt::blue, 2, Qt::DotLine));//редактирование обводки объекта
    rectItem->setBrush(Qt::green);//заливка объекта
    scene->addItem(rectItem);
}

void Gview::myTimerRect()
{
  //qDebug() << "Exterminate!!!" << endl;
}
