#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QAction>
#include "QGraphicsScene"
#include "gscene.h"
#include "elevator.h"
#include "QPixmap"


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
void show_pointer_up();
void show_pointer_down();
void show_no_pointer();

public slots:
void on_add_floor_clicked();

private:
    Ui::MainWindow *ui;
    QPainter Painter;
    Elevator *elevator;
    int floor_button_name;
    QPixmap pointer_up_pixmap;
    QPixmap pointer_down_pixmap;
    QPixmap no_pointer_pixmap;



};

#endif // MAINWINDOW_H
