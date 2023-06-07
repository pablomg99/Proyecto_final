#ifndef LUZ_H
#define LUZ_H
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>
#include <QTimer>
#include <QObject>


class luz: public QGraphicsItem, public QObject
{


public:
    int posx, posy, ancho, alto, velocidad, a;
    QTimer *luzTimer;
    luz();
    luz(int x, int y, int w, int h);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void aceleracion();
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void restartSpeed();
};

#endif // LUZ_H
