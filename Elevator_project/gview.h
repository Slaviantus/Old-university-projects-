#ifndef GVIEW_H
#define GVIEW_H
#include "QGraphicsView"
#include "QTimer"
#include "QWidget"
#include "QGraphicsScene"
#include "QGraphicsItem"
#include "QGraphicsRectItem"
#include "QHBoxLayout"

class Gview : public QGraphicsView //класс окна графического представления QGraphicsView
{
 Q_OBJECT
public:
    Gview(QWidget *parent = 0);
private:
    QGraphicsScene *scene;
    QGraphicsRectItem *rectItem;
    QTimer *myRectTimer;
private slots:
    void myTimerRect();
};

#endif // GVIEW_H
