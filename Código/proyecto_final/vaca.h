#ifndef VACA_H
#define VACA_H
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>
#include <random>


class vaca: public QGraphicsItem
{
    int alturaAbduccion;

public:
    int posx, posy, tamano;
    vaca();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    bool esAbducida();
    bool finAbduccion();
    bool cae();
    void abducida(bool esAbducida);
    void caer(bool cae);
    int random(int inicio, int fin);
};

#endif // VACA_H
