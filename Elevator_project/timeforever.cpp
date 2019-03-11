#include "timeforever.h"
#include <QTimer>
#include <iostream>


using namespace std;

timeforever::timeforever()
{



  timers.start(5000);

}

void timeforever::time_is_over()
{
    cout <<"Time is over!!"<<endl;
}
