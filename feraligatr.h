#ifndef FERALIGATR_H
#define FERALIGATR_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include "thing.h"

class Feraligatr : public Thing
{
	public:
		Feraligatr(QPixmap *pm, int nx, int ny);
		~Feraligatr();
		void move();
};

#endif
