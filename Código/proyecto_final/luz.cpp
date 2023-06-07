#include "luz.h"

luz::luz()
{

}

luz::luz(int x, int y, int w, int h)
{
    this->posx=x;
    this->posy=y;
    this->ancho=w;
    this->alto=h;
    this->velocidad=3;
    this->a=2;
    luzTimer=new QTimer();
    setPos(QPoint(posx, posy));

    connect(luzTimer, &QTimer::timeout, this, &luz::aceleracion);
}

QRectF luz::boundingRect() const
{
    return QRectF(posx, posy, ancho, alto);
}

void luz::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap(":/recursos/Luz_abd-removebg-preview.png");
    painter->setOpacity(0.5);
    painter->drawPixmap(boundingRect(), pixmap, pixmap.rect());
}

void luz::aceleracion()
{
    velocidad += a;
}

void luz::moveUp()
{
    posy=posy-velocidad;
    setPos(posx,posy);
}

void luz::moveDown()
{
    posy=posy+velocidad;
    setPos(posx,posy);
}

void luz::moveLeft()
{
    posx=posx-velocidad;
    setPos(posx,posy);
}

void luz::moveRight()
{
    posx=posx+velocidad;
    setPos(posx,posy);
}

void luz::restartSpeed()
{
    velocidad=3;
}
