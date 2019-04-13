#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include "iostream"
#include "QGraphicsScene"
#include "gscene.h"

using namespace std;

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



void MainWindow::on_add_floor_clicked()
{
    QPushButton* pushButton = new QPushButton(ui->scrollAreaWidgetContents);
    pushButton->setText("kek");
    ui->verticalLayout_2->addWidget(pushButton);
}
