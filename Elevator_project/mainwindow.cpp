#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include "iostream"
#include "QGraphicsScene"
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
    connect(ui->graphicsView->elevator, SIGNAL(floor_Changed()), this, SLOT(indicator()));
    connect(ui->graphicsView->elevator, SIGNAL(pointer_up()), this, SLOT(show_pointer_up()));
    connect(ui->graphicsView->elevator, SIGNAL(pointer_down()), this, SLOT(show_pointer_down()));
    connect(ui->graphicsView->elevator, SIGNAL(no_pointer()), this, SLOT(show_no_pointer()));

    floor_button_name = 0;

    pointer_up_pixmap.load(":/textures/images/pointer_up.png");
    pointer_down_pixmap.load(":/textures/images/pointer_down.png");
    no_pointer_pixmap.load(":/textures/images/pointer_null.png");
    ui->pointer_label->setPixmap(no_pointer_pixmap);

    on_add_floor_clicked();
    on_add_floor_clicked();

    ui->hide_show->setText("Show");
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::indicator()
{
    ui->lcdnumber->display(ui->graphicsView->elevator->get_current_floor());
}

void MainWindow::show_pointer_up()
{
    ui->pointer_label->setPixmap(pointer_up_pixmap);
}

void MainWindow::show_pointer_down()
{
    ui->pointer_label->setPixmap(pointer_down_pixmap);
}

void MainWindow::show_no_pointer()
{
    ui->pointer_label->setPixmap(no_pointer_pixmap);
}



void MainWindow::on_add_floor_clicked()
{
    floor_button_name++;
    QPushButton* pushButton = new QPushButton(ui->scrollAreaWidgetContents);
    button_points.push_back(pushButton);
    pushButton->setText(QVariant(floor_button_name).toString());
    pushButton->setObjectName(QVariant(floor_button_name).toString());
    connect(pushButton, SIGNAL(clicked()), ui->graphicsView->elevator, SLOT(calling_the_floor()));
    ui->floors_layout->addWidget(pushButton);
}


void MainWindow::on_hide_show_clicked()
{
    if(ui->graphicsView->elevator->is_elevator_shown())
    {
        ui->graphicsView->elevator->hide_elevator();
        ui->hide_show->setText("Show");
    }
    else
    {
    ui->graphicsView->elevator->show_elevator();
    ui->hide_show->setText("Hide");
    }
}

void MainWindow::on_delete_floor_clicked()
{
    ui->graphicsView->delete_floor();
    if(ui->graphicsView->elevator->is_elevator_away())
    {
    ui->floors_layout->removeWidget(button_points[button_points.size() - 1]);
    delete button_points[button_points.size() - 1];
    floor_button_name--;
    button_points.pop_back();
    }

}
