#include "mainwindow.h""

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    this->setFixedSize(800, 600);
    scene = new QGraphicsScene(0, 0, 800, 600, this);
    ui.graphicsView->setScene(scene);

    sol = new Soldier;
    movingArm1 = new Rect(78, 210, 22, 100);

    scene->addItem(movingArm1);
    scene->addItem(sol->ShowBody());
    scene->addItem(sol->ShowLeg1());
    scene->addItem(sol->ShowLeg2());
    scene->addItem(sol->ShowArm());
    scene->addItem(sol->DrawHead(100, 160, 50, 50));
    //scene->addItem(new Head(100, 160, 50, 50));

    moveTimer = new QTimer(this);
    connect(moveTimer, SIGNAL(timeout()), scene, SLOT(advance()));
}
bool MainWindow::flag = 0;
//bool MainWindow::flag1 = 0;

MainWindow::~MainWindow()
{
    delete movingArm1;
    delete movingArm2;
    delete sol;
    delete scene;
    delete moveTimer;
}

void MainWindow::on_pushSoldier_clicked()
{
    
    moveTimer->start(1000 / 150);
}

void MainWindow::on_pushStop_clicked()
{
    moveTimer->stop();
}

void MainWindow::on_pushGo_clicked()
{
    moveTimer->start(1000 / 60);
}

void MainWindow::on_pushButton_clicked()
{
    if (!flag)
    {
        movingArm1->setTransformOriginPoint(QPoint(22, 25));
        movingArm1->setRotation(120);
        movingArm2 = new Rect(movingArm1->x() - 60, 185, 22, 80);

        movingArm2->setTransformOriginPoint(QPoint(22, 0));
        movingArm2->setRotation(250);
        scene->addItem(movingArm2);
        flag = 1;
    }   
}

