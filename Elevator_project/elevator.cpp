#include "elevator.h"
#include "iostream"

using namespace std;



Elevator::Elevator()
{
    timer.setFrameRange(0, 90);
    timer.setDuration(3000);
}

void Elevator::set_list(QList<Floor *> *pointer_list)
{
    floors = pointer_list;
    floors_table.resize(floors->length());
}

void Elevator::Goto_floor(int floornum)
{
    for(int i = 0; i < floors_table.size(); i++)
    {
        if(floornum == i + 1)
        {
            floors_table[i] = true;
        }
    }
}

void Elevator::add_floor()
{
    floors_table.resize(floors_table.length() + 1);
}

void Elevator::Show()
{
    cout << "aaaa  " << floors->length() << endl;
    cout << "bbbb  " << floors_table.length() << endl;
}
