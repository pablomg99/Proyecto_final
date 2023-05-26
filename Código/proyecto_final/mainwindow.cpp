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
    fondo=new escena();
    scene->addItem(fondo);
}

MainWindow::~MainWindow()
{
    delete ui;
}

