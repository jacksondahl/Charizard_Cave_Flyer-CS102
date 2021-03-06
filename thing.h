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
		//virtual void collidesWithItem() = 0;
		int getX();
		int getY();
		void changeX(int xVal);
		void changeY(int yVal);
		virtual int getType() {return 0;}
		bool isFireball;
		int getHeight() {return pixMap->height();}
		int getWidth() {return pixMap->width();}
		virtual void printType() {};
		
	protected:
		int x;
		int y;
		int velX;
		int velY;
		QPixmap *pixMap;
};

#endif
