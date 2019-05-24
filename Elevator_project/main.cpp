#include "mainwindow.h"
#include <QApplication>
#include <QTimer>
#include "iostream"
#include "QtGui"
#include <QHBoxLayout>
#include <QToolBar>
#include <QScrollArea>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QLabel>
#include <QImage>
#include <QPixmap>
#include <gview.h>
using namespace std;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

