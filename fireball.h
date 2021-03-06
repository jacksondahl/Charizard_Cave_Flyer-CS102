#ifndef FIREBALL_H
#define FIREBALL_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include "thing.h"

class Fireball : public Thing
{
	public:
		Fireball(QPixmap *pm, int nx, int ny);
		~Fireball();
		void move();
		int getType() {return 1;}
		int moveCounter;
		bool goingUp;
};

#endif
