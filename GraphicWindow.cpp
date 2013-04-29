#include "GraphicWindow.h"
#include <cmath>
#include <QtAlgorithms>
#include <QBrush>
#include <iostream>
#include "charizard.h"
#include "fireball.h"
#include "spikes.h"
#include "feraligatr.h"
#include "gastly.h"

using namespace std;

GraphicWindow::GraphicWindow(MainWindow *parent)
{
	m = parent;
	setFocus();
	//creating scene
	scene = new QGraphicsScene(this);
	parent_ = parent;
	
	//Generating images from files
	playerSprite = new QPixmap(QString("charizardSprite.png")); //charizard player image
	upperSpikesSprite = new QPixmap(QString("upperSpikesSprite.png")); //upper spikes image
	lowerSpikesSprite = new QPixmap(QString("lowerSpikesSprite.png")); //lower spikes image
	feraligatrSprite = new QPixmap(QString("feraligatrSprite.png")); //feraligatr image
	fireballSprite = new QPixmap(QString("fireballSprite.png")); //fireball image
	gastlySprite = new QPixmap(QString("gastlySprite.png")); //gastly image
	
	
	//creating background instance and generating scrolling
	bg = new QGraphicsPixmapItem();
	bg->setPixmap(QPixmap(QString("caveBackground.png")));
	bg2 = new QGraphicsPixmapItem();
	bg2->setPixmap(QPixmap(QString("caveBackground.png")));
	bg2->setPos(1024,0);
	scene->addItem(bg);
	scene->addItem(bg2);
	
	//creating player instance
	playerPos=150;
	player = new Charizard(playerSprite,150,playerPos);
	scene->addItem(player);
	
	//creating spikes instance
	Spikes* upperSpikes = new Spikes(upperSpikesSprite,0,0);
	scene->addItem(upperSpikes);
	Spikes* lowerSpikes = new Spikes(lowerSpikesSprite,0,368);
	scene->addItem(lowerSpikes);

	
	//make all objects move
	for (int i = 0; i<thingList.size(); i++)
	{
		thingList[i]->move();
		if (thingList[i]->getX() == -1)
		{
			delete thingList[i];
			thingList.remove(thingList[i]);
		}
	}

	this->setFixedSize(1044,420);
	topLX = 0;
	setScene(scene);
	
	
	//player->invincible = true; - only if you get fireball
	
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

bool GraphicWindow::checkForSpikes()
{
	const QRectF playerRect(150,playerPos,80,60);
	const QRectF upperSpikesRect(0,0,1024,30);
	const QRectF lowerSpikesRect(0,370,1024,32);
	if ((playerRect.intersects(upperSpikesRect)) || (playerRect.intersects(lowerSpikesRect)))
	{
		return true;
	}
	
}

void GraphicWindow::generateObject()
{
	int val = rand() %2000;
	if (val == 0) //fireball
	{
		//create fireball instance
		Fireball* fire = new Fireball(fireballSprite,1000,200);
		scene->addItem(fire);
		thingList.push_back(fire);
	}
	if (val > 0 && val <= 5)
	{
		//creating Feraligatr instance
		Feraligatr* gatr = new Feraligatr(feraligatrSprite,1000,310);
		scene->addItem(gatr);
		thingList.push_back(gatr);
	}
	if (val > 5 && val <= 30)
	{
		//creating Gastly instance
		Gastly* gas = new Gastly(gastlySprite,1000, 50);
		scene->addItem(gas);
		thingList.push_back(gas);
	}
	

}

void GraphicWindow::objectMovement()
{
	//make all objects move
	for (int i = 0; i<thingList.size(); i++)
	{
		thingList[i]->move();
	}
}

bool GraphicWindow::checkForCollision()
{
	for (int i=0; i<thingList.size(); i++)
	{
		Thing* t = thingList[i];
		return player->collidesWithItem(t);
		
	}
	return false;
}

