#include "thing.h"

Thing::Thing(QPixmap* p, int nx, int ny)
{
	pixMap = p;
	setPixmap(*p);
	x = nx;
	y = ny;
	setPos(x,y);
}
