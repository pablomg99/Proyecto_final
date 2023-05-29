#include "vaca.h"

vaca::vaca()
{
    this->posx= this->random(203, 768);
    this->posy= this->random(223,400);

}

QRectF vaca::boundingRect() const
{
    return QRect(posx, posy, 30, 30);
}

void vaca::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    int numero = random(0,1);
    if (numero ==1){
        QPixmap vacaPm(":/recursos/vaca.png");
        painter->drawPixmap(boundingRect(), vacaPm, vacaPm.rect());
    }
    else{
        QPixmap vacaPm(":/recursos/vaca2.png");
        painter->drawPixmap(boundingRect(), vacaPm, vacaPm.rect());
    }
}

bool vaca::esAbducida()
{

}

bool vaca::finAbduccion()
{

}

bool vaca::cae()
{

}

void vaca::abducida(bool esAbducida)
{

}

void vaca::caer(bool cae)
{

}

int vaca::random(int inicio, int fin)
{
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> dist(inicio, fin);

    return dist(gen);
}
