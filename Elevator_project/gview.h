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
    void add_floor();
private:
    QGraphicsScene *scene;
    QList <Floor*> floors;
private slots:

public slots:
     void on_add_floor_clicked();
};

#endif // GVIEW_H
