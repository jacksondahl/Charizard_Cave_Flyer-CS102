#include "feraligatr.h"

//constructor
Feraligatr::Feraligatr(QPixmap *pm, int nx, int ny) : Thing(pm, nx, ny)
{
	isJumping = false;
	jumpUpCounter = 0;
	jumpDownCounter = 0;
}


//deconstructor
Feraligatr::~Feraligatr()
{

}

//move function
void Feraligatr::move()
{
	setPos(x-2,y);
	x-=2;
	int num = rand() %100;
	if (isJumping) //already jumping
	{
		if (jumpUpCounter > 40) //reached peak, come down
		{
			 setPos(x,y+3);
			 y+=3;
			 jumpDownCounter++;
			 if (jumpDownCounter > 40) //reached bottom
			 {
			 	jumpDownCounter = 0;
			 	jumpUpCounter = 0; //start over
			 	isJumping = false; // no longer jumping
			 }
		}
		else //keep going
		{
			setPos(x,y-3);
			y-=3;
			jumpUpCounter++;
		}
	}
	else if (!isJumping && num == 0) //start jumping
	{
		isJumping = true;
		setPos(x,y-3);
		y-=3;
		jumpUpCounter++;	
	}

	
}
