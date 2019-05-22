#include "elevator.h"
#include "iostream"
#include "floor.h"
#include "QTimer"


using namespace std;




void Elevator::add_floor()
{
    Floor *floor = new Floor(floors.size() + 1, scene);
    floors.push_back(floor);
    scene->addItem(floor->Getgroup());
    floors_table.resize(floors.length());
    floors_table[floors_table.length() - 1] = false;
    if(floors.size() == 1)
    {
        stop_points.push_back(30);
    }
    else
    {
        stop_points.push_back(stop_points[floors.size() - 2] - 220);
    }
    connect(floor, SIGNAL(doors_are_closed()), this, SLOT(control_carry_on()));
    connect(floor, SIGNAL(button_clicked()), this, SLOT(floor_button_clicked()));

}

void Elevator::calling_the_floor()
{
    number = sender()->objectName().toInt();
    if(number != current_floor)
    {
    if(floors_table[number - 1] == false)
    {

    for(int i = 0; i < floors_table.size(); i++)
    {

        if(i == number - 1)
        {
            floors_table[i] = true;
        }

    }

    if((state == STOPPING) && (check_floors()) && !still_stopping)

    {
        emit carry_on();
    }

    }
    }

}

void Elevator::show_elevator()
{
    it = floors.begin();
    for(int j = 0; j < floors.size(); j++)
    {
        (*it)->transparency();
        it++;
    }
}


void Elevator::go_up()
{
    for(int u = 0; u < 1; u++)
    {
        new_y = elevator_shape->pos().y();
        new_y--;
        new_position.setY(new_y);
        elevator_shape->setPos(new_position);
        if(new_y == stop_points[current_floor - 1] - 5)
        {
            timer_up->setInterval(20);
        }
        if(new_y == stop_points[current_floor - 1] - 10)
        {
            timer_up->setInterval(15);
        }
        if(new_y == stop_points[current_floor - 1] - 20)
        {
            timer_up->setInterval(10);
        }
        if(new_y == stop_points[current_floor])
        {
            it++;
            current_floor++;
            emit floor_Changed();
            floor_difference_up--;
            if(floor_difference_up == 0)
            {
                timer_up->stop();
                emit stop();
            }
        }
    }
}

void Elevator::go_down()
{
    for(int u = 0; u < 1; u++)
    {
        new_y = elevator_shape->pos().y();
        new_y++;
        new_position.setY(new_y);
        elevator_shape->setPos(new_position);
        if(new_y == stop_points[current_floor - 2])
        {
            it--;
            current_floor--;
            emit floor_Changed();
            floor_difference_down--;
            if(floor_difference_down == 0)
            {
                timer_down->stop();
                emit stop();
            }
        }
    }
}


void Elevator::Go()
{
    if(direction == UP)
    {
        timer_up->start();
    }
    if(direction == DOWN)
    {
        timer_down->start();
    }

}



