#include "vaca.h"

vaca::vaca()
{
    timerVaca = new QTimer();
    this->tamano=30;
    this->posx = this->random(230, 800-tamano);
    this->posy = this->random(234-tamano, 432-tamano);
    velAbd = 4;
    posx = posx/2;
    posy = posy/2;
    setPos(posx, posy);

    connect(timerVaca, &QTimer::timeout, this, &vaca::abduccion);
}

QRectF vaca::boundingRect() const
{
    return QRect(posx, posy, tamano, tamano);
}

void vaca::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    if (sentido == 1){
        QPixmap vacaPm(":/recursos/vaca.png");
        painter->drawPixmap(boundingRect(), vacaPm, vacaPm.rect());
    }
    else{
        QPixmap vacaPm(":/recursos/vaca2.png");
        painter->drawPixmap(boundingRect(), vacaPm, vacaPm.rect());
    }
}

int vaca::random(int inicio, int fin)
{
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> dist(inicio, fin);

    return dist(gen);
}

void vaca::abduccion()
{
    posy -= velAbd;
    setPos(QPoint(posx, posy));
}
