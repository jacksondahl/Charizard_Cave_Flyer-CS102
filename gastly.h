#ifndef GASTLY_H
#define GASTLY_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include "thing.h"
#include <iostream>

using namespace std;

class Gastly : public Thing
{
	public:
		Gastly(QPixmap *pm, int nx, int ny);
		~Gastly();
		void move();
		//int moveCounter;
		//bool goingUp;
		void printType() {cout << "Killed by Gastly" << endl;}
};

#endif