void Elevator::Change_direction()
{
            state = MOVING;
            departure_floor = current_floor;
            still_stopping = false;
            if(current_floor == floors.length()) // Если на последнем этаже
            {
                floor_difference_up = 0;
            }
            else
            {
            for(int i = current_floor - 1; i < floors_table.size(); i++)
            {
               if(floors_table[i])
                {
                   floor_difference_up = abs(i + 1 - current_floor);
                   break;
                }
              else
               {
                   floor_difference_up = 0;
               }
            }
            }
            if(current_floor == 1)
            {
                floor_difference_down = 0;
            }
            else
            {
                for(int i = current_floor - 1; i >= 0; i--)
            {
                if(floors_table[i])
                {
                  floor_difference_down = abs(i + 1 - current_floor);
                  break;
                }
                else
                {
                    floor_difference_down = 0;
                }
             }
            }

            if((floor_difference_up == 0) && (floor_difference_down != 0))
            {
                direction = DOWN;
                emit pointer_down();
            }
            if((floor_difference_down == 0) && (floor_difference_up != 0))
            {
                direction = UP;
                emit pointer_up();
            }
            if((floor_difference_up == 0) && (floor_difference_down == 0))
            {
                state = STOPPING;
                direction = NOTHING;
                emit no_pointer();
            }


            if(floor_difference_up >= floor_difference_down)
            {
                direction = UP;
                emit pointer_up();
            }
            else
            {
                direction = DOWN;
                 emit pointer_down();
          }
            if(direction != NOTHING || state != STOPPING)
            {
            Go();
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


void Elevator::Check_moving()
{
    emit no_pointer();
    it = floors.begin();
    for(int j = 0; j < floors.size(); j++)
    {
        if(j == current_floor - 1)
        {
            (*it)->Opendoors();
            break;
        }
        it++;
    }
    timer_stopping.start();
}

void Elevator::Closing_doors()
{
    it = floors.begin();
    for(int j = 0; j < floors.size(); j++)
    {
        if(j == current_floor - 1)
        {
            (*it)->Closedoors();
        }
        it++;
    }
}

void Elevator::control_carry_on()
{
    floors_table[current_floor - 1] = false;
    if(check_floors())
       {
           emit carry_on();

       }
    else
    {
        state = STOPPING;
    }
}

void Elevator::floor_button_clicked()
{
    bool is_elevator_on_current_floor;
    it = floors.begin();
    for(int j = 0; j < floors.size(); j++)
    {
        if((*it)->is_button_clicked())
        {
            if((j + 1 == current_floor) && state == STOPPING)
            {
                still_stopping = true;
                (*it)->Opendoors();
                state == MOVING;
                timer_stopping.start();
                (*it)->cancel_button_clicked();
                is_elevator_on_current_floor = true;
            }
            else
            {
            for(int i = 0; i < floors_table.size(); i++)
            {
                if(i == j)
               {
                  floors_table[i] = true;


                }
            }
            }

        }
        it++;
    }

if(!is_elevator_on_current_floor)
{
    if(state == STOPPING)

    {
        emit carry_on();
    }
    it = floors.begin();
    for(int j = 0; j < floors.size(); j++)
    {
        (*it)->cancel_button_clicked();
        it++;
    }
}
is_elevator_on_current_floor = false;
}

Elevator::Elevator()
{
    cout <<"========================================" << endl;
    emit floor_Changed();
    timer_up = new QTimer(this);
    cout << "timer up is created " << timer_up << endl;
    connect(timer_up, SIGNAL(timeout()), this, SLOT(go_up()));
    timer_up->setInterval(40);
    i = 0;
    timer_down = new QTimer(this);
    cout << "timer down is created " << timer_down << endl;
    connect(timer_down, SIGNAL(timeout()), this, SLOT(go_down()));
    timer_down->setInterval(10);
    new_position.setX(342);
    it = floors.begin();
    timer_stopping.setDuration(5000);
    connect(this, &Elevator::stop, this, &Elevator::Check_moving);
    connect(&timer_stopping, &QTimeLine::finished, this, &Elevator::Closing_doors);
    connect(this, &Elevator::carry_on, this, &Elevator::Change_direction);

     pen.setColor(Qt::black);
     pen.setWidth(3);



     left_vertical = new QGraphicsLineItem;
     cout << "left_vertical is created " << left_vertical << endl;
     left_vertical->setPen(pen);
     left_vertical->setLine(0, 0, 0, 170);
     left_vertical->setZValue(-2);
     right_vertical = new QGraphicsLineItem;
       cout << "right_vertical is created " << right_vertical << endl;
     right_vertical->setPen(pen);
     right_vertical->setLine(60, 0, 60, 170);
     right_vertical->setZValue(-2);
     horizontal_up = new QGraphicsLineItem;
    cout << "horivontal_up is created " << horizontal_up << endl;
     horizontal_up->setPen(pen);
     horizontal_up->setLine(0, 0, 60, 0);
     horizontal_up->setZValue(-2);
     horizontal_down = new QGraphicsLineItem;
     cout << "horivontal_down is created " << horizontal_down << endl;
     horizontal_down->setPen(pen);
     horizontal_down->setLine(0, 170, 60, 170);
     horizontal_down->setZValue(-2);

     background = new QGraphicsPixmapItem;
     cout << "background is created " << background << endl;
     background->setPos(0, 0);
     background->setZValue(-2);
     background_pixmap.load(":/textures/images/background.png");
     background->setPixmap(background_pixmap);

     elevator_shape = new QGraphicsItemGroup;
     cout << "elevator_shape is created " << elevator_shape << endl;
     elevator_shape->addToGroup(left_vertical);
     elevator_shape->addToGroup(right_vertical);
     elevator_shape->addToGroup(horizontal_down);
     elevator_shape->addToGroup(horizontal_up);
     elevator_shape->addToGroup(background);
     elevator_shape->setZValue(-2);

     current_floor = 1;

     state = STOPPING;

}

Elevator::~Elevator()
{
cout << "===================================" << endl;
cout << "timer up is deleted " << timer_up << endl;
cout << "timer down is deleted " << timer_down << endl;
cout << "left_vertical is deleted " << left_vertical << endl;
cout << "right_vertical is deleted " << right_vertical << endl;
cout << "horivontal_up is deleted " << horizontal_up << endl;
cout << "horivontal_down is deleted " << horizontal_down << endl;
cout << "background is deleted " << background << endl;
cout << "elevator_shape is deleted " << elevator_shape << endl;
delete timer_up;
delete timer_down;
delete left_vertical;
delete right_vertical;
delete horizontal_up;
delete horizontal_down;
delete background;
delete elevator_shape;
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


