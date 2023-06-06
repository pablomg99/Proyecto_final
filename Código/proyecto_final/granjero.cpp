#include "granjero.h"

granjero::granjero(QObject *parent)
{
    timer=new QTimer();
    filas=1;
    columnas=17;
    granjeroPm=new QPixmap(":/recursos/vaquero_sprite-removebg-preview.png");
    ancho=57;
    alto=100;
    posx=120;
    posy=285;
    velocidad=7;
    contador=0;

    connect(timer, &QTimer::timeout, this, &granjero::Actualizacion);
    connect(timer, &QTimer::timeout, this, &granjero::arriveToScene);
}

QRectF granjero::boundingRect() const
{
    return QRectF(-ancho/2, -alto/2, ancho, alto);
    //return QRectF(posx, posy, 40, 40);
}


void granjero::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //painter->drawPixmap(boundingRect(), granjeroPm, granjeroPm->rect());
    painter->drawPixmap(-ancho/2, -alto/2,*granjeroPm,columnas,filas,ancho,alto);
}

void granjero::arriveToScene()
{
    if(posx >= 500){
        columnas = 237;
        filas = 274;
        timer->stop();
    }
    posx+=velocidad;
    setPos(QPoint(posx, posy));
}

void granjero::Actualizacion()
{
    if(columnas>=500){
        contador=0;
        columnas=17;
    }
    columnas=columnas+(contador*ancho);
    contador+=1;
    this->update(-ancho/2, -alto/2 ,ancho,alto);
    //this->update(posx, posy, ancho, alto);
}
