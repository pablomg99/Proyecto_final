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
    scene->setSceneRect(0, 0, 800, 500);

    paredes.push_back(new obstaculo(0,0,4,496));
    scene->addItem(paredes.back());
    paredes.push_back(new obstaculo(0,496,796,4));
    scene->addItem(paredes.back());
    paredes.push_back(new obstaculo(796,4,4,496));
    scene->addItem(paredes.back());
    paredes.push_back(new obstaculo(4,0,796,4));
    scene->addItem(paredes.back());

    fondo=new escena();
    scene->addItem(fondo);

    ufo=new ovni(2, 2);
    _luz=new luz(ufo->x, (ufo->y)+30, ufo->w, (ufo->h)*3);

    scene->addItem(_luz);
    scene->addItem(ufo);
    _luz->setVisible(false);

    for(int i=0; i<5; i++){
        vacas.push_back(new vaca());
        scene->addItem(vacas.back());
    }

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
        if(!evaluarColision()){
            ufo->moveUp();
            _luz->moveUp();
        }
        else{
            ufo->moveDown();
            _luz->moveDown();
        }
    }
    else if(evento->key() == Qt::Key_S){
        if(!evaluarColision()){
            ufo->moveDown();
            _luz->moveDown();
        }
        else{
            ufo->moveUp();
            _luz->moveUp();
        }
    }
    else if(evento->key() == Qt::Key_A){
        if(!evaluarColision()){
            ufo->moveLeft();
            _luz->moveLeft();
        }
        else{
            ufo->moveRight();
            _luz->moveRight();
        }
    }
    else if(evento->key() == Qt::Key_D){
        if(!evaluarColision()){
            ufo->moveRight();
            _luz->moveRight();
        }
        else{
            ufo->moveLeft();
            _luz->moveLeft();
        }
    }

    else if(evento->key() == Qt::Key_Space){
        _luz->setVisible(true);
        _granjero->setVisible(true);
        if(_granjero->posx<500){
            _granjero->timer->start(50);
        }
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Space){
        _luz->setVisible(false);
    }
    else if(event->key() == Qt::Key_S){
        ufo->vel=(ufo->vel)/2;
        _luz->velocidad=(_luz->velocidad)/2;
        ufo->moveUp();
        _luz->moveUp();
        ufo->vel=(ufo->vel)*2;
        _luz->velocidad=(_luz->velocidad)*2;
    }
    else if(event->key() == Qt::Key_A){
        ufo->vel=(ufo->vel)/2;
        _luz->velocidad=(_luz->velocidad)/2;
        ufo->moveRight();
        _luz->moveRight();
        ufo->vel=(ufo->vel)*2;
        _luz->velocidad=(_luz->velocidad)*2;
    }
    else if(event->key() == Qt::Key_W){
        ufo->vel=(ufo->vel)/2;
        _luz->velocidad=(_luz->velocidad)/2;
        ufo->moveDown();
        _luz->moveDown();
        ufo->vel=(ufo->vel)*2;
        _luz->velocidad=(_luz->velocidad)*2;
    }
    else if(event->key() == Qt::Key_D){
        ufo->vel=(ufo->vel)/2;
        _luz->velocidad=(_luz->velocidad)/2;
        ufo->moveLeft();
        _luz->moveLeft();
        ufo->vel=(ufo->vel)*2;
        _luz->velocidad=(_luz->velocidad)*2;
    }
}

bool MainWindow::evaluarColision()
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

