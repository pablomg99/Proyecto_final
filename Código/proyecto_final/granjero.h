#ifndef GRANJERO_H
#define GRANJERO_H

#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QObject>
#include <QPainter>

class granjero: public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit granjero(QObject *parent=nullptr);

    QTimer *timer;
    QPixmap *granjeroPm;
    float filas, columnas, ancho, alto;
    int posx, posy, velocidad, contador;
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void arriveToScene();
signals:

public slots:
    void Actualizacion();
};

#endif // GRANJERO_H
