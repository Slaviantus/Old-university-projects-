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
    emit floor_Changed();


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
    emit floor_Changed();

     timer_one_floor.setDuration(3000);
     pen.setColor(Qt::red);
     pen.setWidth(3);


     left_vertical = new QGraphicsLineItem;
     left_vertical->setPen(pen);
     left_vertical->setLine(0, 0, 0, 170);
     left_vertical->setZValue(1);
     right_vertical = new QGraphicsLineItem;
     right_vertical->setPen(pen);
     right_vertical->setLine(60, 0, 60, 170);
     right_vertical->setZValue(1);
     horizontal_up = new QGraphicsLineItem;
     horizontal_up->setPen(pen);
     horizontal_up->setLine(0, 0, 60, 0);
     horizontal_up->setZValue(1);
     horizontal_down = new QGraphicsLineItem;
     horizontal_down->setPen(pen);
     horizontal_down->setLine(0, 170, 60, 170);
     horizontal_down->setZValue(1);

     elevator_shape = new QGraphicsItemGroup;
     elevator_shape->addToGroup(left_vertical);
     elevator_shape->addToGroup(right_vertical);
     elevator_shape->addToGroup(horizontal_down);
     elevator_shape->addToGroup(horizontal_up);
     elevator_shape->setZValue(1);

 }

void Elevator::setscene(QGraphicsScene *pointer_scene)
{
    scene = pointer_scene;
    add_floor();
    add_floor();

    floors_table.resize(2);
    floors_table[0] = false;
    floors_table[1] = false;

    it = floors.begin();
    elevator_shape->setPos((*it)->Get_floor_stop_position());
    scene->addItem(elevator_shape);


}

int Elevator::get_current_floor()
{
    return current_floor;
}


