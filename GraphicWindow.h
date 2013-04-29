#ifndef GRAPHICWINDOW_H
#define GRAPHICWINDOW_H

#include <QGraphicsView>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItemAnimation>
#include <QPushButton>
#include <QGraphicsPixmapItem>
#include "mainwindow.h"
#include "thing.h"
#include "charizard.h"
#include <QTimer>

class MainWindow;

class GraphicWindow : public QGraphicsView
{
	Q_OBJECT
    
public:
    explicit GraphicWindow(MainWindow *parent);
    ~GraphicWindow();
   void moveBG();
    
private:
    QGraphicsScene *scene;
    MainWindow *parent_;
    QGraphicsPixmapItem* bg;
    QGraphicsPixmapItem* bg2; //second instance of background used for scrolling
    int *numArr;
    int topLX;
    //void scrollContentsBy(int x, int y) {};

public slots:


};

#endif
