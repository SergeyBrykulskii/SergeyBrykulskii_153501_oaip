#include "mainwindow.h"

enum Timers{MoveLeft, MoveRight, MoveUp, MoveDown, ZoomIn, ZoomOut, RotateLeft, RotateRight};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    scene = new QGraphicsScene(0, 0, 670, 410);
    ui.graphicsView->setScene(scene);
    this->setFixedSize(861, 633);

    form = new Triangle;
    
    TrianParameters = new QDialog(this);
    RectParameters = new QDialog(this);
    SquareParameters = new QDialog(this);
    HexagonParameters = new QDialog(this);
    CircleParameters = new QDialog(this);
    RhombusParameters = new QDialog(this);
    StarParameters = new QDialog(this);

    Enter = nullptr;

    X1 = nullptr;  X2 = nullptr; X3 = nullptr;
    Y1 = nullptr;  Y2 = nullptr; Y3 = nullptr;

    getX1 = nullptr; getX2 = nullptr; getX3 = nullptr;
    getY1 = nullptr; getY1 = nullptr; getY1 = nullptr;

    len = nullptr; wid = nullptr;
    getLen = nullptr; getWid = nullptr;

    timer = new QTimer*[8];
    for(int i = 0; i < 8; i++)
        timer[i] = new QTimer(this);

    canva = new Canva();

    connect(timer[MoveLeft], SIGNAL(timeout()), this, SLOT(moveLeft()));
    connect(timer[MoveRight], SIGNAL(timeout()), this, SLOT(moveRight()));
    connect(timer[MoveDown], SIGNAL(timeout()), this, SLOT(moveDown()));
    connect(timer[MoveUp], SIGNAL(timeout()), this, SLOT(moveUp()));


    connect(timer[RotateLeft], SIGNAL(timeout()), this, SLOT(RotateL()));
    connect(timer[RotateRight], SIGNAL(timeout()), this, SLOT(RotateR()));


    connect(timer[Timers::ZoomIn], SIGNAL(timeout()), this, SLOT(ZoomIn()));
    connect(timer[Timers::ZoomOut], SIGNAL(timeout()), this, SLOT(ZoomOut()));

}

int MainWindow::angl = 0;
QRegularExpression expr("^\\d{1,3}$");

MainWindow::~MainWindow()
{
    if (getX1 != nullptr)
    {
        delete getX1; delete getX2; delete getX3;
        delete getY1; delete getY2; delete getY3;
        delete X1; delete X2; delete X3;
        delete Y1; delete Y2; delete Y3;
    }
    
    if (len != nullptr)
    {
        delete len; delete wid;
        delete getLen; delete getWid;
    }
    delete canva;
    delete TrianParameters;
    for (int i = 0; i < 8; i++)
        delete timer[i];
    delete[] timer;
    delete form;
    delete scene;
}


void MainWindow::on_Triangle_clicked()
{
    TrianParameters->setModal(true);

    TrianParameters->resize(400, 400);

    delete Enter;
    Enter = new QPushButton("Draw", TrianParameters);
    
    Enter->move(160, 300);


    X1 = new QLabel("X1:", TrianParameters);  X2 = new QLabel("X2:", TrianParameters); X3 = new QLabel("X3:", TrianParameters); 
    Y1 = new QLabel("Y1:", TrianParameters); Y2 = new QLabel("Y2:", TrianParameters); Y3 = new QLabel("Y3:", TrianParameters); 
    
    X1->move(40, 50); X2->move(40, 90); X3->move(40, 130);
    Y1->move(210, 50); Y2->move(210, 90); Y3->move(210, 130);


    getX1 = new QLineEdit(TrianParameters); getX2 = new QLineEdit(TrianParameters); getX3 = new QLineEdit(TrianParameters);
    getY1 = new QLineEdit(TrianParameters); getY2 = new QLineEdit(TrianParameters); getY3 = new QLineEdit(TrianParameters);
    
    getX1->move(60, 50); getX2->move(60, 90); getX3->move(60, 130);
    getY1->move(230, 50); getY2->move(230, 90); getY3->move(230, 130);
    //getX1->setInputMask("999");
    //getX2->setInputMask("999");
    //getX3->setInputMask("999");
    //getY1->setInputMask("999");
    //getY2->setInputMask("999");
    //getY3->setInputMask("999");

    connect(Enter, SIGNAL(clicked()), this, SLOT(drawTriangle()));
    connect(Enter, SIGNAL(clicked()), TrianParameters, SLOT(close()));
  
    TrianParameters->show();
}

