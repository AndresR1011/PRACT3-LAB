
#include "laberinto.h"

laberinto::laberinto()
{

}

QRectF laberinto::boundingRect() const
{
    //return QRectF(80,30,425,525); //posiciona la imagen SOBRE LA ESCENA desde la coordenada (102,40)  [IZQ-SUPER(ORIGENIMAGEN)] //++
    return QRectF(80,30,450,550); //posiciona la imagen SOBRE LA ESCENA desde la coordenada (102,40)  [IZQ-SUPER(ORIGENIMAGEN)] //++
}

void laberinto::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //QPixmap pixmap;
    //pixmap.load(":/imag/LABERINTO DED 726X825_V2.png");
    //pixmap.load(":/imag/NUEVO_LABERINTO 425x525  ok.png");
    QImage qImag;
    qImag.load(":/imag/NUEVO_LABERINTO 425x525  ok.png");

    //painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
    //painter->drawPixmap(boundingRect(),qImag,qImag.rect());
    painter->drawImage(boundingRect(),qImag,qImag.rect());
}

/*
QColor laberinto::pixel(int x, int y)
{
    return QColor(x,y);
}*/



