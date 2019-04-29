#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <trainsmodel.h>
#include <QTableView>

using namespace std;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(Trainsmodel *pmodel,QWidget *parent = 0);
    ~MainWindow();

private:
    QTableView *m_priew;
};

#endif // MAINWINDOW_H
