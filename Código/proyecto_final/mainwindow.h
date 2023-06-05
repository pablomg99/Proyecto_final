#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

#include <QGraphicsScene>
#include <QKeyEvent>
#include <QList>
#include <QGraphicsItem>
#include <QTimer>
#include <QObject>
#include <QThread>
#include "escena.h"
#include "vaca.h"
#include "obstaculo.h"
#include "ovni.h"
#include "luz.h"
#include "granjero.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    escena *fondo;
    QList<vaca*> vacas;
    QList<obstaculo*> paredes;
    ovni *ufo;
    luz *_luz;
    granjero *_granjero;

    int cantVacas, cantVacasAux;
    void keyPressEvent(QKeyEvent *evento);
    void keyReleaseEvent(QKeyEvent *event);
    bool colisionMuros();
    bool colisionDeAbduccion();
};
#endif // MAINWINDOW_H
