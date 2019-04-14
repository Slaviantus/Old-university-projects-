#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QAction>
#include "QGraphicsScene"
#include "gscene.h"
#include "elevator.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
QPainter painter;
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
void indicator();

public slots:
void on_add_floor_clicked();

private:
    Ui::MainWindow *ui;
    QPainter Painter;
    Elevator *elevator;
    int floor_button_name;


};

#endif // MAINWINDOW_H
