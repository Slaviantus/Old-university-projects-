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
    //======================================
    current_floor++;
    emit(floor_Changed());


}

void Elevator::calling_the_floor(int floor_number)
{
    for(int i = 0; i < floors_table.size(); i++)
    {
        if(i == floor_number - 1)
        {
            floors_table[i] = true;
        }
    }
}

void Elevator::floor_button_clicked(QString string)
{
cout << "KEK" << endl;
}

void Elevator::Go_One_floor()
{
    timer_one_floor.start();
}

void Elevator::Go()
{
    if(check_floors() && STOPPING)
        {
            Elevator_state::MOVING;
            for(int i = current_floor - 1; i < floors_table.size(); i++)
            {
               if(floors_table[i])
                {
                   floor_difference_up = abs(i + 1 - current_floor);
                }
           }
           for(int i = current_floor - 1; i == 0; i--)
           {
                if(floors_table[i])
                {
                  floor_difference_down = abs(i + 1 - current_floor);
                }
           }
            if(floor_difference_up >= floor_difference_down)
            {
                Elevator_direction::UP;
            }
            else
            {
                Elevator_direction::DOWN;
          }
         if(UP)
            {
                for(int i = 0; i < floor_difference_up; i++)
                {
                    Go_One_floor();
                   current_floor++;
                }
            }
            else
            {
                for(int i = 0; i < floor_difference_down; i++)
                {
                   Go_One_floor();
                    current_floor--;
                }
           }
            Stopping();
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

void Elevator::Stopping()
{

}

Elevator::Elevator()
{
     timer_one_floor.setDuration(3000);
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

int Elevator::get_current_floor()
{
    return current_floor;
}


