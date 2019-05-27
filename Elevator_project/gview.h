#ifndef GVIEW_H
#define GVIEW_H
#include "QGraphicsView"
#include "QTimer"
#include "QWidget"
#include "QGraphicsScene"
#include "QGraphicsItem"
#include "QGraphicsRectItem"
#include "QHBoxLayout"
#include "floor.h"
#include "elevator.h"
#include "QString"


class Gview : public QGraphicsView //класс окна графического представления QGraphicsView
{
 Q_OBJECT
public:
    Gview(QWidget *parent = 0);
    ~Gview();
    Elevator *elevator;
private:
    QGraphicsScene *scene;
    int floor_number_push_button;
private slots:
    void add_floor();
public slots:
    void delete_floor();
};

#endif // GVIEW_H
