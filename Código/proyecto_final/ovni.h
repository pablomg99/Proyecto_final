#ifndef OVNI_H
#define OVNI_H
#include <QGraphicsItem>
#include <QObject>
#include <QPainter>
#include <QPixmap>
#include <QTimer>


class ovni: public QObject, public QGraphicsItem
{

public:
    int x, y, w, h, vel, a, puntuacion;
    ovni();
    ovni(int posx, int posy);
    QTimer *moveUfoTimer;
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void restartSpeed();
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

public slots:
    void aceleracion();
};

#endif // OVNI_H
