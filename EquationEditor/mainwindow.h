#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QMenu>
#include <QAction>
#include "modelscene.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QGraphicsView *view;
    ModelScene *model;

    QMenu *mainMenu;
    // уравнения
    QAction *actAddDE;
    QAction *actAddAE;
    // бинарные
    QAction *actBinPlus;
    QAction *actBinMinus;
    QAction *actBinMult;
    QAction *actBinDiv;
    QAction *actPower;
    QAction *actFraction;
    // унарные
    QAction *actUnaryMinus;
    QAction *actSquareRoot;
    QAction *actUnaryFunction;
    QAction *actRoundPars;      // скобки
    QAction *actAbsValue;
    // сумма, произвед.
    QAction *actSumma;
    QAction *actProduct;
    // вектор, матрица
    QAction *actVector2;
    QAction *actVector3;
    QAction *actMatrix2;
    QAction *actMatrix3;
    // элементы вектора, матрицы
    QAction *actMatrixItem;
    QAction *actMatrixCol;
    QAction *actVectorItem;
    //другие элементы
    QAction *actTimeDer;
    QAction *actTranspose;
    QAction *actCrossProduct;
    QAction *actScalarProduct;

protected slots:
    void insertionCommand();

signals:
    void insertionCommandSelected(ModelScene::ItemTypes);

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
};

#endif // MAINWINDOW_H
