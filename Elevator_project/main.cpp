#include "mainwindow.h"
#include <QApplication>
#include <QTimer>
#include "iostream"
#include "QtGui"
#include <time_again.h>
#include <QHBoxLayout>
#include <workplace.h>
#include <QToolBar>
#include <floors.h>
#include <QScrollArea>
#include <QGraphicsView>
#include <QGraphicsScene>
using namespace std;



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    time_again u;
//    workplace *pwin = new workplace;
//    pwin->setdata(100, 100, 100, 300);
//    QToolBar *tbar = new QToolBar;
//    MainWindow w;
//    QHBoxLayout *layout = new QHBoxLayout;
//    layout->addWidget(tbar);
//    layout->addWidget(tbar)

   //w.show();
    floors *k = new floors;
    //QGraphicsScene *l = new QGraphicsScene;
    QScrollArea *scroll = new QScrollArea;
    scroll->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    scroll->setBackgroundRole(QPalette::Dark);
    k->update();
    scroll->setWidget(k);
    scroll->takeWidget()->show();
    //scroll->show();
    return a.exec();
}

