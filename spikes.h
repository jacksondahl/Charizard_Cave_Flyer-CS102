#ifndef SPIKES_H
#define SPIKES_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include "thing.h"

class Spikes : public Thing
{
	public:
		Spikes(QPixmap *pm, int nx, int ny);
		~Spikes();
		void move();
};

#endif
