#ifndef THING_H
#define THING_H

//abstract superclass to hold "things"

#include <QGraphicsPixmapItem>
#include "GraphicWindow.h"

class GraphicWindow;

class Thing : public QGraphicsPixmapItem
{
	public:
		Thing(GraphicWindow* parent, QPixmap *pm, int nx, int ny);
		virtual void move();
		
	private:
		int x;
		int y;
		int velX;
		int velY;
		QPixmap *pixMap;
};

#endif
