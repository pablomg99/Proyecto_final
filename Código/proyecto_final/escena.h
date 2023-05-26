#ifndef ESCENA_H
#define ESCENA_H
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>


class escena: public QGraphicsItem
{
public:
    escena();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void setLimits();
};

#endif // ESCENA_H
