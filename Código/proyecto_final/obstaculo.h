#ifndef OBSTACULO_H
#define OBSTACULO_H
#include <QGraphicsItem>
#include <QPainter>


class obstaculo: public QGraphicsItem
{
    int posx, posy, w, h;
public:
    obstaculo();
    obstaculo(int x, int y, int ancho, int alto);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};

#endif // OBSTACULO_H
