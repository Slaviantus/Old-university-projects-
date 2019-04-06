#include "gscene.h"
#include "QWidget"
#include "iostream"

using namespace std;

GScene::GScene(QWidget *parent):QWidget(parent)//конструктор виджета
{
    GLayoutScene = new QHBoxLayout(this);
    PGView = new Gview;
    cout << "GView created" << endl;
    cout << PGView << endl;
    GLayoutScene->addWidget(PGView);
    setLayout(GLayoutScene);
}

GScene::~GScene()
{
    cout << "GView destroyed" << endl;
    cout << PGView << endl;
    delete PGView;
}
