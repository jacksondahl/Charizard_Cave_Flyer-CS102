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
#include <vector>
#include "mylist.h"


class MainWindow;

class GraphicWindow : public QGraphicsView
{
	Q_OBJECT
    
public:
    explicit GraphicWindow(MainWindow *parent);
    ~GraphicWindow();
   void moveBG();
   void changeBGToSky();
   void changeBGToRiver();
   void flyUp();
    int playerPos;
    Charizard* player; //player
    bool checkForSpikes();
    void objectMovement(); //moves objects and checks for collisions
	bool checkForCollision();
	bool checkForFire();
	void generateObject();
	
	//bools used in generation of ojbects (hold an object from being generated again until a different object has been generated
	//prevent duplicate objects from being created randomly, except for wingull which is most common enemy
	bool gasHold;
	bool gatrHold;
	bool wingHold;
	bool fireHold; //used to not generate new fireball object if player is already invincible
    
private:
    QGraphicsScene *scene;
    MainWindow *parent_;
    QGraphicsPixmapItem* bg;
    QGraphicsPixmapItem* bg2; //second instance of background used for scrolling
    int *numArr;
    int topLX;
    MyList<Thing*> thingList; //list to store enemies
    MyList<Thing*> fireList; //list to store fireballs
    MainWindow* m;
    void moveAway(Thing* t); //moves object away from Player - used for fireballs
    
    //sprites
    QPixmap* playerSprite; //charizard player image
	QPixmap* upperSpikesSprite; //upper spikes image
	QPixmap* lowerSpikesSprite; //lower spikes image
	QPixmap* feraligatrSprite; //feraligatr image
	QPixmap* fireballSprite; //fireball image
	QPixmap* gastlySprite; //gastly image
	QPixmap* wingullSprite; //wingull image
	

public slots:


};

#endif
