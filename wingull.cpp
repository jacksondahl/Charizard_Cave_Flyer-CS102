#include "wingull.h"

//constructor
Wingull::Wingull(QPixmap *pm, int nx, int ny) : Thing(pm, nx, ny)
{
	//moveCounter = 0;
	firstMove = true;
	up = false;
}


//deconstructor
Wingull::~Wingull()
{

}

//move function
void Wingull::move()
{
	setPos(x-5,y);
	x -= 5;
	if (firstMove)
	{
		int val = rand() %2;
		if (val == 0) // go up
		{
			setPos(x,y-3);
			y -= 3;
			up = true;
		}
		else // go down
		{
			setPos(x,y+3);
			y += 3;
			up = false;
		}
		firstMove = false;
	}
	else
	{
		if (up) //going up
		{
			if (y <=28) // hit ceiling, go down
			{
				setPos(x,y+3);
				y += 3;
				up = false;
			}
			else 
			{
				setPos(x,y-3);
				y -= 3;
			}
		}
		else //going down
		{
			if (y >= 312) // hit bottom, go up
			{
				setPos(x,y-3);
				y -= 2;
				up = true;
			}
			else
			{
				setPos(x,y+3);
				y += 3;
			}
		}
	} 
}
