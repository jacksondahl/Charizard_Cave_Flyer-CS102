#ifndef THING_H
#define THING_H

//abstract superclass to hold "things"
//user can create a list of things (which is in reality, all types of objects or enemies)

#include <QGraphicsPixmapItem>

class Thing : public QGraphicsPixmapItem
{
	public:
		Thing(QPixmap *pm, int nx, int ny);
		virtual void move() = 0;
		
	private:
		int x;
		int y;
		int velX;
		int velY;
		QPixmap *pixMap;
};

#endif
