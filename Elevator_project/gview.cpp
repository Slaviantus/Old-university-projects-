#include "gview.h"
#include "iostream"
#include "QDebug"
#include "floor.h"
#include "QRect"
#include "QList"
#include "iostream"
#include "gscene.h"

using namespace std;

Gview::Gview(QWidget *parent):QGraphicsView (parent)//конструктор графического представления
{
    scene = new QGraphicsScene(this);
    cout << "Scene has been created " << scene << endl;
    setScene(scene);
    elevator = new Elevator;
    cout << "elevator has been created " << elevator << endl;
    elevator->setscene(scene);
}

Gview::~Gview()
{
    cout << "Scene has been deleted " << scene << endl;
    delete scene;
    delete elevator;
    cout << "elevator has been deleted " << elevator << endl;

}

void Gview::add_floor()
{
    elevator->add_floor();
}

