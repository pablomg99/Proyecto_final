#ifndef OBSTACULO_H
#define OBSTACULO_H
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>
#include <sprite.h>


class obstaculo: public sprite
{

public:
    obstaculo();
    obstaculo(int x, int y, int ancho, int alto);

};

#endif // OBSTACULO_H
