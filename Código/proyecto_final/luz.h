#ifndef LUZ_H
#define LUZ_H
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>


class luz: public QGraphicsItem
{


public:
    int posx, posy, ancho, alto, velocidad;
    luz();
    luz(int x, int y, int w, int h);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
};

#endif // LUZ_H
