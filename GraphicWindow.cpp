#include "GraphicWindow.h"
#include <cmath>
#include <QtAlgorithms>
#include <iostream>

using namespace std;

GraphicWindow::GraphicWindow(MainWindow *parent)
{
	scene = new QGraphicsScene(this);
    parent_ = parent;
    setScene(scene);
}

GraphicWindow::~GraphicWindow()
{
}