void MainWindow::drawTriangle()
{
    QRegularExpressionMatch matchX1 = expr.match(getX1->text()), matchY1 = expr.match(getY1->text()),
        matchX2 = expr.match(getX2->text()), matchY2 = expr.match(getY2->text()),
        matchX3 = expr.match(getX3->text()), matchY3 = expr.match(getY3->text());
    
    if (matchX1.hasMatch() && matchY1.hasMatch() &&
        matchX2.hasMatch() && matchY2.hasMatch() &&
        matchX3.hasMatch() && matchY3.hasMatch())
    {
        TrianParameters->close();
        int x1 = getX1->text().toInt(), x2 = getX2->text().toInt(), x3 = getX3->text().toInt(),
            y1 = getY1->text().toInt(), y2 = getY2->text().toInt(), y3 = getY3->text().toInt();

        delete form;
        form = new Triangle(x1, y1, x2, y2, x3, y3);
        
        form->setPos(200, 200);
        scene->addItem(form);

        ui.Perimeter->setText(QString::number(form->returnPerimeter()));
        ui.Square_2->setText(QString::number(form->returnSquare()));
    }
    else 
    {
        QMessageBox::critical(TrianParameters, "Incorrect input", "Try again");
    }
    
}
//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------
void MainWindow::on_Rectengle_clicked()
{
    RectParameters->setModal(true);

    RectParameters->resize(400, 400);

    delete Enter;
    Enter = new QPushButton("Draw", RectParameters);

    Enter->move(160, 300);

    if (len != nullptr)
        delete len;

    len = new QLabel("Length:", RectParameters); wid = new QLabel("Width:", RectParameters);
    len->move(20, 50); wid->move(210, 50);

    if (getLen != nullptr)
        delete getLen;

    getLen = new QLineEdit(RectParameters); getWid = new QLineEdit(RectParameters);
    getLen->move(60, 50); getWid->move(260, 50);
    //getLen->setInputMask("999");
    //getWid->setInputMask("999");
    connect(Enter, SIGNAL(clicked()), this, SLOT(drawRectengle()));
    connect(Enter, SIGNAL(clicked()), RectParameters, SLOT(close()));

    RectParameters->show();
}

void MainWindow::drawRectengle()
{
    QRegularExpressionMatch matchLen = expr.match(getLen->text()), matchWid = expr.match(getWid->text());


    if (matchLen.hasMatch() && matchWid.hasMatch())
    {
        RectParameters->close();
        int len = getLen->text().toInt(), wid = getWid->text().toInt();

        delete form;
        form = new Rectengle(len, wid);

        form->setPos(200, 200);
        scene->addItem(form);

        ui.Perimeter->setText(QString::number(form->returnPerimeter()));
        ui.Square_2->setText(QString::number(form->returnSquare()));
    }
    else
    {
        QMessageBox::critical(RectParameters, "Incorrect input", "Try again");
    }
}
//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------
void MainWindow::on_Square_clicked()
{
    SquareParameters->setModal(true);

    SquareParameters->resize(400, 400);

    delete Enter;
    Enter = new QPushButton("Draw", SquareParameters);

    Enter->move(160, 300);

    if (len != nullptr)
        delete len;

    len = new QLabel("Length:", SquareParameters);
    len->move(20, 50); 

    if (getLen != nullptr)
        delete getLen;

    getLen = new QLineEdit(SquareParameters); 
    getLen->move(60, 50); 
    //getLen->setInputMask("999");
    connect(Enter, SIGNAL(clicked()), this, SLOT(drawSquare()));
    connect(Enter, SIGNAL(clicked()), SquareParameters, SLOT(close()));

    SquareParameters->show();

}

