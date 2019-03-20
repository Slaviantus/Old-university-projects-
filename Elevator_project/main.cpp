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
#include <QLabel>
#include <QImage>
#include <QPixmap>
#include <gview.h>
#include <gscene.h>
using namespace std;



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    GScene gs;
    gs.resize(1100, 900); // задаёт фиксированный размер без скролов
    //gs.show();
    w.show();
    return a.exec();
}

