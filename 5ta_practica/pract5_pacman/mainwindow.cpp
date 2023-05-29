
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    sceneJ=new QGraphicsScene(0,0,650,650);
    ui->graphicsView->setScene(sceneJ); //agregar escena creada en el garficsView

    timercaras=new QTimer();
    connect(timercaras,SIGNAL(timeout()),this,SLOT(animar()));
    //timercaras->start(33);
    timercaras->start(150);

    lab = new laberinto();
    sceneJ->addItem(lab);
    lab->setPos(0,0);


    vias = new sinCalles();
    sceneJ->addItem(vias);
    vias->setPos(0,0);

    caraP= new face();
    sceneJ->addItem(caraP);
    //caraP->setPos(93,275);
    //caraP->setPos(91,280);//++
    caraP->setPos(93,291);

    caraP->setPosX(104.5); //atributos de r(t) clase propia
    caraP->setPosy(302.5); //atributos de r(t) clase propia

    moverDerPacman= false, moverIzqPacman = false, moverAbajPacman = false, moverArrPacman=false;

    barra0 =new QGraphicsRectItem(175,57,9,75);
    sceneJ->addItem(barra0);
    barra0->setPos(70,200);

    barra1 =new QGraphicsRectItem(175,57,4,75);
    sceneJ->addItem(barra1);
    barra1->setPos(177,200);

    //++barra2 =new QGraphicsRectItem(175,57,91,4);
    barra2 =new QGraphicsRectItem(175,57,91,80);
    sceneJ->addItem(barra2);
    //barra2->setPos(50,250);
    barra2->setPos(-95,250);

    //++barra3 =new QGraphicsRectItem(175,57,91,4);
    barra3 =new QGraphicsRectItem(175,57,91,75);
    sceneJ->addItem(barra3);
    //barra2->setPos(50,250);
    //++barra3->setPos(-95,217);
    barra3->setPos(-95,147);

    barra4 =new QGraphicsRectItem(175,57,18,130); //ok
    sceneJ->addItem(barra4);
    //barra2->setPos(50,250);
    barra4->setPos(24,91);
}

MainWindow::~MainWindow()
{
    //delete qPix;
    delete barra6;
    delete barra5;
    delete barra4;
    delete barra3;
    delete barra2;
    delete barra1;
    delete barra0;
    delete caraP;
    delete timercaras;
    delete lab;
    delete vias;
    delete sceneJ;
    delete ui;
}

void MainWindow::animar()
{
    int pasos=2;

    if (moverDerPacman)
    //if (moverDerPacman && caraP->collidesWithItem(barra0) && caraP->collidesWithItem(barra1) && caraP->collidesWithItem(barra2) && caraP->collidesWithItem(barra3) && caraP->collidesWithItem(barra4))// && caraP->collidesWithItem(vias)!=true)
    {
        caraP->setPos(caraP->x()+pasos,caraP->y());
    }

    if(moverIzqPacman)// && caraP->collidesWithItem(vias)!=true)// && barra->x()>30)
    //if(moverIzqPacman && caraP->collidesWithItem(barra0) && caraP->collidesWithItem(barra1) && caraP->collidesWithItem(barra2) && caraP->collidesWithItem(barra3) && caraP->collidesWithItem(barra4))// && caraP->collidesWithItem(vias)!=true)// && barra->x()>30)
    {
        caraP->setPos(caraP->x()-pasos,caraP->y());
        caraP->setPosX(x()-pasos);
        caraP->setPosy(y());
    }

    if(moverArrPacman )// && caraP->collidesWithItem(vias)!=true)// && barra->x()>30)
    //if(moverArrPacman || caraP->collidesWithItem(barra0) && caraP->collidesWithItem(barra1) && caraP->collidesWithItem(barra2) && caraP->collidesWithItem(barra3) && caraP->collidesWithItem(barra4))
    {
        caraP->setPos(caraP->x(),caraP->y()-pasos);
        caraP->setPosX(x());
        caraP->setPosy(y()-pasos);
    }

    if(moverAbajPacman)

    {
        caraP->setPos(caraP->x(),caraP->y()+pasos);
    }

    //pasos +=0.001;
    if (caraP->collidesWithItem(barra2) || caraP->collidesWithItem(barra3))// || caraP->collidesWithItem(barra2) || caraP->collidesWithItem(barra3) || caraP->collidesWithItem(barra4))
    {
        moverAbajPacman = false, moverArrPacman=false;
    }

}
void MainWindow::keyPressEvent(QKeyEvent *ev)
{
    if(ev->key()==Qt::Key_D)
    {
        moverDerPacman = true;

        caraP->setLetra('d');
    }
    else if(ev->key()==Qt::Key_A)
    {
        moverIzqPacman=true;
        caraP->setLetra('a');
    }
    else if(ev->key()==Qt::Key_S)
    {
        moverArrPacman=true;
        caraP->setLetra('s');
    }
    else if(ev->key()==Qt::Key_Z)
    {
        moverAbajPacman=true;
        caraP->setLetra('z');
    }

}

void MainWindow::keyReleaseEvent(QKeyEvent *ev)
{

    if(ev->key()==Qt::Key_D)
    {
        moverDerPacman = false;
        caraP->setLetra('d');
        caraP->setFilas(0);
    }
    else if(ev->key()==Qt::Key_A)
    {
        moverIzqPacman=false;
        caraP->setLetra('a');
        caraP->setFilas(25);
    }
    else if(ev->key()==Qt::Key_S)
    {
        moverArrPacman=false;
        caraP->setLetra('s');
        caraP->setFilas(50);
    }
    else if(ev->key()==Qt::Key_Z)
    {
        moverAbajPacman=false;
        caraP->setLetra('z');
        caraP->setFilas(75);
    }

}




