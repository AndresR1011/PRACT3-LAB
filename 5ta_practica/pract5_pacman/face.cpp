
#include "face.h"

char face::getLetra() const
{
    return letra;
}

void face::setLetra(char newLetra)
{
    letra = newLetra;
}

void face::setFilas(float newFilas)
{
    filas = newFilas;
}

float face::getPosy() const
{
    return posy;
}

void face::setPosy(float newPosy)
{
    posy = newPosy;
}

float face::getPosX() const
{
    return posX;
}

void face::setPosX(float newPosX)
{
    posX = newPosX;
}

face::face(QObject *parent)
    : QObject{parent}
{

    letra = 'd';
    puntaje =0;
    timer = new QTimer();
    filas =0;
    columnas =0;

    //pixmap = new QPixmap(":/imag/PACMANS de 25X25 px.png");   //se le pasa la direccion de meroria de la imagen
    qImagen = new QImage(":/imag/PACMANS de 25X25 px.png");

    //Dimensiones de las subimagen
    ancho = 25;
    alto = 25;


    //timer->start(150); //milisegundos
    timer->start(150); //milisegundos

    //Vinculat timer con el slot ACTUALIZACION
    connect(timer,&QTimer::timeout,this,&face::efectoComer);
}

float face::getPuntaje() const
{
    return puntaje;
}

void face::setPuntaje(float newPuntaje)
{
    puntaje = newPuntaje;
}

void face::efectoComer()
{
    if (letra== 'd' || letra=='D'){ //derecha
        //filas=0;
        columnas +=25;
        if (columnas>= 100){
            columnas =0;
        }
    }
    else if (letra== 'a' || letra=='A'){ //cara hacia izquierda
        //filas=25;
        columnas +=25;
        if (columnas>= 100){
            columnas =0;
        }
    }
    else if (letra== 's' || letra=='S'){ //cara hacia arriba
        //filas=50;
        columnas +=25;
        if (columnas>= 100){
            columnas =0;
        }
    }
    else if (letra== 'z' || letra=='Z'){ // cara hacia abajo
        //filas=75;
        columnas +=25;
        if (columnas>= 100){
            columnas =0;
        }
    }


    this->update(-ancho/2, -alto/2, ancho-2,alto-2);
}

QRectF face::boundingRect() const
{
    float menos=2;
    //return QRectF(-ancho/2, -alto/2, ancho-2,alto-2);
    return QRectF(-(ancho-menos)/2, -(alto-menos)/2, ancho-menos,alto-menos);
}

void face::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    float menos=2;
    //painter->drawPixmap(-ancho/2,-alto/2, *pixmap,columnas,0,ancho,alto);
    //if (filas==0){
    if (letra== 'd' || letra=='D'){
        //painter->drawPixmap(-ancho/2,-alto/2, *pixmap,columnas,0,ancho,alto);
        //painter->drawPixmap(-ancho/2,-alto/2, *pixmap,columnas,filas,ancho,alto);
        //painter->drawImage(-ancho/2,-alto/2, *qImagen,columnas,filas,ancho,alto);
        painter->drawImage(-(ancho-menos)/2,-(alto-menos)/2, *qImagen,columnas,filas,ancho-menos,alto-menos);
    }
    else if (letra== 'a' || letra=='A'){
        //painter->drawPixmap(-ancho/2,-alto/2, *pixmap,columnas,25,ancho,alto);
        //painter->drawPixmap(-ancho/2,-alto/2, *pixmap,columnas,filas,ancho,alto);
        //painter->drawImage(-ancho/2,-alto/2, *qImagen,columnas,filas,ancho,alto);
        painter->drawImage(-(ancho-menos)/2,-(alto-menos)/2, *qImagen,columnas,filas,ancho-menos,alto-menos);
    }
    //else if (filas ==2){
    else if (letra== 's' || letra=='S'){
        //painter->drawPixmap(-ancho/2,-alto/2, *pixmap,columnas,50,ancho,alto);
        //painter->drawPixmap(-ancho/2,-alto/2, *pixmap,columnas,filas,ancho,alto);
        //painter->drawImage(-ancho/2,-alto/2, *qImagen,columnas,filas,ancho-1,alto-1);
        painter->drawImage(-(ancho-menos)/2,-(alto-menos)/2, *qImagen,columnas,filas,ancho-menos,alto-menos);
    }
    //else if (filas ==3){
    else if (letra== 'z' || letra=='Z'){
        //painter->drawPixmap(-ancho/2,-alto/2, *pixmap,columnas,75,ancho,alto);
        //painter->drawPixmap(-ancho/2,-alto/2, *pixmap,columnas,filas,ancho,alto);
        //painter->drawImage(-ancho/2,-alto/2, *qImagen,columnas,filas,ancho-1,alto-1);
        painter->drawImage(-(ancho-menos)/2,-(alto-menos)/2, *qImagen,columnas,filas,ancho-menos,alto-menos);
    }




}

