#include "elevator.h"
#include "iostream"
#include "floor.h"


using namespace std;




void Elevator::add_floor()
{
    Floor *floor = new Floor(floors.length() + 1, scene);
    floors.push_back(floor);
    scene->addItem(floor->Getgroup());
    floors_table.resize(floors.length());
    floors_table[floors_table.length() - 1] = false;
    cout << "SCENA" << scene->height() << endl;
    cout << "Floor number " << floor->Get_number() << endl;
    Show();

}

void Elevator::floor_button_clicked(QString string)
{
cout << "KEK" << endl;
}

void Elevator::Go()
{
    if(check_floors())
    {
        Elevator_state::MOVING;
        for(int i = floors_table[current_floor - 1]; i < floors_table.size(); i++)
        {
            if(floors_table[i])
            {

            }
        }


    }

}

bool Elevator::check_floors()
{
    for(int i = 0; i < floors_table.size(); i++)
    {
        if(floors_table[i])
        {
            return true;
        }
    }
    return false;
}

Elevator::Elevator()
{
    timer.setFrameRange(0, 90);
    timer.setDuration(3000);
}

void Elevator::setscene(QGraphicsScene *pointer_scene)
{
    scene = pointer_scene;
//    Floor *first_floor = new Floor(1, scene);
//    floors.push_front(first_floor);
//    Floor *second_floor = new Floor(2, scene);
//    scene->addItem(first_floor->Getgroup());
//    scene->addItem(second_floor->Getgroup());
    add_floor();
    add_floor();

    floors_table.resize(2);
    floors_table[0] = false;
    floors_table[1] = false;
}



void Elevator::Show()
{
        cout << "bbbb  " << floors_table.length() << endl;
}
