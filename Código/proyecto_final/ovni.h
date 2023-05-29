#ifndef OVNI_H
#define OVNI_H
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>
#include <QTimer>


class ovni: public QGraphicsItem
{

public:
    int x, y, w, h, vel;
    ovni();
    ovni(int posx, int posy);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
};

#endif // OVNI_H
