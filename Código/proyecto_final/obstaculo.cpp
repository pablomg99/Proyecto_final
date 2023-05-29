#include "obstaculo.h"

obstaculo::obstaculo()
{

}

obstaculo::obstaculo(int x, int y, int ancho, int alto)
{
    this->posx=x;
    this->posy=y;
    this->w=ancho;
    this->h=alto;
}

QRectF obstaculo::boundingRect() const
{
    return QRectF(posx, posy, w, h);
}

void obstaculo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::gray);
    painter->drawRect(boundingRect());
}
