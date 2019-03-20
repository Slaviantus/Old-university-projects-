#include "gscene.h"
#include "QWidget"

GScene::GScene(QWidget *parent):QWidget(parent)//конструктор виджета
{
    GLayoutScene = new QHBoxLayout(this);
    PGView = new Gview;
    GLayoutScene->addWidget(PGView);
    setLayout(GLayoutScene);
}
