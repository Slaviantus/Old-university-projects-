#include "mainwindow.h"
#include <trainsmodel.h>
#include "QMainWindow"
#include <QTableView>

using namespace std;

MainWindow::MainWindow(Trainsmodel *pmodel,QWidget *parent = 0) : QMainWindow(parent)
{
    if(pmodel)
    {
        m_priew=new QTableView; //�������� �������
        setCentralWidget(m_priew); //� ������ ����
        m_priew->setModel(pmodel); //������ ������� ����� ������������
    }
    m_priew->horizontalHeader()->resizeSection(0,200);
    m_priew->horizontalHeader()->resizeSection(1,380);
    m_priew->horizontalHeader()->resizeSection(2,150);

}

MainWindow::~MainWindow()
{

}
