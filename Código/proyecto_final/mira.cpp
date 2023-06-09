#include "mira.h"

mira::mira()
{
    posx=200;
    posy=200;
    posx=posx/2;
    posy=posy/2;
    tamano=70;
    velocidad = 3;

    setPos(posx, posy);
}

QRectF mira::boundingRect() const
{
    return QRectF(posx, posy, tamano, tamano);
}

void mira::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap miraPm(":/recursos/mira.png");
    painter->drawPixmap(boundingRect(), miraPm, miraPm.rect());

}

void mira::barrido()
{
    if(posy <= (432-tamano)/2){
        if(posx <= (800-tamano)/2){
            posx += velocidad;
        }

        else{
            posx=225/2;
            posy += (5*velocidad);
        }
    }
    else{
        posx=200/2;
        posy=200/2;
    }

    setPos(posx,posy);
}
