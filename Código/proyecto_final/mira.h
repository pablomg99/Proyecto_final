#ifndef MIRA_H
#define MIRA_H
#include <QGraphicsItem>
#include <QObject>
#include <QPainter>
#include <QPixmap>
#include <QTimer>


class mira: public QObject, public QGraphicsItem
{
public:
    int posx, posy, tamano, velocidad;
    bool sentido;

    mira();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void barrido();
};

#endif // MIRA_H
