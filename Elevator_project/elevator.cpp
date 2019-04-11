#include "elevator.h"
#include "iostream"
#include "floor.h"


using namespace std;




void Elevator::add_floor()
{
    Floor *floor = new Floor(floors.length() + 1, scene->height());
    floors.push_back(floor);
    scene->addItem(floor->Getgroup());
}

Elevator::Elevator()
{
    timer.setFrameRange(0, 90);
    timer.setDuration(3000);
}

void Elevator::setscene(QGraphicsScene *pointer_scene)
{
    scene = pointer_scene;
    Floor *first_floor = new Floor(1, scene->height());
    floors.push_front(first_floor);
    Floor *second_floor = new Floor(2, scene->height());
    scene->addItem(first_floor->Getgroup());
    scene->addItem(second_floor->Getgroup());


}



void Elevator::Show()
{
        cout << "bbbb  " << floors_table.length() << endl;
}
