#ifndef OVNI_H
#define OVNI_H
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>
#include <sprite.h>


class ovni: public sprite
{

public:
    ovni();
    ovni(int posx, int posy, int ancho, int alto);
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
};

#endif // OVNI_H
