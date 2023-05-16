#ifndef GRANJERO_H
#define GRANJERO_H
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>


class granjero: public QGraphicsItem
{
    int x, y, ancho, alto, velGiro;
    QString sceneFarmer;

public:
    granjero();
    granjero(int x, int y, int ancho, int alto);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void moveFieldOfView();
    void increaseLevel();
    bool verOVNI();
    void atacar(bool verOVNI());
};

#endif // GRANJERO_H
