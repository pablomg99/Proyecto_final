#include "ovni.h"

ovni::ovni()
{

}

QRectF ovni::boundingRect() const
{
    return QRectF(x, y, w, h);
}

void ovni::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap ufoPm(":/recursos/ovni.png");
    painter->drawPixmap(boundingRect(), ufoPm, ufoPm.rect());
}

ovni::ovni(int posx, int posy)
{
    this->x=posx;
    this->y=posy;
    this->w=100;
    this->h=70;
    this->vel=3;
    this->setPos(QPoint(x, y));
}

void ovni::moveUp()
{
    y-=vel;
    setPos(QPoint(x, y));
}

void ovni::moveDown()
{
    y+=vel;
    setPos(QPoint(x, y));
}

void ovni::moveLeft()
{
    x-=vel;
    setPos(QPoint(x, y));
}

void ovni::moveRight()
{
    x+=vel;
    setPos(QPoint(x, y));
}
