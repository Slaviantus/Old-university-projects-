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

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    int id = QFontDatabase::addApplicationFont(":/textures/fonts/a_lcdnova_[allfont.ru].ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont monospace(family);
    //connect(&num, SIGNAL(changed()), this, SLOT(show()));
    //ui->lcdnumber->display(num);
    //num++;

    //connect(&ui->graphicsView->elevator, SIGNAL(ui->graphicsView->elevator.floor_Changed()), this, SLOT(indicator()));


    floor_button_name = 0;
    on_add_floor_clicked();
    on_add_floor_clicked();
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::indicator()
{
    //ui->lcdnumber->display(ui->graphicsView->elevator.get_current_floor());
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

