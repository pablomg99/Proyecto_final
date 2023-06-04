#include "ovni.h"

ovni::ovni()
{

}

ovni::ovni(int posx, int posy)
{
    x=posx;
    y=posy;
    w=100;
    h=70;
    velMax=25;
    vel=3;
    puntuacion=0;
    moveUfoTimer=new QTimer;
    setPos(QPoint(x, y));

    connect(moveUfoTimer, &QTimer::timeout, this, &ovni::aceleracion);
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
    /*if(vel<velMax){
        vel+=1;
    }*/
}

void ovni::aceleracion()
{
    vel+=3;
}
