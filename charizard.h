#ifndef CHARIZARD_H
#define CHARIZARD_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include "thing.h"

class Charizard : public Thing
{
	public:
		Charizard(QPixmap *pm, int nx, int ny);
		~Charizard();
		void move();
};

#endif
