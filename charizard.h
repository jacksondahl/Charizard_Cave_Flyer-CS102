#ifndef CHARIZARD_H
#define CHARIZARD_H

#include <QGraphicsPixmapItem>
#include "GraphicWindow.h"

class Charizard : public QGraphicsPixmapItem
{
	public:
		Charizard(GraphicWindow *parent);
		~Charizard();

};

#endif
