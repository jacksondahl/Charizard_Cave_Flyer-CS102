#include "GraphicWindow.h"
#include <cmath>
#include <QtAlgorithms>
#include <iostream>
#include "charizard.h"

using namespace std;

GraphicWindow::GraphicWindow(MainWindow *parent)
{
	//creating scene
	scene = new QGraphicsScene(this);
  parent_ = parent;
  //creating background instance
  background = new QGraphicsPixmapItem();
  background->setPixmap(QPixmap(QString("caveBackground.png")));
  scene->addItem(background);
  
  //creating player instance
  QPixmap* playerSprite = new QPixmap(QString("charizardSprite.png"));
  Charizard* player = new Charizard(this, playerSprite,100,100);
  player->setPos(100,100);
  scene->addItem(player);
  
  
  setScene(scene);
}

GraphicWindow::~GraphicWindow()
{
}
