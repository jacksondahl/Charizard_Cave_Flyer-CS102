#include "fireball.h"

//constructor
Fireball::Fireball(QPixmap *pm, int nx, int ny) : Thing(pm, nx, ny)
{
	moveCounter = 0;
	goingUp = true;
}


//deconstructor
Fireball::~Fireball()
{

}

//move function
void Fireball::move()
{
	setPos(x-15,y);
	x -= 15;
	if (moveCounter == 0 && goingUp) //start or continuing going up
	{
		setPos(x,y-8);
		y -= 8;
		moveCounter++;
	}
	if (moveCounter == 0 && !goingUp) //continue going down
	{
		setPos(x, y+8);
			y += 8;
			moveCounter--;
	}
	if (moveCounter > 0 && goingUp)
	{
		if (moveCounter > 9) //reached peak (5), go back down
		{
			setPos(x, y+8);
			y += 8;
			moveCounter--;
			goingUp = false;
		}
		else //keep going up
		{
			setPos(x,y-8);
			y -= 8;
			moveCounter++;
		}
	}
	if (moveCounter > 0 && !goingUp) //going down
	{
			setPos(x, y+8);
			y += 8;
			moveCounter--;
	}
	if (moveCounter < 0 && goingUp) //going up
	{
		setPos(x,y-8);
		y -= 8;
		moveCounter++;
	}
	if (moveCounter < 0 && !goingUp)
	{
		if (moveCounter < -9) //reached bottom (-5), go back up
		{
			setPos(x, y-8);
			y -= 8;
			moveCounter++;
			goingUp = true;
		}
		else //keep going down
		{
			setPos(x, y+8);
			y += 8;
			moveCounter--;
		}
	}
}
