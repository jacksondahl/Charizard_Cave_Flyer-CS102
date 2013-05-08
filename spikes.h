#ifndef SPIKES_H
#define SPIKES_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include "thing.h"
#include <iostream>

using namespace std;

class Spikes : public Thing
{
	public:
		Spikes(QPixmap *pm, int nx, int ny);
		~Spikes();
		void move();
		void printType() {cout << "Killed by Spikes" << endl;}
};

#endif
