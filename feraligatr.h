#ifndef FERALIGATR_H
#define FERALIGATR_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include "thing.h"
#include <iostream>

using namespace std;

class Feraligatr : public Thing
{
	public:
		Feraligatr(QPixmap *pm, int nx, int ny);
		~Feraligatr();
		void move();
		bool isJumping;
		int jumpUpCounter;
		int jumpDownCounter;
		void printType() {cout << "Killed by Feraligatr" << endl;}
};

#endif