void MainWindow::drawSquare()
{
    QRegularExpressionMatch matchLen = expr.match(getLen->text());


    if (matchLen.hasMatch())
    {
        SquareParameters->close();
        int len = getLen->text().toInt();

        delete form;
        form = new Square(len);

        form->setPos(200, 200);
        scene->addItem(form);

        ui.Perimeter->setText(QString::number(form->returnPerimeter()));
        ui.Square_2->setText(QString::number(form->returnSquare()));
    }
    else
    {
        QMessageBox::critical(SquareParameters, "Incorrect input", "Try again");
    }
}
//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------
void MainWindow::on_Hexagon_clicked()
{
    HexagonParameters->setModal(true);

    HexagonParameters->resize(400, 400);

    delete Enter;
    Enter = new QPushButton("Draw", HexagonParameters);

    Enter->move(160, 300);

    if (len != nullptr)
        delete len;

    len = new QLabel("Length:", HexagonParameters);
    len->move(20, 50);

    if (getLen != nullptr)
        delete getLen;

    getLen = new QLineEdit(HexagonParameters);
    getLen->move(60, 50);
    //getLen->setInputMask("999");
    //getLen->setCursorPosition(0);
    connect(Enter, SIGNAL(clicked()), this, SLOT(drawHexagon()));
    connect(Enter, SIGNAL(clicked()), HexagonParameters, SLOT(close()));

    HexagonParameters->show();

}

void MainWindow::drawHexagon()
{
    QRegularExpressionMatch matchLen = expr.match(getLen->text());


    if (matchLen.hasMatch())
    {
        HexagonParameters->close();
        int len = getLen->text().toInt();

        delete form;
        form = new Hexagon(len);

        form->setPos(230, 150);
        scene->addItem(form);

        ui.Perimeter->setText(QString::number(form->returnPerimeter()));
        ui.Square_2->setText(QString::number(form->returnSquare()));
    }
    else
    {
        QMessageBox::critical(HexagonParameters, "Incorrect input", "Try again");
    }
}
//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------
void MainWindow::on_Circle_clicked()
{
    CircleParameters->setModal(true);

    CircleParameters->resize(400, 400);

    delete Enter;
    Enter = new QPushButton("Draw", CircleParameters);

    Enter->move(160, 300);

    if (len != nullptr)
        delete len;

    len = new QLabel("Radius:", CircleParameters);
    len->move(20, 50);

    if (getLen != nullptr)
        delete getLen;

    getLen = new QLineEdit(CircleParameters);
    getLen->move(60, 50);
    //getLen->setInputMask("999");

    connect(Enter, SIGNAL(clicked()), this, SLOT(drawCircle()));
    connect(Enter, SIGNAL(clicked()), CircleParameters, SLOT(close()));

    CircleParameters->show();
}

void MainWindow::drawCircle()
{
    QRegularExpressionMatch matchLen = expr.match(getLen->text());


    if (matchLen.hasMatch())
    {
        CircleParameters->close();
        int len = getLen->text().toInt();

        delete form;
        form = new Circle(len);

        form->setPos(100, 100);
        scene->addItem(form);

        ui.Perimeter->setText(QString::number(form->returnPerimeter()));
        ui.Square_2->setText(QString::number(form->returnSquare()));
    }
    else
    {
        QMessageBox::critical(CircleParameters, "Incorrect input", "Try again");
    }
}

//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------
void MainWindow::on_Rhombus_clicked()
{
    RhombusParameters->setModal(true);

    RhombusParameters->resize(400, 400);

    delete Enter;
    Enter = new QPushButton("Draw", RhombusParameters);

    Enter->move(160, 300);

    if (len != nullptr)
        delete len;

    len = new QLabel("Length:", RhombusParameters);
    len->move(20, 50);

    if (getLen != nullptr)
        delete getLen;

    getLen = new QLineEdit(RhombusParameters);
    getLen->move(60, 50);
    //getLen->setInputMask("999");

    connect(Enter, SIGNAL(clicked()), this, SLOT(drawRhombus()));
    connect(Enter, SIGNAL(clicked()), RhombusParameters, SLOT(close()));

    RhombusParameters->show();

}

void MainWindow::drawRhombus()
{
    QRegularExpressionMatch matchLen = expr.match(getLen->text());


    if (matchLen.hasMatch())
    {
        RhombusParameters->close();
        int len = getLen->text().toInt();

        delete form;
        form = new Rhombus(len);

        form->setPos(100, 100);
        scene->addItem(form);

        ui.Perimeter->setText(QString::number(form->returnPerimeter()));
        ui.Square_2->setText(QString::number(form->returnSquare()));
    }
    else
    {
        QMessageBox::critical(RhombusParameters, "Incorrect input", "Try again");
    }
}

