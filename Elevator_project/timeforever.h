#ifndef TIMEFOREVER_H
#define TIMEFOREVER_H
#include <QTimer>
#include <iostream>


using namespace std;

class timeforever
{
    Q_OBJECT

    QTimer timers;
public:
    timeforever();
public slots:
    void time_is_over();
};

#endif // TIMEFOREVER_H
