#include "mainwindow.h"
#include <QDebug>
#include <QMenuBar>

void MainWindow::insertionCommand()
{
    QAction *senderAction = static_cast<QAction *>(sender());
    ModelScene::ItemTypes itemType;
    if (actAddAE == senderAction)
        itemType = ModelScene::ITAE;
    else if (actAddDE == senderAction)
        itemType = ModelScene::ITDE;
    else if (actBinDiv == senderAction)
        itemType = ModelScene::ITBinDiv;
    else if (actBinMinus == senderAction)
        itemType = ModelScene::ITBinMinus;
    else if (actBinPlus == senderAction)
        itemType = ModelScene::ITBinPlus;
    else if (actBinMult == senderAction)
        itemType = ModelScene::ITBinMult;
    else if (actPower == senderAction)
        itemType = ModelScene::ITBinPwr;
    else if (actMatrix2 == senderAction)
        itemType = ModelScene::ITMatrix2;
    else if (actMatrix3 == senderAction)
        itemType = ModelScene::ITMatrix3;
    else if (actProduct == senderAction)
        itemType = ModelScene::ITProduct;
    else if (actRoundPars == senderAction)
        itemType = ModelScene::ITRoundPars;
    else if (actSquareRoot == senderAction)
        itemType = ModelScene::ITSquareRoot;
    else if (actSumma == senderAction)
        itemType = ModelScene::ITSumma;
    else if (actUnaryFunction == senderAction)
        itemType = ModelScene::ITUnaryFunction;
    else if (actUnaryMinus == senderAction)
        itemType = ModelScene::ITUnaryMinus;
    else if (actVector2 == senderAction)
        itemType = ModelScene::ITVector2;
    else if (actVector3 == senderAction)
        itemType = ModelScene::ITVector3;
    else {
        itemType = ModelScene::ITUnknown;
        return;
    }

    emit insertionCommandSelected(itemType);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    view  = new QGraphicsView(this);
    model = new ModelScene(this);

    this->setCentralWidget(view);
    view->setScene(model);

    //model->addRect(1.0, 1.0, 100.0, 120.0);
    model->setSceneRect(0.0, 0.0,
                        1024.0, 768.0);

    actAddDE    = new QAction(tr("Дифференциальное"), this);
    actAddAE    = new QAction(tr("Алгебраическое"), this);
    actBinPlus  = new QAction(tr("+"), this);
    actBinMinus = new QAction(tr("-"), this); actBinMinus->setEnabled(true);
    actBinMult  = new QAction(tr("*"), this); actBinMult->setEnabled(true);
    actBinDiv   = new QAction(tr("/"), this); actBinDiv->setEnabled(true);
    actPower    = new QAction(tr("Степень"), this); actPower->setEnabled(true);
    actFraction = new QAction(tr("Обыкновенная дробь"), this); actFraction->setEnabled(true);

    actUnaryMinus    = new QAction(tr("-"), this);    actUnaryMinus->setEnabled(true);
    actSquareRoot    = new QAction(tr("Корень квадратный"), this);    actSquareRoot->setEnabled(true);
    actUnaryFunction = new QAction(tr("f(x)"), this); actUnaryFunction->setEnabled(true);
    actRoundPars     = new QAction(tr("(  )"), this); actRoundPars->setEnabled(true);
    actAbsValue      = new QAction(tr("Модуль"), this); actAbsValue->setEnabled(true);

    actSumma    = new QAction(tr("Суммирование"), this); actSumma->setEnabled(true);
    actProduct  = new QAction(tr("Произведение"), this); actProduct->setEnabled(true);

    actVector2  = new QAction(tr("Вектор 2x1"), this); actVector2->setEnabled(true);
    actVector3  = new QAction(tr("Вектор 3x1"), this); actVector3->setEnabled(true);
    actMatrix2  = new QAction(tr("Матрица 2x1"), this); actMatrix2->setEnabled(true);
    actMatrix3  = new QAction(tr("Матрица 3x1"), this); actMatrix3->setEnabled(true);

    actMatrixItem = new QAction(tr("Элемент матрицы"), this); actMatrixItem->setEnabled(true);
    actMatrixCol  = new QAction(tr("Столбец матрицы"), this); actMatrixCol->setEnabled(true);
    actVectorItem = new QAction(tr("Элемент вектора"), this); actVectorItem->setEnabled(true);

    actTimeDer       = new QAction(tr("Производная по времени"), this); actTimeDer->setEnabled(true);
    actTranspose     = new QAction(tr("Транспонирование"), this); actTranspose->setEnabled(true);
    actCrossProduct  = new QAction(tr("Векторное произведение"), this); actCrossProduct->setEnabled(true);
    actScalarProduct = new QAction(tr("Скалярное произведение"), this); actScalarProduct->setEnabled(true);

    // Добавить ниже строку для активации команды вставки вашего элемента
    // ***********************************************************************
    connect(actBinPlus, SIGNAL(triggered()), this, SLOT(insertionCommand()));
    connect(actBinMinus, SIGNAL(triggered()), this, SLOT(insertionCommand()));
    connect(actBinMult, SIGNAL(triggered()), this, SLOT(insertionCommand()));
    connect(actBinDiv, SIGNAL(triggered()), this, SLOT(insertionCommand()));
//    connect(actSumma, SIGNAL(triggered()), this, SLOT(insertionCommand()));
//    connect(actProduct, SIGNAL(triggered()), this, SLOT(insertionCommand()));
    connect(actPower, SIGNAL(triggered()), this, SLOT(insertionCommand()));
    connect(actVector2, SIGNAL(triggered()), this, SLOT(insertionCommand()));
    connect(actVector3, SIGNAL(triggered()), this, SLOT(insertionCommand()));
    connect(this, SIGNAL(insertionCommandSelected(ModelScene::ItemTypes)), model, SLOT(insertItemWrapper(ModelScene::ItemTypes)));
    // ***********************************************************************

    // панель меню
    QMenuBar *mnuBar = menuBar();
    // формирование главного меню
    QMenu *mnu;
    mnu = new QMenu(tr("Уравнения"), this);
    mnu->addAction(actAddDE);
    mnu->addAction(actAddAE);
    mnuBar->addMenu(mnu);

    mnu = new QMenu(tr("Бинарные операции"), this);
    mnu->addAction(actBinPlus);
    mnu->addAction(actBinMinus);
    mnu->addAction(actBinMult);
    mnu->addAction(actBinDiv);
    mnu->addAction(actPower);
    mnu->addAction(actFraction);
    mnuBar->addMenu(mnu);

    mnu = new QMenu(tr("Унарные операции"), this);
    mnu->addAction(actUnaryMinus);
    mnu->addAction(actSquareRoot);
    mnu->addAction(actUnaryFunction);
    mnu->addAction(actRoundPars);
    mnu->addAction(actAbsValue);
    mnuBar->addMenu(mnu);

    mnu = new QMenu(tr("Сумма и Произв"), this);
    mnu->addAction(actSumma);
    mnu->addAction(actProduct);
    mnuBar->addMenu(mnu);

    mnu = new QMenu(tr("Векторы и матрицы"), this);

    mnu->addAction(actVector3);
    mnu->addAction(actMatrix2);
    mnu->addAction(actMatrix3);
    mnu->addSeparator();
    mnu->addAction(actMatrixItem);
    mnu->addAction(actMatrixCol);
    mnu->addAction(actVectorItem);
    mnuBar->addMenu(mnu);

    mnu = new QMenu(tr("Другие элементы"), this);
    mnu->addAction(actTimeDer);
    mnu->addAction(actTranspose);
    mnu->addAction(actCrossProduct);
    mnu->addAction(actScalarProduct);
    mnuBar->addMenu(mnu);
}

MainWindow::~MainWindow()
{

}