//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------
void MainWindow::on_Star_clicked()
{
    StarParameters->setModal(true);

    StarParameters->resize(400, 400);

    delete Enter;
    Enter = new QPushButton("Draw", StarParameters);

    Enter->move(160, 300);

    if (len != nullptr)
        delete len;

    len = new QLabel("Number of tops:", StarParameters);
    len->move(20, 50);

    if (getLen != nullptr)
        delete getLen;

    getLen = new QLineEdit(StarParameters);
    getLen->move(120, 50);
    //getLen->setInputMask("999");

    connect(Enter, SIGNAL(clicked()), this, SLOT(drawStar()));
    connect(Enter, SIGNAL(clicked()), StarParameters, SLOT(close()));

    StarParameters->show();

}

void MainWindow::drawStar()
{
    QRegularExpressionMatch matchLen = expr.match(getLen->text());


    if (matchLen.hasMatch())
    {
        StarParameters->close();
        int len = getLen->text().toInt();

        delete form;
        form = new Star(len);

        form->setPos(100, 100);
        scene->addItem(form);

        ui.Perimeter->setText(QString::number(form->returnPerimeter()));
        ui.Square_2->setText(QString::number(form->returnSquare()));
    }
    else
    {
        QMessageBox::critical(StarParameters, "Incorrect input", "Try again");
    }
}
//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------
void MainWindow::on_pushLeft_pressed()
{
    timer[MoveLeft]->start(10);
}

void MainWindow::moveLeft() 
{
    if (form)
        form->moveBy(-1, 0);
}

void MainWindow::on_pushLeft_released()
{
    timer[MoveLeft]->stop();
}
//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------
void MainWindow::on_pushRight_pressed()
{
    timer[MoveRight]->start(10);
}

void MainWindow::moveRight()
{
    if (form)
        form->moveBy(1, 0);
}

void MainWindow::on_pushRight_released()
{
    timer[MoveRight]->stop();
}
//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------
void MainWindow::on_pushDown_pressed()
{
    timer[MoveDown]->start(10);
}

void MainWindow::moveDown()
{
    if (form)
        form->moveBy(0, 1);
}

void MainWindow::on_pushDown_released()
{
    timer[MoveDown]->stop();
}
//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------
void MainWindow::on_pushUp_pressed()
{
    timer[MoveUp]->start(10);
}

void MainWindow::moveUp()
{
    if (form)
        form->moveBy(0, -1);
}

void MainWindow::on_pushUp_released()
{
    timer[MoveUp]->stop();
}
//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------
void MainWindow::on_pushRotationL_pressed()
{
    timer[RotateLeft]->start(15);
}

void MainWindow::RotateL()
{
    form->setRotation(angl);
    angl--;
}

void MainWindow::on_pushRotationL_released()
{
    timer[RotateLeft]->stop();
}
//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------
void MainWindow::on_pushRotationR_pressed()
{
    timer[RotateRight]->start(15);
}

void MainWindow::RotateR()
{
    form->setRotation(angl);
    angl++;
}

void MainWindow::on_pushRotationR_released()
{
    timer[RotateRight]->stop();
}
//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------
void MainWindow::on_ZoomOut_pressed()
{
    timer[Timers::ZoomOut]->start(40 );
}

void MainWindow::ZoomOut()
{
    ui.graphicsView->scale(0.95, 0.95);

    ui.Perimeter->setText(QString::number(ui.Perimeter->text().toDouble() * 0.95));
    ui.Square_2->setText(QString::number(ui.Square_2->text().toDouble() * 0.95));

}

void MainWindow::on_ZoomOut_released()
{
    timer[Timers::ZoomOut]->stop();
}
//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------
void MainWindow::on_ZoomIn_pressed()
{
    timer[Timers::ZoomIn]->start(40);
}

void MainWindow::ZoomIn()
{
    ui.graphicsView->scale(1.05, 1.05);
    ui.Perimeter->setText(QString::number(ui.Perimeter->text().toDouble() * 1.05));
    ui.Square_2->setText(QString::number(ui.Square_2->text().toDouble() * 1.05));
}

void MainWindow::on_ZoomIn_released()
{
    timer[Timers::ZoomIn]->stop();
}

void MainWindow::on_Canva_clicked()
{
    canva->show();
}