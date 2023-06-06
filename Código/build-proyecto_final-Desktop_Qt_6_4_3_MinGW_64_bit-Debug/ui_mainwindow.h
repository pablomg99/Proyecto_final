/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QLabel *scoreLbl;
    QWidget *terminarJuegoWidget;
    QLabel *terminarJuegoLbl;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(832, 631);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(10, 60, 810, 442));
        scoreLbl = new QLabel(centralwidget);
        scoreLbl->setObjectName("scoreLbl");
        scoreLbl->setGeometry(QRect(10, 10, 531, 16));
        terminarJuegoWidget = new QWidget(centralwidget);
        terminarJuegoWidget->setObjectName("terminarJuegoWidget");
        terminarJuegoWidget->setGeometry(QRect(170, 140, 451, 251));
        QFont font;
        font.setPointSize(10);
        terminarJuegoWidget->setFont(font);
        terminarJuegoLbl = new QLabel(terminarJuegoWidget);
        terminarJuegoLbl->setObjectName("terminarJuegoLbl");
        terminarJuegoLbl->setGeometry(QRect(-60, 80, 561, 91));
        QFont font1;
        font1.setPointSize(20);
        terminarJuegoLbl->setFont(font1);
        terminarJuegoLbl->setAutoFillBackground(true);
        terminarJuegoLbl->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 832, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        scoreLbl->setText(QCoreApplication::translate("MainWindow", "Puntuacion:", nullptr));
        terminarJuegoLbl->setText(QCoreApplication::translate("MainWindow", "\302\241 JUEGO TERMINADO !", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
