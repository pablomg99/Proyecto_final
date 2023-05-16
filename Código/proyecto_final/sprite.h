#ifndef SPRITE_H
#define SPRITE_H
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>


class sprite: public QGraphicsItem
{
    int posx, posy, ancho, alto;
    QString path;

public:
    sprite();
    sprite(int posx, int posy, int ancho, int alto);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
};

#endif // SPRITE_H
