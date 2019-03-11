#ifndef TIME_AGAIN_H
#define TIME_AGAIN_H

#include <QObject>
#include <iostream>
#include <QTimer>

using namespace std;

class time_again : public QObject
{
    Q_OBJECT
    QTimer *timer;
public:
    time_again();
private slots:
    void action();
};

#endif // TIME_AGAIN_H
