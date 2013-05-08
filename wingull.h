#ifndef WINGULL_H
#define WINGULL_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include "thing.h"
#include <iostream>

using namespace std;


class Wingull : public Thing
{
	public:
		Wingull(QPixmap *pm, int nx, int ny);
		~Wingull();
		void move();
		//int moveCounter;
		bool firstMove;
		bool up;
		void printType() {cout << "Killed by Wingull" << endl;}
};

#endif
