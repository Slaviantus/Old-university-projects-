#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QAction>
#include "QGraphicsScene"
#include "gscene.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
QPainter painter;
public:
    explicit MainWindow(QWidget *parent = nullptr);
void Scene_Pointer(GScene &pointer_to_scene);
    ~MainWindow();

private slots:



private:
    Ui::MainWindow *ui;
    QPainter Painter;


};

#endif // MAINWINDOW_H
