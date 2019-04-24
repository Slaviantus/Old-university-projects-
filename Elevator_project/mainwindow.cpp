#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include "iostream"
#include "QGraphicsScene"
#include "gscene.h"
#include "QString"
#include "QVariant"
#include "elevator.h"
#include "QFontDatabase"
#include "QPalette"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPalette pal;
    pal.setColor(QPalette::Normal, QPalette::WindowText, Qt::red);
    pal.setColor(QPalette::Background, Qt::black);
    ui->lcdnumber->setAutoFillBackground(true);
    ui->lcdnumber->setPalette(pal);
    connect(&ui->graphicsView->elevator, SIGNAL(floor_Changed()), this, SLOT(indicator()));


    floor_button_name = 0;

    //==================experiment===================

    QPixmap pixmap;
    pixmap.load(":/textures/images/tardis_experiment.png");
    ui->pointer_label->setPixmap(pixmap);

    //==================experiment end===================


    on_add_floor_clicked();
    on_add_floor_clicked();
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::indicator()
{
    ui->lcdnumber->display(ui->graphicsView->elevator.get_current_floor());
}



void MainWindow::on_add_floor_clicked()
{
    floor_button_name++;
    QPushButton* pushButton = new QPushButton(ui->scrollAreaWidgetContents);
    pushButton->setText(QVariant(floor_button_name).toString());
    pushButton->setObjectName(QVariant(floor_button_name).toString());
    connect(pushButton, SIGNAL(clicked()), &ui->graphicsView->elevator, SLOT(calling_the_floor()));
    ui->verticalLayout_2->addWidget(pushButton);
}

