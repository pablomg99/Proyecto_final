#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->setupUi(this);
    scene= new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0, 0, 800, 432);

    cantVacas=6;

    paredes.push_back(new obstaculo(0,0,4,428));
    scene->addItem(paredes.back());
    paredes.push_back(new obstaculo(0,428,796,4));
    scene->addItem(paredes.back());
    paredes.push_back(new obstaculo(796,4,4,428));
    scene->addItem(paredes.back());
    paredes.push_back(new obstaculo(4,0,796,4));
    scene->addItem(paredes.back());

    fondo=new escena();
    scene->addItem(fondo);

    ufo=new ovni(2, 2);
    _luz=new luz(ufo->x, (ufo->y)+30, ufo->w, (ufo->h)*3);

    ui->scoreLbl->setText("Puntuacion: " + QString::number(ufo->puntuacion));

    scene->addItem(_luz);
    _luz->setVisible(false);

    for(int i=1; i<=cantVacas; i++){
        vacas.push_back(new vaca());
        vaca *aux = vacas.back();
        if(i%2==0){
            aux->sentido=1;
        }
        else{
            aux->sentido=0;
        }
        scene->addItem(vacas.back());
    }
    scene->addItem(ufo);

    _granjero=new granjero();
    _granjero->setScale(0.4);
    scene->addItem(_granjero);


    _granjero->setPos(QPoint(_granjero->posx,_granjero->posy));
    _granjero->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *evento)
{
    if(evento->key() == Qt::Key_W){
        if(!colisionMuros()){
            ufo->moveUp();
            _luz->moveUp();
        }
    }
    else if(evento->key() == Qt::Key_S){
        if(!colisionMuros()){
            ufo->moveDown();
            _luz->moveDown();
        }
    }
    else if(evento->key() == Qt::Key_A){
        if(!colisionMuros()){
            ufo->moveLeft();
            _luz->moveLeft();
        }
    }
    else if(evento->key() == Qt::Key_D){
        if(!colisionMuros()){
            ufo->moveRight();
            _luz->moveRight();
        }
    }

    else if(evento->key() == Qt::Key_Space){
        vaca *aux;
        _luz->setVisible(true);

        if(! _granjero->isVisible()){
            _granjero->setVisible(true);
        }

        if(_granjero->posx<500){
            _granjero->timer->start(50);
        }

        for(int i=0; i<cantVacas; i++){
            aux=vacas.at(i);
            if(aux->collidesWithItem(_luz, Qt::ContainsItemBoundingRect)){
                aux->timerVaca->start(100);
            }
        }
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Space){
        vaca *aux;
        for(int i=0; i<cantVacas; i++){
            aux=vacas.at(i);
            aux->timerVaca->stop();
        }
        _luz->setVisible(false);
    }
    else if(event->key() == Qt::Key_S){
        if(colisionMuros()){
            ufo->moveUp();
            _luz->moveUp();
        }
    }
    else if(event->key() == Qt::Key::Key_A){
        if(colisionMuros()){
            ufo->moveRight();
            _luz->moveRight();
        }
    }
    else if(event->key() == Qt::Key_W){
        if(colisionMuros()){
            ufo->moveDown();
            _luz->moveDown();
        }
    }
    else if(event->key() == Qt::Key_D){
        if(colisionMuros()){
            ufo->moveLeft();
            _luz->moveLeft();
        }
    }
}

bool MainWindow::colisionMuros()
{
    QList<obstaculo*>::Iterator iterator;
    for(iterator=paredes.begin(); iterator!=paredes.end(); iterator++)
    {
        if((*iterator)->collidesWithItem(ufo))
        {
            return true;
        }
    }
    return false;
}

bool MainWindow::colisionDeAbduccion()
{
    vaca *_vaquita;
    for(int i=0; i<cantVacas; i++){
        _vaquita=vacas.at(i);
        if(_vaquita->collidesWithItem(ufo, Qt::ContainsItemBoundingRect)){
            return true;
        }
        else{
            return false;
        }
    }

}

