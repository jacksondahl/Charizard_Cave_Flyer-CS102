#ifndef WINGULL_H
#define WINGULL_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include "thing.h"

class Wingull : public Thing
{
	public:
		Wingull(QPixmap *pm, int nx, int ny);
		~Wingull();
		void move();
		//int moveCounter;
		bool firstMove;
		bool up;
};

#endif
