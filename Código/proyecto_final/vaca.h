#ifndef VACA_H
#define VACA_H
#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>
#include <QTimer>
#include <random>


class vaca: public QObject, public QGraphicsItem
{
    int alturaAbduccion, velAbd, tamano;

public:
    int posx, posy, sentido=0;
    vaca();
    QTimer *timerVaca;
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void caer(bool cae);
    int random(int inicio, int fin);
    void abduccion();

};

#endif // VACA_H
