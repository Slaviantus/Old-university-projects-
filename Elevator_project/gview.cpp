#include "gview.h"
#include "iostream"
#include "QDebug"
#include "floor.h"
#include "QRect"
#include "QList"
#include "iostream"
#include "QGraphicsScene"

using namespace std;

Gview::Gview(QWidget *parent):QGraphicsView (parent)//конструктор графического представления
{
    scene = new QGraphicsScene(this);
    setScene(scene);
    elevator = new Elevator;
    elevator->setscene(scene);
}

Gview::~Gview()
{
    delete scene;
}

void Gview::add_floor()
{
    elevator->add_floor();
}

void Gview::delete_floor()
{
    elevator->delete_floor();
}

