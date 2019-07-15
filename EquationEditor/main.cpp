#include "mainwindow.h"
#include <QApplication>
#include "iostream"
#include "QGraphicsItem"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    cout << "Hallo!" << endl;
    MainWindow w;
    w.show();

    return a.exec();
}
