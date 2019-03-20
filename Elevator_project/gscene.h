#ifndef GSCENE_H
#define GSCENE_H
#include "QWidget"
#include "QGraphicsView"
#include "QTimer"
#include "QGraphicsScene"
#include "QGraphicsItem"
#include "QGraphicsRectItem"
#include "QHBoxLayout"
#include "gview.h"

class GScene:public QWidget
{
    Q_OBJECT
public:
    GScene(QWidget *parent = 0);
private:
    QHBoxLayout *GLayoutScene;
    Gview *PGView;
};

#endif // GSCENE_H
