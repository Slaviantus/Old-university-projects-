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

class Gview : public QGraphicsView //класс окна графического представления QGraphicsView
{
 Q_OBJECT
public:
    Gview(QWidget *parent = 0);
    ~Gview();
private:
    QGraphicsScene *scene;
    QList <Floor*> floors;
    QList <Floor*>::iterator it;
    Floor *first_floor;
    Floor *second_floor;
private slots:
    void add_floor();
public slots:
};

#endif // GVIEW_H
