#ifndef GRAPHICWINDOW_H
#define GRAPHICWINDOW_H

#include <QGraphicsView>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItemAnimation>
#include <QPushButton>
#include "mainwindow.h"
#include "charizard.h"

class MainWindow;

class GraphicWindow : public QGraphicsView
{
	Q_OBJECT
    
public:
    explicit GraphicWindow(MainWindow *parent);
    ~GraphicWindow();
   
    
private:
    QGraphicsScene *scene;
    MainWindow *parent_;
    int *numArr;
   // QTimer timer;
    

public slots:
};

#endif
