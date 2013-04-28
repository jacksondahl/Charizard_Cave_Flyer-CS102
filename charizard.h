#ifndef CHARIZARD_H
#define CHARIZARD_H

#include <QGraphicsPixmapItem>
#include "GraphicWindow.h"
#include "thing.h"

class GraphicWindow;

class Charizard : public Thing
{
	public:
		Charizard(GraphicWindow* parent, QPixmap *pm, int nx, int ny);
		~Charizard();
		void move();
};

#endif
