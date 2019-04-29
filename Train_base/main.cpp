#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Itemtrain train1(360, 15, "Murzen", "Avalatya", "08:00", "08:20");
    MainWindow w;
    w.show();

    return a.exec();
}
