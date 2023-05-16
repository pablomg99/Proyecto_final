#ifndef ESCENA_H
#define ESCENA_H
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>
#include <sprite.h>


class escena: public sprite
{
public:
    escena();
    escena(int sup, int inf, int iz, int der);
    void setLimits();
};

#endif // ESCENA_H
