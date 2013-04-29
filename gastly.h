#ifndef GASTLY_H
#define GASTLY_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include "thing.h"

class Gastly : public Thing
{
	public:
		Gastly(QPixmap *pm, int nx, int ny);
		~Gastly();
		void move();
		//int moveCounter;
		//bool goingUp;
};

#endif
