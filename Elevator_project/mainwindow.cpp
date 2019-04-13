#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include "iostream"
#include "QGraphicsScene"
#include "gscene.h"
#include "QString"
#include "QVariant"
#include "elevator.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    floor_button_name = 0;
    on_add_floor_clicked();
    on_add_floor_clicked();
}


MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_add_floor_clicked()
{
    floor_button_name++;
    QPushButton* pushButton = new QPushButton(ui->scrollAreaWidgetContents);
    pushButton->setText(QVariant(floor_button_name).toString());
    pushButton->setObjectName(QVariant(floor_button_name).toString());
    connect(pushButton,SIGNAL(clicked()), ui->graphicsView, SLOT(floor_button()));
    ui->verticalLayout_2->addWidget(pushButton);

   }
