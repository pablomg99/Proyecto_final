#ifndef VACA_H
#define VACA_H
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>
#include <sprite.h>


class vaca: public sprite
{
    int alturaAbduccion;

public:
    vaca();
    vaca(int posx, int posy, int ancho, int alto);
    bool esAbducida();
    bool finAbduccion();
    bool cae();
    void abducida(bool esAbducida);
    void caer(bool cae);
};

#endif // VACA_H
