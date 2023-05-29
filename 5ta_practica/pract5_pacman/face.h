
#ifndef FACE_H
#define FACE_H


#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>

#include <QImage>


class face : public QObject,  public QGraphicsItem
{
    Q_OBJECT
private:
    char letra;
    QTimer *timer;
    //QPixmap *pixmap; //para meter imagen

    QImage *qImagen;

    float ancho, alto;  //variables para tamaños de las SUBIMAGENES-DIMENSIONES
    float filas,columnas; //para iterar por las secciones de la imagen
    float velocidad;
    float puntaje;

    float posX;
    float posy;

public:
    explicit face(QObject *parent = nullptr);

    //char letra;
    //QTimer *timer;
    //QPixmap *pixmap; //para meter imagen

    //float filas,columnas; //para iterar por las secciones de la imagen
    //float ancho, alto;  //variables para tamaños de las SUBIMAGENES-DIMENSIONES

    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget);

    float getPuntaje() const;
    void setPuntaje(float newPuntaje);

    char getLetra() const;
    void setLetra(char newLetra);

    void setFilas(float newFilas);

    //QPixelForma

    float getPosy() const;
    void setPosy(float newPosy);

    float getPosX() const;
    void setPosX(float newPosX);

signals:

public slots:
    void efectoComer();

};

#endif // FACE_H
