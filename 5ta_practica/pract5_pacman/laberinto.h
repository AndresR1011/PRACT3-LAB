
#ifndef LABERINTO_H
#define LABERINTO_H

#include <QGraphicsItem>
#include <QPainter>
#include <QImage>
#include <QColor>


class laberinto: public QGraphicsItem
{
public:
    laberinto();   
    QRectF boundingRect() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option, QWidget *widget);

    //QColor pixel(int x, int y);


};

#endif // LABERINTO_H
