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

class Gview : public QGraphicsView //класс окна графического представления QGraphicsView
{
 Q_OBJECT
public:
    Gview(QWidget *parent = 0);
    ~Gview();
private:
    QGraphicsScene *scene;
    Elevator elevator;
private slots:
    void add_floor();
public slots:
    void floor_button();
};

#endif // GVIEW_H
