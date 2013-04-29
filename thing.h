#ifndef THING_H
#define THING_H

//abstract superclass to hold "things"

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
