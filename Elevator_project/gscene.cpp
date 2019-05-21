#include "gscene.h"
#include "QWidget"
#include "iostream"

using namespace std;

GScene::GScene(QWidget *parent):QWidget(parent)//конструктор виджета
{
    GLayoutScene = new QHBoxLayout(this);
    PGView = new Gview;
    GLayoutScene->addWidget(PGView);
    setLayout(GLayoutScene);
}

GScene::~GScene()
{
    delete PGView;
}
