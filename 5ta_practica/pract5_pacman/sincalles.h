
#ifndef SINCALLES_H
#define SINCALLES_H

#include <QGraphicsItem>
#include <QPainter>
#include <QImage>
#include <iostream>
#include <string>

using namespace std;



class sinCalles: public QGraphicsItem
{
public:
    sinCalles();

    QRectF boundingRect() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option, QWidget *widget);

    //string colorPixel(int x, int y);
};

#endif // SINCALLES_H
