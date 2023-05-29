#include "escena.h"

escena::escena()
{
    setPos(0,0);

}

QRectF escena::boundingRect() const
{
    return QRect(0, 0, 800, 500);
}

void escena::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap(":/recursos/Fondo listo.jpg");
    painter->drawPixmap(boundingRect(), pixmap, pixmap.rect());
}

