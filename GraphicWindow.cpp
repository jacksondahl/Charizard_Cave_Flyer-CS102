#include "GraphicWindow.h"
#include <cmath>
#include <QtAlgorithms>
#include <QBrush>
#include <iostream>
#include "charizard.h"
#include "fireball.h"
#include "spikes.h"
#include "feraligatr.h"

using namespace std;

GraphicWindow::GraphicWindow(MainWindow *parent)
{
	setFocus();
	//creating scene
	scene = new QGraphicsScene(this);
	parent_ = parent;
	
	//Generating images from files
	QPixmap* playerSprite = new QPixmap(QString("charizardSprite.png")); //charizard player image
	QPixmap* spikesSprite = new QPixmap(QString("spikesSprite.png")); //spikes image
	QPixmap* feraligatrSprite = new QPixmap(QString("feraligatrSprite.png")); //feraligatr image
	QPixmap* fireballSprite = new QPixmap(QString("fireballSprite.png")); //fireball image
	
	vector<Thing*> thingList;
	
	
	//creating background instance and generating scrolling
	bg = new QGraphicsPixmapItem();
	bg->setPixmap(QPixmap(QString("caveBackground.png")));
	bg2 = new QGraphicsPixmapItem();
	bg2->setPixmap(QPixmap(QString("caveBackground.png")));
	bg2->setPos(1024,0);
	scene->addItem(bg);
	scene->addItem(bg2);
	
	//creating spikes instance
	Spikes* spikes = new Spikes(spikesSprite,0,0);
	scene->addItem(spikes);
  
	//creating player instanc
	playerPos=150;
	
	player = new Charizard(playerSprite,150,playerPos);
	scene->addItem(player);
	
	//creating Feraligatr instance
	Feraligatr* gatr = new Feraligatr(feraligatrSprite,800,310);
	scene->addItem(gatr);
	thingList.push_back(gatr);
	
	//create fireball instance
	Fireball* fire = new Fireball(fireballSprite,400,200);
	scene->addItem(fire);
	thingList.push_back(fire);
	
	
	//make all objects move
	for (int i = 0; i<thingList.size(); i++)
	{
		thingList[i]->move();
	}

	this->setFixedSize(1044,420);
	topLX = 0;
	setScene(scene);
	
	
	const QRectF rect = QRectF(0,0,1024,400);
	this->setSceneRect(rect);
}

GraphicWindow::~GraphicWindow()
{
}

void GraphicWindow::moveBG()
{
	if (topLX != 1024)
	{
		bg->setPos(-1*topLX,0);
		bg2->setPos(1024-1*topLX,0);
		topLX += 8;
	}
	else
	{
		bg->setPos(0,0);
		bg2->setPos(1024,0);
		topLX = 0;
	}
}

void GraphicWindow::flyUp()
{
	player->setPos(150,playerPos-5);
	playerPos-=5;
}
