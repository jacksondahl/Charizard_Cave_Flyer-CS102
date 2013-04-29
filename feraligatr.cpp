#include "feraligatr.h"

//constructor
Feraligatr::Feraligatr(QPixmap *pm, int nx, int ny) : Thing(pm, nx, ny)
{

}


//deconstructor
Feraligatr::~Feraligatr()
{

}

//move function
void Feraligatr::move()
{
	//generate random number 
	//jump on certain numbers
	//if not jumping and number is correct,
	//	set jumping to true
	//	then move up
	
}

//have bool in class for if he is jumping
//counter in class (e.g. 5, for 5 pixels)
//if counters at max, move him down,
//if counter isn't max and he's jumping, move up
