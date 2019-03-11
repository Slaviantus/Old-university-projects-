#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

   painter.drawRect(50, 50, 50, 50);

}

MainWindow::~MainWindow()
{
    delete ui;
}

