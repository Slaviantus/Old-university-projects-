#include "gview.h"
#include "iostream"
#include "QDebug"
#include "floor.h"
#include "QRect"
#include "QList"
#include "iostream"

using namespace std;

Gview::Gview(QWidget *parent):QGraphicsView (parent)//конструктор графического представления
{
    scene = new QGraphicsScene(this);
    //scene->addRect(scene->sceneRect());//рисуем прямоугольник границы сцены
    setScene(scene);
    elevator.setscene(scene);
}

Gview::~Gview()
{
delete scene;
}

void Gview::add_floor()
{
    elevator.add_floor();
}

