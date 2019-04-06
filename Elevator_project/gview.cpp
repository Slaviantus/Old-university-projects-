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
    scene = new QGraphicsScene(0, 0, 741, 1000, this);
    scene->addRect(scene->sceneRect());//рисуем прямоугольник границы сцены
    setScene(scene);

    first_floor = new Floor(1, scene->height());
    floors.push_front(first_floor);
    second_floor = new Floor(2, scene->height());
    floors.push_back(second_floor);
    scene->addItem(first_floor->Getgroup());
    scene->addItem(second_floor->Getgroup());
    for(auto i = floors.begin(); i != floors.end(); i++)
    {
        cout << *i << endl;
    }

}

Gview::~Gview()
{
    for(auto i = floors.begin(); i != floors.end(); i++)
    {
        cout << *i << endl;
        delete *i;
    }
}

void Gview::add_floor()
{
    Floor *floor = new Floor(floors.length() + 1, scene->height());
    floors.push_back(floor);
    scene->addItem(floor->Getgroup());
}

