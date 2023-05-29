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

    for(int i=0; i<5; i++){
        vacas.push_back(new vaca());
        scene->addItem(vacas.back());
    }

    ufo=new ovni(0, 0);
    _luz=new luz(ufo->x, (ufo->y)+30, ufo->w, (ufo->h)*3);

    scene->addItem(_luz);
    scene->addItem(ufo);

    _luz->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *evento)
{
    if(ufo->x <= 4){
        ufo->moveRight();
        _luz->moveRight();
    }

    else if(ufo->y <= 4){
        ufo->moveDown();
        _luz->moveDown();
    }

    else if(ufo->x > (796-(ufo->w))){
        ufo->moveLeft();
        _luz->moveLeft();
    }

    else if(ufo->y > 496-(ufo->h)){
        ufo->moveUp();
        _luz->moveUp();
    }


    if(evento->key() == Qt::Key_W){
        ufo->moveUp();
        _luz->moveUp();
    }

    else if(evento->key() == Qt::Key_S){
        ufo->moveDown();
        _luz->moveDown();
    }

    else if(evento->key() == Qt::Key_A){
        ufo->moveLeft();
        _luz->moveLeft();
    }

    else if(evento->key() == Qt::Key_D){
        ufo->moveRight();
        _luz->moveRight();
    }

    else if(evento->key() == Qt::Key_Space){
        _luz->setVisible(true);

    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Space){
        _luz->setVisible(false);
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

