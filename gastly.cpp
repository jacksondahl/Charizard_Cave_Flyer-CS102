#include "gastly.h"

//constructor
Gastly::Gastly(QPixmap *pm, int nx, int ny) : Thing(pm, nx, ny)
{
	//moveCounter = 0;
	//goingUp = true;
}


//deconstructor
Gastly::~Gastly()
{

}

//move function
void Gastly::move()
{
	setPos(x-5,y);
	x -= 5;
	int valX = rand() %6 -3;
	int valY = rand() %6 -3;
	
	setPos(x+valX,y+valY);
}
