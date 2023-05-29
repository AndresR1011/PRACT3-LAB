
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QGraphicsItem>
#include <QRectF>
#include <QGraphicsScene>

#include <QImage>

#include <QKeyEvent>
#include <QTimer>

#include "face.h"
#include "laberinto.h"
#include "sincalles.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void aviso(int);

public slots:
    void animar();


private:
    Ui::MainWindow *ui;

    QGraphicsScene* sceneJ; //espacio para cargar objetos
    face *caraP;
    laberinto *lab;
    sinCalles *vias;

    bool moverDerPacman, moverIzqPacman, moverArrPacman, moverAbajPacman;
    QTimer *timercaras;

    QGraphicsRectItem* barra0, *barra1, *barra2,*barra3, *barra4, *barra5,*barra6;

    //QImage *qPix;


    //QPixmap *pixel;

    void keyPressEvent(QKeyEvent *ev);
    void keyReleaseEvent(QKeyEvent *ev);



};

#endif // MAINWINDOW_H
