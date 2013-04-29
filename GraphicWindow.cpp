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
	
	//creating scene
	scene = new QGraphicsScene(this);
	parent_ = parent;
	
	
	
	//creating background instance
	
	bg = new QGraphicsPixmapItem();
	bg->setPixmap(QPixmap(QString("caveBackground.png")));
	bg2 = new QGraphicsPixmapItem();
	bg2->setPixmap(QPixmap(QString("caveBackground.png")));
	bg2->setPos(1024,0);
	scene->addItem(bg);
	scene->addItem(bg2);
	
	//creating spikes instance
	QPixmap* spikesSprite = new QPixmap(QString("spikesSprite.png"));
	Spikes* spikes = new Spikes(spikesSprite,0,0);
	scene->addItem(spikes);
  
	//creating player instance
	QPixmap* playerSprite = new QPixmap(QString("charizardSprite.png"));
	Charizard* player = new Charizard(playerSprite,100,100);
	scene->addItem(player);
	
	//creating Feraligatr instance
	QPixmap* feraligatrSprite = new QPixmap(QString("feraligatrSprite.png"));
	Feraligatr* gatr = new Feraligatr(feraligatrSprite,800,310);
	scene->addItem(gatr);
	
	//create fireball instance
	QPixmap* fireballSprite = new QPixmap(QString("fireballSprite.png"));
	Fireball* fire = new Fireball(fireballSprite,400,200);
	
	scene->addItem(fire);

	this->setFixedSize(1024,420);
	topLX = 0;
	setScene(scene);
	
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
	//if topleft x < midpoint
	//then bg->setPos(-topLeftx)
}
