#include "time_again.h"
#include <iostream>

time_again::time_again()
{
    timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(action()));
    timer->start(5000);
}

void time_again::action()
{
    cout << "Exterminate!!!" << endl;
    timer->stop();
}

